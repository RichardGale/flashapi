

#include "ContextMenuEvent.h"
#include "flash/display/InteractiveObject.h"
#include "flash/events/Event.h"

    /// @eventType  flash.events.ContextMenuEvent.MENU_ITEM_SELECT

using namespace flash::display;
using namespace flash::events;

namespace flash {
namespace events {


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
        const std::string ContextMenuEvent::MENU_ITEM_SELECT="menuItemSelect";

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
        const std::string ContextMenuEvent::MENU_SELECT="menuSelect";

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
        flash::display::InteractiveObject* ContextMenuEvent::mouseTarget()                                  ;
        void ContextMenuEvent::mouseTarget(InteractiveObject* value)       ;

        /**
         * The display list object to which the menu is attached. This could be the mouse target (mouseTarget) or one of its ancestors in the display list.
         * @langversion 3.0
         * @playerversion   Flash 9
         */
        flash::display::InteractiveObject* ContextMenuEvent::contextMenuOwner()                                  ;
        void ContextMenuEvent::contextMenuOwner(InteractiveObject* value)       ;

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
        bool ContextMenuEvent::isMouseTargetInaccessible()          ;
        void ContextMenuEvent::isMouseTargetInaccessible(bool value)       ;

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
        ContextMenuEvent::ContextMenuEvent(std::string type, bool bubbles, bool cancelable, InteractiveObject* mouseTarget, InteractiveObject* contextMenuOwner);

        /**
         * Creates a copy of the ContextMenuEvent object and sets the value of each property to match that of the original.
         * @return  A new ContextMenuEvent object with property values that match those of the original.
         * @langversion 3.0
         * @playerversion   Flash 9
         */
        flash::events::Event* ContextMenuEvent::clone()                     ;

        /**
         * Returns a string that contains all the properties of the ContextMenuEvent object. The string is in the following format:
         * [ContextMenuEvent type=value bubbles=value cancelable=value ... contextMenuOwner=value]
         * @return  A string that contains all the properties of the ContextMenuEvent object.
         * @langversion 3.0
         * @playerversion   Flash 9
         */
        std::string ContextMenuEvent::toString()         ;
}
}

