

#include "MouseEvent.h"
#include "flash/display/InteractiveObject.h"
#include "flash/events/Event.h"

    /// @eventType  flash.events.MouseEvent.CLICK

using namespace flash::display;
using namespace flash::events;

namespace flash {
namespace events {


        /**
         * Defines the value of the type property of a click event object.
         * 
         *   This event has the following properties:PropertyValuealtKeytrue if the Alt key is active (Windows).bubblestruebuttonDownFor click events, this value is always false.cancelablefalse; there is no default behavior to cancel.commandKeytrue on the Mac if the Command key is active; false if it is inactive. Always false on Windows.controlKeytrue if the Ctrl or Control key is active; false if it is inactive.ctrlKeytrue on Windows or Linux if the Ctrl key is active. true on Mac if either the Ctrl key or the Command key is active. Otherwise, false.currentTargetThe object that is actively processing the Event 
         * object with an event listener.localXThe horizontal coordinate at which the event occurred relative to the containing sprite.localYThe vertical coordinate at which the event occurred relative to the containing sprite.shiftKeytrue if the Shift key is active; false if it is inactive.stageXThe horizontal coordinate at which the event occurred in global stage coordinates.stageYThe vertical coordinate at which the event occurred in global stage coordinates.targetThe InteractiveObject instance under the pointing device. 
         * The target is not always the object in the display list 
         * that registered the event listener. Use the currentTarget 
         * property to access the object in the display list that is currently processing the event.
         * @langversion 3.0
         * @playerversion   Flash 9
         * @playerversion   Lite 4
         */
        const std::string MouseEvent::CLICK   = "click";

        /**
         * Defines the value of the type property of a doubleClick event object. The doubleClickEnabled property 
         * must be true for an object to generate the doubleClick event.
         * 
         *   This event has the following properties:PropertyValuealtKeytrue if the Alt key is active (Windows).bubblestruebuttonDownFor double-click events, this value is always false.cancelablefalse; there is no default behavior to cancel.commandKeytrue on the Mac if the Command key is active; false if it is inactive. Always false on Windows.controlKeytrue if the Ctrl or Control key is active; false if it is inactive.ctrlKeytrue on Windows or Linux if the Ctrl key is active. true on Mac if either the Ctrl key or the Command key is active. Otherwise, false.currentTargetThe object that is actively processing the Event 
         * object with an event listener.localXThe horizontal coordinate at which the event occurred relative to the containing sprite.localYThe vertical coordinate at which the event occurred relative to the containing sprite.shiftKeytrue if the Shift key is active; false if it is inactive.stageXThe horizontal coordinate at which the event occurred in global stage coordinates.stageYThe vertical coordinate at which the event occurred in global stage coordinates.targetThe InteractiveObject instance under the pointing device. 
         * The target is not always the object in the display list 
         * that registered the event listener. Use the currentTarget 
         * property to access the object in the display list that is currently processing the event.
         * @langversion 3.0
         * @playerversion   Flash 9
         * @playerversion   Lite 4
         */
        const std::string MouseEvent::DOUBLE_CLICK   = "doubleClick";

        /**
         * Defines the value of the type property of a mouseDown event object. 
         * This event has the following properties:PropertyValuealtKeytrue if the Alt key is active (Windows).bubblestruebuttonDowntrue if the primary mouse button is pressed; false otherwise.cancelablefalse; the default behavior cannot be canceled.commandKeytrue on the Mac if the Command key is active; false if it is inactive. Always false on Windows.controlKeytrue if the Ctrl or Control key is active; false if it is inactive.ctrlKeytrue on Windows and Linux if the Ctrl key is active. true on Mac if either the Ctrl key or the Command key is active. Otherwise, false.currentTargetThe object that is actively processing the Event 
         * object with an event listener.localXThe horizontal coordinate at which the event occurred relative to the containing sprite.localYThe vertical coordinate at which the event occurred relative to the containing sprite.shiftKeytrue if the Shift key is active; false if it is inactive.clickCountCount of the number of mouse clicks to indicate whether the event is part of a multi-click sequence.stageXThe horizontal coordinate at which the event occurred in global stage coordinates.stageYThe vertical coordinate at which the event occurred in global stage coordinates.targetThe InteractiveObject instance under the pointing device. 
         * The target is not always the object in the display list 
         * that registered the event listener. Use the currentTarget 
         * property to access the object in the display list that is currently processing the event.
         * @langversion 3.0
         * @playerversion   Flash 9
         * @playerversion   Lite 4
         */
        const std::string MouseEvent::MOUSE_DOWN   = "mouseDown";

