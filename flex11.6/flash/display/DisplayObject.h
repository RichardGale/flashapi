#if !defined(FLEX11_6_FLASH_DISPLAY_DISPLAYOBJECT_AS)
#define FLEX11_6_FLASH_DISPLAY_DISPLAYOBJECT_AS
#if defined(__cplusplus)


#include "flex11.6.h"
#include "flash/events/EventDispatcher.h"
#include "flash/display/IBitmapDrawable.h"

namespace flash
{
    namespace display
    {
        class Stage;
    }
}
namespace flash
{
    namespace display
    {
        class DisplayObjectContainer;
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
    namespace geom
    {
        class Transform;
    }
}
namespace flash
{
    namespace geom
    {
        class Point;
    }
}
namespace flash
{
    namespace display
    {
        class LoaderInfo;
    }
}
namespace flash
{
    namespace accessibility
    {
        class AccessibilityProperties;
    }
}
namespace flash
{
    namespace geom
    {
        class Vector3D;
    }
}
namespace flash
{
    namespace display
    {
        class Shader;
    }
}

/**
 * [broadcast event] Dispatched when the display list is about to be updated and rendered.
 * @eventType   flash.events.Event.RENDER
 */
//[Event(name="render",type="flash.events.Event")]

/**
 * Dispatched when a display object is about to be removed from the display list,
 * either directly or through the removal of a sub tree in which the display object is contained.
 * @eventType   flash.events.Event.REMOVED_FROM_STAGE
 */
//[Event(name="removedFromStage",type="flash.events.Event")]

/**
 * Dispatched when a display object is about to be removed from the display list.
 * @eventType   flash.events.Event.REMOVED
 */
//[Event(name="removed",type="flash.events.Event")]

/**
 * [broadcast event] Dispatched when the playhead is exiting the current frame.
 * @eventType   flash.events.Event.EXIT_FRAME
 */
//[Event(name="exitFrame",type="flash.events.Event")]

/**
 * [broadcast event] Dispatched after the constructors of frame display objects have run but before frame scripts have run.
 * @eventType   flash.events.Event.FRAME_CONSTRUCTED
 */
//[Event(name="frameConstructed",type="flash.events.Event")]

/**
 * [broadcast event] Dispatched when the playhead is entering a new
 * frame.
 * @eventType   flash.events.Event.ENTER_FRAME
 */
//[Event(name="enterFrame",type="flash.events.Event")]

/**
 * Dispatched when a display object is added to the on stage display list,
 * either directly or through the addition of a sub tree in which the display object is contained.
 * @eventType   flash.events.Event.ADDED_TO_STAGE
 */
//[Event(name="addedToStage",type="flash.events.Event")]

/**
 * Dispatched when a display object is added to the display list.
 * @eventType   flash.events.Event.ADDED
 */
//[Event(name="added",type="flash.events.Event")]

using namespace flash::accessibility;
using namespace flash::display;
using namespace flash::events;
using namespace flash::geom;

namespace flash
{
    namespace display
    {
        /**
         * The DisplayObject class is the base class for all objects that can be placed on
         * the display list. The display list manages all objects displayed in the Flash runtimes.
         * Use the DisplayObjectContainer class to arrange the display objects in the display list.
         * DisplayObjectContainer objects can have child display objects, while other display objects, such as
         * Shape and TextField objects, are "leaf" nodes that have only parents and siblings, no children.
         *
         *   <p class="- topic/p ">The DisplayObject class supports basic functionality like the <i class="+ topic/ph hi-d/i ">x</i> and <i class="+ topic/ph hi-d/i ">y</i> position of
         * an object, as well as more advanced properties of the object such as its transformation matrix.
         * </p><p class="- topic/p ">DisplayObject is an abstract base class; therefore, you cannot call DisplayObject directly. Invoking
         * <codeph class="+ topic/ph pr-d/codeph ">new DisplayObject()</codeph> throws an <codeph class="+ topic/ph pr-d/codeph ">ArgumentError</codeph> exception. </p><p class="- topic/p ">All display objects inherit from the DisplayObject class.</p><p class="- topic/p ">The DisplayObject class itself does not include any APIs for rendering content onscreen.
         * For that reason, if you want create a custom subclass of the DisplayObject class, you will want
         * to extend one of its subclasses that do have APIs for rendering content onscreen,
         * such as the Shape, Sprite, Bitmap, SimpleButton, TextField, or MovieClip class.</p><p class="- topic/p ">The DisplayObject class contains several broadcast events. Normally, the target
         * of any particular event is a specific DisplayObject instance. For example,
         * the target of an <codeph class="+ topic/ph pr-d/codeph ">added</codeph> event is the specific DisplayObject instance
         * that was added to the display list. Having a single target restricts the placement of
         * event listeners to that target and in some cases the target's ancestors on the display list.
         * With broadcast events, however, the target is not a specific DisplayObject instance,
         * but rather all DisplayObject instances, including those that are not on the display list.
         * This means that you can add a listener to any DisplayObject instance to listen for broadcast events.
         * In addition to the broadcast events listed in the DisplayObject class's Events table,
         * the DisplayObject class also inherits two broadcast events from the EventDispatcher
         * class: <codeph class="+ topic/ph pr-d/codeph ">activate</codeph> and <codeph class="+ topic/ph pr-d/codeph ">deactivate</codeph>.</p><p class="- topic/p ">Some properties previously used in the ActionScript 1.0 and 2.0 MovieClip, TextField, and Button
         * classes (such as <codeph class="+ topic/ph pr-d/codeph ">_alpha</codeph>, <codeph class="+ topic/ph pr-d/codeph ">_height</codeph>, <codeph class="+ topic/ph pr-d/codeph ">_name</codeph>, <codeph class="+ topic/ph pr-d/codeph ">_width</codeph>,
         * <codeph class="+ topic/ph pr-d/codeph ">_x</codeph>, <codeph class="+ topic/ph pr-d/codeph ">_y</codeph>, and others) have equivalents in the ActionScript 3.0
         * DisplayObject class that are renamed so that they no longer begin with the underscore (_) character.</p><p class="- topic/p ">For more information, see the "Display Programming" chapter of the <i class="+ topic/ph hi-d/i ">ActionScript 3.0 Developer's Guide</i>.</p>
         *
         *   EXAMPLE:
         *
         *   The following example uses the <codeph class="+ topic/ph pr-d/codeph ">DisplayObjectExample</codeph> class to
         * draw an orange square in the corner of the Stage and then respond to events by displaying text
         * information for each event.  This task is accomplished by performing the following steps:
         * <ol class="- topic/ol "><li class="- topic/li ">Class properties are declared for the color and size of the square.</li><li class="- topic/li ">The constructor calls the <codeph class="+ topic/ph pr-d/codeph ">draw()</codeph> method, which draws an orange square on
         * the Stage at the default coordinates of <i class="+ topic/ph hi-d/i ">x = 0, y = 0</i>.</li><li class="- topic/li ">The following event listener methods are attached to the square:
         * <ul class="- topic/ul "><li class="- topic/li "><codeph class="+ topic/ph pr-d/codeph ">addedHandler()</codeph> listens for <codeph class="+ topic/ph pr-d/codeph ">added</codeph> events, dispatched when the
         * square is added to the display list.</li><li class="- topic/li "><codeph class="+ topic/ph pr-d/codeph ">enterFrameHandler()</codeph> listens for <codeph class="+ topic/ph pr-d/codeph ">enterFrame</codeph> events, which have no
         * real meaning in this example.</li><li class="- topic/li "><codeph class="+ topic/ph pr-d/codeph ">removedHandler()</codeph> listens for <codeph class="+ topic/ph pr-d/codeph ">removed</codeph> events, dispatched when
         * the square is removed from the display list, which happens when the square is clicked.</li><li class="- topic/li "><codeph class="+ topic/ph pr-d/codeph ">clickHandler()</codeph> listens for <codeph class="+ topic/ph pr-d/codeph ">click</codeph> events, dispatched when the
         * orange square is clicked.</li><li class="- topic/li "><codeph class="+ topic/ph pr-d/codeph ">renderHandler()</codeph> listens for <codeph class="+ topic/ph pr-d/codeph ">render</codeph> events after the display
         * list is updated.</li></ul></li></ol><codeblock xml:space="preserve" class="+ topic/pre pr-d/codeblock ">
         *
         *   package {
         * import flash.display.Sprite;
         *
         *   public class DisplayObjectExample extends Sprite {
         * public function DisplayObjectExample() {
         * var child:CustomDisplayObject = new CustomDisplayObject();
         * addChild(child);
         * }
         * }
         * }
         *
         *   import flash.display.DisplayObject;
         * import flash.display.Sprite;
         * import flash.display.Stage;
         * import flash.display.StageAlign;
         * import flash.display.StageScaleMode;
         * import flash.events.*;
         *
         *   class CustomDisplayObject extends Sprite {
         * private var bgColor:uint = 0xFFCC00;
         * private var size:uint    = 80;
         *
         *   public function CustomDisplayObject() {
         * draw();
         * addEventListener(Event.ADDED, addedHandler);
         * addEventListener(Event.ENTER_FRAME, enterFrameHandler);
         * addEventListener(Event.REMOVED, removedHandler);
         * addEventListener(MouseEvent.CLICK, clickHandler);
         * addEventListener(Event.RENDER, renderHandler);
         * }
         *
         *   private function draw():void {
         * graphics.beginFill(bgColor);
         * graphics.drawRect(0, 0, size, size);
         * graphics.endFill();
         * }
         *
         *   private function clickHandler(event:MouseEvent):void {
         * trace("clickHandler: " + event);
         * parent.removeChild(this);
         * }
         *
         *   private function addedHandler(event:Event):void {
         * trace("addedHandler: " + event);
         * stage.scaleMode = StageScaleMode.NO_SCALE;
         * stage.align = StageAlign.TOP_LEFT;
         * stage.addEventListener("resize", resizeHandler);
         * }
         *
         *   private function enterFrameHandler(event:Event):void {
         * trace("enterFrameHandler: " + event);
         * removeEventListener("enterFrame", enterFrameHandler);
         * }
         *
         *   private function removedHandler(event:Event):void {
         * trace("removedHandler: " + event);
         * stage.removeEventListener("resize", resizeHandler);
         * }
         *
         *   private function renderHandler(event:Event):void {
         * trace("renderHandler: " + event);
         * }
         *
         *   private function resizeHandler(event:Event):void {
         * trace("resizeHandler: " + event);
         * }
         * }
         * </codeblock>
         * @langversion 3.0
         * @playerversion   Flash 9
         * @playerversion   Lite 4
         */
        class DisplayObject : public flash::events::EventDispatcher, public flash::display::IBitmapDrawable
        {
            /**
             * For a display object in a loaded SWF file, the root property is the
             * top-most display object in the portion of the display list's tree structure represented by that SWF file.
             * For a Bitmap object representing a loaded image file, the root property is the Bitmap object
             * itself. For the instance of the main class of the first SWF file loaded, the root property is the
             * display object itself. The root property of the Stage object is the Stage object itself. The root
             * property is set to null for any display object that has not been added to the display list, unless
             * it has been added to a display object container that is off the display list but that is a child of the
             * top-most display object in a loaded SWF file.
             *
             *   For example, if you create a new Sprite object by calling the Sprite() constructor method,
             * its root property is null until you add it to the display list (or to a display
             * object container that is off the display list but that is a child of the top-most display object in a SWF file).For a loaded SWF file, even though the Loader object used to load the file may not be on the display list,
             * the top-most display object in the SWF file has its root property set to itself.  The Loader object
             * does not have its root property set until it is added as a child of a display object for which the
             * root property is set.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            flash::display::DisplayObject *root();

            /**
             * The Stage of the display object. A Flash runtime application has only one Stage object.
             * For example, you can create and load multiple display objects into the display list, and the
             * stage property of each display object refers to the same Stage object (even if the
             * display object belongs to a loaded SWF file).
             *
             *   If a display object is not added to the display list, its stage property is set to
             * null.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            flash::display::Stage *stage();

            /**
             * Indicates the instance name of the DisplayObject. The object can be identified in
             * the child list of its parent display object container by calling the
             * getChildByName() method of the display object container.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             * @throws  IllegalOperationError If you are attempting to set this property on an object that was
             *   placed on the timeline in the Flash authoring tool.
             */
        public:
            std::string       name();
        public:
            void         name(std::string value);

