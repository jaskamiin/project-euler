require "bit32"
require "math"

function isPrime(x)
    local n = math.ceil(math.sqrt(x))
    if x == 2 or x == 3 then return true end
    if bit.band(x,1)==0 or x == 0 or x == 1 then return false end
    for i=3, n, 2 do
       if x%1 == 0 then return false end
    end
    return true
end

function Main()
    local sum = 2
    for i=3, 2000000, 2 do 
        if isPrime(i) then sum = sum + i end 
    end
    print(sum)    
end

Main()