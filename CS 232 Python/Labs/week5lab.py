# CS 232 Spring 2018 - Week 05 lab
# Eli Peters and John Mackin

while(True):
    inLet = input("Enter a letter. 'x' escapes: ")
    if inLet == 'x':
        break

for i in range(0, 30):
    if i % 3 == 0:
        continue
    print(i, end=" ")

my_list = [x for x in range(0,30) if x % 3 != 0]

alphabet = 'abcdefghijklmnopqrstuvwxyz'
alpha_dict = {x+1:alphabet[x] for x in range(0,26)}

# args -> list
# Expects: any number of strings
# Returns: a list of those strings
def string_list(*args):
    the_list = []
    for i in args:
        if(type(i) == str):
            the_list.append(i)
    return the_list

my_tuple = (( 0,1,2,3,4,5,6,7,8),
	    (10,11,12,13,14,15),
	    (20, 21,22,23),
	    (30,31,32,33,34,35,36,37),
	    (40,41,42,43,44,54))

# tuple(tuple), int -> list
# Expects: a tuple of tuples, and a non-negative integer
# Returns: the values of all internal tuples at that index
def list_at_index(the_tuple_abomination, the_index):
    the_list = []
    for i in the_tuple_abomination:
        if len(i) > the_index:
            the_list.append(i[the_index])
        else:
            the_list = []
            break
    return the_list
