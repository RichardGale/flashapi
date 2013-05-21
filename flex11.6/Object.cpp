

    /**
     * The Object class is at the root of the <ph class="- topic/ph ">ActionScript</ph>
     * class hierarchy. Objects are created by constructors using the
     * <codeph class="+ topic/ph pr-d/codeph ">new</codeph> operator syntax, and can have properties assigned to them dynamically. 
     * <ph class="- topic/ph ">Objects can also be created by 
     * assigning an object literal, as in:</ph><codeblock xml:space="preserve" class="+ topic/pre pr-d/codeblock ">var obj:Object = {a:"foo", b:"bar"}</codeblock><p class="- topic/p ">All classes that don't declare an explicit base class extend the built-in Object class.</p><p class="- topic/p ">You can use the Object class to create <i class="+ topic/ph hi-d/i ">associative arrays</i>. At its core, an associative array is an instance of the Object class, and each key-value pair is represented by a property and its value. Another reason to declare an associative array using the Object data type is that you can then use an object literal to populate your associative array (but only at the time you declare it). The following example creates an associative array using an object literal, accesses items using both the dot operator and the array access operator, and then adds a new key-value pair by creating a new property:</p><codeblock xml:space="preserve" class="+ topic/pre pr-d/codeblock ">
     * var myAssocArray:Object = {fname:"John", lname:"Public"};
     * trace(myAssocArray.fname);     // John
     * trace(myAssocArray["lname"]);  // Public
     * myAssocArray.initial = "Q";
     * trace(myAssocArray.initial);   // Q</codeblock><p class="- topic/p ">ActionScript 3.0 has two types of inheritance: class inheritance and prototype inheritance:</p><ul class="- topic/ul "><li class="- topic/li ">Class inheritance - is the primary inheritance mechanism and supports inheritance of fixed properties. A fixed property is a variable, constant or method declared as part of a class definition. Every class definition is now represented by a special class object that stores information about the class. </li><li class="- topic/li ">Prototype inheritance - is the only inheritance mechanism in previous versions of ActionScript and serves as an alternate form of inheritance in ActionScript 3.0. Each class has an associated prototype object, and the properties of the prototype object are shared by all instances of the class. When a class instance is created, it has a reference to its class's prototype object, which serves as a link between the instance and its associated class prototype object. At run time, when a property is not found on a class instance, the delegate, which is the class prototype object, is checked for that property. If the prototype object does not contain the property, the process continues with the prototype object's delegate checking in consecutively higher levels in the hierarchy until the Flash runtime finds the property. </li></ul><p class="- topic/p ">Both class inheritance and prototype inheritance can exist simultaneously, as shown in the following example:</p><codeblock xml:space="preserve" class="+ topic/pre pr-d/codeblock ">
     * class A {
     * var x = 1
     * prototype.px = 2
     * }
     * dynamic class B extends A {
     * var y = 3
     * prototype.py = 4
     * }
     * 
     *   var b = new B()
     * b.x // 1 via class inheritance
     * b.px // 2 via prototype inheritance from A.prototype
     * b.y // 3
     * b.py // 4 via prototype inheritance from B.prototype
     * 
     *   B.prototype.px = 5
     * b.px // now 5 because B.prototype hides A.prototype
     * 
     *   b.px = 6
     * b.px // now 6 because b hides B.prototype</codeblock><p class="- topic/p ">Using functions instead of classes, you can construct custom prototype inheritance trees. With classes, the prototype inheritance tree mirrors the class inheritance tree. However, since the prototype objects are dynamic, you can add and delete prototype-based properties at run time.</p>
     * 
     *   EXAMPLE:
     * 
     *   The following example uses the classes <codeph class="+ topic/ph pr-d/codeph ">ObjectExample</codeph> and <codeph class="+ topic/ph pr-d/codeph ">Circle</codeph>
     * to demonstrate the dynamic nature of the Object class, and how value objects can be transformed into 
     * Shape objects and then added to the stage at the specified x/y coordinates.
     * 
     *   <p class="- topic/p ">The example creates the value objects <codeph class="+ topic/ph pr-d/codeph ">firstInitObj</codeph> and <codeph class="+ topic/ph pr-d/codeph ">secondInitObj</codeph>. The custom
     * class <codeph class="+ topic/ph pr-d/codeph ">Circle</codeph> accepts the value object and loops over it while setting its matching internal
     * properties to those defined in the value object.</p><codeblock xml:space="preserve" class="+ topic/pre pr-d/codeblock ">
     * package {
     * import flash.display.Sprite;
     * 
     *   public class ObjectExample extends Sprite {
     * public function ObjectExample() {
     * var firstInitObj:Object = new Object();
     * firstInitObj.bgColor = 0xFF0000;
     * firstInitObj.radius = 25;
     * firstInitObj.xCenter = 25;
     * firstInitObj.yCenter = 25;
     * 
     *   var firstCircle:Circle = new Circle(firstInitObj);
     * addChild(firstCircle);
     * firstCircle.x = 50;
     * firstCircle.y = 50;
     * 
     *   var secondInitObj:Object = {bgColor:0xCCCCCC, radius:50, xCenter:50, yCenter:50};
     * 
     *   var secondCircle:Circle = new Circle(secondInitObj);            
     * addChild(secondCircle);
     * secondCircle.x = 100;
     * secondCircle.y = 100;
     * }
     * 
     *   }
     * }
     * 
     *   import flash.display.Shape;
     * 
     *   class Circle extends Shape {
     * public var bgColor:Number = 0xFFFFFF;
     * public var radius:Number = 0;
     * public var xCenter:Number = 0;
     * public var yCenter:Number = 0;
     * 
     *   public function Circle(initObj:Object) {
     * for(var i:String in initObj) {
     * this[i] = initObj[i];
     * }
     * draw();
     * }
     * 
     *   public function draw():void {
     * graphics.beginFill(bgColor);
     * graphics.drawCircle(xCenter, yCenter, radius);
     * graphics.endFill();
     * }
     * }
     * </codeblock>
     * @playerversion   Flash 9
     * @playerversion   AIR 1.0
     * @playerversion   Lite 4
     */




        const int Object::length  ;
                   

        void Object::_setPropertyIsEnumerable(void* o, std::string V, bool enumerable)       ;

        void Object::_dontEnumPrototype(Object* proto)       ;

        void* Object::init()    ;

        void* Object::_init()    ;

        /**
         * Indicates whether an instance of the Object class is in the prototype chain of the object specified 
         * as the parameter. This method returns true if the object is in the prototype chain of the 
         * object specified by the theClass parameter. The method returns false 
         * if the target object is absent from the prototype chain of the theClass object, 
         * and also if the theClass parameter is not an object.
         * 
         *   Note: Methods of the Object class are dynamically created on Object's prototype. To redefine this method in a subclass of Object, do not use the override keyword. For example, A subclass of Object implements function isPrototypeOf():Boolean instead of using an override of the base class.
         * @param   theClass    The class to which the specified object may refer.
         * @return  If the object is in the prototype chain of the object 
         *   specified by the theClass parameter this value is true, otherwise false.
         * @langversion 3.0
         * @playerversion   Flash 9
         * @playerversion   AIR 1.0
         * @playerversion   Lite 4
         */bool Object::isPrototypeOf(void* V)          ;

        /**
         * Indicates whether an object has a specified property defined. This method returns true if the target object has
         * a property that matches the string specified by the name parameter, and false otherwise. 
         * The following types of properties cause this method to return true for objects that are instances of a class (as opposed to class objects):
         * Fixed instance properties   variables, constants, or methods defined by the object's class that are not static;Inherited fixed instance properties   variables, constants, or methods inherited by the object's class;Dynamic properties   properties added to an object after it is instantiated (outside of its class definition). To add dynamic properties, the object's defining class must be declared with the dynamic keyword.The following types of properties cause this method to return false for objects that are instances of a class:Static properties   variables, constants, or methods defined with the static keyword in an object's defining class or any of its superclasses;Prototype properties   properties defined on a prototype object that is part of the object's prototype chain. In ActionScript 3.0, the prototype chain is not used for class inheritance, but still exists as an alternative form of inheritance. For example, an instance of the Array class can access the valueOf() method because it exists on Object.prototype, which is part of the prototype chain for the Array class. Although you can use valueOf() on an instance of Array, the return value of hasOwnProperty("valueOf") for that instance is false.ActionScript 3.0 also has class objects, which are direct representations of class definitions. 
         * When called on class objects, the hasOwnProperty() method returns true only if a property 
         * is a static property defined on that class object. For example, if you create a subclass of Array named 
         * CustomArray, and define a static property in CustomArray named foo, a call to 
         * CustomArray.hasOwnProperty("foo") returns true.
         * For the static property DESCENDING defined in the Array class, however, a call to 
         * CustomArray.hasOwnProperty("DESCENDING") returns false.Note: Methods of the Object class are dynamically created on Object's prototype. To redefine this method in a subclass of Object, do not use the override keyword. For example, A subclass of Object implements function hasOwnProperty():Boolean instead of using an override of the base class.
         * @param   name    The property of the object.
         * @return  If the target object has the property specified by the name 
         *   parameter this value is true, otherwise false.
         * @langversion 3.0
         * @playerversion   Flash 9
         * @playerversion   AIR 1.0
         * @playerversion   Lite 4
         * @category    Method
         */bool Object::hasOwnProperty(void* V)          ;

        /**
         * Creates an Object object and stores a reference to the object's constructor method in the object's constructor property.
         * @playerversion   Flash 9
         * @playerversion   AIR 1.0
         * @playerversion   Lite 4
         */
        Object::Object();

        /**
         * Indicates whether the specified property exists and is enumerable. If true, then the property exists and 
         * can be enumerated in a for..in loop. The property must exist on the target object because this method does not 
         * check the target object's prototype chain.
         * 
         *   Properties that you create are enumerable, but built-in properties are generally not enumerable.Note: Methods of the Object class are dynamically created on Object's prototype. To redefine this method in a subclass of Object, do not use the override keyword. For example, A subclass of Object implements function propertyIsEnumerable():Boolean instead of using an override of the base class.
         * @param   name    The property of the object.
         * @return  If the property specified by the name parameter is enumerable this value is true, otherwise false.
         * @langversion 3.0
         * @playerversion   Flash 9
         * @playerversion   AIR 1.0
         * @playerversion   Lite 4
         * @maelexample The following example creates a generic object, adds a property to the object, then checks whether the object is enumerable. By way of contrast, the example also shows that a built-in property, the <code>Array.length</code> property, is not enumerable.
         *   <listing>
         *   var myObj:Object = new Object();
         *   myObj.prop1 = "hello";
         *   trace(myObj.propertyIsEnumerable("prop1")); // true
         *   
         *     var myArray = new Array();
         *   trace(myArray.propertyIsEnumerable("length")); // false
         *   </listing>
         */bool Object::propertyIsEnumerable(void* V)          ;

