

#include "Stage3D.h"
#include "flash/events/EventDispatcher.h"
#include "flash/display3D/Context3D.h"

using namespace flash::display3D;
using namespace flash::events;

namespace flash {
namespace display {


        Context3D* Stage3D::context3D()            ;

        float Stage3D::x()         ;
        void Stage3D::x(float value)       ;

        float Stage3D::y()         ;
        void Stage3D::y(float value)       ;

        bool Stage3D::visible()          ;
        void Stage3D::visible(bool value)       ;

        void Stage3D::requestContext3D(std::string context3DRenderMode, std::string profile)       ;

        Stage3D::Stage3D();
}
}

