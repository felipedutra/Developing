import socket
import time
mysock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

sitename = input("Enter a link:")
servername = sitename.split('/')
servername = str(servername[2])
print(servername)
mysock.connect((servername, 80))
sitename = 'GET '+ str(sitename)+ ' HTTP/1.0\r\n\r\n'
try:
    cmd = sitename.encode()
    mysock.send(cmd)
except:
    print('Wrong name')
    quit()
countRead = 0
while True:
    data = mysock.recv(5120)


    if len(data) < 1:
        break
    if countRead < 3000:
        x = data.decode()
        countRead += len(x)
        print(x,end='')
print ('\n',countRead)

mysock.close()
