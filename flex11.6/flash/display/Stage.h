#if !defined(FLEX11_6_FLASH_DISPLAY_STAGE_AS)
#define FLEX11_6_FLASH_DISPLAY_STAGE_AS
#if defined(__cplusplus)


#include "flex11.6.h"
namespace flash
{
    namespace display
    {
        class InteractiveObject;
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
    namespace media
    {
        class StageVideo;
    }
}
namespace flash
{
    namespace display
    {
        class Stage3D;
    }
}
namespace flash
{
    namespace display
    {
        class DisplayObject;
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
    namespace accessibility
    {
        class AccessibilityProperties;
    }
}
namespace flash
{
    namespace accessibility
    {
        class AccessibilityImplementation;
    }
}
namespace flash
{
    namespace events
    {
        class Event;
    }
}
namespace flash
{
    namespace text
    {
        class TextSnapshot;
    }
}
namespace flash
{
    namespace ui
    {
        class ContextMenu;
    }
}

/**
 * Dispatched by the Stage object when the state of the stageVideos property changes.
 * @eventType   flash.events.StageVideoAvailabilityEvent.STAGE_VIDEO_AVAILABILITY
 */
//[Event(name="stageVideoAvailability",type="flash.events.StageVideoAvailabilityEvent")]

/**
 * Dispatched by the Stage object when the stage orientation changes.
 * @eventType   flash.events.StageOrientationEvent.ORIENTATION_CHANGE
 */
//[Event(name="orientationChange",type="flash.events.StageOrientationEvent")]

/**
 * Dispatched by the Stage object when the stage orientation begins changing.
 * @eventType   flash.events.StageOrientationEvent.ORIENTATION_CHANGING
 */
//[Event(name="orientationChanging",type="flash.events.StageOrientationEvent")]

/**
 * Dispatched when the Stage object enters, or leaves, full-screen mode.
 * @eventType   flash.events.FullScreenEvent.FULL_SCREEN
 */
//[Event(name="fullScreen",type="flash.events.FullScreenEvent")]

/**
 * Dispatched when the scaleMode property of the Stage object is set to
 * StageScaleMode.NO_SCALE and the SWF file is resized.
 * @eventType   flash.events.Event.RESIZE
 */
//[Event(name="resize",type="flash.events.Event")]

/**
 * Dispatched by the Stage object when the pointer moves out of the
 * stage area.
 * @eventType   flash.events.Event.MOUSE_LEAVE
 */
//[Event(name="mouseLeave",type="flash.events.Event")]

using namespace flash::accessibility;
using namespace flash::display;
using namespace flash::events;
using namespace flash::geom;
using namespace flash::media;
using namespace flash::text;
using namespace flash::ui;

namespace flash
{
    namespace display
    {
        /**
         * The Stage class represents the main drawing area.
         *
         *   <p class="- topic/p ">For SWF content running in the browser (in
         * Flash<sup class="+ topic/ph hi-d/sup ">  </sup> Player), the Stage represents the entire area where Flash
         * content is shown. For content running in AIR on desktop operating systems, each NativeWindow object has a corresponding
         * Stage object.</p><p class="- topic/p ">The Stage object is not globally accessible. You need to access it through the
         * <codeph class="+ topic/ph pr-d/codeph ">stage</codeph> property of a DisplayObject instance.</p><p class="- topic/p ">The Stage class has several ancestor classes     DisplayObjectContainer, InteractiveObject,
         * DisplayObject, and EventDispatcher     from which it inherits properties and methods.
         * Many of these properties and methods are either inapplicable to Stage objects,
         * or require security checks when called on a Stage object.  The properties and methods that
         * require security checks are documented as part of the Stage class.</p><p class="- topic/p ">In addition, the following inherited properties are inapplicable to Stage objects. If you
         * try to set them, an IllegalOperationError is thrown. These properties may always be read, but
         * since they cannot be set, they will always contain default values.</p><ul class="- topic/ul "><li class="- topic/li "><codeph class="+ topic/ph pr-d/codeph ">accessibilityProperties</codeph></li><li class="- topic/li "><codeph class="+ topic/ph pr-d/codeph ">alpha</codeph></li><li class="- topic/li "><codeph class="+ topic/ph pr-d/codeph ">blendMode</codeph></li><li class="- topic/li "><codeph class="+ topic/ph pr-d/codeph ">cacheAsBitmap</codeph></li><li class="- topic/li "><codeph class="+ topic/ph pr-d/codeph ">contextMenu</codeph></li><li class="- topic/li "><codeph class="+ topic/ph pr-d/codeph ">filters</codeph></li><li class="- topic/li "><codeph class="+ topic/ph pr-d/codeph ">focusRect</codeph></li><li class="- topic/li "><codeph class="+ topic/ph pr-d/codeph ">loaderInfo</codeph></li><li class="- topic/li "><codeph class="+ topic/ph pr-d/codeph ">mask</codeph></li><li class="- topic/li "><codeph class="+ topic/ph pr-d/codeph ">mouseEnabled</codeph></li><li class="- topic/li "><codeph class="+ topic/ph pr-d/codeph ">name</codeph></li><li class="- topic/li "><codeph class="+ topic/ph pr-d/codeph ">opaqueBackground</codeph></li><li class="- topic/li "><codeph class="+ topic/ph pr-d/codeph ">rotation</codeph></li><li class="- topic/li "><codeph class="+ topic/ph pr-d/codeph ">scale9Grid</codeph></li><li class="- topic/li "><codeph class="+ topic/ph pr-d/codeph ">scaleX</codeph></li><li class="- topic/li "><codeph class="+ topic/ph pr-d/codeph ">scaleY</codeph></li><li class="- topic/li "><codeph class="+ topic/ph pr-d/codeph ">scrollRect</codeph></li><li class="- topic/li "><codeph class="+ topic/ph pr-d/codeph ">tabEnabled</codeph></li><li class="- topic/li "><codeph class="+ topic/ph pr-d/codeph ">tabIndex</codeph></li><li class="- topic/li "><codeph class="+ topic/ph pr-d/codeph ">transform</codeph></li><li class="- topic/li "><codeph class="+ topic/ph pr-d/codeph ">visible</codeph></li><li class="- topic/li "><codeph class="+ topic/ph pr-d/codeph ">x</codeph></li><li class="- topic/li "><codeph class="+ topic/ph pr-d/codeph ">y</codeph></li></ul><p class="- topic/p ">Some events that you might expect to be a part of the Stage class,
         * such as <codeph class="+ topic/ph pr-d/codeph ">enterFrame</codeph>, <codeph class="+ topic/ph pr-d/codeph ">exitFrame</codeph>,
         * <codeph class="+ topic/ph pr-d/codeph ">frameConstructed</codeph>, and <codeph class="+ topic/ph pr-d/codeph ">render</codeph>,
         * cannot be Stage events because a reference to the Stage object
         * cannot be guaranteed to exist in every situation where these events
         * are used. Because these events cannot be dispatched by the Stage
         * object, they are instead dispatched by every DisplayObject instance,
         * which means that you can add an event listener to
         * any DisplayObject instance to listen for these events.
         * These events, which are part of the DisplayObject class,
         * are called broadcast events to differentiate them from events
         * that target a specific DisplayObject instance.
         * Two other broadcast events, <codeph class="+ topic/ph pr-d/codeph ">activate</codeph> and <codeph class="+ topic/ph pr-d/codeph ">deactivate</codeph>,
         * belong to DisplayObject's superclass, EventDispatcher.
         * The <codeph class="+ topic/ph pr-d/codeph ">activate</codeph> and <codeph class="+ topic/ph pr-d/codeph ">deactivate</codeph> events
         * behave similarly to the DisplayObject broadcast events, except
         * that these two events are dispatched not only by all DisplayObject
         * instances, but also by all EventDispatcher instances and instances
         * of other EventDispatcher subclasses.
         * For more information on broadcast events, see the DisplayObject class.</p>
         *
         *   EXAMPLE:
         *
         *   The following example uses the <codeph class="+ topic/ph pr-d/codeph ">StageExample</codeph> class to dispatch
         * events whenever the stage is activated or resized.  This is accomplished by performing the following steps:
         * <ol class="- topic/ol "><li class="- topic/li ">The class constructor first sets the Flash application to be fixed, regardless of the size of
         * the Flash Player window and then adds two event listeners with the
         * <codeph class="+ topic/ph pr-d/codeph ">activateHandler()</codeph> and <codeph class="+ topic/ph pr-d/codeph ">resizeHandler()</codeph> methods.</li><li class="- topic/li ">The <codeph class="+ topic/ph pr-d/codeph ">activateHandler()</codeph> method runs when the left mouse button is clicked.</li><li class="- topic/li ">The <codeph class="+ topic/ph pr-d/codeph ">resizeHandler()</codeph> method runs when the stage is resized.</li></ol><codeblock xml:space="preserve" class="+ topic/pre pr-d/codeblock ">
         * package {
         * import flash.display.Sprite;
         * import flash.display.StageAlign;
         * import flash.display.StageScaleMode;
         * import flash.events.Event;
         *
         *   public class StageExample extends Sprite {
         *
         *   public function StageExample() {
         * stage.scaleMode = StageScaleMode.NO_SCALE;
         * stage.align = StageAlign.TOP_LEFT;
         * stage.addEventListener(Event.ACTIVATE, activateHandler);
         * stage.addEventListener(Event.RESIZE, resizeHandler);
         * }
         *
         *   private function activateHandler(event:Event):void {
         * trace("activateHandler: " + event);
         * }
         *
         *   private function resizeHandler(event:Event):void {
         * trace("resizeHandler: " + event);
         * trace("stageWidth: " + stage.stageWidth + " stageHeight: " + stage.stageHeight);
         * }
         * }
         * }
         * </codeblock>
         * @langversion 3.0
         * @playerversion   Flash 9
         * @playerversion   Lite 4
         */
        class Stage : public DisplayObjectContainer
        {
            /**
             * Gets and sets the frame rate of the stage. The frame rate is defined as frames per second.
             * By default the rate is set to the frame rate of the first SWF file loaded. Valid range for the frame rate
             * is from 0.01 to 1000 frames per second.
             *
             *   Note: An application might not be able to follow
             * high frame rate settings, either because the target platform is not fast enough or the player is
             * synchronized to the vertical blank timing of the display device (usually 60 Hz on LCD devices).
             * In some cases, a target platform might also choose to lower the maximum frame rate if it
             * anticipates high CPU usage.For content running in Adobe AIR, setting the frameRate property of one Stage
             * object changes the frame rate for all Stage objects (used by different NativeWindow objects).
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             * @throws  SecurityError Calling the frameRate property of a Stage object throws an exception for
             *   any caller that is not in the same security sandbox as the Stage owner (the main SWF file).
             *   To avoid this, the Stage owner can grant permission to the domain of the caller by calling
             *   the Security.allowDomain() method or the Security.allowInsecureDomain() method.
             *   For more information, see the "Security" chapter in the ActionScript 3.0 Developer's Guide.
             */
        public:
            float       frameRate();
        public:
            void         frameRate(float value);

