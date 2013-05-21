

#include "InteractiveObject.h"
#include "flash/accessibility/AccessibilityImplementation.h"
#include "flash/geom/Rectangle.h"
#include "flash/ui/ContextMenu.h"
#include "flash/display/DisplayObject.h"
#include "flash/display/NativeMenu.h"

    /**
     * Dispatched immediately after the soft keyboard is lowered.
     * @eventType   flash.events.SoftKeyboardEvent.SOFT_KEYBOARD_DEACTIVATE
     */

using namespace flash::accessibility;
using namespace flash::display;
using namespace flash::geom;
using namespace flash::ui;

namespace flash {
namespace display {


        /**
         * Specifies whether this object is in the tab order. If this object is in the tab order, 
         * the value is true; otherwise, the value is false. By default,
         * the value is false, except for the following:
         * For a SimpleButton object, the value is true.For a TextField object with type = "input", the value is true.For a Sprite object or MovieClip object with buttonMode = true, the value is true.
         * @langversion 3.0
         * @playerversion   Flash 9
         * @internal    FP IMD: See the AS2 MovieClip.tabEnabled, Button.tabEnabled, and 
         *   TextField.tabEnabled topics for information to migrate to the ASDoc description of this 
         *   property.
         */
        bool InteractiveObject::tabEnabled()          ;
        void InteractiveObject::tabEnabled(bool enabled)       ;

        /**
         * Specifies the tab ordering of objects in a SWF file. The tabIndex 
         * property is -1 by default, meaning no tab index is set for the object.
         * 
         *   If any currently displayed object in the SWF file contains a tabIndex property, automatic 
         * tab ordering is disabled, and the tab ordering is calculated from the tabIndex properties of 
         * objects in the SWF file. The custom tab ordering includes only objects that have tabIndex 
         * properties.The tabIndex property can be a non-negative integer. The objects are ordered according to 
         * their tabIndex properties, in ascending order. An object with a tabIndex 
         * value of 1 precedes an object with a tabIndex value of 2. Do not use the same tabIndex
         * 
         *   value for multiple objects.The custom tab ordering that the tabIndex property defines is flat. 
         * This means that no attention is paid to the hierarchical relationships of objects in the SWF file. 
         * All objects in the SWF file with tabIndex properties are placed in the tab order, and the 
         * tab order is determined by the order of the tabIndex values. Note: To set the tab order for TLFTextField instances, cast the display object child 
         * of the TLFTextField as an InteractiveObject, then set the tabIndex property. For example:
         * 
         *   InteractiveObject(tlfInstance.getChildAt(1)).tabIndex = 3;
         * 
         *   To reverse the tab order from the default setting for three instances of a TLFTextField object 
         * (tlfInstance1, tlfInstance2 and tlfInstance3), use:
         * 
         *   InteractiveObject(tlfInstance1.getChildAt(1)).tabIndex = 3;
         * InteractiveObject(tlfInstance2.getChildAt(1)).tabIndex = 2;
         * InteractiveObject(tlfInstance3.getChildAt(1)).tabIndex = 1;
         * @langversion 3.0
         * @playerversion   Flash 9
         */
        int InteractiveObject::tabIndex()      ;
        void InteractiveObject::tabIndex(int index)       ;

        /**
         * Specifies whether this object displays a focus rectangle. It can take one of three 
         * values: true, false, or null. Values of true 
         * and false work as expected, specifying whether or not the focus rectangle 
         * appears. A value of null indicates that this object obeys the 
         * stageFocusRect property of the Stage.
         * @langversion 3.0
         * @playerversion   Flash 9
         * @playerversion   Lite 4
         * @internal    FP IMD: See the AS2 MovieClip._focusRect, Button._focusRect, and 
         *   _focusRect (global property) topics for information to migrate to the ASDoc description of this 
         *   property.
         */
        Object* InteractiveObject::focusRect()         ;
        void InteractiveObject::focusRect(Object* focusRect)       ;

        /**
         * Specifies whether this object receives mouse, or other user input, messages. The default value is true,
         * which means that by default any InteractiveObject instance that is on the display list
         * receives mouse events or other user input events.
         * If mouseEnabled is set to false, the instance does not receive any
         * mouse events (or other user input events like keyboard events). Any children of this instance on the display list are not affected. To change
         * the mouseEnabled behavior for all children of an object on the display list, use
         * flash.display.DisplayObjectContainer.mouseChildren.
         * No event is dispatched by setting this property. You must use the 
         * addEventListener() method to create interactive functionality.
         * @langversion 3.0
         * @playerversion   Flash 9
         * @playerversion   Lite 4
         */
        bool InteractiveObject::mouseEnabled()          ;
        void InteractiveObject::mouseEnabled(bool enabled)       ;