        /**
         * Defines the value of the type property of a mouseMove event object.
         * 
         *   This event has the following properties:PropertyValuealtKeytrue if the Alt key is active (Windows).bubblestruebuttonDowntrue if the primary mouse button is pressed; false otherwise.cancelablefalse; the default behavior cannot be canceled.commandKeytrue on the Mac if the Command key is active; false if it is inactive. Always false on Windows.controlKeytrue if the Ctrl or Control key is active; false if it is inactive.ctrlKeytrue on Windows or Linux if the Ctrl key is active. true on Mac if either the Ctrl key or the Command key is active. Otherwise, false.currentTargetThe object that is actively processing the Event 
         * object with an event listener.localXThe horizontal coordinate at which the event occurred relative to the containing sprite.localYThe vertical coordinate at which the event occurred relative to the containing sprite.shiftKeytrue if the Shift key is active; false if it is inactive.stageXThe horizontal coordinate at which the event occurred in global stage coordinates.stageYThe vertical coordinate at which the event occurred in global stage coordinates.targetThe InteractiveObject instance under the pointing device. 
         * The target is not always the object in the display list 
         * that registered the event listener. Use the currentTarget 
         * property to access the object in the display list that is currently processing the event.
         * @langversion 3.0
         * @playerversion   Flash 9
         * @playerversion   Lite 4
         */
        const std::string MouseEvent::MOUSE_MOVE   = "mouseMove";

        /**
         * Defines the value of the type property of a mouseOut event object.
         * 
         *   This event has the following properties:PropertyValuealtKeytrue if the Alt key is active (Windows).bubblestruebuttonDowntrue if the primary mouse button is pressed; false otherwise.cancelablefalse; the default behavior cannot be canceled.commandKeytrue on the Mac if the Command key is active; false if it is inactive. Always false on Windows.controlKeytrue if the Ctrl or Control key is active; false if it is inactive.ctrlKeytrue on Windows or Linux if the Ctrl key is active. true on Mac if either the Ctrl key or the Command key is active. Otherwise, false.currentTargetThe object that is actively processing the Event 
         * object with an event listener.relatedObjectThe display list object to which the pointing device now points.localXThe horizontal coordinate at which the event occurred relative to the containing sprite.localYThe vertical coordinate at which the event occurred relative to the containing sprite.shiftKeytrue if the Shift key is active; false if it is inactive.stageXThe horizontal coordinate at which the event occurred in global stage coordinates.stageYThe vertical coordinate at which the event occurred in global stage coordinates.targetThe InteractiveObject instance under the pointing device. 
         * The target is not always the object in the display list 
         * that registered the event listener. Use the currentTarget 
         * property to access the object in the display list that is currently processing the event.
         * @langversion 3.0
         * @playerversion   Flash 9
         * @playerversion   Lite 4
         */
        const std::string MouseEvent::MOUSE_OUT   = "mouseOut";

        /**
         * Defines the value of the type property of a mouseOver event object.
         * 
         *   This event has the following properties:PropertyValuealtKeytrue if the Alt key is active (Windows).bubblestruebuttonDowntrue if the primary mouse button is pressed; false otherwise.cancelablefalse; the default behavior cannot be canceled.commandKeytrue on the Mac if the Command key is active; false if it is inactive. Always false on Windows.controlKeytrue if the Ctrl or Control key is active; false if it is inactive.ctrlKeytrue on Windows or Linux if the Ctrl key is active. true on Mac if either the Ctrl key or the Command key is active. Otherwise, false.currentTargetThe object that is actively processing the Event 
         * object with an event listener.relatedObjectThe display list object to which the pointing device was pointing.localXThe horizontal coordinate at which the event occurred relative to the containing sprite.localYThe vertical coordinate at which the event occurred relative to the containing sprite.shiftKeytrue if the Shift key is active; false if it is inactive.stageXThe horizontal coordinate at which the event occurred in global stage coordinates.stageYThe vertical coordinate at which the event occurred in global stage coordinates.targetThe InteractiveObject instance under the pointing device. 
         * The target is not always the object in the display list 
         * that registered the event listener. Use the currentTarget 
         * property to access the object in the display list that is currently processing the event.
         * @langversion 3.0
         * @playerversion   Flash 9
         * @playerversion   Lite 4
         */
        const std::string MouseEvent::MOUSE_OVER   = "mouseOver";

