#if !defined(FLEX11_6_FLASH_UTILS_OBJECTINPUT_AS)
#define FLEX11_6_FLASH_UTILS_OBJECTINPUT_AS
#if defined(__cplusplus)


#include "flex11.6.h"
namespace flash
{
    namespace utils
    {
        class ByteArray;
    }
}

using namespace flash::utils;

namespace flash
{
    namespace utils
    {
        class ObjectInput : public Object, public IDataInput
        {
        public:
            unsigned int bytesAvailable();

        public:
            unsigned int objectEncoding();
        public:
            void         objectEncoding(unsigned int version);

        public:
            std::string  endian();
        public:
            void         endian(std::string type);

        public:
            ObjectInput();

        public:
            void     readBytes(ByteArray *bytes, unsigned int offset=0, unsigned int length=0);

        public:
            bool     readBoolean();

        public:
            int      readByte();

        public:
            unsigned int readUnsignedByte();

        public:
            int      readShort();

        public:
            unsigned int readUnsignedShort();

        public:
            int      readInt();

        public:
            unsigned int readUnsignedInt();

        public:
            float    readFloat();

        public:
            float    readDouble();

        public:
            std::string readMultiByte(unsigned int length, std::string charSet);

        public:
            std::string readUTF();

        public:
            std::string readUTFBytes(unsigned int length);

        public:
            void    *readObject();
        };
    }
}

#endif // FLEX11_6_FLASH_UTILS_OBJECTINPUT_AS
#endif // __cplusplus

