#if !defined(FLEX11_6_FLASH_DISPLAY_SPRITE_AS)
#define FLEX11_6_FLASH_DISPLAY_SPRITE_AS
#if defined(__cplusplus)


#include "flex11.6.h"
namespace flash
{
    namespace display
    {
        class Graphics;
    }
}
namespace flash
{
    namespace geom
    {
        class Rectangle;
    }
}
namespace flash
{
    namespace display
    {
        class DisplayObject;
    }
}
#include "flash/display/DisplayObjectContainer.h"

namespace flash
{
    namespace media
    {
        class SoundTransform;
    }
}

/**
 * The Sprite class is a basic display list building block: a display list node that can display
 * graphics and can also contain children.
 *
 *   <p class="- topic/p ">A Sprite object is similar to a movie clip, but does not have a timeline. Sprite is an
 * appropriate base class for objects that do not require timelines. For example, Sprite would be a
 * logical base class for user interface (UI) components that typically do not use the timeline.</p><p class="- topic/p ">The Sprite class is new in ActionScript 3.0. It provides an alternative to the functionality of
 * the MovieClip class, which retains all the functionality of previous ActionScript releases to
 * provide backward compatibility.</p>
 *
 *   EXAMPLE:
 *
 *   The following example uses the SpriteExample class to draw an
 * orange square on the stage, and then dispatches events whenever the user clicks or drags the
 * square.  This task is accomplished by performing the following steps:
 * <ol class="- topic/ol "><li class="- topic/li ">Declare the <codeph class="+ topic/ph pr-d/codeph ">size</codeph> property (100 x 100 pixels) and the background color
 * (orange) for later use in drawing the square.</li><li class="- topic/li ">The constructor then creates a new <codeph class="+ topic/ph pr-d/codeph ">child</codeph> Sprite object and uses it to add
 * two event listeners and their associated methods: <codeph class="+ topic/ph pr-d/codeph ">mouseDownHandler()</codeph> and
 * <codeph class="+ topic/ph pr-d/codeph ">mouseUpHandler()</codeph>.</li><li class="- topic/li ">The <codeph class="+ topic/ph pr-d/codeph ">child</codeph> Sprite object  is then passed to the
 * <codeph class="+ topic/ph pr-d/codeph ">draw()</codeph> method, which draws the orange square.</li><li class="- topic/li ">The child is then placed on the display list by a call to the <codeph class="+ topic/ph pr-d/codeph ">addChild()</codeph>
 * method. </li><li class="- topic/li ">The event listeners work as follows:
 *
 *   <ul class="- topic/ul "><li class="- topic/li "><codeph class="+ topic/ph pr-d/codeph ">mouseDownHandler()</codeph>: when the user clicks the Sprite object,
 * this method adds a mouseMove event listener, the <codeph class="+ topic/ph pr-d/codeph ">mouseMoveHandler()</codeph> method,
 * which processes the mouse moves.  Then the <codeph class="+ topic/ph pr-d/codeph ">startDrag()</codeph> method is called, which
 * allows the Sprite object to be dragged.</li><li class="- topic/li "><codeph class="+ topic/ph pr-d/codeph ">mouseUpHandler()</codeph>: when the mouse button is released, the mouseMove event listener
 * is removed and the <codeph class="+ topic/ph pr-d/codeph ">stopDrag()</codeph> method is called, which freezes the orange square in
 * place.</li><li class="- topic/li "><codeph class="+ topic/ph pr-d/codeph ">mouseMoveHandler</codeph>: as long as the left mouse button is being held down, this
 * method instructs the player to continuously redraw the orange square.</li></ul></li></ol><p class="- topic/p "><b class="+ topic/ph hi-d/b ">Note: </b>Each of the event listener methods declares a local <codeph class="+ topic/ph pr-d/codeph ">sprite</codeph>
 * variable,  which is assigned the <codeph class="+ topic/ph pr-d/codeph ">target</codeph> property of the event.</p><codeblock xml:space="preserve" class="+ topic/pre pr-d/codeblock ">
 *
 *   package {
 * import flash.display.Sprite;
 * import flash.events.*;
 *
 *   public class SpriteExample extends Sprite {
 * private var size:uint    = 100;
 * private var bgColor:uint = 0xFFCC00;
 *
 *   public function SpriteExample() {
 * var child:Sprite = new Sprite();
 * child.addEventListener(MouseEvent.MOUSE_DOWN, mouseDownHandler);
 * child.addEventListener(MouseEvent.MOUSE_UP, mouseUpHandler);
 * draw(child);
 * addChild(child);
 * }
 *
 *   private function mouseDownHandler(event:MouseEvent):void {
 * trace("mouseDownHandler");
 * var sprite:Sprite = Sprite(event.target);
 * sprite.addEventListener(MouseEvent.MOUSE_MOVE, mouseMoveHandler);
 * sprite.startDrag();
 * }
 *
 *   private function mouseUpHandler(event:MouseEvent):void {
 * trace("mouseUpHandler");
 * var sprite:Sprite = Sprite(event.target);
 * sprite.removeEventListener(MouseEvent.MOUSE_MOVE, mouseMoveHandler);
 * sprite.stopDrag();
 * }
 *
 *   private function mouseMoveHandler(event:MouseEvent):void {
 * trace("mouseMoveHandler");
 * event.updateAfterEvent();
 * }
 *
 *   private function draw(sprite:Sprite):void {
 * sprite.graphics.beginFill(bgColor);
 * sprite.graphics.drawRect(0, 0, size, size);
 * sprite.graphics.endFill();
 * }
 * }
 * }
 * </codeblock>
 * @langversion 3.0
 * @playerversion   Flash 9
 * @playerversion   AIR 1.0
 * @playerversion   Lite 4
 */

