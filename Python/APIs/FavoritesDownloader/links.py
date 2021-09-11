import re
import os
t = list()
fav = open("favoritos.html")
for lines in fav:
    x = re.findall('HREF="(https://     \S*)"', lines)
    y = re.findall('HREF="(https://      \S*)"', lines)
    if len(x) > 0:
        t.append(x)
    if len(y) > 0:
        t.append(y)
fav.close()
input = input("Write the file name: ")
name = str(input) + ".txt"
fwrite = open(name,"w")
for lines in t:
    line = str(lines)
    line = line[2:len(line) - 2]+ "\n"
    fwrite.write(line)
for lines in t:
    print(lines)
fwrite.close()
print (len(t))