            /**
             * A value from the StageScaleMode class that specifies which scale mode to use.
             * The following are valid values:
             *
             *   StageScaleMode.EXACT_FIT   The entire application is visible
             * in the specified area without trying to preserve the original aspect ratio. Distortion can occur, and the application may appear stretched or compressed.
             * StageScaleMode.SHOW_ALL   The entire application is visible
             * in the specified area without distortion while maintaining the original aspect ratio of the application.
             * Borders can appear on two sides of the application.
             * StageScaleMode.NO_BORDER   The entire application fills the specified area,
             * without distortion but possibly with some cropping, while maintaining the original aspect ratio
             * of the application.
             * StageScaleMode.NO_SCALE   The entire application is fixed, so that
             * it remains unchanged even as the size of the player window changes. Cropping might
             * occur if the player window is smaller than the content.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             * @throws  SecurityError Calling the scaleMode property of a Stage object throws an exception for
             *   any caller that is not in the same security sandbox as the Stage owner (the main SWF file).
             *   To avoid this, the Stage owner can grant permission to the domain of the caller by calling
             *   the Security.allowDomain() method or the Security.allowInsecureDomain() method.
             *   For more information, see the "Security" chapter in the ActionScript 3.0 Developer's Guide.
             */
        public:
            std::string       scaleMode();
        public:
            void         scaleMode(std::string value);

            /**
             * A value from the StageAlign class that specifies the alignment of the stage in
             * Flash Player or the browser. The following are valid values:
             *
             *   ValueVertical AlignmentHorizontalStageAlign.TOPTopCenterStageAlign.BOTTOMBottomCenterStageAlign.LEFTCenterLeftStageAlign.RIGHTCenterRightStageAlign.TOP_LEFTTopLeftStageAlign.TOP_RIGHTTopRightStageAlign.BOTTOM_LEFTBottomLeftStageAlign.BOTTOM_RIGHTBottomRightThe align property is only available to an object that is in the same security sandbox
             * as the Stage owner (the main SWF file).
             * To avoid this, the Stage owner can grant permission to the domain of the
             * calling object by calling the Security.allowDomain() method or the Security.alowInsecureDomain() method.
             * For more information, see the "Security" chapter in the ActionScript 3.0 Developer's Guide.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            std::string       align();
        public:
            void         align(std::string value);

            /**
             * Specifies the current width, in pixels, of the Stage.
             *
             *   If the value of the Stage.scaleMode property is set to StageScaleMode.NO_SCALE
             * when the user resizes the window, the Stage content maintains its defined size while the stageWidth
             * property changes to reflect the new width size of the screen area occupied by the SWF file. (In the other scale
             * modes, the stageWidth property always reflects the original width of the SWF file.) You can add an event
             * listener for the resize event and then use the stageWidth property of the Stage class to
             * determine the actual pixel dimension of the resized Flash runtime window. The event listener allows you to control how
             * the screen content adjusts when the user resizes the window.Air for TV devices have slightly different behavior than desktop devices
             * when you set the stageWidth property.
             * If the Stage.scaleMode
             * property is set to StageScaleMode.NO_SCALE and you set the stageWidth
             * property, the stage width does not change until the next
             * frame of the SWF.Note: In an HTML page hosting the SWF file, both the object and embed tags' width attributes must be set to a percentage (such as 100%), not pixels. If the
             * settings are generated by JavaScript code, the width parameter of the AC_FL_RunContent()
             * method must be set to a percentage, too. This percentage is applied to the stageWidth
             * value.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             * @throws  SecurityError Calling the stageWidth property of a Stage object throws an exception for
             *   any caller that is not in the same security sandbox as the Stage owner (the main SWF file).
             *   To avoid this, the Stage owner can grant permission to the domain of the caller by calling
             *   the Security.allowDomain() method or the Security.allowInsecureDomain() method.
             *   For more information, see the "Security" chapter in the ActionScript 3.0 Developer's Guide.
             */
        public:
            int          stageWidth();
        public:
            void         stageWidth(int value);

