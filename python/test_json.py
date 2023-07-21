import json

with open('fcc.json', 'r') as fcc_file:
    fcc_data = json.load(fcc_file)
    for obj in fcc_data:
        print(fcc_data[obj])
    fcc_data["first"] = "ssss"
    print(fcc_data)
