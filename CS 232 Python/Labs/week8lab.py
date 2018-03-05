# CS 232 Week 08 Lab
# Eli Peters and Mikel Maiorga

from collections import Counter

vowels = "aeiou"

# more_vowels: string string -> int
# expects: a pair of strings
# returns: 1 if the first string has more vowels
#           2 if the second, and 0 if they are equal.
# side effects: prints a message to the screen explaining
#               the outcome.
def more_vowels(string1, string2):
    dict1 = {}
    dict2 = {}

    count1 = 0
    count2 = 0

    dict1 = dict(Counter(string1.lower()))
    dict2 = dict(Counter(string2.lower()))

    for i in vowels:
        dict1.setdefault(i, 0)
        dict2.setdefault(i, 0)

    for i in vowels:
        count1 += dict1[i]
        count2 += dict2[i]

    if(count1 > count2):
        print(string1, "has more vowels than", string2)
        return 1
    elif(count2 > count1):
        print(string2, "has more vowels than", string1)
        return 2
    else:
        print(string1, "and", string2, "have the same number of vowels.")
        return 0
