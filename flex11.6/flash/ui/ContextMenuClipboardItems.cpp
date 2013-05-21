

#include "ContextMenuClipboardItems.h"
#include "flash/ui/ContextMenuClipboardItems.h"

    /**
     * The ContextMenuClipboardItems class lets you enable or disable the commands in the clipboard context menu.
     * 
     *   <p class="- topic/p ">Enable or disable the context menu clipboard commands using the <codeph class="+ topic/ph pr-d/codeph ">clipboardItems</codeph> property of
     * the ContextMenu object. The <codeph class="+ topic/ph pr-d/codeph ">clipboardItems</codeph> property is an instance of this ContextMenuClipboardItems 
     * class. The clipboard context menu is shown in a context menu when the <codeph class="+ topic/ph pr-d/codeph ">clipboardMenu</codeph> property
     * of the context menu is <codeph class="+ topic/ph pr-d/codeph ">true</codeph>, unless the context menu is for a TextField object. TextField objects
     * control the display of the context menu and the state of its clipboard items automatically.</p>
     * @langversion 3.0
     * @playerversion   Flash 10
     * @playerversion   AIR 1.5
     */

using namespace flash::ui;

namespace flash {
namespace ui {


        /**
         * Enables or disables the 'Cut' item on the clipboard menu.
         * This should be enabled only if an object that can be cut is selected.
         * @langversion 3.0
         * @playerversion   Flash 10
         * @playerversion   AIR 1.5
         */
        bool ContextMenuClipboardItems::cut()          ;
        void ContextMenuClipboardItems::cut(bool val)       ;

        /**
         * Enables or disables the 'Copy' item on the clipboard menu.
         * This should be enabled only if an object that can be copied is selected.
         * @langversion 3.0
         * @playerversion   Flash 10
         * @playerversion   AIR 1.5
         */
        bool ContextMenuClipboardItems::copy()          ;
        void ContextMenuClipboardItems::copy(bool val)       ;

        /**
         * Enables or disables the 'Paste' item on the clipboard menu.
         * This should be enabled only if pastable data is on the clipboard.
         * @langversion 3.0
         * @playerversion   Flash 10
         * @playerversion   AIR 1.5
         */
        bool ContextMenuClipboardItems::paste()          ;
        void ContextMenuClipboardItems::paste(bool val)       ;

        /**
         * Enables or disables the 'Delete' or 'Clear' item on the clipboard menu.
         * This should be enabled only if an object that can be cleared is selected.
         * @langversion 3.0
         * @playerversion   Flash 10
         * @playerversion   AIR 1.5
         */
        bool ContextMenuClipboardItems::clear()          ;
        void ContextMenuClipboardItems::clear(bool val)       ;

        /**
         * Enables or disables the 'Select All' item on the clipboard menu.
         * This should only be enabled in a context where a selection can be 
         * expanded to include all similar items, such as in a list or a text editing control.
         * @langversion 3.0
         * @playerversion   Flash 10
         * @playerversion   AIR 1.5
         */
        bool ContextMenuClipboardItems::selectAll()          ;
        void ContextMenuClipboardItems::selectAll(bool val)       ;

        /**
         * Creates a new ContextMenuClipboardItems object.
         * @langversion 3.0
         * @playerversion   Flash 10
         * @playerversion   AIR 1.5
         */
        ContextMenuClipboardItems::ContextMenuClipboardItems();

        ContextMenuClipboardItems* ContextMenuClipboardItems::clone()                            ;
}
}

