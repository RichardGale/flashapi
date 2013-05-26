#if !defined(FLEX11_6_WALKER_AS)
#define FLEX11_6_WALKER_AS
#if defined(__cplusplus)



#include "flex11.6.h"



class Walker : public Object
{
public:
    Function *reviver;

public:
    void        *walk(Object *holder, std::string name);

public:
    Walker(Function *reviver);
};

#endif // FLEX11_6_WALKER_AS
#endif // __cplusplus

