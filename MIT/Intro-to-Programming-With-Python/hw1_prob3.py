sLen = len(s)
maxInOrder = 1
maxStart = 0
currInOrder = 1
maxEnd = 1
i = 1
while (i < sLen):
    if(s[i] >= s[i-1]):
        currInOrder += 1
    else:
        if(maxInOrder < currInOrder):
            maxInOrder = currInOrder
            maxEnd = i
        currInOrder = 1
    i += 1
if(maxInOrder < currInOrder):
    maxInOrder = currInOrder
    maxEnd = i

print("Longest substring in alphabetical order is: " + s[maxEnd-maxInOrder:maxEnd])