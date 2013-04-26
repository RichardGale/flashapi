#if !defined(FLEX11_6_URIERROR_AS)
#define FLEX11_6_URIERROR_AS
#if defined(__cplusplus)


/**
 * A URIError exception is thrown when one of the global URI handling functions is used
 * in a way that is incompatible with its definition. This exception is thrown when an invalid
 * URI is specified to a function that expects a valid URI, such as the <codeph class="+ topic/ph pr-d/codeph ">Socket.connect()</codeph>
 * method.
 * @langversion 3.0
 * @playerversion   Flash 9
 * @playerversion   AIR 1.0
 * @playerversion   Lite 4
 */

class URIError: public Error
{
public:
    static const int length;

    /**
     * Creates a new URIError object.
     * @param   message Contains the message associated with the URIError object.
     * @playerversion   Lite 4
     * @playerversion   Flash 9
     * @playerversion   AIR 1.0
     */
public:
    URIError(void *message, void *id);
};

#endif // FLEX11_6_URIERROR_AS
#endif // __cplusplus

