import xml.etree.ElementTree as ET
import urllib.request, urllib.parse, urllib.error
import ssl

sitename = input("Enter a link:")
fhandle = urllib.request.urlopen(sitename)
data = fhandle.read()
input = data.decode()
#print(input)



stuff = ET.fromstring(data)
print('Retrieved ',len(input),'characters')


counts = stuff.findall('.//count')
sum = 0
print(len(counts))
for item in counts:
    sum += int(item.text)
    print("count",item.text)


teste






print('Sum:',sum)
#http://py4e-data.dr-chuck.net/comments_42.xml
