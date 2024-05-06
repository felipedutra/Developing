from pandas_datareader import data as web
from datetime import datetime
import pandas as pd 
import re


i = 0

df = pd.DataFrame({'Código': codigo, 'Valor Patrimonial': valor_Patrimonial, 'Valor Patrimonial por Cota': valor_Patrimonial_por_cota, 'Valor de Mercado': valor_de_Mercado, 'Valor Yield': valor_Yield, 'Valor Yield 12 Meses': valor_Yield_12_meses})
df['Código'] = codigo


df.to_excel("dados.xlsx", index=False)