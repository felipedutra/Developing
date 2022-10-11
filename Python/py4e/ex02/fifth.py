str = 'X-DSPAM-Confidence: 0.8475'
atpos = str.find(':')
print(atpos)
x = str[atpos + 2:]
print(x)
x = float(x)
print('%g is a float now'% (x))