        /**
         * Defines the value of the type property of a mouseUp event object.
         * 
         *   This event has the following properties:PropertyValuealtKeytrue if the Alt key is active (Windows).bubblestruebuttonDowntrue if the primary mouse button is pressed; false otherwise.cancelablefalse; the default behavior cannot be canceled.commandKeytrue on the Mac if the Command key is active; false if it is inactive. Always false on Windows.controlKeytrue if the Ctrl or Control key is active; false if it is inactive.ctrlKeytrue on Windows or Linux if the Ctrl key is active. true on Mac if either the Ctrl key or the Command key is active. Otherwise, false.currentTargetThe object that is actively processing the Event 
         * object with an event listener.localXThe horizontal coordinate at which the event occurred relative to the containing sprite.localYThe vertical coordinate at which the event occurred relative to the containing sprite.shiftKeytrue if the Shift key is active; false if it is inactive.clickCountCount of the number of mouse clicks to indicate whether the event is part of a multi-click sequence.stageXThe horizontal coordinate at which the event occurred in global stage coordinates.stageYThe vertical coordinate at which the event occurred in global stage coordinates.targetThe InteractiveObject instance under the pointing device. 
         * The target is not always the object in the display list 
         * that registered the event listener. Use the currentTarget 
         * property to access the object in the display list that is currently processing the event.
         * @langversion 3.0
         * @playerversion   Flash 9
         * @playerversion   Lite 4
         */
        const std::string MouseEvent::MOUSE_UP   = "mouseUp";
        const std::string MouseEvent::RELEASE_OUTSIDE  ;

        /**
         * Defines the value of the type property of a mouseWheel event object.
         * 
         *   This event has the following properties:PropertyValuealtKeytrue if the Alt key is active (Windows).bubblestruebuttonDowntrue if the primary mouse button is pressed; false otherwise.cancelablefalse; the default behavior cannot be canceled.commandKeytrue on the Mac if the Command key is active; false if it is inactive. Always false on Windows.controlKeytrue if the Ctrl or Control key is active; false if it is inactive.ctrlKeytrue on Windows or Linux if the Ctrl key is active. true on Mac if either the Ctrl key or the Command key is active. Otherwise, false.currentTargetThe object that is actively processing the Event 
         * object with an event listener.deltaThe number of lines that that each notch on the mouse wheel represents.localXThe horizontal coordinate at which the event occurred relative to the containing sprite.localYThe vertical coordinate at which the event occurred relative to the containing sprite.shiftKeytrue if the Shift key is active; false if it is inactive.stageXThe horizontal coordinate at which the event occurred in global stage coordinates.stageYThe vertical coordinate at which the event occurred in global stage coordinates.targetThe InteractiveObject instance under the pointing device. 
         * The target is not always the object in the display list 
         * that registered the event listener. Use the currentTarget 
         * property to access the object in the display list that is currently processing the event.
         * @langversion 3.0
         * @playerversion   Flash 9
         */
        const std::string MouseEvent::MOUSE_WHEEL   = "mouseWheel";

        /**
         * Defines the value of the type property of a rollOut event object.
         * 
         *   This event has the following properties:PropertyValuealtKeytrue if the Alt key is active (Windows).bubblesfalsebuttonDowntrue if the primary mouse button is pressed; false otherwise.cancelablefalse; there is no default behavior to cancel.commandKeytrue on the Mac if the Command key is active; false if it is inactive. Always false on Windows.controlKeytrue if the Ctrl or Control key is active; false if it is inactive.ctrlKeytrue on Windows or Linux if the Ctrl key is active. true on Mac if either the Ctrl key or the Command key is active. Otherwise, false.currentTargetThe object that is actively processing the Event 
         * object with an event listener.relatedObjectThe display list object to which the pointing device now points.localXThe horizontal coordinate at which the event occurred relative to the containing sprite.localYThe vertical coordinate at which the event occurred relative to the containing sprite.shiftKeytrue if the Shift key is active; false if it is inactive.stageXThe horizontal coordinate at which the event occurred in global stage coordinates.stageYThe vertical coordinate at which the event occurred in global stage coordinates.targetThe InteractiveObject instance under the pointing device. 
         * The target is not always the object in the display list 
         * that registered the event listener. Use the currentTarget 
         * property to access the object in the display list that is currently processing the event.
         * @langversion 3.0
         * @playerversion   Flash 9
         * @playerversion   Lite 4
         */
        const std::string MouseEvent::ROLL_OUT   = "rollOut";

