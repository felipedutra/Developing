inp =input('Enter Hours: ')
checker = False
while checker is not True:
    try:
        hours = int(inp)
        checker = True
    except:
        print('Type a number type')
        inp =input('Enter Hours: ')
if hours > 40:
    extraHours = hours - 40
    hours = 40
inp = input('Enter Rate: ')
checker = False
while checker != True:
    try:
        rate = int(inp)
        checker = True
    except:
        print('Type a number type:')
        inp =input('Enter Hours: ')

print('Pay: ',hours*rate + extraHours*rate*3/2)
