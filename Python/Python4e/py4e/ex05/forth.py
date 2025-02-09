fname = input('Enter File name:')
try:
    fhand = open('mbox.txt')
except:
    print('File cannot be oppened.')
    exit()
d = dict()
for line in fhand:
    word = line.split()

    if len(word) == 0 or word[0] != 'From' or len(word) < 3: continue
    if word[1] not in d:
        d[word[1]] = 1
    else:
        d[word[1]] += 1
highValue = None
highName = None
for person in d:
    if highValue == None:
        highValue = d[person]
    elif highValue < d[person]:
        highValue = d[person]
        highName = person
print('%s %d' % highPerson, highValue)
print(max(d.values()))
