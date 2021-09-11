fhand = open('words.txt')
wordDic = {}
for lines in fhand:
    words = lines.split()
    for i in range(len(words)):
        wordDic[words[i]] = None

print(wordDic)
print ('are' in wordDic)