using namespace flash::display;
using namespace flash::geom;
using namespace flash::media;

namespace flash
{
    namespace display
    {
        class Sprite : public flash::display::DisplayObjectContainer
        {
            /**
             * Specifies the Graphics object that belongs to this sprite where vector
             * drawing commands can occur.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   AIR 1.0
             * @playerversion   Lite 4
             */
        public:
            flash::display::Graphics *graphics();

            /**
             * Specifies the button mode of this sprite. If true, this
             * sprite behaves as a button, which means that it triggers the display
             * of the hand cursor when the pointer passes over the sprite and can
             * receive a click event if the enter or space keys are pressed
             * when the sprite has focus. You can suppress the display of the hand cursor
             * by setting the useHandCursor property to false,
             * in which case the pointer is displayed.
             *
             *   Although it is better to use the SimpleButton class to create buttons,
             * you can use the buttonMode property to give a sprite
             * some button-like functionality. To include a sprite in the tab order,
             * set the tabEnabled property (inherited from the
             * InteractiveObject class and false by default) to
             * true. Additionally, consider whether you want
             * the children of your sprite to be user input enabled. Most buttons
             * do not enable user input interactivity for their child objects because
             * it confuses the event flow. To disable user input interactivity for all child
             * objects, you must set the mouseChildren property (inherited
             * from the DisplayObjectContainer class) to false.If you use the buttonMode property with the MovieClip class (which is a
             * subclass of the Sprite class), your button might have some added
             * functionality. If you include frames labeled _up, _over, and _down,
             * Flash Player provides automatic state changes (functionality
             * similar to that provided in previous versions of ActionScript for movie
             * clips used as buttons). These automatic state changes are
             * not available for sprites, which have no timeline, and thus no frames
             * to label.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   AIR 1.0
             * @playerversion   Lite 4
             */
        public:
            bool      buttonMode();
        public:
            void         buttonMode(bool value);

            /**
             * Specifies the display object over which the sprite is being dragged, or on
             * which the sprite was dropped.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   AIR 1.0
             * @playerversion   Lite 4
             */
        public:
            flash::display::DisplayObject *dropTarget();

            /**
             * Designates another sprite to serve as the hit area for a sprite. If the hitArea
             * property does not exist or the value is null or undefined, the
             * sprite itself is used as the hit area. The value of the hitArea property can
             * be a reference to a Sprite object.
             *
             *   You can change the hitArea property at any time; the modified sprite immediately
             * uses the new hit area behavior. The sprite designated as the hit area does not need to be
             * visible; its graphical shape, although not visible, is still detected as the hit area.Note: You must set to false the mouseEnabled
             * property of the sprite designated as the hit area. Otherwise, your sprite button might
             * not work because the sprite designated as the hit area receives the user input events instead
             * of your sprite button.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   AIR 1.0
             * @playerversion   Lite 4
             */
        public:
            flash::display::Sprite *hitArea();
        public:
            void         hitArea(Sprite *value);

