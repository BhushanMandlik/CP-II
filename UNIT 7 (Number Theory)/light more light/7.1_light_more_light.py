#Light, More Light problem
#A man named Mabu who switches on-off the lights along a corridor
#he toggles only the switches whose position is divisible by i
#here we have to find out the state of final bulb is on or off
#Initially each bulb is off
#numbers that are not perfect squares have an even number of factors.
#Perfect squares have an odd number of factors
#count(factors) == (even) ---> bulb is off
#count(factors) == (odd) ---> bulb is on

from math import sqrt
while True:
  n = int(input())
  if n == 0:
    break
  sq = sqrt(n)
  print('yes' if (sq*sq == n) else 'no')

"""
3
6241
8191
0

no
yes
no
"""