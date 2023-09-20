t_dict = {
        "1": {
            "size": 12
            },
        "2": {
            "size": 1
            }
        }

def add_key(d):
    for k in d:
        node = d[k]
        node["NewK"] = "This a new key"

print(t_dict)
add_key(t_dict)
print(t_dict)
