#if !defined(FLEX11_6_FLASH_TEXT_ENGINE_DIGITWIDTH_AS)
#define FLEX11_6_FLASH_TEXT_ENGINE_DIGITWIDTH_AS
#if defined(__cplusplus)


/**
 * The DigitWidth class is an enumeration of constant values used in setting the <codeph class="+ topic/ph pr-d/codeph ">digitWidth</codeph> property
 * of the ElementFormat class.
 * @langversion 3.0
 * @playerversion   Flash 10
 * @playerversion   AIR 1.5
 * @playerversion   Lite 4
 */

namespace flash
{
    namespace text
    {
        namespace engine
        {
            class DigitWidth: public Object
            {
                /**
                 * Used to specify default digit width. The results are font-dependent; characters use the settings specified by the font designer
                 * without any features applied.
                 * @langversion 3.0
                 * @playerversion   Flash 10
                 * @playerversion   AIR 1.5
                 * @playerversion   Lite 4
                 */
            public:
                static const std::string DEFAULT;

                /**
                 * Used to specify proportional digit width.
                 * @langversion 3.0
                 * @playerversion   Flash 10
                 * @playerversion   AIR 1.5
                 * @playerversion   Lite 4
                 */
            public:
                static const std::string PROPORTIONAL;

                /**
                 * Used to specify tabular digit width.
                 * @langversion 3.0
                 * @playerversion   Flash 10
                 * @playerversion   AIR 1.5
                 * @playerversion   Lite 4
                 */
            public:
                static const std::string TABULAR;

            public:
                DigitWidth();
            };
        }
    }
}

#endif // FLEX11_6_FLASH_TEXT_ENGINE_DIGITWIDTH_AS
#endif // __cplusplus

