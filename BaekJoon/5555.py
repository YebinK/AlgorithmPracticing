find = input()                  #string to find
n = int(input())                #number of rings

rings = []
for i in range(n):
    rings.append(input() * 2)   # act like linked list

count = 0
for i in range(n):
    if find in rings[i]: count += 1

print(count)