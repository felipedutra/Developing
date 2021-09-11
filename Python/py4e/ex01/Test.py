hrs = input("Enter Hours:")
h = float(hrs)
rate = input("Enter rate:")
r = float(rate)
pay = 0.0
pay = float(pay)
if h > 40.0:
    h = h - 40.0
    pay = 40*rate
    extraRate = 1.5
    pay = pay + extraRate*h*rate
else:
    pay = h*rate
print (pay)
