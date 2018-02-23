# CS232-02-elp5.py
# Eli Peters
# Last modified: February 20, 2018

# Problem 1

# pig_latin: string -> string
# expects: any word
# returns: a pig latin version of that word
def pig_latin(the_word):
    vowels = ("a","e","i","o","u")
    if the_word[0].lower() in vowels:
        the_word += "-ay"
        return the_word
    elif the_word[1].lower() == "h":
        the_word = (the_word[2:] + "-" + the_word[:2] + "ay")
        return the_word
    else:
        the_word = (the_word[1:] + "-" + the_word[:1] + "ay")
        return the_word


# Problem 2

# pig_list: list -> list
# expects: a list of words
# returns: a list of those words run through pig_latin
def pig_list(the_list):
    new_list = []
    for i in the_list:
        new_list.append(pig_latin(i))
    return new_list


# Problem 3

# letter_freq: string -> dictionary
# expects: any string
# returns: a dictionary with the keys as the letters of the
#       alphabet, and the values as the number of times that
#       letter appears in the string.  Letters which don't
#       appear are not included in the dictionary.
def letter_freq(the_string):
    alphabet = ('a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z')
    new_dict = {}
    for i in alphabet:
        if the_string.lower().count(i) > 0:
            new_dict.update({i:the_string.lower().count(i)})
    return new_dict


# Problem 4

# letter_freq_chart: dict -> void
# expects: a dictionary with letters as the keys and numbers as the values
# returns: nothing
# side effects: prints a graph of the number associated with each letter
def letter_freq_chart(the_dict):
    print("LETTER FREQUENCY CHART:")
    for i in the_dict:
        print(i, end=": ")
        for j in range(0, the_dict[i]):
            print("X", end="")
        print()


# Problem 5

test_points = { 'a':(4,3), 'b':(1,2), 'c':(5,1) }

# HELPER FUNCTIONS:
# coord_max: dict, int -> int
# expects: a dictionary with letters as the keys and a tuple containing a pair of coordinates as the value
#           and an int containing either 0 or 1
# returns: the largest x or y coodinate, as determined by 0 or 1 respectively
def coord_max(the_dict, xory):
    maximum = 0
    for i in the_dict:
        if maximum < the_dict[i][xory]:
            maximum = the_dict[i][xory]
    return maximum

# print_grid: list int int -> void
# Expcects: a list of lists and the width thereof, returns nothing
# Side effects: prints the contents of each internal list onto a new line\
def print_grid(the_grid, the_width):
    for i in range(0, len(the_grid)):
        print((len(the_grid) - i)-1, end="")
        for j in range(0, len(the_grid[i])):
            print(the_grid[i][j], end="")
        print()
    print(" ", end = "")
    for i in range(0, the_width+1):
            print(i, end="")

# plot_points: dict -> void
# expects: a dictionary with letters as the keys and a tuple containing a pair of coordinates as the value
# returns: nothing
# side effects: prints a plot of those letters at the corresponding coordinates.
def plot_points(the_dict):
    max_x = coord_max(the_dict, 0)
    max_y = coord_max(the_dict, 1)
    grid = []
    for i in range(0, (max_y + 1)):
        grid.append([])
        for j in range(0, (max_x + 1)):
            grid[i].append('.')
    for i in the_dict:
        x = (the_dict[i][0])
        y = (max_y - the_dict[i][1])
        grid[y][x] = i
    print_grid(grid, max_x)
