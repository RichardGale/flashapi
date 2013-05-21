

#include "MessageChannel.h"
#include "flash/events/EventDispatcher.h"

using namespace flash::events;

namespace flash {
namespace system {


        bool MessageChannel::messageAvailable()          ;

        std::string MessageChannel::state()         ;

        MessageChannel::MessageChannel();

        void MessageChannel::send(void* arg, int queueLimit)       ;

        void* MessageChannel::receive(bool blockUntilReceived)    ;

        void MessageChannel::addEventListener(std::string type, Function* listener, bool useCapture, int priority, bool useWeakReference)       ;

        void MessageChannel::removeEventListener(std::string type, Function* listener, bool useCapture)       ;

        void MessageChannel::close()       ;

        std::string MessageChannel::toString()         ;
}
}

