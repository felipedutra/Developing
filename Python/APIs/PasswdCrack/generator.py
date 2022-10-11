import os
fhand = open("try.txt", "w")
i = 0
while i != 10**10:
    text = str(i) + "\n"
    fhand.write(text)
    i +=1
fhand.close()
