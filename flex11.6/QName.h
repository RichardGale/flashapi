#if !defined(FLEX11_6_QNAME_AS)
#define FLEX11_6_QNAME_AS
#if defined(__cplusplus)


/**
 * QName objects represent qualified names of XML elements and attributes. Each
 * QName object has a local name and a namespace Uniform Resource Identifier (URI).
 * When the value of the namespace URI is <codeph class="+ topic/ph pr-d/codeph ">null</codeph>, the QName object matches any namespace.
 * Use the QName constructor to create a new QName object that is either a copy of another QName
 * object or a new QName object with a <codeph class="+ topic/ph pr-d/codeph ">uri</codeph> from a Namespace object and a
 * <codeph class="+ topic/ph pr-d/codeph ">localName</codeph> from a QName object.
 *
 *   <p class="- topic/p ">Methods specific to E4X can use QName objects interchangeably with strings.
 * E4X methods are in the QName, Namespace, XML, and XMLList classes.
 * These E4X methods, which take a string, can also take a QName object.
 * This interchangeability is how namespace support works with, for example,
 * the <codeph class="+ topic/ph pr-d/codeph ">XML.child()</codeph> method. </p><p class="- topic/p ">The QName class (along with the XML, XMLList, and Namespace classes) implements
 * powerful XML-handling standards defined in ECMAScript for XML
 * (E4X) specification (ECMA-357 edition 2).</p><p class="- topic/p ">A qualified identifier evaluates to a QName object. If the QName object of an XML element is
 * specified without identifying a namespace, the <codeph class="+ topic/ph pr-d/codeph ">uri</codeph>
 * property of the associated QName object is set to the global default namespace. If the QName object of an XML
 * attribute is specified without identifying a namespace, the <codeph class="+ topic/ph pr-d/codeph ">uri</codeph> property is set to
 * an empty string.</p>
 *
 *   EXAMPLE:
 *
 *   The following example shows how to create a QName instance and use it to select XML elements.
 * Two ways of creating a QName are shown:
 * <ol class="- topic/ol "><li class="- topic/li ">Creating a Namespace instance and then using it as input to the QName constructor.
 * This approach is best if you want to use the <codeph class="+ topic/ph pr-d/codeph ">Namespace.prefix</codeph> property for other
 * purposes later.</li><li class="- topic/li ">Creating a QName instance using a simple string value for the <codeph class="+ topic/ph pr-d/codeph ">uri</codeph>
 * parameter in the QName constructor.</li></ol><p class="- topic/p ">
 * This code does the following things:
 * </p><ol class="- topic/ol "><li class="- topic/li ">Defines an XML variable named <codeph class="+ topic/ph pr-d/codeph ">rssXML</codeph>.</li><li class="- topic/li ">Creates a new Namespace object with the prefix <codeph class="+ topic/ph pr-d/codeph ">dc</codeph>.</li><li class="- topic/li ">Creates a new QName object using the Namespace object and the local name <codeph class="+ topic/ph pr-d/codeph ">creator</codeph>.</li><li class="- topic/li ">Calls the <codeph class="+ topic/ph pr-d/codeph ">showDescendants()</codeph> method, which uses the <codeph class="+ topic/ph pr-d/codeph ">XML.descendants()</codeph> method to get an XMLList instance
 * containing all the descendant elements whose qualified name matches the given QName instance.</li><li class="- topic/li ">Displays the qualified name and the text value of each element in the list using a <codeph class="+ topic/ph pr-d/codeph ">for each</codeph> loop.</li><li class="- topic/li ">Creates another QName object using a string value for the <codeph class="+ topic/ph pr-d/codeph ">uri</codeph> parameter and the local name <codeph class="+ topic/ph pr-d/codeph ">date</codeph>.</li><li class="- topic/li ">Calls the <codeph class="+ topic/ph pr-d/codeph ">showDescendants()</codeph> method again to display the name and text value of the descendant elements.</li></ol><codeblock xml:space="preserve" class="+ topic/pre pr-d/codeblock ">
 * package
 * {
 * import flash.display.Sprite;
 *
 *   public class QNameExample extends Sprite
 * {
 * public function QNameExample()
 * {
 * var rssXML:XML =  &lt;rdf:RDF
 * xmlns:rdf="http://www.w3.org/1999/02/22-rdf-syntax-ns#"
 * xmlns="http://purl.org/rss/1.0/"
 * xmlns:dc="http://purl.org/dc/elements/1.1/"&gt;
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
 * &lt;title&gt;Flash Developer Center&lt;/title&gt;
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
 *   var dcNamespace:Namespace = new Namespace("dc", "http://purl.org/dc/elements/1.1/");
 * var creatorQName:QName = new QName(dcNamespace, "creator");
 * trace(creatorQName.uri); // http://purl.org/dc/elements/1.1/
 * trace(creatorQName.localName); // creator
 *
 *   showDescendants(rssXML, creatorQName);
 *
 *   var dateQName:QName = new QName("http://purl.org/dc/elements/1.1/", "date");
 * trace(dateQName.uri); // http://purl.org/dc/elements/1.1/
 * trace(dateQName.localName); // date
 *
 *   showDescendants(rssXML, dateQName);
 * }
 *
 *   public function showDescendants(xmlData:XML, qualifiedName:QName):void
 * {
 * var decendantList:XMLList = xmlData.descendants(qualifiedName);
 *
 *   for each (var element:XML in decendantList)
 * {
 * trace(element.name()); // the fully qualified name,
 * // like "http://purl.org/dc/elements/1.1/::creator"
 * trace(element); // the simple text value of each element, like "Adobe"
 * }
 * }
 * }
 * }
 * </codeblock>
 * @langversion 3.0
 * @playerversion   Flash 9
 * @playerversion   Lite 4
 */

#include "flex11.6.h"



class QName : public Object
{
public:
    static const void *length;

    /**
     * The local name of the QName object.
     * @langversion 3.0
     * @playerversion   Flash 9
     */
public:
    std::string       localName();

    /**
     * The Uniform Resource Identifier (URI) of the QName object.
     * @langversion 3.0
     * @playerversion   Flash 9
     */
public:
    std::string       uri();

public:
    QName(void *namespace=NULL, void *name=NULL);

    /**
     * Returns the QName object.
     * @return  The primitive value of a QName instance.
     * @langversion 3.0
     * @playerversion   Flash 9
     */
    QName    *valueOf();

    /**
     * Returns a string composed of the URI, and the local name for the
     * QName object, separated by "::".
     *
     *   The format depends on the uri property of the QName object:If uri == ""
     * toString returns localName
     * else if uri == null
     * toString returns ~~::localName
     * else
     * toString returns uri::localName
     * @return  The qualified name, as a string.
     * @langversion 3.0
     * @playerversion   Flash 9
     */
    std::string   toString();
};

#endif // FLEX11_6_QNAME_AS
#endif // __cplusplus

