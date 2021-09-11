import re
import sqlite3

fhand = open("mbox.txt")
t_counts = dict()

for line in fhand:
    line = line.rstrip()
    org = re.findall('^F.*@(\S*)',line)
    org = str(org)
    x = len(org)
    if x > 3: org = org[2:x-2]
    if len(org) > 3 and org not in t_counts.keys():
        t_counts[org] = 1
    elif len(org) > 3:
        t_counts[org] += 1

print(t_counts)




conn = sqlite3.connect('ex2.sqlite')
cur = conn.cursor()
cur.execute('DROP TABLE IF EXISTS Counts')
cur.execute('CREATE TABLE Counts (org TEXT, count INTEGER)')

for line in t_counts:
    cur.execute('INSERT INTO Counts (org, count) VALUES (?, ?)', (str(t_count.keys()),t_counts()))

conn.commit()


cur.close()
