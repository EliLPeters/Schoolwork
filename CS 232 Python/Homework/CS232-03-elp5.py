# CS232-03-___.py
# Name:
# Last Modified:

# Adapted from MIT 6.189, MIT Open Courseware
# Used by permission of Creative Commons license
# Adapted for use in CS 232 by David Tuttle

# Import statements: DO NOT write code above this!

from random import randrange
from string import *
import os

# Uncomment the next statement and insert the path to the
# directory where your Python module and words.txt files
# are located. This makes loading the words.txt file work

# os.chdir(" ")

###################################################################
# Helper code - DO NOT ALTER ANY OF THE HELPER CODE!
# You don't need to fully understand this helper code,
# but it's a good idea to read it and see what it does

# Define name of file containing the dictionary of words

WORDLIST_FILENAME = "words.txt"

# load_words: void -> list
# expects nothing
# returns a list of words read from the WORDLIST_FILENAME

def load_words():
    '''
    Returns a list of valid words. Words are strings of lowercase
    letters.

    Depending on the size of the word list, this function may
    take a while to finish.
    '''
    print("Loading word list from file...")
    # inFile is a file handle - we'll discuss this later :-)
    inFile = open(WORDLIST_FILENAME, 'rt')
    # line is a string to hold the contents of the file
    line = inFile.readline()
    # wordlist is a list of words found in the file
    wordlist = line.split()
    
    print("  ", len(wordlist), "words loaded.")
    print('Enter play_hangman() to play a game of Hangman!')
    return wordlist

# We run the load_words() function to get the list of words.
# The list_of_words variable is global so it can be used
# in any of the functions defined in this module

list_of_words = load_words()

# You will run get_word() within your play_hangman() function
# to randomly select a secret word by using a statement like
# this within your function:

# secret_word = get_word()

# get_word: void -> str
# expects nothing
# returns a word rendomly selected from the file "words.txt"

def get_word():
    '''
    Retrieves a random word from the list of available words
    '''
    chosen_word = list_of_words[randrange(0, len(list_of_words))]
    return chosen_word

# NOTE: original ASCII images created by internet artist sk
#       replaced with smaller images by David Tuttle

# print_hangman_image: int -> void
# expects an integer for the number of incorrect guesses so far
# returns nothing
# side effect: prints to the screen a drawing of the Hangman
#     game based on the number of incorrect guesses

def print_hangman_image(mistakes=6):
  '''
  Prints out a gallows image for hangman.
  The image printed depends on the number of mistakes (0-6).
  '''

  if mistakes <= 0:
    print('''
        __________
        |    |       
        |
        |
        |
        |
        |_________
        ''')

  elif mistakes == 1:
    print('''
        __________
        |    |       
        |    O
        |
        |
        |
        |_________
        ''')
  elif mistakes == 2:
    print('''
        __________
        |    |       
        |    O
        |    |
        |    |
        |
        |_________
        ''')
  elif mistakes == 3:
    print('''
        __________
        |    |       
        |    O
        |   /|
        |    |
        |
        |_________
        ''')
  elif mistakes == 4:
    print('''
        __________
        |    |       
        |    O
        |   /|\\
        |    |
        |   
        |_________
        ''')
  elif mistakes == 5:
    print('''
        __________
        |    |       
        |    O
        |   /|\\
        |    |
        |   /
        |_________
        ''')
  else: # mistakes >= 6
    print('''
        __________
        |    |       
        |    O
        |   /|\\
        |    |
        |   / \\
        |_HANGED!_

        ''')
  
# End of helper code - DO NOT ALTER HELPER CODE!
###################################################################


# USEFUL CONSTANTS
# DO NOT change value of MAX_GUESSES!
MAX_GUESSES = 6

# GLOBAL VARIABLES (with default values)
secret_word = 'claptrap' 
letters_guessed = []

# THE FOLLOWING IS TO BE COMPLETED BY THE STUDENT

# word_guessed: void -> bool
# expects nothing
# returns True if the word (stored in secret_word) has been
#     completely guessed, based on the letters_guessed list
#     returns False otherwise

def word_guessed():
    '''
    Returns True if the player has successfully guessed the word,
    and False otherwise.
    '''
    global secret_word
    global letters_guessed

    ####### YOUR CODE HERE ######
    for i in secret_word:
        if i not in letters_guessed:
            return False
    return True


# print_guessed: void -> void
# expects nothing, returns nothing
# side effect: prints to the screen (on one line) the letters
# of the secret word that have been guessed, and "_" for the
# letters that haven't yet been guessed

# For example, if the word is "claptrap" and the letters
# guessed so far are ['a', 'e', 'p', 't'] then it should print:
# _ _ a p t _ a p

def print_guessed():
    '''
    Prints out the secret word, revealing only those letters
    that have been guessed so far
    '''
    global secret_word
    global letters_guessed
    
    ####### YOUR CODE HERE ######
    for i in secret_word:
        if i in letters_guessed:
            print(i, end=" ")
        else:
            print('_', end=" ")


# play_hangman: void -> void
# expects nothing, returns nothing
# side effects:
# This function controls the playing of the game Hangman by:
# -- choosing a secret word
# -- asking the player for letters to guess, one at a time
# -- displaying the Hangman image after each guess
#    (by calling the function print_hangman_image)
# -- displaying the word as guessed so far after each guess
#    (by calling the function print_guessed)
# -- When the word has been completely guessed, tell the
#    user they've won! (Use the word_guessed function for this)
# -- If the word's not completely guessed before the allowed
#    number of mistakes, tell the user they've lost and reveal
#    the word they didn't get

def play_hangman():
    '''
    Plays the Hangman game!
    '''
    global secret_word
    global letters_guessed
    
    # Set the wrong_guesses variable here, since you'll use it
    # only within this function.  Increment for each wrong guess
    wrong_guesses = 0

    # Get the secret word to start play.
    # For debugging purposes, don't uncomment the line below,
    # and the word will always be "claptrap".  This will help
    # you test your function.  When you're confident your
    # function works, un-comment the line below to let the
    # computer select a word at random.

    secret_word  = get_word()
    letters_guessed = []

    ####### YOUR CODE HERE ######

    print("Welcome to HANGMAN!!!\nAre you kids ready for an execution? :D")

    print_hangman_image(wrong_guesses)
    print()
    print_guessed()
    guess = input("\nPlease enter your first guess: ")
    letters_guessed += guess
    if guess not in secret_word:
        wrong_guesses += 1

    while(wrong_guesses < 6 and not word_guessed()):
        
        print_hangman_image(wrong_guesses)
        print()
        print_guessed()
        print("\nYour guesses: ", end="")
        for i in letters_guessed:
            print(i, end=" ")
        guess = input("\nPlease enter your next guess: ")
        letters_guessed += guess
        if guess not in secret_word:
            wrong_guesses += 1

    if word_guessed():
        print("\nAw, you got away. :c")
        print("You correctly guessed the word ", secret_word, ".", sep = "")
        print("Next time I'll get you...")
    else:
        print_hangman_image(wrong_guesses)
        print("Congratulations you lost!")
        print("You failed to guess the word ", secret_word, "!", sep="")

    # Leave this return line as is
    return None

    
