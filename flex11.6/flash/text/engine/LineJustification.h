#if !defined(FLEX11_6_FLASH_TEXT_ENGINE_LINEJUSTIFICATION_AS)
#define FLEX11_6_FLASH_TEXT_ENGINE_LINEJUSTIFICATION_AS
#if defined(__cplusplus)


/**
 * The LineJustification class is an enumeration of constant values used in setting the <codeph class="+ topic/ph pr-d/codeph ">lineJustfication</codeph> property
 * of the TextJustifier subclasses.
 * @langversion 3.0
 * @playerversion   Flash 10
 * @playerversion   AIR 1.5
 * @playerversion   Lite 4
 */

#include "flex11.6.h"



namespace flash
{
    namespace text
    {
        namespace engine
        {
            class LineJustification : public Object
            {
                /**
                 * Do not justify lines.
                 * @langversion 3.0
                 * @playerversion   Flash 10
                 * @playerversion   AIR 1.5
                 * @playerversion   Lite 4
                 */
            public:
                static const std::string UNJUSTIFIED;

                /**
                 * Justify all but the last line.
                 * @langversion 3.0
                 * @playerversion   Flash 10
                 * @playerversion   AIR 1.5
                 * @playerversion   Lite 4
                 */
            public:
                static const std::string ALL_BUT_LAST;

                /**
                 * Justify all lines.
                 * @langversion 3.0
                 * @playerversion   Flash 10
                 * @playerversion   AIR 1.5
                 * @playerversion   Lite 4
                 */
            public:
                static const std::string ALL_INCLUDING_LAST;
            public:
                static const std::string ALL_BUT_MANDATORY_BREAK;

            public:
                LineJustification();
            };
        }
    }
}

#endif // FLEX11_6_FLASH_TEXT_ENGINE_LINEJUSTIFICATION_AS
#endif // __cplusplus

