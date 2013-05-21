

    /**
     * Dispatched when an error occurs and developer code doesn't detect and handle
     * the error.
     * @eventType   flash.events.UncaughtErrorEvent.UNCAUGHT_ERROR
     */


namespace flash {
namespace events {


        /**
         * Creates an UncaughtErrorEvents instance. Developer code shouldn't create
         * UncaughtErrorEvents instances directly. To access an UncaughtErrorEvents
         * object, use one of the following properties:
         * 
         *   LoaderInfo.uncaughtErrorEvents: to 
         * detect uncaught errors in code defined in the same SWF.Loader.uncaughtErrorEvents: to detect uncaught
         * errors in code defined in the SWF loaded by a Loader object.
         * @langversion 3.0
         * @playerversion   Flash 10.1
         * @playerversion   AIR 2
         */
        UncaughtErrorEvents::UncaughtErrorEvents();
}
}

