import re
inpt = input("Enter a regular expression: ")
fhand = open("mbox.txt")
count = 0
for line in fhand:
    line = line.rstrip()
    x = re.findall(inpt, line)
    if len(x) > 0: count += 1
print('mbox.txt had %d lines that matched %s' % (count,inpt))
