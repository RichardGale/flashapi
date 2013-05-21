#if !defined(FLEX11_6_VERIFYERROR_AS)
#define FLEX11_6_VERIFYERROR_AS
#if defined(__cplusplus)


/**
 * The VerifyError class represents an error that occurs when a malformed
 * or corrupted SWF file is encountered.
 * @langversion 3.0
 * @playerversion   Flash 9
 * @playerversion   AIR 1.0
 * @playerversion   Lite 4
 */


class VerifyError : public Error
{
public:
    static const int length;

    /**
     * Creates a new VerifyError object.
     * @param   message Contains the message associated with the VerifyError object.
     * @playerversion   Lite 4
     * @playerversion   Flash 9
     * @playerversion   AIR 1.0
     */
public:
    VerifyError(void *message=(void *)"", void *id=0);
};

#endif // FLEX11_6_VERIFYERROR_AS
#endif // __cplusplus

