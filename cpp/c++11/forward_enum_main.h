enum class ClassColor; //OK

//enum TraditionColor; //Error: ISO C++ forbids forward references to 'enum' types

//enum TraditionColor : unsigned int; //Error: In included file: enumeration previously declared with nonfixed underlying type

//enum ColorInt : short; //Error: In included file: enumeration previously declared with nonfixed underlying type 
enum ColorInt : int;

class ForwardEnumMain
{
public:
    ForwardEnumMain();
    virtual ~ForwardEnumMain();

    static void TestFunc(ColorInt c);
};

