

#include "Accessibility.h"
#include "flash/display/DisplayObject.h"

    /**
     * The Accessibility class manages communication with screen readers. Screen readers are a 
     * type of assistive technology for visually impaired users that provides an audio version of 
     * screen content. The methods of the Accessibility class are static   that is, you don't 
     * have to create an instance of the class to use its methods.
     * 
     *   <p class="- topic/p "><b class="+ topic/ph hi-d/b ">Mobile Browser Support:</b> This class is not supported in mobile browsers.</p><p class="- topic/p "><i class="+ topic/ph hi-d/i ">AIR profile support:</i> This feature is supported on all desktop operating systems, 
     * but is not supported on mobile devices or on AIR for TV devices. See 
     * <xref href="http://help.adobe.com/en_US/air/build/WS144092a96ffef7cc16ddeea2126bb46b82f-8000.html" class="- topic/xref ">
     * AIR Profile Support</xref> for more information regarding API support across multiple profiles.</p><p class="- topic/p ">To get and set accessible properties for a specific object, such as a button, movie 
     * clip, or text field, use the <codeph class="+ topic/ph pr-d/codeph ">DisplayObject.accessibilityProperties</codeph> property. 
     * To determine whether the player or runtime is running in an environment that supports accessibility aids, use 
     * the <codeph class="+ topic/ph pr-d/codeph ">Capabilities.hasAccessibility</codeph> property. </p><p class="- topic/p "><b class="+ topic/ph hi-d/b ">Note:</b> AIR 2 supports the JAWS 11 (or higher) screen reader software. For additional information,
     * please see http://www.adobe.com/accessibility/.</p>
     * 
     *   EXAMPLE:
     * 
     *   The following example uses <codeph class="+ topic/ph pr-d/codeph ">AccessibilityExample</codeph>,
     * <codeph class="+ topic/ph pr-d/codeph ">CustomAccessibleButton</codeph>, <codeph class="+ topic/ph pr-d/codeph ">CustomSimpleButton</codeph>, and 
     * <codeph class="+ topic/ph pr-d/codeph ">ButtonDisplayState</codeph> sample classes to create an accessibility-compliant 
     * menu that works with most screen readers. The example carries out the following tasks:
     * <ol class="- topic/ol "><li class="- topic/li ">It traces the <codeph class="+ topic/ph pr-d/codeph ">Accessibility.active</codeph> property to determine whether a screen
     * reader is currently active and the player is communicating with it.</li><li class="- topic/li ">If the <codeph class="+ topic/ph pr-d/codeph ">active</codeph> property returns <codeph class="+ topic/ph pr-d/codeph ">true</codeph>, the example calls the
     * <codeph class="+ topic/ph pr-d/codeph ">updateProperties()</codeph> method to apply the accessibility changes made to the buttons in 
     * this example.</li><li class="- topic/li ">The example calls the <codeph class="+ topic/ph pr-d/codeph ">flash.utils.setTimeout()</codeph> method, specifying that the <codeph class="+ topic/ph pr-d/codeph ">updateAccessibility()</codeph> closure method
     * should be called after 2 seconds.</li></ol><p class="- topic/p "><b class="+ topic/ph hi-d/b ">Note: </b>Call <codeph class="+ topic/ph pr-d/codeph ">setTimeout()</codeph> before checking <codeph class="+ topic/ph pr-d/codeph ">Accessibility.active</codeph> 
     * to give Flash Player the 2 seconds it needs to connect to a screen reader if one is available. 
     * If you do not supply a sufficient delay time, the <codeph class="+ topic/ph pr-d/codeph ">setTimeout</codeph> call might return <codeph class="+ topic/ph pr-d/codeph ">false</codeph> even if a screen reader is available.
     * </p><p class="- topic/p ">The following example processes the <codeph class="+ topic/ph pr-d/codeph ">Accessibility.updateProperties()</codeph> 
     * method only if the call to <codeph class="+ topic/ph pr-d/codeph ">Accessibility.active</codeph> returns <codeph class="+ topic/ph pr-d/codeph ">true</codeph>, which occurs 
     * only if Flash Player is currently connected to an active screen reader. If <codeph class="+ topic/ph pr-d/codeph ">updateProperties</codeph>
     * is called without an active screen reader, it throws an <codeph class="+ topic/ph pr-d/codeph ">IllegalOperationError</codeph> exception.</p><codeblock xml:space="preserve" class="+ topic/pre pr-d/codeblock ">
     * package {
     * import flash.display.Sprite;
     * import flash.accessibility.Accessibility;
     * import flash.utils.setTimeout;
     * 
     *   public class AccessibilityExample extends Sprite {
     * public static const BUTTON_WIDTH:uint = 90;
     * public static const BUTTON_HEIGHT:uint = 20;
     * 
     *   private var gutter:uint = 5;
     * private var menuLabels:Array = new Array("PROJECTS", "PORTFOLIO", "CONTACT");
     * private var menuDescriptions:Array = new Array("Learn more about our projects"
     * , "See our portfolio"
     * , "Get in touch with our team");
     * 
     *   public function AccessibilityExample() {
     * configureAssets();
     * setTimeout(updateAccessibility, 2000); 
     * }
     * 
     *   private function updateAccessibility():void {
     * trace("Accessibility.active: " + Accessibility.active);
     * if(Accessibility.active) {
     * Accessibility.updateProperties();
     * }
     * }
     * 
     *   private function configureAssets():void {
     * var child:CustomAccessibleButton;
     * for(var i:uint; i &lt; menuLabels.length; i++) {
     * child = new CustomAccessibleButton();
     * child.y = (numChildren * (BUTTON_HEIGHT + gutter));
     * child.setLabel(menuLabels[i]);
     * child.setDescription(menuDescriptions[i]);
     * addChild(child);
     * }
     * }
     * }
     * }
     * 
     *   import flash.accessibility.AccessibilityProperties;
     * import flash.display.Shape;
     * import flash.display.SimpleButton;
     * import flash.display.Sprite;
     * import flash.events.Event;
     * import flash.text.TextFormat;
     * import flash.text.TextField;
     * 
     *   class CustomAccessibleButton extends Sprite {
     * private var button:SimpleButton;
     * private var label:TextField;
     * private var description:String;
     * private var _name:String;
     * 
     *   public function CustomAccessibleButton(_width:uint = 0, _height:uint = 0) {
     * _width = (_width == 0) ? AccessibilityExample.BUTTON_WIDTH : _width;
     * _height = (_height == 0) ? AccessibilityExample.BUTTON_HEIGHT : _height;
     * 
     *   button = buildButton(_width, _height);
     * label = buildLabel(_width, _height);
     * 
     *   addEventListener(Event.ADDED, addedHandler);
     * }
     * 
     *   private function addedHandler(event:Event):void {
     * trace("addedHandler: " + this._name);
     * var accessProps:AccessibilityProperties = new AccessibilityProperties();
     * accessProps.name = this._name;
     * accessProps.description = description;
     * accessibilityProperties = accessProps;
     * removeEventListener(Event.ADDED, addedHandler);
     * }
     * 
     *   private function buildButton(_width:uint, _height:uint):SimpleButton {
     * var child:SimpleButton = new CustomSimpleButton(_width, _height);
     * addChild(child);
     * return child;
     * }
     * 
     *   private function buildLabel(_width:uint, _height:uint):TextField {
     * var format:TextFormat = new TextFormat();
     * format.font = "Verdana";
     * format.size = 11;
     * format.color = 0xFFFFFF;
     * format.align = TextFormatAlign.CENTER;
     * format.bold = true;
     * 
     *   var child:TextField = new TextField();
     * child.y = 1;
     * child.width = _width;
     * child.height = _height;
     * child.selectable = false;
     * child.defaultTextFormat = format;
     * child.mouseEnabled = false;
     * 
     *   addChild(child);
     * return child;
     * }
     * 
     *   public function setLabel(text:String):void {
     * label.text = text;
     * this._name = text;
     * }
     * 
     *   public function setDescription(text:String):void {
     * description = text;
     * }
     * }
     * 
     *   class CustomSimpleButton extends SimpleButton {
     * private var upColor:uint = 0xFFCC00;
     * private var overColor:uint = 0xCCFF00;
     * private var downColor:uint = 0x00CCFF;
     * 
     *   public function CustomSimpleButton(_width:uint, _height:uint) {
     * downState = new ButtonDisplayState(downColor, _width, _height);
     * overState = new ButtonDisplayState(overColor, _width, _height);
     * upState = new ButtonDisplayState(upColor, _width, _height);
     * hitTestState = new ButtonDisplayState(upColor, _width, _height);
     * useHandCursor = true;
     * }        
     * }
     * 
     *   class ButtonDisplayState extends Shape {
     * private var bgColor:uint;
     * private var _width:uint;
     * private var _height:uint;
     * 
     *   public function ButtonDisplayState(bgColor:uint, _width:uint, _height:uint) {
     * this.bgColor = bgColor;
     * this._width = _width;
     * this._height = _height;
     * draw();
     * }
     * 
     *   private function draw():void {
     * graphics.beginFill(bgColor);
     * graphics.drawRect(0, 0, _width, _height);
     * graphics.endFill();
     * }
     * }
     * </codeblock>
     * @langversion 3.0
     * @playerversion   Flash 9
     */

