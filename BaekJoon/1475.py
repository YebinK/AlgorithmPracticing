roomNo = input()
count = 1
numLeft = [count] * 10                      #left plastic set (0~9)

for i in range(len(roomNo)):
    roomInt = int(roomNo[i])
    if numLeft[roomInt] <= 0:               #if no plastic set left,
        if roomInt == 6 and numLeft[9] > 0:     #6 -> 9 replacable
            numLeft[9] -= 1
            continue
        elif roomInt == 9 and numLeft[6] > 0:   #9 -> 6 replacable
            numLeft[6] -= 1
            continue
        count += 1
        for j in range(10):                 #add new set
            numLeft[j] += 1
    numLeft[roomInt] -= 1                   #use plastic set

print(count)