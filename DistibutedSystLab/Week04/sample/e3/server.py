import socket
host = '172.16.58.106'
port = 9699
s = socket.socket()
s.bind((host, port))
s.listen()
print("\nWaiting for incoming connections...\n")
conn, addr = s.accept()
print("Received connection from ", addr[0], "(", addr[1], ")\n")
s_name = conn.recv(1024)
s_name = s_name.decode()
print(s_name, " has connected to the chat room\nEnter [e] to exit chat room\n")
name = input(str("Enter your name: "))
conn.send(name.encode())
while True:
	message = input(str("Me: "))
	if message == "[e]":
		message = "Left chat room!"
		conn.send(message.encode())
		print("\n")
		break
	conn.send(message.encode())
	message = conn.recv(1024)
	message	= message.decode()
	print(s_name, ":", message)