        /**
         * Defines the value of the type property of a rollOver event object.
         * 
         *   This event has the following properties:PropertyValuealtKeytrue if the Alt key is active (Windows).bubblesfalsebuttonDowntrue if the primary mouse button is pressed; false otherwise.cancelablefalse; there is no default behavior to cancel.commandKeytrue on the Mac if the Command key is active; false if it is inactive. Always false on Windows.controlKeytrue if the Ctrl or Control key is active; false if it is inactive.ctrlKeytrue on Windows or Linux if the Ctrl key is active. true on Mac if either the Ctrl key or the Command key is active. Otherwise, false.currentTargetThe object that is actively processing the Event 
         * object with an event listener.relatedObjectThe display list object to which the pointing device was pointing.localXThe horizontal coordinate at which the event occurred relative to the containing sprite.localYThe vertical coordinate at which the event occurred relative to the containing sprite.shiftKeytrue if the Shift key is active; false if it is inactive.stageXThe horizontal coordinate at which the event occurred in global stage coordinates.stageYThe vertical coordinate at which the event occurred in global stage coordinates.targetThe InteractiveObject instance under the pointing device. 
         * The target is not always the object in the display list 
         * that registered the event listener. Use the currentTarget 
         * property to access the object in the display list that is currently processing the event.
         * @langversion 3.0
         * @playerversion   Flash 9
         * @playerversion   Lite 4
         */
        const std::string MouseEvent::ROLL_OVER   = "rollOver";

        /**
         * Defines the value of the type property of a middleClick event object.
         * 
         *   This event has the following properties:PropertyValuealtKeytrue if the Alt key is active (Windows).bubblestruebuttonDownFor middle-click events, this property is always false.cancelablefalse; there is no default behavior to cancel.commandKeytrue on the Mac if the Command key is active; false if it is inactive. Always false on Windows.controlKeytrue if the Ctrl or Control key is active; false if it is inactive.ctrlKeytrue on Windows or Linux if the Ctrl key is active. true on Mac if either the Ctrl key or the Command key is active. Otherwise, false.currentTargetThe object that is actively processing the Event 
         * object with an event listener.localXThe horizontal coordinate at which the event occurred relative to the containing sprite.localYThe vertical coordinate at which the event occurred relative to the containing sprite.shiftKeytrue if the Shift key is active; false if it is inactive.stageXThe horizontal coordinate at which the event occurred in global stage coordinates.stageYThe vertical coordinate at which the event occurred in global stage coordinates.targetThe InteractiveObject instance under the pointing device. 
         * The target is not always the object in the display list 
         * that registered the event listener. Use the currentTarget 
         * property to access the object in the display list that is currently processing the event.
         * @langversion 3.0
         * @playerversion   AIR 1.0
         * @playerversion   Lite 4
         */
        const std::string MouseEvent::MIDDLE_CLICK   = "middleClick";

        /**
         * Defines the value of the type property of a middleMouseDown event object. 
         * This event has the following properties:PropertyValuealtKeytrue if the Alt key is active (Windows).bubblestruebuttonDowntrue if the middle mouse button is pressed; false otherwise.cancelablefalse; the default behavior cannot be canceled.commandKeytrue on the Mac if the Command key is active; false if it is inactive. Always false on Windows.controlKeytrue if the Ctrl or Control key is active; false if it is inactive.ctrlKeytrue on Windows or Linux if the Ctrl key is active. true on Mac if either the Ctrl key or the Command key is active. Otherwise, false.currentTargetThe object that is actively processing the Event 
         * object with an event listener.localXThe horizontal coordinate at which the event occurred relative to the containing sprite.localYThe vertical coordinate at which the event occurred relative to the containing sprite.shiftKeytrue if the Shift key is active; false if it is inactive.clickCountCount of the number of mouse clicks to indicate whether the event is part of a multi-click sequence.stageXThe horizontal coordinate at which the event occurred in global stage coordinates.stageYThe vertical coordinate at which the event occurred in global stage coordinates.targetThe InteractiveObject instance under the pointing device. 
         * The target is not always the object in the display list 
         * that registered the event listener. Use the currentTarget 
         * property to access the object in the display list that is currently processing the event.
         * @langversion 3.0
         * @playerversion   AIR 1.0
         * @playerversion   Lite 4
         */
        const std::string MouseEvent::MIDDLE_MOUSE_DOWN   = "middleMouseDown";

