#if !defined(FLEX11_6_FLASH_DISPLAY_STAGEDISPLAYSTATE_AS)
#define FLEX11_6_FLASH_DISPLAY_STAGEDISPLAYSTATE_AS
#if defined(__cplusplus)


/**
 * The StageDisplayState class provides values for the <codeph class="+ topic/ph pr-d/codeph ">Stage.displayState</codeph> property.
 * @langversion 3.0
 * @playerversion   Flash 9.0.28.0
 * @playerversion   Lite 4
 */


namespace flash
{
    namespace display
    {
        class StageDisplayState : public Object
        {
            /**
             * Specifies that the Stage is in full-screen mode. Keyboard interactivity is disabled in this mode.
             * @langversion 3.0
             * @playerversion   Flash 9.0.28.0
             * @playerversion   Lite 4
             */
        public:
            static const std::string FULL_SCREEN;

            /**
             * Specifies that the Stage is in full-screen mode with keyboard interactivity enabled.
             * Only AIR applications support this capability.
             * @langversion 3.0
             * @playerversion   AIR 1.0
             * @playerversion   Lite 4
             */
        public:
            static const std::string FULL_SCREEN_INTERACTIVE;

            /**
             * Specifies that the Stage is in normal mode.
             * @langversion 3.0
             * @playerversion   Flash 9.0.28.0
             * @playerversion   Lite 4
             */
        public:
            static const std::string NORMAL;

        public:
            StageDisplayState();
        };
    }
}

#endif // FLEX11_6_FLASH_DISPLAY_STAGEDISPLAYSTATE_AS
#endif // __cplusplus

