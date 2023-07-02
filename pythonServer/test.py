import socket

serverHost = "localhost"
serverPort = 8080
print("connecting to HTTP server:")

client = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
client.connect((serverHost,serverPort))
client.send(bytes("GET / HTTP/1.1\r\nHost:localhost\r\n\r\n".encode('utf-8')))
resp = client.recv(4096)
print("response from HTTP server")
print(resp.decode())