            /**
             * Indicates the DisplayObjectContainer object that contains this display object. Use the parent
             * property to specify a relative path to display objects that are above the
             * current display object in the display list hierarchy.
             *
             *   You can use parent to move up multiple levels in the display list as in the following:
             * <codeblock>
             *
             *   this.parent.parent.alpha = 20;
             *
             *   </codeblock>
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             * @throws  SecurityError The parent display object belongs to a security sandbox
             *   to which you do not have access. You can avoid this situation by having
             *   the parent movie call the Security.allowDomain() method.
             */
        public:
            flash::display::DisplayObjectContainer *parent();

            /**
             * The calling display object is masked by the specified mask object.
             * To ensure that masking works when the Stage is scaled, the mask display object
             * must be in an active part of the display list. The mask object itself is not drawn.
             * Set mask to null to remove the mask.
             *
             *   To be able to scale a mask object, it must be on the display list. To be able to drag a mask Sprite object
             * (by calling its startDrag() method), it must be on the display list. To call the
             * startDrag() method for a mask sprite based on a mouseDown event
             * being dispatched by the sprite, set the sprite's buttonMode property to true.When display objects are cached by setting the cacheAsBitmap property to
             * true an the cacheAsBitmapMatrix property to a Matrix object,
             * both the mask and the display object being masked must be part of the same cached
             * bitmap. Thus, if the display object is cached, then the mask must be a child of the display object.
             * If an ancestor of the display object on the display list is cached, then the mask must be a child of
             * that ancestor or one of its descendents. If more than one ancestor of the masked object is cached,
             * then the mask must be a descendent of the cached container closest to the masked object in the display list.Note: A single mask object cannot be used to mask more than one calling display object.
             * When the mask is assigned to a second display object, it is removed as the mask of the first
             * object, and that object's mask property becomes null.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            flash::display::DisplayObject *mask();
        public:
            void         mask(DisplayObject *value);

            /**
             * Whether or not the display object is visible. Display objects that are not visible
             * are disabled. For example, if visible=false for an InteractiveObject instance,
             * it cannot be clicked.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            bool      visible();
        public:
            void         visible(bool value);

            /**
             * Indicates the x coordinate of the DisplayObject instance relative to the local coordinates of
             * the parent DisplayObjectContainer. If the object is inside a DisplayObjectContainer that has
             * transformations, it is in the local coordinate system of the enclosing DisplayObjectContainer.
             * Thus, for a DisplayObjectContainer rotated 90   counterclockwise, the DisplayObjectContainer's
             * children inherit a coordinate system that is rotated 90   counterclockwise.
             * The object's coordinates refer to the registration point position.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            float       x();
        public:
            void         x(float value);

            /**
             * Indicates the y coordinate of the DisplayObject instance relative to the local coordinates of
             * the parent DisplayObjectContainer. If the object is inside a DisplayObjectContainer that has
             * transformations, it is in the local coordinate system of the enclosing DisplayObjectContainer.
             * Thus, for a DisplayObjectContainer rotated 90   counterclockwise, the DisplayObjectContainer's
             * children inherit a coordinate system that is rotated 90   counterclockwise.
             * The object's coordinates refer to the registration point position.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            float       y();
        public:
            void         y(float value);

            /**
             * Indicates the z coordinate position along the z-axis of the DisplayObject
             * instance relative to the 3D parent container. The z property is used for
             * 3D coordinates, not screen or pixel coordinates.
             * When you set a z property for a display object to something other than the default
             * value of 0, a corresponding Matrix3D object is automatically created. for adjusting a
             * display object's position and orientation
             * in three dimensions. When working with the z-axis,
             * the existing behavior of x and y properties changes from screen or pixel coordinates to
             * positions relative to the 3D parent container.For example, a child of the _root  at position x = 100, y = 100, z = 200
             * is not drawn at pixel location (100,100). The child is drawn wherever the 3D projection
             * calculation puts it. The calculation is: (x~~cameraFocalLength/cameraRelativeZPosition, y~~cameraFocalLength/cameraRelativeZPosition)
             * @langversion 3.0
             * @playerversion   Flash 10
             * @playerversion   AIR 1.5
             */
        public:
            float       z();
        public:
            void         z(float value);

