

#include "Mouse.h"
#include "flash/ui/MouseCursorData.h"

    /**
     * The methods of the Mouse class are used to hide and show the mouse pointer,
     * or to set the pointer to a specific style.
     * The Mouse class is a top-level class whose properties and methods 
     * you can access without using a constructor. <ph outputclass="flashonly" class="- topic/ph ">The pointer is visible by default, 
     * but you can hide it and implement a custom pointer. </ph>
     * 
     *   EXAMPLE:
     * 
     *   The following example uses the MouseExample, SimpleButton,
     * ButtonDisplayState, and CustomCursor classes to place a simple button on the Stage. The button
     * has a custom pointer and the button changes when clicked.  This is accomplished with the following steps:
     * <ol class="- topic/ol "><li class="- topic/li ">Declare the following instance properties: <codeph class="+ topic/ph pr-d/codeph ">cursor</codeph> of type CustomCursor, <codeph class="+ topic/ph pr-d/codeph ">child</codeph> of type
     * CustomButton, and <codeph class="+ topic/ph pr-d/codeph ">gutter</codeph> of type uint. </li><li class="- topic/li ">Assign <codeph class="+ topic/ph pr-d/codeph ">child</codeph> to a new CustomButton instance, set its <i class="+ topic/ph hi-d/i ">x</i> and 
     * <i class="+ topic/ph hi-d/i ">y</i> coordinates to 10 pixels each, and then add the instance to the display list.
     * The CustomButton class overrides the <codeph class="+ topic/ph pr-d/codeph ">downState</codeph>, <codeph class="+ topic/ph pr-d/codeph ">upState</codeph>, 
     * <codeph class="+ topic/ph pr-d/codeph ">overState</codeph>, and <codeph class="+ topic/ph pr-d/codeph ">hitTestState</codeph> properties in SimpleButton.  Each of these 
     * properties instantiates a ButtonDisplayState object, which draws a different square, depending 
     * on the state of the <codeph class="+ topic/ph pr-d/codeph ">child</codeph> instance.</li><li class="- topic/li ">The <codeph class="+ topic/ph pr-d/codeph ">child</codeph> instance is then used to add a <codeph class="+ topic/ph pr-d/codeph ">MOUSE_OVER</codeph> event listener and
     * <codeph class="+ topic/ph pr-d/codeph ">mouseOverHandler()</codeph> listener method, along with a <codeph class="+ topic/ph pr-d/codeph ">MOUSE_OUT</codeph> event listener and associated
     * <codeph class="+ topic/ph pr-d/codeph ">mouseOutHandler()</codeph> method.</li><li class="- topic/li ">The event listeners work as follows:
     * <ul class="- topic/ul "><li class="- topic/li "><codeph class="+ topic/ph pr-d/codeph ">mouseOverHandler</codeph>: Hides the "normal" pointer and adds a <codeph class="+ topic/ph pr-d/codeph ">MOUSE_MOVE</codeph>
     * listener, which processes the mouse moves using <codeph class="+ topic/ph pr-d/codeph ">mouseMoveHandler()</codeph>, described
     * below.</li><li class="- topic/li "><codeph class="+ topic/ph pr-d/codeph ">mouseOutHandler</codeph>: When the mouse moves outside the custom button, the
     * "normal" pointer is shown, the <codeph class="+ topic/ph pr-d/codeph ">MOUSE_MOVE</codeph> event listener is removed, and the custom cursor's
     * visibility is set to <codeph class="+ topic/ph pr-d/codeph ">false</codeph>.</li><li class="- topic/li "><codeph class="+ topic/ph pr-d/codeph ">mouseMoveHandler</codeph>: Moves the custom cursor around wherever the pointer is 
     * moved and sets the custom cursor's visibility to <codeph class="+ topic/ph pr-d/codeph ">true</codeph>.</li></ul></li><li class="- topic/li ">Back in the <codeph class="+ topic/ph pr-d/codeph ">MouseExample</codeph> constructor, the cursor property is assigned to a new 
     * CustomCursor object and then added to the display list using <codeph class="+ topic/ph pr-d/codeph ">addChild()</codeph>.  
     * The CustomCursor class draws a small nearly black square in place of the "normal" pointer
     * whenever the mouse is over <codeph class="+ topic/ph pr-d/codeph ">child</codeph>.</li><li class="- topic/li ">A fourth event listener of type <codeph class="+ topic/ph pr-d/codeph ">MOUSE_LEAVE</codeph> is added, with the associated
     * <codeph class="+ topic/ph pr-d/codeph ">mouseLeaveHandler()</codeph> method.  In this method (called if the mouse leaves the Stage), 
     * <codeph class="+ topic/ph pr-d/codeph ">mouseOutHandler()</codeph> is passed a new <codeph class="+ topic/ph pr-d/codeph ">mouseMove</codeph> listener object, which essentially
     * removes the pointer so it is not left on the Stage.</li></ol><codeblock xml:space="preserve" class="+ topic/pre pr-d/codeblock ">
     * package {
     * import flash.display.Sprite;
     * import flash.display.DisplayObject;
     * import flash.ui.Mouse;
     * import flash.events.*;
     * 
     *   public class MouseExample extends Sprite {
     * private var cursor:CustomCursor;
     * private var child:CustomButton;
     * private var gutter:uint = 10;
     * 
     *   public function MouseExample() {
     * child = new CustomButton();
     * child.x = gutter;
     * child.y = gutter;
     * addChild(child);
     * 
     *   child.addEventListener(MouseEvent.MOUSE_OVER, mouseOverHandler);
     * child.addEventListener(MouseEvent.MOUSE_OUT, mouseOutHandler);
     * 
     *   cursor = new CustomCursor();
     * addChild(cursor);
     * 
     *   stage.addEventListener(Event.MOUSE_LEAVE, mouseLeaveHandler);
     * }
     * 
     *   private function mouseOverHandler(event:MouseEvent):void {
     * trace("mouseOverHandler");
     * Mouse.hide();
     * child.addEventListener(MouseEvent.MOUSE_MOVE, mouseMoveHandler);
     * }
     * 
     *   private function mouseOutHandler(event:MouseEvent):void {
     * trace("mouseOutHandler");
     * Mouse.show();
     * child.removeEventListener(MouseEvent.MOUSE_MOVE, mouseMoveHandler);
     * cursor.visible = false;
     * }
     * 
     *   private function mouseMoveHandler(event:MouseEvent):void {
     * trace("mouseMoveHandler");
     * cursor.x = event.localX;
     * cursor.y = event.localY;
     * event.updateAfterEvent();
     * cursor.visible = true;
     * }
     * 
     *   private function mouseLeaveHandler(event:Event):void {
     * trace("mouseLeaveHandler");
     * mouseOutHandler(new MouseEvent(MouseEvent.MOUSE_MOVE));
     * }
     * }
     * }
     * 
     *   import flash.display.Shape;
     * import flash.display.SimpleButton;
     * 
     *   class CustomButton extends SimpleButton {
     * var upColor:uint = 0xFFCC00;
     * var overColor:uint = 0xCCFF00;
     * var downColor:uint = 0x00CCFF;
     * var size:uint = 80;
     * 
     *   public function CustomButton() {
     * downState = new ButtonDisplayState(downColor, size+10);
     * overState = new ButtonDisplayState(overColor, size);
     * upState = new ButtonDisplayState(upColor, size);
     * hitTestState = new ButtonDisplayState(upColor, size);
     * }
     * }
     * 
     *   class ButtonDisplayState extends Shape {
     * var bgColor:uint;
     * var size:uint;
     * 
     *   public function ButtonDisplayState(bgColor:uint, size:uint) {
     * this.bgColor = bgColor;
     * this.size = size;
     * draw();
     * }
     * 
     *   private function draw():void {
     * graphics.clear();
     * graphics.beginFill(bgColor);
     * graphics.drawRect(0, 0, size, size);
     * graphics.endFill();
     * }
     * }
     * 
     *   class CustomCursor extends Shape {
     * var bgColor:uint = 0x333333;
     * var size:uint = 10;
     * 
     *   public function CustomCursor() {
     * visible = false;
     * draw();
     * }
     * 
     *   private function draw():void {
     * graphics.clear();
     * graphics.beginFill(bgColor);
     * graphics.drawRect(0, 0, size, size);
     * graphics.endFill();
     * }
     * }
     * </codeblock>
     * @langversion 3.0
     * @playerversion   Flash 9
     */

