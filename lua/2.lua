require "bit"

function fib(x)
    if x == 0 or x == 1 then 
        return 1 
    else return fib(x-1)+fib(x-2) end 
end

function Main()
    local i, sum = 0, 0
    repeat
        f = fib(i)
        if bit.band(f,1) == 0 then sum = sum + f end
    until f > 4000000
    print(sum)
end

Main()