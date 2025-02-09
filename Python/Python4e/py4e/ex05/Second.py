fhand = open('mbox-short.txt')
d = dict()
for line in fhand:
    words = line.split()
    if len(words) == 0 or words[0] != 'From' : continue
    if len(words) > 2:
        if words[2] not in d:
            d[words[2]] = 1
        else:
            d[words[2]] += 1
print(d)
