numberList = list()
while True:
    number = input('Enter a number:')
    if number == 'done':
        break
    try:
        x = int(number)
    except:
        print('Invalid input!')
        continue
    numberList.append(x)
print(max(numberList),min(numberList))
