# CS 232 Spring 2018 - Week 06 Lab
# Eli Peters and Elizabeth Lujan

import random

# generator for rolling 2 six-sided dice
def dice_roller():
    while True:
        roll1 = random.randint(1, 6)
        roll2 = random.randint(1, 6)
        yield (roll1 + roll2)

roll_dice = dice_roller()

# play_craps: void -> bool
# Expects Nothing
# Returns a bool representing whether the player won or lost
def play_craps():
    point = 0
    for i in roll_dice:
        if i == 7 or i == 11:
            return True
        elif i == 2 or i == 3 or i == 12:
            return False
        else:
            point = i
        break

    for i in roll_dice:
        if i == point:
            return True
        elif i == 7:
            return False
        
        
            
# run_trials: int -> void
# Expects a number of trials to play craps
# Returns NOTHING
# Side Effects: prints out how many games were won/lost, and the victory rate
def run_trials(num_trials):
    wins = 0
    losses = 0
    for i in range(0, num_trials):
        if play_craps():
            wins += 1
        else:
            losses += 1
    ratio = ((wins / num_trials) * 100)
    print("Wins: ", wins)
    print("Losses: ", losses)
    print("Winrate: ", ratio, "%")
    print("Don't pass")
