str = input()

if len(str) <= 1:
    print(str)
    exit()

suffix = []

for i in range(1, len(str) + 1): #get suffix
    suffix.append(str[len(str) - i:len(str)])

suffix = sorted(suffix) #sort suffix

for i in range(len(suffix)):
    print(suffix[i])