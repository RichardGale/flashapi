#if !defined(FLEX11_6_FLASH_TEXT_ENGINE_JUSTIFICATIONSTYLE_AS)
#define FLEX11_6_FLASH_TEXT_ENGINE_JUSTIFICATIONSTYLE_AS
#if defined(__cplusplus)


/**
 * The JustificationStyle class is an enumeration of constant values for setting the <codeph class="+ topic/ph pr-d/codeph ">justificationStyle</codeph> property
 * of the EastAsianJustifier class. These constants specify options for handling kinsoku characters, which are Japanese characters that cannot
 * appear at either the beginning or end of a line.
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
            class JustificationStyle : public Object
            {
                /**
                 * Bases justification on compressing kinsoku at the end of the line,
                 * or expanding it if no kinsoku occurs or if that space is insufficient.
                 * @langversion 3.0
                 * @playerversion   Flash 10
                 * @playerversion   AIR 1.5
                 * @playerversion   Lite 4
                 */
            public:
                static const std::string PUSH_IN_KINSOKU;

                /**
                 * Bases justification on expanding the line.
                 * @langversion 3.0
                 * @playerversion   Flash 10
                 * @playerversion   AIR 1.5
                 * @playerversion   Lite 4
                 */
            public:
                static const std::string PUSH_OUT_ONLY;

                /**
                 * Bases justification on either expanding or compressing
                 * the line, whichever gives a result closest to the desired width.
                 * @langversion 3.0
                 * @playerversion   Flash 10
                 * @playerversion   AIR 1.5
                 * @playerversion   Lite 4
                 */
            public:
                static const std::string PRIORITIZE_LEAST_ADJUSTMENT;

            public:
                JustificationStyle();
            };
        }
    }
}

#endif // FLEX11_6_FLASH_TEXT_ENGINE_JUSTIFICATIONSTYLE_AS
#endif // __cplusplus

