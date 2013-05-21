#if !defined(FLEX11_6_ADOBE_UTILS_XMLUI_AS)
#define FLEX11_6_ADOBE_UTILS_XMLUI_AS
#if defined(__cplusplus)


/**
 * The XMLUI class enables communication with SWF files that are used as custom user interfaces for the Flash
 * authoring tool's extensibility features.
 *
 *   <p class="- topic/p ">Macromedia Flash MX 2004 and Macromedia Flash MX Professional 2004 and later versions come with several extensibility
 * features including Behaviors, Commands (JavaScript API), Effects, and Tools. With these features, advanced
 * users can extend or automate the authoring tool's capabilities. The XML-to-UI engine works with each of
 * these extensibility features to create dialog boxes that the user sees if the extension either requires or
 * accepts parameters. You can define dialog boxes by using XML tags or by creating a SWF file to display.
 * The XMLUI object provides a mechanism by which an advanced user can communicate with a SWF file used in
 * such a manner.</p>
 * @langversion 3.0
 * @playerversion   Flash 9
 * @productversion  Flash CS3
 */


namespace adobe
{
    namespace utils
    {
        class XMLUI : public Object
        {
            /**
             * Retrieves the value of the specified property of the current XMLUI dialog box.
             * @param   name    The name of the XMLUI property to retrieve.
             * @return  The value of the property.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @productversion  Flash CS3
             */
        public:
            static std::string getProperty(std::string name);

            /**
             * Modifies the value of the specified property of the current XMLUI dialog.
             * @param   name    The name of the XMLUI property to modify.
             * @param   value   The value to which the specified property will be set.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @productversion  Flash CS3
             */
        public:
            static void     setProperty(std::string name, std::string value);

            /**
             * Makes the current XMLUI dialog box close with an "accept" state. This is identical to the user
             * clicking the OK button.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @productversion  Flash CS3
             */
        public:
            static void     accept();

            /**
             * Makes the current XMLUI dialog box close with a "cancel" state. This is identical to
             * the user clicking the Cancel button.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @productversion  Flash CS3
             */
        public:
            static void     cancel();

        public:
            XMLUI();
        };
    }
}

#endif // FLEX11_6_ADOBE_UTILS_XMLUI_AS
#endif // __cplusplus

