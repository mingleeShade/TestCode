feature_key_map = {"k1": 1, "k2": 2}


def get_conf():
    conf = {"translation": "show", "close": "hide"}
    fk = globals().get("feature_key_map", {})
    if "k3" in fk and fk["k3"] > 0:
        print("fk.k3 > 0")

    if "k2" in fk and fk["k2"] > 1:
        print("fk.k2 > 1")

    sk = globals().get("sk", {})
    if "k2" in sk and sk["k2"] > 0:
        print("sk.k2 > 0")

    return conf


get_conf()
