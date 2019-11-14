a, b = input().split(' ')

minCount = 100
for i in range(len(b)):
    count = 0
    for j in range(0, len(a)):
        if a[j] != '.' and b[j] != a[j]: count += 1
    if count < minCount: minCount = count

    if len(a) + 1 <= len(b): a = '.' + a
    else: break

print(minCount)