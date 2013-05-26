

#include "Event.h"
#include "flash/events/Event.h"

    /// @eventType  flash.events.Event.ACTIVATE

using namespace flash::events;

namespace flash {
namespace events {


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
        const std::string Event::ACTIVATE   = "activate";

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
        const std::string Event::ADDED   = "added";

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
        const std::string Event::ADDED_TO_STAGE   = "addedToStage";

        /**
         * The Event.CANCEL constant defines the value of the type property of a cancel event object. 
         * This event has the following properties:PropertyValuebubblesfalsecancelablefalse; there is no default behavior to cancel.currentTargetThe object that is actively processing the Event 
         * object with an event listener.targetA reference to the object on which the operation is canceled.
         * @langversion 3.0
         * @playerversion   Flash 9
         * @playerversion   Lite 4
         * @internal    <code>ProductManager</code> pulled from table
         */
        const std::string Event::CANCEL   = "cancel";

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
        const std::string Event::CHANGE   = "change";

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
        const std::string Event::CLEAR   = "clear";

        /**
         * The Event.CLOSE constant defines the value of the type property of a close event object.
         * 
         *   This event has the following properties:PropertyValuebubblesfalsecancelablefalse; there is no default behavior to cancel.currentTargetThe object that is actively processing the Event 
         * object with an event listener.targetThe object whose connection has been closed.
         * @langversion 3.0
         * @playerversion   Flash 9
         * @playerversion   Lite 4
         */
        const std::string Event::CLOSE   = "close";

        /**
         * The Event.COMPLETE constant defines the value of the type property of a complete event object.
         * 
         *   This event has the following properties:PropertyValuebubblesfalsecancelablefalse; there is no default behavior to cancel.currentTargetThe object that is actively processing the Event 
         * object with an event listener.targetThe network object that has completed loading.
         * @langversion 3.0
         * @playerversion   Flash 9
         * @playerversion   Lite 4
         */
        const std::string Event::COMPLETE   = "complete";

        /**
         * The Event.CONNECT constant defines the value of the type property of a connect event object.
         * 
         *   This event has the following properties:PropertyValuebubblesfalsecancelablefalse; there is no default behavior to cancel.currentTargetThe object that is actively processing the Event 
         * object with an event listener.targetThe Socket or XMLSocket object that has established a network connection.
         * @langversion 3.0
         * @playerversion   Flash 9
         * @playerversion   Lite 4
         */
        const std::string Event::CONNECT   = "connect";

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
        const std::string Event::COPY   = "copy";

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
        const std::string Event::CUT   = "cut";

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
        const std::string Event::DEACTIVATE   = "deactivate";

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
        const std::string Event::ENTER_FRAME   = "enterFrame";

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
        const std::string Event::FRAME_CONSTRUCTED   = "frameConstructed";

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
        const std::string Event::EXIT_FRAME   = "exitFrame";
        const std::string Event::FRAME_LABEL  ;

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
        const std::string Event::ID3   = "id3";

        /**
         * The Event.INIT constant defines the value of the type property of an init event object.
         * 
         *   This event has the following properties:PropertyValuebubblesfalsecancelablefalse; there is no default behavior to cancel.currentTargetThe object that is actively processing the Event 
         * object with an event listener.targetThe LoaderInfo object associated with the SWF file being loaded.
         * @langversion 3.0
         * @playerversion   Flash 9
         * @playerversion   Lite 4
         */
        const std::string Event::INIT   = "init";

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
        const std::string Event::MOUSE_LEAVE   = "mouseLeave";

        /**
         * The Event.OPEN constant defines the value of the type property of an open event object.
         * 
         *   This event has the following properties:PropertyValuebubblesfalsecancelablefalse; there is no default behavior to cancel.currentTargetThe object that is actively processing the Event 
         * object with an event listener.targetThe network object that has opened a connection.
         * @langversion 3.0
         * @playerversion   Flash 9
         * @playerversion   Lite 4
         */
        const std::string Event::OPEN   = "open";

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
        const std::string Event::PASTE   = "paste";

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
        const std::string Event::REMOVED   = "removed";

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
        const std::string Event::REMOVED_FROM_STAGE   = "removedFromStage";

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
        const std::string Event::RENDER   = "render";

        /**
         * The Event.RESIZE constant defines the value of the type property of a resize event object.
         * 
         *   This event has the following properties:PropertyValuebubblesfalsecancelablefalse; there is no default behavior to cancel.currentTargetThe object that is actively processing the Event 
         * object with an event listener.targetThe Stage object.
         * @langversion 3.0
         * @playerversion   Flash 9
         * @playerversion   Lite 4
         */
        const std::string Event::RESIZE   = "resize";

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
        const std::string Event::SCROLL   = "scroll";

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
        const std::string Event::TEXT_INTERACTION_MODE_CHANGE   = "textInteractionModeChange";

        /**
         * The Event.SELECT constant defines the value of the type property of a select event object.
         * 
         *   This event has the following properties:PropertyValuebubblesfalsecancelablefalse; there is no default behavior to cancel.currentTargetThe object that is actively processing the Event 
         * object with an event listener.targetThe object on which an item has been selected.
         * @langversion 3.0
         * @playerversion   Flash 9
         * @playerversion   Lite 4
         */
        const std::string Event::SELECT   = "select";

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
        const std::string Event::SELECT_ALL   = "selectAll";

