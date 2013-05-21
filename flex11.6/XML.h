#if !defined(FLEX11_6_XML_AS)
#define FLEX11_6_XML_AS
#if defined(__cplusplus)


/**
 * The XML class contains methods and properties for working with XML objects. The XML class
 * (along with the XMLList, Namespace, and QName classes) implements the
 * powerful XML-handling standards defined in ECMAScript for XML
 * (E4X) specification (ECMA-357 edition 2).
 *
 *   <p class="- topic/p ">Use the <codeph class="+ topic/ph pr-d/codeph ">toXMLString()</codeph> method to return a string representation of the XML object
 * regardless of whether the XML object has simple content or complex content.</p><p class="- topic/p "><b class="+ topic/ph hi-d/b ">Note</b>: The XML class (along with related classes) from ActionScript 2.0 has been
 * renamed XMLDocument and moved into the flash.xml package.
 * It is included in ActionScript 3.0 for backward compatibility.</p>
 *
 *   EXAMPLE:
 *
 *   The following example first creates an XML variable and adds nodes to it.
 * Then XML properties are used to find and print XML nodes.  Notice that the "at"
 * (<codeph class="+ topic/ph pr-d/codeph ">@</codeph>) symbol is used in several of the <codeph class="+ topic/ph pr-d/codeph ">trace()</codeph> calls to locate information
 * by attribute name.
 * <codeblock xml:space="preserve" class="+ topic/pre pr-d/codeblock ">
 * package {
 * import flash.display.Sprite;
 *
 *   public class XmlExample extends Sprite {
 * public function XmlExample() {
 * var employees:XML =
 * &lt;employees&gt;
 * &lt;employee ssn="123-123-1234"&gt;
 * &lt;name first="John" last="Doe"/&gt;
 * &lt;address&gt;
 * &lt;street&gt;11 Main St.&lt;/street&gt;
 * &lt;city&gt;San Francisco&lt;/city&gt;
 * &lt;state&gt;CA&lt;/state&gt;
 * &lt;zip&gt;98765&lt;/zip&gt;
 * &lt;/address&gt;
 * &lt;/employee&gt;
 * &lt;employee ssn="789-789-7890"&gt;
 * &lt;name first="Mary" last="Roe"/&gt;
 * &lt;address&gt;
 * &lt;street&gt;99 Broad St.&lt;/street&gt;
 * &lt;city&gt;Newton&lt;/city&gt;
 * &lt;state&gt;MA&lt;/state&gt;
 * &lt;zip&gt;01234&lt;/zip&gt;
 * &lt;/address&gt;
 * &lt;/employee&gt;
 * &lt;/employees&gt;;
 *
 *   trace(employees.employee[0].address.zip);   // 98765
 *
 *   trace(employees.employee[1].@ssn);          // 789-789-7890
 *
 *     trace(employees.employee.name);             // &lt;name first="John" last="Doe"/&gt;
 *   // &lt;name first="Mary" last="Roe"/&gt;
 *
 *     trace(employees..zip[0]);                   // 98765
 *
 *     trace(employees..@ssn[1]);                  // 789-789-7890
 *
 *     trace(employees..name);                     // &lt;name first="John" last="Doe"/&gt;
 *   // &lt;name first="Mary" last="Roe"/&gt;
 *
 *     trace(employees.employee[0].address.*);     // &lt;street&gt;11 Main St.&lt;/street&gt;
 *   // &lt;city&gt;San Francisco&lt;/city&gt;
 *   // &lt;state&gt;CA&lt;/state&gt;
 *   // &lt;zip&gt;98765&lt;/zip&gt;
 *   var node:String = "zip";
 *   trace(employees.employee[0].address[node]); // 98765
 *
 *     var attribute:String = "ssn";
 *   trace(employees.employee[1].@[attribute]);  // 789-789-7890
 *
 *     for each (var num:XML in employees..@ssn) {
 *   trace(num);                             // 123-123-1234
 *   }                                           // 789-789-7890
 *
 *     var ssnToFind:String = "789-789-7890";
 *   trace(employees.employee.(@ssn == ssnToFind).toXMLString());
 *   // &lt;employee ssn="789-789-7890"&gt;
 *   // &lt;name first="Mary" last="Roe"/&gt;
 *   // &lt;address&gt;
 *   // &lt;street&gt;99 Broad St.&lt;/street&gt;
 *   // &lt;city&gt;Newton&lt;/city&gt;
 *   // &lt;state&gt;MA&lt;/state&gt;
 *   // &lt;zip&gt;01234&lt;/zip&gt;
 *   // &lt;/address&gt;
 *   // &lt;/employee&gt;
 *   }
 *   }
 *   }
 *   </codeblock>
 * @langversion 3.0
 * @playerversion   Flash 9
 * @playerversion   Lite 4
 */


