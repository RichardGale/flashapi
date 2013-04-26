#if !defined(FLEX11_6_FLASH_XML_XMLDOCUMENT_AS)
#define FLEX11_6_FLASH_XML_XMLDOCUMENT_AS
#if defined(__cplusplus)


#include "flash/xml/XMLNode.h"

/**
 * The XMLDocument class represents the legacy XML object
 * that was present in ActionScript 2.0. It was renamed in ActionScript 3.0
 * to XMLDocument to avoid name conflicts with the new
 * XML class in ActionScript 3.0. In ActionScript 3.0,
 * it is recommended that you use the new
 * <xref href="../../XML.html" class="- topic/xref ">XML</xref> class and related classes,
 * which support E4X (ECMAScript for XML).
 *
 *   <p class="- topic/p ">The XMLDocument class, as well as XMLNode and XMLNodeType, are present for backward
 * compatibility. The functionality for loading XML documents can now be found in the
 * URLLoader class.</p>
 *
 *   EXAMPLE:
 *
 *   The following example uses the XMLDocument and XMLNode classes
 * to parse and format an XML document. Rather than loading an external
 * XML file, the example uses the top-level XML class to create an XML document,
 * then parses it.
 * <codeblock xml:space="preserve" class="+ topic/pre pr-d/codeblock ">
 * package {
 * import flash.display.Sprite;
 * import flash.xml.XMLDocument;
 * import flash.xml.XMLNode;
 * import flash.xml.XMLNodeType;
 *
 *   public class XMLDocumentExample extends Sprite {
 * public function XMLDocumentExample() {
 * var result:XMLDocument = new XMLDocument();
 * result.ignoreWhite = true;
 * result.parseXML(getXMLString());
 *
 *   var books:Array = parseBooks(result.firstChild);
 * trace("books: \n" + books);
 * }
 *
 *   private function parseBooks(node:XMLNode):Array {
 * var books:Array = new Array();
 *
 *   var kids:Array = node.childNodes;
 * for each(var item:XMLNode in kids) {
 * parseBook(item, books);
 * }
 *
 *   return books;
 * }
 *
 *   private function parseBook(node:XMLNode, books:Array):void {
 * var item:Book = new Book();
 * item.setPublisher(node.attributes.publisher);
 * item.setName(node.attributes.name);
 * books.push(item);
 * }
 *
 *   private function getXMLString():String {
 * var list:XML = &lt;books&gt;
 * &lt;book publisher="Addison-Wesley" name="Design Patterns" /&gt;
 * &lt;book publisher="Addison-Wesley" name="The Pragmatic Programmer" /&gt;
 * &lt;book publisher="Addison-Wesley" name="Test Driven Development" /&gt;
 * &lt;book publisher="Addison-Wesley" name="Refactoring to Patterns" /&gt;
 * &lt;book publisher="O'Reilly Media" name="The Cathedral &amp; the Bazaar" /&gt;
 * &lt;book publisher="O'Reilly Media" name="Unit Test Frameworks" /&gt;
 * &lt;/books&gt;;
 * return list.toXMLString();
 * }
 * }
 *
 *   }
 * class Book {
 * private var publisher:String;
 * private var name:String;
 *
 *   public function setPublisher(publisher:String):void {
 * this.publisher = publisher;
 * }
 *
 *   public function setName(name:String):void {
 * this.name = name;
 * }
 *
 *   public function toString():String {
 * return "[Book name: " + name + " publisher: " + publisher + "]\n";
 * }
 * }
 * </codeblock>
 * @langversion 3.0
 * @playerversion   Flash 9
 * @playerversion   Lite 4
 */
using namespace flash::xml;

