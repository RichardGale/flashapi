

    /**
     * The ActionScriptVersion class is an enumeration of constant values that
     * indicate the language version of a loaded SWF file.
     * 
     *   The language version constants are provided for use in checking the 
     * <codeph class="+ topic/ph pr-d/codeph ">actionScriptVersion</codeph> property of a flash.display.LoaderInfo object.
     * @langversion 3.0
     * @playerversion   Flash 9
     * @playerversion   Lite 4
     */


namespace flash {
namespace display {


        /**
         * ActionScript language version 2.0 and earlier.
         * @langversion 3.0
         * @playerversion   Flash 9
         * @playerversion   Lite 4
         */
        const unsigned int ActionScriptVersion::ACTIONSCRIPT2   = 2;

        /**
         * ActionScript language version 3.0.
         * @langversion 3.0
         * @playerversion   Flash 9
         * @playerversion   Lite 4
         */
        const unsigned int ActionScriptVersion::ACTIONSCRIPT3   = 3;

        ActionScriptVersion::ActionScriptVersion();
}
}