            /**
             * Indicates the horizontal scale (percentage) of the object as applied from the registration point. The default
             * registration point is (0,0). 1.0 equals 100% scale.
             *
             *   Scaling the local coordinate system changes the x and y property values, which are defined in
             * whole pixels.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            float       scaleX();
        public:
            void         scaleX(float value);

            /**
             * Indicates the vertical scale (percentage) of an object as applied from the registration point of the object. The
             * default registration point is (0,0). 1.0 is 100% scale.
             *
             *   Scaling the local coordinate system changes the x and y property values, which are defined in
             * whole pixels.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            float       scaleY();
        public:
            void         scaleY(float value);

            /**
             * Indicates the depth scale (percentage) of an object as applied from the registration point of the object. The
             * default registration point is (0,0). 1.0 is 100% scale.
             *
             *   Scaling the local coordinate system changes the x, y and z property values, which are defined in
             * whole pixels.
             * @langversion 3.0
             * @playerversion   Flash 10
             * @playerversion   AIR 1.5
             */
        public:
            float       scaleZ();
        public:
            void         scaleZ(float value);

            /**
             * Indicates the x coordinate of the mouse or user input device position, in pixels.
             *
             *   Note: For a DisplayObject that has been rotated, the returned x coordinate will reflect the
             * non-rotated object.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            float       mouseX();

            /**
             * Indicates the y coordinate of the mouse or user input device position, in pixels.
             *
             *   Note: For a DisplayObject that has been rotated, the returned y coordinate will reflect the
             * non-rotated object.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            float       mouseY();

            /**
             * Indicates the rotation of the DisplayObject instance, in degrees, from its original orientation. Values from 0 to 180 represent
             * clockwise rotation; values from 0 to -180 represent counterclockwise rotation. Values outside this range are added to or
             * subtracted from 360 to obtain a value within the range. For example, the statement my_video.rotation = 450 is the
             * same as  my_video.rotation = 90.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            float       rotation();
        public:
            void         rotation(float value);

            /**
             * Indicates the x-axis rotation of the DisplayObject instance, in degrees, from its original orientation relative to the 3D parent container. Values from 0 to 180 represent
             * clockwise rotation; values from 0 to -180 represent counterclockwise rotation. Values outside this range are added to or
             * subtracted from 360 to obtain a value within the range.
             * @langversion 3.0
             * @playerversion   Flash 10
             * @playerversion   AIR 1.5
             * @playerversion   Lite 4
             */
        public:
            float       rotationX();
        public:
            void         rotationX(float value);

            /**
             * Indicates the y-axis rotation of the DisplayObject instance, in degrees, from its original orientation relative to the 3D parent container. Values from 0 to 180 represent
             * clockwise rotation; values from 0 to -180 represent counterclockwise rotation. Values outside this range are added to or
             * subtracted from 360 to obtain a value within the range.
             * @langversion 3.0
             * @playerversion   Flash 10
             * @playerversion   AIR 1.5
             * @playerversion   Lite 4
             */
        public:
            float       rotationY();
        public:
            void         rotationY(float value);