namespace flash
{
    namespace xml
    {
        class XMLDocument: public XMLNode
        {
            /**
             * A string that specifies information about a document's XML declaration.
             * After the XML document is parsed into an XMLDocument object, this property is set
             * to the text of the document's XML declaration. This property is set using a string
             * representation of the XML declaration, not an XMLNode object. If no XML declaration
             * is encountered during a parse operation, the property is set to null.
             * The XMLDocument.toString() method outputs the contents of the
             * XML.xmlDecl property before any other text in the XML object.
             * If the XML.xmlDecl property contains null,
             * no XML declaration is output.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             * @maelexample The following example creates a text field called <code>my_txt</code>
             *   that has the same dimensions as the Stage. The text field displays properties of the XML packet that loads into the SWF file. The doc type declaration displays in <code>my_txt</code>. Add the following ActionScript to your FLA or AS file:
             *   <listing><code>var my_fmt:TextFormat = new TextFormat();</code><code>my_fmt.font = "_typewriter";</code><code>my_fmt.size = 12;</code><code>my_fmt.leftMargin = 10;</code><code>this.createTextField("my_txt", this.getNextHighestDepth(), 0, 0, Stage.width, Stage.height);</code><code>my_txt.border = true;</code><code>my_txt.multiline = true;</code><code>my_txt.wordWrap = true;</code><code>my_txt.setNewTextFormat(my_fmt);</code><code>var my_xml:XML = new XML();</code><code>my_xml.ignoreWhite = true;</code><code>my_xml.onLoad = function(success:Boolean) {</code><code>  var endTime:Number = getTimer();</code><code>  var elapsedTime:Number = endTime-startTime;</code><code>  if (success) {</code><code>    my_txt.text = "xmlDecl:"+newline+my_xml.xmlDecl+newline+newline;</code><code>    my_txt.text += "contentType:"+newline+my_xml.contentType+newline+newline;</code><code>    my_txt.text += "docTypeDecl:"+newline+my_xml.docTypeDecl+newline+newline;</code><code>    my_txt.text += "packet:"+newline+my_xml.toString()+newline+newline;</code><code>  } else {</code><code>    my_txt.text = "Unable to load remote XML."+newline+newline;</code><code>  }</code><code>  my_txt.text += "loaded in: "+elapsedTime+" ms.";</code><code>};</code><code>my_xml.load("http://www.helpexamples.com/crossdomain.xml");</code><code>var startTime:Number = getTimer();</code></listing>
             */
        public:
            Object *xmlDecl;

            /**
             * Specifies information about the XML document's DOCTYPE declaration.
             * After the XML text has been parsed into an XMLDocument object, the
             * XMLDocument.docTypeDecl property of the XMLDocument object is set to the
             * text of the XML document's DOCTYPE declaration
             * (for example, <!DOCTYPEgreeting SYSTEM "hello.dtd">).
             * This property is set using a string representation of the DOCTYPE declaration,
             * not an XMLNode object.
             * The legacy ActionScript XML parser is not a validating parser. The DOCTYPE
             * declaration is read by the parser and stored in the XMLDocument.docTypeDecl property,
             * but no DTD validation is performed.If no DOCTYPE declaration was encountered during a parse operation,
             * the XMLDocument.docTypeDecl property is set to null.
             * The XML.toString() method outputs the contents of XML.docTypeDecl
             * immediately after the XML declaration stored in XML.xmlDecl, and before any other
             * text in the XML object. If XMLDocument.docTypeDecl is null, no
             * DOCTYPE declaration is output.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             * @maelexample The following example uses the <code>XML.docTypeDecl</code> property to set the <code>DOCTYPE</code> declaration for an XML object:
             *   <listing><code><em>my_xml</em></code>.<code>docTypeDecl = "&lt;!DOCTYPE greeting SYSTEM \"hello.dtd\"&gt;";</code></listing>
             */
        public:
            Object *docTypeDecl;

