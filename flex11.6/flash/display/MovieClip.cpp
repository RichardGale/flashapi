

#include "MovieClip.h"
#include "flash/display/Scene.h"

    /**
     * The MovieClip class inherits from the following classes: Sprite, DisplayObjectContainer, 
     * InteractiveObject, DisplayObject, and EventDispatcher.
     * 
     *   <p class="- topic/p ">Unlike the Sprite object, a MovieClip object has a timeline.</p><p class="- topic/p ">&gt;In Flash Professional, the methods for the MovieClip class provide the same functionality 
     * as actions that target movie clips. Some additional methods do not have equivalent 
     * actions in the Actions toolbox in the Actions panel in the Flash authoring tool. </p><p class="- topic/p ">Children instances placed on the Stage in Flash Professional cannot be accessed by code from within the
     * constructor of a parent instance since they have not been created at that point in code execution.
     * Before accessing the child, the parent must instead either create the child instance
     * by code or delay access to a callback function that listens for the child to dispatch
     * its <codeph class="+ topic/ph pr-d/codeph ">Event.ADDED_TO_STAGE</codeph> event.</p><p class="- topic/p ">If you modify any of the following properties of a MovieClip object that contains a motion tween,
     * the playhead is stopped in that MovieClip object: <codeph class="+ topic/ph pr-d/codeph ">alpha</codeph>, <codeph class="+ topic/ph pr-d/codeph ">blendMode</codeph>, 
     * <codeph class="+ topic/ph pr-d/codeph ">filters</codeph>, <codeph class="+ topic/ph pr-d/codeph ">height</codeph>, <codeph class="+ topic/ph pr-d/codeph ">opaqueBackground</codeph>, <codeph class="+ topic/ph pr-d/codeph ">rotation</codeph>, 
     * <codeph class="+ topic/ph pr-d/codeph ">scaleX</codeph>, <codeph class="+ topic/ph pr-d/codeph ">scaleY</codeph>, <codeph class="+ topic/ph pr-d/codeph ">scale9Grid</codeph>, <codeph class="+ topic/ph pr-d/codeph ">scrollRect</codeph>, 
     * <codeph class="+ topic/ph pr-d/codeph ">transform</codeph>, <codeph class="+ topic/ph pr-d/codeph ">visible</codeph>, <codeph class="+ topic/ph pr-d/codeph ">width</codeph>, <codeph class="+ topic/ph pr-d/codeph ">x</codeph>, 
     * or <codeph class="+ topic/ph pr-d/codeph ">y</codeph>. However, it does not stop the playhead in any child MovieClip objects of that 
     * MovieClip object.</p><p class="- topic/p "><b class="+ topic/ph hi-d/b ">Note:</b>Flash Lite 4 supports the MovieClip.opaqueBackground property only if 
     * FEATURE_BITMAPCACHE is defined. The default configuration of Flash Lite 4 does not define 
     * FEATURE_BITMAPCACHE. To enable the MovieClip.opaqueBackground property for a suitable device, 
     * define FEATURE_BITMAPCACHE in your project.</p>
     * 
     *   EXAMPLE:
     * 
     *   The following example uses the MovieClipExample class to illustrate how
     * to monitor various properties of a MovieClip.  This task is accomplished by performing the following steps:
     * 
     *   <ol class="- topic/ol "><li class="- topic/li ">The constructor function defines a text field, which is used to display values of properties
     * of the MovieClipExample object (which extends MovieClip).</li><li class="- topic/li ">The return value of the <codeph class="+ topic/ph pr-d/codeph ">getPropertiesString()</codeph> method is used as text for the 
     * <codeph class="+ topic/ph pr-d/codeph ">outputText</codeph> text field. The <codeph class="+ topic/ph pr-d/codeph ">getPropertiesString()</codeph> method returns
     * a string that is populated with values of the following properties of the movie clip: 
     * <codeph class="+ topic/ph pr-d/codeph ">currentFrame</codeph>, <codeph class="+ topic/ph pr-d/codeph ">currentLabel</codeph>, <codeph class="+ topic/ph pr-d/codeph ">currentScene</codeph>, 
     * <codeph class="+ topic/ph pr-d/codeph ">framesLoaded</codeph>, <codeph class="+ topic/ph pr-d/codeph ">totalFrames</codeph>, and <codeph class="+ topic/ph pr-d/codeph ">trackAsMenu</codeph>.</li><li class="- topic/li ">Two lines of code in the constructor function adjust the <codeph class="+ topic/ph pr-d/codeph ">width</codeph> and
     * <codeph class="+ topic/ph pr-d/codeph ">height</codeph> properties of the <codeph class="+ topic/ph pr-d/codeph ">outputText</codeph> text field.</li><li class="- topic/li ">The last line of the constructor function adds the <codeph class="+ topic/ph pr-d/codeph ">outputText</codeph> text field
     * to the display list.</li></ol><codeblock xml:space="preserve" class="+ topic/pre pr-d/codeblock ">
     * 
     *   package {
     * import flash.display.MovieClip;
     * import flash.text.TextField;
     * 
     *   public class MovieClipExample extends MovieClip {
     * 
     *   public function MovieClipExample() {
     * var outputText:TextField = new TextField();
     * outputText.text = getPropertiesString();
     * outputText.width = stage.stageWidth;
     * outputText.height = outputText.textHeight;
     * addChild(outputText);
     * }
     * 
     *   private function getPropertiesString():String {
     * var str:String = ""
     * + "currentFrame: " + currentFrame + "\n"
     * + "currentLabel: " + currentLabel + "\n"
     * + "currentScene: " + currentScene + "\n"
     * + "framesLoaded: " + framesLoaded + "\n"
     * + "totalFrames: " + totalFrames + "\n"
     * + "trackAsMenu: " + trackAsMenu + "\n";
     * return str;
     * }
     * }
     * }
     * </codeblock>
     * @langversion 3.0
     * @playerversion   Flash 9
     * @playerversion   Lite 4
     */

