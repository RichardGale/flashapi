#if !defined(FLEX11_6_FLASH_EVENTS_EVENTDISPATCHER_AS)
#define FLEX11_6_FLASH_EVENTS_EVENTDISPATCHER_AS
#if defined(__cplusplus)


#include "flex11.6.h"
#include "flash/events/IEventDispatcher.h"
namespace flash
{
    namespace events
    {
        class Event;
    }
}

/**
 * [broadcast event] Dispatched when the Flash Player or AIR application operating
 * loses system focus and is becoming inactive.
 * @eventType   flash.events.Event.DEACTIVATE
 */
//[Event(name="deactivate",type="flash.events.Event")]

/**
 * [broadcast event] Dispatched when the Flash Player or AIR application gains
 * operating system focus and becomes active.
 * @eventType   flash.events.Event.ACTIVATE
 */
//[Event(name="activate",type="flash.events.Event")]

using namespace flash::events;

namespace flash
{
    namespace events
    {
        /**
         * The EventDispatcher class is the base class for all  classes that dispatch events.
         * <ph class="- topic/ph ">The EventDispatcher class implements the IEventDispatcher interface and is the base class for
         * the DisplayObject class. The EventDispatcher class allows any object on the display list to be
         * an event target and as such, to use the methods of the IEventDispatcher interface.</ph><p class="- topic/p ">Event targets are an important part of the Flash<sup class="+ topic/ph hi-d/sup ">  </sup> Player and
         * Adobe<sup class="+ topic/ph hi-d/sup ">  </sup> AIR<sup class="+ topic/ph hi-d/sup ">  </sup> event model. The event target serves
         * as the focal point for how events flow through the display list hierarchy.
         * When an event such as a mouse click or a keypress occurs, Flash Player or the AIR application dispatches an event
         * object into the event flow from the root of the display list. The event object then makes its
         * way through the display list until it reaches the event target, at which point it begins its
         * return trip through the display list. This round-trip journey to the event target is
         * conceptually divided into three phases: the capture phase comprises the journey from the
         * root to the last node before the event target's node, the target phase comprises only the
         * event target node, and the bubbling phase comprises any subsequent nodes encountered on
         * the return trip to the root of the display list.</p><p class="- topic/p ">In general, the easiest way for a user-defined class to gain event dispatching
         * capabilities is to extend EventDispatcher.  If this is impossible (that is, if the class is already extending
         * another class), you can instead implement the IEventDispatcher interface, create an EventDispatcher member,
         * and write simple hooks to route calls into the aggregated EventDispatcher.</p>
         *
         *   EXAMPLE:
         *
         *   The following example uses the classes <codeph class="+ topic/ph pr-d/codeph ">EventDispatcherExample</codeph> and
         * <codeph class="+ topic/ph pr-d/codeph ">CustomDispatcher</codeph>, a subclass of <codeph class="+ topic/ph pr-d/codeph ">EventDispatcher</codeph>, to show how a
         * custom event is created and dispatched.  The example carries out the following tasks:
         * <ol class="- topic/ol "><li class="- topic/li ">The constructor of <codeph class="+ topic/ph pr-d/codeph ">EventDispatcherExample</codeph> creates a local variable
         * <codeph class="+ topic/ph pr-d/codeph ">dispatcher</codeph> and assigns it to a new CustomDispatcher instance.</li><li class="- topic/li ">Inside <codeph class="+ topic/ph pr-d/codeph ">CustomDispatcher</codeph>, a string is set so that the event has
         * the name <codeph class="+ topic/ph pr-d/codeph ">action</codeph>, and the <codeph class="+ topic/ph pr-d/codeph ">doAction()</codeph> method is declared. When called, this method creates the <codeph class="+ topic/ph pr-d/codeph ">action</codeph>
         * event and dispatches it using <codeph class="+ topic/ph pr-d/codeph ">EventDispatcher.dispatchEvent()</codeph>.</li><li class="- topic/li ">The <codeph class="+ topic/ph pr-d/codeph ">dispatcher</codeph> property is then used to add the <codeph class="+ topic/ph pr-d/codeph ">action</codeph>
         * event listener and associated subscriber method <codeph class="+ topic/ph pr-d/codeph ">actionHandler()</codeph>, which simply
         * prints information about the event when it is dispatched.</li><li class="- topic/li ">The <codeph class="+ topic/ph pr-d/codeph ">doAction()</codeph> method is invoked, dispatching the <codeph class="+ topic/ph pr-d/codeph ">action</codeph>
         * event.</li></ol><codeblock xml:space="preserve" class="+ topic/pre pr-d/codeblock ">
         * package {
         * import flash.display.Sprite;
         * import flash.events.Event;
         *
         *   public class EventDispatcherExample extends Sprite {
         *
         *   public function EventDispatcherExample() {
         * var dispatcher:CustomDispatcher = new CustomDispatcher();
         * dispatcher.addEventListener(CustomDispatcher.ACTION, actionHandler);
         * dispatcher.doAction();
         * }
         *
         *   private function actionHandler(event:Event):void {
         * trace("actionHandler: " + event);
         * }
         * }
         * }
         *
         *   import flash.events.EventDispatcher;
         * import flash.events.Event;
         *
         *   class CustomDispatcher extends EventDispatcher {
         * public static var ACTION:String = "action";
         *
         *   public function doAction():void {
         * dispatchEvent(new Event(CustomDispatcher.ACTION));
         * }
         * }
         * </codeblock>
         * @langversion 3.0
         * @playerversion   Flash 9
         * @playerversion   Lite 4
         */
        class EventDispatcher : public Object, public flash::events::IEventDispatcher
        {
            /**
             * Aggregates an instance of the EventDispatcher class.
             *
             *   The EventDispatcher class is generally used as a base class, which means that most
             * developers do not need to use
             * this constructor function. However, advanced developers who are implementing
             * the IEventDispatcher interface need to use this constructor.
             * If you are unable to extend the EventDispatcher class and must
             * instead implement the IEventDispatcher interface, use this constructor to aggregate an instance of the EventDispatcher class.
             * @param   target  The target object for events dispatched to the EventDispatcher object.
             *   This parameter is used when the EventDispatcher instance is aggregated by a class that implements IEventDispatcher; it is necessary so that the containing object can be the target for events.
             *   Do not use this parameter in simple cases in which a class extends EventDispatcher.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            EventDispatcher(IEventDispatcher *target=NULL);

        public:
            std::string   toString();

            /**
             * Registers an event listener object with an EventDispatcher object so that the listener
             * receives notification of an event. You can register event listeners on all nodes in the
             * display list for a specific type of event, phase, and priority.After you successfully register an event listener, you cannot change its priority
             * through additional calls to addEventListener(). To change a listener's
             * priority, you must first call removeListener(). Then you can register the
             * listener again with the new priority level. Keep in mind that after the listener is registered, subsequent calls to
             * addEventListener() with a different type or
             * useCapture value result in the creation of a separate listener registration.
             * For example, if you first register a listener with useCapture set to
             * true, it listens only during the capture phase. If you call
             * addEventListener() again using the same listener object, but with
             * useCapture set to false, you have two separate listeners: one
             * that listens during the capture phase and another that listens during the target and
             * bubbling phases.You cannot register an event listener for only the target phase or the bubbling
             * phase. Those phases are coupled during registration because bubbling
             * applies only to the ancestors of the target node.If you no longer need an event listener, remove it by calling
             * removeEventListener(), or memory problems could result. Event listeners are not automatically
             * removed from memory because the garbage
             * collector does not remove the listener as long as the dispatching object exists (unless the useWeakReference
             * parameter is set to true).Copying an EventDispatcher instance does not copy the event listeners attached to it.
             * (If your newly created node needs an event listener, you must attach the listener after
             * creating the node.) However, if you move an EventDispatcher instance, the event listeners
             * attached to it move along with it.If the event listener is being registered on a node while an event is being processed
             * on this node, the event listener is not triggered during the current phase but can be
             * triggered during a later phase in the event flow, such as the bubbling phase.If an event listener is removed from a node while an event is being processed on the node,
             * it is still triggered by the current actions. After it is removed, the event listener is
             * never invoked again (unless registered again for future processing).
             * @param   type    The type of event.
             * @param   listener    The listener function that processes the event. This function must accept
             *   an Event object as its only parameter and must return nothing, as this example shows:
             *   <codeblock>
             *   function(evt:Event):void
             *   </codeblock>
             *   The function can have any name.
             * @param   useCapture  Determines whether the listener works in the capture phase or the
             *   target and bubbling phases. If useCapture is set to true,
             *   the listener processes the event only during the capture phase and not in the
             *   target or bubbling phase. If useCapture is false, the
             *   listener processes the event only during the target or bubbling phase. To listen for
             *   the event in all three phases, call addEventListener twice, once with
             *   useCapture set to true, then again with
             *   useCapture set to false.
             * @param   priority    The priority level of the event listener. The priority is designated by
             *   a signed 32-bit integer. The higher the number, the higher the priority. All listeners
             *   with priority n are processed before listeners of priority n-1. If two
             *   or more listeners share the same priority, they are processed in the order in which they
             *   were added. The default priority is 0.
             * @param   useWeakReference    Determines whether the reference to the listener is strong or
             *   weak. A strong reference (the default) prevents your listener from being garbage-collected.
             *   A weak reference does not. Class-level member functions are not subject to garbage
             *   collection, so you can set useWeakReference to true for
             *   class-level member functions without subjecting them to garbage collection. If you set
             *   useWeakReference to true for a listener that is a nested inner
             *   function, the function will be garbage-collected and no longer persistent. If you create
             *   references to the inner function (save it in another variable) then it is not
             *   garbage-collected and stays persistent.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             * @throws  ArgumentError The listener specified is not a function.
             */
        public:
            virtual void     addEventListener(std::string type, Function *listener, bool useCapture=false, int priority=0, bool useWeakReference=false);