            /**
             * An Object containing the nodes of the XML that have an id attribute assigned.
             * The names of the properties of the object (each containing a node) match the values of the
             * id attributes.
             *
             *   Consider the following XMLDocument object:
             * <codeblock>
             *
             *   <employee id='41'>
             * <name>
             * John Doe
             * </name>
             * <address>
             * 601 Townsend St.
             * </address>
             * </employee>
             *
             *   <employee id='42'>
             * <name>
             * Jane Q. Public
             * </name>
             * </employee>
             * <department id="IT">
             * Information Technology
             * </department>
             *
             *   </codeblock>
             * In this example, the idMap property for this XMLDocument object is an Object with
             * three properties: 41, 42, and IT. Each of these
             * properties is an XMLNode that has the matching id value. For example,
             * the IT property of the idMap object is this node:
             * <codeblock>
             *
             *   <department id="IT">
             * Information Technology
             * </department>
             *
             *   </codeblock>
             * You must use the parseXML() method on the XMLDocument object for the
             * idMap property to be instantiated.If there is more than one XMLNode with the same id value, the matching property
             * of the idNode object is that of the last node parsed. For example:
             * <codeblock>
             *
             *   var x1:XML = new XMLDocument("<a id='1'><b id='2' /><c id='1' /></a>");
             * x2 = new XMLDocument();
             * x2.parseXML(x1);
             * trace(x2.idMap['1']);
             *
             *   </codeblock>
             *
             *   This will output the <c> node:
             *
             *   <codeblock>
             * <c id='1' />
             * </codeblock>
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             * @maelexample Create a text file named "idMapTest.xml" containing the following text:
             *
             *     <listing>&lt;?xml version="1.0"?&gt;
             *   &lt;doc xml:base="http://example.org/today/" xmlns:xlink="http://www.w3.org/1999/xlink"&gt;
             *   &lt;head&gt;
             *   &lt;title&gt;Virtual Library&lt;/title&gt;
             *   &lt;/head&gt;
             *   &lt;body&gt;
             *   &lt;paragraph id="linkP1"&gt;See &lt;link xlink:type="simple" xlink:href="new.xml"&gt;what's
             *   new&lt;/link&gt;!&lt;/paragraph&gt;
             *   &lt;paragraph&gt;Check out the hot picks of the day!&lt;/paragraph&gt;
             *   &lt;olist xml:base="/hotpicks/"&gt;
             *   &lt;item&gt;
             *   &lt;link id="foo" xlink:type="simple" xlink:href="pick1.xml"&gt;Hot Pick #1&lt;/link&gt;
             *   &lt;/item&gt;
             *   &lt;item&gt;
             *   &lt;link id="bar" xlink:type="simple" xlink:href="pick2.xml"&gt;Hot Pick #2&lt;/link&gt;
             *   &lt;/item&gt;
             *   &lt;item&gt;
             *   &lt;link xlink:type="simple" xlink:href="pick3.xml"&gt;Hot Pick #3&lt;/link&gt;
             *   &lt;/item&gt;
             *   &lt;/olist&gt;
             *   &lt;/body&gt;
             *   &lt;/doc&gt;
             *   </listing><p class="- topic/p ">Then create a SWF file in the same directory as the XML file. Include the following
             *   script in the SWF:</p><listing>
             *   var readXML = new XMLDocument();
             *   readXML.load("idMapTest.xml");
             *   readXML.onLoad = function(success) {
             *   myXML = new XMLDocument();
             *   myXML.parseXML(readXML);
             *   for (var x in myXML.idMap){
             *   trace('idMap.' + x + " = " + newline + myXML.idMap[x]);
             *   trace('____________' + newline);
             *   }
             *   }
             *   </listing><p class="- topic/p ">When you test the SWF file, the following output is generated:</p><listing>
             *   idMap.bar =
             *   &lt;link id="bar" xlink:type="simple" xlink:href="pick2.xml"&gt;Hot Pick #2&lt;/link&gt;
             *   ____________
             *
             *     idMap.foo =
             *   &lt;link id="foo" xlink:type="simple" xlink:href="pick1.xml"&gt;Hot Pick #1&lt;/link&gt;
             *   ____________
             *
             *     idMap.linkP1 =
             *   &lt;paragraph id="linkP1"&gt;See &lt;link xlink:type="simple" xlink:href="new.xml"&gt;what's
             *
             *     new&lt;/link&gt;!&lt;/paragraph&gt;
             *   ____________
             *   </listing>
             */
        public:
            Object *idMap;

