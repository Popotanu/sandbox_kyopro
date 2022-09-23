class SecondConverter
  require "ostruct"
  RATES = OpenStruct.new({
    s: 1,
    sec: 1,
    m: 60,
    min: 60,
    h: 3600,
    hour: 3600
  })

  def self.abbr_union
    RATES.to_h.keys.join('|')
  end

  # in が予約語だった
  def self.to_second(innn)
    raise ArgumentError if !/\A[0-9].*[#{abbr_union}]?\z/.match?(innn)
    SecondConverter.new(innn).to_second
  end

  def to_second
    suffixed = /(\d*)(#{self.class.abbr_union})\z/.match(suffixing).to_a
    suffixed[1].to_i * RATES[suffixed[2]]
  end

  private

  def initialize(innn)
    @innn = innn
  end

  def suffixing
    @innn.sub(/[0-9]\z/, '\1s')
  end
end

if ARGV.length != 1
  puts "usage: ruby #{__FILE__} 5[s|m|h]"
  exit 0
end

begin
  in_sec = SecondConverter.to_second(ARGV[0])
rescue ArgumentError
  puts "usage: ruby #{__FILE__} 5[s|m|h]"
  exit 0
end
start = Time.now
finish = start + in_sec

while Time.now < finish
  remain = (finish - Time.now).floor
  remain = [remain / 3600, (remain % 3600) / 60, (remain % 3600 % 60)]
  puts remain.join(":")

  sleep(1)
end
