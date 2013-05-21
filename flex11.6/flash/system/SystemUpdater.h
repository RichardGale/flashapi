#if !defined(FLEX11_6_FLASH_SYSTEM_SYSTEMUPDATER_AS)
#define FLEX11_6_FLASH_SYSTEM_SYSTEMUPDATER_AS
#if defined(__cplusplus)


#include "flex11.6.h"
#include "flash/events/EventDispatcher.h"
namespace adobe
{
    namespace utils
    {
        class ProductManager;
    }
}
namespace flash
{
    namespace events
    {
        class Event;
    }
}

/**
 * Dispatched when an update of the player itself is cancelled by the user.
 * @eventType   flash.events.Event.CANCEL
 */
//[Event(name="cancel",type="flash.events.Event")]

/**
 * Dispatched when the update completes.
 * @eventType   flash.events.Event.COMPLETE
 */
//[Event(name="complete",type="flash.events.Event")]

/**
 * Dispatched upon encountering a security error.
 * @eventType   flash.events.SecurityErrorEvent.SECURITY_ERROR
 */
//[Event(name="securityError",type="flash.events.SecurityErrorEvent")]

/**
 * Dispatched when an I/O error occurs.
 * @eventType   flash.events.IOErrorEvent.IO_ERROR
 */
//[Event(name="ioError",type="flash.events.IOErrorEvent")]

/**
 * Dispatched to indicate download progress.
 * @eventType   flash.events.ProgressEvent.PROGRESS
 */
//[Event(name="progress",type="flash.events.ProgressEvent")]

/**
 * Dispatched when the update fails.
 * @eventType   flash.events.StatusEvent.STATUS
 */
//[Event(name="status",type="flash.events.StatusEvent")]

/**
 * Dispatched when an update begins.
 * @eventType   flash.events.Event.OPEN
 */
//[Event(name="open",type="flash.events.Event")]

using namespace adobe::utils;
using namespace flash::events;

namespace flash
{
    namespace system
    {
        /**
         * The SystemUpdater class allows you to update modules of the Flash Player,
         * such as the DRM module for Flash Access, as well as the Flash Player itself.
         * Available modules are listed in the SystemUpdaterType class.
         *
         *   <p class="- topic/p ">Flash Player identifies the need for a Flash-Access-module update by dispatching a NetStatusEvent event.
         * The event has a <codeph class="+ topic/ph pr-d/codeph ">code</codeph> property with a value of <codeph class="+ topic/ph pr-d/codeph ">"DRM.UpdateNeeded"</codeph>. For updates to the Flash Access
         * module, user consent is not required. Listen for the event and initiate the update by calling
         * <codeph class="+ topic/ph pr-d/codeph ">update("DRM")</codeph>.</p><p class="- topic/p ">Flash Player identifies the need for a player update by dispatching a StatusEvent event, with several
         * possible <codeph class="+ topic/ph pr-d/codeph ">code</codeph> property values (see the <codeph class="+ topic/ph pr-d/codeph ">status</codeph> event). For updates to the player,
         * user consent is required. Listen for the event and present the user with the option to update. The user must agree to the actual
         * update and initiate the update by, for example, clicking a button in the user interface. You can then
         * initiate the player update directly in ActionScript by calling <codeph class="+ topic/ph pr-d/codeph ">update("SYSTEM")</codeph>.</p><p class="- topic/p "><b class="+ topic/ph hi-d/b ">Note</b>: The SystemUpdater API is supported on all desktop platforms.</p>
         * @langversion 3.0
         * @playerversion   Flash 10.1
         */
        class SystemUpdater : public flash::events::EventDispatcher
        {
            /**
             * Constructor.
             * @langversion 3.0
             * @playerversion   Flash 10.1
             */
        public:
            SystemUpdater();

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
        public:
            void     update(std::string type);

            /**
             * Cancels an active update.
             * @langversion 3.0
             * @playerversion   Flash 10.1
             */
        public:
            void     cancel();
        };
    }
}

#endif // FLEX11_6_FLASH_SYSTEM_SYSTEMUPDATER_AS
#endif // __cplusplus

