def computepay(hours, rate):
    if hours > 40:
        extraHours = hours - 40
        hours = 40
    pay = hours*rate + extraHours*rate*1.5
    print('Pay: ',pay)

#Main
inp = input('Enter Hours: ')
checker = False
while checker is not True:
    try:
        hours = int(inp)
        checker = True
    except:
        print('Type a number type')
        inp = input('Enter Hours: ')
inp = input('Enter Rate: ')
checker = False
while checker != True:
    try:
        rate = int(inp)
        checker = True
    except:
        print('Type a number type:')
        inp = input('Enter Hours: ')
computepay(hours, rate)
