#if !defined(FLEX11_6_JSON_AS)
#define FLEX11_6_JSON_AS
#if defined(__cplusplus)



class JSON: public Object
{
public:
    JSON();

public:
    static Object  *parse(std::string text, Function *reviver);

public:
    static std::string stringify(Object *value, void *replacer, void *space);
};

#endif // FLEX11_6_JSON_AS
#endif // __cplusplus

