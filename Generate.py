from random import randrange as rand
from math import gcd

n = rand(3,8)
c = [[] for i in range(n)] 

for i in range(n):
    k = rand(1,9)

    for j in range(k):
        c[i].append(rand(1,10))

print(n)
for x in c:
    print(*set(x))







 
