function Test()
    return 111, 222
end

function Test2()
    return 333,
        444
end

local f, s = Test()
print("f: " .. f .. ", s: " .. s)

local f2, s2 = Test2()
print("f2: " .. f2 .. ", s2: " .. s2)