            /**
             * The current height, in pixels, of the Stage.
             *
             *   If the value of the Stage.scaleMode property is set to StageScaleMode.NO_SCALE
             * when the user resizes the window, the Stage content maintains its size while the
             * stageHeight property changes to reflect the new height size of the screen area occupied by
             * the SWF file. (In the other scale modes, the stageHeight property always reflects the original
             * height of the SWF file.) You can add an event listener for the resize event and then use the
             * stageHeight property of the Stage class to determine the actual pixel dimension of the resized
             * Flash runtime window. The event listener allows you to control how
             * the screen content adjusts when the user resizes the window.Air for TV devices have slightly different behavior than desktop devices
             * when you set the stageHeight property.
             * If the Stage.scaleMode
             * property is set to StageScaleMode.NO_SCALE and you set the stageHeight
             * property, the stage height does not change until the next
             * frame of the SWF.Note: In an HTML page hosting the SWF file, both the object and embed tags' height attributes must be set to a percentage (such as 100%), not pixels. If the
             * settings are generated by JavaScript code, the height parameter of the AC_FL_RunContent()
             * method must be set to a percentage, too. This percentage is applied to the stageHeight
             * value.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             * @throws  SecurityError Calling the stageHeight property of a Stage object throws an exception for
             *   any caller that is not in the same security sandbox as the Stage owner (the main SWF file).
             *   To avoid this, the Stage owner can grant permission to the domain of the caller by calling
             *   the Security.allowDomain() method or the Security.allowInsecureDomain() method.
             *   For more information, see the "Security" chapter in the ActionScript 3.0 Developer's Guide.
             */
        public:
            int          stageHeight();
        public:
            void         stageHeight(int value);

            /**
             * Specifies whether to show or hide the default items in the Flash runtime
             * context menu.
             *
             *   If the showDefaultContextMenu property is set to true (the
             * default), all context menu items appear. If the showDefaultContextMenu property
             * is set to false, only the Settings and About... menu items appear.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @throws  SecurityError Calling the showDefaultContextMenu property of a Stage object throws an exception for
             *   any caller that is not in the same security sandbox as the Stage owner (the main SWF file).
             *   To avoid this, the Stage owner can grant permission to the domain of the caller by calling
             *   the Security.allowDomain() method or the Security.allowInsecureDomain() method.
             *   For more information, see the "Security" chapter in the ActionScript 3.0 Developer's Guide.
             */
        public:
            bool      showDefaultContextMenu();
        public:
            void         showDefaultContextMenu(bool value);

            /**
             * The interactive object with keyboard focus; or null if focus is not set
             * or if the focused object belongs to a security sandbox to which the calling object does not
             * have access.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             * @throws  Error Throws an error if focus cannot be set to the target.
             */
        public:
            flash::display::InteractiveObject *focus();
        public:
            void         focus(InteractiveObject *newFocus);

            /**
             * Controls Flash runtime color correction for displays.
             * Color correction works only if the main monitor is assigned a valid ICC color profile, which specifies
             * the device's particular color attributes.
             * By default, the Flash runtime tries to match the color correction of its host (usually a browser).
             *
             *   Use the Stage.colorCorrectionSupport property
             * to determine if color correction is available on the current system and the default state.
             * .    If color correction is available, all colors on the stage are assumed to be in
             * the sRGB color space, which is the most standard color space. Source profiles of input devices are not considered during color correction.
             * No input color correction is applied; only the stage output is mapped to the main
             * monitor's ICC color profile.In general, the benefits of activating color management include predictable and consistent color, better conversion,
             * accurate proofing and more efficient cross-media output. Be aware, though, that color management does not provide
             * perfect conversions due to devices having a different gamut from each other or original images.
             * Nor does color management eliminate the need for custom or edited profiles.
             * Color profiles are dependent on browsers, operating systems (OS), OS extensions, output devices, and application support.Applying color correction degrades the Flash runtime performance.
             * A Flash runtime's color correction is document style color correction because
             * all SWF movies are considered documents with implicit sRGB profiles.
             * Use the Stage.colorCorrectionSupport property to tell the Flash runtime
             * to correct colors when displaying the SWF file (document) to the display color space.
             * Flash runtimes only compensates for differences between monitors, not for differences between input devices (camera/scanner/etc.).
             * The three possible values are strings with corresponding constants in the flash.display.ColorCorrection class:"default": Use the same color correction as the host system."on": Always perform color correction."off": Never perform color correction.
             * @langversion 3.0
             * @playerversion   Flash 10
             * @playerversion   AIR 1.5
             */
        public:
            std::string       colorCorrection();
        public:
            void         colorCorrection(std::string value);

            /**
             * Specifies whether the Flash runtime is running on an operating system that supports
             * color correction and whether the color profile of the main (primary)
             * monitor can be read and understood by the Flash runtime. This property also returns the default state
             * of color correction on the host system (usually the browser).
             * Currently the return values can be:
             * The three possible values are strings with corresponding constants in the flash.display.ColorCorrectionSupport class:"unsupported": Color correction is not available."defaultOn": Always performs color correction."defaultOff": Never performs color correction.
             * @langversion 3.0
             * @playerversion   Flash 10
             * @playerversion   AIR 1.5
             */
        public:
            std::string       colorCorrectionSupport();

            /**
             * Specifies whether or not objects display a glowing border when they have focus.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             * @throws  SecurityError Calling the stageFocusRect property of a Stage object throws an exception for
             *   any caller that is not in the same security sandbox as the Stage owner (the main SWF file).
             *   To avoid this, the Stage owner can grant permission to the domain of the caller by calling
             *   the Security.allowDomain() method or the Security.allowInsecureDomain() method.
             *   For more information, see the "Security" chapter in the ActionScript 3.0 Developer's Guide.
             */
        public:
            bool      stageFocusRect();
        public:
            void         stageFocusRect(bool on);

