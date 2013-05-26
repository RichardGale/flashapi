#if !defined(FLEX11_6_FLASH_TEXT_ENGINE_DIGITCASE_AS)
#define FLEX11_6_FLASH_TEXT_ENGINE_DIGITCASE_AS
#if defined(__cplusplus)


/**
 * The DigitCase class is an enumeration of constant values used in setting the <codeph class="+ topic/ph pr-d/codeph ">digitCase</codeph> property
 * of the ElementFormat class.
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
            class DigitCase : public Object
            {
                /**
                 * Used to specify default digit case. The results are font-dependent; characters use the settings specified by the font designer
                 * without any features applied.
                 * @langversion 3.0
                 * @playerversion   Flash 10
                 * @playerversion   AIR 1.5
                 * @playerversion   Lite 4
                 */
            public:
                static const std::string DEFAULT;

                /**
                 * Used to specify lining digit case.
                 * @langversion 3.0
                 * @playerversion   Flash 10
                 * @playerversion   AIR 1.5
                 * @playerversion   Lite 4
                 */
            public:
                static const std::string LINING;

                /**
                 * Used to specify old style digit case.
                 * @langversion 3.0
                 * @playerversion   Flash 10
                 * @playerversion   AIR 1.5
                 * @playerversion   Lite 4
                 */
            public:
                static const std::string OLD_STYLE;

            public:
                DigitCase();
            };
        }
    }
}

#endif // FLEX11_6_FLASH_TEXT_ENGINE_DIGITCASE_AS
#endif // __cplusplus