using namespace flash::ui;

namespace flash {
namespace ui {


        /**
         * Indicates whether the computer or device displays a persistent cursor.
         * 
         *   The supportsCursor property is true on most desktop computers
         * and false on most mobile devices.Note: Mouse events can be dispatched whether or not this property is true.
         * However, mouse events may behave differently depending on the physical characteristics of the pointing device.
         * @langversion 3.0
         * @playerversion   Flash 10.1
         * @playerversion   AIR 2
         */
        bool Mouse::supportsCursor()          ;

        /**
         * Sets or returns the type of cursor, or, for a native cursor, the cursor name.
         * 
         *   The default value is flash.ui.MouseCursor.AUTO.To set values for this property, use the following string values:String valueDescriptionflash.ui.MouseCursor.AUTOMouse cursor will change automatically based on the object under the mouse.flash.ui.MouseCursor.ARROWMouse cursor will be an arrow.flash.ui.MouseCursor.BUTTONMouse cursor will be a button clicking hand.flash.ui.MouseCursor.HANDMouse cursor will be a dragging hand.flash.ui.MouseCursor.IBEAMMouse cursor will be an I-beam.Note: For Flash Player 10.2 or AIR 2.6 and later versions, this property sets or gets the cursor name
         * when you are using a native cursor. A native cursor name defined using Mouse.registerCursor() overwrites currently
         * predefined cursor types (such as flash.ui.MouseCursor.IBEAM).
         * @langversion 3.0
         * @playerversion   Flash 10
         * @playerversion   AIR 1.5
         * @throws  ArgumentError If set to any value which is not a member of flash.ui.MouseCursor, or is not a string specified using
         *   the Mouse.registerCursor() method.
         */
        std::string Mouse::cursor()         ;
        void Mouse::cursor(std::string value)       ;

