local string = string
function ToHex(str)
    return string.format("%X", str)
end

function ToHex2(str)
    local hex = ""
    for i = 1, #str do
        hex = hex .. string.format("%02X", string.byte(str, i))
    end
    return hex
end

local s = " 1 235abcdAACEZZ"

local hex = ToHex2(s)
print("hex: " .. hex)
