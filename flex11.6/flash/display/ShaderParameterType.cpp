

    /**
     * This class defines the constants that represent the possible values for 
     * the ShaderParameter class's <codeph class="+ topic/ph pr-d/codeph ">type</codeph> property. Each constant 
     * represents one of the data types available in Flash Player for 
     * parameters in the Pixel Bender shader language.
     * @langversion 3.0
     * @playerversion   Flash 10
     * @playerversion   AIR 1.5
     */


namespace flash {
namespace display {


        /**
         * Indicates that the shader parameter is defined as a  
         * float value, equivalent to a single Number instance 
         * in ActionScript.
         * 
         *   Note that even though the parameter only expects a single value, 
         * the ShaderParameter.value property is an Array, so the single value 
         * must be the only element of an Array assigned to the 
         * value property, like this:
         * <codeblock>
         * 
         *   // assumes the shader has a parameter named "param"
         * // whose data type is float
         * myShader.data.param.value = [22.5];
         * 
         *   </codeblock>
         * @langversion 3.0
         * @playerversion   Flash 10
         * @playerversion   AIR 1.5
         */
        const std::string ShaderParameterType::FLOAT="float";

        /**
         * Indicates that the shader parameter is defined as a 
         * float2 value, equivalent to an Array of two Number instances 
         * in ActionScript.
         * @langversion 3.0
         * @playerversion   Flash 10
         * @playerversion   AIR 1.5
         */
        const std::string ShaderParameterType::FLOAT2="float2";

        /**
         * Indicates that the shader parameter is defined as a 
         * float3 value, equivalent to an Array of three Number instances 
         * in ActionScript.
         * @langversion 3.0
         * @playerversion   Flash 10
         * @playerversion   AIR 1.5
         */
        const std::string ShaderParameterType::FLOAT3="float3";

        /**
         * Indicates that the shader parameter is defined as a 
         * float4 value, equivalent to an Array of four Number instances 
         * in ActionScript.
         * @langversion 3.0
         * @playerversion   Flash 10
         * @playerversion   AIR 1.5
         */
        const std::string ShaderParameterType::FLOAT4="float4";

        /**
         * Indicates that the shader parameter is defined as an 
         * int value, equivalent to a single int or uint instance 
         * in ActionScript.
         * 
         *   Note that even though the parameter only expects a single value, 
         * the ShaderParameter.value property is an Array, so the single value 
         * must be the only element of an Array assigned to the 
         * value property, like this:
         * <codeblock>
         * 
         *   // assumes the shader has a parameter named "param"
         * // whose data type is int
         * myShader.data.param.value = [275];
         * 
         *   </codeblock>
         * @langversion 3.0
         * @playerversion   Flash 10
         * @playerversion   AIR 1.5
         */
        const std::string ShaderParameterType::INT="int";

        /**
         * Indicates that the shader parameter is defined as an 
         * int2 value, equivalent to an Array of two int or uint 
         * instances in ActionScript.
         * @langversion 3.0
         * @playerversion   Flash 10
         * @playerversion   AIR 1.5
         */
        const std::string ShaderParameterType::INT2="int2";

        /**
         * Indicates that the shader parameter is defined as an 
         * int3 value, equivalent to an Array of three int or uint 
         * instances in ActionScript.
         * @langversion 3.0
         * @playerversion   Flash 10
         * @playerversion   AIR 1.5
         */
        const std::string ShaderParameterType::INT3="int3";

        /**
         * Indicates that the shader parameter is defined as an  
         * int4 value, equivalent to an Array of four int or uint 
         * instances in ActionScript.
         * @langversion 3.0
         * @playerversion   Flash 10
         * @playerversion   AIR 1.5
         */
        const std::string ShaderParameterType::INT4="int4";

        /**
         * Indicates that the shader parameter is defined as a 
         * bool value, equivalent to a single Boolean instance 
         * in ActionScript.
         * 
         *   Note that even though the parameter only expects a single value, 
         * the ShaderParameter.value property is an Array, so the single value 
         * must be the only element of an Array assigned to the 
         * value property, like this:
         * <codeblock>
         * 
         *   // assumes the shader has a parameter named "param"
         * // whose data type is bool
         * myShader.data.param.value = [true];
         * 
         *   </codeblock>
         * @langversion 3.0
         * @playerversion   Flash 10
         * @playerversion   AIR 1.5
         */
        const std::string ShaderParameterType::BOOL="bool";

        /**
         * Indicates that the shader parameter is defined as a 
         * bool2 value, equivalent to an Array of two Boolean instances 
         * in ActionScript.
         * @langversion 3.0
         * @playerversion   Flash 10
         * @playerversion   AIR 1.5
         */
        const std::string ShaderParameterType::BOOL2="bool2";

        /**
         * Indicates that the shader parameter is defined as a 
         * bool3 value, equivalent to an Array of three Boolean instances 
         * in ActionScript.
         * @langversion 3.0
         * @playerversion   Flash 10
         * @playerversion   AIR 1.5
         */
        const std::string ShaderParameterType::BOOL3="bool3";

        /**
         * Indicates that the shader parameter is defined as a 
         * bool4 value, equivalent to an Array of four Boolean instances 
         * in ActionScript.
         * @langversion 3.0
         * @playerversion   Flash 10
         * @playerversion   AIR 1.5
         */
        const std::string ShaderParameterType::BOOL4="bool4";

        /**
         * Indicates that the shader parameter is defined as a 
         * float2x2 value, equivalent to a 2-by-2 matrix. This matrix is represented as an 
         * Array of four Number instances in ActionScript.
         * @langversion 3.0
         * @playerversion   Flash 10
         * @playerversion   AIR 1.5
         */
        const std::string ShaderParameterType::MATRIX2X2="matrix2x2";

        /**
         * Indicates that the shader parameter is defined as a 
         * float3x3 value, equivalent to a 3-by-3 matrix. This matrix is represented as an 
         * Array of nine Number instances in ActionScript.
         * @langversion 3.0
         * @playerversion   Flash 10
         * @playerversion   AIR 1.5
         */
        const std::string ShaderParameterType::MATRIX3X3="matrix3x3";

        /**
         * Indicates that the shader parameter is defined as a 
         * float4x4 value, equivalent to a 4-by-4 matrix. This matrix is represented as an 
         * Array of 16 Number instances in ActionScript.
         * @langversion 3.0
         * @playerversion   Flash 10
         * @playerversion   AIR 1.5
         */
        const std::string ShaderParameterType::MATRIX4X4="matrix4x4";

        ShaderParameterType::ShaderParameterType();
}
}

