#if !defined(FLEX11_6_FLASH_PRINTING_PRINTJOBOPTIONS_AS)
#define FLEX11_6_FLASH_PRINTING_PRINTJOBOPTIONS_AS
#if defined(__cplusplus)


/**
 * The PrintJobOptions class contains properties to use with the
 * <codeph class="+ topic/ph pr-d/codeph ">options</codeph> parameter of the <codeph class="+ topic/ph pr-d/codeph ">PrintJob.addPage()</codeph> method.
 * For more information about <codeph class="+ topic/ph pr-d/codeph ">addPage()</codeph>, see the PrintJob class.
 * @langversion 3.0
 * @playerversion   Flash 9
 */


namespace flash
{
    namespace printing
    {
        class PrintJobOptions : public Object
        {
            /**
             * Specifies whether the content in the print job is printed as a bitmap or as a vector.
             * The default value is false, for vector printing.
             *
             *   If the content that you're printing includes a bitmap image,
             * set printAsBitmap to true to include any
             * alpha transparency and color effects.
             * If the content does not include bitmap images, print
             * the content in higher quality vector format (the default option).For example, to print your content as a bitmap, use the following syntax:
             * <codeblock>
             *
             *   var options:PrintJobOptions = new PrintJobOptions();
             * options.printAsBitmap = true;
             * myPrintJob.addPage(mySprite, null, options);
             *
             *   </codeblock>
             * Note:Adobe AIR does not support vector printing on Mac OS.
             * @langversion 3.0
             * @playerversion   Flash 9
             */
        public:
            bool printAsBitmap;

            /**
             * Creates a new PrintJobOptions object. Pass this object
             * to the options parameter of the PrintJob.addPage() method.
             * @param   printAsBitmap   If true, this object is printed as a bitmap.
             *   If false, this object is printed as a vector.
             *
             *     If the content that you're printing includes a bitmap image,
             *   set the printAsBitmap property to true to include any
             *   alpha transparency and color effects.
             *   If the content does not include bitmap images, omit this parameter to print
             *   the content in higher quality vector format (the default option).Note:Adobe AIR does not support vector printing on Mac OS.
             * @langversion 3.0
             * @playerversion   Flash 9
             */
        public:
            PrintJobOptions(bool printAsBitmap   =false);
        };
    }
}

#endif // FLEX11_6_FLASH_PRINTING_PRINTJOBOPTIONS_AS
#endif // __cplusplus