            /**
             * Indicates the z-axis rotation of the DisplayObject instance, in degrees, from its original orientation relative to the 3D parent container. Values from 0 to 180 represent
             * clockwise rotation; values from 0 to -180 represent counterclockwise rotation. Values outside this range are added to or
             * subtracted from 360 to obtain a value within the range.
             * @langversion 3.0
             * @playerversion   Flash 10
             * @playerversion   AIR 1.5
             * @playerversion   Lite 4
             */
        public:
            float       rotationZ();
        public:
            void         rotationZ(float value);

            /**
             * Indicates the alpha transparency value of the object specified.
             * Valid values are 0 (fully transparent) to 1 (fully opaque).
             * The default value is 1. Display objects with alpha
             * set to 0 are active, even though they are invisible.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            float       alpha();
        public:
            void         alpha(float value);

            /**
             * Indicates the width of the display object, in pixels. The width is calculated based on the bounds of the content of the display object.
             * When you set the width property, the scaleX property is adjusted accordingly, as shown in the
             * following code:
             *
             *   <codeblock>
             *
             *   var rect:Shape = new Shape();
             * rect.graphics.beginFill(0xFF0000);
             * rect.graphics.drawRect(0, 0, 100, 100);
             * trace(rect.scaleX) // 1;
             * rect.width = 200;
             * trace(rect.scaleX) // 2;
             * </codeblock>
             * Except for TextField and Video objects, a display object with no content (such as an empty sprite) has a width
             * of 0, even if you try to set width to a different value.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            float       width();
        public:
            void         width(float value);

            /**
             * Indicates the height of the display object, in pixels. The height is calculated based on the bounds of the content of the display object.
             * When you set the height property, the scaleY property is adjusted accordingly, as shown in the
             * following code:
             *
             *   <codeblock>
             *
             *   var rect:Shape = new Shape();
             * rect.graphics.beginFill(0xFF0000);
             * rect.graphics.drawRect(0, 0, 100, 100);
             * trace(rect.scaleY) // 1;
             * rect.height = 200;
             * trace(rect.scaleY) // 2;
             * </codeblock>
             * Except for TextField and Video objects, a display object with no content (such as an empty sprite) has a height
             * of 0, even if you try to set height to a different value.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            float       height();
        public:
            void         height(float value);

            /**
             * If set to true, Flash runtimes cache an internal bitmap representation of the
             * display object. This caching can increase performance for display objects that contain complex
             * vector content.
             *
             *   All vector data for a display object that has a cached bitmap is drawn to the bitmap
             * instead of the main display. If cacheAsBitmapMatrix is null or unsupported,
             * the bitmap is then copied to the main display as unstretched, unrotated pixels snapped to
             * the nearest pixel boundaries. Pixels are mapped 1 to 1 with
             * the parent object. If the bounds of the bitmap change, the bitmap is recreated instead
             * of being stretched.If cacheAsBitmapMatrix is non-null and supported, the object is drawn to the off-screen bitmap
             * using that matrix and the stretched and/or rotated results of that rendering are used
             * to draw the object to the main display.No internal bitmap is created unless the cacheAsBitmap property is set to
             * true.After you set the cacheAsBitmap property to true,
             * the rendering does not change, however the display object performs pixel snapping
             * automatically. The animation speed can be significantly faster depending
             * on the complexity of the vector content.
             * The cacheAsBitmap property is automatically set to true
             * whenever you apply a filter to a display object (when its filter array is not empty),
             * and if a display object has a filter applied to it, cacheAsBitmap is reported as
             * true for that display object, even if you set the property to false.
             * If you clear all filters for a display object, the cacheAsBitmap setting changes to
             * what it was last set to.A display object does not use a bitmap even if the cacheAsBitmap
             * property is set to true and instead renders from vector data in the following cases:The bitmap is too large.
             * In  AIR 1.5 and Flash Player 10, the maximum size for a bitmap image is 8,191 pixels in width or height,
             * and the total number of pixels cannot exceed 16,777,215 pixels. (So, if a bitmap image is 8,191 pixels
             * wide, it can only be 2,048 pixels high.) In Flash Player 9 and earlier, the limitation is
             * is 2880 pixels in height and 2,880 pixels in width.The bitmap fails to allocate (out of memory error). The cacheAsBitmap property is best used with movie clips that have
             * mostly static content and that do not scale and rotate frequently. With such movie
             * clips, cacheAsBitmap can lead to performance increases when the
             * movie clip is translated (when its x and y position is changed).
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            bool      cacheAsBitmap();
        public:
            void         cacheAsBitmap(bool value);

            /**
             * Specifies whether the display object is opaque with a certain background color.
             * A transparent bitmap contains alpha
             * channel data and is drawn transparently. An opaque bitmap has no alpha channel (and renders faster
             * than a transparent bitmap). If the bitmap is opaque, you specify its own background color to use.
             *
             *   If set to a number value, the surface is opaque (not transparent) with the RGB background
             * color that the number specifies. If set to null (the default value), the display
             * object has a transparent background.The opaqueBackground property is intended mainly for use with the
             * cacheAsBitmap property, for rendering optimization. For display objects in which the
             * cacheAsBitmap property is set to true, setting opaqueBackground can
             * improve rendering performance.The opaque background region is not matched when calling the hitTestPoint()
             * method with the shapeFlag parameter set to true.The opaque background region does not respond to mouse events.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            Object       *opaqueBackground();
        public:
            void         opaqueBackground(Object *value);

            /**
             * The scroll rectangle bounds of the display object. The display object is cropped to the size
             * defined by the rectangle, and it scrolls within the rectangle when you change the
             * x and y properties of the scrollRect object.
             *
             *   The properties of the scrollRect Rectangle object use the display object's coordinate space
             * and are scaled just like the overall display object. The corner bounds of the cropped window on the scrolling
             * display object are the origin of the display object (0,0) and the point defined by the
             * width and height of the rectangle. They are not centered around the origin, but
             * use the origin to define the upper-left corner of the area. A scrolled display object always
             * scrolls in whole pixel increments. You can scroll an object left and right by setting the x property of the
             * scrollRect Rectangle object. You can scroll an object up and down by setting
             * the y property of the scrollRect Rectangle object. If the display object
             * is rotated 90   and you scroll it left and right, the display object actually scrolls up and down.
             * @langversion 3.0
             * @playerversion   Flash 9
             */
        public:
            flash::geom::Rectangle *scrollRect();
        public:
            void         scrollRect(Rectangle *value);

