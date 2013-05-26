#if !defined(FLEX11_6_FLASH_DESKTOP_CLIPBOARDFORMATS_AS)
#define FLEX11_6_FLASH_DESKTOP_CLIPBOARDFORMATS_AS
#if defined(__cplusplus)


/**
 * The ClipboardFormats class defines constants for the names of the standard data formats used with the Clipboard class.
 * Flash Player 10 only supports TEXT_FORMAT, RICH_TEXT_FORMAT, and HTML_FORMAT.
 * @langversion 3.0
 * @playerversion   Flash 10
 * @playerversion   AIR 1.0
 * @internal    Clipboard, ClipboardFormats and ClipboardTransferMode were all added to AIR 1.0. These are also being added, with some exceptions listed in this file, to FP10.
 */

#include "flex11.6.h"



namespace flash
{
    namespace desktop
    {
        class ClipboardFormats : public Object
        {
            static const std::string FLASH_PREFIX;
            static const std::string AIR_PREFIX;
            static const std::string REFERENCE_PREFIX;
            static const std::string SERIALIZATION_PREFIX;

            /**
             * String data.
             * @langversion 3.0
             * @playerversion   Flash 10
             * @playerversion   AIR 1.0
             */
        public:
            static const std::string TEXT_FORMAT;

            /**
             * HTML data.
             * @langversion 3.0
             * @playerversion   Flash 10
             * @playerversion   AIR 1.0
             */
        public:
            static const std::string HTML_FORMAT;

            /**
             * Rich Text Format data.
             * @langversion 3.0
             * @playerversion   Flash 10
             * @playerversion   AIR 1.1
             */
        public:
            static const std::string RICH_TEXT_FORMAT;

            /**
             * A URL string (AIR only).
             * @langversion 3.0
             * @playerversion   AIR 1.0
             * @internal    Not supported in FP10.
             */
        public:
            static const std::string URL_FORMAT;

            /**
             * An array of files (AIR only).
             * @langversion 3.0
             * @playerversion   AIR 1.0
             * @internal    Not supported in FP10.
             */
        public:
            static const std::string FILE_LIST_FORMAT;

            /**
             * Image data (AIR only).
             * @langversion 3.0
             * @playerversion   AIR 1.0
             * @internal    Not supported in FP10.
             */
        public:
            static const std::string BITMAP_FORMAT;

            /**
             * File promise list (AIR only).
             * @langversion 3.0
             * @playerversion   AIR 2
             * @internal    Not supported in FP10.
             */
        public:
            static const std::string FILE_PROMISE_LIST_FORMAT;

        public:
            ClipboardFormats();
        };
    }
}

#endif // FLEX11_6_FLASH_DESKTOP_CLIPBOARDFORMATS_AS
#endif // __cplusplus

