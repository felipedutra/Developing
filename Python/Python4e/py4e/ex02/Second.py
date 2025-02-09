#Main
print("Hello there: ")
maximum = None
imp = " "
minimum = None
while imp != 'done':
    imp = input("Enter a number: ")
    try:
        x = int(imp)
    except:
        print("Invalid input")
    if maximum is None or maximum < x:
        maximum = x
    if minimum is None or minimum > x: 
        minimum = x

print(maximum, minimum)
