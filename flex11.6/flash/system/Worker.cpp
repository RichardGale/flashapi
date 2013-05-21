

#include "Worker.h"
#include "flash/events/EventDispatcher.h"
#include "flash/system/Worker.h"
#include "flash/system/MessageChannel.h"
#include "flash/utils/ByteArray.h"

using namespace flash::events;
using namespace flash::system;
using namespace flash::utils;

namespace flash {
namespace system {


        bool Worker::isSupported()          ;

        Worker* Worker::current()         ;

        bool Worker::isPrimordial()          ;

        std::string Worker::state()         ;

        MessageChannel* Worker::createMessageChannel(Worker* receiver)                 ;

        void Worker::start()       ;

        void Worker::setSharedProperty(std::string key, void* value)       ;

        void* Worker::getSharedProperty(std::string key)    ;

        void Worker::addEventListener(std::string type, Function* listener, bool useCapture, int priority, bool useWeakReference)       ;

        void Worker::removeEventListener(std::string type, Function* listener, bool useCapture)       ;

        bool Worker::terminate()          ;

        Worker::Worker();
}
}

