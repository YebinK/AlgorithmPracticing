str = input().upper()

dict = {}

if len(str) == 1:                                   #length 1
    print(str)
    exit()

for i in range(len(str)):                           #count alphabet
    if str[i] in dict:
        dict[str[i]] += 1
    else:
        dict[str[i]] = 1

dict = sorted(dict.items(), key = lambda k : k[1])  #sort dict
index = len(dict) - 1

if dict[index][1] == dict[index-1][1]:
    print("?")
else:
    print(dict[index][0])