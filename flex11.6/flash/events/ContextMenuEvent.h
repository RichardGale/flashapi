#if !defined(FLEX11_6_FLASH_EVENTS_CONTEXTMENUEVENT_AS)
#define FLEX11_6_FLASH_EVENTS_CONTEXTMENUEVENT_AS
#if defined(__cplusplus)


namespace flash
{
    namespace display
    {
        class InteractiveObject;
    }
}
#include "flash/events/Event.h"

/// @eventType  flash.events.ContextMenuEvent.MENU_ITEM_SELECT
//[Event(name="menuItemSelect",type="flash.events.ContextMenuEvent")]


//[Event(name="menuSelect",type="flash.events.ContextMenuEvent")]/// @eventType  flash.events.ContextMenuEvent.MENU_SELECT

/**
 * An InteractiveObject dispatches a ContextMenuEvent object when the user opens or interacts with
 * the context menu. There are two types of
 * ContextMenuEvent objects:
 * <ul class="- topic/ul "><li class="- topic/li "><codeph class="+ topic/ph pr-d/codeph ">ContextMenuEvent.MENU_ITEM_SELECT</codeph></li><li class="- topic/li "><codeph class="+ topic/ph pr-d/codeph ">ContextMenuEvent.MENU_SELECT</codeph></li></ul>
 *
 *   EXAMPLE:
 *
 *   The following example uses the <codeph class="+ topic/ph pr-d/codeph ">ContextMenuEventExample</codeph> class
 * to remove the default context menu items from the Stage and add a new menu item that changes
 * the color of a square on the Stage. The example carries out the following
 * tasks:
 *
 *   <ol class="- topic/ol "><li class="- topic/li ">The <codeph class="+ topic/ph pr-d/codeph ">myContextMenu</codeph> property is declared and then assigned to a new ContextMenu
 * object and the <codeph class="+ topic/ph pr-d/codeph ">redRectangle</codeph> property  (of type Sprite) is declared.</li><li class="- topic/li ">The <codeph class="+ topic/ph pr-d/codeph ">removeDefaultItems()</codeph> method is called. This method removes all built-in context
 * menu items except Print.</li><li class="- topic/li ">The <codeph class="+ topic/ph pr-d/codeph ">addCustomMenuItems()</codeph> method is called. This method places a
 * <codeph class="+ topic/ph pr-d/codeph ">Reverse Colors</codeph> menu item in the <codeph class="+ topic/ph pr-d/codeph ">defaultItems</codeph> array by using the
 * <codeph class="+ topic/ph pr-d/codeph ">push()</codeph> method of Array. A <codeph class="+ topic/ph pr-d/codeph ">menuItemSelect</codeph> event listener is added to the
 * ContextMenuItem object and the associated method is called <codeph class="+ topic/ph pr-d/codeph ">menuItemSelectHandler()</codeph>.
 * This method prints some <codeph class="+ topic/ph pr-d/codeph ">trace()</codeph> statements whenever the user
 * selects Reverse Colors from the context menu. In addition the red square
 * becomes black and the black text becomes red.</li><li class="- topic/li ">Back in the constructor, a <codeph class="+ topic/ph pr-d/codeph ">menuSelect</codeph> event listener is added, along with
 * the associated method <codeph class="+ topic/ph pr-d/codeph ">menuSelectHandler()</codeph>, which simply prints out three <codeph class="+ topic/ph pr-d/codeph ">trace()</codeph> statements
 * every time an item in the context menu is selected.</li><li class="- topic/li ">The constructor calls <codeph class="+ topic/ph pr-d/codeph ">addChildren()</codeph>, which draws a red square and adds it
 * to the display list, which immediately displays the square.</li><li class="- topic/li ">Finally, <codeph class="+ topic/ph pr-d/codeph ">myContextMenu</codeph> is assigned to the context menu of the <codeph class="+ topic/ph pr-d/codeph ">redRectangle</codeph> property,
 * so that the custom context menu is displayed only when the mouse pointer is over the square.</li></ol><codeblock xml:space="preserve" class="+ topic/pre pr-d/codeblock ">
 * package {
 * import flash.ui.ContextMenu;
 * import flash.ui.ContextMenuItem;
 * import flash.ui.ContextMenuBuiltInItems;
 * import flash.events.ContextMenuEvent;
 * import flash.display.Sprite;
 * import flash.display.Shape;
 * import flash.text.TextField;
 *
 *   public class ContextMenuEventExample extends Sprite {
 * private var myContextMenu:ContextMenu;
 * private var menuLabel:String = "Reverse Colors";
 * private var textLabel:String = "Right Click";
 * private var redRectangle:Sprite;
 * private var label:TextField;
 * private var size:uint = 100;
 * private var black:uint = 0x000000;
 * private var red:uint = 0xFF0000;
 *
 *   public function ContextMenuEventExample() {
 * myContextMenu = new ContextMenu();
 * removeDefaultItems();
 * addCustomMenuItems();
 * myContextMenu.addEventListener(ContextMenuEvent.MENU_SELECT, menuSelectHandler);
 *
 *   addChildren();
 * redRectangle.contextMenu = myContextMenu;
 * }
 *
 *   private function addChildren():void {
 * redRectangle = new Sprite();
 * redRectangle.graphics.beginFill(red);
 * redRectangle.graphics.drawRect(0, 0, size, size);
 * addChild(redRectangle);
 * redRectangle.x = size;
 * redRectangle.y = size;
 * label = createLabel();
 * redRectangle.addChild(label);
 * }
 *
 *   private function removeDefaultItems():void {
 * myContextMenu.hideBuiltInItems();
 * var defaultItems:ContextMenuBuiltInItems = myContextMenu.builtInItems;
 * defaultItems.print = true;
 * }
 *
 *   private function addCustomMenuItems():void {
 * var item:ContextMenuItem = new ContextMenuItem(menuLabel);
 * myContextMenu.customItems.push(item);
 * item.addEventListener(ContextMenuEvent.MENU_ITEM_SELECT, menuItemSelectHandler);
 * }
 *
 *   private function menuSelectHandler(event:ContextMenuEvent):void {
 * trace("menuSelectHandler: " + event);
 * }
 *
 *   private function menuItemSelectHandler(event:ContextMenuEvent):void {
 * trace("menuItemSelectHandler: " + event);
 * var textColor:uint = (label.textColor == black) ? red : black;
 * var bgColor:uint = (label.textColor == black) ? black : red;
 * redRectangle.graphics.clear();
 * redRectangle.graphics.beginFill(bgColor);
 * redRectangle.graphics.drawRect(0, 0, size, size);
 * label.textColor = textColor;
 * }
 *
 *   private function createLabel():TextField {
 * var txtField:TextField = new TextField();
 * txtField.text = textLabel;
 * return txtField;
 * }
 * }
 * }
 * </codeblock>
 * @langversion 3.0
 * @playerversion   Flash 9
 */