            /**
             * A value from the StageQuality class that specifies which rendering quality is used.
             * The following are valid values:
             *
             *   StageQuality.LOW   Low rendering quality. Graphics are not
             * anti-aliased, and bitmaps are not smoothed, but runtimes still use mip-mapping.StageQuality.MEDIUM   Medium rendering quality. Graphics are
             * anti-aliased using a 2 x 2 pixel grid, bitmap smoothing is dependent on the Bitmap.smoothing setting.
             * Runtimes use mip-mapping. This setting is suitable for movies that do not contain text.StageQuality.HIGH   High rendering quality. Graphics are anti-aliased
             * using a 4 x 4 pixel grid, and bitmap smoothing is dependent on the Bitmap.smoothing setting.
             * Runtimes use mip-mapping. This is the default rendering quality setting that Flash Player uses.StageQuality.BEST   Very high rendering quality. Graphics are
             * anti-aliased using a 4 x 4 pixel grid. If Bitmap.smoothing is true the runtime uses a high quality
             * downscale algorithm that produces fewer artifacts (however, using StageQuality.BEST with Bitmap.smoothing set to true
             * slows performance significantly and is not a recommended setting).Higher quality settings produce better rendering of scaled bitmaps. However, higher
             * quality settings are computationally more expensive. In particular, when rendering scaled video,
             * using higher quality settings can reduce the frame rate.
             * In the desktop profile of Adobe AIR, quality can be set
             * to StageQuality.BEST or StageQuality.HIGH (and the default value
             * is StageQuality.HIGH). Attempting to set it to another value has no effect
             * (and the property remains unchanged). In the moble profile of AIR, all four quality settings
             * are available. The default value on mobile devices is StageQuality.MEDIUM.For content running in Adobe AIR, setting the quality property of one Stage
             * object changes the rendering quality for all Stage objects (used by different NativeWindow objects).
             * Note: The operating system draws the device fonts,
             * which are therefore unaffected by the quality property.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             * @throws  SecurityError Calling the quality property of a Stage object throws an exception for
             *   any caller that is not in the same security sandbox as the Stage owner (the main SWF file).
             *   To avoid this, the Stage owner can grant permission to the domain of the caller by calling
             *   the Security.allowDomain() method or the Security.allowInsecureDomain() method.
             *   For more information, see the "Security" chapter in the ActionScript 3.0 Developer's Guide.
             */
        public:
            std::string       quality();
        public:
            void         quality(std::string value);

            /**
             * A value from the StageDisplayState class that specifies which display state to use. The following
             * are valid values:
             *
             *   StageDisplayState.FULL_SCREEN Sets AIR application or Flash runtime to expand the
             * stage over the user's entire screen, with keyboard input disabled.StageDisplayState.FULL_SCREEN_INTERACTIVE Sets the AIR application to expand the
             * stage over the user's entire screen, with keyboard input allowed.
             * (Not available for content running in Flash Player.)StageDisplayState.NORMAL Sets the Flash runtime back to the standard stage display mode.The scaling behavior of the movie in full-screen mode is determined by the scaleMode
             * setting (set using the Stage.scaleMode property or the SWF file's embed
             * tag settings in the HTML file). If the scaleMode property is set to noScale
             * while the application transitions to full-screen mode, the Stage width and height
             * properties are updated, and the Stage dispatches a resize event. If any other scale mode is set,
             * the stage and its contents are scaled to fill the new screen dimensions. The Stage object retains its original
             * width and height values and does not dispatch a resize event.The following restrictions apply to SWF files that play within an HTML page (not those using the stand-alone
             * Flash Player or not running in the AIR runtime):To enable full-screen mode, add the allowFullScreen parameter to the object
             * and embed tags in the HTML page that includes the SWF file, with allowFullScreen set
             * to "true", as shown in the following example:
             *
             *   <codeblock>
             * <param name="allowFullScreen" value="true" />
             * ...
             * <embed src="example.swf" allowFullScreen="true" ... >
             * </codeblock>
             * An HTML page may also use a script to generate SWF-embedding tags. You need to alter the script
             * so that it inserts the proper allowFullScreen settings. HTML pages generated by Flash Professional and
             * Flash Builder use the AC_FL_RunContent() function to embed references to SWF files, and you
             * need to add the allowFullScreen parameter settings, as in the following:
             * <codeblock>
             * AC_FL_RunContent( ... "allowFullScreen", "true", ... )
             * </codeblock>
             * Full-screen mode is initiated in response to a mouse click or key press by the user; the movie cannot change
             * Stage.displayState without user input. Flash runtimes restrict keyboard input  in full-screen mode.
             * Acceptable keys include keyboard shortcuts that terminate full-screen mode and non-printing keys such as arrows, space, Shift,
             * and Tab keys. Keyboard shortcuts that terminate full-screen mode are: Escape (Windows, Linux, and Mac), Control+W (Windows),
             * Command+W (Mac), and Alt+F4.
             * A Flash runtime dialog box appears over the movie when users enter full-screen mode to inform the users they are in
             * full-screen mode and that they can press the Escape key to end full-screen mode.Starting with Flash Player 9.0.115.0, full-screen works the same in windowless mode as it does in window mode.
             * If you set the Window Mode (wmode in the HTML) to Opaque Windowless (opaque)
             * or Transparent Windowless (transparent), full-screen can be initiated,
             * but the full-screen window will always be opaque.These restrictions are not present for SWF content running in the
             * stand-alone Flash Player or in AIR. AIR supports an interactive full-screen mode which allows keyboard input.For AIR content running in full-screen mode, the system screen saver
             * and power saving options are disabled while video content is playing and until either the video stops
             * or full-screen mode is exited.On Linux, setting displayState to StageDisplayState.FULL_SCREEN or
             * StageDisplayState.FULL_SCREEN_INTERACTIVE is an asynchronous operation.
             * @langversion 3.0
             * @playerversion   Flash 9.0.28.0
             * @playerversion   Lite 4
             * @throws  SecurityError Calling the displayState property of a Stage object throws an exception for
             *   any caller that is not in the same security sandbox as the Stage owner (the main SWF file).
             *   To avoid this, the Stage owner can grant permission to the domain of the caller by calling
             *   the Security.allowDomain() method or the Security.allowInsecureDomain() method.
             *   For more information, see the "Security" chapter in the ActionScript 3.0 Developer's Guide.
             *   Trying to set the displayState property while the settings dialog is displayed, without a user response, or
             *   if the param or embed HTML tag's allowFullScreen attribute is not set to
             *   true throws a security error.
             */
        public:
            std::string       displayState();
        public:
            void         displayState(std::string value);