class XML : public Object
{
public:
    static const void *length;

    /**
     * Determines whether XML comments are ignored
     * when XML objects parse the source XML data. By default, the comments are ignored
     * (true). To include XML comments, set this property to false.
     * The ignoreComments property is used only during the XML parsing, not during
     * the call to any method such as myXMLObject.child(~~).toXMLString().
     * If the source XML includes comment nodes, they are kept or discarded during the XML parsing.
     * @langversion 3.0
     * @playerversion   Flash 9
     */
public:
    static bool         ignoreComments();
public:
    static void         ignoreComments(bool newIgnore);

    /**
     * Determines whether XML
     * processing instructions are ignored when XML objects parse the source XML data.
     * By default, the processing instructions are ignored (true). To include XML
     * processing instructions, set this property to false. The
     * ignoreProcessingInstructions property is used only during the XML parsing,
     * not during the call to any method such as myXMLObject.child(~~).toXMLString().
     * If the source XML includes processing instructions nodes, they are kept or discarded during
     * the XML parsing.
     * @langversion 3.0
     * @playerversion   Flash 9
     */
public:
    static bool         ignoreProcessingInstructions();
public:
    static void         ignoreProcessingInstructions(bool newIgnore);

    /**
     * Determines whether white space characters
     * at the beginning and end of text nodes are ignored during parsing. By default,
     * white space is ignored (true). If a text node is 100% white space and the
     * ignoreWhitespace property is set to true, then the node is not created.
     * To show white space in a text node, set the ignoreWhitespace property to
     * false.
     *
     *   When you create an XML object, it caches the current value of the ignoreWhitespace
     * property. Changing the ignoreWhitespace does not change the behavior of existing XML
     * objects.
     * @langversion 3.0
     * @playerversion   Flash 9
     */
public:
    static bool         ignoreWhitespace();
public:
    static void         ignoreWhitespace(bool newIgnore);

    /**
     * Determines whether the toString()
     * and toXMLString() methods normalize white space characters between some tags.
     * The default value is true.
     * @langversion 3.0
     * @playerversion   Flash 9
     */
public:
    static bool         prettyPrinting();
public:
    static void         prettyPrinting(bool newPretty);

    /**
     * Determines the amount of indentation applied by
     * the toString() and toXMLString() methods when
     * the XML.prettyPrinting property is set to true.
     * Indentation is applied with the space character, not the tab character.
     *
     *   The default value is 2.
     * @langversion 3.0
     * @playerversion   Flash 9
     */
public:
    static int          prettyIndent();
public:
    static void         prettyIndent(int newIndent);

    /**
     * Retrieves the following properties: ignoreComments,
     * ignoreProcessingInstructions, ignoreWhitespace,
     * prettyIndent, and prettyPrinting.
     * @return  An object with the following XML properties:
     *   ignoreCommentsignoreProcessingInstructionsignoreWhitespaceprettyIndentprettyPrinting
     * @langversion 3.0
     * @playerversion   Flash 9
     */
    static Object  *settings();

    /**
     * Sets values for the following XML properties: ignoreComments,
     * ignoreProcessingInstructions, ignoreWhitespace,
     * prettyIndent, and prettyPrinting.
     *
     *   The following are the default settings, which are applied if no setObj parameter
     * is provided:
     *
     *   XML.ignoreComments = trueXML.ignoreProcessingInstructions = trueXML.ignoreWhitespace = trueXML.prettyIndent = 2XML.prettyPrinting = trueNote: You do not apply this method to an instance of the XML class; you apply it to
     * XML, as in the following code: XML.setSettings().
     * @param   rest    An object with each of the following properties:
     *
     *     ignoreCommentsignoreProcessingInstructionsignoreWhitespaceprettyIndentprettyPrinting
     * @langversion 3.0
     * @playerversion   Flash 9
     */
    static void     setSettings(Object *o=NULL);

