import socket
server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
server.bind(("localhost", 8080))
server.listen(5)

while True:
    print("server waiting for connections.....")

    (client, addr) = server.accept()
    print("HTTP server request received:")
    print(client.recv(1024))
    client.send(bytes(
        "HTTP/1.1 200 OK\r\n\r\n<html><body><h1>HELLO WORLD FROM HTTP SERVER PYTHON</h1></body></html>\r\n".encode('utf-8')
    ))
    client.close()