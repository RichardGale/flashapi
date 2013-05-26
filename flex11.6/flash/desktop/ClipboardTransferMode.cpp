

    /**
     * The ClipboardTransferMode class defines constants for the modes used as values of the <codeph class="+ topic/ph pr-d/codeph ">transferMode</codeph>
     * parameter of the <codeph class="+ topic/ph pr-d/codeph ">Clipboard.getData()</codeph> method.
     * 
     *   <p class="- topic/p ">The transfer mode provides a hint about whether to return a reference or a 
     * copy when accessing an object contained on a clipboard.</p>
     * @langversion 3.0
     * @playerversion   Flash 10
     * @playerversion   AIR 1.0
     * @internal    Clipboard, ClipboardFormats and ClipboardTransferMode were all added to AIR 1.0. These are also being added, with some exceptions listed in this file, to FP10.
     */


namespace flash {
namespace desktop {


        /**
         * The Clipboard object should return a reference if available and a copy if not.
         * @langversion 3.0
         * @playerversion   Flash 10
         * @playerversion   AIR 1.0
         */
        const std::string ClipboardTransferMode::ORIGINAL_PREFERRED   = "originalPreferred";

        /**
         * The Clipboard object should only return a reference.
         * @langversion 3.0
         * @playerversion   Flash 10
         * @playerversion   AIR 1.0
         */
        const std::string ClipboardTransferMode::ORIGINAL_ONLY   = "originalOnly";

        /**
         * The Clipboard object should return a copy if available and a reference if not.
         * @langversion 3.0
         * @playerversion   Flash 10
         * @playerversion   AIR 1.0
         */
        const std::string ClipboardTransferMode::CLONE_PREFERRED   = "clonePreferred";

        /**
         * The Clipboard object should only return a copy.
         * @langversion 3.0
         * @playerversion   Flash 10
         * @playerversion   AIR 1.0
         */
        const std::string ClipboardTransferMode::CLONE_ONLY   = "cloneOnly";

        ClipboardTransferMode::ClipboardTransferMode();
}
}

