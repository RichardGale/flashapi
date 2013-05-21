#if !defined(FLEX11_6_FLASH_ERRORS_INVALIDSWFERROR_AS)
#define FLEX11_6_FLASH_ERRORS_INVALIDSWFERROR_AS
#if defined(__cplusplus)


/**
 * The Flash runtimes throw this exception when they encounter a corrupted SWF file.
 * @langversion 3.0
 * @playerversion   Flash 9
 * @playerversion   Lite 4
 */


namespace flash
{
    namespace errors
    {
        class InvalidSWFError : public Error
        {
            /**
             * Creates a new InvalidSWFError object.
             * @param   message A string associated with the error object.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            InvalidSWFError(std::string message="", int id=0);
        };
    }
}

#endif // FLEX11_6_FLASH_ERRORS_INVALIDSWFERROR_AS
#endif // __cplusplus