using namespace flash::display;

namespace flash {
namespace display {


        /**
         * Specifies the number of the frame in which the playhead is located in the timeline of 
         * the MovieClip instance. If the movie clip has multiple scenes, this value is the 
         * frame number in the current scene.
         * @langversion 3.0
         * @playerversion   Flash 9
         * @playerversion   Lite 4
         */
        int MovieClip::currentFrame()      ;

        /**
         * The number of frames that are loaded from a streaming SWF file. You can use the framesLoaded 
         * property to determine whether the contents of a specific frame and all the frames before it
         * loaded and are available locally in the browser. You can also use it to monitor the downloading 
         * of large SWF files. For example, you might want to display a message to users indicating that 
         * the SWF file is loading until a specified frame in the SWF file finishes loading.
         * 
         *   If the movie clip contains multiple scenes, the framesLoaded property returns the number 
         * of frames loaded for all scenes in the movie clip.
         * @langversion 3.0
         * @playerversion   Flash 9
         * @playerversion   Lite 4
         */
        int MovieClip::framesLoaded()      ;

        /**
         * The total number of frames in the MovieClip instance.
         * 
         *   If the movie clip contains multiple frames, the totalFrames property returns 
         * the total number of frames in all scenes in the movie clip.
         * @langversion 3.0
         * @playerversion   Flash 9
         * @playerversion   Lite 4
         */
        int MovieClip::totalFrames()      ;

        /**
         * Indicates whether other display objects that are SimpleButton or MovieClip objects can receive 
         * mouse release events or other user input release events. The trackAsMenu property lets you create menus. You 
         * can set the trackAsMenu property on any SimpleButton or MovieClip object.
         * The default value of the trackAsMenu property is false.
         * 
         *   You can change the trackAsMenu property at any time; the modified movie 
         * clip immediately uses the new behavior.
         * @langversion 3.0
         * @playerversion   Flash 9
         */
        bool MovieClip::trackAsMenu()          ;
        void MovieClip::trackAsMenu(bool value)       ;

        /**
         * An array of Scene objects, each listing the name, the number of frames,
         * and the frame labels for a scene in the MovieClip instance.
         * @langversion 3.0
         * @playerversion   Flash 9
         * @playerversion   Lite 4
         */
        std::vector<void*> MovieClip::scenes()        ;

        /**
         * The current scene in which the playhead is located in the timeline of the MovieClip instance.
         * @langversion 3.0
         * @playerversion   Flash 9
         * @playerversion   Lite 4
         */
        flash::display::Scene* MovieClip::currentScene()                      ;

        /**
         * The current label in which the playhead is located in the timeline of the MovieClip instance.
         * If the current frame has no label, currentLabel is set to the name of the previous frame 
         * that includes a label. If the current frame and previous frames do not include a label,
         * currentLabel returns null.
         * @langversion 3.0
         * @playerversion   Flash 9
         * @playerversion   Lite 4
         */
        std::string MovieClip::currentLabel()         ;

        /**
         * The label at the current frame in the timeline of the MovieClip instance.
         * If the current frame has no label, currentLabel is null.
         * @langversion 3.0
         * @playerversion   Flash 10
         * @playerversion   AIR 1.5
         * @playerversion   Lite 4
         */
        std::string MovieClip::currentFrameLabel()         ;