using namespace flash::display;
using namespace flash::events;

namespace flash
{
    namespace events
    {
        class ContextMenuEvent: public Event
        {
            /**
             * Defines the value of the type property of a menuItemSelect event object.
             * This event has the following properties:PropertyValuebubblesfalsecancelablefalse; there is no default behavior to cancel.contextMenuOwnerThe display list object to which the menu is attached.currentTargetThe object that is actively processing the Event
             * object with an event listener.mouseTargetThe display list object on which the user right-clicked to display the context menu.targetThe ContextMenuItem object that has been selected.
             * The target is not always the object in the display list
             * that registered the event listener. Use the currentTarget
             * property to access the object in the display list that is currently processing the event.
             * @langversion 3.0
             * @playerversion   Flash 9
             */
        public:
            static const std::string MENU_ITEM_SELECT;

            /**
             * Defines the value of the type property of a menuSelect event object.
             * This event has the following properties:PropertyValuebubblesfalsecancelablefalse; there is no default behavior to cancel.contextMenuOwnerThe display list object to which the menu is attached.currentTargetThe object that is actively processing the Event
             * object with an event listener.mouseTargetThe display list object on which the user right-clicked to display the context menu.targetThe ContextMenu object that is about to be displayed.
             * The target is not always the object in the display list
             * that registered the event listener. Use the currentTarget
             * property to access the object in the display list that is currently processing the event.
             * @langversion 3.0
             * @playerversion   Flash 9
             */
        public:
            static const std::string MENU_SELECT;

