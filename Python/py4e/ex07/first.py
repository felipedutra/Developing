fhand = open('mbox.txt')
counts = dict()
for lines in fhand:
    line = lines.split()
    if len(line) == 0 or line[0] != 'From' or len(line) < 3: continue
    email = line [1]
    if email not in counts:
        counts[email] = 1
    else:
        counts[email] += 1

# Sort the dictionary by value
#lst = list()
#for key, val in list(counts.items()):
#    lst.append((val, key))

#lst.sort(reverse=True)

#for key, val in lst[:]:
#    print(val, key)

t = list()
for val, key in list(counts.items()):
    t.append((key,val))
t.sort(reverse = True)
for key, val in t[:]:
    print(key, val)
