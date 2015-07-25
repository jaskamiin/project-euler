--works, but slowly

function Main()
    local flag,inc = false, 1
    repeat
        for i=1,21,1 do
            if i == 21 then 
                flag = true
                goto continue
            end
            if inc%i ~= 0 then goto continue end
        end
        ::continue::
        inc = inc + 1
    until flag == true
    print(inc-1)
end

Main()