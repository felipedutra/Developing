def alfa(t):
    lowT = []
    for word in t:
        lowWord = word.lower()
        lowT.append(lowWord)
        lowT.sort()
    for word in t:
        i = 0
        for lowWord in lowT:

            if word.lower() == lowT[i] :
                lowT[i] = word.capitalize()
                continue
            i = i + 1

    return lowT

fhand = open('romeo.txt')
wordList = []
for line in fhand:
    words = line.split() # Splitting words into a list
    if len(words) == 0 : continue
    for word in words:
        if not wordList:
            wordList.append(word)
            continue
        if word in wordList: continue
        wordList.append(word)

print(alfa(wordList))
