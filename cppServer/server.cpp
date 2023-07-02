#include <sys/socket.h>
#include <netinet/in.h>
#include <errno.h>
#include <unistd.h>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#pragma comment(lib, "ws2_32.lib")

using namespace std;

#define PORT 3000

void error_out(char* s) {
    perror(s);
    exit(EXIT_FAILURE);
}

// test for the position of error(uncommented all "tester" and "test" if needed)
// void tester(int &s) {
//     printf("here we test our error:%d\n", s);
//     s++;
// }

int main() {
    //int test = 0;

    printf("welcome to c++ web server");
    //tester(test);

    /*
    * in cpp, it's wholesome to prepare a complete socket. it comprises INITIALIZATION|BINDING WITH SPECIAL ADDRESS|LISTENING TEST
    where too much data need to be declared.
    */
    
    int server, client;
    
    if ((server = socket(AF_INET, SOCK_STREAM, 0)) == 0) {error_out("fail to build the socket");}
    //tester(test);

    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(PORT);
    addr.sin_addr.s_addr = INADDR_ANY;

    //memset(addr.sin_zero, '\0', sizeof(addr.sin_zero));
    
    if (bind(server, (struct sockaddr*)&addr, sizeof(addr)) < 0) {error_out("fail to bind");}
    //tester(test);

    if (listen(server, 6) < 0) {error_out("fail to listen");}
    //tester(test);

    struct sockaddr_in claddr;
    int cllen = sizeof(claddr);
    
    while (1) {
        if (client = accept(server, (struct sockaddr*)&claddr, (socklen_t*)(&claddr)) < 0){error_out("fail to connect from client");}
        //tester(test);

        
        /**
         * However, in cpp data preparation is much straightforward with no need for extra buffer to retrieve and process data from sockets.
         * recv() and send() did lost of "dirty works" behind. 
         * **/
        char revdata[1024] = "";
        recv(client, revdata, 1024, 0);
        printf("%s: %ld data has been received\n", revdata, strlen(revdata));
        //tester(test);

        char senddata[1024] = "hello world";
        send(client, senddata, strlen(senddata), 0);
        close(client);
        //tester(test);
    }

    close(server);

    getchar();
    return 0;
}