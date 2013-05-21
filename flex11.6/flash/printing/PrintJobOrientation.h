#if !defined(FLEX11_6_FLASH_PRINTING_PRINTJOBORIENTATION_AS)
#define FLEX11_6_FLASH_PRINTING_PRINTJOBORIENTATION_AS
#if defined(__cplusplus)


/**
 * This class provides values that are used by the <codeph class="+ topic/ph pr-d/codeph ">PrintJob.orientation</codeph> property for the image position of a printed page.
 * @langversion 3.0
 * @playerversion   Flash 9
 */


namespace flash
{
    namespace printing
    {
        class PrintJobOrientation : public Object
        {
            /**
             * The landscape (horizontal) image orientation for printing.
             * This constant is used with the PrintJob.orientation property.
             * Use the syntax PrintJobOrientation.LANDSCAPE.
             * @langversion 3.0
             * @playerversion   Flash 9
             */
        public:
            static const std::string LANDSCAPE;

            /**
             * The portrait (vertical) image orientation for printing.
             * This constant is used with the PrintJob.orientation property.
             * Use the syntax PrintJobOrientation.PORTRAIT.
             * @langversion 3.0
             * @playerversion   Flash 9
             */
        public:
            static const std::string PORTRAIT;

        public:
            PrintJobOrientation();
        };
    }
}

#endif // FLEX11_6_FLASH_PRINTING_PRINTJOBORIENTATION_AS
#endif // __cplusplus

