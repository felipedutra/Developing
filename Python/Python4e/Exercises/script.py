def secMax(vetor):
    sec_max = 0
    max = 0
    for i in range (len(vetor)):
        if vetor[i] > max:
            sec_max = max
            max = vetor[i]
        elif vetor[i] > sec_max:
            sec_max = vetor[i]
    print(sec_max)

vetor = [1, 2, 3, 4, 5, 6, 7, 11, 9, 10]
secMax(vetor)

def intPrime(n):
    if n == 1:
        return False
    for i in range(2, n):
        if n % i == 0:
            return False
    return True