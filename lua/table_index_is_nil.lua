local t = {}
function F1()
    print("this is F1")
end

function Register(id, func)
    if id == nil then
        t = debug.getinfo(func, "flnSu")
        local name = t.name or "empty"
        print("name: " .. name)
    end
    t[id] = func
end

Register(1, F1)
Register(nil, F1)
