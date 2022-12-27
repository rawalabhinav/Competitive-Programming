from random import randrange as rand

# n = rand(1, 10)
# print(n)
# for i in range(n) :
#     print(rand(1,8), end=' ')

x = 0
for i in range(1, 12):
    x =  x  ^ i
    print(x)