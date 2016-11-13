
X = 'x'
O = 'o'

def get_neighbours(table):
  return array_of_tables

table = [['_' for x in range(3)] for y in range(3)]


def max_value(state, l, b):
  v = INF_MIN
  for child in state:
    v = max(v, min_value(child, l, b))
    if v >= b:
      return v
    l = max(v, l)

def min_value(state, l, b):
  v = INF_PLUS
  for child in state:
    v = min(v, max_value(child, l, b))
    if v <= l:
      return v
    b = min(v, b)

def value(state, l, b, player):
  if len(state) == 1: # this is a leaf
    return 0
  if player == X:
    return max_value(state, l, b)
  else:
    return min_value(state)


def dfs(table):
  if value(table, l, b, X) == 0:
    return
  else:
    for child in table

while not is_solved(table):
  x = int(input())
  y = int(input())
  table[x][y] = X
  x1, y1 = dfs(table)
  table[x1][y1] = O