    /**
     * Returns an object with the following properties set to the default values: ignoreComments,
     * ignoreProcessingInstructions, ignoreWhitespace, prettyIndent, and
     * prettyPrinting. The default values are as follows:
     *
     *   ignoreComments = trueignoreProcessingInstructions = trueignoreWhitespace = trueprettyIndent = 2prettyPrinting = trueNote: You do not apply this method to an instance of the XML class; you apply it to
     * XML, as in the following code: var df:Object = XML.defaultSettings().
     * @return  An object with properties set to the default settings.
     * @langversion 3.0
     * @playerversion   Flash 9
     */
    static Object  *defaultSettings();

    /**
     * Returns a string representation of the XML object. The rules for this conversion depend on whether
     * the XML object has simple content or complex content:
     *
     *   If the XML object has simple content, toString() returns the String contents of the
     * XML object with  the following stripped out: the start tag, attributes, namespace declarations, and
     * end tag. If the XML object has complex content, toString() returns an XML encoded String
     * representing the entire XML object, including the start tag, attributes, namespace declarations,
     * and end tag.To return the entire XML object every time, use toXMLString().
     * @return  The string representation of the XML object.
     * @langversion 3.0
     * @playerversion   Flash 9
     */
    std::string toString();

    /**
     * Checks to see whether the object has the property specified by the p parameter.
     * @param   p   The property to match.
     * @return  If the property exists, true; otherwise false.
     * @langversion 3.0
     * @playerversion   Flash 9
     */
    bool     hasOwnProperty(void *P=NULL);

    /**
     * Checks whether the property p is in the set of properties that can be iterated in a
     * for..in statement applied to the XML object. Returns true only
     * if toString(p) == "0".
     * @param   p   The property that you want to check.
     * @return  If the property can be iterated in a for..in statement, true;
     *   otherwise, false.
     * @langversion 3.0
     * @playerversion   Flash 9
     */
    bool     propertyIsEnumerable(void *P=NULL);

    /**
     * Adds a namespace to the set of in-scope namespaces for the XML object. If the namespace already
     * exists in the in-scope namespaces for the XML object (with a prefix matching that of the given
     * parameter), then the prefix of the existing namespace is set to undefined. If the input parameter
     * is a Namespace object, it's used directly. If it's a QName object, the input parameter's
     * URI is used to create a new namespace; otherwise, it's converted to a String and a namespace is created from
     * the String.
     * @param   ns  The namespace to add to the XML object.
     * @return  The new XML object, with the namespace added.
     * @langversion 3.0
     * @playerversion   Flash 9
     */
    XML     *addNamespace(void *ns);

    /**
     * Appends the given child to the end of the XML object's properties.
     * The appendChild() method takes an XML object, an XMLList object, or
     * any other data type that is then converted to a String.
     *
     *   Use the delete (XML) operator to remove XML nodes.
     * @param   child   The XML object to append.
     * @return  The resulting XML object.
     * @langversion 3.0
     * @playerversion   Flash 9
     */
    XML     *appendChild(void *child);

    /**
     * Returns the XML value of the attribute that has the name matching the attributeName
     * parameter. Attributes are found within XML elements.
     * In the following example, the element has an attribute named "gender"
     * with the value "boy": <first gender="boy">John</first>.
     *
     *   The attributeName parameter can be any data type; however,
     * String is the most common data type to use. When passing any object other than a QName object,
     * the attributeName parameter uses the toString() method
     * to convert the parameter to a string. If you need a qualified name reference, you can pass in a QName object. A QName object
     * defines a namespace and the local name, which you can use to define the qualified name of an
     * attribute. Therefore calling attribute(qname) is not the same as calling
     * attribute(qname.toString()).
     * @param   attributeName   The name of the attribute.
     * @return  An XMLList object or an empty XMLList object. Returns an empty XMLList object
     *   when an attribute value has not been defined.
     * @langversion 3.0
     * @playerversion   Flash 9
     */
    XMLList *attribute(void *arg);

    /**
     * Returns a list of attribute values for the given XML object. Use the name()
     * method with the attributes() method to return the name of an attribute.
     * Use of xml.attributes() is equivalent to xml.@*.
     * @return  The list of attribute values.
     * @langversion 3.0
     * @playerversion   Flash 9
     */
    XMLList *attributes();