            /**
             * An indexed array that contains each filter object currently associated with the display object.
             * The flash.filters package contains several classes that define specific filters you can
             * use.
             *
             *   Filters can be applied in Flash Professional at design time, or at run time by using
             * ActionScript code. To apply a filter by using ActionScript, you must make a temporary copy of the
             * entire filters array, modify the temporary array, then assign the value
             * of the temporary array back to the filters array. You cannot directly
             * add a new filter object to the filters array.To add a filter by using ActionScript, perform the following steps (assume that the
             * target display object is named myDisplayObject):Create a new filter object by using the constructor method of your chosen filter
             * class.Assign the value of the myDisplayObject.filters array to a temporary array, such
             * as one named myFilters.Add the new filter object to the myFilters temporary array.Assign the value of the temporary array to the myDisplayObject.filters array.If the filters array is undefined, you do not need to use a temporary array.
             * Instead, you can directly assign an array literal that contains one or more filter objects that
             * you create. The first example in the Examples section adds a drop shadow filter by using
             * code that handles both defined and undefined filters arrays.To modify an existing filter object,
             * you must use the technique of modifying a copy of the filters array:Assign the value of the filters array to a temporary array, such as one
             * named myFilters.Modify the property by using the temporary array, myFilters. For example,
             * to set the quality property of the first filter in the array, you could use the
             * following code: myFilters[0].quality = 1;Assign the value of the temporary array to the filters array.At load time, if a display object has an associated filter, it is marked to cache itself as a
             * transparent bitmap. From this point forward, as long as the display object has a valid filter list,
             * the player caches the display object as a bitmap. This source bitmap is used as a source
             * image for the filter effects. Each display object usually has two bitmaps: one with the
             * original unfiltered source display object and another for the final image after filtering.
             * The final image is used when rendering. As long as the display object does not
             * change, the final image does not need updating.The flash.filters package includes classes for filters. For example, to create a DropShadow
             * filter, you would write:
             * <codeblock>
             *
             *   import flash.filters.DropShadowFilter
             * var myFilter:DropShadowFilter = new DropShadowFilter (distance, angle, color, alpha, blurX, blurY, quality, inner, knockout)
             *
             *   </codeblock>
             * You can use the is operator to determine the type of filter assigned to
             * each index position in the filter array. For example, the following code shows
             * how to determine the position of the first filter in the filters array that
             * is a DropShadowFilter:
             *
             *   <codeblock>
             *
             *   import flash.text.TextField;
             * import flash.filters.~~;
             * var tf:TextField = new TextField();
             * var filter1:DropShadowFilter = new DropShadowFilter();
             * var filter2:GradientGlowFilter = new GradientGlowFilter();
             * tf.filters = [filter1, filter2];
             *
             *   tf.text = "DropShadow index: " + filterPosition(tf, DropShadowFilter).toString(); // 0
             * addChild(tf)
             *
             *   function filterPosition(displayObject:DisplayObject, filterClass:Class):int {
             * for (var i:uint = 0; i < displayObject.filters.length; i++) {
             * if (displayObject.filters[i] is filterClass) {
             * return i;
             * }
             * }
             * return -1;
             * }
             *
             *   </codeblock>
             * Note: Since you cannot directly add a new filter object to the
             * DisplayObject.filters array, the following code has no
             * effect on the target display object, named myDisplayObject:
             * <codeblock>
             *
             *   myDisplayObject.filters.push(myDropShadow);
             *
             *   </codeblock>
             * @langversion 3.0
             * @playerversion   Flash 9
             * @throws  ArgumentError When filters includes a ShaderFilter and the shader
             *   output type is not compatible with this operation
             *   (the shader must specify a pixel4
             *   output).
             * @throws  ArgumentError When filters includes a ShaderFilter and the shader
             *   doesn't specify any image input or the first
             *   input is not an image4 input.
             * @throws  ArgumentError When filters includes a ShaderFilter and the shader
             *   specifies an image input that isn't provided.
             * @throws  ArgumentError When filters includes a ShaderFilter, a
             *   ByteArray or Vector.<Number> instance as
             *   a shader input, and the width
             *   and height properties aren't specified for the
             *   ShaderInput object, or the specified values don't match the amount of
             *   data in the input data. See the ShaderInput.input
             *   property for more information.
             */
        public:
            std::vector<void *>        filters();
        public:
            void         filters(std::vector<void *> value);

