

#include "NativeMenuItem.h"
#include "flash/events/EventDispatcher.h"

    /**
     * Dispatched by this NativeMenuItem object when its key equivalent is pressed and immediately before the containing menu is displayed.
     * @eventType   flash.events.Event.PREPARING
     */

using namespace flash::events;

namespace flash {
namespace display {


        /**
         * Controls whether this menu item is enabled.
         * @langversion 3.0
         * @playerversion   AIR 1.0
         */
        bool NativeMenuItem::enabled()          ;
        void NativeMenuItem::enabled(bool isSeparator)       ;

        /**
         * Creates a new NativeMenuItem object.
         * 
         *   To create a menu command, set the label parameter to a
         * string containing the display label and set isSeparator 
         * to false.To create a submenu command, create a command item and then assign the 
         * NativeMenu object for the submenu to the item's submenu 
         * property. Add the item to the parent menu.To create a separator, set the label parameter to an empty 
         * string and set isSeparator to true.Add and remove items from a menu using the NativeMenu addItem()
         * and removeItem() methods.
         * @param   label   The display label for the item, or an empty string for separators.
         * @param   isSeparator Set to true to create a separator; set to
         *   false otherwise.
         * @langversion 3.0
         * @playerversion   AIR 1.0
         */
        NativeMenuItem::NativeMenuItem();
}
}

