#if !defined(FLEX11_6_FLASH_DISPLAY_FOCUSDIRECTION_AS)
#define FLEX11_6_FLASH_DISPLAY_FOCUSDIRECTION_AS
#if defined(__cplusplus)


/**
 * The FocusDirection class enumerates values to be used for the
 * <codeph class="+ topic/ph pr-d/codeph ">direction</codeph> parameter of the <codeph class="+ topic/ph pr-d/codeph ">assignFocus()</codeph> method
 * of a Stage object and for the <codeph class="+ topic/ph pr-d/codeph ">direction</codeph> property of a FocusEvent object.
 * @langversion 3.0
 * @playerversion   AIR 1.0
 */

namespace flash
{
    namespace display
    {
        class FocusDirection: public Object
        {
            /**
             * Indicates that focus should be given to the object at the beginning of the reading order.
             * @playerversion   AIR 1.0
             */
        public:
            static const std::string TOP;

            /**
             * Indicates that focus should be given to the object at the end of the reading order.
             * @playerversion   AIR 1.0
             */
        public:
            static const std::string BOTTOM;

            /**
             * Indicates that focus object within the interactive object should not change.
             * @playerversion   AIR 1.0
             */
        public:
            static const std::string NONE;

        public:
            FocusDirection();
        };
    }
}

#endif // FLEX11_6_FLASH_DISPLAY_FOCUSDIRECTION_AS
#endif // __cplusplus

