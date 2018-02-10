# CS 232 Spring 2018 Week 03 Lab
# Eli Peters and Pablo Nambo

# Problem 1

# c_to_f: float -> float
# purpose: expects a temperature in celsius
#   returns equivalent temperature in fahrenheit
def c_to_f(celsius_temp):
    return ((celsius_temp * 1.8) + 32)


# Problem 2

# c_to_f_check: float -> float
# purpose: expects a temperature in celsius
#   returns equivalent temperature in fahrenheit, but returns -9999
#       if the input is below absolute zero (-273.16 C)
def c_to_f_check(celsius_temp):
    if(celsius_temp >= -273.16):
        return c_to_f(celsius_temp)
    else:
        print("Temperature is too low!")
        return -9999


# Problem 3

# yell_it: object -> void
# purpose: expects an object of any type and returns nothing
# side effects: if the object is a string it is printed to the screen
#   in all caps followed by three exclamations marks.  If the object
#   is not a string instead prints "Not a String!!!"
def yell_it(an_object):
    if(type(an_object) == str):
        print(an_object.upper() , "!!!")
    else:
        print("Not a String!!!")


# Problem 4

# divisible_by: int -> void
# purpose: expects an integer, returns nothing
#   side effects: prints to the screen whether that number is divisible by
#       2, 3, 4, etc through 10 inclusive
def divisible_by(an_int):
    for x in range (2, 11):
        if((an_int % x) == 0):
            print( an_int, "is divisible by", x)
        else:
            print( an_int, "is not divisible by", x)


# Problem 5

# test_demorgan: bool, bool -> bool
# purpose: expects any two boolean values
#   returns whether or not demorgans law works for them
def test_demorgan(bool_p, bool_q):
    return (((not (bool_p and bool_q)) == (not(bool_p) or not(bool_q)) and (not (bool_p or bool_q)) == (not bool_p and not bool_q)))