        /**
         * Defines the value of the type property of a middleMouseUp event object.
         * 
         *   This event has the following properties:PropertyValuealtKeytrue if the Alt key is active (Windows).bubblestruebuttonDowntrue if the middle mouse button is pressed; false otherwise.cancelablefalse; the default behavior cannot be canceled.commandKeytrue on the Mac if the Command key is active; false if it is inactive. Always false on Windows.controlKeytrue if the Ctrl or Control key is active; false if it is inactive.ctrlKeytrue on Windows or Linux if the Ctrl key is active. true on Mac if either the Ctrl key or the Command key is active. Otherwise, false.currentTargetThe object that is actively processing the Event 
         * object with an event listener.localXThe horizontal coordinate at which the event occurred relative to the containing sprite.localYThe vertical coordinate at which the event occurred relative to the containing sprite.shiftKeytrue if the Shift key is active; false if it is inactive.clickCountCount of the number of mouse clicks to indicate whether the event is part of a multi-click sequence.stageXThe horizontal coordinate at which the event occurred in global stage coordinates.stageYThe vertical coordinate at which the event occurred in global stage coordinates.targetThe InteractiveObject instance under the pointing device. 
         * The target is not always the object in the display list 
         * that registered the event listener. Use the currentTarget 
         * property to access the object in the display list that is currently processing the event.
         * @langversion 3.0
         * @playerversion   AIR 1.0
         * @playerversion   Lite 4
         */
        const std::string MouseEvent::MIDDLE_MOUSE_UP   = "middleMouseUp";

        /**
         * Defines the value of the type property of a rightClick event object.
         * 
         *   This event has the following properties:PropertyValuealtKeytrue if the Alt key is active (Windows).bubblestruebuttonDownFor right-click events, this property is always false.cancelablefalse; there is no default behavior to cancel.commandKeytrue on the Mac if the Command key is active; false if it is inactive. Always false on Windows.controlKeytrue if the Ctrl or Control key is active; false if it is inactive.ctrlKeytrue on Windows or Linux if the Ctrl key is active. true on Mac if either the Ctrl key or the Command key is active. Otherwise, false.currentTargetThe object that is actively processing the Event 
         * object with an event listener.localXThe horizontal coordinate at which the event occurred relative to the containing sprite.localYThe vertical coordinate at which the event occurred relative to the containing sprite.shiftKeytrue if the Shift key is active; false if it is inactive.stageXThe horizontal coordinate at which the event occurred in global stage coordinates.stageYThe vertical coordinate at which the event occurred in global stage coordinates.targetThe InteractiveObject instance under the pointing device. 
         * The target is not always the object in the display list 
         * that registered the event listener. Use the currentTarget 
         * property to access the object in the display list that is currently processing the event.
         * @langversion 3.0
         * @playerversion   AIR 1.0
         * @playerversion   Lite 4
         */
        const std::string MouseEvent::RIGHT_CLICK   = "rightClick";

        /**
         * Defines the value of the type property of a rightMouseDown event object. 
         * This event has the following properties:PropertyValuealtKeytrue if the Alt key is active (Windows).bubblestruebuttonDownFor right-click events, this property is always true.cancelablefalse; the default behavior cannot be canceled.commandKeytrue on the Mac if the Command key is active; false if it is inactive. Always false on Windows.controlKeytrue if the Ctrl or Control key is active; false if it is inactive.ctrlKeytrue on Windows or Linux if the Ctrl key is active. true on Mac if either the Ctrl key or the Command key is active. Otherwise, false.currentTargetThe object that is actively processing the Event 
         * object with an event listener.localXThe horizontal coordinate at which the event occurred relative to the containing sprite.localYThe vertical coordinate at which the event occurred relative to the containing sprite.shiftKeytrue if the Shift key is active; false if it is inactive.clickCountCount of the number of mouse clicks to indicate whether the event is part of a multi-click sequence.stageXThe horizontal coordinate at which the event occurred in global stage coordinates.stageYThe vertical coordinate at which the event occurred in global stage coordinates.targetThe InteractiveObject instance under the pointing device. 
         * The target is not always the object in the display list 
         * that registered the event listener. Use the currentTarget 
         * property to access the object in the display list that is currently processing the event.
         * @langversion 3.0
         * @playerversion   AIR 1.0
         * @playerversion   Lite 4
         */
        const std::string MouseEvent::RIGHT_MOUSE_DOWN   = "rightMouseDown";

