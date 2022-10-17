a= gets.chomp.split(" ").map(&:to_i)

a[0].times do |i|
  puts i
  a[1] = a[1].round(-i-1)
end

puts a[1]

