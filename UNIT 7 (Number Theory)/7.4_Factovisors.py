#Factovisors
#check second number divides factorial(first number) or not

while True:
    m,n = map(int, input().split())
    fact = 1
    for i in range(1, m+1):
        fact = fact * i
    if (fact % n == 0):
        print(n,'divides',m,'!')
    else:
        print(n, 'does not divides', m, '!')

'''
6 9
6 27
20 10000
20 100000
1000 1009

9 divides 6!
27 does not divide 6!
10000 divides 20!
100000 does not divide 20!
1009 does not divide 1000!
'''