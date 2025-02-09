from os import link
from googlesearch import search
import sqlite3
import re
 
dados = [] #Vetor de leitura do arquivo
links = [] #Vetor de links
nomes = [] #Vetor de nomes
desvios = [] #Vetor de desvios 

fhandle = open("nomes.txt") # Arquivo com os nomes a serem pesquisados no Google 
for lines in fhandle:
    if len(lines) == 0: continue
    nomes.append(lines)
fhandle.close()






for i in nomes:
    query = str(i) 
    links.append("\n" +"Pesquisando: " + query )
    #Pesquisa em Português
    for k in search(query, lang = "pt", tld="com.br", num=4, stop=10, pause=2):
        links.append(k)
    for k in search(query, lang = "en", tld="com", num=4, stop=10, pause=2):
       links.append(k)       
# Escrevendo os dados em arquivo
fwrite = open("resultados.txt", "w")

for i in links:
    fwrite.write(str(i) + "\n")
fwrite.close()
