#if !defined(FLEX11_6_FUNCTION_AS)
#define FLEX11_6_FUNCTION_AS
#if defined(__cplusplus)


/**
 * A function is the basic unit of code that can be invoked in ActionScript.
 * Both user-defined and built-in functions in ActionScript are represented by Function objects,
 * which are instances of the Function class.
 * <p class="- topic/p ">Methods of a class are slightly different than Function objects. Unlike an ordinary function object, a method is tightly linked to its associated class object. Therefore, a method or property has a definition that is shared among all instances of the same class. Methods can be extracted from an instance and treated as "bound" methods (retaining the link to the original instance). For a bound method, the <codeph class="+ topic/ph pr-d/codeph ">this</codeph> keyword points to the original object that implemented the method. For a function, <codeph class="+ topic/ph pr-d/codeph ">this</codeph> points to the associated object at the time the function is invoked.</p>
 *
 *   EXAMPLE:
 *
 *   The following example uses the <codeph class="+ topic/ph pr-d/codeph ">FunctionExample</codeph>,
 * <codeph class="+ topic/ph pr-d/codeph ">SimpleCollection</codeph>, <codeph class="+ topic/ph pr-d/codeph ">EventBroadcaster</codeph>, and <codeph class="+ topic/ph pr-d/codeph ">EventListener</codeph> classes
 * to show various uses of functions in ActionScript.  This is accomplished with the following steps:
 * <ol class="- topic/ol "><li class="- topic/li ">The constructor for <codeph class="+ topic/ph pr-d/codeph ">FunctionExample</codeph> creates a local variable named
 * <codeph class="+ topic/ph pr-d/codeph ">simpleColl</codeph>, which is populated with an array of integers ranging from <codeph class="+ topic/ph pr-d/codeph ">1</codeph> to
 * <codeph class="+ topic/ph pr-d/codeph ">8</codeph>. </li><li class="- topic/li ">The <codeph class="+ topic/ph pr-d/codeph ">simpleColl</codeph> object is printed using <codeph class="+ topic/ph pr-d/codeph ">trace()</codeph>.</li><li class="- topic/li ">An EventListener object, <codeph class="+ topic/ph pr-d/codeph ">listener</codeph>, is added to <codeph class="+ topic/ph pr-d/codeph ">simpleColl</codeph>.</li><li class="- topic/li ">When the <codeph class="+ topic/ph pr-d/codeph ">insert()</codeph> and <codeph class="+ topic/ph pr-d/codeph ">remove()</codeph> functions are called, the listener responds
 * to their events.</li><li class="- topic/li ">A second SimpleCollection object is created named <codeph class="+ topic/ph pr-d/codeph ">greaterThanFourColl</codeph>.</li><li class="- topic/li ">The <codeph class="+ topic/ph pr-d/codeph ">greaterThanFourColl</codeph> object is assigned the result of <codeph class="+ topic/ph pr-d/codeph ">simpleColl.select()</codeph>
 * with the argument <codeph class="+ topic/ph pr-d/codeph ">4</codeph> and an anonymous function. The SimpleCollection object's select method is an
 * internal iterator that uses the anonymous function parameter as a block.</li></ol><codeblock xml:space="preserve" class="+ topic/pre pr-d/codeblock ">
 * package {
 * import flash.display.Sprite;
 *
 *   public class FunctionExample extends Sprite {
 * public function FunctionExample() {
 * var simpleColl:SimpleCollection;
 * simpleColl = new SimpleCollection(0, 1, 2, 3, 4, 5, 6, 7, 8);
 * trace(simpleColl);        // 0, 1, 2, 3, 4, 5, 6, 7, 8
 *
 *   var listener:EventListener = new EventListener();
 * simpleColl.addListener(listener);
 * simpleColl.insert(9);        // itemInsertedHandler: 9
 * simpleColl.remove(8);        // itemRemovedHandler: 8
 * trace(simpleColl);        // 0, 1, 2, 3, 4, 5, 6, 7, 9
 *
 *   var greaterThanFourColl:SimpleCollection;
 * greaterThanFourColl = simpleColl.select(4, function(item:int, value:int){ return item &gt; value });
 * trace(greaterThanFourColl);    // 5, 6, 7, 9
 * }
 * }
 * }
 *
 *   import flash.display.Sprite;
 *
 *   class EventBroadcaster {
 * private var listeners:Array;
 *
 *   public function EventBroadcaster() {
 * listeners = new Array();
 * }
 *
 *   public function addListener(obj:Object):void {
 * removeListener(obj);
 * listeners.push(obj);
 * }
 *
 *   public function removeListener(obj:Object):void {
 * for(var i:uint = 0; i &lt; listeners.length; i++) {
 * if(listeners[i] == obj) {
 * listeners.splice(i, 1);
 * }
 * }
 * }
 *
 *   public function broadcastEvent(evnt:String, ...args):void {
 * for(var i:uint = 0; i &lt; listeners.length; i++) {
 * listeners[i][evnt].apply(listeners[i], args);
 * }
 * }
 * }
 *
 *   class SimpleCollection extends EventBroadcaster {
 * private var arr:Array;
 * public function SimpleCollection(... args) {
 * arr = (args.length == 1 &amp;&amp; !isNaN(args[0])) ? new Array(args[0]) : args;
 * }
 *
 *   public function insert(obj:Object):void {
 * remove(obj);
 * arr.push(obj);
 * broadcastEvent("itemInsertedHandler", obj);
 * }
 *
 *   public function remove(obj:Object):void {
 * for(var i:uint = 0; i &lt; arr.length; i++) {
 * if(arr[i] == obj) {
 * var obj:Object = arr.splice(i, 1)[0];
 * broadcastEvent("itemRemovedHandler", obj);
 * }
 * }
 * }
 *
 *   public function select(val:int, fn:Function):SimpleCollection {
 * var col:SimpleCollection = new SimpleCollection();
 * for(var i:uint = 0; i &lt; arr.length; i++) {
 * if(fn.call(this, arr[i], val)) {
 * col.insert(arr[i]);
 * }
 * }
 * return col;
 * }
 *
 *   public function toString():String {
 * var str:String = new String();
 * for(var i:uint = 0; i &lt; arr.length - 1; i++) {
 * str += arr[i] + ", ";
 * }
 * str += arr[arr.length - 1];
 * return str;
 * }
 * }
 *
 *   class EventListener {
 * public function EventListener() {
 * }
 *
 *   public function itemInsertedHandler(obj:Object):void {
 * trace("itemInsertedHandler: " + obj);
 * }
 *
 *   public function itemRemovedHandler(obj:Object):void {
 * trace("itemRemovedHandler: " + obj);
 * }
 * }
 * </codeblock>
 * @langversion 3.0
 * @playerversion   Flash 9
 * @playerversion   Lite 4
 */