        /**
         * Defines the value of the type property of a rightMouseUp event object.
         * 
         *   This event has the following properties:PropertyValuealtKeytrue if the Alt key is active (Windows).bubblestruebuttonDowntrue if the right mouse button is pressed; false otherwise.cancelablefalse; the default behavior cannot be canceled.commandKeytrue on the Mac if the Command key is active; false if it is inactive. Always false on Windows.controlKeytrue if the Ctrl or Control key is active; false if it is inactive.ctrlKeytrue on Windows or Linux if the Ctrl key is active. true on Mac if either the Ctrl key or the Command key is active. Otherwise, false.currentTargetThe object that is actively processing the Event 
         * object with an event listener.localXThe horizontal coordinate at which the event occurred relative to the containing sprite.localYThe vertical coordinate at which the event occurred relative to the containing sprite.shiftKeytrue if the Shift key is active; false if it is inactive.clickCountCount of the number of mouse clicks to indicate whether the event is part of a multi-click sequence.stageXThe horizontal coordinate at which the event occurred in global stage coordinates.stageYThe vertical coordinate at which the event occurred in global stage coordinates.targetThe InteractiveObject instance under the pointing device. 
         * The target is not always the object in the display list 
         * that registered the event listener. Use the currentTarget 
         * property to access the object in the display list that is currently processing the event.
         * @langversion 3.0
         * @playerversion   AIR 1.0
         * @playerversion   Lite 4
         */
        const std::string MouseEvent::RIGHT_MOUSE_UP   = "rightMouseUp";

        /**
         * The MouseEvent.CONTEXT_MENU constant defines the value of the 
         * type property of a contextMenu event object.
         * 
         *   This event has the following properties:PropertyValuealtKeytrue if the Alt key is active (Windows).bubblestruebuttonDowntrue if the right mouse button is pressed; false otherwise.cancelablefalse; the default behavior cannot be canceled.commandKeytrue on the Mac if the Command key is active; false if it is inactive. Always false on Windows.controlKeytrue if the Ctrl or Control key is active; false if it is inactive.ctrlKeytrue on Windows or Linux if the Ctrl key is active. true on Mac if either the Ctrl key or the Command key is active. Otherwise, false.currentTargetThe object that is actively processing the Event 
         * object with an event listener.localXThe horizontal coordinate at which the event occurred relative to the containing sprite.localYThe vertical coordinate at which the event occurred relative to the containing sprite.shiftKeytrue if the Shift key is active; false if it is inactive.clickCountCount of the number of mouse clicks to indicate whether the event is part of a multi-click sequence.stageXThe horizontal coordinate at which the event occurred in global stage coordinates.stageYThe vertical coordinate at which the event occurred in global stage coordinates.targetThe InteractiveObject instance under the pointing device. 
         * The target is not always the object in the display list 
         * that registered the event listener. Use the currentTarget 
         * property to access the object in the display list that is currently processing the event.
         * @langversion 3.0
         * @playerversion   AIR 1.0
         * @playerversion   Lite 4
         */
        const std::string MouseEvent::CONTEXT_MENU   = "contextMenu";

        /**
         * The horizontal coordinate at which the event occurred relative to the containing sprite.
         * @langversion 3.0
         * @playerversion   Flash 9
         * @playerversion   Lite 4
         */
        float MouseEvent::localX()         ;
        void MouseEvent::localX(float value)       ;

        /**
         * The vertical coordinate at which the event occurred relative to the containing sprite.
         * @langversion 3.0
         * @playerversion   Flash 9
         * @playerversion   Lite 4
         */
        float MouseEvent::localY()         ;
        void MouseEvent::localY(float value)       ;

        /**
         * A reference to a display list object that is related to the event. For example, when a mouseOut event occurs, 
         * relatedObject represents the display list object to which the pointing device now points. 
         * This property applies to the mouseOut, mouseOver, rollOut, and rollOver events.
         * The value of this property can be null in two circumstances: if there no related object, 
         * or there is a related object, but it is in a security sandbox to which you don't have access.
         * Use the isRelatedObjectInaccessible() property to determine which of these reasons applies.
         * @langversion 3.0
         * @playerversion   Flash 9
         * @playerversion   Lite 4
         */
        flash::display::InteractiveObject* MouseEvent::relatedObject()                                  ;
        void MouseEvent::relatedObject(InteractiveObject* value)       ;

