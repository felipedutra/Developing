import re

fhand = open('nomeFundos.txt')
codigosFundos = []
x = {}
for lines in fhand:
    line = lines.split()
    #print(line)
    if len(line) == 0: continue
    codigosFundos.append(line)



#x = {}
fwrite= open("dados.txt","w")
i = 0
for codigo in codigosFundos:
    nome = str(codigo)
    pattern =  nome[2:8] +'\S+\s\S+'
    pattern2 =  "valor_atual_cota" +'\S+\s\S+'
    print(pattern2)
    fhandle = open("html.txt")
    for lines in fhandle:
        found = re.findall(pattern, lines)
        found2 = re.findall(pattern2, lines)
        if (found):
            #print(str(found) + '\n')
            #x[str(codigo)[2:8]] = found
            fwrite.write(str(found)+ '\n')
        if (found2):
            #print(str(found2) + '\n')
            #x[str(codigo)[2:8]] = found
            fwrite.write(str(found2)+ '\n')
            
fwrite.close()

