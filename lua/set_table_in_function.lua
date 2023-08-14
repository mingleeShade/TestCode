local g_t = {}

g_t["1"] = { k = 1, v = 10 }
g_t["2"] = { k = 2, v = 20 }

function Get(t)
    return g_t[t]
end

local function main()
    local t = Get("1")
    t.k = 11
    t.v = 111
    for i, sub in pairs(g_t) do
        print("index: " .. i)
        for k, v in pairs(sub) do
            print("  k: " .. k .. ", v: " .. v)
        end
    end
end

main()
