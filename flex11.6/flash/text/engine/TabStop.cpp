

    /**
     * The TabStop class represents the properties of a tab stop in a text block. You assign tab stops as a Vector of TabStop objects
     * to the <codeph class="+ topic/ph pr-d/codeph ">TextBlock.tabStops</codeph> property.
     * 
     *   <p class="- topic/p ">Setting the properties of a TabStop object after you apply it to a TextBlock does not invalidate the TextBlock.</p>
     * 
     *   EXAMPLE:
     * 
     *   This example illustrates the effects of the four tab stop alignment settings - START, 
     * CENTER, DECIMAL, and END.
     * <codeblock xml:space="preserve" class="+ topic/pre pr-d/codeblock ">
     * package {
     * 
     *   import flash.text.engine.*;
     * import flash.display.Sprite;
     * 
     *   public class TabStopExample extends Sprite {
     * 
     *   public function TabStopExample():void {
     * var container:Sprite = new Sprite();
     * 
     *   var english:ElementFormat = new ElementFormat(); 
     * english.fontDescription = new FontDescription("Arial"); 
     * english.fontSize = 16;
     * english.locale = "en";
     * 
     *   var tabStops:Vector.&lt;TabStop&gt; = new Vector.&lt;TabStop&gt;();    
     * tabStops.push(
     * new TabStop(TabAlignment.START, 20),
     * new TabStop(TabAlignment.CENTER, 120),
     * new TabStop(TabAlignment.DECIMAL, 220, "."),
     * new TabStop(TabAlignment.END, 320)
     * );
     * 
     *   var textBlock:TextBlock = new TextBlock();
     * textBlock.content = new TextElement(
     * "\tstart\tcenter\tdeci.mal\tend\n" +        
     * "\tl\tl\t3.4\tl\n" +
     * "\tlm\tlm\t234.56\tlm\n" +
     * "\tlmn\tlmn\t12345678.34567\tlmn\n"
     * , english); 
     * textBlock.tabStops = tabStops;
     * var y:Number = 60;
     * var previousTextLine:TextLine = null; 
     * var textLine:TextLine;
     * var i:int;
     * var tabOrigin:Number = 100;
     * for (i = 0; i &lt; 4; i++) {
     * textLine = textBlock.createTextLine(previousTextLine, 1000, 0); 
     * textLine.x = 20;
     * textLine.y = y;
     * 
     *   container.addChild(textLine);
     * 
     *   y += 25; 
     * previousTextLine = textLine; 
     * }
     * addChild(container);        
     * }
     * }
     * }
     * 
     *   </codeblock>
     * @langversion 3.0
     * @playerversion   Flash 10
     * @playerversion   AIR 1.5
     * @playerversion   Lite 4
     */


namespace flash {
namespace text {
namespace engine {


        /**
         * Specifies the tab alignment for this tab stop. Use the constants in the TabAlignment class to 
         * set this property.
         * 
         *   The default value is TabAlignment.START.Use the lineOffset argument to TextBlock.createTextLine() 
         * to adjust the tabs if the origin of the line does not align with other lines that
         * share the same tab stops.Use the following constants from the TabAlignment class to set the value for this property:String valueDescriptionTabAlignment.STARTThe position property specifies the number of pixels that the start of the tabbed text is from the start of the text line.TabAlignment.CENTERThe position property specifies the number of pixels that the center of the tabbed text is from the start of the text line.TabAlignment.ENDThe position property specifies the number of pixels that the end of the tabbed text is from the start of the text line.TabAlignment.DECIMALThe position property specifies the number of pixels that the alignment token is from the start of the text line.
         * @langversion 3.0
         * @playerversion   Flash 10
         * @playerversion   AIR 1.5
         * @playerversion   Lite 4
         * @throws  ArgumentError If set to any value that is not a member of TabAlignment.
         */
        std::string TabStop::alignment()         ;
        void TabStop::alignment(std::string value)       ;

        /**
         * The position of the tab stop, in pixels, relative to the start of the text line.
         * 
         *   The default value is 0.0.
         * @langversion 3.0
         * @playerversion   Flash 10
         * @playerversion   AIR 1.5
         * @playerversion   Lite 4
         * @throws  ArgumentError If set to a value less than 0.0.
         */
        float TabStop::position()         ;
        void TabStop::position(float value)       ;

        /**
         * Specifies the alignment token to use when you set the alignment property to TabAlignment.DECIMAL. The value
         * is a String that occurs in the text line.
         * 
         *   The default value is "".
         * @langversion 3.0
         * @playerversion   Flash 10
         * @playerversion   AIR 1.5
         * @playerversion   Lite 4
         */
        std::string TabStop::decimalAlignmentToken()         ;
        void TabStop::decimalAlignmentToken(std::string value)       ;

        /**
         * Creates a new TabStop.
         * @param   alignment   The tab alignment type of this tab stop.
         *   Valid values for this property are found in the members of the TabAlignment class.
         *   The default value is TabAlignment.START.
         * @param   position    The position of the tab stop, in pixels.
         *   The default value is 0.0.
         * @param   decimalAlignmentToken   The alignment token to be used if the alignment is TabAlignment.DECIMAL,
         *   The default value is "".
         * @langversion 3.0
         * @playerversion   Flash 10
         * @playerversion   AIR 1.5
         * @playerversion   Lite 4
         * @throws  ArgumentError The alignment specified is not a member of TabAlignment.
         */
        TabStop::TabStop(std::string alignment, float position, std::string decimalAlignmentToken);
}
}
}