            /**
             * Removes a listener from the EventDispatcher object. If there is no matching listener registered with the EventDispatcher object, a call to this method has no effect.
             * @param   type    The type of event.
             * @param   listener    The listener object to remove.
             * @param   useCapture  Specifies whether the listener was registered for the capture phase or the
             *   target and bubbling phases. If the listener was registered for both the capture phase and the
             *   target and bubbling phases, two calls to removeEventListener() are required
             *   to remove both, one call with useCapture() set to true, and another
             *   call with useCapture() set to false.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            virtual void     removeEventListener(std::string type, Function *listener, bool useCapture=false);

            /**
             * Dispatches an event into the event flow. The event target is the EventDispatcher
             * object upon which the dispatchEvent() method is called.
             * @param   event   The Event object that is dispatched into the event flow.
             *   If the event is being redispatched, a clone of the event is created automatically.
             *   After an event is dispatched, its target property cannot be changed, so you
             *   must create a new copy of the event for redispatching to work.
             * @return  A value of true if the event was successfully dispatched. A value of false indicates failure or that preventDefault() was called
             *   on the event.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             * @throws  Error The event dispatch recursion limit has been reached.
             */
        public:
            virtual bool  dispatchEvent(Event *event);

            /**
             * Checks whether the EventDispatcher object has any listeners registered for a specific type
             * of event. This allows you to determine where an EventDispatcher object has altered
             * handling of an event type in the event flow hierarchy. To determine whether a specific
             * event type actually triggers an event listener, use willTrigger().
             *
             *   The difference between hasEventListener() and willTrigger()
             * is that hasEventListener() examines only the object to
             * which it belongs, whereas willTrigger() examines the entire
             * event flow for the event specified by the type parameter.
             *
             *   When hasEventListener() is called from a LoaderInfo object, only the
             * listeners that the caller can access are considered.
             * @param   type    The type of event.
             * @return  A value of true if a listener of the specified type is registered;
             *   false otherwise.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            virtual bool  hasEventListener(std::string type);

            /**
             * Checks whether an event listener is registered with this EventDispatcher object or any of
             * its ancestors for the specified event type. This method returns true if an
             * event listener is triggered during any phase of the event flow when an event of the
             * specified type is dispatched to this EventDispatcher object or any of its descendants.
             *
             *   The difference between the hasEventListener() and the willTrigger()
             * methods is that hasEventListener() examines only the object to which it belongs,
             * whereas the willTrigger() method examines the entire event flow for the event specified by the
             * type parameter. When willTrigger() is called from a LoaderInfo object, only the
             * listeners that the caller can access are considered.
             * @param   type    The type of event.
             * @return  A value of true if a listener of the specified type will be triggered; false otherwise.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            virtual bool  willTrigger(std::string type);
        };
    }
}

#endif // FLEX11_6_FLASH_EVENTS_EVENTDISPATCHER_AS
#endif // __cplusplus

