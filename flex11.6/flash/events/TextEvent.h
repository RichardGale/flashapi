#if !defined(FLEX11_6_FLASH_EVENTS_TEXTEVENT_AS)
#define FLEX11_6_FLASH_EVENTS_TEXTEVENT_AS
#if defined(__cplusplus)


#include "flash/events/Event.h"


/// @eventType  flash.events.TextEvent.LINK
//[Event(name="link",type="flash.events.TextEvent")]


//[Event(name="textInput",type="flash.events.TextEvent")]/// @eventType  flash.events.TextEvent.TEXT_INPUT

/**
 * An object dispatches a TextEvent object when a user enters text in a text field or clicks
 * a hyperlink in an HTML-enabled text field. There are two types of text events: <codeph class="+ topic/ph pr-d/codeph ">TextEvent.LINK</codeph>
 * and <codeph class="+ topic/ph pr-d/codeph ">TextEvent.TEXT_INPUT</codeph>.
 *
 *   EXAMPLE:
 *
 *   The following example uses the TextEventExample class to create text fields and to
 * listen for various text events on them.  The example carries out the following tasks:
 * <ol class="- topic/ol "><li class="- topic/li ">The example declares constants for two URLs to be used later.</li><li class="- topic/li ">The example declares two variables of type TextField to be used later.</li><li class="- topic/li ">The class constructor calls the following two methods:
 * <ul class="- topic/ul "><li class="- topic/li "><codeph class="+ topic/ph pr-d/codeph ">init()</codeph> initializes the TextField objects and add event listeners to them.</li><li class="- topic/li "><codeph class="+ topic/ph pr-d/codeph ">draw()</codeph> adds the TextFields to the display list and assigns the text to be displayed.</li></ul></li><li class="- topic/li ">The listeners <codeph class="+ topic/ph pr-d/codeph ">linkHandler()</codeph> and <codeph class="+ topic/ph pr-d/codeph ">textInputHandler()</codeph> react to the events
 * according to their event type. The <codeph class="+ topic/ph pr-d/codeph ">linkHandler()</codeph> method opens a web browser if one is not open already
 * and navigates to the clicked URL. The <codeph class="+ topic/ph pr-d/codeph ">textInputHandler()</codeph> method simply displays information every time
 * a key is pressed in the associated text field.</li></ol><p class="- topic/p "><b class="+ topic/ph hi-d/b ">Note: </b>The domain shown in this example is fictitious and <codeph class="+ topic/ph pr-d/codeph ">[yourDomain]</codeph>
 * should be replaced with a real domain.</p><codeblock xml:space="preserve" class="+ topic/pre pr-d/codeblock ">
 * package {
 * import flash.display.Sprite;
 * import flash.text.TextField;
 * import flash.text.TextFieldType;
 * import flash.text.TextFieldAutoSize;
 * import flash.events.TextEvent;
 * import flash.events.TextEvent;
 * import flash.net.URLRequest;
 * import flash.net.navigateToURL;
 *
 *   public class TextEventExample extends Sprite {
 * private const DOMAIN_1_URL:String = "http://www.[yourDomain].com";
 * private const DOMAIN_2_URL:String = "http://www.[yourDomain].com";
 * private var linkTxt:TextField;
 * private var textInputTxt:TextField;
 *
 *   public function TextEventExample() {
 * init();
 * draw();
 * }
 *
 *   private function init():void {
 * linkTxt = new TextField();
 * linkTxt.addEventListener(TextEvent.LINK, linkHandler);
 * linkTxt.height = 60;
 * linkTxt.autoSize = TextFieldAutoSize.LEFT;
 * linkTxt.multiline = true;
 *
 *   textInputTxt = new TextField();
 * textInputTxt.addEventListener(TextEvent.TEXT_INPUT, textInputHandler);
 * textInputTxt.type = TextFieldType.INPUT;
 * textInputTxt.background = true;
 * textInputTxt.border = true;
 * textInputTxt.height = 20;
 * }
 *
 *   private function draw():void {
 * addChild(linkTxt);
 * linkTxt.htmlText += createLink(DOMAIN_1_URL, "Click to go to first domain");
 * linkTxt.htmlText += "&lt;br /&gt;";
 * linkTxt.htmlText += createLink(DOMAIN_2_URL, "Click to go to second domain");
 *
 *   addChild(textInputTxt);
 * textInputTxt.y = linkTxt.height;
 * textInputTxt.text = "type here";
 * }
 *
 *   private function createLink(url:String, text:String):String {
 * var link:String = "";
 * link += "&lt;font color='#0000FF'&gt;";
 * link += "&lt;u&gt;";
 * link += "&lt;b&gt;";
 * link += "&lt;a href='event:" + url + "'&gt;" + text + "&lt;/a&gt;";
 * link += "&lt;/b&gt;";
 * link += "&lt;/u&gt;";
 * link += "&lt;/font&gt;";
 * return link;
 * }
 *
 *   private function linkHandler(e:TextEvent):void {
 * var request:URLRequest = new URLRequest(e.text);
 * navigateToURL(request);
 * }
 *
 *   private function textInputHandler(e:TextEvent):void {
 * trace("&gt;&gt; ============================");
 * trace("&gt;&gt; e.text: " + e.text);
 * trace("&gt;&gt; textInputTxt.text: " + textInputTxt.text);
 * }
 * }
 * }
 * </codeblock>
 * @langversion 3.0
 * @playerversion   Flash 9
 * @playerversion   Lite 4
 */