            /**
             * Sets the Flash runtime to scale a specific region of the stage to full-screen mode.
             * If available, the Flash runtime scales in hardware, which uses the graphics and video card on a user's computer,
             * and generally displays content more quickly than software scaling.
             *
             *   When this property is set to a valid rectangle and the displayState property is set to full-screen mode,
             * the Flash runtime scales the specified area. The actual Stage size in pixels within ActionScript does not change.
             * The Flash runtime enforces a minimum limit for the size of the rectangle to accommodate the standard "Press Esc to exit full-screen mode" message.
             * This limit is usually around 260 by 30 pixels but can vary on platform and Flash runtime version.This property can only be set when the Flash runtime is not in full-screen mode.
             * To use this property correctly, set this property first, then set the displayState property to full-screen mode, as shown in the code examples.To enable scaling, set the fullScreenSourceRect property to a rectangle object:
             * <codeblock>
             *
             *   // valid, will enable hardware scaling
             * stage.fullScreenSourceRect = new Rectangle(0,0,320,240);
             *
             *   </codeblock>
             * To disable scaling, set the fullScreenSourceRect=null in ActionScript 3.0, and undefined in ActionScript 2.0.
             * <codeblock>
             *
             *   stage.fullScreenSourceRect = null;
             *
             *   </codeblock>
             * The end user also can select within Flash Player Display Settings to turn off hardware scaling, which is enabled by default.
             * For more information, see www.adobe.com/go/display_settings.
             * @langversion 3.0
             * @playerversion   Flash 9.0.115.0
             * @playerversion   Lite 4
             */
        public:
            flash::geom::Rectangle *fullScreenSourceRect();
        public:
            void         fullScreenSourceRect(Rectangle *value);

        public:
            bool      mouseLock();
        public:
            void         mouseLock(bool value);

            /**
             * A list of StageVideo objects available for playing external videos.
             *
             *   You can use only a limited number of StageVideo objects at a time.
             * When a SWF begins to run, the number of available StageVideo objects depends on the platform
             * and on available hardware.
             * To use a StageVideo object, assign a member of the stageVideos Vector object to a StageVideo variable.
             * All StageVideo objects are displayed on the stage behind any display objects.
             * The StageVideo objects are displayed on the stage in the order they appear in
             * the stageVideos Vector object. For example, if the stageVideos Vector object contains
             * three entries:The StageVideo object in the 0 index of the stageVideos Vector object is
             * displayed behind all StageVideo objects.The StageVideo object at index 1 is displayed in front
             * of the StageVideo object at index 0.The StageVideo object at index 2 is displayed in front
             * of the StageVideo object at index 1.Use the StageVideo.depth property to change this ordering.Note: AIR for TV devices support only one StageVideo object.
             * @langversion 3.0
             * @playerversion   AIR 2.5
             */
        public:
            std::vector<flash::media::StageVideo *> stageVideos();

        public:
            std::vector<Stage3D *> stage3Ds();

        public:
            unsigned int         color();
        public:
            void         color(unsigned int color);

            /**
             * Returns the width of the monitor that will be used when going to full screen size, if that state
             * is entered immediately. If the user has multiple monitors, the monitor that's used is the
             * monitor that most of the stage is on at the time.
             *
             *   Note: If the user has the opportunity to move the browser from one
             * monitor to another between retrieving the value and going to full screen
             * size, the value could be incorrect. If you retrieve the value in an event handler that
             * sets Stage.displayState to StageDisplayState.FULL_SCREEN, the value will be
             * correct.This is the pixel width of the monitor and is the same as the stage width would be if
             * Stage.align is set to StageAlign.TOP_LEFT and
             * Stage.scaleMode is set to StageScaleMode.NO_SCALE.
             * @langversion 3.0
             * @playerversion   Flash 9.0.115.0
             * @playerversion   Lite 4
             */
        public:
            unsigned int         fullScreenWidth();

            /**
             * Returns the height of the monitor that will be used when going to full screen size, if that state
             * is entered immediately. If the user has multiple monitors, the monitor that's used is the
             * monitor that most of the stage is on at the time.
             *
             *   Note: If the user has the opportunity to move the browser from one
             * monitor to another between retrieving the value and going to full screen
             * size, the value could be incorrect. If you retrieve the value in an event handler that
             * sets Stage.displayState to StageDisplayState.FULL_SCREEN, the value will be
             * correct.This is the pixel height of the monitor and is the same as the
             * stage height would be if Stage.align is set to StageAlign.TOP_LEFT
             * and Stage.scaleMode is set to StageScaleMode.NO_SCALE.
             * @langversion 3.0
             * @playerversion   Flash 9.0.115.0
             * @playerversion   Lite 4
             */
        public:
            unsigned int         fullScreenHeight();

            /**
             * Indicates whether GPU compositing is available and in use. The wmodeGPU value is trueonly
             * when all three of the following conditions exist:
             * GPU compositing has been requested.GPU compositing is available.GPU compositing is in use.Specifically, the wmodeGPU property indicates one of the following:GPU compositing has not been requested or is unavailable. In this case, the wmodeGPU property value is false.GPU compositing has been requested (if applicable and available), but the environment is operating in "fallback mode"
             * (not optimal rendering) due to limitations of the content. In this case, the wmodeGPU property value is true.GPU compositing has been requested (if applicable and available), and the environment is operating in the best mode. In this case, the
             * wmodeGPU property value is also true.In other words, the wmodeGPU property identifies the capability and state of the rendering environment. For runtimes
             * that do not support GPU compositing, such as AIR 1.5.2, the value is always false, because (as stated above) the value is
             * true only when GPU compositing has been requested, is available, and is in use.The wmodeGPU property is useful to determine, at runtime, whether or not GPU compositing is in use. The value of
             * wmodeGPU indicates if your content is going to be scaled by hardware, or not, so you can present graphics at the correct size.
             * You can also determine if you're rendering in a fast path or not, so that you can adjust your content complexity accordingly.For Flash Player in a browser, GPU compositing can be requested by the value of gpu for the wmode HTML
             * parameter in the page hosting the SWF file. For other configurations, GPU compositing can be requested in the header of a SWF file
             * (set using SWF authoring tools).However, the wmodeGPU property does not identify the current rendering performance. Even if GPU compositing is "in use" the rendering
             * process might not be operating in the best mode. To adjust your content for optimal rendering, use a Flash runtime debugger version,
             * and set the DisplayGPUBlendsetting in your mm.cfg file.Note: This property is always false when referenced
             * from ActionScript that runs before the runtime performs its first rendering
             * pass.  For example, if you examine wmodeGPU from a script in Frame 1 of
             * Adobe Flash Professional, and your SWF file is the first SWF file loaded in a new
             * instance of the runtime, then the wmodeGPU value is false.
             * To get an accurate value, wait until at least one rendering pass
             * has occurred. If you write an event listener for the
             * exitFrame event of any DisplayObject, the wmodeGPU value at
             * is the correct value.
             * @langversion 3.0
             * @playerversion   Flash 10.0.32
             * @playerversion   AIR 1.5.2
             * @playerversion   Lite 4
             */
        public:
            bool      wmodeGPU();

