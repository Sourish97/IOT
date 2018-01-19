import socket
my_soc=socket.socket(socket.AF_INET,socket.SOCK_STREAM)
my_soc.connect(("127.0.0.1",1264))
with open('/home/pi/Downloads/example.mp3','rb') as f:
    my_soc.sendall(f.read())
my_soc.close()
