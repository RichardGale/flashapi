#if !defined(FLEX11_6_FLASH_EVENTS_EVENT_AS)
#define FLEX11_6_FLASH_EVENTS_EVENT_AS
#if defined(__cplusplus)


#include "flex11.6.h"


/// @eventType  flash.events.Event.ACTIVATE
//[Event(name="activate",type="flash.events.Event")]

/// @eventType  flash.events.Event.ADDED_TO_STAGE
//[Event(name="addedToStage",type="flash.events.Event")]

/// @eventType  flash.events.Event.ADDED
//[Event(name="added",type="flash.events.Event")]

/// @eventType  flash.events.Event.CANCEL
//[Event(name="cancel",type="flash.events.Event")]

/// @eventType  flash.events.Event.CHANGE
//[Event(name="change",type="flash.events.Event")]

/// @eventType  flash.events.Event.CLEAR
//[Event(name="copy",type="flash.events.Event")]

/// @eventType  flash.events.Event.CLOSE
//[Event(name="close",type="flash.events.Event")]

/// @eventType  flash.events.Event.CLOSING
//[Event(name="closing",type="flash.events.Event")]

/// @eventType  flash.events.Event.COMPLETE
//[Event(name="complete",type="flash.events.Event")]

/// @eventType  flash.events.Event.CONNECT
//[Event(name="connect",type="flash.events.Event")]

/// @eventType  flash.events.Event.COPY
//[Event(name="copy",type="flash.events.Event")]

/// @eventType  flash.events.Event.CUT
//[Event(name="cut",type="flash.events.Event")]

/// @eventType  flash.events.Event.DEACTIVATE
//[Event(name="deactivate",type="flash.events.Event")]

/// @eventType  flash.events.Event.DISPLAYING
//[Event(name="displaying",type="flash.events.Event")]

/// @eventType  flash.events.Event.ENTER_FRAME
//[Event(name="enterFrame",type="flash.events.Event")]

/// @eventType  flash.events.Event.EXITING
//[Event(name="exiting",type="flash.events.Event")]

/// @eventType  flash.events.Event.EXIT_FRAME
//[Event(name="exitFrame",type="flash.events.Event")]

/// @eventType  flash.events.Event.FRAME_CONSTRUCTED
//[Event(name="frameConstructed",type="flash.events.Event")]

/// @eventType  flash.events.Event.FULLSCREEN
//[Event(name="fullScreen",type="flash.events.Event")]

/// @eventType  flash.events.Event.HTML_BOUNDS_CHANGE
//[Event(name="htmlBoundsChange",type="flash.events.Event")]

/// @eventType  flash.events.Event.HTML_DOM_INITIALIZE
//[Event(name="htmlDOMInitialize",type="flash.events.Event")]

/// @eventType  flash.events.Event.HTML_RENDER
//[Event(name="htmlRender",type="flash.events.Event")]

/// @eventType  flash.events.Event.ID3
//[Event(name="id3",type="flash.events.Event")]

/// @eventType  flash.events.Event.INIT
//[Event(name="init",type="flash.events.Event")]

/// @eventType  flash.events.Event.LOCATION_CHANGE
//[Event(name="locationChange",type="flash.events.Event")]

/// @eventType  flash.events.Event.MOUSE_LEAVE
//[Event(name="mouseLeave",type="flash.events.Event")]

/// @eventType  flash.events.Event.NETWORK_CHANGE
//[Event(name="networkChange",type="flash.events.Event")]

/// @eventType  flash.events.Event.OPEN
//[Event(name="open",type="flash.events.Event")]

/// @eventType  flash.events.Event.PASTE
//[Event(name="paste",type="flash.events.Event")]

/// @eventType  flash.events.Event.PREPARING
//[Event(name="flash.events.Event",type="flash.events.Event")]

/// @eventType  flash.events.Event.REMOVED_FROM_STAGE
//[Event(name="removedFromStage",type="flash.events.Event")]

/// @eventType  flash.events.Event.REMOVED
//[Event(name="removed",type="flash.events.Event")]

/// @eventType  flash.events.Event.RENDER
//[Event(name="render",type="flash.events.Event")]

/// @eventType  flash.events.Event.RESIZE
//[Event(name="resize",type="flash.events.Event")]

/// @eventType  flash.events.Event.SCROLL
//[Event(name="scroll",type="flash.events.Event")]

/// @eventType  flash.events.Event.SELECT_ALL
//[Event(name="selectAll",type="flash.events.Event")]

/// @eventType  flash.events.Event.SELECT
//[Event(name="select",type="flash.events.Event")]

/// @eventType  flash.events.Event.SOUND_COMPLETE
//[Event(name="soundComplete",type="flash.events.Event")]

/// @eventType  flash.events.Event.STANDARD_ERROR_CLOSE
//[Event(name="flash.events.Event",type="flash.events.Event")]

/// @eventType  flash.events.Event.STANDARD_INPUT_CLOSE
//[Event(name="flash.events.Event",type="flash.events.Event")]

/// @eventType  flash.events.Event.STANDARD_OUTPUT_CLOSE
//[Event(name="flash.events.Event",type="flash.events.Event")]