        /**
         * On Windows or Linux, indicates whether the Ctrl key is active (true) or inactive (false).
         * On Macintosh, indicates whether either the Control key or the Command key is activated.
         * @langversion 3.0
         * @playerversion   Flash 9
         * @playerversion   Lite 4
         */
        bool MouseEvent::ctrlKey()          ;
        void MouseEvent::ctrlKey(bool value)       ;

        /**
         * Indicates whether the Alt key is active (true) or inactive (false).
         * Supported for Windows only. On other operating systems, this property is always set to false.
         * @langversion 3.0
         * @playerversion   Flash 9
         * @playerversion   Lite 4
         * @internal    Reserved in case Desktop Player wants to capture this key in a future implementation.
         *   The Option key modifier on Macintosh system must be represented using this key modifier. So far, it seems
         *   only the Windows version is hooked up.
         */
        bool MouseEvent::altKey()          ;
        void MouseEvent::altKey(bool value)       ;

        /**
         * Indicates whether the Shift key is active (true) or inactive 
         * (false).
         * @langversion 3.0
         * @playerversion   Flash 9
         * @playerversion   Lite 4
         */
        bool MouseEvent::shiftKey()          ;
        void MouseEvent::shiftKey(bool value)       ;

        /**
         * Indicates whether the primary mouse button is pressed (true) or not (false).
         * @langversion 3.0
         * @playerversion   Flash 9
         * @playerversion   Lite 4
         */
        bool MouseEvent::buttonDown()          ;
        void MouseEvent::buttonDown(bool value)       ;

        /**
         * Indicates how many lines should be scrolled for each unit the user rotates the 
         * mouse wheel. A positive delta value indicates an upward scroll; a negative 
         * value indicates a downward scroll. Typical values are 1 to 3, but faster 
         * rotation may produce larger values. This setting depends on the device 
         * and operating system and is usually configurable by the user. This 
         * property applies only to the MouseEvent.mouseWheel event.
         * @langversion 3.0
         * @playerversion   Flash 9
         * @playerversion   Lite 4
         */
        int MouseEvent::delta()      ;
        void MouseEvent::delta(int value)       ;

        /**
         * The horizontal coordinate at which the event occurred in global Stage coordinates.  
         * This property is calculated when the localX property is set.
         * @langversion 3.0
         * @playerversion   Flash 9
         * @playerversion   Lite 4
         */
        float MouseEvent::stageX()         ;

        /**
         * The vertical coordinate at which the event occurred in global Stage coordinates. 
         * This property is calculated when the localY property is set.
         * @langversion 3.0
         * @playerversion   Flash 9
         * @playerversion   Lite 4
         */
        float MouseEvent::stageY()         ;

        /**
         * If true, the relatedObject property is set to null for 
         * reasons related to security sandboxes.  If the nominal value of relatedObject is a reference to a
         * DisplayObject in another sandbox, relatedObject is set to
         * null unless there is permission in both directions across this sandbox boundary.  Permission is
         * established by calling Security.allowDomain() from a SWF file, or by providing
         * a policy file from the server of an image file, and setting the LoaderContext.checkPolicyFile
         * property when loading the image.
         * @langversion 3.0
         * @playerversion   Flash 10
         * @playerversion   Lite 4
         */
        bool MouseEvent::isRelatedObjectInaccessible()          ;
        void MouseEvent::isRelatedObjectInaccessible(bool value)       ;

        float MouseEvent::movementX()         ;
        void MouseEvent::movementX(float value)       ;

        float MouseEvent::movementY()         ;
        void MouseEvent::movementY(float value)       ;