        /**
         * Indicates whether the current configuration supports native cursors.
         * @langversion 3.0
         * @playerversion   Flash 10.2
         * @playerversion   AIR 2.6
         */
        bool Mouse::supportsNativeCursor()          ;

        /**
         * Hides the pointer. The pointer is visible by default.
         * 
         *   Note: You need to call Mouse.hide() only once, regardless of
         * the number of previous calls to Mouse.show().
         * @langversion 3.0
         * @playerversion   Flash 9
         */
        void Mouse::hide()       ;

        Mouse::Mouse();

        /**
         * Displays the pointer. The pointer is visible by default.
         * 
         *   Note: You need to call Mouse.show() only once, regardless of
         * the number of previous calls to Mouse.hide().
         * @langversion 3.0
         * @playerversion   Flash 9
         */
        void Mouse::show()       ;

        /**
         * Registers a native cursor under the given name, with the given data.
         * @param   name    The name to use as a reference to the native cursor instance.
         * @param   cursor  The properties for the native cursor, such as icon bitmap, specified as a MouseCursorData instance.
         * @langversion 3.0
         * @playerversion   Flash 10.2
         * @playerversion   AIR 2.6
         */
        void Mouse::registerCursor(std::string name, MouseCursorData* cursor)       ;

        /**
         * Unregisters the native cursor with the given name.
         * @param   name    The name referring to the native cursor instance.
         * @langversion 3.0
         * @playerversion   Flash 10.2
         * @playerversion   AIR 2.6
         */
        void Mouse::unregisterCursor(std::string name)       ;
}
}

