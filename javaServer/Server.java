import java.net.*;
import java.io.*;


public class Server {
    public static void main(String[] args) throws IOException{
        int port = 8081;

        // java gets much easier to build socket, only by providing port(means ServerSocket() did lots of configuration behind)
        ServerSocket server = new ServerSocket(port);
        System.out.println("Server running on port:"+port);
        while(true) {
            Socket client = server.accept();
            System.out.println("a client connected");
            BufferedReader in = new BufferedReader(new InputStreamReader(client.getInputStream()));
            String s;
            while((s = in.readLine()) != null){
                System.out.println(s);
                if (s.isEmpty()){
                    break;
                }
            }

            //however, in java an extra buffer is needed to access and retrieve the informations interacted with sockets.
            OutputStream clientOutput = client.getOutputStream();
            clientOutput.write("HTTP/1.1 200 OK\r\n".getBytes());
            clientOutput.write("\r\n".getBytes());
            clientOutput.write("<b>Welcome To My Code!</b>".getBytes());
            clientOutput.write("\r\n\r\n".getBytes());
            clientOutput.flush();

            System.out.println("Client connection closed");
            in.close();
            clientOutput.close();   
        }
    }
}