        /**
         * The Event.SOUND_COMPLETE constant defines the value of the type property of a soundComplete event object.
         * 
         *   This event has the following properties:PropertyValuebubblesfalsecancelablefalse; there is no default behavior to cancel.currentTargetThe object that is actively processing the Event 
         * object with an event listener.targetThe SoundChannel object in which a sound has finished playing.
         * @langversion 3.0
         * @playerversion   Flash 9
         * @playerversion   Lite 4
         */
        const std::string Event::SOUND_COMPLETE   = "soundComplete";

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
        const std::string Event::TAB_CHILDREN_CHANGE   = "tabChildrenChange";

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
        const std::string Event::TAB_ENABLED_CHANGE   = "tabEnabledChange";

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
        const std::string Event::TAB_INDEX_CHANGE   = "tabIndexChange";

        /**
         * The Event.UNLOAD constant defines the value of the type property of an unload event object.
         * 
         *   This event has the following properties:PropertyValuebubblesfalsecancelablefalse; there is no default behavior to cancel.currentTargetThe object that is actively processing the Event 
         * object with an event listener.targetThe LoaderInfo object associated with the SWF file being unloaded or replaced.
         * @langversion 3.0
         * @playerversion   Flash 9
         * @playerversion   Lite 4
         */
        const std::string Event::UNLOAD   = "unload";

        /**
         * The Event.FULL_SCREEN constant defines the value of the type property of a fullScreen event object.
         * 
         *   This event has the following properties:PropertyValuebubblesfalsecancelablefalse; there is no default behavior to cancel.currentTargetThe object that is actively processing the Event 
         * object with an event listener.targetThe Stage object.
         * @langversion 3.0
         * @playerversion   Flash 9
         * @playerversion   Lite 4
         */
        const std::string Event::FULLSCREEN   = "fullScreen";
        const std::string Event::CONTEXT3D_CREATE  ;
        const std::string Event::TEXTURE_READY  ;
        const std::string Event::VIDEO_FRAME  ;
        const std::string Event::SUSPEND  ;
        const std::string Event::CHANNEL_MESSAGE  ;
        const std::string Event::CHANNEL_STATE  ;
        const std::string Event::WORKER_STATE  ;

        /**
         * The type of event. The type is case-sensitive.
         * @langversion 3.0
         * @playerversion   Flash 9
         * @playerversion   Lite 4
         */
        std::string Event::type()         ;

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
        bool Event::bubbles()          ;

        /**
         * Indicates whether the behavior associated with the event can be prevented. 
         * If the behavior can be canceled, this value is true; otherwise it is false.
         * @langversion 3.0
         * @playerversion   Flash 9
         * @playerversion   Lite 4
         */
        bool Event::cancelable()          ;

        /**
         * The event target. This property contains the target node. For example, if a user clicks an OK button, the target node is the display list node containing that button.
         * @langversion 3.0
         * @playerversion   Flash 9
         * @playerversion   Lite 4
         */
        Object* Event::target()         ;

        /**
         * The object that is actively processing the Event object with an event listener. For example, if a user clicks an OK button, the current target could be the node containing that button or one of its ancestors that has registered an event listener for that event.
         * @langversion 3.0
         * @playerversion   Flash 9
         * @playerversion   Lite 4
         */
        Object* Event::currentTarget()         ;

        /**
         * The current phase in the event flow. This property can contain the following numeric values:
         * The capture phase (EventPhase.CAPTURING_PHASE). The target phase (EventPhase.AT_TARGET). The bubbling phase (EventPhase.BUBBLING_PHASE).
         * @langversion 3.0
         * @playerversion   Flash 9
         * @playerversion   Lite 4
         */
        unsigned int Event::eventPhase()       ;

        /**
         * Creates an Event object to pass as a parameter to event listeners.
         * @param   type    The type of the event, accessible as Event.type.
         * @param   bubbles Determines whether the Event object participates in the bubbling stage of the event flow. The default value is false.
         * @param   cancelable  Determines whether the Event object can be canceled. The default values is false.
         * @langversion 3.0
         * @playerversion   Flash 9
         * @playerversion   Lite 4
         */
        Event::Event(std::string type, bool bubbles, bool cancelable);

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
        std::string Event::formatToString(std::string className, ...)         ;

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
        flash::events::Event* Event::clone()                     ;

        /**
         * Returns a string containing all the properties of the Event object. The string is in the following format:
         * [Event type=value bubbles=value cancelable=value]
         * @return  A string containing all the properties of the Event object.
         * @langversion 3.0
         * @playerversion   Flash 9
         * @playerversion   Lite 4
         */
        std::string Event::toString()         ;

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
        void Event::stopPropagation()       ;

        /**
         * Prevents processing of any event listeners in the current node and any subsequent nodes in 
         * the event flow. This method takes effect immediately, and it affects event listeners 
         * in the current node. In contrast, the stopPropagation() method doesn't take 
         * effect until all the event listeners in the current node finish processing.Note:  This method does not cancel the behavior associated with this event; see preventDefault() for that functionality.
         * @langversion 3.0
         * @playerversion   Flash 9
         * @playerversion   Lite 4
         */
        void Event::stopImmediatePropagation()       ;

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
        void Event::preventDefault()       ;

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
        bool Event::isDefaultPrevented()          ;
}
}

