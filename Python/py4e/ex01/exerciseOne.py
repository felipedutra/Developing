inp =input('Enter Hours: ')
hours = int(inp)
if hours > 40:
    extraHours = hours - 40
    hours = 40
inp = input('Enter Rate: ')
rate = int(inp)
print('Pay: ',hours*rate + extraHours*rate*1.5)