/// @eventType  flash.events.Event.TAB_CHILDREN_CHANGE
//[Event(name="tabChildrenChange",type="flash.events.Event")]

/// @eventType  flash.events.Event.TAB_ENABLED_CHANGE
//[Event(name="tabEnabledChange",type="flash.events.Event")]

/// @eventType  flash.events.Event.TAB_INDEX_CHANGE
//[Event(name="tabIndexChange",type="flash.events.Event")]

/// @eventType  flash.events.Event.TEXT_INTERACTION_MODE_CHANGE
//[Event(name="textInteractionModeChange",type="flash.events.Event")]

/// @eventType  flash.events.Event.UNLOAD
//[Event(name="unload",type="flash.events.Event")]

/// @eventType  flash.events.Event.USER_IDLE
//[Event(name="userIdle",type="flash.events.Event")]


//[Event(name="userIdle",type="flash.events.Event")]


namespace flash
{
    namespace events
    {
        /// @eventType  flash.events.Event.USER_PRESENT


        /**
         * The Event class is used as the base class for the creation of Event objects,
         * which are passed as parameters to event listeners when an event occurs.
         *
         *   <p class="- topic/p ">The properties of the Event class carry basic information about an event, such as
         * the event's type or whether the event's default behavior can be canceled. For many
         * events, such as the events represented by the Event class constants, this basic information
         * is sufficient. Other events, however, may require more detailed information. <ph class="- topic/ph ">Events associated
         * with a mouse click, for example, need to include additional information about the location of
         * the click event and whether any keys were pressed during the click event.  You can pass such additional
         * information to event listeners by extending the Event class, which is what
         * the MouseEvent class does. ActionScript 3.0</ph> API defines several Event subclasses for common
         * events that require additional information. Events associated with each of the Event
         * subclasses are described in the documentation for each class.</p><p class="- topic/p ">The methods of the Event class can be used in event listener functions to affect the
         * behavior of the event object. Some events have an associated default behavior.<ph class="- topic/ph "> For example,
         * the <codeph class="+ topic/ph pr-d/codeph ">doubleClick</codeph> event has an associated default behavior that highlights
         * the word under the mouse pointer at the time of the event.</ph>
         * Your event listener can cancel this
         * behavior by calling the <codeph class="+ topic/ph pr-d/codeph ">preventDefault()</codeph> method.
         * <ph class="- topic/ph ">You can also make the current
         * event listener the last one to process an event by calling the <codeph class="+ topic/ph pr-d/codeph ">stopPropagation()</codeph>
         * or <codeph class="+ topic/ph pr-d/codeph ">stopImmediatePropagation()</codeph> method.</ph></p><p class="- topic/p ">Other sources of information include:</p><ul class="- topic/ul "><li class="- topic/li ">A useful description about the timing of events, code execution, and rendering at runtime in Ted Patrick's blog entry:
         * <xref href="http://www.onflex.org/ted/2005/07/flash-player-mental-model-elastic.php" scope="external" class="- topic/xref ">Flash Player Mental Model - The Elastic Racetrack</xref>.</li><li class="- topic/li ">A blog entry by Johannes Tacskovics about the timing of frame events, such as ENTER_FRAME, EXIT_FRAME:
         * <xref href="http://blog.johannest.com/2009/06/15/the-movieclip-life-cycle-revisited-from-event-added-to-event-removed_from_stage/" scope="external" class="- topic/xref ">The MovieClip Lifecycle</xref>.</li><li class="- topic/li ">An article by Trevor McCauley about the order of ActionScript operations:
         * <xref href="http://www.senocular.com/flash/tutorials/orderofoperations/" scope="external" class="- topic/xref ">Order of Operations in ActionScript</xref>.</li><li class="- topic/li ">A blog entry by Matt Przybylski on creating custom events:
         * <xref href="http://evolve.reintroducing.com/2007/10/23/as3/as3-custom-events/" scope="external" class="- topic/xref ">AS3: Custom Events</xref>.</li></ul>
         *
         *   EXAMPLE:
         *
         *   The following example uses the <codeph class="+ topic/ph pr-d/codeph ">EventExample</codeph> class and the
         * <codeph class="+ topic/ph pr-d/codeph ">Square</codeph> custom class to demonstrate how to manage event bubbling.
         * <codeblock xml:space="preserve" class="+ topic/pre pr-d/codeblock ">
         * package {
         * import flash.display.Sprite;
         * import flash.events.Event;
         * import flash.events.MouseEvent;
         *
         *   public class EventExample extends Sprite {
         *
         *   public function EventExample() {
         * var square_0:Square = new Square(300, 0x336633);
         * addChild(square_0);
         *
         *   var square_1:Square = new Square(250, 0x669966);
         * square_0.addChild(square_1);
         *
         *   var square_2:Square = new Square(200, 0x66CC66);
         * square_1.addChild(square_2);
         *
         *   var square_3:Square = new Square(150, 0xAA0000);
         * square_3.shouldBubble = false;
         * square_2.addChild(square_3);
         *
         *   var square_4:Square = new Square(100, 0x66FF66);
         * square_3.addChild(square_4);
         *
         *   var square_5:Square = new Square(50, 0xCC0000);
         * square_5.shouldBubble = false;
         * square_4.addChild(square_5);
         *
         *   this.addEventListener(MouseEvent.CLICK, clickHandler);
         * }
         *
         *   private function clickHandler(e:Event):void {
         * trace("&gt;&gt; stage: " + e.type + " event from " + e.target.name + " called on " + this.name);
         * trace("&gt;&gt; --------------------------------------------");
         * }
         * }
         * }
         *
         *   import flash.display.Sprite;
         * import flash.events.Event;
         * import flash.events.MouseEvent;
         *
         *   class Square extends Sprite {
         * private var sideLen:int;
         * private var color:Number;
         * public var shouldBubble:Boolean = true;
         *
         *   public function Square(sideLen:int, color:Number) {
         * this.sideLen = sideLen;
         * this.color = color;
         * init();
         * draw();
         * }
         *
         *   private function init():void {
         * buttonMode = true;
         * this.addEventListener(MouseEvent.CLICK, firstClickHandler);
         * this.addEventListener(MouseEvent.CLICK, secondClickHandler);
         * this.addEventListener(MouseEvent.CLICK, thirdClickHandler);
         * }
         *
         *   private function draw():void {
         * this.graphics.beginFill(color);
         * this.graphics.drawRect(0, 0, sideLen, sideLen);
         * }
         *
         *   private function firstClickHandler(e:Event):void {
         * trace("&gt;&gt; 1e: " + e.type + " event from " + e.target.name + " called on " + this.name);
         * if(!shouldBubble) {
         * e.stopPropagation();
         * }
         * }
         *
         *   private function secondClickHandler(e:Event):void {
         * trace("&gt;&gt; 2e: " + e.type + " event from " + e.target.name + " called on " + this.name);
         * if(!shouldBubble) {
         * e.stopImmediatePropagation();
         * trace("&gt;&gt; --------------------------------------------");
         * }
         * }
         *
         *   private function thirdClickHandler(e:Event):void {
         * trace("&gt;&gt; 3e: " + e.type + " event from " + e.target.name + " called on " + this.name);
         * }
         * }
         * </codeblock>
         *
         *   EXAMPLE:
         *
         *   The following example creates an interactive demonstration of
         * the difference between <codeph class="+ topic/ph pr-d/codeph ">ADDED</codeph> and <codeph class="+ topic/ph pr-d/codeph ">ADDED_TO_STAGE</codeph> events,
         * as well as the difference between <codeph class="+ topic/ph pr-d/codeph ">REMOVED</codeph> and <codeph class="+ topic/ph pr-d/codeph ">REMOVED_FROM_STAGE</codeph>
         * events. Clicking a sprite will remove it from the stage as well as everything nested within it.
         * For example, clicking the largest sprite will cause a <codeph class="+ topic/ph pr-d/codeph ">REMOVED</codeph> event
         * as well as three <codeph class="+ topic/ph pr-d/codeph ">REMOVED_FROM_STAGE</codeph> events to fire.
         * <codeblock xml:space="preserve" class="+ topic/pre pr-d/codeblock ">
         * package {
         * import flash.display.Sprite;
         * import flash.events.*;
         *
         *   public class EventExample2 extends Sprite {
         * public function EventExample2():void {
         * var parentSprite:Sprite = createSprite("parentSprite",200);
         * var childSprite:Sprite = createSprite("childSprite",100);
         * var childOfChildSprite:Sprite = createSprite("childOfChildSprite",50);
         *
         *   trace(":: Adding to Stage ::");
         * this.addChild(parentSprite);
         * trace(":: Adding to Stage ::");
         * parentSprite.addChild(childSprite);
         * trace(":: Adding to Stage ::");
         * childSprite.addChild(childOfChildSprite);
         * }
         * private function createSprite(name:String,size:uint):Sprite {
         * trace(":: Creating Sprite ::");
         * var newSprite:Sprite = new Sprite();
         * newSprite.name = name;
         * newSprite.graphics.beginFill(0xFFFFFF * Math.random(),1);
         * newSprite.graphics.drawRect(0,0,size,size);
         * newSprite.graphics.endFill();
         * newSprite.addEventListener(Event.ADDED, spriteAdded);
         * newSprite.addEventListener(Event.ADDED_TO_STAGE, spriteAddedToStage);
         * newSprite.addEventListener(Event.REMOVED, spriteRemoved);
         * newSprite.addEventListener(Event.REMOVED_FROM_STAGE, spriteRemovedFromStage);
         * newSprite.addEventListener(MouseEvent.CLICK, remove);
         * return newSprite;
         * }
         * private function remove(event:Event) {
         * if(event.target == event.currentTarget) {
         * trace(":: Removing Clicked Sprite ::");
         * var target:Sprite = Sprite(event.target);
         * target.parent.removeChild(target);
         * }
         * }
         * private function spriteRemovedFromStage(event:Event):void {
         * trace("REMOVED_FROM_STAGE: " + event.target.name + " : " + event.currentTarget.name);
         * }
         * private function spriteRemoved(event:Event):void {
         * trace("REMOVED: " + event.target.name + " from " + event.currentTarget.name);
         * }
         * private function spriteAddedToStage(event:Event):void {
         * trace("ADDED_TO_STAGE: " + event.target.name + " : " + event.currentTarget.name);
         * }
         * private function spriteAdded(event:Event):void {
         * trace("ADDED: " + event.target.name + " within " + event.currentTarget.name);
         * }
         * }
         * }
         * </codeblock>
         * @langversion 3.0
         * @playerversion   Flash 9
         * @playerversion   Lite 4
         */
        class Event : public Object
        {
            /**
             * The ACTIVATE constant defines the value of the type property of an activate event object.
             * Note: This event has neither a "capture phase" nor a "bubble phase",
             * which means that event listeners must be added directly to any potential targets,
             * whether the target is on the display list or not.AIR for TV devices never automatically dispatch this event. You can, however, dispatch it manually.This event has the following properties:PropertyValuebubblesfalsecancelablefalse; there is no default behavior to cancel.currentTargetThe object that is actively processing the Event
             * object with an event listener.targetAny DisplayObject instance with a listener registered for the activate event.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            static const std::string ACTIVATE;

            /**
             * The Event.ADDED constant defines the value of the type property of
             * an added event object.
             *
             *   This event has the following properties:PropertyValuebubblestruecancelablefalse; there is no default behavior to cancel.currentTargetThe object that is actively processing the Event
             * object with an event listener.targetThe DisplayObject instance being added to the display list.
             * The target is not always the object in the display list
             * that registered the event listener. Use the currentTarget
             * property to access the object in the display list that is currently processing the event.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            static const std::string ADDED;

            /**
             * The Event.ADDED_TO_STAGE constant defines the value of the type
             * property of an addedToStage event object.
             *
             *   This event has the following properties:PropertyValuebubblesfalsecancelablefalse; there is no default behavior to cancel.currentTargetThe object that is actively processing the Event
             * object with an event listener.targetThe DisplayObject instance being added to the on stage display list,
             * either directly or through the addition of a sub tree in which the DisplayObject instance is contained.
             * If the DisplayObject instance is being directly added, the added event occurs before this event.
             * @langversion 3.0
             * @playerversion   Flash 9.0.28.0
             * @playerversion   Lite 4
             */
        public:
            static const std::string ADDED_TO_STAGE;

