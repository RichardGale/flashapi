

    /**
     * A RangeError exception is thrown when a numeric value is outside the acceptable range. When working with arrays,
     * referring to an index position of an array item that does not exist will throw a RangeError exception. 
     * Using <codeph class="+ topic/ph pr-d/codeph ">Number.toExponential()</codeph>, <codeph class="+ topic/ph pr-d/codeph ">Number.toPrecision()</codeph>, and <codeph class="+ topic/ph pr-d/codeph ">Number.toFixed()</codeph> methods
     * will throw a RangeError exception in cases
     * where the arguments are outside the acceptable range of numbers. You can extend <codeph class="+ topic/ph pr-d/codeph ">Number.toExponential()</codeph>,
     * <codeph class="+ topic/ph pr-d/codeph ">Number.toPrecision()</codeph>, and <codeph class="+ topic/ph pr-d/codeph ">Number.toFixed()</codeph> to avoid throwing a RangeError.
     * <p product="flash" class="- topic/p ">Other situations that cause this exception to be thrown include the following:
     * <ul class="- topic/ul "><li class="- topic/li ">Any Flash runtime API that expects a depth number is invoked with an invalid depth 
     * number.</li><li class="- topic/li ">Any Flash runtime API that expects a frame number is invoked with an invalid frame 
     * number.</li><li class="- topic/li ">Any Flash runtime API that expects a layer number is invoked with an invalid layer 
     * number.</li></ul></p>
     * 
     *   EXAMPLE:
     * 
     *   The following example shows how a <codeph class="+ topic/ph pr-d/codeph ">RangeError</codeph> exception can 
     * be generated and handled within a <codeph class="+ topic/ph pr-d/codeph ">try..catch</codeph> statement. 
     * <codeblock xml:space="preserve" class="+ topic/pre pr-d/codeblock ">
     * package {
     * import flash.display.Sprite;
     * 
     *   public class RangeErrorExample extends Sprite {
     * 
     *   public function RangeErrorExample() {
     * var child:Sprite = new Sprite();
     * try {
     * addChildAt(child, 1);
     * }
     * catch(e:RangeError) {
     * trace(e);
     * }
     * }
     * }
     * }
     * </codeblock>
     * @langversion 3.0
     * @playerversion   Flash 9
     * @playerversion   AIR 1.0
     * @playerversion   Lite 4
     */




        const int RangeError::length  ;

        /**
         * Creates a new RangeError object.
         * @param   message Contains the message associated with the RangeError object.
         * @playerversion   Lite 4
         * @playerversion   Flash 9
         * @playerversion   AIR 1.0
         */
        RangeError::RangeError(std::string message, void* id);