            /**
             * The area of the stage that is currently covered by the software keyboard.
             *
             *   The area has a size of zero (0,0,0,0) when the soft keyboard is not visible.When the keyboard opens, the softKeyboardRect is set at the time the
             * softKeyboardActivate event is dispatched. If the keyboard changes size while open,
             * the runtime updates the softKeyboardRect property and dispatches an
             * additional softKeyboardActivate event.Note: On Android, the area covered by the keyboard is estimated when
             * the operating system does not provide the information necessary to determine the exact
             * area. This problem occurs in fullscreen mode and also when the keyboard opens in response to
             * an InteractiveObject receiving focus or invoking the requestSoftKeyboard() method.
             * @langversion 3.0
             * @playerversion   AIR 2.6
             * @playerversion   Flash 10.2
             */
        public:
            flash::geom::Rectangle *softKeyboardRect();

        public:
            void         name(std::string value);

        public:
            void         mask(DisplayObject *value);

        public:
            void         visible(bool value);

        public:
            void         x(float value);

        public:
            void         y(float value);

        public:
            void         z(float value);

        public:
            void         scaleX(float value);

        public:
            void         scaleY(float value);

        public:
            void         scaleZ(float value);

        public:
            void         rotation(float value);

        public:
            void         rotationX(float value);

        public:
            void         rotationY(float value);

        public:
            void         rotationZ(float value);

        public:
            void         alpha(float value);

        public:
            void         cacheAsBitmap(bool value);

        public:
            void         opaqueBackground(Object *value);

        public:
            void         scrollRect(Rectangle *value);

        public:
            void         filters(std::vector<void *> value);

        public:
            void         blendMode(std::string value);

        public:
            void         transform(Transform *value);

        public:
            void         accessibilityProperties(AccessibilityProperties *value);

        public:
            void         scale9Grid(Rectangle *value);

        public:
            void         tabEnabled(bool value);

        public:
            void         tabIndex(int value);

        public:
            void         focusRect(Object *value);

        public:
            void         mouseEnabled(bool value);

        public:
            void         accessibilityImplementation(AccessibilityImplementation *value);

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
             * @throws  SecurityError Referencing the width property of a Stage object throws an exception for
             *   any caller that is not in the same security sandbox as the Stage owner (the main SWF file).
             *   To avoid this, the Stage owner can grant permission to the domain of the caller by calling
             *   the Security.allowDomain() method or the Security.allowInsecureDomain() method.
             *   For more information, see the "Security" chapter in the ActionScript 3.0 Developer's Guide.
             * @throws  IllegalOperationError It is always illegal to set the width property of a Stage object,
             *   even if you are the Stage owner.
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
             * @throws  SecurityError Referencing the height property of a Stage object throws an exception for
             *   any caller that is not in the same security sandbox as the Stage owner (the main SWF file).
             *   To avoid this, the Stage owner can grant permission to the domain of the caller by calling
             *   the Security.allowDomain() method or the Security.allowInsecureDomain() method.
             *   For more information, see the "Security" chapter in the ActionScript 3.0 Developer's Guide.
             * @throws  IllegalOperationError It is always illegal to set the height property of a Stage object,
             *   even if the calling object is the Stage owner (the main SWF file).
             */
        public:
            float       height();
        public:
            void         height(float value);

            /**
             * Returns a TextSnapshot object for this DisplayObjectContainer instance.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @throws  IllegalOperationError Referencing the textSnapshot property of a Stage object throws an
             *   exception because the Stage class does not implement this property. To avoid this, call the
             *   textSnapshot property of a display object container other than the Stage object.
             */
        public:
            flash::text::TextSnapshot *textSnapshot();

            /**
             * Determines whether or not the children of the object are mouse, or user input device, enabled.
             * If an object is enabled, a user can interact with it by using a mouse or user input device. The default is true.
             *
             *   This property is useful when you create a button with an instance of the Sprite class
             * (instead of using the SimpleButton class). When you use a Sprite instance to create a button,
             * you can choose to decorate the button by using the addChild() method to add additional
             * Sprite instances. This process can cause unexpected behavior with mouse events because
             * the Sprite instances you add as children can become the target object of a mouse event
             * when you expect the parent instance to be the target object. To ensure that the parent
             * instance serves as the target objects for mouse events, you can set the
             * mouseChildren property of the parent instance to false. No event is dispatched by setting this property. You must use the
             * addEventListener() method to create interactive functionality.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             * @throws  SecurityError Referencing the mouseChildren property of a Stage object throws an exception for
             *   any caller that is not in the same security sandbox as the Stage owner (the main SWF file).
             *   To avoid this, the Stage owner can grant permission to the domain of the caller by calling
             *   the Security.allowDomain() method or the Security.allowInsecureDomain() method.
             *   For more information, see the "Security" chapter in the ActionScript 3.0 Developer's Guide.
             */
        public:
            bool      mouseChildren();
        public:
            void         mouseChildren(bool value);

            /**
             * Returns the number of children of this object.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             * @throws  SecurityError Referencing the numChildren property of a Stage object throws an exception for
             *   any caller that is not in the same security sandbox as the Stage owner (the main SWF file).
             *   To avoid this, the Stage owner can grant permission to the domain of the caller by calling
             *   the Security.allowDomain() method or the Security.allowInsecureDomain() method.
             *   For more information, see the "Security" chapter in the ActionScript 3.0 Developer's Guide.
             */
        public:
            int          numChildren();

            /**
             * Determines whether the children of the object are tab enabled. Enables or disables tabbing for the
             * children of the object. The default is true.
             * Note: Do not use the tabChildren property with Flex.
             * Instead, use the mx.core.UIComponent.hasFocusableChildren property.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @throws  SecurityError Referencing the tabChildren property of a Stage object throws an exception for
             *   any caller that is not in the same security sandbox as the Stage owner (the main SWF file).
             *   To avoid this, the Stage owner can grant permission to the domain of the caller by calling
             *   the Security.allowDomain() method or the Security.allowInsecureDomain() method.
             *   For more information, see the "Security" chapter in the ActionScript 3.0 Developer's Guide.
             */
        public:
            bool      tabChildren();
        public:
            void         tabChildren(bool value);

            /**
             * Specifies whether this stage allows the use of the full screen mode
             * @langversion 3.0
             * @playerversion   Flash 10.2
             * @oldexample  The following example traces the value of this read-only property:
             *   <pre xml:space="preserve" class="- topic/pre ">
             *   trace(Stage.allowsFullsreen);
             *   </pre>
             */
        public:
            bool      allowsFullScreen();

        public:
            bool      allowsFullScreenInteractive();

        public:
            float       contentsScaleFactor();

        public:
            std::string       displayContextInfo();

        public:
            void            *constructor();
        public:
            void         constructor(void *c);

        public:
            void         contextMenu(ContextMenu *value);

