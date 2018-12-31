numBob = 0

sLen = len(s)

for i in range(sLen):
    if ((i + 2 < sLen) and (s[i:i+3] == 'bob')):
        numBob += 1
        
print("Number of times bob occurs is: " + str(numBob))