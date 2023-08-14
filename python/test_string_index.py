str = "12.12B"
str = "12.12K"
data = float(str[:-1])

if str[-1] == "B":
    print("BBBl")
elif str[-1] == "K":
    print("KKK")
    data *= 1024
else:
    print("MMM")
    data *= 1024 * 1024
print(int(data))
