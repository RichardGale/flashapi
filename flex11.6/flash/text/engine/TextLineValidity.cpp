

    /**
     * The TextLineValidity class is an enumeration of constant values for setting the <codeph class="+ topic/ph pr-d/codeph ">validity</codeph> property 
     * of the TextLine class.
     * @langversion 3.0
     * @playerversion   Flash 10
     * @playerversion   AIR 1.5
     * @playerversion   Lite 4
     */


namespace flash {
namespace text {
namespace engine {


        /**
         * Specifies that the text line is valid.
         * @langversion 3.0
         * @playerversion   Flash 10
         * @playerversion   AIR 1.5
         * @playerversion   Lite 4
         */
        const std::string TextLineValidity::VALID="valid";

        /**
         * Specifies that the text line is possibly invalid.  The Flash runtime uses this validity during rebreaking of a previously broken text 
         * block whose content has not changed.  You cannot set this value.
         * @langversion 3.0
         * @playerversion   Flash 10
         * @playerversion   AIR 1.5
         * @playerversion   Lite 4
         */
        const std::string TextLineValidity::POSSIBLY_INVALID="possiblyInvalid";

        /**
         * Specifies that the line is invalid.
         * @langversion 3.0
         * @playerversion   Flash 10
         * @playerversion   AIR 1.5
         * @playerversion   Lite 4
         */
        const std::string TextLineValidity::INVALID="invalid";

        /**
         * Specifies that the line is static, and that the connection between the line and the text block has been severed.
         * @langversion 3.0
         * @playerversion   Flash 10
         * @playerversion   AIR 1.5
         * @playerversion   Lite 4
         */
        const std::string TextLineValidity::STATIC="static";

        TextLineValidity::TextLineValidity();
}
}
}

