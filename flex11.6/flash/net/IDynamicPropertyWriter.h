#if !defined(FLEX11_6_FLASH_NET_IDYNAMICPROPERTYWRITER_AS)
#define FLEX11_6_FLASH_NET_IDYNAMICPROPERTYWRITER_AS
#if defined(__cplusplus)


#include "flex11.6.h"
namespace flash
{
    namespace net
    {
        class IDynamicPropertyOutput;
    }
}

/**
 * This interface is used with the IDynamicPropertyOutput interface to control
 * the serialization of dynamic properties of dynamic objects. To use this interface,
 * assign an object that implements the IDynamicPropertyWriter interface to
 * the <codeph class="+ topic/ph pr-d/codeph ">ObjectEncoding.dynamicPropertyWriter</codeph> property.
 * @langversion 3.0
 * @playerversion   Flash 9
 * @playerversion   Lite 4
 */

using namespace flash::net;

namespace flash
{
    namespace net
    {
        class IDynamicPropertyWriter
        {
            /**
             * Writes the name and value of an IDynamicPropertyOutput object to an object with
             * dynamic properties. If ObjectEncoding.dynamicPropertyWriter is set,
             * this method is invoked for each object with dynamic properties.
             * @param   obj The object to write to.
             * @param   output  The IDynamicPropertyOutput object that contains the name and value
             *   to dynamically write to the object.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */virtual
            void     writeDynamicProperties(Object *obj, IDynamicPropertyOutput *output) = 0;
        };
    }
}

#endif // FLEX11_6_FLASH_NET_IDYNAMICPROPERTYWRITER_AS
#endif // __cplusplus

