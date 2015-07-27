function Main()
    local ss1, ss2 = 0, 0 
    for i=1, 100, 1 do
        ss1 = ss1 + i^2
        ss2 = ss2 + i
    end
    ss2 = ss2^2
    print(math.abs(ss1 - ss2))
end

Main()