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
