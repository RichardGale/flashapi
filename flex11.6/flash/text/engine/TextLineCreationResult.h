#if !defined(FLEX11_6_FLASH_TEXT_ENGINE_TEXTLINECREATIONRESULT_AS)
#define FLEX11_6_FLASH_TEXT_ENGINE_TEXTLINECREATIONRESULT_AS
#if defined(__cplusplus)


/**
 * The TextLineCreationResult class is an enumeration of constant values used with <codeph class="+ topic/ph pr-d/codeph ">TextBlock.textLineCreationResult</codeph>.
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
            class TextLineCreationResult : public Object
            {
                /**
                 * Indicates the line was successfully broken.
                 * @langversion 3.0
                 * @playerversion   Flash 10
                 * @playerversion   AIR 1.5
                 * @playerversion   Lite 4
                 */
            public:
                static const std::string SUCCESS;

                /**
                 * Indicates the line was created with an emergency break because no break opportunity
                 * was available in the specified width.
                 * @langversion 3.0
                 * @playerversion   Flash 10
                 * @playerversion   AIR 1.5
                 * @playerversion   Lite 4
                 */
            public:
                static const std::string EMERGENCY;

                /**
                 * Indicates no line was created because all text in the block had already been broken.
                 * @langversion 3.0
                 * @playerversion   Flash 10
                 * @playerversion   AIR 1.5
                 * @playerversion   Lite 4
                 */
            public:
                static const std::string COMPLETE;

                /**
                 * Indicates no line was created because no text could fit in the specified width
                 * and fitSomething was not specified in the call to createTextLine().
                 * @langversion 3.0
                 * @playerversion   Flash 10
                 * @playerversion   AIR 1.5
                 * @playerversion   Lite 4
                 */
            public:
                static const std::string INSUFFICIENT_WIDTH;

            public:
                TextLineCreationResult();
            };
        }
    }
}

#endif // FLEX11_6_FLASH_TEXT_ENGINE_TEXTLINECREATIONRESULT_AS
#endif // __cplusplus

