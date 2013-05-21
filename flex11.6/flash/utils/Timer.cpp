

#include "Timer.h"
#include "flash/events/EventDispatcher.h"

    /**
     * Dispatched whenever it has completed the number of requests set by Timer.repeatCount.
     * @eventType   flash.events.TimerEvent.TIMER_COMPLETE
     */

using namespace flash::events;

namespace flash {
namespace utils {


        /**
         * The delay, in milliseconds, between timer
         * events. If you set the delay interval while
         * the timer is running, the timer will restart
         * at the same repeatCount iteration.
         * Note: A delay lower than 20 milliseconds is not recommended. Timer frequency
         * is limited to 60 frames per second, meaning a delay lower than 16.6 milliseconds causes runtime problems.
         * @langversion 3.0
         * @playerversion   Flash 9
         * @playerversion   Lite 4
         * @throws  Error Throws an exception if the delay specified is negative or not a finite number.
         */
        float Timer::delay()         ;

        /**
         * The total number of times the timer is set to run.
         * If the repeat count is set to 0, the timer continues forever 
         * or until the stop() method is invoked or the program stops.
         * If the repeat count is nonzero, the timer runs the specified number of times. 
         * If repeatCount is set to a total that is the same or less then currentCount
         * the timer stops and will not fire again.
         * @langversion 3.0
         * @playerversion   Flash 9
         * @playerversion   Lite 4
         */
        int Timer::repeatCount()      ;
        void Timer::repeatCount(int value)       ;

        /**
         * The total number of times the timer has fired since it started
         * at zero. If the timer has been reset, only the fires since
         * the reset are counted.
         * @langversion 3.0
         * @playerversion   Flash 9
         * @playerversion   Lite 4
         */
        int Timer::currentCount()      ;

        /**
         * The timer's current state; true if the timer is running, otherwise false.
         * @langversion 3.0
         * @playerversion   Flash 9
         * @playerversion   Lite 4
         */
        bool Timer::running()          ;

        void Timer::delay(float value)       ;

        /**
         * Starts the timer, if it is not already running.
         * @langversion 3.0
         * @playerversion   Flash 9
         * @playerversion   Lite 4
         */
        void Timer::start()       ;

        /**
         * Stops the timer, if it is running, and sets the currentCount property back to 0,
         * like the reset button of a stopwatch. Then, when start() is called,
         * the timer instance runs for the specified number of repetitions,
         * as set by the repeatCount value.
         * @langversion 3.0
         * @playerversion   Flash 9
         * @playerversion   Lite 4
         */
        void Timer::reset()       ;

        /**
         * Stops the timer. When start() is called after stop(), the timer
         * instance runs for the remaining number of repetitions, as set by the repeatCount property.
         * @langversion 3.0
         * @playerversion   Flash 9
         * @playerversion   Lite 4
         */
        void Timer::stop()       ;

        /**
         * Constructs a new Timer object with the specified delay
         * and repeatCount states.
         * 
         *   The timer does not start automatically; you must call the start() method
         * to start it.
         * @param   delay   The delay between timer events, in milliseconds. A delay lower than 20 milliseconds is not recommended. Timer frequency
         *   is limited to 60 frames per second, meaning a delay lower than 16.6 milliseconds causes runtime problems.
         * @param   repeatCount Specifies the number of repetitions.
         *   If zero, the timer repeats infinitely. 
         *   If nonzero, the timer runs the specified number of times and then stops.
         * @langversion 3.0
         * @playerversion   Flash 9
         * @playerversion   Lite 4
         * @throws  Error if the delay specified is negative or not a finite number
         */
        Timer::Timer(float delay, int repeatCount);
}
}

