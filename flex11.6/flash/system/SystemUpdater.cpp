

#include "SystemUpdater.h"
#include "flash/events/EventDispatcher.h"
#include "adobe/utils/ProductManager.h"
#include "flash/events/Event.h"

    /**
     * Dispatched when an update of the player itself is cancelled by the user.
     * @eventType   flash.events.Event.CANCEL
     */

using namespace adobe::utils;
using namespace flash::events;

namespace flash {
namespace system {


        /**
         * Constructor.
         * @langversion 3.0
         * @playerversion   Flash 10.1
         */
        SystemUpdater::SystemUpdater();

        /**
         * Begins an update of a given type. Update types are one of the string constants defined
         * in the SystemUpdaterType class. 
         * Only one update is allowed at a time across all browsers.
         * After the update begins, listen for the events defined in this class. The following events
         * events indicate the end of an update and allow a new update or update attempt to proceed, 
         * as does calling the update() function:completecancelsecurityErrorioErrorstatus
         * @langversion 3.0
         * @playerversion   Flash 10.1
         */
        void SystemUpdater::update(std::string type)       ;

        /**
         * Cancels an active update.
         * @langversion 3.0
         * @playerversion   Flash 10.1
         */
        void SystemUpdater::cancel()       ;
}
}

