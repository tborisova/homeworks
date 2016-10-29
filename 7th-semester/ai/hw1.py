import re

number = int(input())

visited = {}
start_frogs_string = ">"*number + "_" + "<"*number
expected_frogs_output = "<"*number + "_" + ">"*number
count = 1 + number*2
lines = []

def get_neighbours(current_string):
  index_of_blank = current_string.index('_')
  neighbours = []

  if current_string != re.sub(r">(<|>)_",r"_\1>", current_string): 
    neighbours.append(re.sub(r">(<|>)_",r"_\1>", current_string))

  if current_string != re.sub(r"_(<|>)<",r"<\1_", current_string):
    neighbours.append(re.sub(r"_(<|>)<",r"<\1_", current_string))

  if current_string != re.sub(r"_<",r"<_", current_string): 
    neighbours.append(re.sub(r"_<",r"<_", current_string))

  if current_string != re.sub(r">_",r"_>", current_string):
    neighbours.append(re.sub(r">_",r"_>", current_string))

  return neighbours

def dfs(current_string):
  s = []
  s.append(current_string)

  while len(s) > 0:
    string = s.pop()
    if string == expected_frogs_output:
      lines.append(string)
      return
    else:
      if visited.get(string, False) != True:
        visited[string] = True
        neighbours = get_neighbours(string)
        if len(neighbours) > 0:
          lines.append(string)
          for neighbour in neighbours:
            s.append(neighbour)
  return

dfs(start_frogs_string)

first_line = lines.pop(0)

for line in lines:
  if line in get_neighbours(first_line):
    print(first_line)
  first_line = line

print(expected_frogs_output)