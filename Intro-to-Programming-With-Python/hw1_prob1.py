numVowels = 0
for c in s:
    if c == 'a' or c == 'e' or c == 'i' or c == 'o' or c == 'u':
        numVowels += 1

print("Number of vowels: " + str(numVowels))