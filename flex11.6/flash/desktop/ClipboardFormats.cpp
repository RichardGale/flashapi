

    /**
     * The ClipboardFormats class defines constants for the names of the standard data formats used with the Clipboard class.
     * Flash Player 10 only supports TEXT_FORMAT, RICH_TEXT_FORMAT, and HTML_FORMAT.
     * @langversion 3.0
     * @playerversion   Flash 10
     * @playerversion   AIR 1.0
     * @internal    Clipboard, ClipboardFormats and ClipboardTransferMode were all added to AIR 1.0. These are also being added, with some exceptions listed in this file, to FP10.
     */


namespace flash {
namespace desktop {


        const std::string ClipboardFormats::FLASH_PREFIX;
        const std::string ClipboardFormats::AIR_PREFIX;
        const std::string ClipboardFormats::REFERENCE_PREFIX;
        const std::string ClipboardFormats::SERIALIZATION_PREFIX;

        /**
         * String data.
         * @langversion 3.0
         * @playerversion   Flash 10
         * @playerversion   AIR 1.0
         */
        const std::string ClipboardFormats::TEXT_FORMAT="air:text";

        /**
         * HTML data.
         * @langversion 3.0
         * @playerversion   Flash 10
         * @playerversion   AIR 1.0
         */
        const std::string ClipboardFormats::HTML_FORMAT="air:html";

        /**
         * Rich Text Format data.
         * @langversion 3.0
         * @playerversion   Flash 10
         * @playerversion   AIR 1.1
         */
        const std::string ClipboardFormats::RICH_TEXT_FORMAT="air:rtf";

        /**
         * A URL string (AIR only).
         * @langversion 3.0
         * @playerversion   AIR 1.0
         * @internal    Not supported in FP10.
         */
        const std::string ClipboardFormats::URL_FORMAT="air:url";

        /**
         * An array of files (AIR only).
         * @langversion 3.0
         * @playerversion   AIR 1.0
         * @internal    Not supported in FP10.
         */
        const std::string ClipboardFormats::FILE_LIST_FORMAT="air:file list";

        /**
         * Image data (AIR only).
         * @langversion 3.0
         * @playerversion   AIR 1.0
         * @internal    Not supported in FP10.
         */
        const std::string ClipboardFormats::BITMAP_FORMAT="air:bitmap";

        /**
         * File promise list (AIR only).
         * @langversion 3.0
         * @playerversion   AIR 2
         * @internal    Not supported in FP10.
         */
        const std::string ClipboardFormats::FILE_PROMISE_LIST_FORMAT="air:file promise list";

        ClipboardFormats::ClipboardFormats();
}
}

