#if !defined(FLEX11_6_FLASH_UI_KEYLOCATION_AS)
#define FLEX11_6_FLASH_UI_KEYLOCATION_AS
#if defined(__cplusplus)


/**
 * The KeyLocation class contains constants that indicate the location of a key pressed on
 * the keyboard or keyboard-like input device.
 * <p class="- topic/p ">The KeyLocation constants are used in the <codeph class="+ topic/ph pr-d/codeph ">KeyboardEvent.keyLocation</codeph> property.</p>
 * @langversion 3.0
 * @playerversion   Flash 9
 */

#include "flex11.6.h"



namespace flash
{
    namespace ui
    {
        class KeyLocation : public Object
        {
            /**
             * Indicates the key activation is not distinguished as the left or right version of the key,
             * and did not originate on the numeric keypad (or did not originate with a virtual
             * key corresponding to the numeric keypad). Example: The Q key on a PC 101 Key US keyboard.
             * @langversion 3.0
             * @playerversion   Flash 9
             */
        public:
            static const unsigned int STANDARD;

            /**
             * Indicates the key activated is in the left key location (there is more than one possible location for this
             * key).
             * Example: The left Shift key on a PC 101 Key US keyboard.
             * @langversion 3.0
             * @playerversion   Flash 9
             */
        public:
            static const unsigned int LEFT;

            /**
             * Indicates the key activated is in the right key location (there is more than one possible location for this
             * key).
             * Example: The right Shift key on a PC 101 Key US keyboard.
             * @langversion 3.0
             * @playerversion   Flash 9
             */
        public:
            static const unsigned int RIGHT;

            /**
             * Indicates the key activation originated on the numeric keypad or with a virtual key corresponding
             * to the numeric keypad. Example: The 1 key on a PC 101 Key US keyboard located on the numeric pad.
             * @langversion 3.0
             * @playerversion   Flash 9
             */
        public:
            static const unsigned int NUM_PAD;

            /**
             * Indicates the key activation originated on a directional pad of input device.
             * Example: The trackball on a mobile device or the left arrow on a remote control.
             * @langversion 3.0
             * @playerversion   AIR 2.5
             */
        public:
            static const unsigned int D_PAD;

        public:
            KeyLocation();
        };
    }
}

#endif // FLEX11_6_FLASH_UI_KEYLOCATION_AS
#endif // __cplusplus

