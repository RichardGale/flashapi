#if !defined(FLEX11_6_FLASH_DISPLAY3D_INDEXBUFFER3D_AS)
#define FLEX11_6_FLASH_DISPLAY3D_INDEXBUFFER3D_AS
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
    namespace display3D
    {
        class IndexBuffer3D: public Object
        {
        public:
            IndexBuffer3D();

        public:
            void     uploadFromVector(std::vector<unsigned int> *data, int startOffset, int count);

        public:
            void     uploadFromByteArray(ByteArray *data, int byteArrayOffset, int startOffset, int count);

        public:
            void     dispose();
        };
    }
}

#endif // FLEX11_6_FLASH_DISPLAY3D_INDEXBUFFER3D_AS
#endif // __cplusplus

