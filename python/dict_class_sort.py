
class TestData:
    name_ = ""
    value_ = 0
    def __init__(self, name, value) -> None:
        self.name_ = name
        self.value_ = value

    # 这个可以让输出更加简洁，不带上 对象相关属性
    #  def __repr__(self) -> str:
    #      return repr((self.name_, self.value_))

def main():
    test_dict = {}
    t1 = TestData("t1", 3)
    t2 = TestData("t2", 4)
    t3 = TestData("t3", 1)
    t4 = TestData("t4", 5)
    t5 = TestData("t5", 5)
    test_dict[t1.name_] = t1;
    test_dict[t2.name_] = t2;
    test_dict[t3.name_] = t3;
    test_dict[t4.name_] = t4;
    test_dict[t5.name_] = t5;

    dict_sorted = sorted(test_dict.items(), key=lambda t: t[1].value_)
    #dict_sorted = sorted(test_dict.items(), key = lambda)
    print("sorted: ", dict_sorted)
    print("type of dict_sorted", type(dict_sorted)) # type  list

    new_dict = {
            "2": {
                "size": 22,
                "dsize": 11
                },
            "1": {
                "size": 12,
                "dsize": 52
                },
            "3": {
                "size": 33,
                "dsize": 31
                }
            }
    print(new_dict.items())
    # dict_items([('2', {'size': 22, 'dsize': 11}), ('1', {'size': 12, 'dsize': 52}), ('3', {'size': 33, 'dsize': 31})])

    dict_sorted = sorted(new_dict.items(), key = lambda i:i[1]['size']+i[1]['dsize'], reverse=True)

    print(dict_sorted)
    # [('1', {'size': 12, 'dsize': 52}), ('3', {'size': 33, 'dsize': 31}), ('2', {'size': 22, 'dsize': 11})]


if __name__ == "__main__":
    main()