            /**
             * When set to true, text nodes that contain only white space are discarded during the parsing process. Text nodes with leading or trailing white space are unaffected. The default setting is false.
             * You can set the ignoreWhite property for individual XMLDocument objects, as the following code shows:
             * <codeblock>
             *
             *   my_xml.ignoreWhite = true;
             *
             *   </codeblock>
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             * @maelexample The following example loads an XML file with a text node that contains only white space; the <code>foyer</code> tag comprises fourteen space characters. To run this example, create a text file named <em>flooring.xml</em>, and copy the following tags into it:
             *   <listing>
             *   &lt;house&gt;
             *   &lt;kitchen&gt;   ceramic tile   &lt;/kitchen&gt;
             *   &lt;bathroom&gt;linoleum&lt;/bathroom&gt;
             *   &lt;foyer&gt;              &lt;/foyer&gt;
             *   &lt;/house&gt;
             *   </listing><p class="- topic/p ">Create a new Flash document named <em>flooring.fla</em> and save it to the same directory as the XML file. Place the following code into the main Timeline:</p><listing>
             *   // create a new XML object
             *   var flooring:XML = new XML();
             *
             *     // set the ignoreWhite property to true (default value is false)
             *   flooring.ignoreWhite = true;
             *
             *     // After loading is complete, trace the XML object
             *   flooring.onLoad = function(success:Boolean) {
             *   trace(flooring);
             *   }
             *
             *     // load the XML into the flooring object
             *   flooring.load("flooring.xml");
             *
             *     // output (line breaks added for clarity):
             *   &lt;house&gt;
             *   &lt;kitchen&gt;   ceramic tile   &lt;/kitchen&gt;
             *   &lt;bathroom&gt;linoleum&lt;/bathroom&gt;
             *   &lt;foyer /&gt;
             *   &lt;/house&gt;
             *
             *     </listing><p class="- topic/p ">If you then change the setting of <code>flooring.ignoreWhite</code> to <code>false</code>, or simply remove that line of code entirely, the fourteen space characters in the <code>foyer</code> tag will be preserved:</p><listing>
             *   ...
             *   // set the ignoreWhite property to false (default value)
             *   flooring.ignoreWhite = false;
             *   ...
             *   // output (line breaks added for clarity):
             *   &lt;house&gt;
             *   &lt;kitchen&gt;   ceramic tile   &lt;/kitchen&gt;
             *   &lt;bathroom&gt;linoleum&lt;/bathroom&gt;
             *   &lt;foyer&gt;              &lt;/foyer&gt;
             *   &lt;/house&gt;
             *
             *     </listing><span class="flashonly"><p class="- topic/p ">The XML_blogTracker.fla and XML_languagePicker.fla files in the ActionScript samples folder also contain a code example. The following are typical paths to this folder:</p><ul class="- topic/ul "><li class="- topic/li ">Windows: <i class="+ topic/ph hi-d/i ">boot drive</i>\Program Files\Macromedia\Flash 8\Samples and Tutorials\Samples\ActionScript </li><li class="- topic/li ">Macintosh: <i class="+ topic/ph hi-d/i ">Macintosh HD</i>/Applications/Macromedia Flash 8/Samples and Tutorials/Samples/ActionScript </li><li class="- topic/li " /></ul></span>
             */
        public:
            bool ignoreWhite;

            /**
             * Creates a new XMLNode object with the name specified in the parameter.
             * The new node initially has no parent, no children, and no siblings.
             * The method returns a reference to the newly created XMLNode object
             * that represents the element. This method and the XMLDocument.createTextNode()
             * method are the constructor methods for creating nodes for an XMLDocument object.
             * @param   name    The tag name of the XMLDocument element being created.
             * @return  An XMLNode object.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             * @maelexample The following example creates three XML nodes using the <code>createElement()</code> method:
             *   <listing>
             *   // create an XML document
             *   var doc:XML = new XML();
             *
             *     // create three XML nodes using createElement()
             *   var element1:XMLNode = doc.createElement("element1");
             *   var element2:XMLNode = doc.createElement("element2");
             *   var element3:XMLNode = doc.createElement("element3");
             *
             *     // place the new nodes into the XML tree
             *   doc.appendChild(element1);
             *   element1.appendChild(element2);
             *   element1.appendChild(element3);
             *
             *     trace(doc);
             *   // output: &lt;element1&gt;&lt;element2 /&gt;&lt;element3 /&gt;&lt;/element1&gt;
             *   </listing>
             */
        public:
            flash::xml::XMLNode *createElement(std::string name);