        /**
         * Creates an Event object that contains information about mouse events.
         * Event objects are passed as parameters to event listeners.
         * @param   type    The type of the event. Possible values are: MouseEvent.CLICK,
         *   MouseEvent.DOUBLE_CLICK, MouseEvent.MOUSE_DOWN, 
         *   MouseEvent.MOUSE_MOVE, MouseEvent.MOUSE_OUT, 
         *   MouseEvent.MOUSE_OVER, MouseEvent.MOUSE_UP, 
         *   MouseEvent.MIDDLE_CLICK, MouseEvent.MIDDLE_MOUSE_DOWN, MouseEvent.MIDDLE_MOUSE_UP,
         *   MouseEvent.RIGHT_CLICK, MouseEvent.RIGHT_MOUSE_DOWN, MouseEvent.RIGHT_MOUSE_UP,
         *   MouseEvent.MOUSE_WHEEL, MouseEvent.ROLL_OUT, and MouseEvent.ROLL_OVER.
         * @param   bubbles Determines whether the Event object participates in the bubbling phase of the event flow.
         * @param   cancelable  Determines whether the Event object can be canceled.
         * @param   localX  The horizontal coordinate at which the event occurred relative to the containing sprite.
         * @param   localY  The vertical coordinate at which the event occurred relative to the containing sprite.
         * @param   relatedObject   The complementary InteractiveObject instance that is affected by the event. For example, when a mouseOut event occurs, relatedObject represents the display list object to which the pointing device now points.
         * @param   ctrlKey On Windows or Linux, indicates whether the Ctrl key is activated. On Mac, indicates whether either the Ctrl key or the Command key is activated.
         * @param   altKey  Indicates whether the Alt key is activated (Windows or Linux only).
         * @param   shiftKey    Indicates whether the Shift key is activated.
         * @param   buttonDown  Indicates whether the primary mouse button is pressed.
         * @param   delta   Indicates how many lines should be scrolled for each unit the user rotates the mouse wheel. A positive delta value indicates an upward scroll; a negative value indicates a downward scroll. Typical values are 1 to 3, but faster rotation may produce larger values. This parameter is used only for the MouseEvent.mouseWheel event.
         * @param   commandKey  (AIR only) Indicates whether the Command key is activated (Mac only). This parameter is used only for the MouseEvent.click, 
         *   MouseEvent.mouseDown, MouseEvent.mouseUp, MouseEvent.middleClick, MouseEvent.middleMouseDown, 
         *   MouseEvent.middleMouseUp, MouseEvent.rightClick, MouseEvent.rightMouseDown, MouseEvent.rightMouseUp, 
         *   and MouseEvent.doubleClick events. This parameter is for Adobe AIR only; do not set it for Flash Player content.
         * @param   controlKey  (AIR only) Indicates whether the Control or Ctrl key is activated. This parameter is used only for the MouseEvent.click, 
         *   MouseEvent.mouseDown, MouseEvent.mouseUp, MouseEvent.middleClick, MouseEvent.middleMouseDown, 
         *   MouseEvent.middleMouseUp, MouseEvent.rightClick, MouseEvent.rightMouseDown, MouseEvent.rightMouseUp, 
         *   and MouseEvent.doubleClick events. This parameter is for Adobe AIR only; do not set it for Flash Player content.
         * @param   clickCount  (AIR only) Indicates whether or not the mouse event is part of a multi-click sequence. This parameter will be zero for all mouse events other than 
         *   MouseEvent.mouseDown, MouseEvent.mouseUp, MouseEvent.middleMouseDown, MouseEvent.middleMouseUp, 
         *   MouseEvent.rightMouseDown and MouseEvent.rightMouseUp. Listening for single clicks, double clicks, or any multi-click sequence 
         *   is possible with the clickCount parameter. This parameter is for Adobe AIR only; do not set it for Flash Player content.
         * @langversion 3.0
         * @playerversion   AIR 1.0
         * @playerversion   Flash 9
         * @playerversion   Lite 4
         */
        MouseEvent::MouseEvent(std::string type, bool bubbles, bool cancelable, float localX, float localY, InteractiveObject* relatedObject, bool ctrlKey, bool altKey, bool shiftKey, bool buttonDown, int delta);

        /**
         * Creates a copy of the MouseEvent object and sets the value of each property to match that of the original.
         * @return  A new MouseEvent object with property values that match those of the original.
         * @langversion 3.0
         * @playerversion   Flash 9
         * @playerversion   Lite 4
         */
        flash::events::Event* MouseEvent::clone()                     ;

        /**
         * Returns a string that contains all the properties of the MouseEvent object. The string is in the following format:
         * [MouseEvent type=value bubbles=value cancelable=value ... delta=value]
         * @return  A string that contains all the properties of the MouseEvent object.
         * @langversion 3.0
         * @playerversion   Flash 9
         * @playerversion   Lite 4
         */
        std::string MouseEvent::toString()         ;

        /**
         * Instructs Flash Player or Adobe AIR to render after processing of this event completes, if the display list has been modified.
         * @langversion 3.0
         * @playerversion   Flash 9
         */
        void MouseEvent::updateAfterEvent()       ;
}
}

