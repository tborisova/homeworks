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

def count_left_right(index_row, field):
  result = 0
  result = sum([1 for index_col in range(number) if field[index_row][index_col] == '*'])
  return result

def count_down_up(index_col, field):
  result = 0
  result = sum([1 for index_row in range(number) if field[index_row][index_col] == '*'])
  return result

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

def get_columns_from_row_with_min_conflicts(field, index_row):
  result = PriorityQueue() # first element is the conflicts, the second  is the index of the column
  for index_col in range(number):
    res = count_left_right(index_row, field) + count_down_up(index_col, field) + count_in_diag(index_row, index_col, field)
    result.put(res, index_col) # sorted by res

  return result


# while(is_solution(field) == False):
field = generate_field(number)
print_field(field)
i = 0
result = get_columns_from_row_with_min_conflicts(field, 0)
while not result.empty():
  print(result.get())
# while i <= max_iter:
#   for index_row, row in enumerate(field):
#     i += 1
#     columns_from_row_with_min_conflicts = get_columns_from_row_with_min_conflicts(field, index_row)[0]
#     col_in_row_with_queen = [index_col for index_col, col in enumerate(row) if '*' in row][0]
#     field[row][col_in_row_with_queen] = '_'
#     field[row][columns_from_row_with_min_conflicts] = '*'
#     if(is_solution(field) == True):
#       print_field(field)
#       break


