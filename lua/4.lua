function isPalindrome(x)
    local n = string.len(x) + 1
    for i=1, n, 1 do
        if x.sub(i,i) ~= x.sub(n-i, n-i) then
            return false
        end
    end
    return true
end

function Main()
    local p = {}
    for i=999, 100, -1 do
        for j=999, 100, -1 do
            str = string.format("%i", i*j)
            if isPalindrome(str) then p[#p+1]=str end
        end
    end
    table.sort(p)
    print(p[#p])
end

Main()