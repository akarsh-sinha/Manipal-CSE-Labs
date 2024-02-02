import socket
host = '172.16.58.106'
port = 9699
s = socket.socket()
name = input(str("\nEnter your name: "))
print("\nTrying to connect to ", host, "(", port, ")\n")
s.connect((host, port))
print("Connected...\n")
s.send(name.encode())
s_name = s.recv(1024)
s_name = s_name.decode()
print(s_name, "has joined the chat room\nEnter [e] to exit chat room\n")
while True:
	message = s.recv(1024)
	message = message.decode()
	print(s_name, ":", message)
	message = input(str("Me: "))
	if message == "[e]":
		message = "Left chat room!"
		s.send(message.encode())
		print("\n")
		break
	s.send(message.encode())