            /**
             * The display list object on which the user right-clicked to display the context menu. This could be the display list object to which the
             * menu is attached (contextMenuOwner) or one of its display list descendants.
             * The value of this property can be null in two circumstances: if there no mouse target,
             * for example when you mouse over something from
             * the background; or there is a mouse target, but it is in a security sandbox to which you don't have access.
             * Use the isMouseTargetInaccessible() property to determine which of these reasons applies.
             * @langversion 3.0
             * @playerversion   Flash 9
             */
        public:
            flash::display::InteractiveObject *mouseTarget();
        public:
            void         mouseTarget(InteractiveObject *value);

            /**
             * The display list object to which the menu is attached. This could be the mouse target (mouseTarget) or one of its ancestors in the display list.
             * @langversion 3.0
             * @playerversion   Flash 9
             */
        public:
            flash::display::InteractiveObject *contextMenuOwner();
        public:
            void         contextMenuOwner(InteractiveObject *value);

            /**
             * Indicates whether the mouseTarget property was set to null for security
             * reasons.  If the nominal value of menuTarget would be a reference to a
             * DisplayObject in another security sandbox, then menuTarget is set to
             * null unless there is permission in both directions across this sandbox boundary.  Permission is
             * established by calling Security.allowDomain() from a SWF file, or providing
             * a policy file from the server of an image file, and setting the LoaderContext.checkPolicyFile
             * flag when loading the image.
             * @langversion 3.0
             * @playerversion   Flash 10
             */
        public:
            bool         isMouseTargetInaccessible();
        public:
            void         isMouseTargetInaccessible(bool value);

            /**
             * Creates an Event object that contains specific information about menu events.
             * Event objects are passed as parameters to event listeners.
             * @param   type    The type of the event. Possible values are:
             *   ContextMenuEvent.MENU_ITEM_SELECTContextMenuEvent.MENU_SELECT
             * @param   bubbles Determines whether the Event object participates in the bubbling stage of the event flow. Event listeners can access this information through the inherited bubbles property.
             * @param   cancelable  Determines whether the Event object can be canceled. Event listeners can access this information through the inherited cancelable property.
             * @param   mouseTarget The display list object on which the user right-clicked to display the context menu. This could be the contextMenuOwner or one of its display list descendants.
             * @param   contextMenuOwner    The display list object to which the menu is attached. This could be the mouseTarget or one of its ancestors in the display list.
             * @langversion 3.0
             * @playerversion   Flash 9
             */
        public:
            ContextMenuEvent(std::string type, bool bubbles, bool cancelable, InteractiveObject *mouseTarget, InteractiveObject *contextMenuOwner);

            /**
             * Creates a copy of the ContextMenuEvent object and sets the value of each property to match that of the original.
             * @return  A new ContextMenuEvent object with property values that match those of the original.
             * @langversion 3.0
             * @playerversion   Flash 9
             */
        public:
            flash::events::Event *clone();

            /**
             * Returns a string that contains all the properties of the ContextMenuEvent object. The string is in the following format:
             * [ContextMenuEvent type=value bubbles=value cancelable=value ... contextMenuOwner=value]
             * @return  A string that contains all the properties of the ContextMenuEvent object.
             * @langversion 3.0
             * @playerversion   Flash 9
             */
        public:
            std::string toString();
        };
    }
}

#endif // FLEX11_6_FLASH_EVENTS_CONTEXTMENUEVENT_AS
#endif // __cplusplus