        /**
         * Returns an array of FrameLabel objects from the current scene. If the MovieClip instance does
         * not use scenes, the array includes all frame labels from the entire MovieClip instance.
         * @langversion 3.0
         * @playerversion   Flash 9
         * @playerversion   Lite 4
         */
        std::vector<void*> MovieClip::currentLabels()        ;

        /**
         * A Boolean value that indicates whether a movie clip is enabled. The default value of enabled
         * is true. If enabled is set to false, the movie clip's
         * Over, Down, and Up frames are disabled. The movie clip
         * continues to receive events (for example, mouseDown,
         * mouseUp, keyDown, and keyUp).
         * 
         *   The enabled property governs only the button-like properties of a movie clip. You
         * can change the enabled property at any time; the modified movie clip is immediately
         * enabled or disabled. If enabled is set to false, the object is not 
         * included in automatic tab ordering.
         * @langversion 3.0
         * @playerversion   Flash 9
         * @playerversion   Lite 4
         */
        bool MovieClip::enabled()          ;
        void MovieClip::enabled(bool value)       ;

        bool MovieClip::isPlaying()          ;

        /**
         * Creates a new MovieClip instance. After creating the MovieClip, call the 
         * addChild() or addChildAt() method of a
         * display object container that is onstage.
         * @langversion 3.0
         * @playerversion   Flash 9
         * @playerversion   Lite 4
         */
        MovieClip::MovieClip();

        /**
         * Moves the playhead in the timeline of the movie clip.
         * @langversion 3.0
         * @playerversion   Flash 9
         * @playerversion   Lite 4
         */
        void MovieClip::play()       ;

        /**
         * Stops the playhead in the movie clip.
         * @langversion 3.0
         * @playerversion   Flash 9
         * @playerversion   Lite 4
         */
        void MovieClip::stop()       ;

        /**
         * Sends the playhead to the next frame and stops it.  This happens after all 
         * remaining actions in the frame have finished executing.
         * @langversion 3.0
         * @playerversion   Flash 9
         * @playerversion   Lite 4
         */
        void MovieClip::nextFrame()       ;

        /**
         * Sends the playhead to the previous frame and stops it.  This happens after all 
         * remaining actions in the frame have finished executing.
         * @langversion 3.0
         * @playerversion   Flash 9
         * @playerversion   Lite 4
         */
        void MovieClip::prevFrame()       ;

        /**
         * Starts playing the SWF file at the specified frame.  This happens after all 
         * remaining actions in the frame have finished executing.  To specify a scene 
         * as well as a frame, specify a value for the scene parameter.
         * @param   frame   A number representing the frame number, or a string representing the label of the 
         *   frame, to which the playhead is sent. If you specify a number, it is relative to the 
         *   scene you specify. If you do not specify a scene, the current scene determines the global frame number to play. If you do specify a scene, the playhead
         *   jumps to the frame number in the specified scene.
         * @param   scene   The name of the scene to play. This parameter is optional.
         * @langversion 3.0
         * @playerversion   Flash 9
         * @playerversion   Lite 4
         */
        void MovieClip::gotoAndPlay(Object* frame, std::string scene)       ;

        /**
         * Brings the playhead to the specified frame of the movie clip and stops it there.  This happens after all 
         * remaining actions in the frame have finished executing.  If you want to specify a scene in addition to a frame, 
         * specify a scene parameter.
         * @param   frame   A number representing the frame number, or a string representing the label of the 
         *   frame, to which the playhead is sent. If you specify a number, it is relative to the 
         *   scene you specify. If you do not specify a scene, the current scene determines the global frame number at which to go to and stop. If you do specify a scene, 
         *   the playhead goes to the frame number in the specified scene and stops.
         * @param   scene   The name of the scene. This parameter is optional.
         * @langversion 3.0
         * @playerversion   Flash 9
         * @playerversion   Lite 4
         * @throws  ArgumentError If the scene or frame specified are
         *   not found in this movie clip.
         */
        void MovieClip::gotoAndStop(Object* frame, std::string scene)       ;

        void MovieClip::addFrameScript(...)       ;

        /**
         * Moves the playhead to the previous scene of the MovieClip instance.  This happens after all 
         * remaining actions in the frame have finished executing.
         * @langversion 3.0
         * @playerversion   Flash 9
         * @playerversion   Lite 4
         */
        void MovieClip::prevScene()       ;

        /**
         * Moves the playhead to the next scene of the MovieClip instance.  This happens after all 
         * remaining actions in the frame have finished executing.
         * @langversion 3.0
         * @playerversion   Flash 9
         * @playerversion   Lite 4
         */
        void MovieClip::nextScene()       ;
}
}

