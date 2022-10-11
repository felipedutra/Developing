import socket
import time
mysock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

sitename = input("Enter a link:")
servername = sitename.split('/')
servername = str(servername[2])
#print(servername)
mysock.connect((servername, 80))
sitename = 'GET '+ str(sitename)+ ' HTTP/1.0\r\n\r\n'
try:
    cmd = sitename.encode()
    mysock.send(cmd)
except:
    print('Wrong name')
    quit()

j = 0
while True:
    data = mysock.recv(512)


    if len(data) < 1:
        break
    y = data.find(b'\r\n\r\n')
    data = data[y+4:]
    x = data.decode()
    if j == 0:
        print(x[y+4:],end='')
        j = 1
    if j == 1:
        print(x ,end='')
print("Blank line")
mysock.close()
