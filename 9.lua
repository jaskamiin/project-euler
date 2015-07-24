function Main()
    for a=3, 333, 1 do
        for b=4, 500, 1 do
            for c=5, 500, 1 do
                if a^2 + b^2 == c^2 then
                    if a+b+c == 1000 then
                        print(a*b*c)
                        return true
                    end
                end
            end
        end
    end
end

Main()