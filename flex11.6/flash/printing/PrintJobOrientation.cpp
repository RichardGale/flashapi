

    /**
     * This class provides values that are used by the <codeph class="+ topic/ph pr-d/codeph ">PrintJob.orientation</codeph> property for the image position of a printed page.
     * @langversion 3.0
     * @playerversion   Flash 9
     */


namespace flash {
namespace printing {


        /**
         * The landscape (horizontal) image orientation for printing. 
         * This constant is used with the PrintJob.orientation property.
         * Use the syntax PrintJobOrientation.LANDSCAPE.
         * @langversion 3.0
         * @playerversion   Flash 9
         */
        const std::string PrintJobOrientation::LANDSCAPE="landscape";

        /**
         * The portrait (vertical) image orientation for printing.
         * This constant is used with the PrintJob.orientation property.
         * Use the syntax PrintJobOrientation.PORTRAIT.
         * @langversion 3.0
         * @playerversion   Flash 9
         */
        const std::string PrintJobOrientation::PORTRAIT="portrait";

        PrintJobOrientation::PrintJobOrientation();
}
}

