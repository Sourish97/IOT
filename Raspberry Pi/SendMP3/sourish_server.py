import socket
my_soc=socket.socket(socket.AF_INET,socket.SOCK_STREAM)
my_soc.bind(("",1264))
my_soc.listen(5)
(conn,addr)=my_soc.accept()
data=conn.recv(25000)
with open('/home/pi/Desktop/received.mp3', 'wb') as f :
        f.write(data)
print('received')
conn.close()
my_soc.close()
exit()