            /**
             * The Event.CANCEL constant defines the value of the type property of a cancel event object.
             * This event has the following properties:PropertyValuebubblesfalsecancelablefalse; there is no default behavior to cancel.currentTargetThe object that is actively processing the Event
             * object with an event listener.targetA reference to the object on which the operation is canceled.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             * @internal    <code>ProductManager</code> pulled from table
             */
        public:
            static const std::string CANCEL;

            /**
             * The Event.CHANGE constant defines the value of the type property of a change event object.
             *
             *   This event has the following properties:PropertyValuebubblestruecancelablefalse; there is no default behavior to cancel.currentTargetThe object that is actively processing the Event
             * object with an event listener.targetThe object that has had its value modified.
             * The target is not always the object in the display list
             * that registered the event listener. Use the currentTarget
             * property to access the object in the display list that is currently processing the event.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            static const std::string CHANGE;

            /**
             * The Event.CLEAR constant defines the value of the type property
             * of a clear event object.
             * This event has the following properties:PropertyValuebubblesfalsecancelablefalse; there is no default behavior to cancel.currentTargetThe object that is actively processing the Event
             * object with an event listener.targetAny InteractiveObject instance with a listener registered for the clear event.Note: TextField objects do not dispatch clear, copy, cut, paste,
             * or selectAll events. TextField objects always include Cut, Copy, Paste, Clear, and Select All commands in the context menu.
             * You cannot remove these commands from the context menu for TextField objects. For TextField objects, selecting these commands
             * (or their keyboard equivalents) does not generate clear, copy, cut, paste,
             * or selectAll events. However, other classes that extend the InteractiveObject class, including components built
             * using the Flash Text Engine (FTE), will dispatch these events in response to user actions such as keyboard shortcuts and context menus.
             * @langversion 3.0
             * @playerversion   Flash 10
             * @playerversion   AIR 1.5
             * @playerversion   Lite 4
             */
        public:
            static const std::string CLEAR;

