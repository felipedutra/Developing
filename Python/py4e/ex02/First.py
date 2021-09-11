#Main
print("Hello there: ")
count = 0
imp = " "
sum = 0
while imp != 'done':
    imp = input("Enter a number: ")
    try:
        x = int(imp)
        sum = sum + x
        count = count + 1
    except:
        print("Invalid input")
print(sum, count, sum/count)
