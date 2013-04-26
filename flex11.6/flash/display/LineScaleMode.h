#if !defined(FLEX11_6_FLASH_DISPLAY_LINESCALEMODE_AS)
#define FLEX11_6_FLASH_DISPLAY_LINESCALEMODE_AS
#if defined(__cplusplus)


/**
 * The LineScaleMode class provides values for the <codeph class="+ topic/ph pr-d/codeph ">scaleMode</codeph>
 * parameter in the <codeph class="+ topic/ph pr-d/codeph ">Graphics.lineStyle()</codeph> method.
 * @langversion 3.0
 * @playerversion   Flash 9
 */

namespace flash
{
    namespace display
    {
        class LineScaleMode: public Object
        {
            /**
             * With this setting used as the scaleMode parameter of the lineStyle()
             * method, the thickness of the line always scales when the object is scaled (the default).
             * @langversion 3.0
             * @playerversion   Flash 9
             */
        public:
            static const std::string NORMAL;

            /**
             * With this setting used as the scaleMode parameter of the lineStyle()
             * method, the thickness of the line scales only horizontally. For example,
             * consider the following circles, drawn with a one-pixel line, and each with the
             * scaleMode parameter set to LineScaleMode.HORIZONTAL. The circle on the left
             * is scaled only horizontally, and the circle on the right is scaled both vertically and horizontally.
             * @langversion 3.0
             * @playerversion   Flash 9
             */
        public:
            static const std::string VERTICAL;

            /**
             * With this setting used as the scaleMode parameter of the lineStyle()
             * method, the thickness of the line scales only vertically. For example,
             * consider the following circles, drawn with a one-pixel line, and each with the
             * scaleMode parameter set to LineScaleMode.VERTICAL. The circle on the left
             * is scaled only vertically, and the circle on the right is scaled both vertically and horizontally.
             * @langversion 3.0
             * @playerversion   Flash 9
             */
        public:
            static const std::string HORIZONTAL;

            /**
             * With this setting used as the scaleMode parameter of the lineStyle()
             * method, the thickness of the line never scales.
             * @langversion 3.0
             * @playerversion   Flash 9
             */
        public:
            static const std::string NONE;

        public:
            LineScaleMode();
        };
    }
}

#endif // FLEX11_6_FLASH_DISPLAY_LINESCALEMODE_AS
#endif // __cplusplus

