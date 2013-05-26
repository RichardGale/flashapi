#if !defined(FLEX11_6_JSON_AS)
#define FLEX11_6_JSON_AS
#if defined(__cplusplus)



#include "flex11.6.h"



class JSON : public Object
{
public:
    JSON();

public:
    static Object   *parse(std::string text, Function *reviver=NULL);

public:
    static std::string   stringify(Object *value, void *replacer=NULL, void *space=NULL);
};

#endif // FLEX11_6_JSON_AS
#endif // __cplusplus

