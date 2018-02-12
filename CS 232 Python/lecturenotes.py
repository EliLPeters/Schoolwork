# CS 232 Spring 2018 Week 03 Lab
# Eli Peters

# Problem 1

# add3: float -> float
# purpose: expects a number
#   returns that number + 3
# side effects: writes to the screen "woof"

def add3(a_number):
    return (a_number + 3)

x = 0
while True:
    x+=1
    if x > 10:
        break

y = 0
while y < 20:
    y += 1
    if (y % 10 == 0):
        continue
    print(y)
