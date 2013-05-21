#if !defined(FLEX11_6_FLASH_UI_MOUSECURSOR_AS)
#define FLEX11_6_FLASH_UI_MOUSECURSOR_AS
#if defined(__cplusplus)


/**
 * The MouseCursor class is an enumeration of constant values used in setting the <codeph class="+ topic/ph pr-d/codeph ">cursor</codeph> property
 * of the Mouse class.
 * @langversion 3.0
 * @playerversion   Flash 10
 * @playerversion   AIR 1.5
 */


namespace flash
{
    namespace ui
    {
        class MouseCursor : public Object
        {
            /**
             * Used to specify that the cursor should be selected automatically based on the object under the mouse.
             * @langversion 3.0
             * @playerversion   Flash 10
             * @playerversion   AIR 1.5
             */
        public:
            static const std::string AUTO;

            /**
             * Used to specify that the arrow cursor should be used.
             * @langversion 3.0
             * @playerversion   Flash 10
             * @playerversion   AIR 1.5
             */
        public:
            static const std::string ARROW;

            /**
             * Used to specify that the button pressing hand cursor should be used.
             * @langversion 3.0
             * @playerversion   Flash 10
             * @playerversion   AIR 1.5
             */
        public:
            static const std::string BUTTON;

            /**
             * Used to specify that the dragging hand cursor should be used.
             * @langversion 3.0
             * @playerversion   Flash 10
             * @playerversion   AIR 1.5
             */
        public:
            static const std::string HAND;

            /**
             * Used to specify that the I-beam cursor should be used.
             * @langversion 3.0
             * @playerversion   Flash 10
             * @playerversion   AIR 1.5
             */
        public:
            static const std::string IBEAM;

        public:
            MouseCursor();
        };
    }
}

#endif // FLEX11_6_FLASH_UI_MOUSECURSOR_AS
#endif // __cplusplus

