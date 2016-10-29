import random
from queue import *

number = int(input())
max_iter = int(input())

def generate_field(number):
  field = [['_' for x in range(number)] for y in range(number)]

  queens_indexes = random.sample([(x, y) for x in range(number) for y in range(number)], number)

  for (x, y) in queens_indexes:
    field[x][y] = '*'

  return field

def print_field(field):
  for row in field:
    print(row)

def count_in_row(row, col, field):
  res = sum([1 for x in range(0, number) if field[x][col] == '*'])
  return res - 1

def count_in_col(row, col, field):
  res = sum([1 for x in range(0, number) if field[row][x] == '*'])
  return res - 1

def count_in_diag(row, col, field):
  res = 0

  for x in range(row-1, number):
    for y in range(col-1, number):
      if field[x][y] == '*':
        res += 1

  for x in range(row+1, number):
    for y in range(col-1, number):
      if field[x][y] == '*':
        res += 1  

  for x in range(row+1, number):
    for y in range(col+1, number):
      if field[x][y] == '*':
        res += 1        

  for x in range(row-1, number):
    for y in range(col+1, number):
      if field[x][y] == '*':
        res += 1
  return res

def get_min_conflicts_by_row(field, column): 
  result = PriorityQueue()
  for row in range(number):
    if field[row][column] == '*':
      res = count_in_row(row, column, field) + count_in_col(row, colum, field) + count_in_diag(row, column, field)
      result.put(row, res) # sorted by res

  return result # should return the row    


def is_solution(field):
  for column in reversed(field):
    result = get_min_conflicts_by_row(field, column)
    return sum([1 for (row, res) in result if res != 0]) >= 1


# while(is_solution(field) == False):
field = generate_field(number)
i = 0

while ++i <= max_iter:
  for row in field:
    min_conflicts_row, _ = get_min_conflicts_by_row(field, column).get()
    field[min_conflicts_row][column] = '*'
    print(field)
    if(is_solution(field) == True):
      print_field(field)
      break

