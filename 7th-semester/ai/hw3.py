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
  print(' ')
  for i in range(len(field[1])):  # Make it work with non square matrices.
    print(i)
  print
  for i, element in enumerate(field):
        print(i, ' '.join(element))
        
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
  res = 0
  for index_col in range(number):
    res = sum([1 for x in range(number) if field[index_row][x] == '*']) # настрани
    res += sum([1 for x in range(number) if field[x][index_col] == '*']) # надолу и на горе
    res += count_in_diag(index_row, index_col, field)
    result.put((res, index_col))
  return result


def is_solution(field):
  for index_row, row in enumerate(field):
    result = get_columns_from_row_with_min_conflicts(field, index_row)
  while not result.empty():
    _, x = result.get()
    if x > 0:
      return False
  return True

# while(is_solution(field) == False):
field = generate_field(number)
print_field(field)
i = 0
# result = get_columns_from_row_with_min_conflicts(field, 0)
# for x in result:
  # print(x)

# for x in range(0, 3):
  # print(x)
while i <= max_iter:
  for index_row, row in enumerate(field):
    if '*' in row:
      i += 1
      _, columns_from_row_with_min_conflicts = get_columns_from_row_with_min_conflicts(field, index_row).get()
      # print(columns_from_row_with_min_conflicts)
      col_in_row_with_queen = [index_col for index_col, col in enumerate(row) if '*' == col][0]
      field[index_row][col_in_row_with_queen] = '_'
      field[index_row][columns_from_row_with_min_conflicts] = '*'
      print("\n")
      print(field)
      # if(is_solution(field) == True):
      #   print_field(field)
      #   break


