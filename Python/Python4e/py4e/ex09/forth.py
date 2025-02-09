# To run this, download the BeautifulSoup zip file
# http://www.py4e.com/code3/bs4.zip
# and unzip it in the same directory as this file

from urllib.request import urlopen
from bs4 import BeautifulSoup
import ssl

# Ignore SSL certificate errors
ctx = ssl.create_default_context()
ctx.check_hostname = False
ctx.verify_mode = ssl.CERT_NONE

url = input('Enter - ')
html = urlopen(url, context=ctx).read()
soup = BeautifulSoup(html, "html.parser")

# Retrieve all of the anchor tags
tags = soup('span')
sum = 0
count = 0
for tag in tags:
    # Look at the parts of a tag
    x = str(tag)
    print(tag)
    x = x[1:]
    i = x.find('>')
    j = x.find('<')
    x = x[i+1:j]
    sum += int(x)
    count += 1
    print(x)
print('Sum: ',sum)
print ('Count: ',count)
