require "bit"

function isPrime(x)
    n = math.ceil(math.sqrt(x))
    if x == 2 or x == 3 then return true end
    if bit.band(x,1)==0 or x == 1 or x == 0 then return false end
    for i=3, n, 2 do
        if x%i==0 then return false end
    end
    return true
end

function Main()
    n,h = math.floor(600851475143/2), 0
    for i=3, n, 2 do
        if n%i==0 and isprime(i) then h = i end
    end
    print(h)
end

Main()