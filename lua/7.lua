require "bit"

function isPrime(x)
    n = math.ceil(math.sqrt(x))
    if x == 2 or x == 3 then return true end
    if bit.band(x,1) or x == 1 or x == 0 then return false end
    for i=3, n, 2 do
        if x%i then return false end
    end
    return true
end

function Main()
    local count, i = 0, 0
    repeat
        i = i + 1
        if isPrime(i) then count = count + 1 end
    until count == 10001
    print(i)
end

Main()