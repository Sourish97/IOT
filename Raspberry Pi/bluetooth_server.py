from bluetooth import *
port=1
server_sock=BluetoothSocket(RFCOMM)
server_sock.bind(("",port))
server_sock.listen(1)

client,address=server_sock.accept()
print "Connection Received From Address :",address

while True:
    data = client.recv(1)
    print "%s" % data

server_sock.close()
client.close()
