

    /**
     * A Boolean object is a data type that can have one of two values, either <codeph class="+ topic/ph pr-d/codeph ">true</codeph> or <codeph class="+ topic/ph pr-d/codeph ">false</codeph>,  
     * used for logical operations. Use the Boolean 
     * class to retrieve the primitive data type or string representation of a Boolean object.
     * 
     *   <p class="- topic/p ">To create a Boolean object, you can use the constructor or the global function, or assign a literal value. 
     * It doesn't matter which technique you use; in ActionScript 3.0, all three techniques are equivalent. (This is 
     * different from JavaScript, where a Boolean object is distinct from the Boolean primitive type.)</p><p class="- topic/p ">The following lines of code are equivalent:</p><codeblock rev="3.0" xml:space="preserve" class="+ topic/pre pr-d/codeblock ">
     * var flag:Boolean = true;
     * var flag:Boolean = new Boolean(true);
     * var flag:Boolean = Boolean(true);
     * </codeblock>
     * 
     *   EXAMPLE:
     * 
     *   The following example toggles and displays each corresponding value for the Boolean object:
     * <codeblock xml:space="preserve" class="+ topic/pre pr-d/codeblock ">
     * package {
     * import flash.display.Sprite;
     * 
     *   public class BooleanExample extends Sprite {
     * private var flag:Boolean;
     * 
     *   public function BooleanExample() {
     * trace(flag);    // false
     * toggle();
     * trace(flag);    // true
     * toggle();
     * trace(flag);    // false
     * }
     * 
     *   private function toggle():void{
     * flag = !flag;
     * }
     * }
     * }
     * </codeblock>
     * @langversion 3.0
     * @playerversion   Flash 9
     * @playerversion   Lite 4
     * @refpath Objects/Core/Boolean/
     */




        const int Boolean::length  ;

        /**
         * Creates a Boolean object with the specified value. If you omit the expression 
         * parameter, the Boolean object is initialized with a value of false. If you 
         * specify a value for the expression parameter, the method evaluates it and returns the result 
         * as a Boolean value according to the rules in the global Boolean() function.
         * @param   expression  Any expression.
         * @langversion 3.0
         * @playerversion   Flash 9
         * @playerversion   Lite 4
         */
        Boolean::Boolean(void* value);

        /**
         * Returns the string representation ("true" or 
         * "false") of the Boolean object. The output is not localized, and is "true" or 
         * "false" regardless of the system language.
         * @return  The string "true" or "false".
         * @langversion 3.0
         * @playerversion   Flash 9
         * @playerversion   Lite 4
         */std::string Boolean::toString()         ;

        /**
         * Returns true if the value of the specified Boolean 
         * object is true; false otherwise.
         * @return  A Boolean value.
         * @langversion 3.0
         * @playerversion   Flash 9
         * @playerversion   Lite 4
         */bool Boolean::valueOf()          ;

