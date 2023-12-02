from pandas_datareader import data as web
from datetime import datetime
import pandas as pd 
import re
fhandle = open("dados.txt")
dados = [] #Vetor de leitura do arquivo
quantidade_de_Cotistas = [] #Vetor de quantidade de Cotistas
codigo = [] # Vetor de códigos
cotacao = [] # Vetor de cotações
valor_Patrimonial = [] # Vetor de valores patrimoniais
valor_Patrimonial_por_cota = [] # Vetor de valores patrimoniais por cota
valor_de_Mercado = [] # Vetor de valores de mercado
valor_Yield = [] # Vetor de yields
valor_Yield_12_meses = [] # Vetor de yields de 12 meses
tipo_de_Fii = [] # Vetor de tipos de FII

fhand = open('nomeFundos.txt')
codigosFundos = []
x = {}
for lines in fhand:
    line = lines.split()
    #print(line)
    if len(line) == 0: continue
    codigosFundos.append(str(line)[2:8])
#print(codigosFundos)
while (lines):
    lines = fhandle.readline()
   #print(lines)
    valorCot = re.findall('valor_atual_cota', lines)
    line = lines.split()
    if (valorCot):
        #print(lines)
        #print(line[1])
        text = line[1]
        text = text.replace('>', ' ')
        text = text.split()
        text = text[1]
        #print(text)
        line[1] = text
        line[1] = line[1].replace( "\']","")
        #print(line[1])
        dados.append(line[1])
    
    elif(line):
        line[1] = line[1].replace( "\']","")
        #print( line[1])
        dados.append(line[1])
#print(dados)
i = 0
#print(cotacao)
while i < len(dados):
    if(str(dados[i]) in codigosFundos):
        print (dados[i +7])
        codigo.append(dados[i])
        cotacao.append(dados[i+2])
        valor_Patrimonial.append(dados[i+4])
        valor_de_Mercado.append(dados[i+6])
        valor_Yield.append(dados[i+8])
        valor_Yield_12_meses.append(dados[i+9])
        valor_Patrimonial_por_cota.append(dados[i+10])
        quantidade_de_Cotistas.append(dados[i+11])
        #print(dados[i])
    i += 1
df = pd.DataFrame({'Código': codigo, 'Valor Patrimonial': valor_Patrimonial, 'Valor Patrimonial por Cota': valor_Patrimonial_por_cota, 'Valor de Mercado': valor_de_Mercado, 'Valor Yield': valor_Yield, 'Valor Yield 12 Meses': valor_Yield_12_meses})
df['Código'] = codigo
df["Valor de Mercado"] = valor_de_Mercado
df["Cotação"] = cotacao
df["P/VPA"] = valor_Patrimonial_por_cota 
df["Quantidade de Cotistas"] = quantidade_de_Cotistas 
df['Valor Patrimonial'] = valor_Patrimonial
df["Valor Yield"] = valor_Yield
df["Valor Yield 12 Meses"] = valor_Yield_12_meses

df.to_excel("dados.xlsx", index=False)