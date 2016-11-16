import random
from queue import *

number = int(input())
max_iter = int(input())

def generate_field(number):
  field = [['_' for x in range(number)] for y in range(number)]

  for x in range(number):
    field[x][random.randint(0, number - 1)] = '*'

  return field

def print_field(field):
  for row in field:
    print(row)

def count_in_diag(row, col, field):
  res = 0
  if row - 1 >= 0 and col - 1 >= 0:
    temp_row = row - 1
    temp_col = col - 1
    while temp_row >= 0 and temp_col >= 0:
      if field[temp_row][temp_col] == '*':
        res += 1
      temp_row = temp_row - 1
      temp_col = temp_col - 1

  if row + 1 < number and col - 1 >= 0:
    temp_row = row + 1
    temp_col = col - 1
    while temp_row < number and temp_col >= 0:
      if field[temp_row][temp_col] == '*':
        res += 1
      temp_row = temp_row + 1
      temp_col = temp_col - 1

  if row + 1 < number and col + 1 < number:
    temp_row = row + 1
    temp_col = col + 1
    while temp_row < number and temp_col < number:
      if field[temp_row][temp_col] == '*':
        res += 1
      temp_row = temp_row + 1
      temp_col = temp_col + 1
    
  if row - 1 >= 0 and col + 1 < number:
    temp_row = row - 1
    temp_col = col + 1
    while temp_row >= 0 and temp_col < number:
      if field[temp_row][temp_col] == '*':
        res += 1
      temp_row = temp_row - 1
      temp_col = temp_col + 1
    
  return res

def get_columns_from_row_with_min_conflicts(field, index_row):
  result = PriorityQueue() # first element is the conflicts, the second  is the index of the column
  for index_col in range(number):
    res = 0
    left_and_right = sum([1 for x in range(number) if field[index_row][x] == '*']) # настрани
    up_and_down = sum([1 for x in range(number) if field[x][index_col] == '*']) # надолу и на горе
    diag = count_in_diag(index_row, index_col, field)
    res = left_and_right + up_and_down + diag
    if field[index_row][index_col] == '*':
      res -= 1
    result.put((res, index_col))
  return result


def is_solution(field):
  for index_row, row in enumerate(field):
    x = row.count('*')
    if x >= 2:
      return False
    for index_col, col in enumerate(row):
      cols = sum([1 for x in range(number) if field[x][index_col] == '*']) # надолу и на горе
    if cols >= 2:
      return False
    for index_col, col in enumerate(row):
      diag = count_in_diag(index_row, index_col, field)
      if diag >= 1 and field[index_row][index_col] == '*':
        return False
  return True

field = generate_field(number)

def solve(field, number, max_iter):
  i = 0
  while i <= max_iter:
    for index_row, row in enumerate(field):
      if '*' in row:
        i += 1
        _, columns_from_row_with_min_conflicts = get_columns_from_row_with_min_conflicts(field, index_row).get()
        col_in_row_with_queen = [index_col for index_col, col in enumerate(row) if '*' == col][0]
        field[index_row][col_in_row_with_queen] = '_'
        field[index_row][columns_from_row_with_min_conflicts] = '*'
        if is_solution(field):
          print(field)
          return
  print("NO SOLUTION")
  print(field)
  return

solve(field, number, max_iter)