            /**
             * Calling the invalidate() method signals Flash runtimes to alert display objects
             * on the next opportunity it has to render the display list (for example, when the playhead
             * advances to a new frame). After you call the invalidate() method, when the display
             * list is next rendered, the Flash runtime sends a render event to each display object that has
             * registered to listen for the render event. You must call the invalidate()
             * method each time you want the Flash runtime to send render events.
             *
             *   The render event gives you an opportunity to make changes to the display list
             * immediately before it is actually rendered. This lets you defer updates to the display list until the
             * latest opportunity. This can increase performance by eliminating unnecessary screen updates.The render event is dispatched only to display objects that are in the same
             * security domain as the code that calls the stage.invalidate() method,
             * or to display objects from a security domain that has been granted permission via the
             * Security.allowDomain() method.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            void     invalidate();

        public:
            Stage();

            /**
             * Determines whether the Stage.focus property returns null for
             * security reasons.
             * In other words, isFocusInaccessible returns true if the
             * object that has focus belongs to a security sandbox to which the SWF file does not have access.
             * @return  true if the object that has focus belongs to a security sandbox to which
             *   the SWF file does not have access.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            bool  isFocusInaccessible();

            /**
             * Adds a child DisplayObject instance to this DisplayObjectContainer instance. The child is added
             * to the front (top) of all other children in this DisplayObjectContainer instance. (To add a child to a
             * specific index position, use the addChildAt() method.)
             *
             *   If you add a child object that already has a different display object container as
             * a parent, the object is removed from the child list of the other display object container. Note: The command stage.addChild() can cause problems with a published SWF file,
             * including security problems and conflicts with other loaded SWF files. There is only one Stage within a Flash runtime instance,
             * no matter how many SWF files you load into the runtime. So, generally, objects
             * should not be added to the Stage, directly, at all. The only object the Stage should
             * contain is the root object. Create a DisplayObjectContainer to contain all of the items on the
             * display list. Then, if necessary, add that DisplayObjectContainer instance to the Stage.
             * @param   child   The DisplayObject instance to add as a child of this DisplayObjectContainer instance.
             * @return  The DisplayObject instance that you pass in the
             *   child parameter.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             * @throws  SecurityError Calling the addChild() method of a Stage object throws an exception for
             *   any caller that is not in the same security sandbox as the Stage owner (the main SWF file).
             *   To avoid this, the Stage owner can grant permission to the domain of the caller by calling
             *   the Security.allowDomain() method or the Security.allowInsecureDomain() method.
             *   For more information, see the "Security" chapter in the ActionScript 3.0 Developer's Guide.
             */
        public:
            flash::display::DisplayObject *addChild(DisplayObject *child);

            /**
             * Adds a child DisplayObject instance to this DisplayObjectContainer
             * instance.  The child is added
             * at the index position specified. An index of 0 represents the back (bottom)
             * of the display list for this DisplayObjectContainer object.
             *
             *   For example, the following example shows three display objects, labeled a, b, and c, at
             * index positions 0, 2, and 1, respectively:If you add a child object that already has a different display object container as
             * a parent, the object is removed from the child list of the other display object container.
             * @param   child   The DisplayObject instance to add as a child of this
             *   DisplayObjectContainer instance.
             * @param   index   The index position to which the child is added. If you specify a
             *   currently occupied index position, the child object that exists at that position and all
             *   higher positions are moved up one position in the child list.
             * @return  The DisplayObject instance that you pass in the
             *   child parameter.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             * @throws  SecurityError Calling the addChildAt() method of a Stage object throws an exception for
             *   any caller that is not in the same security sandbox as the Stage owner (the main SWF file).
             *   To avoid this, the Stage owner can grant permission to the domain of the caller by calling
             *   the Security.allowDomain() method or the Security.allowInsecureDomain() method.
             *   For more information, see the "Security" chapter in the ActionScript 3.0 Developer's Guide.
             */
        public:
            flash::display::DisplayObject *addChildAt(DisplayObject *child, int index);

            /**
             * Changes the  position of an existing child in the display object container.
             * This affects the layering of child objects. For example, the following example shows three
             * display objects, labeled a, b, and c, at index positions 0, 1, and 2, respectively:
             *
             *   When you use the setChildIndex() method and specify an index position
             * that is already occupied, the only positions that change are those in between the display object's former and new position.
             * All others will stay the same.
             * If a child is moved to an index LOWER than its current index, all children in between will INCREASE by 1 for their index reference.
             * If a child is moved to an index HIGHER than its current index, all children in between will DECREASE by 1 for their index reference.
             * For example, if the display object container
             * in the previous example is named container, you can swap the position
             * of the display objects labeled a and b by calling the following code:
             * <codeblock>
             * container.setChildIndex(container.getChildAt(1), 0);
             * </codeblock>
             * This code results in the following arrangement of objects:
             * @param   child   The child DisplayObject instance for which you want to change
             *   the index number.
             * @param   index   The resulting index number for the child display object.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             * @throws  SecurityError Calling the setChildIndex() method of a Stage object throws an exception for
             *   any caller that is not in the same security sandbox as the Stage owner (the main SWF file).
             *   To avoid this, the Stage owner can grant permission to the domain of the caller by calling
             *   the Security.allowDomain() method or the Security.allowInsecureDomain() method.
             *   For more information, see the "Security" chapter in the ActionScript 3.0 Developer's Guide.
             */
        public:
            void     setChildIndex(DisplayObject *child, int index);