            /**
             * The Event.CLOSE constant defines the value of the type property of a close event object.
             *
             *   This event has the following properties:PropertyValuebubblesfalsecancelablefalse; there is no default behavior to cancel.currentTargetThe object that is actively processing the Event
             * object with an event listener.targetThe object whose connection has been closed.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            static const std::string CLOSE;

            /**
             * The Event.COMPLETE constant defines the value of the type property of a complete event object.
             *
             *   This event has the following properties:PropertyValuebubblesfalsecancelablefalse; there is no default behavior to cancel.currentTargetThe object that is actively processing the Event
             * object with an event listener.targetThe network object that has completed loading.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            static const std::string COMPLETE;

            /**
             * The Event.CONNECT constant defines the value of the type property of a connect event object.
             *
             *   This event has the following properties:PropertyValuebubblesfalsecancelablefalse; there is no default behavior to cancel.currentTargetThe object that is actively processing the Event
             * object with an event listener.targetThe Socket or XMLSocket object that has established a network connection.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            static const std::string CONNECT;

            /**
             * Defines the value of the type property of a copy event object.
             * This event has the following properties:PropertyValuebubblesfalsecancelablefalse; there is no default behavior to cancel.currentTargetThe object that is actively processing the Event
             * object with an event listener.targetAny InteractiveObject instance with a listener registered for the copy event.Note: TextField objects do not dispatch clear, copy, cut, paste,
             * or selectAll events. TextField objects always include Cut, Copy, Paste, Clear, and Select All commands in the context menu.
             * You cannot remove these commands from the context menu for TextField objects. For TextField objects, selecting these commands
             * (or their keyboard equivalents) does not generate clear, copy, cut, paste,
             * or selectAll events. However, other classes that extend the InteractiveObject class, including components built
             * using the Flash Text Engine (FTE), will dispatch these events in response to user actions such as keyboard shortcuts and context menus.
             * @langversion 3.0
             * @playerversion   Flash 10
             * @playerversion   AIR 1.5
             * @playerversion   Lite 4
             */
        public:
            static const std::string COPY;

