#if !defined(FLEX11_6_CLASS_AS)
#define FLEX11_6_CLASS_AS
#if defined(__cplusplus)


/**
 * A Class object is created for each class definition in a program. Every Class object is an instance
 * of the Class class. The Class object contains the static properties and methods of the class. The
 * class object creates instances of the class when invoked using the <codeph class="+ topic/ph pr-d/codeph ">new</codeph> operator.
 *
 *   <p class="- topic/p ">Some methods, such as <codeph class="+ topic/ph pr-d/codeph ">flash.net.getClassByAlias()</codeph>, return an object of type Class.
 * Other methods may have a parameter of type Class, such as <codeph class="+ topic/ph pr-d/codeph ">flash.net.registerClassAlias()</codeph>. </p><p class="- topic/p ">The class name is the reference to the Class object, as this example shows:</p><pre xml:space="preserve" class="- topic/pre ">
 * class Foo {
 * }
 * </pre><p class="- topic/p ">The <codeph class="+ topic/ph pr-d/codeph ">class Foo{}</codeph> statement is the class definition that creates the Class object Foo. Additionally,
 * the statement <codeph class="+ topic/ph pr-d/codeph ">new Foo()</codeph> will create a new instance of class Foo, and the result will be of type Foo.</p><p class="- topic/p ">Use the <codeph class="+ topic/ph pr-d/codeph ">class</codeph> statement to declare your classes. Class objects are useful for advanced
 * techniques, such as assigning classes to an existing instance object at runtime, as shown in the "Examples"
 * section below.</p><p class="- topic/p ">Any static properties and methods of a class live on the class's Class object. Class, itself, declares
 * <codeph class="+ topic/ph pr-d/codeph ">prototype</codeph>.</p><p class="- topic/p ">Generally, you do not need to declare or create variables of type Class manually. However, in the following
 * code, a class is assigned as a public Class property <codeph class="+ topic/ph pr-d/codeph ">circleClass</codeph>, and you can refer to this Class property
 * as a property of the main Library class:</p><codeblock xml:space="preserve" class="+ topic/pre pr-d/codeblock ">
 * package {
 * import flash.display.Sprite;
 * public class Library extends Sprite {
 *
 *   public var circleClass:Class = Circle;
 * public function Library() {
 * }
 * }
 * }
 *
 *   import flash.display.Shape;
 * class Circle extends Shape {
 * public function Circle(color:uint = 0xFFCC00, radius:Number = 10) {
 * graphics.beginFill(color);
 * graphics.drawCircle(radius, radius, radius);
 * }
 * }
 * </codeblock><p class="- topic/p ">Another SWF file can load the resulting Library.swf file and then instantiate objects of type Circle. The
 * following example shows one way to get access to a child SWF file's assets. (Other techniques include using
 * <codeph class="+ topic/ph pr-d/codeph ">flash.utils.getDefnitionByName()</codeph> or importing stub definitions of the child SWF file.)</p><codeblock xml:space="preserve" class="+ topic/pre pr-d/codeblock ">
 * package {
 * import flash.display.Sprite;
 * import flash.display.Shape;
 * import flash.display.Loader;
 * import flash.net.URLRequest;
 * import flash.events.Event;
 * public class LibaryLoader extends Sprite {
 * public function LibaryLoader() {
 * var ldr:Loader = new Loader();
 * var urlReq:URLRequest = new URLRequest("Library.swf");
 * ldr.load(urlReq);
 * ldr.contentLoaderInfo.addEventListener(Event.COMPLETE, loaded);
 * }
 * private function loaded(event:Event):void {
 * var library:Object = event.target.content;
 * var circle:Shape = new library.circleClass();
 * addChild(circle);
 * }
 * }
 * }
 * </codeblock><p class="- topic/p ">In ActionScript 3.0, you can create embedded classes for external assets (such as images, sounds, or fonts) that are
 * compiled into SWF files. In earlier versions of ActionScript, you associated those assets using a linkage ID with the
 * <codeph class="+ topic/ph pr-d/codeph ">MovieClip.attachMovie()</codeph> method. In ActionScript 3.0, each embedded asset is represented by a unique embedded
 * asset class. Therefore, you can use the <codeph class="+ topic/ph pr-d/codeph ">new</codeph> operator to instantiate the asset's associated class and call
 * methods and properties on that asset.</p><p product="flex" class="- topic/p ">For example, if you are using an MXML compiler to generate SWF files, you would create an embedded
 * class as follows:</p><codeblock product="flex" xml:space="preserve" class="+ topic/pre pr-d/codeblock ">
 * [Embed(source="bratwurst.jpg")]
 * public var imgClass:Class;
 * </codeblock><p product="flex" class="- topic/p ">And, to instantiate it, you write the following:</p><codeblock product="flex" xml:space="preserve" class="+ topic/pre pr-d/codeblock ">
 * var myImg:Bitmap = new imgClass();
 * </codeblock>
 *
 *   EXAMPLE:
 *
 *   The following example shows how to use Class objects to defer until runtime
 * the decision about which class to instantiate using the following steps:
 * <ol class="- topic/ol "><li class="- topic/li ">Declare two classes as <codeph class="+ topic/ph pr-d/codeph ">ClassA</codeph> and <codeph class="+ topic/ph pr-d/codeph ">ClassB</codeph>. </li><li class="- topic/li ">Declare a variable of type Class named <codeph class="+ topic/ph pr-d/codeph ">classToConstruct</codeph> and one of type
 * Boolean <codeph class="+ topic/ph pr-d/codeph ">chooseClassA</codeph>, which is set to <codeph class="+ topic/ph pr-d/codeph ">true</codeph> in this case,
 * but your code could use a custom test expression to set the value of that variable. </li></ol><codeblock xml:space="preserve" class="+ topic/pre pr-d/codeblock ">
 * package {
 * import flash.display.Sprite;
 *
 *   public class ClassExample extends Sprite {
 * public function ClassExample() {
 * var classToConstruct:Class;
 * var classInstance:Object;
 *
 *   classToConstruct = ClassA;
 * classInstance = new classToConstruct();
 * trace(classInstance);    // [object ClassA]
 *
 *   classToConstruct = ClassB;
 * classInstance = new classToConstruct();
 * trace(classInstance);    // [object ClassB]
 * }
 * }
 * }
 *
 *   class ClassA {
 * }
 *
 *   class ClassB {
 * }
 * </codeblock>
 * @langversion 3.0
 * @playerversion   Flash 9
 * @playerversion   Lite 4
 */

class Class: public Object
{
public:
    static const int length;

public:
    void        *prototype();

public:
    Class();
};

#endif // FLEX11_6_CLASS_AS
#endif // __cplusplus

