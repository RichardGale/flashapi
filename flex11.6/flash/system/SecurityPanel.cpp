

    /**
     * The SecurityPanel class provides values for specifying
     * which Security Settings panel you want to display.
     * 
     *   <p class="- topic/p ">This class contains static constants that are used with the 
     * <codeph class="+ topic/ph pr-d/codeph ">Security.showSettings()</codeph> method. You cannot create new instances
     * of the SecurityPanel class.</p>
     * 
     *   EXAMPLE:
     * 
     *   The following example shows how a <codeph class="+ topic/ph pr-d/codeph ">click</codeph> event on a Sprite object can be
     * used to show the Local Storage Settings panel of the Flash Player Settings.  An orange box is added to the 
     * stage using <codeph class="+ topic/ph pr-d/codeph ">draw()</codeph>.  In <codeph class="+ topic/ph pr-d/codeph ">draw()</codeph>, a <codeph class="+ topic/ph pr-d/codeph ">click</codeph> event listener is 
     * added named <codeph class="+ topic/ph pr-d/codeph ">clickHandler()</codeph>, which responds to <codeph class="+ topic/ph pr-d/codeph ">click</codeph> events by directing
     * Flash Player to open its Local Storage Settings panel.
     * <codeblock xml:space="preserve" class="+ topic/pre pr-d/codeblock ">
     * package {
     * import flash.display.Sprite;
     * import flash.text.TextField;
     * import flash.events.*;
     * import flash.system.Security;
     * import flash.system.SecurityPanel;
     * 
     *   public class SecurityExample extends Sprite {
     * private var bgColor:uint = 0xFFCC00;
     * private var size:uint = 100;
     * 
     *   public function SecurityExample() {
     * draw();
     * }
     * 
     *   private function draw():void {
     * var child:Sprite = new Sprite();
     * child.graphics.beginFill(bgColor);
     * child.graphics.drawRect(0, 0, size, size);
     * child.graphics.endFill();
     * child.buttonMode = true;
     * 
     *   var label:TextField = new TextField();
     * label.text = "settings";
     * label.selectable = false;
     * label.mouseEnabled = false;
     * child.addChild(label);
     * 
     *   child.addEventListener(MouseEvent.CLICK, clickHandler);
     * addChild(child);
     * }
     * 
     *   private function clickHandler(event:MouseEvent):void {
     * Security.showSettings(SecurityPanel.LOCAL_STORAGE);
     * }
     * }
     * }
     * </codeblock>
     * @langversion 3.0
     * @playerversion   Flash 9
     * @playerversion   Lite 4
     */


namespace flash {
namespace system {


        /**
         * When passed to Security.showSettings(), displays the panel
         * that was open the last time the user closed the Flash Player Settings.
         * @langversion 3.0
         * @playerversion   Flash 9
         * @playerversion   Lite 4
         */
        const std::string SecurityPanel::DEFAULT="default";

        /**
         * When passed to Security.showSettings(), displays the
         * Privacy Settings panel in Flash Player Settings.
         * @langversion 3.0
         * @playerversion   Flash 9
         * @playerversion   Lite 4
         */
        const std::string SecurityPanel::PRIVACY="privacy";

        /**
         * When passed to Security.showSettings(), displays the
         * Local Storage Settings panel in Flash Player Settings.
         * @langversion 3.0
         * @playerversion   Flash 9
         * @playerversion   Lite 4
         */
        const std::string SecurityPanel::LOCAL_STORAGE="localStorage";

        /**
         * When passed to Security.showSettings(), displays the
         * Microphone panel in Flash Player Settings.
         * @langversion 3.0
         * @playerversion   Flash 9
         * @playerversion   Lite 4
         */
        const std::string SecurityPanel::MICROPHONE="microphone";

        /**
         * When passed to Security.showSettings(), displays the
         * Camera panel in Flash Player Settings.
         * @langversion 3.0
         * @playerversion   Flash 9
         * @playerversion   Lite 4
         */
        const std::string SecurityPanel::CAMERA="camera";

        /**
         * When passed to Security.showSettings(), displays the
         * Display panel in Flash Player Settings.
         * @langversion 3.0
         * @playerversion   Flash 9
         * @playerversion   Lite 4
         */
        const std::string SecurityPanel::DISPLAY="display";

        /**
         * When passed to Security.showSettings(), displays the
         * Settings Manager (in a separate browser window).
         * @langversion 3.0
         * @playerversion   Flash 9
         * @playerversion   Lite 4
         */
        const std::string SecurityPanel::SETTINGS_MANAGER="settingsManager";

        SecurityPanel::SecurityPanel();
}
}

