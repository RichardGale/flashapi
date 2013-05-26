#if !defined(FLEX11_6_NAMESPACE_AS)
#define FLEX11_6_NAMESPACE_AS
#if defined(__cplusplus)


/**
 * The Namespace class contains methods and properties for defining and working with namespaces.
 * There are three scenarios for using namespaces:
 *
 *   <ul class="- topic/ul "><li class="- topic/li "><b class="+ topic/ph hi-d/b ">Namespaces of XML objects</b> Namespaces associate a namespace prefix with a Uniform Resource Identifier (URI)
 * that identifies the namespace. The prefix is a string used to reference the namespace within an
 * XML object. If the prefix is undefined, when the XML is converted to a string, a prefix is
 * automatically generated.
 * </li><li class="- topic/li "><b class="+ topic/ph hi-d/b ">Namespace to differentiate methods</b> Namespaces can differentiate methods with the same name to perform different tasks.
 * If two methods have the same name but separate namespaces, they can perform different tasks.
 * </li><li class="- topic/li "><b class="+ topic/ph hi-d/b ">Namespaces for access control</b>
 * Namespaces can be used to control access to a group of
 * properties and methods in a class. If you place the
 * properties and methods into a private
 * namespace, they are
 * inaccessible to any code that does not have access to
 * that namespace. You can grant access to the group of
 * properties and methods by passing the namespace to
 * other classes, methods or functions.
 * </li></ul><p class="- topic/p ">This class shows two forms of the constructor method because each form accepts
 * different parameters.</p><p class="- topic/p ">This class (along with the XML, XMLList, and QName classes) implements
 * powerful XML-handling standards defined in ECMAScript for XML
 * (E4X) specification (ECMA-357 edition 2).</p>
 *
 *   EXAMPLE:
 *
 *   The following example shows how to work with namespaces defined in XML objects.
 * This is accomplished with the following steps:
 * <ol class="- topic/ol "><li class="- topic/li ">The example defines three Namespace objects, each with a unique URI that defines a namespace.</li><li class="- topic/li ">The example defines an XML variable named <codeph class="+ topic/ph pr-d/codeph ">myXML</codeph> and assigns it to the return value of
 * <codeph class="+ topic/ph pr-d/codeph ">getRSS()</codeph>.  The <codeph class="+ topic/ph pr-d/codeph ">getRSS()</codeph> method defines an XML object that contains several namespaces
 * and returns that XML object.</li><li class="- topic/li ">The example declares and evaluates an Array variable by calling the <codeph class="+ topic/ph pr-d/codeph ">parseRSS()</codeph> method with
 * <codeph class="+ topic/ph pr-d/codeph ">myXML</codeph> passed to it.  In <codeph class="+ topic/ph pr-d/codeph ">parseRSS()</codeph>, the default XML namespace is defined as
 * <codeph class="+ topic/ph pr-d/codeph ">rss</codeph> and the example defines an XMLList variable by assigning the list of <codeph class="+ topic/ph pr-d/codeph ">item</codeph>
 * objects in <codeph class="+ topic/ph pr-d/codeph ">myXML</codeph>.  An array is created and populated with various nodes within
 * <codeph class="+ topic/ph pr-d/codeph ">myXML.item</codeph>. The array is then returned.</li><li class="- topic/li ">The elements in the array are printed using a <codeph class="+ topic/ph pr-d/codeph ">for</codeph> loop and three calls to
 * <codeph class="+ topic/ph pr-d/codeph ">trace()</codeph>.</li></ol><codeblock xml:space="preserve" class="+ topic/pre pr-d/codeblock ">
 * package {
 * import flash.display.Sprite;
 *
 *   public class NamespaceExample extends Sprite {
 * private var rss:Namespace = new Namespace("http://purl.org/rss/1.0/");
 * private var rdf:Namespace = new Namespace("http://www.w3.org/1999/02/22-rdf-syntax-ns#");
 * private var dc:Namespace  = new Namespace("http://purl.org/dc/elements/1.1/");
 *
 *   public function NamespaceExample() {
 * var myXML:XML = getRSS();
 * var rssItems:Array = parseRSS(myXML);
 *
 *   var len:uint = rssItems.length;
 * for (var i:uint; i &lt; len; i++) {
 * trace(rssItems[i].title);
 * trace(rssItems[i].creator);
 * trace(rssItems[i].date);
 * // Adobe Flash Developer Center
 * // Adobe
 * // 2005-08-08
 * // Flex Developer Center
 * // Adobe
 * // 2005-10-16
 * }
 * }
 *
 *   private function parseRSS(rssXML:XML):Array {
 * default xml namespace = rss;
 *
 *   var items:XMLList = rssXML.item;
 *
 *   var arr:Array = new Array();
 * var len:uint = items.length();
 * for (var i:uint; i &lt; len; i++) {
 * arr.push({title:items[i].title, creator:items[i].dc::creator, date:items[i].dc::date});
 * }
 *
 *   return arr;
 * }
 *
 *   private function getRSS():XML {
 * var myXML:XML =  &lt;rdf:RDF
 * xmlns:rdf="http://www.w3.org/1999/02/22-rdf-syntax-ns#"
 * xmlns="http://purl.org/rss/1.0/"
 * xmlns:dc="http://purl.org/dc/elements/1.1/"
 * &gt;
 * &lt;channel rdf:about="http://www.xml.com/cs/xml/query/q/19"&gt;
 * &lt;title&gt;Test RSS&lt;/title&gt;
 * &lt;link&gt;http://www.adobe.com/&lt;/link&gt;
 * &lt;description&gt;This is a test RSS document.&lt;/description&gt;
 * &lt;language&gt;en-us&lt;/language&gt;
 * &lt;items&gt;
 * &lt;rdf:Seq&gt;
 * &lt;rdf:li rdf:resource="http://www.adobe.com/devnet/flash/"/&gt;
 * &lt;rdf:li rdf:resource="http://www.adobe.com/devnet/flex/"/&gt;
 * &lt;/rdf:Seq&gt;
 * &lt;/items&gt;
 * &lt;/channel&gt;
 * &lt;item rdf:about="http://www.adobe.com/devnet/flash/"&gt;
 * &lt;title&gt;Adobe Flash Developer Center&lt;/title&gt;
 * &lt;link&gt;http://www.adobe.com/devnet/flash/&lt;/link&gt;
 * &lt;description&gt;Welcome to the Flash Developer Center&lt;/description&gt;
 * &lt;dc:creator&gt;Adobe&lt;/dc:creator&gt;
 * &lt;dc:date&gt;2005-08-08&lt;/dc:date&gt;
 * &lt;/item&gt;
 * &lt;item rdf:about="http://www.adobe.com/devnet/flex/"&gt;
 * &lt;title&gt;Flex Developer Center&lt;/title&gt;
 * &lt;link&gt;http://www.adobe.com/devnet/flex/&lt;/link&gt;
 * &lt;description&gt;Welcome to the Flex Developer Center&lt;/description&gt;
 * &lt;dc:creator&gt;Adobe&lt;/dc:creator&gt;
 * &lt;dc:date&gt;2005-10-16&lt;/dc:date&gt;
 * &lt;/item&gt;
 * &lt;/rdf:RDF&gt;;
 *
 *   return myXML;
 * }
 * }
 * }
 * </codeblock>
 *
 *   EXAMPLE:
 *
 *   The following example shows how namespaces can be used to differentiate methods that have
 * the same name but perform different tasks. In this example, three methods named <codeph class="+ topic/ph pr-d/codeph ">hello()</codeph>
 * reside in separate namespaces; each returns a different string when called.
 * <codeblock xml:space="preserve" class="+ topic/pre pr-d/codeblock ">
 * package {
 *
 *   import flash.display.Sprite;
 *
 *   public class Namespace_2_Example extends Sprite {
 * public function Namespace_2_Example() {
 * var vocab:MultilingualVocabulary = new MultilingualVocabulary();
 *
 *   trace(vocab.hello());    // hello
 *
 *   var languages:Array = vocab.getLanguages();
 *
 *   for (var i:uint; i &lt; languages.length; i++) {
 * var ns:Namespace = languages[i];
 * if (ns != null) {
 * trace(ns.toString() + ": " + vocab.ns::hello());
 * // hello
 * // MultilingualVocabulary:Hawaiian: aloha
 * // MultilingualVocabulary:French: bon jour
 * }
 * }
 * }
 * }
 * }
 *
 *   class MultilingualVocabulary {
 * public namespace French;
 * public namespace Hawaiian;
 * private var languages:Array;
 *
 *   public function MultilingualVocabulary() {
 * languages = new Array(Hawaiian, French);
 * }
 *
 *   public function hello():String {
 * return "hello";
 * }
 *
 *   Hawaiian function hello():String {
 * return "aloha";
 * }
 *
 *   French function hello():String {
 * return "bon jour";
 * }
 *
 *   public function getLanguages():Array {
 * return languages;
 * }
 * }
 * </codeblock>
 *
 *   EXAMPLE:
 *
 *   The following example uses namespace names to select an appropriate
 * variable value. It shows how you can store a namespace value in a variable and use
 * that variable to refer to objects within that namespace.
 * <p class="- topic/p ">The example defines namespaces and colors that correspond to mouse
 * states for a rectangular button. Each time the button is drawn, the example applies
 * the appropriate color (out is red; over is yellow; down is white) by referencing the <codeph class="+ topic/ph pr-d/codeph ">bgcolor</codeph>
 * variable for the corresponding namespace (<codeph class="+ topic/ph pr-d/codeph ">out</codeph>, <codeph class="+ topic/ph pr-d/codeph ">over</codeph>, <codeph class="+ topic/ph pr-d/codeph ">down</codeph>). </p><codeblock xml:space="preserve" class="+ topic/pre pr-d/codeblock ">
 * package {
 * import flash.display.Sprite;
 *
 *   public class Namespace_3_Example extends Sprite {
 * public function Namespace_3_Example() {
 * addChild(new StateButton("Press Me."));
 * }
 * }
 * }
 *
 *   import flash.display.Sprite;
 * import flash.text.TextField;
 * import flash.events.Event;
 * import flash.events.MouseEvent;
 *
 *   class StateButton extends Sprite{
 * private namespace out;
 * private namespace over;
 * private namespace down;
 * private var label:TextField;
 * private var labelTxt:String;
 * private var ns:Namespace;
 * out var bgColor:Number = 0xFF0000;
 * over var bgColor:Number = 0xFFFF00;
 * down var bgColor:Number = 0xFFFFFF;
 *
 *   public function StateButton(str:String) {
 * buttonMode = true;
 * labelTxt = str;
 * ns = out;
 * draw();
 * addLabel();
 * addListeners();
 * }
 *
 *   private function addLabel():void {
 * label = new TextField();
 * label.text = labelTxt;
 * label.width = 50;
 * label.height = 20;
 * label.mouseEnabled = false;
 * addChild(label);
 * }
 *
 *   private function addListeners():void {
 * addEventListener(MouseEvent.MOUSE_UP, mouseOverHandler);
 * addEventListener(MouseEvent.MOUSE_OUT, mouseOutHandler);
 * addEventListener(MouseEvent.MOUSE_OVER, mouseOverHandler);
 * addEventListener(MouseEvent.MOUSE_DOWN, mouseDownHandler);
 * }
 *
 *   private function mouseOutHandler(e:Event):void {
 * ns = out;
 * draw();
 * }
 *
 *   private function mouseOverHandler(e:Event):void {
 * ns = over;
 * draw();
 * }
 *
 *   private function mouseDownHandler(e:Event):void {
 * ns = down;
 * draw();
 * }
 *
 *   private function draw():void {
 * this.graphics.clear();
 * this.graphics.beginFill(ns::bgColor);
 * this.graphics.drawRect(0, 0, 60, 20);
 * }
 * }
 * </codeblock>
 * @langversion 3.0
 * @playerversion   Flash 9
 * @playerversion   Lite 4
 */

#include "flex11.6.h"



class Namespace : public Object
{
public:
    static const void *length;

    /**
     * The prefix of the namespace.
     * @langversion 3.0
     * @playerversion   Flash 9
     */
public:
    std::string       prefix();

    /**
     * The Uniform Resource Identifier (URI) of the namespace.
     * @langversion 3.0
     * @playerversion   Flash 9
     */
public:
    std::string       uri();

public:
    Namespace(void *prefix=NULL, void *uri=NULL);

    /**
     * Returns the URI value of the specified object.
     * @return  The Uniform Resource Identifier (URI) of the namespace, as a string.
     * @langversion 3.0
     * @playerversion   Flash 9
     */
    std::string   valueOf();

    /**
     * Equivalent to the Namespace.uri property.
     * @return  The Uniform Resource Identifier (URI) of the namespace, as a string.
     * @langversion 3.0
     * @playerversion   Flash 9
     */
    std::string   toString();
};

#endif // FLEX11_6_NAMESPACE_AS
#endif // __cplusplus

