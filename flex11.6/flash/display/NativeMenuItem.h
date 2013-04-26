#if !defined(FLEX11_6_FLASH_DISPLAY_NATIVEMENUITEM_AS)
#define FLEX11_6_FLASH_DISPLAY_NATIVEMENUITEM_AS
#if defined(__cplusplus)


#include "flash/events/EventDispatcher.h"

/**
 * Dispatched by this NativeMenuItem object when its key equivalent is pressed and immediately before the containing menu is displayed.
 * @eventType   flash.events.Event.PREPARING
 */
//[Event(name="preparing",type="flash.events.Event")]

/**
 * Dispatched by this NativeMenuItem object immediately before the
 * menu containing the item is displayed.
 * @eventType   flash.events.Event.DISPLAYING
 */
//[Event(name="displaying",type="flash.events.Event")]

/**
 * Dispatched whenever a menu item is selected by the user.
 * @eventType   flash.events.Event.SELECT
 */
//[Event(name="select",type="flash.events.Event")]

/**
 * The NativeMenuItem class represents a single item in a menu.
 *
 *   <p class="- topic/p ">A menu item can be a command, a submenu, or a separator line:</p><ul class="- topic/ul "><li class="- topic/li ">To create a command item, call the NativeMenuItem constructor, passing in a
 * string for the label and <codeph class="+ topic/ph pr-d/codeph ">false</codeph> for the <codeph class="+ topic/ph pr-d/codeph ">isSeparator</codeph>
 * parameter.</li><li class="- topic/li ">To create a submenu, create a command item for the parent menu and
 * assign the NativeMenu object of the submenu to the item's <codeph class="+ topic/ph pr-d/codeph ">submenu</codeph>
 * property. You can also call the <codeph class="+ topic/ph pr-d/codeph ">addSubmenu()</codeph> method of the
 * parent NativeMenu object to create the item and set the <codeph class="+ topic/ph pr-d/codeph ">submenu</codeph>
 * property at the same time.</li><li class="- topic/li ">To create a separator, call the NativeMenuItem constructor, passing in an empty
 * string for the label and <codeph class="+ topic/ph pr-d/codeph ">true</codeph> for the <codeph class="+ topic/ph pr-d/codeph ">isSeparator</codeph>
 * parameter.</li></ul><p class="- topic/p ">Listen for <codeph class="+ topic/ph pr-d/codeph ">select</codeph> events on an item or a parent menu to detect when a
 * menu command is selected. Neither submenus nor separators dispatch
 * select events. Listen for <codeph class="+ topic/ph pr-d/codeph ">preparing</codeph> events to determine when
 * a menu item is about to be displayed or activated through a key equivalent.</p>
 * @langversion 3.0
 * @playerversion   AIR 1.0
 */
using namespace flash::events;

namespace flash
{
    namespace display
    {
        class NativeMenuItem: public EventDispatcher
        {
            /**
             * Controls whether this menu item is enabled.
             * @langversion 3.0
             * @playerversion   AIR 1.0
             */
        public:
            bool         enabled();
        public:
            void         enabled(bool isSeparator);

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
        public:
            NativeMenuItem();
        };
    }
}

#endif // FLEX11_6_FLASH_DISPLAY_NATIVEMENUITEM_AS
#endif // __cplusplus

