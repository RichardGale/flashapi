

    /**
     * The CSMSettings class contains properties for use with the 
     * <codeph class="+ topic/ph pr-d/codeph ">TextRenderer.setAdvancedAntiAliasingTable()</codeph> method 
     * to provide continuous stroke modulation (CSM). CSM is the continuous 
     * modulation of both stroke weight and edge sharpness.
     * @langversion 3.0
     * @playerversion   Flash 9
     * @internal    Not functioning correctly. Bug report 193833
     */


namespace flash {
namespace text {


        /**
         * The size, in pixels, for which the settings apply.
         * 
         *   The advancedAntiAliasingTable array passed to the 
         * setAdvancedAntiAliasingTable() method can contain multiple
         * entries that specify CSM settings for different font sizes. Using this
         * property, you can specify the font size to which the other settings apply.
         * @langversion 3.0
         * @playerversion   Flash 9
         */
                   

        /**
         * The inside cutoff value, above which densities are set to a maximum density
         * value (such as 255).
         * @langversion 3.0
         * @playerversion   Flash 9
         */
                   

        /**
         * The outside cutoff value, below which densities are set to zero.
         * @langversion 3.0
         * @playerversion   Flash 9
         */
                   

        /**
         * Creates a new CSMSettings object which stores stroke values for custom anti-aliasing settings.
         * @param   fontSize    The size, in pixels, for which the settings apply.
         * @param   insideCutoff    The inside cutoff value, above which densities are set to a maximum density
         *   value (such as 255).
         * @param   outsideCutoff   The outside cutoff value, below which densities are set to zero.
         * @langversion 3.0
         * @playerversion   Flash 9
         */
        CSMSettings::CSMSettings(float fontSize, float insideCutoff, float outsideCutoff);
}
}

