

#include "ContextMenuItem.h"
#include "flash/display/NativeMenuItem.h"
#include "flash/ui/ContextMenuItem.h"

    /**
     * Dispatched when a user selects an item from a context menu.
     * @eventType   flash.events.ContextMenuEvent.MENU_ITEM_SELECT
     */

using namespace flash::display;
using namespace flash::ui;

namespace flash {
namespace ui {


        /**
         * Specifies the menu item caption (text) displayed in the context menu.
         * See the ContextMenuItem class overview for caption value restrictions.
         * @langversion 3.0
         * @playerversion   Flash 9
         */
        std::string ContextMenuItem::caption()         ;
        void ContextMenuItem::caption(std::string value)       ;

        /**
         * Indicates whether a separator bar should appear above the specified menu item.
         * 
         *   Note: A separator bar always appears between any custom menu items and the
         * built-in menu items.
         * @langversion 3.0
         * @playerversion   Flash 9
         */
        bool ContextMenuItem::separatorBefore()          ;
        void ContextMenuItem::separatorBefore(bool value)       ;

        /**
         * Indicates whether the specified menu item is visible when the Flash Player
         * context menu is displayed.
         * @langversion 3.0
         * @playerversion   Flash 9
         */
        bool ContextMenuItem::visible()          ;
        void ContextMenuItem::visible(bool value)       ;

        /**
         * Creates a new ContextMenuItem object that can be added to the ContextMenu.customItems
         * array.
         * @param   caption Specifies the text associated with the menu item. 
         *   See the ContextMenuItem class overview for caption value restrictions.
         * @param   separatorBefore Specifies whether a separator bar appears above the
         *   menu item in the context menu. The default value is false.
         * @param   enabled Specifies whether the menu item is enabled or disabled in the
         *   context menu. The default value is true (enabled). This parameter is optional.
         * @param   visible Specifies whether the menu item is visible or invisible. The
         *   default value is true (visible).
         * @langversion 3.0
         * @playerversion   Flash 9
         */
        ContextMenuItem::ContextMenuItem(std::string caption, bool separatorBefore, bool enabled, bool visible);

        /// Creates a copy of the NativeMenuItem object.
        flash::display::NativeMenuItem* ContextMenuItem::clone()                               ;
}
}

