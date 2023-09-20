local EI = 10001


function Test()
    local str = "10001.1"
    local n = tonumber(str)
    local i = EI

    if i == n then
        print("equal")
    end
    local t = math.floor(n or 0)
    i = n or 0

    print("\ntype(i): " .. type(i) .. ", v: " .. i)
    print("\ntype(n): " .. type(n) .. ", v: " .. n)
end

Test()
