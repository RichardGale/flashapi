

#include "GraphicElement.h"
#include "flash/display/DisplayObject.h"
#include "flash/text/engine/ElementFormat.h"
#include "flash/events/EventDispatcher.h"

    /**
     * The GraphicElement class represents a graphic element in a TextBlock or GroupElement object. Assign a GraphicElement object to the 
     * <codeph class="+ topic/ph pr-d/codeph ">content</codeph> property of a TextBlock object to display a graphic or an image with <codeph class="+ topic/ph pr-d/codeph ">TextBlock.createTextLine()</codeph>.  
     * Assign it to a GroupElement object to combine it with other graphic and text elements.
     * 
     *   EXAMPLE:
     * 
     *   The following example creates a TextBlock with a GraphicElement (a red box) and
     * displays it, adding a second TextBlock beneath it that contains a caption.
     * <codeblock xml:space="preserve" class="+ topic/pre pr-d/codeblock ">
     * 
     *   package {
     * 
     *   import flash.display.Sprite;
     * import flash.display.MovieClip;
     * import flash.text.engine.TextBlock;
     * import flash.text.engine.TextElement;
     * import flash.text.engine.GraphicElement;
     * import flash.text.engine.TextLine;
     * import flash.text.engine.ElementFormat;
     * import flash.text.engine.FontDescription;
     * 
     *   public class GraphicElementExample extends Sprite {
     * 
     *   public function GraphicElementExample():void {
     * 
     *   var format:ElementFormat = new ElementFormat();
     * format.fontSize = 14;
     * var redBox:MovieClip = new MovieClip();
     * redBox.graphics.beginFill(0xCC0000, 1.0);
     * redBox.graphics.drawRect(0,0, 200, 200);
     * redBox.graphics.endFill();   
     * var graphicElement:GraphicElement = new GraphicElement(redBox,redBox.width,redBox.height, format);
     * var textBlock:TextBlock = new TextBlock();
     * textBlock.content = graphicElement;
     * var textLine1:TextLine = textBlock.createTextLine(null,redBox.width);
     * addChild(textLine1);
     * textLine1.x = 15
     * textLine1.y = 215
     * var str:String = "Your picture here ...";
     * var textElement:TextElement = new TextElement(str, format);
     * textBlock = new TextBlock();
     * textBlock.content = textElement;
     * var textLine2 = textBlock.createTextLine(null, 300);
     * addChild(textLine2);
     * textLine2.x = textLine1.x;
     * textLine2.y += textLine1.y + format.fontSize;        
     * }
     * }    
     * }
     * </codeblock>
     * @langversion 3.0
     * @playerversion   Flash 10
     * @playerversion   AIR 1.5
     * @playerversion   Lite 4
     */

using namespace flash::display;
using namespace flash::events;
using namespace flash::text::engine;

namespace flash {
namespace text {
namespace engine {


        /**
         * The DisplayObject to be used as a graphic for the GraphicElement.
         * 
         *   The default value is null.When the GraphicElement becomes part of a text line, the graphic
         * is added as a child of the line.  Setting the graphic removes
         * the old graphic from the line and adds the new one.
         * @langversion 3.0
         * @playerversion   Flash 10
         * @playerversion   AIR 1.5
         * @playerversion   Lite 4
         */
        flash::display::DisplayObject* GraphicElement::graphic()                              ;
        void GraphicElement::graphic(DisplayObject* value)       ;

        /**
         * The height in pixels to reserve for the graphic in the line.  
         * It is the responsibility of the caller to scale the graphic.
         * 
         *   The default value is 15.0.
         * @langversion 3.0
         * @playerversion   Flash 10
         * @playerversion   AIR 1.5
         * @playerversion   Lite 4
         */
        float GraphicElement::elementHeight()         ;
        void GraphicElement::elementHeight(float value)       ;

        /**
         * The width in pixels to reserve for the graphic in the line.  
         * It is the responsibility of the caller to scale the graphic.
         * 
         *   The default value is 15.0.
         * @langversion 3.0
         * @playerversion   Flash 10
         * @playerversion   AIR 1.5
         * @playerversion   Lite 4
         */
        float GraphicElement::elementWidth()         ;
        void GraphicElement::elementWidth(float value)       ;

        /**
         * Creates a new GraphicElement instance.
         * 
         *   The registration point of the graphic aligns with the upper-left corner
         * of the region defined by elementHeight, elementWidth
         * and elementFormat.baselineShift.  The graphic is not scaled to match the size of the region.
         * If the GraphicElement has an eventMirror, the elementWidth and elementHeight
         * properties, and not the graphic, determine the size and position of the resulting mirror region.  If a loader
         * is used, the graphic might not be loaded at the time the text line and the mirror regions are created.
         * @param   graphic The DisplayObject to populate the GraphicElement.  The default value is null.
         * @param   elementWidth    The width of the area reserved for the element in pixels.  The default value is 15.
         * @param   elementHeight   The height of the area reserved for the element in pixels.  The default value is 15.
         * @param   elementFormat   The element format for the element.  The default value is null.
         * @param   eventMirror The EventDispatcher object that receives copies of every
         *   event dispatched to text lines created based on this content element.  The default value is null.
         * @param   textRotation    The rotation applied to the element as a unit. Use flash.text.engine.TextRotation
         *   constants for this property.  The default value is flash.text.engine.TextRotation.ROTATE_0.
         * @langversion 3.0
         * @playerversion   Flash 10
         * @playerversion   AIR 1.5
         * @playerversion   Lite 4
         */
        GraphicElement::GraphicElement(DisplayObject* graphic, float elementWidth, float elementHeight, ElementFormat* elementFormat, EventDispatcher* eventMirror, std::string textRotation);
}
}
}

