#if !defined(FLEX11_6_FLASH_TEXT_TEXTLINEMETRICS_AS)
#define FLEX11_6_FLASH_TEXT_TEXTLINEMETRICS_AS
#if defined(__cplusplus)


/**
 * The TextLineMetrics class contains information about the text position and measurements of a
 * <i class="+ topic/ph hi-d/i ">line of text</i> within a text field. All measurements are in pixels. Objects of this class are returned by the
 * <codeph class="+ topic/ph pr-d/codeph ">flash.text.TextField.getLineMetrics()</codeph> method.
 * <p class="- topic/p ">For measurements related to the text field containing the line of text (for example, the "Text Field height" measurement in the diagram), see flash.text.TextField. </p><p class="- topic/p ">The following diagram indicates the points and measurements of a text field and the line of text the field contains:</p><p class="- topic/p "><adobeimage alt="An image illustrating text metrics" href="../../images/text-metrics.jpg" placement="inline" class="+ topic/image adobe-d/adobeimage " /></p>
 *
 *   EXAMPLE:
 *
 *   The following example creates the classes TextLineMetricsExample and
 * LineMetricsReader to print out a message in the Flash Player via an XML object.  This
 * is accomplished using the following steps:
 * <ol class="- topic/ol "><li class="- topic/li ">Create a property called <codeph class="+ topic/ph pr-d/codeph ">label</codeph> of type TextField.</li><li class="- topic/li ">The constructor calls <codeph class="+ topic/ph pr-d/codeph ">configureAssets()</codeph>, which does the following:
 * <ul class="- topic/ul "><li class="- topic/li ">Sets the stage's alignment to top-left and no scale.</li><li class="- topic/li ">Creates a new TextField object named <codeph class="+ topic/ph pr-d/codeph ">label</codeph>.</li><li class="- topic/li ">Enables <codeph class="+ topic/ph pr-d/codeph ">label</codeph>'s background and sets the color to white.</li><li class="- topic/li ">Allows <codeph class="+ topic/ph pr-d/codeph ">label</codeph>'s text to span multiple lines with automatic word wrapping.</li><li class="- topic/li ">Assigns the result of a call to <codeph class="+ topic/ph pr-d/codeph ">getLabelText()</codeph> to the <codeph class="+ topic/ph pr-d/codeph ">text</codeph> property
 * of <codeph class="+ topic/ph pr-d/codeph ">label</codeph>.  The <codeph class="+ topic/ph pr-d/codeph ">getLabelText()</codeph> method creates a variable of type XML and assigns
 * it to an XML node named <codeph class="+ topic/ph pr-d/codeph ">body</codeph>, which is populated with a long sentence.</li><li class="- topic/li ">Adds <codeph class="+ topic/ph pr-d/codeph ">label</codeph> to the display list using <codeph class="+ topic/ph pr-d/codeph ">addChild()</codeph>.</li></ul></li><li class="- topic/li ">A method that listens for <codeph class="+ topic/ph pr-d/codeph ">resize</codeph> events performed on the stage is then added called
 * <codeph class="+ topic/ph pr-d/codeph ">resizeHandler()</codeph>.  Every time the Flash Player window size is changed, a <codeph class="+ topic/ph pr-d/codeph ">RESIZE</codeph>
 * event is dispatched and the following happens:
 * <ul class="- topic/ul "><li class="- topic/li "><codeph class="+ topic/ph pr-d/codeph ">draw()</codeph> is called to ensure that <codeph class="+ topic/ph pr-d/codeph ">label</codeph> appears in the center of the
 * stage and surrounded by a 10-pixel buffer.</li><li class="- topic/li "><codeph class="+ topic/ph pr-d/codeph ">setTimeout()</codeph> then executes <codeph class="+ topic/ph pr-d/codeph ">showMetrics()</codeph> after a short delay.  The
 * delay is added because the line metrics are not updated until after the <codeph class="+ topic/ph pr-d/codeph ">RESIZE</codeph> event has
 * completed and the stage has fully re-drawn.</li><li class="- topic/li "><codeph class="+ topic/ph pr-d/codeph ">showMetrics()</codeph> assigns a TextLineMetrics variable named <codeph class="+ topic/ph pr-d/codeph ">metrics</codeph> to
 * the result of a call to <codeph class="+ topic/ph pr-d/codeph ">getLineMetrics()</codeph> and this variable is then passed to
 * a new instance of a LineMetricsReader instance named <codeph class="+ topic/ph pr-d/codeph ">reader</codeph>.  The two
 * variables are then used within calls to <codeph class="+ topic/ph pr-d/codeph ">trace()</codeph> to print out the first (and only)
 * line of <codeph class="+ topic/ph pr-d/codeph ">label</codeph> and information provided by the LineMetricsReader instance through its
 * <codeph class="+ topic/ph pr-d/codeph ">toString()</codeph> method.</li></ul></li><li class="- topic/li ">The constructor forces a single dispatch of the <codeph class="+ topic/ph pr-d/codeph ">resize</codeph> event to force
 * <codeph class="+ topic/ph pr-d/codeph ">label</codeph> to be drawn correctly when the SWF file is first loaded.</li></ol><codeblock xml:space="preserve" class="+ topic/pre pr-d/codeblock ">
 * package {
 * import flash.display.Sprite;
 * import flash.display.StageAlign;
 * import flash.display.StageScaleMode;
 * import flash.events.*;
 * import flash.text.TextField;
 * import flash.text.TextLineMetrics;
 * import flash.utils.setTimeout;
 *
 *   public class TextLineMetricsExample extends Sprite {
 * private var gutter:int = 10;
 * private var label:TextField;
 *
 *   public function TextLineMetricsExample() {
 * configureAssets();
 * configureListeners();
 * resizeHandler(new Event(Event.RESIZE));
 * }
 *
 *   private function showMetrics():void {
 * var metrics:TextLineMetrics = label.getLineMetrics(0);
 * var reader:LineMetricsReader = new LineMetricsReader(metrics);
 * trace("lineText: " + label.getLineText(0));
 * trace("metrics: " + reader);
 * }
 *
 *   private function configureAssets():void {
 * stage.align = StageAlign.TOP_LEFT;
 * stage.scaleMode = StageScaleMode.NO_SCALE;
 *
 *   label = new TextField();
 * label.background = true;
 * label.backgroundColor = 0xFFFFFF;
 * label.multiline = true;
 * label.wordWrap = true;
 * label.text = getLabelText();
 * addChild(label);
 * }
 *
 *   private function configureListeners():void {
 * stage.addEventListener(Event.RESIZE, resizeHandler);
 * }
 *
 *   private function resizeHandler(event:Event):void {
 * draw();
 * setTimeout(showMetrics, 100);
 * }
 *
 *   private function draw():void {
 * label.x = gutter;
 * label.y = gutter;
 * label.width = stage.stageWidth - (gutter * 2);
 * label.height = stage.stageHeight - (gutter * 2);
 * }
 *
 *   private function getLabelText():String {
 * var text:XML = &lt;body&gt;The Flex product line enables developers to build rich Internet applications that blend the responsiveness of desktop software, the cross-platform reach of the web, and the expressiveness of the Flash Platform.&lt;/body&gt;
 * return text.toString();
 * }
 * }
 * }
 *
 *   import flash.text.TextLineMetrics;
 *
 *   class LineMetricsReader {
 * private var metrics:TextLineMetrics;
 *
 *   public function LineMetricsReader(metrics:TextLineMetrics) {
 * this.metrics = metrics;
 * }
 *
 *   public function toString():String {
 * return "[TextLineMetrics ascent:" + metrics.ascent
 * + ", descent:" + metrics.descent
 * + ", leading:" + metrics.leading
 * + ", width:" + metrics.width
 * + ", height:" + metrics.height
 * + ", x:" + metrics.x
 * + "]";
 * }
 * }
 * </codeblock>
 * @langversion 3.0
 * @playerversion   Flash 9
 * @playerversion   Lite 4
 */

