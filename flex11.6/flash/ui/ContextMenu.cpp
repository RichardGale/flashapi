

#include "ContextMenu.h"
#include "flash/display/NativeMenu.h"
#include "flash/ui/ContextMenuBuiltInItems.h"
#include "flash/net/URLRequest.h"
#include "flash/ui/ContextMenuClipboardItems.h"
#include "flash/ui/ContextMenu.h"

    /**
     * Dispatched when a user first generates a 
     * context menu but before the contents of the context menu are displayed.
     * @eventType   flash.events.ContextMenuEvent.MENU_SELECT
     */

using namespace flash::display;
using namespace flash::net;
using namespace flash::ui;

namespace flash {
namespace ui {


        /**
         * The isSupported property is set to true if the 
         * ContextMenu class is supported on the current platform, otherwise it is
         * set to false.
         * @langversion 3.0
         * @playerversion   Flash 10.1
         * @playerversion   AIR 2
         */
        bool ContextMenu::isSupported()          ;

        /**
         * An instance of the ContextMenuBuiltInItems class with the following properties: 
         * forwardAndBack, loop,
         * play, print, quality,
         * rewind, save, and zoom.
         * Setting these properties to false removes the corresponding menu items from the
         * specified ContextMenu object. These properties are enumerable and are set to true by
         * default.
         * 
         *   Note: In AIR, context menus do not have built-in items.
         * @langversion 3.0
         * @playerversion   Flash 9
         */
        flash::ui::ContextMenuBuiltInItems* ContextMenu::builtInItems()                                   ;
        void ContextMenu::builtInItems(ContextMenuBuiltInItems* value)       ;

        /**
         * An array of ContextMenuItem objects. Each object in the array represents a context menu item that you
         * have defined. Use this property to add, remove, or modify these custom menu items.
         * 
         *   To add new menu items, you create a ContextMenuItem object and then add it to the
         * customItems array (for example, by using Array.push()). For more information about creating
         * menu items, see the ContextMenuItem class entry.
         * @langversion 3.0
         * @playerversion   Flash 9
         */
        std::vector<void*> ContextMenu::customItems()        ;
        void ContextMenu::customItems(std::vector<void*> value)       ;

        /**
         * The URLRequest of the link.  If this property is null, a normal context menu is displayed.
         * If this property is not null, the link context menu is displayed, and operates on the url specified.
         * 
         *   If a link is specified, the clipboardMenu property is ignored.The default value is null.
         * @langversion 3.0
         * @playerversion   Flash 10
         * @playerversion   AIR 1.5
         */
        flash::net::URLRequest* ContextMenu::link()                       ;
        void ContextMenu::link(URLRequest* value)       ;

        /**
         * Specifies whether or not the clipboard menu should be used.  If this value is true,
         * the clipboardItems property determines which items are enabled or disabled on the clipboard menu.
         * 
         *   If the link property is non-null, this clipBoardMenu property is ignored.
         * @langversion 3.0
         * @playerversion   Flash 10
         * @playerversion   AIR 1.5
         */
        bool ContextMenu::clipboardMenu()          ;
        void ContextMenu::clipboardMenu(bool value)       ;

        /**
         * An instance of the ContextMenuClipboardItems class with the following properties: 
         * cut, copy, paste, delete, selectAll.
         * Setting one of these properties to false disables the corresponding item in the
         * clipboard menu.
         * @langversion 3.0
         * @playerversion   Flash 10
         * @playerversion   AIR 1.5
         */
        flash::ui::ContextMenuClipboardItems* ContextMenu::clipboardItems()                                     ;
        void ContextMenu::clipboardItems(ContextMenuClipboardItems* value)       ;

        /**
         * Creates a ContextMenu object.
         * @langversion 3.0
         * @playerversion   Flash 9
         */
        ContextMenu::ContextMenu();

        /**
         * Hides all built-in menu items (except Settings) in the specified ContextMenu object. If the debugger version of Flash
         * Player is running, the Debugging menu item appears, although it is dimmed for SWF files that
         * do not have remote debugging enabled.
         * 
         *   This method hides only menu items that appear in the standard context menu; it does not affect
         * items that appear in the edit and error menus. This method works by setting all the Boolean members of my_cm.builtInItems to false. You can selectively make a built-in item visible by setting its
         * corresponding member in my_cm.builtInItems to true.
         * Note: In AIR, context menus do not have built-in items. Calling this method will have no effect.
         * @langversion 3.0
         * @playerversion   Flash 9
         */
        void ContextMenu::hideBuiltInItems()       ;

        /**
         * Creates a copy of the menu and all items.
         * @playerversion   AIR 1.0
         */
        flash::display::NativeMenu* ContextMenu::clone()                           ;
}
}

