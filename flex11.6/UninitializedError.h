#if !defined(FLEX11_6_UNINITIALIZEDERROR_AS)
#define FLEX11_6_UNINITIALIZEDERROR_AS
#if defined(__cplusplus)



#include "flex11.6.h"



class UninitializedError : public Error
{
public:
    static const int length;

public:
    UninitializedError(std::string message="", void *id=0);
};

#endif // FLEX11_6_UNINITIALIZEDERROR_AS
#endif // __cplusplus

