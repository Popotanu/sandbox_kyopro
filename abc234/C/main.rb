# https://atcoder.jp/contests/abc234/tasks/abc234_c
k = gets.chomp.to_i
k = k.to_s(2)
ans = k.chars.map{ _1=='1' ? '2' : '0' }.join
puts ans

