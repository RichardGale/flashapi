

#include "Context3D.h"
#include "flash/events/EventDispatcher.h"
#include "flash/display3D/IndexBuffer3D.h"
#include "flash/display3D/Program3D.h"
#include "flash/geom/Matrix3D.h"
#include "flash/utils/ByteArray.h"
#include "flash/display3D/VertexBuffer3D.h"
#include "flash/display3D/textures/TextureBase.h"
#include "flash/geom/Rectangle.h"
#include "flash/display3D/textures/Texture.h"
#include "flash/display3D/textures/CubeTexture.h"
#include "flash/display/BitmapData.h"

using namespace flash::display;
using namespace flash::display3D;
using namespace flash::display3D::textures;
using namespace flash::events;
using namespace flash::geom;
using namespace flash::utils;

namespace flash {
namespace display3D {


        std::string Context3D::driverInfo()         ;

        bool Context3D::enableErrorChecking()          ;
        void Context3D::enableErrorChecking(bool toggle)       ;

        void Context3D::clear(float red, float green, float blue, float alpha, float depth, unsigned int stencil, unsigned int mask)       ;

        void Context3D::configureBackBuffer(int width, int height, int antiAlias, bool enableDepthAndStencil, bool wantsBestResolution)       ;

        Context3D::Context3D();

        CubeTexture* Context3D::createCubeTexture(int size, std::string format, bool optimizeForRenderToTexture, int streamingLevels)              ;

        IndexBuffer3D* Context3D::createIndexBuffer(int numIndices)                ;

        Program3D* Context3D::createProgram()            ;

        flash::display3D::textures::Texture* Context3D::createTexture(int width, int height, std::string format, bool optimizeForRenderToTexture, int streamingLevels)                                   ;

        VertexBuffer3D* Context3D::createVertexBuffer(int numVertices, int data32PerVertex)                 ;

        void Context3D::dispose(bool recreate)       ;

        void Context3D::drawToBitmapData(BitmapData* destination)       ;

        void Context3D::drawTriangles(IndexBuffer3D* indexBuffer, int firstIndex, int numTriangles)       ;

        void Context3D::present()       ;

        void Context3D::setBlendFactors(std::string sourceFactor, std::string destinationFactor)       ;

        void Context3D::setColorMask(bool red, bool green, bool blue, bool alpha)       ;

        void Context3D::setCulling(std::string triangleFaceToCull)       ;

        void Context3D::setDepthTest(bool depthMask, std::string passCompareMode)       ;

        void Context3D::setProgram(Program3D* program)       ;

        void Context3D::setProgramConstantsFromByteArray(std::string programType, int firstRegister, int numRegisters, ByteArray* data, unsigned int byteArrayOffset)       ;

        void Context3D::setProgramConstantsFromMatrix(std::string programType, int firstRegister, Matrix3D* matrix, bool transposedMatrix)       ;

        void Context3D::setProgramConstantsFromVector(std::string programType, int firstRegister, std::vector<float> data, int numRegisters)       ;

        void Context3D::setRenderToBackBuffer()       ;

        void Context3D::setRenderToTexture(TextureBase* texture, bool enableDepthAndStencil, int antiAlias, int surfaceSelector)       ;

        void Context3D::setSamplerStateAt(int sampler, std::string wrap, std::string filter, std::string mipfilter)       ;

        void Context3D::setScissorRectangle(Rectangle* rectangle)       ;

        void Context3D::setStencilActions(std::string triangleFace, std::string compareMode, std::string actionOnBothPass, std::string actionOnDepthFail, std::string actionOnDepthPassStencilFail)       ;

        void Context3D::setStencilReferenceValue(unsigned int referenceValue, unsigned int readMask, unsigned int writeMask)       ;

        void Context3D::setTextureAt(int sampler, TextureBase* texture)       ;

        void Context3D::setVertexBufferAt(int index, VertexBuffer3D* buffer, int bufferOffset, std::string format)       ;
}
}

