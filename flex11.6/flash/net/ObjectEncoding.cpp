

#include "ObjectEncoding.h"
#include "flash/net/IDynamicPropertyWriter.h"

    /**
     * The ObjectEncoding class is used in defining serialization settings in classes
     * that serialize objects (such as FileStream, NetStream, NetConnection, SharedObject,
     * and ByteArray) to work with prior versions of ActionScript.
     * 
     *   <p class="- topic/p ">Object encoding controls
     * how objects are represented in Action Message Format (AMF). Flash Player uses
     * AMF to enable efficient communication between an application and a remote server.
     * AMF encodes remote procedure calls into a compact binary representation that can
     * be transferred over HTTP/HTTPS or the RTMP/RTMPS protocol used by Flash Media Server.
     * Objects and data values are serialized into this binary format,
     * which is generally more compact than other representations, such as XML.</p><p class="- topic/p ">Adobe AIR and Flash Player 9 can serialize in two different formats: AMF3 and AMF0.
     * AMF3, the default serialization developed for ActionScript 3.0, provides various advantages
     * over AMF0, which is used for ActionScript 1.0 and 2.0. AMF3 sends data over
     * the network more efficiently than AMF0. <ph class="- topic/ph ">AMF3 supports
     * sending <codeph class="+ topic/ph pr-d/codeph ">int</codeph> and <codeph class="+ topic/ph pr-d/codeph ">uint</codeph>
     * objects as integers and supports data types that are available only in ActionScript 3.0, such as ByteArray,
     * XML, and IExternalizable. It is available only in ActionScript 3.0 and with servers
     * that use AMF3 encoding, such as Flex 2.</ph></p><p class="- topic/p ">The ByteArray, FileStream, NetConnection, NetStream, <ph class="- topic/ph ">SharedObject,</ph>
     * Socket, and URLStream classes contain an <codeph class="+ topic/ph pr-d/codeph ">objectEncoding</codeph> property that is assigned
     * a constant from the ObjectEncoding class.
     * The behavior of the <codeph class="+ topic/ph pr-d/codeph ">objectEncoding</codeph> property differs depending
     * on the object; each class's <codeph class="+ topic/ph pr-d/codeph ">objectEncoding</codeph> property
     * description explains the behavior more thoroughly.</p>
     * @langversion 3.0
     * @playerversion   Flash 9
     * @playerversion   Lite 4
     */

using namespace flash::net;

namespace flash {
namespace net {


        /**
         * Specifies that objects are serialized using the Action Message Format for ActionScript 1.0 and 2.0.
         * @langversion 3.0
         * @playerversion   Flash 9
         * @playerversion   Lite 4
         */
        const unsigned int ObjectEncoding::AMF0=0;

        /**
         * Specifies that objects are serialized using the Action Message Format for ActionScript 3.0.
         * @langversion 3.0
         * @playerversion   Flash 9
         * @playerversion   Lite 4
         */
        const unsigned int ObjectEncoding::AMF3=3;

        /**
         * Specifies the default (latest) format for the current runtime (either Flash
         * Player or AIR). Because object encoding control is only
         * available in Flash Player 9 and later and Adobe AIR, the earliest format used will be
         * the Action Message Format for ActionScript 3.0.
         * 
         *   For example, if an object has the objectEncoding property set to
         * ObjectEncoding.DEFAULT, AMF3 encoding is used.
         * If, in the future, a later version of Flash Player or Adobe AIR introduces a new AMF version
         * and you republish your content, the application will use that new AMF version.
         * You can use this constant only if you're not concerned at all about interoperability
         * with previous versions.
         * @langversion 3.0
         * @playerversion   Flash 9
         * @playerversion   Lite 4
         */
        const unsigned int ObjectEncoding::DEFAULT=3;

        /**
         * Allows greater control over the serialization of dynamic properties of dynamic objects.
         * When this property is set to null,
         * the default value, dynamic properties are serialized using native code, which writes
         * all dynamic properties excluding those whose value is a function.
         * This value is called only for properties of a dynamic object (objects declared
         * within a dynamic class) or for objects declared using the
         * new operator.You can use this property to exclude properties of dynamic objects from
         * serialization; to write values to properties of dynamic objects; or to
         * create new properties for dynamic objects. To do so, set this property to an object that
         * implements the IDynamicPropertyWriter interface. For more information, see the
         * IDynamicPropertyWriter interface.
         * @langversion 3.0
         * @playerversion   Flash 9
         * @playerversion   Lite 4
         */
        flash::net::IDynamicPropertyWriter* ObjectEncoding::dynamicPropertyWriter()                                   ;
        void ObjectEncoding::dynamicPropertyWriter(IDynamicPropertyWriter* object)       ;

        ObjectEncoding::ObjectEncoding();
}
}