        /**
         * Specifies whether the object receives doubleClick events. The default value 
         * is false, which means that by default an InteractiveObject instance does not receive
         * doubleClick events. If the doubleClickEnabled property is set to 
         * true, the instance receives doubleClick events within its bounds. 
         * The mouseEnabled property of the InteractiveObject instance must also be 
         * set to true for the object to receive doubleClick events.
         * 
         *   No event is dispatched by setting this property. You must use the
         * addEventListener() method to add an event listener 
         * for the doubleClick event.
         * @langversion 3.0
         * @playerversion   Flash 9
         */
        bool InteractiveObject::doubleClickEnabled()          ;
        void InteractiveObject::doubleClickEnabled(bool enabled)       ;

        /**
         * The current accessibility implementation (AccessibilityImplementation)  
         * for this InteractiveObject instance.
         * @langversion 3.0
         */
        flash::accessibility::AccessibilityImplementation* InteractiveObject::accessibilityImplementation()                                                  ;
        void InteractiveObject::accessibilityImplementation(AccessibilityImplementation* value)       ;

        /**
         * Defines the area that should remain on-screen when a soft keyboard is displayed.
         * 
         *   If the needsSoftKeyboard property of this InteractiveObject is
         * true, then the runtime adjusts the display as needed to keep the 
         * object in view while the user types. Ordinarily, the runtime uses the object
         * bounds obtained from the DisplayObject.getBounds() method. You can
         * specify a different area using this softKeyboardInputAreaOfInterest
         * property.Specify the softKeyboardInputAreaOfInterest in stage coordinates.Note: On Android, the softKeyboardInputAreaOfInterest is not
         * respected in landscape orientations.
         * @langversion 3.0
         * @playerversion   Flash 10.2
         * @playerversion   AIR 2.6
         */
        flash::geom::Rectangle* InteractiveObject::softKeyboardInputAreaOfInterest()                       ;
        void InteractiveObject::softKeyboardInputAreaOfInterest(Rectangle* value)       ;

        /**
         * Specifies whether a virtual keyboard (an on-screen, software keyboard) should display 
         * when this InteractiveObject instance receives focus.
         * 
         *   By default, the value is false and focusing an InteractiveObject instance does 
         * not raise a soft keyboard. If the needsSoftKeyboard property is set to true, 
         * the runtime raises a soft keyboard when the InteractiveObject instance is ready to accept user input.
         * An InteractiveObject instance is ready to accept user input after a programmatic call to set the Stage
         * focus property or a user interaction, such as a "tap." If the client system has a
         * hardware keyboard available or does not support virtual keyboards, then the soft keyboard is not raised.The InteractiveObject instance dispatches softKeyboardActivating, 
         * softKeyboardActivate, and softKeyboardDeactivate events  
         * when the soft keyboard raises and lowers.Note: This property is not supported in AIR applications on iOS.
         * @langversion 3.0
         * @playerversion   Flash 10.2
         * @playerversion   AIR 2.6
         */
        bool InteractiveObject::needsSoftKeyboard()          ;
        void InteractiveObject::needsSoftKeyboard(bool value)       ;

        /**
         * Specifies the context menu associated with this object.
         * 
         *   For content running in Flash Player, this property is a ContextMenu object. In the AIR runtime, 
         * the ContextMenu class extends the NativeMenu class, however Flash Player only supports the 
         * ContextMenu class, not the NativeMenu class.
         * Note: TextField objects always include a clipboard menu in the context menu. The clipboard menu contains
         * Cut, Copy, Paste, Clear, and Select All commands. You cannot remove these commands from the context menu for TextField objects. 
         * For TextField objects, selecting these commands (or their keyboard equivalents) does not generate clear, 
         * copy, cut, paste, or selectAll events.
         * @langversion 3.0
         * @playerversion   Flash 9
         * @playerversion   Lite 4
         */
        flash::display::NativeMenu* InteractiveObject::contextMenu()                           ;
        void InteractiveObject::contextMenu(ContextMenu* cm)       ;

        /**
         * Calling the new InteractiveObject() constructor 
         * throws an ArgumentError exception. 
         * You can, however, call constructors for the following subclasses of InteractiveObject:
         * 
         *   new SimpleButton()new TextField()new Loader()new Sprite()new MovieClip()
         * @langversion 3.0
         * @playerversion   Flash 9
         * @playerversion   Lite 4
         */
        InteractiveObject::InteractiveObject();

        /**
         * Raises a virtual keyboard.
         * 
         *   Calling this method focuses the InteractiveObject instance and raises the soft keyboard, if necessary.
         * The needsSoftKeyboard must also be true. A keyboard is not raised
         * if a hardware keyboard is available, or if the client system does not support virtual keyboards.Note: This method is not supported in AIR applications on iOS.
         * @return  A value of true means that the soft keyboard request was granted; false means that the soft keyboard was not raised.
         * @langversion 3.0
         * @playerversion   Flash 10.2
         * @playerversion   AIR 2.6
         */
        bool InteractiveObject::requestSoftKeyboard()          ;
}
}

