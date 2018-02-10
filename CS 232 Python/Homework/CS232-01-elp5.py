# CS232-01-elp5.py
# Eli Peters
# Last Modified February 6th, 2018

# Problem 1
# multiples_in_range: int int int -> int
# Expects three integers.  The second and third indicate a range, while
#   the first is the number we are looking for multiples of therein.
#   Returns the number of multiples of the first number within that range.
# Side Effects: prints to the screen the specific multiples in that range.
def multiples_in_range(factor, low, high):
    total_multiples = 0
    for i in range ((low + 1), high):
        if (i % factor == 0):
            total_multiples += 1
            print(i)
    return total_multiples

# Problem 2
# letter_grade: float -> string
# Expects a Float representing a numeric grade.
# Returns a string representing the corresponding letter grade
# Side Effects: prints the letter grade to the screen.
def letter_grade(score):
    the_grade = "E" # If E is ever returned we will know something's gone wrong.
    if(score >= 90):
        the_grade = "A"
    elif(score >= 80):
        the_grade = "B"
    elif(score >= 70):
        the_grade = "C"
    elif(score >= 60):
        the_grade = "D"
    else:
        the_grade = "F"
    print(the_grade)
    return the_grade

# Problem 3
# bump_it: any -> any
# expects data of any type
# Returns that data modified as follows:
#   Int: adds one
#   Float: adds 0.1
#   String: appends an exclamationmark
#   Bool: inverts the value
#   Any other: no changes
def bump_it(val):
    if type(val) == int:
        return (val + 1)
    elif type(val) == float:
        return (val + 0.1)
    elif type(val) == str:
        return (val + "!")
    elif type(val) == bool:
        return (not val)
    else:
        return val

# Problem 4
# my_nickname: string -> string
# Expects a string representing someone's name
# Returns a nickname with the following system:
#   If the name is less than 5 letters it is left unaltered.
#   If the name is more than 5 letters it is shortened to 5 letters.
#       If the fifth letter is 'Y', it is removed
#       If the fifth letter is not 'Y', a 'Y' is appended to the name
def my_nickname(the_name):
    if (len(the_name) < 5):
        return the_name
    else:
        if (the_name[4] == "y"):
            return the_name[0:4]
        else:
            return (the_name[0:5] + "y")

# Problem 5
# flip_case: string -> string
# Expects a string
# Returns that string with the case flipped.
#   If the string has a mixed case it only flips the first character.
def flip_case(the_string):
    if (the_string.isupper()):
        return the_string.lower()
    elif (the_string.islower()):
        return the_string.upper()
    else:
        return (the_string[0].swapcase() + the_string[1:])

# Problem 6
# fibonacci_list: int -> list
# Expects an integer of at least 2
# Returns a list containing the fibonaci sequence to that index.
def fibonacci_list(the_int):
    prev1 = 0
    prev2 = 0
    the_list = []
    for i in range(0, the_int):
        entry = prev1 + prev2
        the_list.append(entry)
        prev2 = prev1
        prev1 = entry
        if (prev1 == 0 and prev2 ==0):
            prev1 = 1
    return the_list
