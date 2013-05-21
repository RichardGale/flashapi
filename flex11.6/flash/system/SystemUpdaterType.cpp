

    /**
     * The SystemUpdaterType class provides constants for a system update. These constants
     * are used in the <codeph class="+ topic/ph pr-d/codeph ">SystemUpdater.update()</codeph> function.
     * 
     *   <p class="- topic/p "><b class="+ topic/ph hi-d/b ">Note</b>: The SystemUpdater API is supported on desktop platforms.</p>
     * @langversion 3.0
     * @playerversion   Flash 10.1
     */


namespace flash {
namespace system {


        /**
         * Updates the player runtime itself.
         * @langversion 3.0
         * @playerversion   Flash 10.1
         */
        const std::string SystemUpdaterType::SYSTEM="system";

        /**
         * Updates the DRM module.
         * @langversion 3.0
         * @playerversion   Flash 10.1
         */
        const std::string SystemUpdaterType::DRM="drm";

        SystemUpdaterType::SystemUpdaterType();
}
}

