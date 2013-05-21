#if !defined(FLEX11_6_FLASH_NET_URLVARIABLES_AS)
#define FLEX11_6_FLASH_NET_URLVARIABLES_AS
#if defined(__cplusplus)


/**
 * The URLVariables class allows you to transfer
 * variables between an application and a
 * server.
 * Use URLVariables objects with methods of the URLLoader
 * class, with the <codeph class="+ topic/ph pr-d/codeph ">data</codeph> property
 * of the URLRequest class, and with flash.net package
 * functions.
 *
 *   EXAMPLE:
 *
 *   The following example opens the remote application hosted at
 * http://www.[yourDomain].com/application.jsp in a new browser window and passes
 * data about a user session, captured in a URLVariables object, to the application.
 *
 *   <p class="- topic/p ">Highlights of the example follow:</p><ol class="- topic/ol "><li class="- topic/li ">The constructor function creates a URLRequest
 * instance named <codeph class="+ topic/ph pr-d/codeph ">request</codeph>, taking the URL of the remote application as a parameter.</li><li class="- topic/li ">A URLVariables object is created and two of its properties are assigned values.</li><li class="- topic/li ">The URLVariables object is assigned to the <codeph class="+ topic/ph pr-d/codeph ">data</codeph> property of the URLRequest object.</li><li class="- topic/li ">The example calls <codeph class="+ topic/ph pr-d/codeph ">navigateToURL</codeph>, which opens a new browser window
 * to the remote application's URL.</li></ol><p class="- topic/p "><b class="+ topic/ph hi-d/b ">Note:</b> To run the example, the remote application URL in the example must be replaced
 * with a working URL. Additionally, you would need server code
 * to process the information captured by Flash Player in the URLVariables object.</p><codeblock xml:space="preserve" class="+ topic/pre pr-d/codeblock ">
 * package {
 * import flash.display.Sprite;
 * import flash.net.navigateToURL;
 * import flash.net.URLRequest;
 * import flash.net.URLVariables;
 *
 *   public class URLVariablesExample extends Sprite {
 *
 *   public function URLVariablesExample() {
 * var url:String = "http://www.[yourDomain].com/application.jsp";
 * var request:URLRequest = new URLRequest(url);
 * var variables:URLVariables = new URLVariables();
 * variables.exampleSessionId = new Date().getTime();
 * variables.exampleUserLabel = "guest";
 * request.data = variables;
 * navigateToURL(request);
 * }
 * }
 * }
 * </codeblock>
 * @langversion 3.0
 * @playerversion   Flash 9
 * @playerversion   Lite 4
 */


namespace flash
{
    namespace net
    {
        class URLVariables : public Object
        {
            /**
             * Converts the variable string to properties of the specified URLVariables object.
             * This method is used internally by the URLVariables events.
             * Most users do not need to call this method directly.
             * @param   source  A URL-encoded query string containing name/value pairs.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             * @throws  Error The source parameter must be a URL-encoded query
             *   string containing name/value pairs.
             */
        public:
            void     decode(std::string source);

            /**
             * Returns a string containing all enumerable variables,
             * in the MIME content encoding application/x-www-form-urlencoded.
             * @return  A URL-encoded string containing name/value pairs.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            std::string toString();

            /**
             * Creates a new URLVariables object. You pass URLVariables
             * objects to the data property of URLRequest objects.
             *
             *   If you call the URLVariables constructor with a string,
             * the decode() method is automatically called
             * to convert the string to properties of the URLVariables object.
             * @param   source  A URL-encoded string containing name/value pairs.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            URLVariables(std::string source="");
        };
    }
}

#endif // FLEX11_6_FLASH_NET_URLVARIABLES_AS
#endif // __cplusplus

