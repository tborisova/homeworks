import random
from queue import *

number = int(input())
max_iter = int(input())

def generate_field(number):
  field = [['_' for x in range(number)] for y in range(number)]

  return field

def get_random_position_for_queen(number):
  [(x, y)] = random.sample([(x, y) for x in range(number) for y in range(number)], 1)
  return (x, y)

field = generate_field(number)
print(field)
x, y = get_random_position_for_queen(number)
print("x: {0} y: {1}".format(x, y))