using namespace flash::display;

namespace flash {
namespace accessibility {


        /**
         * Indicates whether a screen reader is active and the application is 
         * communicating with it. Use this method when you want your application to behave 
         * differently in the presence of a screen reader.
         * 
         *   Once this property is set to true, it remains true for the duration 
         * of the application. (It is unusual for a user to turn off the screen reader once it is
         * started.)Note: Before calling this method, wait 1 or 2 seconds after launching your 
         * AIR application or after the first appearance of the Flash   Player window in which 
         * your document is playing. Otherwise, you might get a return value of false
         * even if there is an active accessibility client. This happens because of an asynchronous 
         * communication mechanism between accessibility clients and Flash Player or AIR.
         * 
         *   To determine whether the player is running in an environment that supports screen readers, use the  
         * Capabilities.hasAccessibility property.
         * @langversion 3.0
         * @playerversion   Flash 9
         */
        bool Accessibility::active()          ;

        Accessibility::Accessibility();

        void Accessibility::sendEvent(DisplayObject* source, unsigned int childID, unsigned int eventType, bool nonHTML)       ;

        /**
         * Tells Flash Player to apply any accessibility changes made by using the DisplayObject.accessibilityProperties property.  
         * You need to call this method for your changes to take effect.
         * 
         *   If you modify the accessibility properties for multiple objects, only one call to the
         * Accessibility.updateProperties() method is necessary; multiple calls can result in
         * reduced performance and erroneous screen reader output.
         * @langversion 3.0
         * @playerversion   Flash 9
         * @throws  IllegalOperationError Accessibility is not supported in this version of
         *   Flash Player. Do not call the Accessibility.updateProperties() method 
         *   if the flash.system.Capabilities.hasAccessibility property is false.
         */
        void Accessibility::updateProperties()       ;
}
}

