str = input()
bomb = input()

result = []

for i in str:
    result.append(i)
    if result[-len(bomb):] == list(bomb): #stack
        for j in bomb:
            result.pop()

if len(result) == 0:
    print("FRULA")
else:
    print(''.join(result))