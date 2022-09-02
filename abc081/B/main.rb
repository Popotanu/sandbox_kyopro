_=gets.chomp
c=Float::INFINITY
gets.chomp.split.map do |a|
 c= [ c, a.to_i.to_s(2).reverse.index('1') ].min
end
puts c

