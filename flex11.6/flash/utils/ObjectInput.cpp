

#include "ObjectInput.h"
#include "flash/utils/ByteArray.h"

using namespace flash::utils;

namespace flash {
namespace utils {


        unsigned int ObjectInput::bytesAvailable()       ;

        unsigned int ObjectInput::objectEncoding()       ;
        void ObjectInput::objectEncoding(unsigned int version)       ;

        std::string ObjectInput::endian()         ;
        void ObjectInput::endian(std::string type)       ;

        ObjectInput::ObjectInput();

        void ObjectInput::readBytes(ByteArray* bytes, unsigned int offset, unsigned int length)       ;

        bool ObjectInput::readBoolean()          ;

        int ObjectInput::readByte()      ;

        unsigned int ObjectInput::readUnsignedByte()       ;

        int ObjectInput::readShort()      ;

        unsigned int ObjectInput::readUnsignedShort()       ;

        int ObjectInput::readInt()      ;

        unsigned int ObjectInput::readUnsignedInt()       ;

        float ObjectInput::readFloat()         ;

        float ObjectInput::readDouble()         ;

        std::string ObjectInput::readMultiByte(unsigned int length, std::string charSet)         ;

        std::string ObjectInput::readUTF()         ;

        std::string ObjectInput::readUTFBytes(unsigned int length)         ;

        void* ObjectInput::readObject()    ;
}
}

