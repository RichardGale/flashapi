#if !defined(FLEX11_6_FLASH_UTILS_PACKAGE_AS_AS)
#define FLEX11_6_FLASH_UTILS_PACKAGE_AS_AS
#if defined(__cplusplus)


/**
 * Runs a function at a specified interval (in milliseconds).
 *
 *   Instead of using the setInterval() method, consider
 * creating a Timer object, with the specified interval, using 0 as the repeatCount
 * parameter (which sets the timer to repeat indefinitely).If you intend to use the clearInterval() method to cancel the
 * setInterval() call, be sure to assign the setInterval() call to a
 * variable (which the clearInterval() function will later reference).
 * If you do not call the clearInterval() function to cancel the
 * setInterval() call, the object containing the set timeout closure
 * function will not be garbage collected.
 * @param   closure The name of the function to execute. Do not include quotation marks or
 *   parentheses, and do not specify parameters of the function to call. For example, use
 *   functionName, not functionName() or functionName(param).
 * @param   delay   The interval, in milliseconds.
 * @param   arguments   An optional list of arguments that are passed to the closure function.
 * @return  Unique numeric identifier for the timed process. Use this identifier to cancel
 *   the process, by calling the clearInterval() method.
 * @langversion 3.0
 * @playerversion   Flash 9
 */
public:
unsigned int setInterval(Function *closure, float delay, ...);
/**
 * Runs a specified function after a specified delay (in milliseconds).
 *
 *   Instead of using this method, consider
 * creating a Timer object, with the specified interval, using 1 as the repeatCount
 * parameter (which sets the timer to run only once).If you intend to use the clearTimeout() method to cancel the
 * setTimeout() call, be sure to assign the setTimeout() call to a
 * variable (which the clearTimeout() function will later reference).
 * If you do not call the clearTimeout() function to cancel the
 * setTimeout() call, the object containing the set timeout closure
 * function will not be garbage collected.
 * @param   closure The name of the function to execute. Do not include quotation marks or
 *   parentheses, and do not specify parameters of the function to call. For example, use
 *   functionName, not functionName() or functionName(param).
 * @param   delay   The delay, in milliseconds, until the function is executed.
 * @param   arguments   An optional list of arguments that are passed to the closure function.
 * @return  Unique numeric identifier for the timed process. Use this identifier to cancel
 *   the process, by calling the clearTimeout() method.
 * @langversion 3.0
 * @playerversion   Flash 9
 */
public:
unsigned int setTimeout(Function *closure, float delay, ...);
/**
 * Cancels a specified setInterval() call.
 * @param   id  The ID of the setInterval() call, which you set to a variable,
 *   as in the following:
 * @langversion 3.0
 * @playerversion   Flash 9
 */
public:
void     clearInterval(unsigned int id);
/**
 * Cancels a specified setTimeout() call.
 * @param   id  The ID of the setTimeout() call, which you set to a variable,
 *   as in the following:
 * @langversion 3.0
 * @playerversion   Flash 9
 */