    /**
     * Lists the children of an XML object. An XML child is an XML element, text node, comment,
     * or processing instruction.
     *
     *   Use the propertyName parameter to list the
     * contents of a specific XML child. For example, to return the contents of a child named
     * <first>, use child.name("first"). You can generate the same result
     * by using the child's index number. The index number identifies the child's position in the
     * list of other XML children. For example, name.child(0) returns the first child
     * in a list. Use an asterisk (~~) to output all the children in an XML document.
     * For example, doc.child("~~").Use the length() method with the asterisk (~~) parameter of the
     * child() method to output the total number of children. For example,
     * numChildren = doc.child("~~").length().
     * @param   propertyName    The element name or integer of the XML child.
     * @return  An XMLList object of child nodes that match the input parameter.
     * @langversion 3.0
     * @playerversion   Flash 9
     */
    XMLList *child(void *propertyName);

    /**
     * Identifies the zero-indexed position of this XML object within the context of its parent.
     * @return  The position of the object. Returns -1 as well as positive integers.
     * @langversion 3.0
     * @playerversion   Flash 9
     */
    int      childIndex();

    /**
     * Lists the children of the XML object in the sequence in which they appear. An XML child
     * is an XML element, text node, comment, or processing instruction.
     * @return  An XMLList object of the XML object's children.
     * @langversion 3.0
     * @playerversion   Flash 9
     */
    XMLList *children();

    /**
     * Lists the properties of the XML object that contain XML comments.
     * @return  An XMLList object of the properties that contain comments.
     * @langversion 3.0
     * @playerversion   Flash 9
     */
    XMLList *comments();

    /**
     * Compares the XML object against the given value parameter.
     * @param   value   A value to compare against the current XML object.
     * @return  If the XML object matches the value parameter, then true; otherwise false.
     * @langversion 3.0
     * @playerversion   Flash 9
     */
    bool     contains(void *value);

    /**
     * Returns a copy of the given XML object. The copy is a duplicate of the entire tree of nodes.
     * The copied XML object has no parent and returns null if you attempt to call the
     * parent() method.
     * @return  The copy of the object.
     * @langversion 3.0
     * @playerversion   Flash 9
     */
    XML     *copy();

    /**
     * Returns all descendants (children, grandchildren, great-grandchildren, and so on) of the
     * XML object that have the given name parameter. The name parameter
     * is optional. The name parameter can be a QName object, a String data type
     * or any other data type that is then converted to a String data type.
     *
     *   To return all descendants, use the "~~" parameter. If no parameter is passed,
     * the string "~~" is passed and returns all descendants of the XML object.
     * @param   name    The name of the element to match.
     * @return  An XMLList object of matching descendants. If there are no descendants, returns an
     *   empty XMLList object.
     * @langversion 3.0
     * @playerversion   Flash 9
     */
    XMLList *descendants(void *name=(void *)"*");

    /**
     * Lists the elements of an XML object. An element consists of a start and an end tag;
     * for example <first></first>. The name parameter
     * is optional. The name parameter can be a QName object, a String data type,
     * or any other data type that is then converted to a String data type. Use the name parameter to list a specific element. For example,
     * the element "first" returns "John" in this example:
     * <first>John</first>.
     *
     *   To list all elements, use the asterisk (~~) as the
     * parameter. The asterisk is also the default parameter. Use the length() method with the asterisk parameter to output the total
     * number of elements. For example, numElement = addressbook.elements("~~").length().
     * @param   name    The name of the element. An element's name is surrounded by angle brackets.
     *   For example, "first" is the name in this example:
     *   <first></first>.
     * @return  An XMLList object of the element's content. The element's content falls between the start and
     *   end tags. If you use the asterisk (~~) to call all elements, both the
     *   element's tags and content are returned.
     * @langversion 3.0
     * @playerversion   Flash 9
     */
    XMLList *elements(void *name=(void *)"*");

    /**
     * Checks to see whether the XML object contains complex content. An XML object contains complex content if
     * it has child elements. XML objects that representing attributes, comments, processing instructions,
     * and text nodes do not have complex content. However, an object that contains these can
     * still be considered to contain complex content (if the object has child elements).
     * @return  If the XML object contains complex content, true; otherwise false.
     * @langversion 3.0
     * @playerversion   Flash 9
     */
    bool     hasComplexContent();

