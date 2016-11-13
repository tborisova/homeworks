from queue import *
from copy import deepcopy

number = int(input())

count_of_rows = int(number/2 - 1)
count_of_cols = int(number/2 - 1)

expected_matrix = [[0 for x in range(count_of_rows)] for y in range(count_of_cols)]
actual_matrix = [[0 for x in range(count_of_rows)] for y in range(count_of_cols)]
visited = {}

start = 1
end = count_of_rows + 1
for x in range(0, count_of_rows):
  expected_matrix[x] = list(range(start, end))
  start = start + count_of_rows
  end = start + count_of_rows

expected_matrix[count_of_cols - 1][count_of_rows - 1] = 0

actual_matrix = [[int(input()) for x in range(count_of_rows)] for y in range(count_of_cols)]

def index_of_zero(table, number):
  [(row_of_zero, col_of_zero)] = [(index, row.index(number)) for index, row in enumerate(table) if number in row]
  return (row_of_zero, col_of_zero)

def neighbors(current_table):
  (row_of_zero, col_of_zero) = index_of_zero(current_table, 0)

  result = []
  if row_of_zero - 1 >= 0: # up
    new_table = deepcopy(current_table)
    new_table[row_of_zero][col_of_zero] = current_table[row_of_zero - 1][col_of_zero]
    new_table[row_of_zero - 1][col_of_zero] = 0
    result.append((new_table, "up"))
  if row_of_zero + 1 <= count_of_rows - 1: # down
    new_table = deepcopy(current_table)
    new_table[row_of_zero][col_of_zero] = current_table[row_of_zero + 1][col_of_zero]
    new_table[row_of_zero + 1][col_of_zero] = 0
    result.append((new_table, "down"))
  if col_of_zero - 1 >= 0: # left
    new_table = deepcopy(current_table)
    new_table[row_of_zero][col_of_zero] = current_table[row_of_zero][col_of_zero - 1]
    new_table[row_of_zero][col_of_zero - 1] = 0
    result.append((new_table, "right"))
  if col_of_zero + 1 <= count_of_rows - 1: #right
    new_table = deepcopy(current_table)
    new_table[row_of_zero][col_of_zero] = current_table[row_of_zero][col_of_zero + 1]
    new_table[row_of_zero][col_of_zero + 1] = 0
    result.append((new_table, "left"))
    
  return result

def to_string(table):
  result = ""

  for row in table:
    for el in row:
      result += str(el)
  return result

result1 = []
for x in range(number):
  result1.insert(x, index_of_zero(expected_matrix, x+1))

def heuristic(a, b):
    result2 = []
    distance = 0

    for x in range(number):
      result2.insert(x, index_of_zero(b, x+1))
    
    for x in range(number):
      (x1, y1) = result1[x]
      (x2, y2) = result2[x]

      distance += abs(x1 - x2) + abs(y1 - y2)

    return distance

def reconstruct_path(came_from, current):
    total_path = [current]
    for current in came_from.keys():
        current = came_from[current]
        total_path.append(current)
    return total_path

def a_star_search(start, goal):
    frontier = PriorityQueue()
    frontier.put((0, start, 0))
    came_from = {}
    cost = {}
    came_from[to_string(start)] = None
    visited[to_string(start)] = False
    counter = 0
    result = []

    while not frontier.empty():
      _, current, level = frontier.get()
      result.append(came_from[to_string(current)])
      counter += 1
      if current == goal: # if table is the final 
        return reconstruct_path(came_from, current)

      for (next, step) in neighbors(current): # get all possible states
          priority = heuristic(goal, next)
          if visited.get(to_string(next), False) == False or cost[to_string(next)] >= priority + level:
              visited[to_string(next)] = True
              cost[to_string(next)] = priority + level
              frontier.put((priority, next, level + 1))
              came_from[to_string(next)] = step
    

path = a_star_search(actual_matrix, expected_matrix)

print(len(path))
for x in path:
  print(x)