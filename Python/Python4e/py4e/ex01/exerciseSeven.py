#def
def computeNote(score):
    str = ' '
    if score >= 0.9:
        str = 'A'
    elif score >= 0.8:
        str = 'B'
    elif score >= 0.7:
        str = 'C'
    elif score >= 0.6:
        str = 'D'
    else:    str = 'F'
    return str
#Main
score = 1
while(score != 99):

    inp = input ('Enter score: ')
    checker = False
    while checker != True:
        try:
            score = float(inp)
            checker = True
        except:
            print('Bad score')
            inp = input ('Enter score: ')

    str = computeNote(score)
    print(str)
