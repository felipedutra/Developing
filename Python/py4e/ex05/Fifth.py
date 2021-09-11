fname = input('Enter File name:')
try:
    fhand = open('mbox.txt')
except:
    print('File cannot be oppened.')
    exit()
d = dict()
for line in fhand:
    words = line.split()
    if len(words) == 0 or words[0] != 'From' or len(words) < 3: continue
    word = words[1]
    x = word.find('@')
    word = word[x+1:]
    if word not in d:
        d[word] = 1
    else:
        d[word] += 1
print(d)
