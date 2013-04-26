#if !defined(FLEX11_6_FLASH_DISPLAY3D_VERTEXBUFFER3D_AS)
#define FLEX11_6_FLASH_DISPLAY3D_VERTEXBUFFER3D_AS
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
        class VertexBuffer3D: public Object
        {
        public:
            void     uploadFromVector(std::vector<float> *data, int startVertex, int numVertices);

        public:
            void     uploadFromByteArray(ByteArray *data, int byteArrayOffset, int startVertex, int numVertices);

        public:
            void     dispose();

        public:
            VertexBuffer3D();
        };
    }
}

#endif // FLEX11_6_FLASH_DISPLAY3D_VERTEXBUFFER3D_AS
#endif // __cplusplus

