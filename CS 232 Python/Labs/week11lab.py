# CS 232 Sprint 2018
# Lab 11
# Eli Peters and Pablo Nambo

import math

class Car:
    def __init__(self, x_pos, y_pos):
        self.x_position = x_pos
        self.y_position = y_pos
        self.direction = 0
        self.speed = 0

    def turn(self, left_or_right):
        #left_or_right is a string, "left" or "right"
        if(left_or_right == 'left'):
            self.direction -= 1
        else:
            self.direction += 1
        if(self.direction < 0):
            self.direction = 3
        elif(self.direction > 3):
            self.direction = 0

    def drive(self, time):
        #You may assume that time is a non-negative integer
        if(self.direction == 0):
            self.y_position += (self.speed * time)
        elif(self.direction == 1):
            self.x_position += (self.speed * time)
        elif(self.direction == 2):
            self.y_position -= (self.speed * time)
        else:
            self.x_position -= (self.speed * time)

    def print_status(self):
        print("Current position is ({}, {})".format(self.x_position, self.y_position))
        print("Current speed is {}".format(self.speed))
        if(self.direction == 0):
            print("Current direction is up")
        elif(self.direction == 1):
            print("Current direction is right")
        elif(self.direction == 2):
            print("Current direction is down")
        else:
            print("Current direction is left")
        print()


    def accelerate(self, amount):
        # amount may be a positive or negative integer
        #   that increases or decreases the speed of the car
        self.speed += amount

    def stop(self):
        #set speed to zero
        self.speed = 0

    def distance_from_origin(self):
        hypo2 = (self.x_position * self.x_position) + (self.y_position * self.y_position)
        s_hypo = "Distance from 0,0 is {0:.2f} units".format(hypo2**(1/2))
        return s_hypo
        
my_car = Car(0,0)
my_car.print_status()
my_car.accelerate(10)
my_car.drive(3)
my_car.print_status()
my_car.turn('left')
my_car.drive(2)
my_car.print_status()
my_car.stop()
my_car.print_status()
print(my_car.distance_from_origin())
