

    /**
     * This class defines the constants that represent the possible values for 
     * the Shader class's <codeph class="+ topic/ph pr-d/codeph ">precisionHint</codeph> property. Each constant 
     * represents one of the precision modes for executing shader operations.
     * 
     *   <p class="- topic/p ">The precision mode selection affects the following shader operations. 
     * These operations are faster on an Intel processor 
     * with the SSE instruction set:</p><ul class="- topic/ul "><li class="- topic/li "><codeph class="+ topic/ph pr-d/codeph ">sin(x)</codeph></li><li class="- topic/li "><codeph class="+ topic/ph pr-d/codeph ">cos(x)</codeph></li><li class="- topic/li "><codeph class="+ topic/ph pr-d/codeph ">tan(x)</codeph></li><li class="- topic/li "><codeph class="+ topic/ph pr-d/codeph ">asin(x)</codeph></li><li class="- topic/li "><codeph class="+ topic/ph pr-d/codeph ">acos(x)</codeph></li><li class="- topic/li "><codeph class="+ topic/ph pr-d/codeph ">atan(x)</codeph></li><li class="- topic/li "><codeph class="+ topic/ph pr-d/codeph ">atan(x, y)</codeph></li><li class="- topic/li "><codeph class="+ topic/ph pr-d/codeph ">exp(x)</codeph></li><li class="- topic/li "><codeph class="+ topic/ph pr-d/codeph ">exp2(x)</codeph></li><li class="- topic/li "><codeph class="+ topic/ph pr-d/codeph ">log(x)</codeph></li><li class="- topic/li "><codeph class="+ topic/ph pr-d/codeph ">log2(x)</codeph></li><li class="- topic/li "><codeph class="+ topic/ph pr-d/codeph ">pow(x, y)</codeph></li><li class="- topic/li "><codeph class="+ topic/ph pr-d/codeph ">reciprocal(x)</codeph></li><li class="- topic/li "><codeph class="+ topic/ph pr-d/codeph ">sqrt(x)</codeph></li></ul>
     * @langversion 3.0
     * @playerversion   Flash 10
     * @playerversion   AIR 1.5
     */


namespace flash {
namespace display {


        /**
         * Represents full precision mode.
         * 
         *   In full precision mode, the shader computes all math 
         * operations to the full width of the IEEE 32-bit floating standard. This mode provides 
         * consistent behavior on all platforms. In this mode, some math operations such 
         * as trigonometric and exponential functions can be slow.
         * @langversion 3.0
         * @playerversion   Flash 10
         * @playerversion   AIR 1.5
         */
        const std::string ShaderPrecision::FULL   = "full";

        /**
         * Represents fast precision mode.
         * 
         *   Fast precision mode is designed for 
         * maximum performance but does not work consistently on different platforms 
         * and individual CPU configurations. In many cases, this level of precision
         * is sufficient to create graphic effects without visible artifacts.It is usually faster to use fast precision mode than to use lookup tables.
         * @langversion 3.0
         * @playerversion   Flash 10
         * @playerversion   AIR 1.5
         */
        const std::string ShaderPrecision::FAST   = "fast";

        ShaderPrecision::ShaderPrecision();
}
}

