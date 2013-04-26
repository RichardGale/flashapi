#if !defined(FLEX11_6_FLASH_DISPLAY_SWFVERSION_AS)
#define FLEX11_6_FLASH_DISPLAY_SWFVERSION_AS
#if defined(__cplusplus)


/**
 * The SWFVersion class is an enumeration of constant values that indicate the
 * file format version of a loaded SWF file.
 *
 *   The SWFVersion constants are provided for use in checking the
 * <codeph class="+ topic/ph pr-d/codeph ">swfVersion</codeph> property of a flash.display.LoaderInfo object.
 * @langversion 3.0
 * @playerversion   Flash 9
 * @playerversion   Lite 4
 */

namespace flash
{
    namespace display
    {
        class SWFVersion: public Object
        {
            /**
             * SWF file format version 1.0.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            static const unsigned int FLASH1;

            /**
             * SWF file format version 2.0.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            static const unsigned int FLASH2;

            /**
             * SWF file format version 3.0.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            static const unsigned int FLASH3;

            /**
             * SWF file format version 4.0.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            static const unsigned int FLASH4;

            /**
             * SWF file format version 5.0.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            static const unsigned int FLASH5;

            /**
             * SWF file format version 6.0.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            static const unsigned int FLASH6;

            /**
             * SWF file format version 7.0.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            static const unsigned int FLASH7;

            /**
             * SWF file format version 8.0.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            static const unsigned int FLASH8;

            /**
             * SWF file format version 9.0.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            static const unsigned int FLASH9;

            /**
             * SWF file format version 10.0.
             * @langversion 3.0
             * @playerversion   Flash 10
             * @playerversion   Lite 4
             */
        public:
            static const unsigned int FLASH10;

            /**
             * SWF file format version 11.0.
             * @langversion 3.0
             * @playerversion   Flash 10.2
             */
        public:
            static const unsigned int FLASH11;
        public:
            static const unsigned int FLASH12;

        public:
            SWFVersion();
        };
    }
}

#endif // FLEX11_6_FLASH_DISPLAY_SWFVERSION_AS
#endif // __cplusplus