            /**
             * Defines the value of the type property of a cut event object.
             * This event has the following properties:PropertyValuebubblesfalsecancelablefalse; there is no default behavior to cancel.currentTargetThe object that is actively processing the Event
             * object with an event listener.targetAny InteractiveObject instance with a listener registered for the cut event.Note: TextField objects do not dispatch clear, copy, cut, paste,
             * or selectAll events. TextField objects always include Cut, Copy, Paste, Clear, and Select All commands in the context menu.
             * You cannot remove these commands from the context menu for TextField objects. For TextField objects, selecting these commands
             * (or their keyboard equivalents) does not generate clear, copy, cut, paste,
             * or selectAll events. However, other classes that extend the InteractiveObject class, including components built
             * using the Flash Text Engine (FTE), will dispatch these events in response to user actions such as keyboard shortcuts and context menus.
             * @langversion 3.0
             * @playerversion   Flash 10
             * @playerversion   AIR 1.5
             * @playerversion   Lite 4
             */
        public:
            static const std::string CUT;

            /**
             * The Event.DEACTIVATE constant defines the value of the type property of a deactivate event object.
             * Note: This event has neither a "capture phase" nor a "bubble phase",
             * which means that event listeners must be added directly to any potential targets,
             * whether the target is on the display list or not.AIR for TV devices never automatically dispatch this event. You can, however, dispatch it manually.This event has the following properties:PropertyValuebubblesfalsecancelablefalse; there is no default behavior to cancel.currentTargetThe object that is actively processing the Event
             * object with an event listener.targetAny DisplayObject instance with a listener registered for the deactivate event.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            static const std::string DEACTIVATE;

            /**
             * The Event.ENTER_FRAME constant defines the value of the type property of an enterFrame event object.
             * Note: This event has neither a "capture phase" nor a "bubble phase",
             * which means that event listeners must be added directly to any potential targets,
             * whether the target is on the display list or not.This event has the following properties:PropertyValuebubblesfalsecancelablefalse; there is no default behavior to cancel.currentTargetThe object that is actively processing the Event
             * object with an event listener.targetAny DisplayObject instance with a listener registered for the enterFrame event.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            static const std::string ENTER_FRAME;

            /**
             * The Event.FRAME_CONSTRUCTED constant defines the value of the type property of an frameConstructed event object.
             *
             *   Note: This event has neither a "capture phase" nor a "bubble phase",
             * which means that event listeners must be added directly to any potential targets,
             * whether the target is on the display list or not.This event has the following properties:PropertyValuebubblesfalsecancelablefalse; there is no default behavior to cancel.currentTargetThe object that is actively processing the Event
             * object with an event listener.targetAny DisplayObject instance with a listener registered for the frameConstructed event.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            static const std::string FRAME_CONSTRUCTED;

            /**
             * The Event.EXIT_FRAME constant defines the value of the type property of an exitFrame event object.
             * Note: This event has neither a "capture phase" nor a "bubble phase",
             * which means that event listeners must be added directly to any potential targets,
             * whether the target is on the display list or not.This event has the following properties:PropertyValuebubblesfalsecancelablefalse; there is no default behavior to cancel.currentTargetThe object that is actively processing the Event
             * object with an event listener.targetAny DisplayObject instance with a listener registered for the enterFrame event.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            static const std::string EXIT_FRAME;
        public:
            static const std::string FRAME_LABEL;

            /**
             * The Event.ID3 constant defines the value of the type property of an id3 event object.
             * This event has the following properties:PropertyValuebubblesfalsecancelablefalse; there is no default behavior to cancel.currentTargetThe object that is actively processing the Event
             * object with an event listener.targetThe Sound object loading the MP3 for which ID3 data is now available.
             * The target is not always the object in the display list
             * that registered the event listener. Use the currentTarget
             * property to access the object in the display list that is currently processing the event.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            static const std::string ID3;

            /**
             * The Event.INIT constant defines the value of the type property of an init event object.
             *
             *   This event has the following properties:PropertyValuebubblesfalsecancelablefalse; there is no default behavior to cancel.currentTargetThe object that is actively processing the Event
             * object with an event listener.targetThe LoaderInfo object associated with the SWF file being loaded.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            static const std::string INIT;

            /**
             * The Event.MOUSE_LEAVE constant defines the value of the type property of a mouseLeave event object.
             *
             *   This event has the following properties:PropertyValuebubblesfalsecancelablefalse; there is no default behavior to cancel.currentTargetThe object that is actively processing the Event
             * object with an event listener.targetThe Stage object.
             * The target is not always the object in the display list
             * that registered the event listener. Use the currentTarget
             * property to access the object in the display list that is currently processing the event.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            static const std::string MOUSE_LEAVE;

            /**
             * The Event.OPEN constant defines the value of the type property of an open event object.
             *
             *   This event has the following properties:PropertyValuebubblesfalsecancelablefalse; there is no default behavior to cancel.currentTargetThe object that is actively processing the Event
             * object with an event listener.targetThe network object that has opened a connection.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            static const std::string OPEN;

            /**
             * The Event.PASTE constant defines the value of the type property of a paste event object.
             * This event has the following properties:PropertyValuebubblesfalsecancelablefalse; there is no default behavior to cancel.currentTargetThe object that is actively processing the Event
             * object with an event listener.targetAny InteractiveObject instance with a listener registered for the paste event.Note: TextField objects do not dispatch clear, copy, cut, paste,
             * or selectAll events. TextField objects always include Cut, Copy, Paste, Clear, and Select All commands in the context menu.
             * You cannot remove these commands from the context menu for TextField objects. For TextField objects, selecting these commands
             * (or their keyboard equivalents) does not generate clear, copy, cut, paste,
             * or selectAll events. However, other classes that extend the InteractiveObject class, including components built
             * using the Flash Text Engine (FTE), will dispatch these events in response to user actions such as keyboard shortcuts and context menus.
             * @langversion 3.0
             * @playerversion   Flash 10
             * @playerversion   AIR 1.5
             * @playerversion   Lite 4
             */
        public:
            static const std::string PASTE;

