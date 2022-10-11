#Hello world
fhand = open('mbox-short.txt')
counts = dict()
for lines in fhand:
    line = lines.split()
    if len(line) == 0 or line[0] != 'From' or len(line) < 6: continue
    hour = line [5]
    x = hour.find(":")
    hour = hour[:x]
    if hour not in counts:
        counts[hour] = 1
    else:
        counts[hour] += 1


t = list()
for val, key in list(counts.items()):
    t.append((val,key))
t.sort()
for key, val in t[:]:
    print(key, val)
