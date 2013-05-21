

#include "ShaderEvent.h"
#include "flash/events/Event.h"
#include "flash/display/BitmapData.h"
#include "flash/utils/ByteArray.h"

    /// @eventType  flash.events.ShaderEvent.COMPLETE

using namespace flash::display;
using namespace flash::events;
using namespace flash::utils;

namespace flash {
namespace events {


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
        const std::string ShaderEvent::COMPLETE="complete";

        /**
         * The BitmapData object that was passed to the ShaderJob.start() method. 
         * If a ByteArray or Vector.<Number> was passed to the start() method 
         * this property is null.
         * @langversion 3.0
         * @playerversion   Flash 10
         * @playerversion   AIR 1.5
         */
        flash::display::BitmapData* ShaderEvent::bitmapData()                           ;
        void ShaderEvent::bitmapData(BitmapData* bmpData)       ;

        /**
         * The ByteArray object that was passed to the ShaderJob.start() method.
         * If a BitmapData or Vector.<Number> object was passed to the start() method 
         * this property is null.
         * @langversion 3.0
         * @playerversion   Flash 10
         * @playerversion   AIR 1.5
         */
        flash::utils::ByteArray* ShaderEvent::byteArray()                        ;
        void ShaderEvent::byteArray(ByteArray* bArray)       ;

        /**
         * The Vector.<Number> object that was passed to the ShaderJob.start() method. 
         * If a BitmapData or ByteArray object was passed to the start() method 
         * this property is null.
         * @langversion 3.0
         * @playerversion   Flash 10
         * @playerversion   AIR 1.5
         */
        std::vector<float> ShaderEvent::vector()                  ;
        void ShaderEvent::vector(std::vector<float> v)       ;

        /**
         * Creates a copy of the ShaderEvent object and sets the value of each property
         * to match that of the original.
         * @return  A new ShaderEvent object with property values that match the values of
         *   the original.
         * @langversion 3.0
         * @playerversion   Flash 10
         * @playerversion   AIR 1.5
         */
        flash::events::Event* ShaderEvent::clone()                     ;

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
        ShaderEvent::ShaderEvent(std::string type, bool bubbles, bool cancelable, BitmapData* bitmap, ByteArray* array, std::vector<float> vector);

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
        std::string ShaderEvent::toString()         ;
}
}