            /**
             * A value from the BlendMode class that specifies which blend mode to use.
             * A bitmap can be drawn internally in two ways. If you have a blend mode enabled or an
             * external clipping mask, the bitmap is drawn by adding a bitmap-filled square shape to the vector
             * render. If you attempt to set this property to an invalid value, Flash runtimes set the value
             * to BlendMode.NORMAL.
             *
             *   The blendMode property affects each pixel of the display object.
             * Each pixel is composed of three constituent
             * colors (red, green, and blue), and each constituent color has a value between 0x00 and 0xFF.
             * Flash Player or Adobe AIR compares each constituent color of one pixel in the movie clip with
             * the corresponding color of the pixel in the background. For example, if blendMode
             * is set to BlendMode.LIGHTEN, Flash Player or Adobe AIR compares the red value of the display object with
             * the red value of the background, and uses the lighter of the two as the
             * value for the red component of the displayed color.The following table describes the blendMode settings.
             * The BlendMode class defines string values you can use.
             * The illustrations in the table show blendMode values applied to a circular
             * display object (2) superimposed on another display object (1).BlendMode ConstantIllustrationDescriptionBlendMode.NORMALThe display object appears in front of the background. Pixel values of the display object
             * override those of the background. Where the display object is transparent, the background is
             * visible.BlendMode.LAYERForces the creation of a transparency group for the display object. This means that the display
             * object is pre-composed in a temporary buffer before it is processed further. This is done
             * automatically if the display object is pre-cached using bitmap caching or if the display object is
             * a display object container with at least one child object with a blendMode
             * setting other than BlendMode.NORMAL. Not supported under GPU rendering.
             * BlendMode.MULTIPLYMultiplies the values of the display object constituent colors by the colors of the background color,
             * and then normalizes by dividing by 0xFF,
             * resulting in darker colors. This setting is commonly used for shadows and depth effects.
             *
             *   For example, if a constituent color (such as red) of one pixel in the display object and the
             * corresponding color of the pixel in the background both have the value 0x88, the multiplied
             * result is 0x4840. Dividing by 0xFF yields a value of 0x48 for that constituent color,
             * which is a darker shade than the color of the display object or the color of the background.BlendMode.SCREENMultiplies the complement (inverse) of the display object color by the complement of the background
             * color, resulting in a bleaching effect. This setting is commonly used for highlights or to remove black
             * areas of the display object.BlendMode.LIGHTENSelects the lighter of the constituent colors of the display object and the color of the background (the
             * colors with the larger values). This setting is commonly used for superimposing type.
             *
             *   For example, if the display object has a pixel with an RGB value of 0xFFCC33, and the background
             * pixel has an RGB value of 0xDDF800, the resulting RGB value for the displayed pixel is
             * 0xFFF833 (because 0xFF > 0xDD, 0xCC < 0xF8, and 0x33 > 0x00 = 33). Not supported under GPU rendering.BlendMode.DARKENSelects the darker of the constituent colors of the display object and the colors of the
             * background (the colors with the smaller values). This setting is commonly used for superimposing type.
             *
             *   For example, if the display object has a pixel with an RGB value of 0xFFCC33, and the background
             * pixel has an RGB value of 0xDDF800, the resulting RGB value for the displayed pixel is
             * 0xDDCC00 (because 0xFF > 0xDD, 0xCC < 0xF8, and 0x33 > 0x00 = 33). Not supported under GPU rendering.BlendMode.DIFFERENCECompares the constituent colors of the display object with the colors of its background, and subtracts
             * the darker of the values of the two constituent colors from the lighter value. This setting is commonly
             * used for more vibrant colors.
             *
             *   For example, if the display object has a pixel with an RGB value of 0xFFCC33, and the background
             * pixel has an RGB value of 0xDDF800, the resulting RGB value for the displayed pixel is
             * 0x222C33 (because 0xFF - 0xDD = 0x22, 0xF8 - 0xCC = 0x2C, and 0x33 - 0x00 = 0x33).BlendMode.ADDAdds the values of the constituent colors of the display object to the colors of its background, applying a
             * ceiling of 0xFF. This setting is commonly used for animating a lightening dissolve between
             * two objects.
             *
             *   For example, if the display object has a pixel with an RGB value of 0xAAA633, and the background
             * pixel has an RGB value of 0xDD2200, the resulting RGB value for the displayed pixel is
             * 0xFFC833 (because 0xAA + 0xDD > 0xFF, 0xA6 + 0x22 = 0xC8, and 0x33 + 0x00 = 0x33).BlendMode.SUBTRACTSubtracts the values of the constituent colors in the display object from the values of the
             * background color, applying a floor of 0. This setting is commonly used for animating a
             * darkening dissolve between two objects.
             *
             *   For example, if the display object has a pixel with an RGB value of 0xAA2233, and the background
             * pixel has an RGB value of 0xDDA600, the resulting RGB value for the displayed pixel is
             * 0x338400 (because 0xDD - 0xAA = 0x33, 0xA6 - 0x22 = 0x84, and 0x00 - 0x33 < 0x00).BlendMode.INVERTInverts the background.BlendMode.ALPHAApplies the alpha value of each pixel of the display object to the background.
             * This requires the blendMode setting of the parent display object to be set to
             * BlendMode.LAYER.
             * For example, in the illustration, the parent display object, which is a white background,
             * has blendMode = BlendMode.LAYER. Not supported under GPU rendering.BlendMode.ERASEErases the background based on the alpha value of the display object. This requires the
             * blendMode of the parent display object to be set to
             * BlendMode.LAYER. For example, in the
             * illustration, the parent display object, which is a white background, has
             * blendMode = BlendMode.LAYER. Not supported under GPU rendering.BlendMode.OVERLAYAdjusts the color of each pixel based on the darkness of the background.
             * If the background is lighter than 50% gray, the display object and background colors are
             * screened, which results in a lighter color. If the background is darker than 50% gray,
             * the colors are multiplied, which results in a darker color.
             * This setting is commonly used for shading effects. Not supported under GPU rendering.BlendMode.HARDLIGHTAdjusts the color of each pixel based on the darkness of the display object.
             * If the display object is lighter than 50% gray, the display object and background colors are
             * screened, which results in a lighter color. If the display object is darker than 50% gray,
             * the colors are multiplied, which results in a darker color.
             * This setting is commonly used for shading effects. Not supported under GPU rendering.BlendMode.SHADERN/AAdjusts the color using a custom shader routine. The shader that is used is specified
             * as the Shader instance assigned to the blendShader property. Setting the
             * blendShader property of a display object to a Shader instance
             * automatically sets the display object's blendMode property to
             * BlendMode.SHADER. If the blendMode property is set to
             * BlendMode.SHADER without first setting the blendShader property,
             * the blendMode property is set to BlendMode.NORMAL. Not supported under GPU rendering.
             * @langversion 3.0
             * @playerversion   Flash 9
             */
        public:
            std::string       blendMode();
        public:
            void         blendMode(std::string value);

