local t = {}
t[10] = 1
t[2] = 3
t[3] = 30
t[1] = 33

for k, v in pairs(t) do
    print(k, v)
end

print("#t: " .. #t)
