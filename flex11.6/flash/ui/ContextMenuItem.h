#if !defined(FLEX11_6_FLASH_UI_CONTEXTMENUITEM_AS)
#define FLEX11_6_FLASH_UI_CONTEXTMENUITEM_AS
#if defined(__cplusplus)


#include "flex11.6.h"
#include "flash/display/NativeMenuItem.h"


/**
 * Dispatched when a user selects an item from a context menu.
 * @eventType   flash.events.ContextMenuEvent.MENU_ITEM_SELECT
 */
//[Event(name="menuItemSelect",type="flash.events.ContextMenuEvent")]

using namespace flash::display;

namespace flash
{
    namespace ui
    {
        /**
         * The ContextMenuItem class represents an item in the context
         * menu. Each ContextMenuItem object has a caption (text) that is displayed in the context menu. To add
         * a new item to a context menu, you add it to the <codeph class="+ topic/ph pr-d/codeph ">customItems</codeph> array of a
         * ContextMenu object.
         *
         *   <p class="- topic/p ">With the properties of the ContextMenuItem class you can enable or disable specific menu items, and you can make
         * items visible or invisible.</p> You write an event handler for the <codeph class="+ topic/ph pr-d/codeph ">menuItemSelect</codeph> event
         * to add functionality to the menu item when the user selects it.
         *
         *   <p class="- topic/p ">Custom menu items appear at the top of the context menu, above any built-in items. A separator bar
         * divides custom menu items from built-in items. In AIR, there are no built-in items and the
         * following restrictions do not apply to content in the AIR application sandbox.</p><p class="- topic/p ">Restrictions:</p><ul class="- topic/ul "><li class="- topic/li ">You can add no more than 15 custom items to a context menu.</li><li class="- topic/li ">Each caption must contain at least one visible character.</li><li class="- topic/li ">Control characters, newlines, and other white space characters are ignored.</li><li class="- topic/li ">No caption can be more than 100 characters long.</li><li class="- topic/li ">Captions that are identical to any built-in menu item, or to another custom item, are ignored,
         * whether the matching item is visible or not. Menu captions are compared to built-in captions or
         * existing custom captions without regard to case, punctuation, or white space.</li><li class="- topic/li ">The following captions are not allowed, but the words may be used in conjunction with other words
         * to form a custom caption (for example, although "Paste" is not allowed, "Paste tastes great" is allowed):
         * <pre xml:space="preserve" class="- topic/pre ">
         * Save
         * Zoom In
         * Zoom Out
         * 100%
         * Show All
         * Quality
         * Play
         * Loop
         * Rewind
         * Forward
         * Back
         * Movie not loaded
         * About
         * Print
         * Show Redraw Regions
         * Debugger
         * Undo
         * Cut
         * Copy
         * Paste
         * Delete
         * Select All
         * Open
         * Open in new window
         * Copy link
         * </pre></li><li class="- topic/li ">None of the following words can appear in a custom caption on their own or in conjunction with other words:
         * <pre xml:space="preserve" class="- topic/pre ">
         * Adobe
         * Macromedia
         * Flash Player
         * Settings
         * </pre></li></ul><p class="- topic/p "><b class="+ topic/ph hi-d/b ">Note:</b> When the player is running on a non-English system, the caption strings are compared to both the English list and the localized equivalents.</p>
         *
         *   EXAMPLE:
         *
         *   The following example uses the class <codeph class="+ topic/ph pr-d/codeph ">ContextMenuBuiltInItemsExample</codeph>
         * to remove the default context menu items from the Stage and add a new menu item.  This is
         * accomplished with the following steps:
         * <ol class="- topic/ol "><li class="- topic/li ">A property <codeph class="+ topic/ph pr-d/codeph ">myContextMenu</codeph> is declared and then assigned to a new ContextMenu
         * object.</li><li class="- topic/li ">The method <codeph class="+ topic/ph pr-d/codeph ">removeDefaultItems()</codeph> is called, which removes all built-in context
         * menu items except Print.</li><li class="- topic/li ">The method <codeph class="+ topic/ph pr-d/codeph ">addCustomMenuItems()</codeph> is called, which places a menu item called
         * <codeph class="+ topic/ph pr-d/codeph ">Hello World</codeph> into the <codeph class="+ topic/ph pr-d/codeph ">customItems</codeph> array by using the
         * <codeph class="+ topic/ph pr-d/codeph ">push()</codeph> method of Array.</li><li class="- topic/li ">The <codeph class="+ topic/ph pr-d/codeph ">Hello World</codeph> context menu item is added to the Stage's context
         * menu item list.</li><li class="- topic/li ">A TextField object with the text "Right Click Here" is added to the stage.</li></ol><codeblock xml:space="preserve" class="+ topic/pre pr-d/codeblock ">
         * package {
         * import flash.ui.ContextMenu;
         * import flash.ui.ContextMenuItem;
         * import flash.ui.ContextMenuBuiltInItems;
         * import flash.display.Sprite;
         * import flash.text.TextField;
         *
         *   public class ContextMenuItemExample extends Sprite {
         * private var myContextMenu:ContextMenu;
         *
         *   public function ContextMenuItemExample() {
         * myContextMenu = new ContextMenu();
         * removeDefaultItems();
         * addCustomMenuItems();
         * this.contextMenu = myContextMenu;
         * addChild(createLabel());
         * }
         *
         *   private function removeDefaultItems():void {
         * myContextMenu.hideBuiltInItems();
         *
         *   var defaultItems:ContextMenuBuiltInItems = myContextMenu.builtInItems;
         * defaultItems.print = true;
         * }
         *
         *   private function addCustomMenuItems():void {
         * var item:ContextMenuItem = new ContextMenuItem("Hello World");
         * myContextMenu.customItems.push(item);
         * }
         *
         *   private function createLabel():TextField {
         * var txtField:TextField = new TextField();
         * txtField.text = "Right Click Here";
         * return txtField;
         * }
         * }
         * }
         * </codeblock>
         * @langversion 3.0
         * @playerversion   Flash 9
         */
        class ContextMenuItem : public flash::display::NativeMenuItem
        {
            /**
             * Specifies the menu item caption (text) displayed in the context menu.
             * See the ContextMenuItem class overview for caption value restrictions.
             * @langversion 3.0
             * @playerversion   Flash 9
             */
        public:
            std::string       caption();
        public:
            void         caption(std::string value);

            /**
             * Indicates whether a separator bar should appear above the specified menu item.
             *
             *   Note: A separator bar always appears between any custom menu items and the
             * built-in menu items.
             * @langversion 3.0
             * @playerversion   Flash 9
             */
        public:
            bool      separatorBefore();
        public:
            void         separatorBefore(bool value);

            /**
             * Indicates whether the specified menu item is visible when the Flash Player
             * context menu is displayed.
             * @langversion 3.0
             * @playerversion   Flash 9
             */
        public:
            bool      visible();
        public:
            void         visible(bool value);

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
        public:
            ContextMenuItem(std::string caption, bool separatorBefore=false, bool enabled=true, bool visible=true);

            /// Creates a copy of the NativeMenuItem object.
        public:
            flash::display::NativeMenuItem *clone();
        };
    }
}

#endif // FLEX11_6_FLASH_UI_CONTEXTMENUITEM_AS
#endif // __cplusplus