            /**
             * An object with properties pertaining to a display object's matrix, color transform, and pixel bounds.
             * The specific properties     matrix, colorTransform, and three read-only properties
             * (concatenatedMatrix, concatenatedColorTransform,
             * and pixelBounds)     are described in the entry for the Transform class.
             *
             *   Each of the transform object's properties is itself an object. This concept is important because the only
             * way to set new values for the matrix or colorTransform objects is to create a new object and copy that
             * object into the transform.matrix or transform.colorTransform property.For example, to increase the tx value of a display object's matrix, you must make a
             * copy of the entire matrix object, then copy the new object into the matrix property of the transform
             * object:
             * var myMatrix:Matrix = myDisplayObject.transform.matrix;
             * myMatrix.tx += 10;
             * myDisplayObject.transform.matrix = myMatrix;
             * You cannot directly set the tx property. The following code has
             * no effect on myDisplayObject:
             * myDisplayObject.transform.matrix.tx += 10;
             * You can also copy an entire transform object and assign it to another
             * display object's transform property. For example, the following code
             * copies the entire transform object from myOldDisplayObj to
             * myNewDisplayObj:myNewDisplayObj.transform = myOldDisplayObj.transform;The resulting display object, myNewDisplayObj, now has the same values for its
             * matrix, color transform, and pixel bounds as the old display object, myOldDisplayObj.Note that AIR for TV devices use hardware acceleration, if it is available, for color transforms.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            flash::geom::Transform *transform();
        public:
            void         transform(Transform *value);

            /**
             * The current scaling grid that is in effect. If set to null,
             * the entire display object is scaled normally when any scale transformation is
             * applied.
             *
             *   When you define the scale9Grid property, the display object is divided into a
             * grid with nine regions based on the scale9Grid rectangle, which defines the
             * center region of the grid. The eight other regions of the grid are the following areas: The upper-left corner outside of the rectangleThe area above the rectangle The upper-right corner outside of the rectangleThe area to the left of the rectangleThe area to the right of the rectangleThe lower-left corner outside of the rectangleThe area below the rectangleThe lower-right corner outside of the rectangleYou can think of the eight regions outside of the center (defined by the rectangle)
             * as being like a picture frame that has special rules applied to it when scaled.When the scale9Grid property is set and a display object is scaled, all text and
             * gradients are scaled normally; however, for other types of objects the following rules apply:Content in the center region is scaled normally. Content in the corners is not scaled. Content in the top and bottom regions is scaled horizontally only. Content in the
             * left and right regions is scaled vertically only.All fills (including bitmaps, video, and gradients) are stretched to fit their shapes.If a display object is rotated, all subsequent scaling is normal (and the
             * scale9Grid property is ignored).For example, consider the following display object and a rectangle that is applied as the display
             * object's scale9Grid:The display object.The red rectangle shows the scale9Grid.When the display object is scaled or stretched, the objects within the rectangle scale
             * normally, but the objects outside of the rectangle scale according to the
             * scale9Grid rules:Scaled to 75%:Scaled to 50%:Scaled to 25%:Stretched horizontally 150%: A common use for setting scale9Grid is to set up a display object to be used
             * as a component, in which edge regions retain the same width when the component is scaled.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             * @maelexample The following creates a movie clip that contains a 20-pixel line (which forms a border)
             *   and a gradient fill. The movie clip scales based on the mouse position, and because of the
             *   <code>scale9Grid</code> set for the movie clip, the thickness of the 20-pixel line does not
             *   vary when the clip scales (although the gradient in the movie clip <em>does</em> scale):
             *
             *     <listing version="2.0">
             *   import flash.geom.Rectangle;
             *   import flash.geom.Matrix;
             *
             *     this.createEmptyMovieClip("my_mc", this.getNextHighestDepth());
             *
             *     var grid:Rectangle = new Rectangle(20, 20, 260, 260);
             *   my_mc.scale9Grid = grid ;
             *
             *     my_mc._x = 50;
             *   my_mc._y = 50;
             *
             *     function onMouseMove()
             *   {
             *   my_mc._width  = _xmouse;
             *   my_mc._height = _ymouse;
             *   }
             *
             *     my_mc.lineStyle(20, 0xff3333, 100);
             *   var gradient_matrix:Matrix = new Matrix();
             *   gradient_matrix.createGradientBox(15, 15, Math.PI, 10, 10);
             *   my_mc.beginGradientFill("radial", [0xffff00, 0x0000ff],
             *   [100, 100], [0, 0xFF], gradient_matrix,
             *   "reflect", "RGB", 0.9);
             *   my_mc.moveTo(0, 0);
             *   my_mc.lineTo(0, 300);
             *   my_mc.lineTo(300, 300);
             *   my_mc.lineTo(300, 0);
             *   my_mc.lineTo(0, 0);
             *   my_mc.endFill();
             *   </listing>
             * @throws  ArgumentError If you pass an invalid argument to the method.
             */
        public:
            flash::geom::Rectangle *scale9Grid();
        public:
            void         scale9Grid(Rectangle *innerRectangle);

            /**
             * Returns a LoaderInfo object containing information about loading the file
             * to which this display object belongs. The loaderInfo property is defined only
             * for the root display object of a SWF file or for a loaded Bitmap (not for a Bitmap that is drawn
             * with ActionScript). To find the loaderInfo object associated with the SWF file that contains
             * a display object named myDisplayObject, use myDisplayObject.root.loaderInfo.
             *
             *   A large SWF file can monitor its download by calling
             * this.root.loaderInfo.addEventListener(Event.COMPLETE, func).
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            flash::display::LoaderInfo *loaderInfo();

            /**
             * The current accessibility options for this display object. If you modify the accessibilityProperties
             * property or any of the fields within accessibilityProperties, you must call
             * the Accessibility.updateProperties() method to make your changes take effect.
             *
             *   Note: For an object created in the Flash authoring environment, the value of accessibilityProperties
             * is prepopulated with any information you entered in the Accessibility panel for
             * that object.
             * @langversion 3.0
             * @playerversion   Flash 9
             */
        public:
            flash::accessibility::AccessibilityProperties *accessibilityProperties();
        public:
            void         accessibilityProperties(AccessibilityProperties *value);

            /**
             * Sets a shader that is used for blending the foreground and background. When the
             * blendMode property is set to BlendMode.SHADER, the specified
             * Shader is used to create the blend mode output for the display object.
             *
             *   Setting the blendShader property of a display object to a Shader instance
             * automatically sets the display object's blendMode property to
             * BlendMode.SHADER. If the blendShader property is set (which sets the
             * blendMode property to BlendMode.SHADER), then the value of the
             * blendMode property is changed, the blend mode can be reset to use the blend
             * shader simply by setting the blendMode property to BlendMode.SHADER.
             * The blendShader property does not need to be set again except to change the
             * shader that's used for the blend mode.The Shader assigned to the blendShader property must specify at least two
             * image4 inputs. The inputs do not need to be specified in code using the
             * associated ShaderInput objects' input properties. The background display object
             * is automatically
             * used as the first input (the input with index 0). The foreground display object
             * is used as the second input (the input with index 1). A shader used as a blend
             * shader can specify more than two inputs. In that case, any additional input must be specified
             * by setting its ShaderInput instance's input property.When you assign a Shader instance to this property the shader is copied internally. The
             * blend operation uses that internal copy, not a reference to the original shader. Any changes
             * made to the shader, such as changing a parameter value, input, or bytecode, are not applied
             * to the copied shader that's used for the blend mode.
             * @langversion 3.0
             * @playerversion   Flash 10
             * @playerversion   AIR 1.5
             * @throws  ArgumentError When the shader output type is not compatible with this operation
             *   (the shader must specify a pixel4
             *   output).
             * @throws  ArgumentError When the shader specifies fewer than two image inputs or the first
             *   two inputs are not image4 inputs.
             * @throws  ArgumentError When the shader specifies an image input that isn't provided.
             * @throws  ArgumentError When a ByteArray or Vector.<Number> instance is used as
             *   an input and the width
             *   and height properties aren't specified for the
             *   ShaderInput, or the specified values don't match the amount of
             *   data in the input object. See the ShaderInput.input
             *   property for more information.
             */
        public:
            void         blendShader(Shader *value);

        public:
            Object       *metaData();
        public:
            void         metaData(Object *data);

        public:
            DisplayObject();

