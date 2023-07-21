import json

with open('fcc.json', 'r') as fcc_file:
    fcc_data = json.load(fcc_file)
    for key in fcc_data:
        print(fcc_data[key])
        obj = fcc_data[key]
        edge_list = obj["edge"]
        for obj in edge_list:
            print(obj)
    fcc_data["first"] = "ssss"
    #  print(fcc_data)
