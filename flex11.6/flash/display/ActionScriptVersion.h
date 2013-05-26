#if !defined(FLEX11_6_FLASH_DISPLAY_ACTIONSCRIPTVERSION_AS)
#define FLEX11_6_FLASH_DISPLAY_ACTIONSCRIPTVERSION_AS
#if defined(__cplusplus)


/**
 * The ActionScriptVersion class is an enumeration of constant values that
 * indicate the language version of a loaded SWF file.
 *
 *   The language version constants are provided for use in checking the
 * <codeph class="+ topic/ph pr-d/codeph ">actionScriptVersion</codeph> property of a flash.display.LoaderInfo object.
 * @langversion 3.0
 * @playerversion   Flash 9
 * @playerversion   Lite 4
 */

#include "flex11.6.h"



namespace flash
{
    namespace display
    {
        class ActionScriptVersion : public Object
        {
            /**
             * ActionScript language version 2.0 and earlier.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            static const unsigned int ACTIONSCRIPT2;

            /**
             * ActionScript language version 3.0.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            static const unsigned int ACTIONSCRIPT3;

        public:
            ActionScriptVersion();
        };
    }
}

#endif // FLEX11_6_FLASH_DISPLAY_ACTIONSCRIPTVERSION_AS
#endif // __cplusplus

