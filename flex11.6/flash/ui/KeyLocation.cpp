

    /**
     * The KeyLocation class contains constants that indicate the location of a key pressed on 
     * the keyboard or keyboard-like input device. 
     * <p class="- topic/p ">The KeyLocation constants are used in the <codeph class="+ topic/ph pr-d/codeph ">KeyboardEvent.keyLocation</codeph> property.</p>
     * @langversion 3.0
     * @playerversion   Flash 9
     */


namespace flash {
namespace ui {


        /**
         * Indicates the key activation is not distinguished as the left or right version of the key, 
         * and did not originate on the numeric keypad (or did not originate with a virtual 
         * key corresponding to the numeric keypad). Example: The Q key on a PC 101 Key US keyboard.
         * @langversion 3.0
         * @playerversion   Flash 9
         */
        const unsigned int KeyLocation::STANDARD   = 0;

        /**
         * Indicates the key activated is in the left key location (there is more than one possible location for this 
         * key). 
         * Example: The left Shift key on a PC 101 Key US keyboard.
         * @langversion 3.0
         * @playerversion   Flash 9
         */
        const unsigned int KeyLocation::LEFT   = 1;

        /**
         * Indicates the key activated is in the right key location (there is more than one possible location for this 
         * key). 
         * Example: The right Shift key on a PC 101 Key US keyboard.
         * @langversion 3.0
         * @playerversion   Flash 9
         */
        const unsigned int KeyLocation::RIGHT   = 2;

        /**
         * Indicates the key activation originated on the numeric keypad or with a virtual key corresponding 
         * to the numeric keypad. Example: The 1 key on a PC 101 Key US keyboard located on the numeric pad.
         * @langversion 3.0
         * @playerversion   Flash 9
         */
        const unsigned int KeyLocation::NUM_PAD   = 3;

        /**
         * Indicates the key activation originated on a directional pad of input device.
         * Example: The trackball on a mobile device or the left arrow on a remote control.
         * @langversion 3.0
         * @playerversion   AIR 2.5
         */
        const unsigned int KeyLocation::D_PAD   = 4;

        KeyLocation::KeyLocation();
}
}

