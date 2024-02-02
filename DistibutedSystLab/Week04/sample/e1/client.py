import socket
HOST = '127.0.0.1'
PORT = 12345
with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
	s.connect((HOST, PORT))
	s.sendall(b'Hello, world')
	data = s.recv(1024)
	print("Received Connection")
	print("Server: ", data.decode())