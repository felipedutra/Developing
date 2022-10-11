import sqlite3

conn = sqlite3.connect('ages.sqlite')
cur = conn.cursor()

cur.execute('DROP TABLE IF EXISTS Ages')
cur.execute('CREATE TABLE Ages (name VARCHAR(128),   age INTEGER)')
cur.execute('DELETE FROM Ages')
cur.execute('INSERT INTO Ages (name, age) VALUES (?,?)', ('Athena', 19))
cur.execute('INSERT INTO Ages (name, age) VALUES (?,?)', ('Zainib', 25))
cur.execute('INSERT INTO Ages (name, age) VALUES (?,?)', ('Talise', 13))
cur.execute('INSERT INTO Ages (name, age) VALUES (?,?)', ('Khairah', 14))
cur.execute('INSERT INTO Ages (name, age) VALUES (?,?)', ('Kaydyn', 14))
cur.execute('INSERT INTO Ages (name, age) VALUES (?,?)', ('Jasmin', 28))
cur.execute('SELECT hex(name || age) AS X FROM Ages ORDER BY X')
cur.execute ('SELECT name, age FROM Ages')
for row in cur:
    print(row)







conn.close()
