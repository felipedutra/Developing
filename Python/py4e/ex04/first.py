#Hello there
def chop(t):
    del t[0]
    del t [len(t) - 1]
    return
def middle(t):
    new_list = t[1:len(t) - 1]
    return(new_list)

t1 = [1,2,3,4,5,6,7,8,9,0]
print(t1)
t2 = middle(t1)
print(t2)
