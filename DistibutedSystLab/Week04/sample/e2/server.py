import socket
import time
serversock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
host = socket.gethostname()
port = 12345
serversock.bind((host, port))
serversock.listen(5)
while True:
	clientsock,addr = serversock.accept()
	print("Got a aconnection from %s" %str(addr))
	currentTime = time.ctime(time.time()) + "\r\n"
	clientsock.send(currentTime.encode('ascii'))
	clientsock.close()
