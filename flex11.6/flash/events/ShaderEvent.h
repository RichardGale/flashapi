#if !defined(FLEX11_6_FLASH_EVENTS_SHADEREVENT_AS)
#define FLEX11_6_FLASH_EVENTS_SHADEREVENT_AS
#if defined(__cplusplus)


#include "flex11.6.h"
#include "flash/events/Event.h"
namespace flash
{
    namespace display
    {
        class BitmapData;
    }
}
namespace flash
{
    namespace utils
    {
        class ByteArray;
    }
}

/// @eventType  flash.events.ShaderEvent.COMPLETE
//[Event(name="complete",type="flash.events.ShaderEvent")]

using namespace flash::display;
using namespace flash::events;
using namespace flash::utils;

namespace flash
{
    namespace events
    {
        /**
         * A ShaderEvent is dispatched when a shader operation launched from
         * a ShaderJob finishes.
         * @langversion 3.0
         * @playerversion   Flash 10
         * @playerversion   AIR 1.5
         */
        class ShaderEvent : public flash::events::Event
        {
            /**
             * Defines the value of the type property of a complete event object.
             *
             *   This event has the following properties:PropertyValuebubblesfalsebitmapDataThe BitmapData object
             * containing the result of the operation that finished (or
             * null if the target wasn't a BitmapData object).byteArrayThe ByteArray object containing
             * the result of the operation that finished (or null if
             * the target wasn't a ByteArray object).cancelablefalse; there is
             * no default behavior to cancel.currentTargetThe object that is
             * actively processing the event object with an event listener.targetThe ShaderJob object reporting completion.vectorThe Vector.<Number> instance
             * containing the result of the operation that finished (or null if
             * the target wasn't a Vector.<Number> instance).
             * @langversion 3.0
             * @playerversion   Flash 10
             * @playerversion   AIR 1.5
             */
        public:
            static const std::string COMPLETE;

            /**
             * The BitmapData object that was passed to the ShaderJob.start() method.
             * If a ByteArray or Vector.<Number> was passed to the start() method
             * this property is null.
             * @langversion 3.0
             * @playerversion   Flash 10
             * @playerversion   AIR 1.5
             */
        public:
            flash::display::BitmapData *bitmapData();
        public:
            void         bitmapData(BitmapData *bmpData);

            /**
             * The ByteArray object that was passed to the ShaderJob.start() method.
             * If a BitmapData or Vector.<Number> object was passed to the start() method
             * this property is null.
             * @langversion 3.0
             * @playerversion   Flash 10
             * @playerversion   AIR 1.5
             */
        public:
            flash::utils::ByteArray *byteArray();
        public:
            void         byteArray(ByteArray *bArray);

            /**
             * The Vector.<Number> object that was passed to the ShaderJob.start() method.
             * If a BitmapData or ByteArray object was passed to the start() method
             * this property is null.
             * @langversion 3.0
             * @playerversion   Flash 10
             * @playerversion   AIR 1.5
             */
        public:
            std::vector<float> vector();
        public:
            void         vector(std::vector<float> v);

            /**
             * Creates a copy of the ShaderEvent object and sets the value of each property
             * to match that of the original.
             * @return  A new ShaderEvent object with property values that match the values of
             *   the original.
             * @langversion 3.0
             * @playerversion   Flash 10
             * @playerversion   AIR 1.5
             */
        public:
            flash::events::Event *clone();

            /**
             * Creates a ShaderEvent object to pass to event listeners.
             * @param   type    The type of the event, available in the
             *   type property.
             * @param   bubbles Determines whether the Event object participates
             *   in the bubbling stage of the event flow. The default value
             *   is false.
             * @param   cancelable  Determines whether the Event object can be
             *   canceled. The default value is false.
             * @param   bitmap  The BitmapData object containing the result of the
             *   operation that finished (or null if
             *   the target wasn't a BitmapData object).
             * @param   array   The ByteArray object containing the result of the
             *   operation that finished (or null if
             *   the target wasn't a ByteArray object).
             * @param   vector  The Vector.<Number> instance containing the result of the
             *   operation that finished (or null if
             *   the target wasn't a Vector.<Number> instance).
             * @langversion 3.0
             * @playerversion   Flash 10
             * @playerversion   AIR 1.5
             */
        public:
            ShaderEvent(std::string type, bool bubbles=false, bool cancelable=false, BitmapData *bitmap=NULL, ByteArray *array=NULL, std::vector<float> vector=std::vector<float>());

            /**
             * Returns a string that contains all the properties of the ShaderEvent object.
             * The string is in the following format:
             *
             *   [ShaderEvent type=value bubbles=value
             * cancelable=value eventPhase=value
             * bitmapData=value byteArray=value vector=value]
             * @return  A string that contains all the properties of the ShaderEvent object.
             * @langversion 3.0
             * @playerversion   Flash 10
             * @playerversion   AIR 1.5
             */
        public:
            std::string   toString();
        };
    }
}

#endif // FLEX11_6_FLASH_EVENTS_SHADEREVENT_AS
#endif // __cplusplus

