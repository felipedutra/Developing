fhandle = open ('nomes.txt', 'r')
for line in fhandle:
    line = line.rstrip()
    if line.startswith('From:'):
        print(line)