using namespace flash::events;

namespace flash
{
    namespace events
    {
        class TextEvent: public Event
        {
            /**
             * Defines the value of the type property of a link event object.
             *
             *   This event has the following properties:PropertyValuebubblestruecancelablefalse; there is no default behavior to cancel.currentTargetThe object that is actively processing the Event
             * object with an event listener.targetThe text field containing the hyperlink that has been clicked.
             * The target is not always the object in the display list
             * that registered the event listener. Use the currentTarget
             * property to access the object in the display list that is currently processing the event.textThe remainder of the URL after "event:"
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            static const std::string LINK;

            /**
             * Defines the value of the type property of a textInput event object.
             * Note: This event is not dispatched for the Delete or Backspace keys.This event has the following properties:PropertyValuebubblestruecancelabletrue; call the preventDefault() method
             * to cancel default behavior.currentTargetThe object that is actively processing the Event
             * object with an event listener.targetThe text field into which characters are being entered.
             * The target is not always the object in the display list
             * that registered the event listener. Use the currentTarget
             * property to access the object in the display list that is currently processing the event.textThe character or sequence of characters entered by the user.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            static const std::string TEXT_INPUT;

            /**
             * For a textInput event, the character or sequence of characters
             * entered by the user. For a link event, the text
             * of the event attribute of the href attribute of the
             * <a> tag.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            std::string  text();
        public:
            void         text(std::string value);

            /**
             * Creates a copy of the TextEvent object and sets the value of each property to match that of the original.
             * @return  A new TextEvent object with property values that match those of the original.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            flash::events::Event *clone();

            /**
             * Creates an Event object that contains information about text events.
             * Event objects are passed as parameters to event listeners.
             * @param   type    The type of the event. Event listeners can access this information through the inherited type property. Possible values are:
             *   TextEvent.LINK and TextEvent.TEXT_INPUT.
             * @param   bubbles Determines whether the Event object participates in the bubbling phase of the event flow. Event listeners can access this information through the inherited bubbles property.
             * @param   cancelable  Determines whether the Event object can be canceled. Event listeners can access this information through the inherited cancelable property.
             * @param   text    One or more characters of text entered by the user. Event listeners can access this information through the text property.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            TextEvent(std::string type, bool bubbles, bool cancelable, std::string text);

            /**
             * Returns a string that contains all the properties of the TextEvent object. The string is in the following format:
             * [TextEvent type=value bubbles=value cancelable=value text=value]
             * @return  A string that contains all the properties of the TextEvent object.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            std::string toString();
        };
    }
}

#endif // FLEX11_6_FLASH_EVENTS_TEXTEVENT_AS
#endif // __cplusplus

