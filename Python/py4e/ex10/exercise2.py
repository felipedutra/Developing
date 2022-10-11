import urllib.request, urllib.parse, urllib.error
import json
import ssl

# Ignore SSL certificate errors
ctx = ssl.create_default_context()
ctx.check_hostname = False
ctx.verify_mode = ssl.CERT_NONE
address = input('Enter address:')

print('Retrieving', address)
try:
    fhandle = urllib.request.urlopen(address)
except:
    fhandle = urllib.request.urlopen('http://py4e-data.dr-chuck.net/comments_895901.json')
data = fhandle.read().decode()
x = data.find('[')
y = data.find(']')
text = data[x:y+1]
fwrite =open('input.txt','w')
fwrite.write(text)
print('Retrieved', len(data), 'characters')
try:
    js = json.loads(text)
except:
    quit()
sum = 0

for item in js:
    print('Name', item['name'])
    print('Attribute', item['count'])
    sum+= item['count']
print ('Count:',sum)
