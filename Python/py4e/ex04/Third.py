fhand = open('mbox-short.txt')
count = 0 #There is no use for this variable
for line in fhand:
    words = line.split()
    # print 'Debug:', words
    if len(words) == 0 or words[0] != 'From' : continue
    #if len(words) == 0 : continue
    #if words[0] != 'From' : continue
    if len(words) > 2:
        print(words[2])
    count = count + 1
print (('There were %d lines in the file with From as the first word') % count)
