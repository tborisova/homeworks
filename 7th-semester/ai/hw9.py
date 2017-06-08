def get_data():
  votes = csv.reader(open('', newline=''), delimiter=',')
  rows = []

  # not sure about these values since we need to test the classification by class - republican vs democrats?
  # so we don't need the rows that have ?
  for row in votes:
    rows.append(row)

  return rows