public:
void     clearTimeout(unsigned int id);
/**
 * Produces an XML object that describes the ActionScript object named as the parameter of
 * the method. This method implements the programming concept of reflection for the
 * ActionScript language.
 * If the value parameter is an instance of a type, the returned XML object includes all the instance properties of that type,
 * but does not include any static properties. You can check for this condition when you parse the XML object by examining the value of the <type> tag's isStatic attribute, which is false when the value parameter is an instance of a type.To obtain the static properties of a type, pass the type itself for the value parameter. The returned XML object includes not only the type's static properties, but also all of its instance properties.
 * The instance properties are nested inside a tag named <factory> to distinguish them from the static properties.
 * In this case, the isStatic attribute of the <type> tag is true.Note: If you need only to traverse an object's inheritance hierarchy and do not need the other information provided by describeType(),
 * use the getQualifiedClassName() and getQualifiedSuperclassName() functions instead.The following table describes some of the tags and attributes of the XML object generated by describeType()
 * (all class and interface names returned are in fully qualified format):TagAttributeDescription<type>  The root tag of the XML object.  nameThe name of the ActionScript object's data type.  baseThe immediate superclass of the ActionScript object's defining class. If the ActionScript object is a class object, the value is Class.  isDynamictrue if the ActionScript object's defining class is dynamic; false otherwise. If the ActionScript object is a class object, the value is true because the Class class is dynamic.  isFinaltrue if the ActionScript object's defining class is final; false otherwise.  isStatictrue if the ActionScript object is a class object or constructor function; false otherwise. This attribute is named isStatic because if it is true, any tags that are not nested inside the factory tag are static.<extendsClass>  There is a separate extendsClass tag for each superclass of the ActionScript object's defining class.  typeThe name of a superclass that the ActionScript object's defining class extends.<implementsInterface>  There is a separate implementsInterface tag for each interface implemented by the ActionScript object's defining class or any of its superclasses.  typeThe name of an interface that the ActionScript object's defining class implements.<accessor>  An accessor is a property defined by getter and setter functions.  nameThe name of the accessor.  accessThe access rights of the property. Possible values include readonly, writeonly, and readwrite.  typeThe data type of the property.  declaredByThe class that contains the associated getter or setter functions.<constant>  A constant is a property defined with the const statement.  nameThe name of the constant.  typeThe data type of the constant.<method>  A method is a function declared as part of a class definition.  nameThe name of the method.  declaredByThe class that contains the method definition.  returnTypeThe data type of the method's return value.<parameter>  There is a separate parameter tag for each parameter that a method defines. This tag is always nested inside a <method> tag.  indexA number corresponding to the order in which the parameter appears in the method's parameter list. The first parameter has a value of 1.  typeThe data type of the parameter.  optionaltrue if the parameter is optional; false otherwise.<variable>  A variable is a property defined with the var statement.  nameThe name of the variable.  typeThe data type of the variable.<factory>  If the ActionScript object is a class object or constructor function, all instance properties and methods are nested inside this tag. If the isStatic attribute of the <type> tag is true, all properties and methods that are not nested within the <factory> tag are static. This tag appears only if the ActionScript object is a class object or constructor function.
 * @param   value   The object for which a type description is desired. Any ActionScript value
 *   may be passed to this method including all available ActionScript types, object
 *   instances, primitive types such as uint, and class objects.
 * @return  An XML object containing details about the object that was passed in as a parameter.
 *   It provides the following information about the object:
 *
 *     The class of the objectThe attributes of the classThe inheritance tree from the class to its base classesThe interfaces implemented by the classThe declared instance properties of the classThe declared static properties of the classThe instance methods of the classThe static methods of the class For each method of the class, the name, number of parameters, return type,
 *   and parameter types Note:describeType() only shows public properties and methods, and will not show
 *   properties and methods that are private, package internal or in custom namespaces.
 * @langversion 3.0
 * @playerversion   Flash 9
 * @playerversion   Lite 4
 */
public:
XML     *describeType(void *value);
public:
std::string getAliasName(void *value);
/**
 * Returns the fully qualified class name of an object.
 * @param   value   The object for which a fully qualified class name is desired. Any ActionScript value
 *   may be passed to this method including all available ActionScript types, object
 *   instances, primitive types such as uint, and class objects.
 * @return  A string containing the fully qualified class name.
 * @langversion 3.0
 * @playerversion   Flash 9
 * @playerversion   Lite 4
 */
public:
std::string getQualifiedClassName(void *value);
/**
 * Returns a reference to the class object of the class specified by the name parameter.
 * @param   name    The name of a class.
 * @return  Returns a reference to the class object of the class specified by the name parameter.
 * @langversion 3.0
 * @playerversion   Flash 9
 * @playerversion   Lite 4
 * @throws  ReferenceError No public definition exists with the
 *   specified name.
 */
public:
Object  *getDefinitionByName(std::string name);
/**
 * Returns the fully qualified class name of the base class of the object specified by the value
 * parameter. This function provides a quicker way of retrieving the base class name than describeType(), but also
 * doesn't provide all the information describeType() does.
 * After you retrieve the name of a class with this function, you can convert the class name to a class reference with the getDefinitionByName() function.Note: This function restricts itself to instance hierarchies, whereas the describeType() function
 * uses class object hierarchies if the value parameter is a data type. Calling describeType() on a data type returns the
 * superclass based on the class object hierarchy, in which all class objects inherit from Class. The getQualifiedSuperclassName()
 * function, however, ignores the class object hierarchy and returns the superclass based on the more familiar instance hierarchy.
 * For example, calling getQualifiedSuperclassName(String)
 * returns Object although technically the String class object inherits from Class. In other words, the results are
 * the same whether you use an instance of a type or the type itself.
 * @param   value   Any value.
 * @return  A fully qualified base class name, or null if none exists.
 * @langversion 3.0
 * @playerversion   Flash 9
 * @playerversion   Lite 4
 */
