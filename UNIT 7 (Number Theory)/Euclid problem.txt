#Euclid Algorithm
#AX + BY = D
#here, D is gcd of 2 entered numbers (A & B)

def gcd(a,b):
    x,y,lx,ly = 0,1,1,0
    while b:
        q = a // b
        a,b = b, a%b         #run this loop while b!=0
        x,lx = (lx - q*x), x
        y,ly = (ly - q*y), y
    return lx,ly,a

while True:
    a,b = map(int,input().split())
    A, B, D = gcd(a,b)
    print(A,B,D)

'''
4 6
17 17

-1 1 2
0 1 17
'''