#if !defined(FLEX11_6_FLASH_UI_CONTEXTMENUBUILTINITEMS_AS)
#define FLEX11_6_FLASH_UI_CONTEXTMENUBUILTINITEMS_AS
#if defined(__cplusplus)


#include "flex11.6.h"


/**
 * The ContextMenuBuiltInItems class describes the items that are built in to a context menu.
 * You can hide these items by using the <codeph class="+ topic/ph pr-d/codeph ">ContextMenu.hideBuiltInItems()</codeph> method.
 *
 *   EXAMPLE:
 *
 *   The following example uses the class <codeph class="+ topic/ph pr-d/codeph ">ContextMenuBuiltInItemsExample</codeph>
 * to remove the normal context menu items from the stage and add a new menu item.  This is
 * accomplished with the following steps:
 * <ol class="- topic/ol "><li class="- topic/li ">A property <codeph class="+ topic/ph pr-d/codeph ">myContextMenu</codeph> is declared and then assigned to a new ContextMenu
 * object.</li><li class="- topic/li ">The method <codeph class="+ topic/ph pr-d/codeph ">removeDefaultItems()</codeph> is called, which removes all built-in context
 * menu items except Print.</li><li class="- topic/li ">The method <codeph class="+ topic/ph pr-d/codeph ">addCustomMenuItems()</codeph> is called, which places a menu item called
 * <codeph class="+ topic/ph pr-d/codeph ">Hello World</codeph> into the <codeph class="+ topic/ph pr-d/codeph ">customItems</codeph> array using the
 * <codeph class="+ topic/ph pr-d/codeph ">push()</codeph> method of Array.</li><li class="- topic/li ">The <codeph class="+ topic/ph pr-d/codeph ">Hello World</codeph> menu item is then added to the Stage's context
 * menu item list.</li><li class="- topic/li ">A TextField object with the text "Right Click" is added to the center of the Stage
 * by using <codeph class="+ topic/ph pr-d/codeph ">addChild()</codeph> via <codeph class="+ topic/ph pr-d/codeph ">createLabel()</codeph>.</li></ol><codeblock xml:space="preserve" class="+ topic/pre pr-d/codeblock ">
 * package {
 * import flash.ui.ContextMenu;
 * import flash.ui.ContextMenuItem;
 * import flash.ui.ContextMenuBuiltInItems;
 * import flash.display.Sprite;
 * import flash.text.TextField;
 *
 *   public class ContextMenuBuiltInItemsExample extends Sprite {
 * private var myContextMenu:ContextMenu;
 *
 *   public function ContextMenuBuiltInItemsExample() {
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
 * txtField.text = "Right Click";
 * txtField.x = this.stage.stageWidth/2 - txtField.width/2;
 * txtField.y = this.stage.stageHeight/2 - txtField.height/2;
 * return txtField;
 * }
 * }
 * }
 * </codeblock>
 * @langversion 3.0
 * @playerversion   Flash 9
 */


namespace flash
{
    namespace ui
    {
        class ContextMenuBuiltInItems : public Object
        {
            /**
             * Lets the user with Shockmachine installed save a SWF file.
             * @langversion 3.0
             * @playerversion   Flash 9
             */
        public:
            bool      save();
        public:
            void         save(bool val);

            /**
             * Lets the user zoom in and out on a SWF file at run time.
             * @langversion 3.0
             * @playerversion   Flash 9
             */
        public:
            bool      zoom();
        public:
            void         zoom(bool val);

            /**
             * Lets the user set the resolution of the SWF file at run time.
             * @langversion 3.0
             * @playerversion   Flash 9
             */
        public:
            bool      quality();
        public:
            void         quality(bool val);

            /**
             * Lets the user start a paused SWF file (does not appear for a single-frame SWF file).
             * @langversion 3.0
             * @playerversion   Flash 9
             */
        public:
            bool      play();
        public:
            void         play(bool val);

            /**
             * Lets the user set a SWF file to start over automatically when it reaches the final
             * frame (does not appear for a single-frame SWF file).
             * @langversion 3.0
             * @playerversion   Flash 9
             */
        public:
            bool      loop();
        public:
            void         loop(bool val);

            /**
             * Lets the user set a SWF file to play from the first frame when selected, at any time (does not
             * appear for a single-frame SWF file).
             * @langversion 3.0
             * @playerversion   Flash 9
             */
        public:
            bool      rewind();
        public:
            void         rewind(bool val);

            /**
             * Lets the user move forward or backward one frame in a SWF file at run time (does not
             * appear for a single-frame SWF file).
             * @langversion 3.0
             * @playerversion   Flash 9
             */
        public:
            bool      forwardAndBack();
        public:
            void         forwardAndBack(bool val);

            /**
             * Lets the user send the displayed frame image to a printer.
             * @langversion 3.0
             * @playerversion   Flash 9
             */
        public:
            bool      print();
        public:
            void         print(bool val);

            /**
             * Creates a new ContextMenuBuiltInItems object so that you can set the properties for Flash Player to display or hide each menu item.
             * @langversion 3.0
             * @playerversion   Flash 9
             */
        public:
            ContextMenuBuiltInItems();

        public:
            ContextMenuBuiltInItems *clone();
        };
    }
}

#endif // FLEX11_6_FLASH_UI_CONTEXTMENUBUILTINITEMS_AS
#endif // __cplusplus