            /**
             * The Event.REMOVED constant defines the value of the type property of
             * a removed event object.
             *
             *   This event has the following properties:PropertyValuebubblestruecancelablefalse; there is no default behavior to cancel.currentTargetThe object that is actively processing the Event
             * object with an event listener.targetThe DisplayObject instance to be removed from the display list.
             * The target is not always the object in the display list
             * that registered the event listener. Use the currentTarget
             * property to access the object in the display list that is currently processing the event.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            static const std::string REMOVED;

            /**
             * The Event.REMOVED_FROM_STAGE constant defines the value of the type
             * property of a removedFromStage event object.
             *
             *   This event has the following properties:PropertyValuebubblesfalsecancelablefalse; there is no default behavior to cancel.currentTargetThe object that is actively processing the Event
             * object with an event listener.targetThe DisplayObject instance being removed from the on stage display list,
             * either directly or through the removal of a sub tree in which the DisplayObject instance is contained.
             * If the DisplayObject instance is being directly removed, the removed event occurs before this event.
             * @langversion 3.0
             * @playerversion   Flash 9.0.28.0
             * @playerversion   Lite 4
             */
        public:
            static const std::string REMOVED_FROM_STAGE;

            /**
             * The Event.RENDER constant defines the value of the type property of a render event object.
             * Note: This event has neither a "capture phase" nor a "bubble phase",
             * which means that event listeners must be added directly to any potential targets,
             * whether the target is on the display list or not.This event has the following properties:PropertyValuebubblesfalsecancelablefalse; the default behavior cannot be canceled.currentTargetThe object that is actively processing the Event
             * object with an event listener.targetAny DisplayObject instance with a listener registered for the render event.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            static const std::string RENDER;

            /**
             * The Event.RESIZE constant defines the value of the type property of a resize event object.
             *
             *   This event has the following properties:PropertyValuebubblesfalsecancelablefalse; there is no default behavior to cancel.currentTargetThe object that is actively processing the Event
             * object with an event listener.targetThe Stage object.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            static const std::string RESIZE;

            /**
             * The Event.SCROLL constant defines the value of the type property of a scroll event object.
             *
             *   This event has the following properties:PropertyValuebubblesfalsecancelablefalse; there is no default behavior to cancel.currentTargetThe object that is actively processing the Event
             * object with an event listener.targetThe TextField object that has been scrolled.
             * The target property is not always the object in the display list
             * that registered the event listener. Use the currentTarget
             * property to access the object in the display list that is currently processing the event.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            static const std::string SCROLL;

            /**
             * The Event.TEXT_INTERACTION_MODE_CHANGE constant defines the value of the type property of a interaction mode event object.
             *
             *   This event has the following properties:PropertyValuebubblesfalsecancelablefalse; there is no default behavior to cancel.currentTargetThe object that is actively processing the Event
             * object with an event listener.targetThe TextField object whose interaction mode property is changed. For example on Android, one can change the interaction mode to SELECTION via context menu.
             * The target property is not always the object in the display list
             * that registered the event listener. Use the currentTarget
             * property to access the object in the display list that is currently processing the event.
             * @langversion 3.0
             * @playerversion   Flash 11
             * @playerversion   Lite 4
             */
        public:
            static const std::string TEXT_INTERACTION_MODE_CHANGE;