namespace flash
{
    namespace text
    {
        class TextLineMetrics: public Object
        {
            /**
             * The x value is the left position of the first character in pixels. This value includes the margin,
             * indent (if any), and gutter widths. See the "Text Line x-position" in the overview diagram for this class.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            float x;

            /**
             * The width value is the width of the text of the selected lines (not necessarily the complete text) in pixels. The width of the
             * text line is not the same as the width of the text field. The width of the text line is relative to the
             * text field width, minus the gutter width of 4 pixels (2 pixels on each side). See the "Text Line width"
             * measurement in the overview diagram for this class.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            float width;

            /**
             * The height value of the text of the selected lines (not necessarily the complete text) in pixels. The height of the
             * text line does not include the gutter height. See the "Line height" measurement in the overview diagram
             * for this class.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            float height;

            /**
             * The ascent value of the text is the length from the baseline to the top of the line height in pixels. See the
             * "Ascent" measurement in the overview diagram for this class.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             * @internal    including accents? is it really the line or the font itself?
             */
        public:
            float ascent;

            /**
             * The descent value of the text is the length from the baseline to the bottom depth of the line in pixels.
             * See the "Descent" measurement in the overview diagram for this class.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             * @internal    is it really the line? or the font itself?
             */
        public:
            float descent;

            /**
             * The leading value is the measurement of the vertical distance between the lines of text.
             * See the "Leading" measurement in the overview diagram for this class.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            float leading;

            /**
             * Creates a TextLineMetrics object.  The TextLineMetrics object contains information about
             * the text metrics of a line of text in a text field.  Objects of this class are returned by the
             * flash.text.TextField.getLineMetrics() method.
             * See the diagram in the overview for this class for the properties in context.
             * @param   x   The left position of the first character in pixels.
             * @param   width   The width of the text of the selected lines (not necessarily the complete text) in pixels.
             * @param   height  The height of the text of the selected lines (not necessarily the complete text) in pixels.
             * @param   ascent  The length from the baseline to the top of the line height in pixels.
             * @param   descent The length from the baseline to the bottom depth of the line in pixels.
             * @param   leading The measurement of the vertical distance between the lines of text.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            TextLineMetrics(float x, float width, float height, float ascent, float descent, float leading);
        };
    }
}

#endif // FLEX11_6_FLASH_TEXT_TEXTLINEMETRICS_AS
#endif // __cplusplus

