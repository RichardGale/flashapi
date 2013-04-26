#if !defined(FLEX11_6_FLASH_NET_IDYNAMICPROPERTYOUTPUT_AS)
#define FLEX11_6_FLASH_NET_IDYNAMICPROPERTYOUTPUT_AS
#if defined(__cplusplus)


/**
 * This interface controls the serialization of dynamic properties of dynamic objects.
 * You use this interface with the IDynamicPropertyWriter interface
 * and the <codeph class="+ topic/ph pr-d/codeph ">ObjectEncoding.dynamicPropertyWriter</codeph> property.
 * @langversion 3.0
 * @playerversion   Flash 9
 * @playerversion   Lite 4
 */

namespace flash
{
    namespace net
    {
        class IDynamicPropertyOutput
        {
            /**
             * Adds a dynamic property to the binary output of a serialized object.
             * When the object is subsequently read (using a method such as
             * readObject), it contains the new property.
             * You can use this method
             * to exclude properties of dynamic objects from serialization; to write values
             * to properties of dynamic objects; or to create new properties
             * for dynamic objects.
             * @param   name    The name of the property. You can use this parameter either to specify
             *   the name of an existing property of the dynamic object or to create a
             *   new property.
             * @param   value   The value to write to the specified property.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
            virtual void writeDynamicProperty(std::string name, void *value) = 0;
        };
    }
}

#endif // FLEX11_6_FLASH_NET_IDYNAMICPROPERTYOUTPUT_AS
#endif // __cplusplus

