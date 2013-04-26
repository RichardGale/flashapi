#if !defined(FLEX11_6_FLASH_DISPLAY_SHADERPARAMETER_AS)
#define FLEX11_6_FLASH_DISPLAY_SHADERPARAMETER_AS
#if defined(__cplusplus)


/**
 * A ShaderParameter instance represents a single input parameter of
 * a shader kernel. A kernel can be defined to accept zero, one, or more
 * parameters that are used in the kernel execution. A ShaderParameter
 * provides information about the parameter, such as the type of data
 * it expects. It also provides a mechanism for setting the parameter
 * value that is used when the shader executes. To specify a value or
 * values for the shader parameter,
 * create an Array containing the value or values and assign it to the
 * <codeph class="+ topic/ph pr-d/codeph ">value</codeph> property.
 *
 *   <p class="- topic/p ">A ShaderParameter instance representing a parameter
 * for a Shader instance is accessed as a property of the Shader instance's
 * <codeph class="+ topic/ph pr-d/codeph ">data</codeph> property. The ShaderParameter property has the same name
 * as the parameter's name in the shader code.
 * For example, if a shader defines a parameter named <codeph class="+ topic/ph pr-d/codeph ">radius</codeph>,
 * the ShaderParameter instance representing the <codeph class="+ topic/ph pr-d/codeph ">radius</codeph> parameter
 * is available as the <codeph class="+ topic/ph pr-d/codeph ">radius</codeph> property, as shown here:</p><codeblock xml:space="preserve" class="+ topic/pre pr-d/codeblock ">var radiusParam:ShaderParameter = myShader.data.radius;</codeblock><p class="- topic/p ">In addition to the defined properties of the ShaderParameter class,
 * each ShaderParameter instance has additional properties
 * corresponding to any metadata defined for the parameter. These properties
 * are added to the ShaderParameter object when it is created. The properties'
 * names match the metadata names specified in the shader's source code.
 * The data type of each property varies according to the data type of the
 * corresponding metadata. A text metadata value such as "description" is a String
 * instance. A metadata property with a non-string value (such as <codeph class="+ topic/ph pr-d/codeph ">minValue</codeph>
 * or <codeph class="+ topic/ph pr-d/codeph ">defaultValue</codeph>) is represented as an Array instance. The number of elements and
 * element data types correspond to the metadata values.</p><p class="- topic/p ">For example, suppose a shader includes the following two parameter declarations:</p><codeblock xml:space="preserve" class="+ topic/pre pr-d/codeblock ">
 * parameter float2 size
 * &lt;
 * description: "The size of the image to which the kernel is applied";
 * minValue: float2(0.0, 0.0);
 * maxValue: float2(100.0, 100.0);
 * defaultValue: float2(50.0, 50.0);
 * &gt;;
 *
 *   parameter float radius
 * &lt;
 * description: "The radius of the effect";
 * minValue: 0.0;
 * maxValue: 50.0;
 * defaultValue: 25.0;
 * &gt;;
 * </codeblock><p class="- topic/p ">The ShaderParameter instance
 * corresponding to the <codeph class="+ topic/ph pr-d/codeph ">size</codeph> parameter has the following metadata
 * properties in addition to its built-in properties:</p><adobetable class="innertable"><tgroup cols="3" class="- topic/tgroup "><thead class="- topic/thead "><row class="- topic/row "><entry class="- topic/entry ">Property name</entry><entry class="- topic/entry ">Data type</entry><entry class="- topic/entry ">Value</entry></row></thead><tbody class="- topic/tbody "><row class="- topic/row "><entry class="- topic/entry "><codeph class="+ topic/ph pr-d/codeph ">name</codeph></entry><entry class="- topic/entry ">String</entry><entry class="- topic/entry "><codeph class="+ topic/ph pr-d/codeph ">"size"</codeph></entry></row><row class="- topic/row "><entry class="- topic/entry "><codeph class="+ topic/ph pr-d/codeph ">description</codeph></entry><entry class="- topic/entry ">String</entry><entry class="- topic/entry "><codeph class="+ topic/ph pr-d/codeph ">"The size of the image to which the kernel is applied"</codeph></entry></row><row class="- topic/row "><entry class="- topic/entry "><codeph class="+ topic/ph pr-d/codeph ">minValue</codeph></entry><entry class="- topic/entry ">Array</entry><entry class="- topic/entry "><codeph class="+ topic/ph pr-d/codeph ">[0, 0]</codeph></entry></row><row class="- topic/row "><entry class="- topic/entry "><codeph class="+ topic/ph pr-d/codeph ">maxValue</codeph></entry><entry class="- topic/entry ">Array</entry><entry class="- topic/entry "><codeph class="+ topic/ph pr-d/codeph ">[100, 100]</codeph></entry></row><row class="- topic/row "><entry class="- topic/entry "><codeph class="+ topic/ph pr-d/codeph ">defaultValue</codeph></entry><entry class="- topic/entry ">Array</entry><entry class="- topic/entry "><codeph class="+ topic/ph pr-d/codeph ">[50, 50]</codeph></entry></row></tbody></tgroup></adobetable><p class="- topic/p ">The ShaderParameter corresponding to the <codeph class="+ topic/ph pr-d/codeph ">radius</codeph> parameter
 * has the following additional properties:</p><adobetable class="innertable"><tgroup cols="3" class="- topic/tgroup "><thead class="- topic/thead "><row class="- topic/row "><entry class="- topic/entry ">Property name</entry><entry class="- topic/entry ">Data type</entry><entry class="- topic/entry ">Value</entry></row></thead><tbody class="- topic/tbody "><row class="- topic/row "><entry class="- topic/entry "><codeph class="+ topic/ph pr-d/codeph ">name</codeph></entry><entry class="- topic/entry ">String</entry><entry class="- topic/entry "><codeph class="+ topic/ph pr-d/codeph ">"radius"</codeph></entry></row><row class="- topic/row "><entry class="- topic/entry "><codeph class="+ topic/ph pr-d/codeph ">description</codeph></entry><entry class="- topic/entry ">String</entry><entry class="- topic/entry "><codeph class="+ topic/ph pr-d/codeph ">"The radius of the effect"</codeph></entry></row><row class="- topic/row "><entry class="- topic/entry "><codeph class="+ topic/ph pr-d/codeph ">minValue</codeph></entry><entry class="- topic/entry ">Array</entry><entry class="- topic/entry "><codeph class="+ topic/ph pr-d/codeph ">[0]</codeph></entry></row><row class="- topic/row "><entry class="- topic/entry "><codeph class="+ topic/ph pr-d/codeph ">maxValue</codeph></entry><entry class="- topic/entry ">Array</entry><entry class="- topic/entry "><codeph class="+ topic/ph pr-d/codeph ">[50]</codeph></entry></row><row class="- topic/row "><entry class="- topic/entry "><codeph class="+ topic/ph pr-d/codeph ">defaultValue</codeph></entry><entry class="- topic/entry ">Array</entry><entry class="- topic/entry "><codeph class="+ topic/ph pr-d/codeph ">[25]</codeph></entry></row></tbody></tgroup></adobetable><p class="- topic/p ">Generally, developer code does not create a ShaderParameter instance
 * directly. A ShaderParameter instance is created for each of a shader's
 * parameters when the Shader instance is created.</p>
 * @langversion 3.0
 * @playerversion   Flash 10
 * @playerversion   AIR 1.5
 */