            /**
             * Registers an event listener object with an EventDispatcher object so that the listener
             * receives notification of an event. You can register event listeners on all nodes in the
             * display list for a specific type of event, phase, and priority.After you successfully register an event listener, you cannot change its priority
             * through additional calls to addEventListener(). To change a listener's
             * priority, you must first call removeListener(). Then you can register the
             * listener again with the new priority level. Keep in mind that after the listener is registered, subsequent calls to
             * addEventListener() with a different type or
             * useCapture value result in the creation of a separate listener registration.
             * For example, if you first register a listener with useCapture set to
             * true, it listens only during the capture phase. If you call
             * addEventListener() again using the same listener object, but with
             * useCapture set to false, you have two separate listeners: one
             * that listens during the capture phase and another that listens during the target and
             * bubbling phases.You cannot register an event listener for only the target phase or the bubbling
             * phase. Those phases are coupled during registration because bubbling
             * applies only to the ancestors of the target node.If you no longer need an event listener, remove it by calling
             * removeEventListener(), or memory problems could result. Event listeners are not automatically
             * removed from memory because the garbage
             * collector does not remove the listener as long as the dispatching object exists (unless the useWeakReference
             * parameter is set to true).Copying an EventDispatcher instance does not copy the event listeners attached to it.
             * (If your newly created node needs an event listener, you must attach the listener after
             * creating the node.) However, if you move an EventDispatcher instance, the event listeners
             * attached to it move along with it.If the event listener is being registered on a node while an event is being processed
             * on this node, the event listener is not triggered during the current phase but can be
             * triggered during a later phase in the event flow, such as the bubbling phase.If an event listener is removed from a node while an event is being processed on the node,
             * it is still triggered by the current actions. After it is removed, the event listener is
             * never invoked again (unless registered again for future processing).
             * @param   type    The type of event.
             * @param   listener    The listener function that processes the event. This function must accept
             *   an Event object as its only parameter and must return nothing, as this example shows:
             *   <codeblock>
             *   function(evt:Event):void
             *   </codeblock>
             *   The function can have any name.
             * @param   useCapture  Determines whether the listener works in the capture phase or the
             *   target and bubbling phases. If useCapture is set to true,
             *   the listener processes the event only during the capture phase and not in the
             *   target or bubbling phase. If useCapture is false, the
             *   listener processes the event only during the target or bubbling phase. To listen for
             *   the event in all three phases, call addEventListener twice, once with
             *   useCapture set to true, then again with
             *   useCapture set to false.
             * @param   priority    The priority level of the event listener. The priority is designated by
             *   a signed 32-bit integer. The higher the number, the higher the priority. All listeners
             *   with priority n are processed before listeners of priority n-1. If two
             *   or more listeners share the same priority, they are processed in the order in which they
             *   were added. The default priority is 0.
             * @param   useWeakReference    Determines whether the reference to the listener is strong or
             *   weak. A strong reference (the default) prevents your listener from being garbage-collected.
             *   A weak reference does not. Class-level member functions are not subject to garbage
             *   collection, so you can set useWeakReference to true for
             *   class-level member functions without subjecting them to garbage collection. If you set
             *   useWeakReference to true for a listener that is a nested inner
             *   function, the function will be garbage-collected and no longer persistent. If you create
             *   references to the inner function (save it in another variable) then it is not
             *   garbage-collected and stays persistent.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             * @throws  SecurityError Calling the addEventListener method of a Stage object throws an exception for
             *   any caller that is not in the same security sandbox as the Stage owner (the main SWF file).
             *   To avoid this situation, the Stage owner can grant permission to the domain of the caller by calling
             *   the Security.allowDomain() method or the Security.allowInsecureDomain() method.
             *   For more information, see the "Security" chapter in the ActionScript 3.0 Developer's Guide.
             */
        public:
            void     addEventListener(std::string type, Function *listener, bool useCapture=false, int priority=0, bool useWeakReference=false);

            /**
             * Dispatches an event into the event flow. The event target is the EventDispatcher
             * object upon which the dispatchEvent() method is called.
             * @param   event   The Event object that is dispatched into the event flow.
             *   If the event is being redispatched, a clone of the event is created automatically.
             *   After an event is dispatched, its target property cannot be changed, so you
             *   must create a new copy of the event for redispatching to work.
             * @return  A value of true if the event was successfully dispatched. A value of false indicates failure or that preventDefault() was called
             *   on the event.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             * @throws  SecurityError Calling the dispatchEvent() method of a Stage object throws an exception for
             *   any caller that is not in the same security sandbox as the Stage owner (the main SWF file).
             *   To avoid this, the Stage owner can grant permission to the domain of the caller by calling
             *   the Security.allowDomain() method or the Security.allowInsecureDomain() method.
             *   For more information, see the "Security" chapter in the ActionScript 3.0 Developer's Guide.
             */
        public:
            bool  dispatchEvent(flash::events::Event *event);

            /**
             * Checks whether the EventDispatcher object has any listeners registered for a specific type
             * of event. This allows you to determine where an EventDispatcher object has altered
             * handling of an event type in the event flow hierarchy. To determine whether a specific
             * event type actually triggers an event listener, use willTrigger().
             *
             *   The difference between hasEventListener() and willTrigger()
             * is that hasEventListener() examines only the object to
             * which it belongs, whereas willTrigger() examines the entire
             * event flow for the event specified by the type parameter.
             *
             *   When hasEventListener() is called from a LoaderInfo object, only the
             * listeners that the caller can access are considered.
             * @param   type    The type of event.
             * @return  A value of true if a listener of the specified type is registered;
             *   false otherwise.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             * @throws  SecurityError Calling the hasEventListener() method of a Stage object throws an exception for
             *   any caller that is not in the same security sandbox as the Stage owner (the main SWF file).
             *   To avoid this, the Stage owner can grant permission to the domain of the caller by calling
             *   the Security.allowDomain() method or the Security.allowInsecureDomain() method.
             *   For more information, see the "Security" chapter in the ActionScript 3.0 Developer's Guide.
             */
        public:
            bool  hasEventListener(std::string type);

            /**
             * Checks whether an event listener is registered with this EventDispatcher object or any of
             * its ancestors for the specified event type. This method returns true if an
             * event listener is triggered during any phase of the event flow when an event of the
             * specified type is dispatched to this EventDispatcher object or any of its descendants.
             *
             *   The difference between the hasEventListener() and the willTrigger()
             * methods is that hasEventListener() examines only the object to which it belongs,
             * whereas the willTrigger() method examines the entire event flow for the event specified by the
             * type parameter. When willTrigger() is called from a LoaderInfo object, only the
             * listeners that the caller can access are considered.
             * @param   type    The type of event.
             * @return  A value of true if a listener of the specified type will be triggered; false otherwise.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @throws  SecurityError Calling the willTrigger() method of a Stage object throws an exception for
             *   any caller that is not in the same security sandbox as the Stage owner (the main SWF file).
             *   To avoid this, the Stage owner can grant permission to the domain of the caller by calling
             *   the Security.allowDomain() method or the Security.allowInsecureDomain() method.
             *   For more information, see the "Security" chapter in the ActionScript 3.0 Developer's Guide.
             */
        public:
            bool  willTrigger(std::string type);

            /**
             * Removes a child DisplayObject from the specified index position in the child list of
             * the DisplayObjectContainer. The parent property of the removed child is set to
             * null, and the object is garbage collected if no other references to the child exist. The index
             * positions of any display objects above the child in the DisplayObjectContainer are decreased by 1.
             *
             *   The garbage collector reallocates unused memory space. When a variable or
             * object is no longer actively referenced or stored somewhere, the garbage collector sweeps
             * through and wipes out the memory space it used to occupy if no other references to it exist.
             * @param   index   The child index of the DisplayObject to remove.
             * @return  The DisplayObject instance that was removed.
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             * @throws  SecurityError Calling the removeChildAt() method of a Stage object throws an exception for
             *   any caller that is not in the same security sandbox as the object to be removed. To avoid this,
             *   the owner of that object can grant permission to the domain of the caller by calling
             *   the Security.allowDomain() method or the Security.allowInsecureDomain() method.
             *   For more information, see the "Security" chapter in the ActionScript 3.0 Developer's Guide.
             */
        public:
            flash::display::DisplayObject *removeChildAt(int index);

        public:
            void     swapChildrenAt(int index1, int index2);
        };
    }
}

#endif // FLEX11_6_FLASH_DISPLAY_STAGE_AS
#endif // __cplusplus

