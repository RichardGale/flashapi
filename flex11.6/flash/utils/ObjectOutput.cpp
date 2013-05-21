

#include "ObjectOutput.h"
#include "flash/utils/ByteArray.h"

using namespace flash::utils;

namespace flash {
namespace utils {


        unsigned int ObjectOutput::objectEncoding()       ;
        void ObjectOutput::objectEncoding(unsigned int version)       ;

        std::string ObjectOutput::endian()         ;
        void ObjectOutput::endian(std::string type)       ;

        ObjectOutput::ObjectOutput();

        void ObjectOutput::writeBytes(ByteArray* bytes, unsigned int offset, unsigned int length)       ;

        void ObjectOutput::writeBoolean(bool value)       ;

        void ObjectOutput::writeByte(int value)       ;

        void ObjectOutput::writeShort(int value)       ;

        void ObjectOutput::writeInt(int value)       ;

        void ObjectOutput::writeUnsignedInt(unsigned int value)       ;

        void ObjectOutput::writeFloat(float value)       ;

        void ObjectOutput::writeDouble(float value)       ;

        void ObjectOutput::writeMultiByte(std::string value, std::string charSet)       ;

        void ObjectOutput::writeUTF(std::string value)       ;

        void ObjectOutput::writeUTFBytes(std::string value)       ;

        void ObjectOutput::writeObject(void* object)       ;
}
}

