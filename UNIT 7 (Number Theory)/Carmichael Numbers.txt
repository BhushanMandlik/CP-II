#Carmichael Numbers
#SieveOfEratosthenes ---> O(Nlog(log N))
#if number is prime then number is normal number (not a Carmichael Number)
#if number is notprime then number is Carmichael number

ls = []
def SieveOfEratosthenes(n):
    prime = [True for i in range(n + 1)]
    p = 2
    while (p * p <= n):
        if (prime[p] == True):
            for i in range(p*p, n+1, p):
                prime[i] = False
        p += 1
    for p in range(2, n + 1):
        if prime[p]:
            ls.append(p)        #this list contains only primes numbers < 65000
    #print(ls)
SieveOfEratosthenes(65000)

while True:
    n = int(input())
    if(n==0):
        break
    elif(n in ls):   #means n is prime number
        print("{} is normal.".format(n))
    else:
        print("The number {} is a Carmichael number.".format(n))

'''
1729
17
561
1109
431
0

The number 1729 is a Carmichael number.
17 is normal.
The number 561 is a Carmichael number.
1109 is normal.
431 is normal.
'''