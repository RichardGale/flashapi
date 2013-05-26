

#include "StageCapture.h"
#include "flash/events/EventDispatcher.h"
#include "flash/geom/Rectangle.h"
#include "flash/display/BitmapData.h"

using namespace flash::display;
using namespace flash::events;
using namespace flash::geom;

namespace flash {
namespace automation {


        const std::string StageCapture::CURRENT  ;
        const std::string StageCapture::NEXT  ;
        const std::string StageCapture::MULTIPLE  ;
        const std::string StageCapture::RASTER  ;
        const std::string StageCapture::STAGE  ;
        const std::string StageCapture::SCREEN  ;

        void StageCapture::fileNameBase(std::string value)       ;
        std::string StageCapture::fileNameBase()         ;

        void StageCapture::clipRect(Rectangle* value)       ;
        Rectangle* StageCapture::clipRect()            ;

        void StageCapture::captureSource(std::string value)       ;
        std::string StageCapture::captureSource()         ;

        void StageCapture::capture(std::string type)       ;

        void StageCapture::cancel()       ;

        BitmapData* StageCapture::captureBitmapData()             ;

        StageCapture::StageCapture();
}
}

