#if !defined(FLEX11_6_FLASH_UTILS_OBJECTOUTPUT_AS)
#define FLEX11_6_FLASH_UTILS_OBJECTOUTPUT_AS
#if defined(__cplusplus)


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
        class ObjectOutput: public Object, public IDataOutput
        {
        public:
            unsigned int objectEncoding();
        public:
            void         objectEncoding(unsigned int version);

        public:
            std::string  endian();
        public:
            void         endian(std::string type);

        public:
            ObjectOutput();

        public:
            void     writeBytes(ByteArray *bytes, unsigned int offset, unsigned int length);

        public:
            void     writeBoolean(bool value);

        public:
            void     writeByte(int value);

        public:
            void     writeShort(int value);

        public:
            void     writeInt(int value);

        public:
            void     writeUnsignedInt(unsigned int value);

        public:
            void     writeFloat(float value);

        public:
            void     writeDouble(float value);

        public:
            void     writeMultiByte(std::string value, std::string charSet);

        public:
            void     writeUTF(std::string value);

        public:
            void     writeUTFBytes(std::string value);

        public:
            void     writeObject(void *object);
        };
    }
}

#endif // FLEX11_6_FLASH_UTILS_OBJECTOUTPUT_AS
#endif // __cplusplus