            /**
             * A Boolean value that indicates whether the pointing hand (hand cursor) appears when the pointer rolls
             * over a sprite in which the buttonMode property is set to true.
             * The default value of the useHandCursor property is true.
             * If useHandCursor is set to true, the pointing hand used for buttons
             * appears when the pointer rolls over a button sprite. If useHandCursor is
             * false, the arrow pointer is used instead.
             *
             *   You can change the useHandCursor property at any time; the modified sprite
             * immediately takes on the new cursor appearance. Note: In Flex or Flash Builder, if your sprite has child sprites, you might want to
             * set the mouseChildren property to false. For example, if you want a hand
             * cursor to appear over a Flex <mx:Label> control, set the useHandCursor and
             * buttonMode properties to true, and the mouseChildren property
             * to false.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   AIR 1.0
             */
        public:
            bool      useHandCursor();
        public:
            void         useHandCursor(bool value);

            /**
             * Controls sound within this sprite.
             *
             *   Note: This property does not affect HTML content in an HTMLControl object (in Adobe AIR).
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   AIR 1.0
             * @playerversion   Lite 4
             */
        public:
            flash::media::SoundTransform *soundTransform();
        public:
            void         soundTransform(SoundTransform *sndTransform);

            /**
             * Creates a new Sprite instance. After you create the Sprite instance, call the
             * DisplayObjectContainer.addChild() or DisplayObjectContainer.addChildAt()
             * method to add the Sprite to a parent DisplayObjectContainer.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   AIR 1.0
             * @playerversion   Lite 4
             */
        public:
            Sprite();

            /**
             * Lets the user drag the specified sprite. The sprite remains draggable until explicitly
             * stopped through a call to the Sprite.stopDrag() method, or until
             * another sprite is made draggable. Only one sprite is draggable at a time.
             * Three-dimensional display objects follow the pointer and
             * Sprite.startDrag() moves the object within
             * the three-dimensional plane defined by the display object. Or, if the display object is a two-dimensional object
             * and the child of a three-dimensional object, the two-dimensional object
             * moves within the three dimensional plane defined by the three-dimensional parent object.
             * @param   lockCenter  Specifies whether the draggable sprite is locked to the center of
             *   the pointer position (true), or locked to the point where the user first clicked the
             *   sprite (false).
             * @param   bounds  Value relative to the coordinates of the Sprite's parent that specify a constraint
             *   rectangle for the Sprite.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   AIR 1.0
             * @playerversion   Lite 4
             */
        public:
            void     startDrag(bool lockCenter=false, Rectangle *bounds=NULL);

            /**
             * Ends the startDrag() method. A sprite that was made draggable with the
             * startDrag() method remains draggable until a
             * stopDrag() method is added, or until another
             * sprite becomes draggable. Only one sprite is draggable at a time.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   AIR 1.0
             * @playerversion   Lite 4
             */
        public:
            void     stopDrag();

            /**
             * Lets the user drag the specified sprite on a touch-enabled device. The sprite remains draggable until explicitly
             * stopped through a call to the Sprite.stopTouchDrag() method, or until
             * another sprite is made draggable. Only one sprite is draggable at a time.
             * Three-dimensional display objects follow the pointer and
             * Sprite.startTouchDrag() moves the object within
             * the three-dimensional plane defined by the display object. Or, if the display object is a two-dimensional object
             * and the child of a three-dimensional object, the two-dimensional object
             * moves within the three dimensional plane defined by the three-dimensional parent object.
             * @param   touchPointID    An integer to assign to the touch point.
             * @param   lockCenter  Specifies whether the draggable sprite is locked to the center of
             *   the pointer position (true), or locked to the point where the user first clicked the
             *   sprite (false).
             * @param   bounds  Value relative to the coordinates of the Sprite's parent that specify a constraint
             *   rectangle for the Sprite.
             * @langversion 3.0
             * @playerversion   Flash 10.1
             * @playerversion   AIR 2
             * @playerversion   Lite 4
             */
        public:
            void     startTouchDrag(int touchPointID, bool lockCenter=false, Rectangle *bounds=NULL);

            /**
             * Ends the startTouchDrag() method, for use with touch-enabled devices. A sprite that was made draggable with the
             * startTouchDrag() method remains draggable until a
             * stopTouchDrag() method is added, or until another
             * sprite becomes draggable. Only one sprite is draggable at a time.
             * @param   touchPointID    The integer assigned to the touch point in the startTouchDrag method.
             * @langversion 3.0
             * @playerversion   Flash 10.1
             * @playerversion   AIR 2
             * @playerversion   Lite 4
             */
        public:
            void     stopTouchDrag(int touchPointID);
        };
    }
}

#endif // FLEX11_6_FLASH_DISPLAY_SPRITE_AS
#endif // __cplusplus

