

#include "IEventDispatcher.h"
#include "flash/events/Event.h"

    /**
     * The IEventDispatcher interface defines methods for adding or removing event listeners, checks 
     * whether specific types of event listeners are registered, and dispatches events.
     * 
     *   <p class="- topic/p ">Event targets are an important part of the Flash<sup class="+ topic/ph hi-d/sup ">  </sup> Player and Adobe AIR event model. The event target 
     * serves as the focal point for how events flow through the display list hierarchy. 
     * When an event such as a mouse click or a keypress occurs, an event 
     * object is dispatched into the event flow from the root of the display list. The event object makes a
     * round-trip journey to the event target, which is conceptually divided into three phases: 
     * the capture phase includes the journey from the root to the last node before the event 
     * target's node; the target phase includes only the event target node; and the bubbling 
     * phase includes any subsequent nodes encountered on the return trip to the root of the 
     * display list.</p><p class="- topic/p ">In general, the easiest way for a user-defined class to gain event dispatching
     * capabilities is to extend EventDispatcher. If this is impossible (that is, if the class is
     * already extending another class), you can instead implement the IEventDispatcher interface,
     * create an EventDispatcher member, and write simple hooks to route calls into the aggregated 
     * EventDispatcher.</p>
     * 
     *   EXAMPLE:
     * 
     *   The following example uses the IEventDispatcherExample and
     * DecoratedDispatcher sample classes to show how the IEventDispatcher class can be
     * implemented and used.  The example accomplishes this by implementing each method of 
     * DecoratedDispatcher in the same manner as in EventDispatcher.
     * Within the constructor for IEventDispatcherExample, a new instance (named <codeph class="+ topic/ph pr-d/codeph ">decorDispatcher</codeph>) of the DecoratedDispatcher class is constructed
     * and the  <codeph class="+ topic/ph pr-d/codeph ">decorDispatcher</codeph> variable is used to call
     * <codeph class="+ topic/ph pr-d/codeph ">addEventListener()</codeph> with the custom event <codeph class="+ topic/ph pr-d/codeph ">doSomething</codeph>, which is
     * then handled by <codeph class="+ topic/ph pr-d/codeph ">didSomething()</codeph>, which prints a line of text using
     * <codeph class="+ topic/ph pr-d/codeph ">trace()</codeph>.
     * <codeblock xml:space="preserve" class="+ topic/pre pr-d/codeblock "> 
     * package {
     * import flash.events.Event;
     * import flash.display.Sprite;
     * 
     *   public class IEventDispatcherExample extends Sprite {
     * public function IEventDispatcherExample() {
     * var decorDispatcher:DecoratedDispatcher = new DecoratedDispatcher();
     * decorDispatcher.addEventListener("doSomething", didSomething);
     * decorDispatcher.dispatchEvent(new Event("doSomething"));
     * }
     * 
     *   public function didSomething(evt:Event):void {
     * trace("&gt;&gt; didSomething");
     * }
     * }
     * }
     * 
     *   import flash.events.IEventDispatcher;
     * import flash.events.EventDispatcher;
     * import flash.events.Event;
     * 
     *   class DecoratedDispatcher implements IEventDispatcher {       
     * private var dispatcher:EventDispatcher;
     * 
     *   public function DecoratedDispatcher() {
     * dispatcher = new EventDispatcher(this);
     * }
     * 
     *   public function addEventListener(type:String, listener:Function, useCapture:Boolean = false, priority:int = 0, useWeakReference:Boolean = false):void{
     * dispatcher.addEventListener(type, listener, useCapture, priority);
     * }
     * 
     *   public function dispatchEvent(evt:Event):Boolean{
     * return dispatcher.dispatchEvent(evt);
     * }
     * 
     *   public function hasEventListener(type:String):Boolean{
     * return dispatcher.hasEventListener(type);
     * }
     * 
     *   public function removeEventListener(type:String, listener:Function, useCapture:Boolean = false):void{
     * dispatcher.removeEventListener(type, listener, useCapture);
     * }
     * 
     *   public function willTrigger(type:String):Boolean {
     * return dispatcher.willTrigger(type);
     * }
     * }
     * </codeblock>
     * @langversion 3.0
     * @playerversion   Flash 9
     * @playerversion   Lite 4
     */
