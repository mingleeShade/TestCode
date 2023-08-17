local t = {}
table.insert(t, "1")
table.insert(t, "1xxx")
table.insert(t, "2")
table.insert(t, "2xxx")


for k, v in pairs(t) do
    print(k, v)
end
