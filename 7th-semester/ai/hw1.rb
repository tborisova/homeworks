number = gets.chomp.to_i

frogs = []
visited = []

start = 0
end_frog = 2*number

start.upto(number - 1) do |frog|
  frogs[frog] = '>'
end

frogs[number] = ' '

(number + 1).upto(end_frog) do |frog|
  frogs[frog] = '<'
end

# def dfs(frogs, frog)
#   s = []
#   s << frog

#   while s.size > 0
#     frog = s.last
#     if !visited[frog]
#       visited[frog] = true
#       if frogs[frog+1] == ' '
#         s << frog + 1
#       end
#     end
#   end
# end


# > > _ < <
# 1 2 3 4 5

#   3
# 2   4


# dfs()

# def dfs(frog)
#   visited[frog] = true


# end



# void dfs(int current)
# {
#   visited[current] = 1;
#   for (int i = 0; i < neighbours[current].size(); i++)
#   {
#     int next = neighbours[current][i];
#     if (!visited[next])
#       dfs(next);
#   }
# }
def dfs(frogs, current_frog, visited, end_frog)
  s = []
  s << current_frog
  while !s.empty?
    current_frog = s.last
    if !visited[current_frog]
      p 'dddd'
      p frogs[current_frog]
      if frogs[current_frog] == ' '
        s << current_frog - 1 if current_frog - 1 >= 0
        s << current_frog + 1 if current_frog + 1 <= end_frog
      else
        s << current_frog - 1 if current_frog - 1 >= 0 && frogs[current_frog - 1] == ' '
        s << current_frog + 1 if current_frog + 1 <= end_frog && frogs[current_frog + 1] == ' '
      end
    end
  end
end

def final_output_is_reached?(start, frogs, end_frog,   number)
  res1 = start.upto(number - 1).select do |frog|
    frogs[frog] == '>'
  end

  res2 = (number + 1).upto(end_frog) do |frog|
    frogs[frog] == '<'
  end
  p 'dddd'
  p res1
  p res2
  res1.empty? && res2.empty?
end

num = 0
while !final_output_is_reached?(start, frogs, end_frog, number)
  start.upto(end_frog) do |i|
    visited[i] = false
  end
  p frogs
  dfs(frogs, num, visited, end_frog)
  p "\n"
  if num < end_frog
    num = num + 1
  else
    num = 0
  end
end




