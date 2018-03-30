# Week 10 lab
# Eli Peters and Eric Misner

import os
os.chdir("C:\\Users\\elp5\\Desktop\\bin\\Schoolwork\\CS 232 Python\\Labs")

#gettysburg str -> str
#purpose: Expects a single character
#returns: a string stating the number of words
#    in the Gettysburg Address that begin with that letter.
# CASE SENSITIVE
def gettysburg(letter):
    inpt_file = open("GettysburgAddress.txt", "rt")
    count = 0
    addr = inpt_file.read()
    wrd_lst = addr.split()
    for i in wrd_lst:
        if i[0] == letter:
            print(i)
            count += 1
    inpt_file.close()
    return ("There are " + str(count) + " words in the Gettysburg Address that start with " + letter + ".")


#count_sentences: str -> str
#Expects: the name of a file as a string
#Returns: a string describing how many sentences were found in the file.
def count_sentences(file):
    inpt_file = open(file)
    raw = inpt_file.read()
    count = 0
    wrd_list = raw.split()
    for i in wrd_list:
        if i[-1] == '.' or i[-1] == '!' or i[-1] == '?':
            count += 1
    outp = ""
    if count > 1:
        outp = "There are {c} sentences in {f}."
    elif count == 1:
        outp = "There is one sentence in {f}."
    else:
        outp = "There are no sentences in {f}."
    #outp.format(c = str(count), f = file)
    return outp.format(c = str(count), f = file)
