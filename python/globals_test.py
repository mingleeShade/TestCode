g_server_unit = "server"


def GetGlobals():
    g_server_unit = globals().get("g_server_unit", "")
    conf = {"g_server_unit": g_server_unit}
    return conf


def UpdateGlobals():
    g_server_unit = globals().get("g_server_unit", "")
    g_server_unit = "sss"
    print(g_server_unit)


conf = GetGlobals()
print("===get_globals===")
print(g_server_unit)
print(conf)

UpdateGlobals()
print("\n===update_globals===")
print(g_server_unit)
print(conf)
