fhand = open('mbox-short.txt')
for line in fhand:
    word = line.split()
    if len(word) == 0 or word[0] != 'From' or len(word) < 3:
        continue
    print(word[1])