namespace flash
{
    namespace display
    {
        class ShaderParameter: public Object
        {
            /**
             * The value or values that are passed in as the parameter value to the shader.
             * The value property is an indexed Array. The number and type of
             * the elements of the Array correspond to the data type of the parameter, which
             * can be determined using the type property.
             *
             *   The following table indicates the parameter type and corresponding
             * number and data type of the value Array's elements:Parameter type# ElementsElement data typefloat (ShaderParameterType.FLOAT)1Numberfloat2 (ShaderParameterType.FLOAT2)2Numberfloat3 (ShaderParameterType.FLOAT3)3Numberfloat4 (ShaderParameterType.FLOAT4)4Numberint (ShaderParameterType.INT)1int or uintint2 (ShaderParameterType.INT2)2int or uintint3 (ShaderParameterType.INT3)3int or uintint4 (ShaderParameterType.INT4)4int or uintbool (ShaderParameterType.BOOL)1Booleanbool2 (ShaderParameterType.BOOL2)2Booleanbool3 (ShaderParameterType.BOOL3)3Booleanbool4 (ShaderParameterType.BOOL4)4Booleanfloat2x2 (ShaderParameterType.MATRIX2X2)4Numberfloat3x3 (ShaderParameterType.MATRIX3X3)9Numberfloat4x4 (ShaderParameterType.MATRIX4X4)16NumberFor the matrix parameter types, the array elements fill the rows of
             * the matrix, then the columns. For example, suppose the following line
             * of ActionScript is used to fill a float2x2
             * parameter named myMatrix:
             * <codeblock>
             * myShader.data.myMatrix.value = [.1, .2, .3, .4];
             * </codeblock>
             * Within the shader, the matrix elements have the following values:myMatrix[0][0]: .1myMatrix[0][1]: .2myMatrix[1][0]: .3myMatrix[1][1]: .4
             * @langversion 3.0
             * @playerversion   Flash 10
             * @playerversion   AIR 1.5
             */
        public:
            std::vector<void *> value();
        public:
            void         value(std::vector<void *> v);

            /**
             * The data type of the parameter as defined in the shader. The set of
             * possible values for the type property is defined by the
             * constants in the ShaderParameterType class.
             * @langversion 3.0
             * @playerversion   Flash 10
             * @playerversion   AIR 1.5
             */
        public:
            std::string  type();

            /**
             * The zero-based index of the parameter.
             * @langversion 3.0
             * @playerversion   Flash 10
             * @playerversion   AIR 1.5
             */
        public:
            int          index();

            /**
             * Creates a ShaderParameter instance. Developer code does
             * not call the ShaderParameter constructor
             * directly. A ShaderParameter instance is created for each of a
             * shader's parameters when the Shader instance is created.
             * @langversion 3.0
             * @playerversion   Flash 10
             * @playerversion   AIR 1.5
             */
        public:
            ShaderParameter();
        };
    }
}

#endif // FLEX11_6_FLASH_DISPLAY_SHADERPARAMETER_AS
#endif // __cplusplus

