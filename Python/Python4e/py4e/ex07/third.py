import string
#fname = input("Enter a file name: ")
try:
    fhand = open("romeo-full.txt")
except:
    print("Cannot open this file!")
    exit()
counts = dict()
for line in fhand:
    line = line.translate(str.maketrans('','',string.punctuation))
    line = line.lower()
    words = line.split()
    for word in words:
        letters = word
        for letter in letters:
            if letter > 'z' or letter < 'a': continue
            if letter not in counts:
                counts[letter] = 1
            else:
                counts[letter] += 1

t = list()
for val, key in list(counts.items()):
    t.append((key,val))
t.sort()
for key, val in t[:]:
    print(key, val)