            /**
             * The Event.SELECT constant defines the value of the type property of a select event object.
             *
             *   This event has the following properties:PropertyValuebubblesfalsecancelablefalse; there is no default behavior to cancel.currentTargetThe object that is actively processing the Event
             * object with an event listener.targetThe object on which an item has been selected.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            static const std::string SELECT;

            /**
             * The Event.SELECT_ALL constant defines the value of the type property of a selectAll event object.
             * This event has the following properties:PropertyValuebubblesfalsecancelablefalse; there is no default behavior to cancel.currentTargetThe object that is actively processing the Event
             * object with an event listener.targetAny InteractiveObject instance with a listener registered for the selectAll event.Note: TextField objects do not dispatch clear, copy, cut, paste,
             * or selectAll events. TextField objects always include Cut, Copy, Paste, Clear, and Select All commands in the context menu.
             * You cannot remove these commands from the context menu for TextField objects. For TextField objects, selecting these commands
             * (or their keyboard equivalents) does not generate clear, copy, cut, paste,
             * or selectAll events. However, other classes that extend the InteractiveObject class, including components built
             * using the Flash Text Engine (FTE), will dispatch these events in response to user actions such as keyboard shortcuts and context menus.
             * @langversion 3.0
             * @playerversion   Flash 10
             * @playerversion   AIR 1.5
             * @playerversion   Lite 4
             */
        public:
            static const std::string SELECT_ALL;