    /**
     * Checks to see whether the XML object contains simple content. An XML object contains simple content
     * if it represents a text node, an attribute node, or an XML element that has no child elements.
     * XML objects that represent comments and processing instructions do not contain simple
     * content.
     * @return  If the XML object contains simple content, true; otherwise false.
     * @langversion 3.0
     * @playerversion   Flash 9
     */
    bool     hasSimpleContent();

    /**
     * Lists the namespaces for the XML object, based on the object's parent.
     * @return  An array of Namespace objects.
     * @langversion 3.0
     * @playerversion   Flash 9
     */
    std::vector<void *> inScopeNamespaces();

    /**
     * Inserts the given child2 parameter after the child1 parameter in this XML object and returns the
     * resulting object. If the child1 parameter is null, the method
     * inserts the contents of child2before all children of the XML object
     * (in other words, after none). If child1 is provided, but it does not
     * exist in the XML object, the XML object is not modified and undefined is
     * returned.
     *
     *   If you call this method on an XML child that is not an element (text, attributes, comments, pi, and so on)
     * undefined is returned.Use the delete (XML) operator to remove XML nodes.
     * @param   child1  The object in the source object that you insert before child2.
     * @param   child2  The object to insert.
     * @return  The resulting XML object or undefined.
     * @langversion 3.0
     * @playerversion   Flash 9
     */
    void    *insertChildAfter(void *child1, void *child2);

    /**
     * Inserts the given child2 parameter before the child1 parameter
     * in this XML object and returns the resulting object. If the child1 parameter
     * is null, the method inserts the contents of
     * child2after all children of the XML object (in other words, before
     * none). If child1 is provided, but it does not exist in the XML object,
     * the XML object is not modified and undefined is returned.
     *
     *   If you call this method on an XML child that is not an element (text, attributes,
     * comments, pi, and so on) undefined is returned.Use the delete (XML) operator to remove XML nodes.
     * @param   child1  The object in the source object that you insert after child2.
     * @param   child2  The object to insert.
     * @return  The resulting XML object or undefined.
     * @langversion 3.0
     * @playerversion   Flash 9
     */
    void    *insertChildBefore(void *child1, void *child2);

    /**
     * For XML objects, this method always returns the integer 1.
     * The length() method of the XMLList class returns a value of 1 for
     * an XMLList object that contains only one value.
     * @return  Always returns 1 for any XML object.
     * @langversion 3.0
     * @playerversion   Flash 9
     */
    int      length();

    /**
     * Gives the local name portion of the qualified name of the XML object.
     * @return  The local name as either a String or null.
     * @langversion 3.0
     * @playerversion   Flash 9
     */
    Object  *localName();

    /**
     * Gives the qualified name for the XML object.
     * @return  The qualified name is either a QName or null.
     * @langversion 3.0
     * @playerversion   Flash 9
     */
    Object  *name();

    /**
     * If no parameter is provided, gives the namespace associated with the qualified name of
     * this XML object. If a prefix parameter is specified, the method returns the namespace
     * that matches the prefix parameter and that is in scope for the XML object. If there is no
     * such namespace, the method returns undefined.
     * @param   prefix  The prefix you want to match.
     * @return  Returns null, undefined, or a namespace.
     * @langversion 3.0
     * @playerversion   Flash 9
     */
    void    *namespace(void *prefix=NULL);

    /**
     * Lists namespace declarations associated with the XML object in the context of its parent.
     * @return  An array of Namespace objects.
     * @langversion 3.0
     * @playerversion   Flash 9
     */
    std::vector<void *> namespaceDeclarations();

    /**
     * Specifies the type of node: text, comment, processing-instruction,
     * attribute, or element.
     * @return  The node type used.
     * @langversion 3.0
     * @playerversion   Flash 9
     */
    std::string nodeKind();

    /**
     * For the XML object and all descendant XML objects, merges adjacent text nodes and
     * eliminates empty text nodes.
     * @return  The resulting normalized XML object.
     * @langversion 3.0
     * @playerversion   Flash 9
     */
    XML     *normalize();

    /**
     * Returns the parent of the XML object. If the XML object has no parent, the method returns
     * undefined.
     * @return  Either an XML reference of the parent node, or undefined
     *   if the XML object has no parent.
     * @langversion 3.0
     * @playerversion   Flash 9
     */
    void    *parent();

