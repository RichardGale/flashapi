#if !defined(FLEX11_6_DEFINITIONERROR_AS)
#define FLEX11_6_DEFINITIONERROR_AS
#if defined(__cplusplus)


/**
 * The DefinitionError class represents an error that occurs when user code
 * attempts to define an identifier that is already defined. This error commonly
 * occurs in redefining classes, interfaces,
 * and functions.
 * @langversion 3.0
 * @playerversion   Flash 9
 * @playerversion   AIR 1.0
 * @playerversion   Lite 4
 */

#include "flex11.6.h"



class DefinitionError : public Error
{
public:
    static const int length;

    /**
     * Creates a new DefinitionError object.
     * @playerversion   Lite 4
     * @playerversion   Flash 9
     * @playerversion   AIR 1.0
     */
public:
    DefinitionError(std::string message="", void *id=0);
};

#endif // FLEX11_6_DEFINITIONERROR_AS
#endif // __cplusplus