#include "flex11.6.h"



class Function : public Object
{
public:
    static const int _length;

public:
    void            *prototype();
public:
    void         prototype(void *p);

public:
    int          length();

public:
    Function();

public:
    static Function *createEmptyFunction();

    /**
     * Invokes the function represented by a Function object. Every function in ActionScript
     * is represented by a Function object, so all functions support this method.
     * In almost all cases, the function call (()) operator can be used instead of this method.
     * The function call operator produces code that is concise and readable. This method is primarily useful
     * when the thisObject parameter of the function invocation needs to be explicitly controlled.
     * Normally, if a function is invoked as a method of an object within the body of the function, thisObject
     * is set to myObject, as shown in the following example:
     * <codeblock>
     *
     *   myObject.myMethod(1, 2, 3);
     *
     *   </codeblock>
     * In some situations, you might want thisObject to point somewhere else;
     * for example, if a function must be invoked as a method of an object, but is not actually stored as a method
     * of that object:
     * <codeblock>
     *
     *   myObject.myMethod.call(myOtherObject, 1, 2, 3);
     *
     *   </codeblock>
     * You can pass the value null for the thisObject parameter to invoke a function as a
     * regular function and not as a method of an object. For example, the following function invocations are equivalent:
     * <codeblock>
     *
     *   Math.sin(Math.PI / 4)
     * Math.sin.call(null, Math.PI / 4)
     *
     *   </codeblock>
     * Returns the value that the called function specifies as the return value.
     * @param   thisArg An object that specifies the value of thisObject within the function body.
     * @param   args    The parameter or parameters to be passed to the function. You can specify zero or more parameters.
     * @langversion 3.0
     * @playerversion   Flash 9
     * @playerversion   Lite 4
     */
    void        *call(void *thisArg=NULL, ...);

    /**
     * Specifies the value of thisObject to be used within any function that ActionScript calls.
     * This method also specifies the parameters to be passed to any called function. Because apply()
     * is a method of the Function class, it is also a method of every Function object in ActionScript.
     * The parameters are specified as an Array object, unlike Function.call(), which specifies
     * parameters as a comma-delimited list. This is often useful when the number of parameters to be passed is not
     * known until the script actually executes.Returns the value that the called function specifies as the return value.
     * @param   thisArg The object to which the function is applied.
     * @param   argArray    An array whose elements are passed to the function as parameters.
     * @return  Any value that the called function specifies.
     * @langversion 3.0
     * @playerversion   Flash 9
     * @playerversion   Lite 4
     */
    void        *apply(void *thisArg=NULL, void *argArray=NULL);
};

#endif // FLEX11_6_FUNCTION_AS
#endif // __cplusplus

