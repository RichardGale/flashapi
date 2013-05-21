#if !defined(FLEX11_6_FLASH_UTILS_PROXY_AS)
#define FLEX11_6_FLASH_UTILS_PROXY_AS
#if defined(__cplusplus)


/**
 * The Proxy class lets you
 * override the default behavior of ActionScript operations
 * (such as retrieving and modifying properties) on an object.
 *
 *   <p class="- topic/p ">The Proxy class has no constructor, and you should not attempt to instantiate Proxy.
 * Instead, subclass the Proxy class to override methods such as
 * <codeph class="+ topic/ph pr-d/codeph ">getProperty</codeph> and provide custom behavior. If you try to use a method of
 * the Proxy class without overriding the method, an exception is thrown.</p><p class="- topic/p ">And, keep in mind, your own code overriding the methods of the Proxy class can throw
 * exceptions unintentionally. Throwing exceptions when using these methods causes problems because
 * the calling code (using operators like <codeph class="+ topic/ph pr-d/codeph ">in</codeph>, <codeph class="+ topic/ph pr-d/codeph ">is</codeph>, <codeph class="+ topic/ph pr-d/codeph ">delete</codeph> and others)
 * does not expect exceptions. Unless you're already sure your overriding method does not throw exceptions,
 * Adobe recommends using <codeph class="+ topic/ph pr-d/codeph ">try..catch</codeph> statements around your implementation of the Proxy class
 * to avoid fatal errors when operators call your methods. For example: </p><codeblock xml:space="preserve" class="+ topic/pre pr-d/codeblock ">
 * dynamic class MyProxy extends Proxy {
 * flash_proxy override function callProperty(name:~~, ...rest):~~ {
 * try {
 * // custom code here
 * }
 * catch (e:Error) {
 * // respond to error here
 * }
 * }
 * </codeblock><p class="- topic/p ">The Proxy class is a replacement for the
 * <codeph class="+ topic/ph pr-d/codeph ">Object.__resolve</codeph> and <codeph class="+ topic/ph pr-d/codeph ">Object.addProperty</codeph>
 * features of ActionScript 2.0, which are no longer
 * available in ActionScript 3.0. The <codeph class="+ topic/ph pr-d/codeph ">Object.addProperty()</codeph> feature allowed you to
 * dynamically create get and set methods in ActionScript 2.0. Although ActionScript 3.0
 * provides get and set methods at compile time, you cannot dynamically assign one
 * to an object unless you use the Proxy class.</p><p class="- topic/p ">To avoid collisions with the <codeph class="+ topic/ph pr-d/codeph ">public</codeph> namespace,
 * the methods of the Proxy class are in the
 * <codeph class="+ topic/ph pr-d/codeph ">flash_proxy</codeph> namespace.</p><p class="- topic/p ">Where methods of the Proxy class take a <codeph class="+ topic/ph pr-d/codeph ">name</codeph>
 * argument, <codeph class="+ topic/ph pr-d/codeph ">name</codeph> can be either a String or
 * a QName object (if namespaces are being used).</p>
 *
 *   EXAMPLE:
 *
 *   <codeblock xml:space="preserve" class="+ topic/pre pr-d/codeblock ">
 * package {
 * import flash.display.Sprite;
 *
 *   public class ProxyExample extends Sprite {
 * public function ProxyExample() {
 * var arr:ProxyArray = new ProxyArray();
 * arr.push(1);
 * arr.push(-2);
 * arr.push(3);
 * arr.push(4);
 * arr.push("five");
 *
 *   trace(arr.length); // 5
 * trace(arr[0]);     // 1
 * trace(arr[1]);     // -2
 * trace(arr[2]);     // 3
 * trace(arr[3]);     // 4
 *
 *   trace(arr.sum());  // 6
 *
 *   arr.clear();
 * trace(arr); // (empty string)
 *
 *   arr[0] = "zero";
 * trace(arr); // zero
 * }
 * }
 * }
 *
 *   import flash.utils.Proxy;
 * import flash.utils.flash_proxy;
 *
 *   dynamic class ProxyArray extends Proxy {
 * private var _item:Array;
 *
 *   public function ProxyArray() {
 * _item = new Array();
 * }
 *
 *   override flash_proxy function callProperty(methodName:*, ... args):* {
 * var res:*;
 * switch (methodName.toString()) {
 * case 'clear':
 * _item = new Array();
 * break;
 * case 'sum':
 * var sum:Number = 0;
 * for each (var i:* in _item) {
 * // ignore non-numeric values
 * if (!isNaN(i)) {
 * sum += i;
 * }
 * }
 * res = sum;
 * break;
 * default:
 * res = _item[methodName].apply(_item, args);
 * break;
 * }
 * return res;
 * }
 *
 *   override flash_proxy function getProperty(name:*):* {
 * return _item[name];
 * }
 *
 *   override flash_proxy function setProperty(name:*, value:*):void {
 * _item[name] = value;
 * }
 * }
 * </codeblock>
 * @langversion 3.0
 * @playerversion   Flash 9
 * @playerversion   Lite 4
 */


