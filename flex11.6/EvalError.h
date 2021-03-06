#if !defined(FLEX11_6_EVALERROR_AS)
#define FLEX11_6_EVALERROR_AS
#if defined(__cplusplus)


/**
 * The EvalError class represents an error that occurs when user code
 * calls the <codeph class="+ topic/ph pr-d/codeph ">eval()</codeph> function or attempts to use the <codeph class="+ topic/ph pr-d/codeph ">new</codeph>
 * operator with the Function object. Calling <codeph class="+ topic/ph pr-d/codeph ">eval()</codeph> and
 * calling <codeph class="+ topic/ph pr-d/codeph ">new</codeph> with the Function object are not supported.
 * @langversion 3.0
 * @playerversion   Flash 9
 * @playerversion   AIR 1.0
 * @playerversion   Lite 4
 */

#include "flex11.6.h"



class EvalError : public Error
{
public:
    static const int length;

    /**
     * Creates a new EvalError object.
     * @param   message A string associated with the error.
     * @playerversion   Lite 4
     * @playerversion   Flash 9
     * @playerversion   AIR 1.0
     */
public:
    EvalError(std::string message="", void *id=0);
};

#endif // FLEX11_6_EVALERROR_AS
#endif // __cplusplus