            /**
             * Converts the point object from the Stage (global) coordinates
             * to the display object's (local) coordinates.
             *
             *   To use this method, first create an instance of the Point class. The
             * x and y values that you assign represent global coordinates because they
             * relate to the origin (0,0) of the main display area. Then pass the Point instance
             * as the parameter to the globalToLocal() method. The method returns a new Point object with
             * x and y values that relate to the origin of the display object
             * instead of the origin of the Stage.
             * @param   point   An object created with the Point class. The Point object
             *   specifies the x and y coordinates as properties.
             * @return  A Point object with coordinates relative to the display object.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            flash::geom::Point *globalToLocal(Point *point);

            /**
             * Converts the point object from the display object's (local) coordinates to the
             * Stage (global) coordinates.
             *
             *   This method allows you to convert any given x and y coordinates from
             * values that are relative to the origin (0,0) of a specific display object (local coordinates)
             * to values that are relative to the origin of the Stage (global coordinates).To use this method, first create an instance of the Point class. The
             * x and y values that you assign represent local coordinates because they
             * relate to the origin of the display object.You then pass the Point instance that you created as the parameter to
             * the localToGlobal() method. The method returns a new Point object with
             * x and y values that relate to the origin of the Stage
             * instead of the origin of the display object.
             * @param   point   The name or identifier of a point created with the Point class, specifying the
             *   x and y coordinates as properties.
             * @return  A Point object with coordinates relative to the Stage.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            flash::geom::Point *localToGlobal(Point *point);

            /**
             * Returns a rectangle that defines the area of the display object relative to the coordinate system
             * of the targetCoordinateSpace object.
             * Consider the following code, which shows how the rectangle returned can vary depending on the
             * targetCoordinateSpace parameter that you pass to the method:
             *
             *   <codeblock>
             *
             *   var container:Sprite = new Sprite();
             * container.x = 100;
             * container.y = 100;
             * this.addChild(container);
             * var contents:Shape = new Shape();
             * contents.graphics.drawCircle(0,0,100);
             * container.addChild(contents);
             * trace(contents.getBounds(container));
             * // (x=-100, y=-100, w=200, h=200)
             * trace(contents.getBounds(this));
             * // (x=0, y=0, w=200, h=200)
             *
             *   </codeblock>
             * Note: Use the localToGlobal() and
             * globalToLocal() methods to convert the display object's local coordinates
             * to display coordinates, or display coordinates to local coordinates, respectively.The getBounds() method is similar to the getRect() method;
             * however, the Rectangle returned by the getBounds() method includes any strokes
             * on shapes, whereas the Rectangle returned by the getRect() method does not.
             * For an example, see the description of the getRect() method.
             * @param   targetCoordinateSpace   The display object that defines the coordinate system to use.
             * @return  The rectangle that defines the area of the display object relative to
             *   the targetCoordinateSpace object's coordinate system.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            flash::geom::Rectangle *getBounds(DisplayObject *targetCoordinateSpace);

            /**
             * Returns a rectangle that defines the boundary of the display object,
             * based on the coordinate system defined by the targetCoordinateSpace
             * parameter, excluding any strokes on shapes. The values that the getRect() method
             * returns are the same or smaller than those returned by the getBounds() method.
             *
             *   Note: Use localToGlobal() and globalToLocal() methods
             * to convert the display object's local coordinates to Stage coordinates, or Stage coordinates to
             * local coordinates, respectively.
             * @param   targetCoordinateSpace   The display object that defines the coordinate system to use.
             * @return  The rectangle that defines the area of the display object relative to
             *   the targetCoordinateSpace object's coordinate system.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            flash::geom::Rectangle *getRect(DisplayObject *targetCoordinateSpace);

            /**
             * Evaluates the bounding box of the display object to see if it overlaps or intersects with the
             * bounding box of the obj display object.
             * @param   obj The display object to test against.
             * @return  true if the bounding boxes of the display objects intersect; false if not.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            bool  hitTestObject(DisplayObject *obj);

            /**
             * Evaluates the display object to see if it overlaps or intersects with the
             * point specified by the x and y parameters.
             * The x and y parameters specify a point in the
             * coordinate space of the Stage, not the display object container that contains the
             * display object (unless that display object container is the Stage).
             * @param   x   The x coordinate to test against this object.
             * @param   y   The y coordinate to test against this object.
             * @param   shapeFlag   Whether to check against the actual pixels of the object (true)
             *   or the bounding box (false).
             * @return  true if the display object overlaps or intersects with the specified point;
             *   false otherwise.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            bool  hitTestPoint(float x, float y, bool shapeFlag=false);

            /**
             * Converts a two-dimensional point from the Stage (global) coordinates to a
             * three-dimensional display object's (local) coordinates.
             *
             *   To use this method, first create an instance of the Point class.
             * The x and y values that you assign to the Point object represent global
             * coordinates because they are relative to the origin (0,0) of the main display area.
             * Then pass the Point object to the globalToLocal3D()
             * method as the point parameter. The method returns three-dimensional
             * coordinates as a Vector3D object containing x, y, and
             * z values that are relative to the origin
             * of the three-dimensional display object.
             * @param   point   A two dimensional Point object representing global x and y coordinates.
             * @return  A Vector3D object with coordinates relative to the three-dimensional
             *   display object.
             * @langversion 3.0
             * @playerversion   Flash 10
             * @playerversion   AIR 1.5
             * @playerversion   Lite 4
             */
        public:
            flash::geom::Vector3D *globalToLocal3D(Point *point);

            /**
             * Converts a three-dimensional point of the three-dimensional display
             * object's (local) coordinates to a two-dimensional point in the Stage (global) coordinates.
             *
             *   For example, you can only use two-dimensional coordinates (x,y) to
             * draw with the display.Graphics methods. To draw a three-dimensional
             * object, you need to map the three-dimensional coordinates of a
             * display object to two-dimensional coordinates. First, create an instance of
             * the Vector3D class that holds the x-, y-, and z- coordinates of the three-dimensional
             * display object. Then pass the Vector3D object to the local3DToGlobal()
             * method as the point3d parameter. The method returns a two-dimensional Point
             * object that can be used
             * with the Graphics API to draw the three-dimensional object.
             * @param   point3d A Vector3D object containing either a three-dimensional point or
             *   the coordinates of the three-dimensional display object.
             * @return  A two-dimensional point representing a three-dimensional point
             *   in two-dimensional space.
             * @langversion 3.0
             * @playerversion   Flash 10
             * @playerversion   AIR 1.5
             * @playerversion   Lite 4
             */
        public:
            flash::geom::Point *local3DToGlobal(Vector3D *point3d);
        };
    }
}

#endif // FLEX11_6_FLASH_DISPLAY_DISPLAYOBJECT_AS
#endif // __cplusplus

