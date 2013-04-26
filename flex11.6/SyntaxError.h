#if !defined(FLEX11_6_SYNTAXERROR_AS)
#define FLEX11_6_SYNTAXERROR_AS
#if defined(__cplusplus)


/**
 * A SyntaxError exception is thrown when a parsing error occurs, for one of the following reasons:.
 * <ul class="- topic/ul "><li class="- topic/li ">An invalid regular expression is parsed by the RegExp class.</li><li class="- topic/li ">Invalid XML content is parsed by the XML class.</li></ul>
 * @langversion 3.0
 * @playerversion   Flash 9
 * @playerversion   AIR 1.0
 * @playerversion   Lite 4
 */

class SyntaxError: public Error
{
public:
    static const int length;

    /**
     * Creates a new SyntaxError object.
     * @param   message Contains the message associated with the SyntaxError object.
     * @playerversion   Lite 4
     * @playerversion   Flash 9
     * @playerversion   AIR 1.0
     */
public:
    SyntaxError(void *message, void *id);
};

#endif // FLEX11_6_SYNTAXERROR_AS
#endif // __cplusplus