            /**
             * Creates a new XML text node with the specified text. The new node initially has no parent, and text nodes cannot have children or siblings. This method returns a reference to the XMLDocument object that represents the new text node. This method and the XMLDocument.createElement() method are the constructor methods for creating nodes for an XMLDocument object.
             * @param   text    The text used to create the new text node.
             * @return  An XMLNode object.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             * @maelexample The following example creates two XML text nodes using the <code>createTextNode()</code> method, and places them into existing XML nodes:
             *   <listing>
             *   // create an XML document
             *   var doc:XML = new XML();
             *
             *     // create three XML nodes using createElement()
             *   var element1:XMLNode = doc.createElement("element1");
             *   var element2:XMLNode = doc.createElement("element2");
             *   var element3:XMLNode = doc.createElement("element3");
             *
             *     // place the new nodes into the XML tree
             *   doc.appendChild(element1);
             *   element1.appendChild(element2);
             *   element1.appendChild(element3);
             *
             *     // create two XML text nodes using createTextNode()
             *   var textNode1:XMLNode = doc.createTextNode("textNode1 String value");
             *   var textNode2:XMLNode = doc.createTextNode("textNode2 String value");
             *
             *     // place the new nodes into the XML tree
             *   element2.appendChild(textNode1);
             *   element3.appendChild(textNode2);
             *
             *     trace(doc);
             *   // output (with line breaks added between tags):
             *   // &lt;element1&gt;
             *   //    &lt;element2&gt;textNode1 String value&lt;/element2&gt;
             *   //    &lt;element3&gt;textNode2 String value&lt;/element3&gt;
             *   // &lt;/element1&gt;
             *   </listing>
             */
        public:
            flash::xml::XMLNode *createTextNode(std::string text);

            /**
             * Returns a string representation of the XML object.
             * @return  A string representation of the XML object.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            std::string toString();

            /**
             * Parses the XML text specified in the value parameter
             * and populates the specified XMLDocument object with the resulting XML tree. Any existing trees in the XMLDocument object are discarded.
             * @param   source  The XML text to be parsed and passed to the specified XMLDocument object.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             * @maelexample The following example creates and parses an XML packet:
             *   <listing>
             *   var xml_str:String = "&lt;state name=\"California\"&gt;
             *   &lt;city&gt;San Francisco&lt;/city&gt;&lt;/state&gt;"
             *
             *     // defining the XML source within the XML constructor:
             *   var my1_xml:XML = new XML(xml_str);
             *   trace(my1_xml.firstChild.attributes.name); // output: California
             *
             *     // defining the XML source using the XML.parseXML method:
             *   var my2_xml:XML = new XML();
             *   my2_xml.parseXML(xml_str);
             *   trace(my2_xml.firstChild.attributes.name); // output: California
             *   </listing>
             */
        public:
            void     parseXML(std::string source);

            /**
             * Creates a new XMLDocument object. You must use the constructor to create an XMLDocument object before you call any of the methods of the XMLDocument class.
             * Note: Use the createElement() and createTextNode() methods to add elements and text nodes to an XML document tree.
             * @param   source  The XML text parsed to create the new XMLDocument object.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             * @maelexample The following example creates a new, empty XMLDocument object:
             *   <listing>
             *   var my_xml:XML = new XML();
             *   </listing><p class="- topic/p ">The following example creates an XML object by parsing the XML text specified in the <code>source</code> parameter, and populates the newly created XML object with the resulting XML document tree:</p><listing>
             *   var other_xml:XML = new XML("&lt;state name=\"California\"&gt;&lt;city&gt;San Francisco&lt;/city&gt;&lt;/state&gt;");
             *   </listing>
             */
        public:
            XMLDocument(std::string source);
        };
    }
}

#endif // FLEX11_6_FLASH_XML_XMLDOCUMENT_AS
#endif // __cplusplus