            /**
             * The Event.SOUND_COMPLETE constant defines the value of the type property of a soundComplete event object.
             *
             *   This event has the following properties:PropertyValuebubblesfalsecancelablefalse; there is no default behavior to cancel.currentTargetThe object that is actively processing the Event
             * object with an event listener.targetThe SoundChannel object in which a sound has finished playing.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            static const std::string SOUND_COMPLETE;

            /**
             * The Event.TAB_CHILDREN_CHANGE constant defines the value of the type property of a tabChildrenChange event object.
             * This event has the following properties:PropertyValuebubblestruecancelablefalse; there is no default behavior to cancel.currentTargetThe object that is actively processing the Event
             * object with an event listener.targetThe object whose tabChildren flag has changed.
             * The target is not always the object in the display list
             * that registered the event listener. Use the currentTarget
             * property to access the object in the display list that is currently processing the event.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            static const std::string TAB_CHILDREN_CHANGE;

            /**
             * The Event.TAB_ENABLED_CHANGE constant defines the value of the type
             * property of a tabEnabledChange event object.
             *
             *   This event has the following properties:PropertyValuebubblestruecancelablefalse; there is no default behavior to cancel.currentTargetThe object that is actively processing the Event
             * object with an event listener.targetThe InteractiveObject whose tabEnabled flag has changed.
             * The target is not always the object in the display list
             * that registered the event listener. Use the currentTarget
             * property to access the object in the display list that is currently processing the event.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            static const std::string TAB_ENABLED_CHANGE;

            /**
             * The Event.TAB_INDEX_CHANGE constant defines the value of the
             * type property of a tabIndexChange event object.
             *
             *   This event has the following properties:PropertyValuebubblestruecancelablefalse; there is no default behavior to cancel.currentTargetThe object that is actively processing the Event
             * object with an event listener.targetThe object whose tabIndex has changed.
             * The target is not always the object in the display list
             * that registered the event listener. Use the currentTarget
             * property to access the object in the display list that is currently processing the event.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            static const std::string TAB_INDEX_CHANGE;

            /**
             * The Event.UNLOAD constant defines the value of the type property of an unload event object.
             *
             *   This event has the following properties:PropertyValuebubblesfalsecancelablefalse; there is no default behavior to cancel.currentTargetThe object that is actively processing the Event
             * object with an event listener.targetThe LoaderInfo object associated with the SWF file being unloaded or replaced.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            static const std::string UNLOAD;

            /**
             * The Event.FULL_SCREEN constant defines the value of the type property of a fullScreen event object.
             *
             *   This event has the following properties:PropertyValuebubblesfalsecancelablefalse; there is no default behavior to cancel.currentTargetThe object that is actively processing the Event
             * object with an event listener.targetThe Stage object.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            static const std::string FULLSCREEN;
        public:
            static const std::string CONTEXT3D_CREATE;
        public:
            static const std::string TEXTURE_READY;
        public:
            static const std::string VIDEO_FRAME;
        public:
            static const std::string SUSPEND;
        public:
            static const std::string CHANNEL_MESSAGE;
        public:
            static const std::string CHANNEL_STATE;
        public:
            static const std::string WORKER_STATE;

            /**
             * The type of event. The type is case-sensitive.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            std::string  type();

            /**
             * Indicates whether an event is a bubbling event. If the event can bubble,
             * this value is true; otherwise it is false.
             *
             *   When an event occurs, it moves through the three phases of the event flow: the capture
             * phase, which flows from the top of the display list hierarchy to the node just before the
             * target node; the target phase, which comprises the target node; and the bubbling phase,
             * which flows from the node subsequent to the target node back up the display list hierarchy.Some events, such as the activate and unload events, do not
             * have a bubbling phase. The bubbles property has a value of
             * false for events that do not have a bubbling phase.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            bool         bubbles();

            /**
             * Indicates whether the behavior associated with the event can be prevented.
             * If the behavior can be canceled, this value is true; otherwise it is false.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            bool         cancelable();

            /**
             * The event target. This property contains the target node. For example, if a user clicks an OK button, the target node is the display list node containing that button.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            Object      *target();

            /**
             * The object that is actively processing the Event object with an event listener. For example, if a user clicks an OK button, the current target could be the node containing that button or one of its ancestors that has registered an event listener for that event.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            Object      *currentTarget();

            /**
             * The current phase in the event flow. This property can contain the following numeric values:
             * The capture phase (EventPhase.CAPTURING_PHASE). The target phase (EventPhase.AT_TARGET). The bubbling phase (EventPhase.BUBBLING_PHASE).
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            unsigned int eventPhase();

            /**
             * Creates an Event object to pass as a parameter to event listeners.
             * @param   type    The type of the event, accessible as Event.type.
             * @param   bubbles Determines whether the Event object participates in the bubbling stage of the event flow. The default value is false.
             * @param   cancelable  Determines whether the Event object can be canceled. The default values is false.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            Event(std::string type, bool bubbles   =false, bool cancelable   =false);

            /**
             * A utility function for implementing the toString() method in custom
             * ActionScript 3.0 Event classes. Overriding the
             * toString() method is recommended, but not required.
             * class PingEvent extends Event {
             * var URL:String;
             *
             *   public override function toString():String {
             * return formatToString("PingEvent", "type", "bubbles", "cancelable", "eventPhase", "URL");
             * }
             * }
             * @param   className   The name of your custom Event class. In the previous example,
             *   the className parameter is PingEvent.
             * @param   arguments   The properties of the Event class and the
             *   properties that you add in your custom Event class. In the previous example, the ...arguments
             *   parameter includes type, bubbles, cancelable,
             *   eventPhase, and URL.
             * @return  The name of your custom Event class and the String value of your ...arguments
             *   parameter.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            std::string formatToString(std::string className, ...);

            /**
             * Duplicates an instance of an Event subclass.
             *
             *   Returns a new Event object that is a copy of the original instance of the Event object.
             * You do not normally call clone(); the EventDispatcher class calls it automatically
             * when you redispatch an event   that is, when you call dispatchEvent(event) from a handler
             * that is handling event.The new Event object includes all the properties of the original.When creating your own custom Event class, you must override the
             * inherited Event.clone() method in order for it to duplicate the
             * properties of your custom class. If you do not set all the properties that you add
             * in your event subclass, those properties will not have the correct values when listeners
             * handle the redispatched event.In this example, PingEvent is a subclass of Event
             * and therefore implements its own version of clone().
             * <codeblock>
             *
             *   class PingEvent extends Event {
             * var URL:String;
             *
             *   public override function clone():Event {
             * return new PingEvent(type, bubbles, cancelable, URL);
             * }
             * }
             *
             *   </codeblock>
             * @return  A new Event object that is identical to the original.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            flash::events::Event *clone();

            /**
             * Returns a string containing all the properties of the Event object. The string is in the following format:
             * [Event type=value bubbles=value cancelable=value]
             * @return  A string containing all the properties of the Event object.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            std::string toString();

            /**
             * Prevents processing of any event listeners in nodes subsequent to the current node in the
             * event flow. This method does not affect any event listeners in the current node
             * (currentTarget). In contrast, the stopImmediatePropagation() method
             * prevents processing of event listeners in both the current node and subsequent nodes.
             * Additional calls to this method have no effect. This method can be called in any phase
             * of the event flow.Note:  This method does not cancel the behavior associated with this event; see preventDefault() for that functionality.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            void     stopPropagation();

            /**
             * Prevents processing of any event listeners in the current node and any subsequent nodes in
             * the event flow. This method takes effect immediately, and it affects event listeners
             * in the current node. In contrast, the stopPropagation() method doesn't take
             * effect until all the event listeners in the current node finish processing.Note:  This method does not cancel the behavior associated with this event; see preventDefault() for that functionality.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            void     stopImmediatePropagation();

            /**
             * Cancels an event's default behavior if that behavior can be canceled.
             *
             *   Many events have associated behaviors that are carried out by default.
             * For example, if a user types a character
             * into a text field, the default behavior is that the character is
             * displayed in the text field. Because the TextEvent.TEXT_INPUT
             * event's default behavior can be canceled, you can use the preventDefault()
             * method to prevent the character from appearing.An example of a behavior that is not cancelable is the default behavior associated with
             * the Event.REMOVED event, which is generated whenever Flash Player is about to
             * remove a display object from the display list. The default behavior (removing the element)
             * cannot be canceled, so the preventDefault() method has no effect on this
             * default behavior. You can use the Event.cancelable property to check whether you can prevent
             * the default behavior associated with a particular event. If the value of
             * Event.cancelable is true, then preventDefault() can
             * be used to cancel the event; otherwise, preventDefault() has no effect.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            void     preventDefault();

            /**
             * Checks whether the preventDefault() method has been called on the event. If the
             * preventDefault() method has been called,
             * returns true; otherwise, returns false.
             * @return  If preventDefault() has been called, returns true; otherwise,
             *   returns false.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            bool     isDefaultPrevented();
        };
    }
}

#endif // FLEX11_6_FLASH_EVENTS_EVENT_AS
#endif // __cplusplus

