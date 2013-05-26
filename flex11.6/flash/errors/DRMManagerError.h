#if !defined(FLEX11_6_FLASH_ERRORS_DRMMANAGERERROR_AS)
#define FLEX11_6_FLASH_ERRORS_DRMMANAGERERROR_AS
#if defined(__cplusplus)


/**
 * The DRMManager dispatches a DRMManagerError event to report errors.
 * @langversion 3.0
 * @playerversion   AIR 1.5
 */

#include "flex11.6.h"



namespace flash
{
    namespace errors
    {
        class DRMManagerError : public Error
        {
            /**
             * The specific error number.
             * @langversion 3.0
             * @playerversion   AIR 1.5
             */
        public:
            int          subErrorID();

            /**
             * Creates a new instance of the DRMManagerError class.
             * @param   message The error description
             * @param   id  The general error number
             * @param   subErrorID  The specific error number
             * @langversion 3.0
             * @playerversion   AIR 1.5
             */
        public:
            DRMManagerError(std::string message, int id, int subErrorID);

            /**
             * Returns the string "Error" by default or the value contained in the Error.message property,
             * if defined.
             * @return  The error message.
             */
        public:
            std::string   toString();
        };
    }
}

#endif // FLEX11_6_FLASH_ERRORS_DRMMANAGERERROR_AS
#endif // __cplusplus