    /**
     * If a name parameter is provided, lists all the children of the XML object
     * that contain processing instructions with that name. With no parameters, the method
     * lists all the children of the XML object that contain any processing instructions.
     * @param   name    The name of the processing instructions to match.
     * @return  A list of matching child objects.
     * @langversion 3.0
     * @playerversion   Flash 9
     */
    XMLList *processingInstructions(void *name=(void *)"*");

    /**
     * Inserts a copy of the provided child object into the XML element before any existing XML
     * properties for that element.
     *
     *   Use the delete (XML) operator to remove XML nodes.
     * @param   value   The object to insert.
     * @return  The resulting XML object.
     * @langversion 3.0
     * @playerversion   Flash 9
     */
    XML     *prependChild(void *value);

    /**
     * Removes the given namespace for this object and all descendants. The removeNamespaces()
     * method does not remove a namespace if it is referenced by the object's qualified name or the
     * qualified name of the object's attributes.
     * @param   ns  The namespace to remove.
     * @return  A copy of the resulting XML object.
     * @langversion 3.0
     * @playerversion   Flash 9
     */
    XML     *removeNamespace(void *ns);

    /**
     * Replaces the properties specified by the propertyName parameter
     * with the given value parameter.
     * If no properties match propertyName, the XML object is left unmodified.
     * @param   propertyName    Can be a
     *   numeric value, an unqualified name for a set of XML elements, a qualified name for a set of
     *   XML elements, or the asterisk wildcard ("*").
     *   Use an unqualified name to identify XML elements in the default namespace.
     * @param   value   The replacement value. This can be an XML object, an XMLList object, or any value
     *   that can be converted with toString().
     * @return  The resulting XML object, with the matching properties replaced.
     * @langversion 3.0
     * @playerversion   Flash 9
     */
    XML     *replace(void *propertyName, void *value);

    /**
     * Replaces the child properties of the XML object with the specified set of XML properties,
     * provided in the value parameter.
     * @param   value   The replacement XML properties. Can be a single XML object or an XMLList object.
     * @return  The resulting XML object.
     * @langversion 3.0
     * @playerversion   Flash 9
     */
    XML     *setChildren(void *value);

    /**
     * Changes the local name of the XML object to the given name parameter.
     * @param   name    The replacement name for the local name.
     * @langversion 3.0
     * @playerversion   Flash 9
     */
    void     setLocalName(void *name);

    /**
     * Sets the name of the XML object to the given qualified name or attribute name.
     * @param   name    The new name for the object.
     * @langversion 3.0
     * @playerversion   Flash 9
     */
    void     setName(void *name);

    /**
     * Sets the namespace associated with the XML object.
     * @param   ns  The new namespace.
     * @langversion 3.0
     * @playerversion   Flash 9
     */
    void     setNamespace(void *ns);

    /**
     * Returns an XMLList object of all XML properties of the XML object that represent XML text nodes.
     * @return  The list of properties.
     * @langversion 3.0
     * @playerversion   Flash 9
     */
    XMLList *text();

    /**
     * Returns a string representation of the XML object. Unlike the toString() method,
     * the toXMLString() method always returns the start tag, attributes,
     * and end tag of the XML object, regardless of whether the XML object has simple content or complex
     * content. (The toString() method strips out these items for XML objects that contain
     * simple content.)
     * @return  The string representation of the XML object.
     * @langversion 3.0
     * @playerversion   Flash 9
     */
    std::string toXMLString();

    Function *notification();

    void    *setNotification(Function *f);

    void    *toJSON(std::string k);

    /**
     * Returns the XML object.
     * @return  The primitive value of an XML instance.
     * @langversion 3.0
     * @playerversion   Flash 9
     */
    XML     *valueOf();

    /**
     * Creates a new XML object. You must use the constructor to create an
     * XML object before you call any of the methods of the XML class.
     *
     *   Use the toXMLString() method to return a string representation of the XML object
     * regardless of whether the XML object has simple content or complex content.
     * @param   value   Any object that can be converted to XML with the top-level
     *   XML() function.
     * @langversion 3.0
     * @playerversion   Flash 9
     */
public:
    XML(void *value=NULL);
};

#endif // FLEX11_6_XML_AS
#endif // __cplusplus

