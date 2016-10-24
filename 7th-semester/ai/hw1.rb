require 'pry'
number = gets.chomp.to_i

$visited = Hash.new
$start_frogs_string = ">"*number + "_" + "<"*number
$expected_frogs_output = "<"*number + "_" + ">"*number
$count = 1 + number*2

def get_neighbours(current_string)
  index_of_blank = current_string.index('_')
  neighbours = []

  if index_of_blank - 2  >= 0 && (current_string[index_of_blank - 2]) == '>'
    s = current_string.dup
    s[index_of_blank - 2] = '_'
    s[index_of_blank] = '>'
    neighbours << s
  end

  if index_of_blank + 2  <= $count && (current_string[index_of_blank + 2]) == '<'
    s = current_string.dup
    s[index_of_blank + 2] = '_'
    s[index_of_blank] = '<'
    neighbours << s
  end

  if index_of_blank - 1  >= 0 && (current_string[index_of_blank - 1]) == '>'
    s = current_string.dup
    s[index_of_blank - 1] = '_'
    s[index_of_blank] = '>'
    neighbours << s
  end

  if index_of_blank + 1  <= $count && (current_string[index_of_blank + 1]) == '<'
    s = current_string.dup
    s[index_of_blank + 1] = '_'
    s[index_of_blank] = '<'
    neighbours << s
  end

  neighbours
end

$lines = []

def dfs(current_string)
  s = []
  s << current_string
  while s.size > 0
    string = s.pop

    if final_output_is_reached?(string)
      $lines << string
      return
    end

    if $visited[string] != true
      $visited[string] = true
      $lines << string
      neighbours = get_neighbours(string)
      neighbours.each do |neighbour|
        s << neighbour
      end
    end
  end
end


def final_output_is_reached?(string)
  string == $expected_frogs_output
end

dfs($start_frogs_string)

$lines.each do |line|
  p line
end