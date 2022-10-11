import urllib.request, urllib.parse, urllib.error
sitename = input("Enter a link:")
fhandle = urllib.request.urlopen(sitename)
countRead = 0
while True:
    data = fhandle.read(512)
    if len(data) < 1: break

    if countRead < 3000:
        print(data)
    countRead += len(data)
print (countRead)