public:
std::string getQualifiedSuperclassName(void *value);
/**
 * Used to compute relative time. For a Flash runtime processing ActionScript 3.0, this method returns the number of milliseconds that have elapsed
 * since the Flash runtime virtual machine for ActionScript 3.0 (AVM2) started. For a Flash runtime processing ActionScript 2.0, this method returns
 * the number of milliseconds since the Flash runtime began initialization. Flash runtimes use two
 * virtual machines to process ActionScript. AVM1 is the ActionScript virtual machine used to run ActionScript 1.0 and 2.0.
 * AVM2 is the ActionScript virtual machine used to run ActionScript 3.0. The getTimer() method behavior for AVM1 is different than the
 * behavior for AVM2.
 * For a calendar date (timestamp), see the Date object.
 * @return  The number of milliseconds since the runtime was initialized (while processing ActionScript 2.0), or since the virtual machine started (while
 *   processing ActionScript 3.0). If the runtime starts playing one
 *   SWF file, and another SWF file is loaded later, the return value is relative to when the first SWF file was
 *   loaded.
 * @langversion 3.0
 * @playerversion   Flash 9
 * @playerversion   Lite 4
 */
public:
int      getTimer();
/**
 * Returns an escaped copy of the input string encoded as either UTF-8 or system code page, depending on the value of System.useCodePage.
 * Use of System.useCodePage allows legacy content encoded in local code pages to be accessed by the runtime, but only on systems using that legacy code page.
 * For example, Japanese data encoded as Shift-JIS will only be escaped and unescaped properly on an OS using a Japanese default code page.
 * @param   value   The string to be escaped.
 * @return  An escaped copy of the input string.  If System.useCodePage is true, the escaped string is encoded in the system code page.
 *   If System.useCodePage is false, the escaped string is encoded in UTF-8.
 *   For example, the input string "Cr  e" will be escaped as "Cr%C3%BCe" on all systems if System.useCodePage is false.
 *   If system.useCodePage is true, and the system uses a Latin code page, "Cr  e" will be escaped as "Cr%FCe".
 *   If the system uses a non Latin code page that does not contain the letter '  ' the result will probably be "Cr?e".
 *   Unescaping "Cr%C3%BCe" with System.useCodePage set to true will produce different undesired results on different systems, such as "Cr    e" on a Latin system.
 *   Similarly, unescaping "Cr%FCe" with System.useCodePage set to false could produce "Cre" or "Cr?e" or other variations depending on the code page of the system.
 * @langversion 3.0
 * @playerversion   Flash 9
 * @playerversion   Lite 4
 */
public:
std::string escapeMultiByte(std::string value);
/**
 * Returns an unescaped copy of the input string, which is decoded from either system code page page or UTF-8 depending on the value of System.useCodePage.
 * Use of System.useCodePage allows legacy content encoded in local code pages to be accessed by the runtime, but only on systems using that legacy code page.
 * For example, Japanese data encoded as Shift-JIS will only be escaped and unescaped properly on an OS using a Japanese default code page.
 * @param   value   The escaped string to be unescaped.
 * @return  An unescaped copy of the input string.  If System.useCodePage is true, the escaped string is decoded from the system code page.
 *   If System.useCodePage is false, the escaped string is decoded from UTF-8.
 *   For example, if the input string is "Cr  e" and System.useCodePage is false, the result will be "Cr    e" on all systems.
 *   If System.useCodePage is true and the input string is "Cr%FCe", and the system uses a Latin code page, the result will also be "Cr    e".
 *   Unescaping "Cr%C3%BCe" with System.useCodePage set to true will produce different undesired results on different systems, such as "Cr      e" on a Latin system.
 *   Similarly, unescaping "Cr%FCe" with System.useCodePage set to false could produce "Cre" or "Cr?e" or other variations depending on the code page of the system.
 * @langversion 3.0
 * @playerversion   Flash 9
 * @playerversion   Lite 4
 */
public:
std::string unescapeMultiByte(std::string value);
namespace flash_proxy {};
#endif // FLEX11_6_FLASH_UTILS_PACKAGE_AS_AS
#endif // __cplusplus

