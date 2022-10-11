import re
fhandle = open('text.txt')
sum = 0
for line in fhandle:
    x = re.findall('([0-9]+)',line)
    if len(x) > 0:
        for n in range(len(x)):
            sum += int(x[n])
print(sum)
