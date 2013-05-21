

    /**
     * The TextFieldAutoSize class is an enumeration of constant values used in setting the <codeph class="+ topic/ph pr-d/codeph ">autoSize</codeph> 
     * property of the TextField class.
     * @langversion 3.0
     * @playerversion   Flash 9
     * @playerversion   Lite 4
     */


namespace flash {
namespace text {


        /**
         * Specifies that no resizing is to occur.
         * @langversion 3.0
         * @playerversion   Flash 9
         * @playerversion   Lite 4
         */
        const std::string TextFieldAutoSize::NONE="none";

        /**
         * Specifies that the text is to be treated as left-justified text, 
         * meaning that the left side of the text field remains fixed and any 
         * resizing of a single line is on the right side.
         * @langversion 3.0
         * @playerversion   Flash 9
         * @playerversion   Lite 4
         */
        const std::string TextFieldAutoSize::LEFT="left";

        /**
         * Specifies that the text is to be treated as center-justified text.
         * Any resizing of a single line of a text field is equally distributed
         * to both the right and left sides.
         * @langversion 3.0
         * @playerversion   Flash 9
         * @playerversion   Lite 4
         */
        const std::string TextFieldAutoSize::CENTER="center";

        /**
         * Specifies that the text is to be treated as right-justified text, 
         * meaning that the right side of the text field remains fixed and any 
         * resizing of a single line is on the left side.
         * @langversion 3.0
         * @playerversion   Flash 9
         * @playerversion   Lite 4
         */
        const std::string TextFieldAutoSize::RIGHT="right";

        TextFieldAutoSize::TextFieldAutoSize();
}
}

