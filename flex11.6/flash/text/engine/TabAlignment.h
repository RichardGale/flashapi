#if !defined(FLEX11_6_FLASH_TEXT_ENGINE_TABALIGNMENT_AS)
#define FLEX11_6_FLASH_TEXT_ENGINE_TABALIGNMENT_AS
#if defined(__cplusplus)


/**
 * The TabAlignment class is an enumeration of constant values that you can use to set the <codeph class="+ topic/ph pr-d/codeph ">tabAlignment</codeph> property
 * of the <codeph class="+ topic/ph pr-d/codeph ">TabStop</codeph> class.
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
            class TabAlignment : public Object
            {
                /**
                 * Positions the start of the tabbed text at the tab stop.
                 * @langversion 3.0
                 * @playerversion   Flash 10
                 * @playerversion   AIR 1.5
                 * @playerversion   Lite 4
                 */
            public:
                static const std::string START;

                /**
                 * Positions the center of the tabbed text at the tab stop.
                 * @langversion 3.0
                 * @playerversion   Flash 10
                 * @playerversion   AIR 1.5
                 * @playerversion   Lite 4
                 */
            public:
                static const std::string CENTER;

                /**
                 * Positions the end of the tabbed text at the tab stop.
                 * @langversion 3.0
                 * @playerversion   Flash 10
                 * @playerversion   AIR 1.5
                 * @playerversion   Lite 4
                 */
            public:
                static const std::string END;

                /**
                 * Positions the alignment token of the tabbed text at the tab stop.
                 * @langversion 3.0
                 * @playerversion   Flash 10
                 * @playerversion   AIR 1.5
                 * @playerversion   Lite 4
                 */
            public:
                static const std::string DECIMAL;

            public:
                TabAlignment();
            };
        }
    }
}

#endif // FLEX11_6_FLASH_TEXT_ENGINE_TABALIGNMENT_AS
#endif // __cplusplus

