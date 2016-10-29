number = int(input())

count_of_rows = int(number/2 - 1)
count_of_cols = int(number/2 - 1)

expected_matrix = [[0 for x in range(count_of_rows)] for y in range(count_of_cols)]
actual_matrix = [[0 for x in range(count_of_rows)] for y in range(count_of_cols)]
visited = [[False for x in range(count_of_rows)] for y in range(count_of_cols)]

start = 1
end = count_of_rows + 1
for x in range(0, count_of_rows):
  expected_matrix[x] = list(range(start, end))
  start = start + count_of_rows
  end = start + count_of_rows

expected_matrix[count_of_cols - 1][count_of_rows - 1] = 0
print(expected_matrix)

actual_matrix = [[int(input()) for x in range(count_of_rows)] for y in range(count_of_cols)]
print(actual_matrix)


def count_h_and_indices(num_row, num_col):
  number = actual_matrix[num_row][num_col]
  [(row_of_number, col_of_number)] = [(index, row.index(number)) for index, row in enumerate(expected_matrix) if number in row]
  heuristic = abs(row_of_number - num_row) + abs(col_of_number + num_col)
  return (num_row, num_col, heuristic)

zero = 0

while actual_matrix != expected_matrix:
  [(row_of_zero, col_of_zero)] = [(index, row.index(zero)) for index, row in enumerate(actual_matrix) if zero in row]

  up_row, up_col = row_of_zero - 1, col_of_zero
  left_row, left_col = row_of_zero, col_of_zero - 1
  down_row, down_col = row_of_zero + 1, col_of_zero
  right_row, right_col = row_of_zero, col_of_zero + 1

  data = []

  if up_row >= 0 and up_row <= count_of_rows - 1:
    up_pair = count_h_and_indices(up_row, up_col)
    if up_pair[2] != 0:
      data.append(up_pair)

  if left_col >= 0 and left_col <= count_of_rows - 1:
    left_pair = count_h_and_indices(left_row, left_col)
    if left_pair[2] != 0:
      data.append(left_pair)
    
  if down_row >= 0 and down_row <= count_of_rows - 1:
    down_pair = count_h_and_indices(down_row, down_col)
    if down_pair[2] != 0:
      data.append(down_pair)
    
  if right_row >= 0 and right_row <= count_of_rows - 1:
    right_pair = count_h_and_indices(right_row, right_col)
    if right_pair[2] != 0:
      data.append(right_pair)
    
  (num_row, num_col, _) = min(data, key = lambda t: t[2])


  if visited[row_of_zero][col_of_zero] == False:
    actual_matrix[row_of_zero][col_of_zero] = actual_matrix[num_row][num_col]
    actual_matrix[num_row][num_col] = 0
    visited[row_of_zero][col_of_zero] = True
    
  print(actual_matrix)

    