namespace flash
{
    namespace utils
    {
        class Proxy : public Object
        {
            /**
             * Overrides any request for a property's value.  If the property can't be found, the method
             * returns undefined. For more information on this behavior, see
             * the ECMA-262 Language Specification, 3rd Edition, section 8.6.2.1.
             * @param   name    The name of the property to retrieve.
             * @return  The specified property or undefined if the property is not found.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
            void    *getProperty(void *name);

        public:
            Proxy();

            /**
             * Overrides a call to change a property's value. If the property can't be found, this method
             * creates a property with the specified name and value.
             * @param   name    The name of the property to modify.
             * @param   value   The value to set the property to.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
            void     setProperty(void *name, void *value);

            /**
             * Overrides the behavior of an object property that can be called as a function. When a method of
             * the object is invoked, this method is called. While some objects can be called as functions,
             * some object properties can also be called as functions.
             * @param   name    The name of the method being invoked.
             * @param   rest    An array specifying the arguments to the
             *   called method.
             * @return  The return value of the called method.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
            void    *callProperty(void *name, ...);

            /**
             * Overrides a request to check whether an object has a particular property by name.
             * @param   name    The name of the property to check for.
             * @return  If the property exists, true; otherwise false.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
            bool     hasProperty(void *name);

            /**
             * Overrides the request to delete a property. When a property is deleted
             * with the delete operator, this
             * method is called to perform the deletion.
             * @param   name    The name of the property to delete.
             * @return  If the property was deleted, true; otherwise false.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
            bool     deleteProperty(void *name);

            /**
             * Overrides the use of the descendant operator.
             * When the descendant operator is used, this method
             * is invoked.
             * @param   name    The name of the property to descend
             *   into the object and search for.
             * @return  The results of the descendant operator.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
            void    *getDescendants(void *name);

            /**
             * Allows enumeration of the proxied object's properties by index number. However, you cannot
             * enumerate the properties of the Proxy class themselves.
             * This function supports implementing for...in and
             * for each..in loops on the object to retrieve property index values.
             * For example:
             * <codeblock>
             *
             *   protected var _item:Array; // array of object's properties
             * override flash_proxy function nextNameIndex (index:int):int {
             * // initial call
             * if (index == 0) {
             * _item = new Array();
             * for (var x:~~ in _target) {
             * _item.push(x);
             * }
             * }
             *
             *   if (index < _item.length) {
             * return index + 1;
             * } else {
             * return 0;
             * }
             * }
             * override flash_proxy function nextName(index:int):String {
             * return _item[index - 1];
             * }
             *
             *   </codeblock>
             * @param   index   The zero-based index value where the enumeration begins.
             * @return  The property's index value.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
            int      nextNameIndex(int index);

            /**
             * Allows enumeration of the proxied object's properties by index number to
             * retrieve property names. However, you cannot
             * enumerate the properties of the Proxy class themselves.
             * This function supports implementing for...in and
             * for each..in loops on the object to retrieve the desired names.
             * For example (with code from Proxy.nextNameIndex()):
             * <codeblock>
             *
             *   protected var _item:Array; // array of object's properties
             * override flash_proxy function nextNameIndex (index:int):int {
             * // initial call
             * if (index == 0) {
             * _item = new Array();
             * for (var x:~~ in _target) {
             * _item.push(x);
             * }
             * }
             *
             *   if (index < _item.length) {
             * return index + 1;
             * } else {
             * return 0;
             * }
             * }
             * override flash_proxy function nextName(index:int):String {
             * return _item[index - 1];
             * }
             *
             *   </codeblock>
             * @param   index   The zero-based index value of the object's property.
             * @return  The property's name.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
            std::string nextName(int index);

            /**
             * Allows enumeration of the proxied object's properties by index number to
             * retrieve property values. However, you cannot
             * enumerate the properties of the Proxy class themselves.
             * This function supports implementing for...in and
             * for each..in loops on the object to retrieve the desired values.
             *
             *   For example (with code from Proxy.nextNameIndex()):
             * <codeblock>
             *
             *   protected var _item:Array; // array of object's properties
             * override flash_proxy function nextNameIndex (index:int):int {
             * // initial call
             * if (index == 0) {
             * _item = new Array();
             * for (var x:~~ in _target) {
             * _item.push(x);
             * }
             * }
             *
             *   if (index < _item.length) {
             * return index + 1;
             * } else {
             * return 0;
             * }
             * }
             * override flash_proxy function nextName(index:int):String {
             * return _item[index - 1];
             * }
             *
             *   </codeblock>
             * @param   index   The zero-based index value of the object's property.
             * @return  The property's value.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
            void    *nextValue(int index);

            /**
             * Checks whether a supplied QName is also marked as an attribute.
             * @param   name    The name of the property to check.
             * @return  Returns true if the argument for name is a QName that is also
             *   marked as an attribute.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
            bool     isAttribute(void *name);
        };
    }
}

#endif // FLEX11_6_FLASH_UTILS_PROXY_AS
#endif // __cplusplus

