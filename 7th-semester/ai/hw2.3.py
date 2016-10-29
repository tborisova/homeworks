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

def index_of_zero(table):
  [(row_of_zero, col_of_zero)] = [(index, row.index(0)) for index, row in enumerate(table) if 0 in row]
  return [(row_of_zero, col_of_zero)]

def neighbors(current_table):
  [(row_of_zero, col_of_zero)] = index_of_zero(current_table)

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

def heuristic(a, b):
    [(x1, y1)] = index_of_zero(a)
    [(x2, y2)] = index_of_zero(b)
    return abs(x1 - x2) + abs(y1 - y2)

def a_star_search(start, goal):
    frontier = PriorityQueue()
    frontier.put((0, start))
    came_from = {}
    cost = {}
    came_from[to_string(start)] = None
    visited[to_string(start)] = False
    counter = 0
    result = []

    while not frontier.empty():
        _, current = frontier.get()
        result.append(came_from[to_string(current)])
        counter += 1
        if current == goal: # if table is the final 
            break
        
        for (next, step) in neighbors(current): # get all possible states
            priority = heuristic(goal, next)
            if visited.get(to_string(next), False) == False or cost[to_string(next)] > priority:
                visited[to_string(next)] = True
                cost[to_string(next)] = priority
                frontier.put((priority, next))
                came_from[to_string(next)] = step
    
    return counter, result

counter, path = a_star_search(actual_matrix, expected_matrix)

print(counter - 1)
for el in reversed(path):
  if el != None:
    print(el)