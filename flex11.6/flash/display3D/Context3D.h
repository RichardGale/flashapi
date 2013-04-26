#if !defined(FLEX11_6_FLASH_DISPLAY3D_CONTEXT3D_AS)
#define FLEX11_6_FLASH_DISPLAY3D_CONTEXT3D_AS
#if defined(__cplusplus)


#include "flash/events/EventDispatcher.h"
namespace flash
{
    namespace display3D
    {
        class IndexBuffer3D;
    }
}
namespace flash
{
    namespace display3D
    {
        class Program3D;
    }
}
namespace flash
{
    namespace geom
    {
        class Matrix3D;
    }
}
namespace flash
{
    namespace utils
    {
        class ByteArray;
    }
}
namespace flash
{
    namespace display3D
    {
        class VertexBuffer3D;
    }
}
namespace flash
{
    namespace display3D
    {
        namespace textures
        {
            class TextureBase;
        }
    }
}
namespace flash
{
    namespace geom
    {
        class Rectangle;
    }
}
namespace flash
{
    namespace display3D
    {
        namespace textures
        {
            class Texture;
        }
    }
}
namespace flash
{
    namespace display3D
    {
        namespace textures
        {
            class CubeTexture;
        }
    }
}
namespace flash
{
    namespace display
    {
        class BitmapData;
    }
}

using namespace flash::events;
using namespace flash::display3D;
using namespace flash::display3D;
using namespace flash::geom;
using namespace flash::utils;
using namespace flash::display3D;
using namespace flash::display3D::textures;
using namespace flash::geom;
using namespace flash::display3D::textures;
using namespace flash::display3D::textures;
using namespace flash::display;

namespace flash
{
    namespace display3D
    {
        class Context3D: public EventDispatcher
        {
        public:
            std::string  driverInfo();

        public:
            bool         enableErrorChecking();
        public:
            void         enableErrorChecking(bool toggle);

        public:
            void     clear(float red, float green, float blue, float alpha, float depth, unsigned int stencil, unsigned int mask);

        public:
            void     configureBackBuffer(int width, int height, int antiAlias, bool enableDepthAndStencil, bool wantsBestResolution);

        public:
            Context3D();

        public:
            CubeTexture *createCubeTexture(int size, std::string format, bool optimizeForRenderToTexture, int streamingLevels);

        public:
            IndexBuffer3D *createIndexBuffer(int numIndices);

        public:
            Program3D *createProgram();

        public:
            Texture *createTexture(int width, int height, std::string format, bool optimizeForRenderToTexture, int streamingLevels);

        public:
            VertexBuffer3D *createVertexBuffer(int numVertices, int data32PerVertex);

        public:
            void     dispose(bool recreate);

        public:
            void     drawToBitmapData(BitmapData *destination);

        public:
            void     drawTriangles(IndexBuffer3D *indexBuffer, int firstIndex, int numTriangles);

        public:
            void     present();

        public:
            void     setBlendFactors(std::string sourceFactor, std::string destinationFactor);

        public:
            void     setColorMask(bool red, bool green, bool blue, bool alpha);

        public:
            void     setCulling(std::string triangleFaceToCull);

        public:
            void     setDepthTest(bool depthMask, std::string passCompareMode);

        public:
            void     setProgram(Program3D *program);

        public:
            void     setProgramConstantsFromByteArray(std::string programType, int firstRegister, int numRegisters, ByteArray *data, unsigned int byteArrayOffset);

        public:
            void     setProgramConstantsFromMatrix(std::string programType, int firstRegister, Matrix3D *matrix, bool transposedMatrix);

        public:
            void     setProgramConstantsFromVector(std::string programType, int firstRegister, std::vector<float> *data, int numRegisters);

        public:
            void     setRenderToBackBuffer();

        public:
            void     setRenderToTexture(TextureBase *texture, bool enableDepthAndStencil, int antiAlias, int surfaceSelector);

        public:
            void     setSamplerStateAt(int sampler, std::string wrap, std::string filter, std::string mipfilter);

        public:
            void     setScissorRectangle(Rectangle *rectangle);

        public:
            void     setStencilActions(std::string triangleFace, std::string compareMode, std::string actionOnBothPass, std::string actionOnDepthFail, std::string actionOnDepthPassStencilFail);

        public:
            void     setStencilReferenceValue(unsigned int referenceValue, unsigned int readMask, unsigned int writeMask);

        public:
            void     setTextureAt(int sampler, TextureBase *texture);

        public:
            void     setVertexBufferAt(int index, VertexBuffer3D *buffer, int bufferOffset, std::string format);
        };
    }
}

#endif // FLEX11_6_FLASH_DISPLAY3D_CONTEXT3D_AS
#endif // __cplusplus

