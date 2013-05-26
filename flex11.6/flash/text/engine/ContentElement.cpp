

#include "ContentElement.h"
#include "flash/text/engine/TextBlock.h"
#include "flash/text/engine/ElementFormat.h"
#include "flash/events/EventDispatcher.h"
#include "flash/text/engine/GroupElement.h"

    /**
     * The ContentElement class serves as a base class for the element types that can appear in a GroupElement, namely a GraphicElement, 
     * another GroupElement, or a TextElement.
     * 
     *   <p class="- topic/p ">ContentElement is an abstract base class; therefore, you cannot instantiate ContentElement directly. 
     * Invoking <codeph class="+ topic/ph pr-d/codeph ">new ContentElement()</codeph> throws an <codeph class="+ topic/ph pr-d/codeph ">ArgumentError</codeph> exception. </p><p class="- topic/p ">You can assign a ContentElement element to exactly one <codeph class="+ topic/ph pr-d/codeph ">GroupElement</codeph> or to the <codeph class="+ topic/ph pr-d/codeph ">content</codeph> property of exactly one text 
     * block.</p>
     * @langversion 3.0
     * @playerversion   Flash 10
     * @playerversion   AIR 1.5
     * @playerversion   Lite 4
     */

using namespace flash::events;
using namespace flash::text::engine;

namespace flash {
namespace text {
namespace engine {


        /**
         * Indicates the presence of a graphic element in the text.
         * @langversion 3.0
         * @playerversion   Flash 10
         * @playerversion   AIR 1.5
         * @playerversion   Lite 4
         */
        const unsigned int ContentElement::GRAPHIC_ELEMENT   = 0xFDEF;

        /**
         * Provides a way for an application to associate arbitrary data with the element.
         * 
         *   The default value is null.
         * @langversion 3.0
         * @playerversion   Flash 10
         * @playerversion   AIR 1.5
         * @playerversion   Lite 4
         */
                   

        /**
         * The TextBlock to which this element belongs.
         * 
         *   The default value is null.
         * @langversion 3.0
         * @playerversion   Flash 10
         * @playerversion   AIR 1.5
         * @playerversion   Lite 4
         */
        flash::text::engine::TextBlock* ContentElement::textBlock()                              ;

        /**
         * The index in the text block of the first character of this element.
         * This value is not cached; it is calculated whenever this method is called.
         * 
         *   The default value is -1.
         * @langversion 3.0
         * @playerversion   Flash 10
         * @playerversion   AIR 1.5
         * @playerversion   Lite 4
         */
        int ContentElement::textBlockBeginIndex()      ;

        /**
         * The ElementFormat object used for the element.
         * 
         *   The default value is null.When the elementFormat property is set, the ElementFormat object provided is locked:  its locked
         * property is set to true.  A locked ElementFormat cannot be modified.
         * @langversion 3.0
         * @playerversion   Flash 10
         * @playerversion   AIR 1.5
         * @playerversion   Lite 4
         */
        flash::text::engine::ElementFormat* ContentElement::elementFormat()                                  ;
        void ContentElement::elementFormat(ElementFormat* value)       ;

        /**
         * The EventDispatcher object that receives copies of every
         * event dispatched to valid text lines based on this content element.
         * The specified object can be used to set up listeners for a text link or other 
         * interactive piece of text, as it can be difficult to determine at runtime which parts
         * of lines have resulted from particular content elements.
         * You can also use listeners to apply decorations such as underlines, the metrics of which
         * you cannot determine until after the text is laid out.
         * The default value is null, which means no mirrored events are dispatched.
         * 
         *   Event mirrors manifest themselves in text lines as instances of the TextLineMirrorRegion
         * class. Depending on bidirectional processing and line breaking, one or more mirror regions can be produced.The default value is null.
         * @langversion 3.0
         * @playerversion   Flash 10
         * @playerversion   AIR 1.5
         * @playerversion   Lite 4
         */
        flash::events::EventDispatcher* ContentElement::eventMirror()                               ;
        void ContentElement::eventMirror(EventDispatcher* value)       ;

        /**
         * The GroupElement object that contains this element, or
         * null if it is not in a group.
         * 
         *   The default value is null.
         * @langversion 3.0
         * @playerversion   Flash 10
         * @playerversion   AIR 1.5
         * @playerversion   Lite 4
         */
        flash::text::engine::GroupElement* ContentElement::groupElement()                                 ;

        /**
         * A copy of the text in the element, including any U+FDEF characters. The Unicode character, U+FDEF, marks the location of
         * a graphic element in the String.
         * @langversion 3.0
         * @playerversion   Flash 10
         * @playerversion   AIR 1.5
         * @playerversion   Lite 4
         */
        std::string ContentElement::rawText()         ;

        /**
         * A copy of the text in the element, not including any U+FDEF characters, which represent graphic elements in the String.
         * @langversion 3.0
         * @playerversion   Flash 10
         * @playerversion   AIR 1.5
         * @playerversion   Lite 4
         */
        std::string ContentElement::text()         ;

        /**
         * The rotation to apply to the element as a unit. Use TextRotation
         * constants for this property.
         * 
         *   The default value is TextRotation.ROTATE_0.The final rotation of any glyph is the sum of ElementFormat.textRotation, ContentElement.textRotation, and TextBlock.lineRotation.ContentElement.textRotation is used to create a short run of text whose
         * rotation differs from the containing line.  TCY runs in Japanese text are an example. TCY stands for Tate-Chu-Yoko
         * and refers to a little horizontal run of text (usually a number) in some vertical Japanese text.
         * To create a Paragraph of vertical Japanese text containing a TCY run, do the following:Set TextBlock.lineRotation=TextRotation.ROTATE_90Set TextBlock.content to a GroupElement, consisting of three TextElement objects.
         * The first of these elements is the Japanese text before the TCY run, the second is the Latin text of the TCY run, and the third is 
         * the Japanese text after the TCY run.Set the textRotation property of the TCY TextElement to TextRotation.ROTATE_270.
         * The TCY text element rotates as a unit.  It starts with a 90 degree rotation inherited
         * from the line.  Adding another 270 degrees takes it around to horizontal.Rotated content elements cannot be nested.  In any hierarchy of content elements, no matter how complex,
         * only one content element can have its textRotation property set.  The following methods and property setters throw an 
         * argument error if nested rotations are detected:ContentElement.textRotationGroupElement.setElementsGroupElement.replaceElementsTo set values for this property, use the following string values:String valueDescriptionTextRotation.ROTATE_0Element is not rotated.TextRotation.ROTATE_90Element is rotated 90 degrees clockwise.TextRotation.ROTATE_180Element is rotated 180 degrees.TextRotation.ROTATE_270Element is rotated 270 degrees clockwise.TextRotation.AUTONot supported.
         * @langversion 3.0
         * @playerversion   Flash 10
         * @playerversion   AIR 1.5
         * @playerversion   Lite 4
         * @throws  ArgumentError If set to any value that is not a member of TextRotation.
         * @throws  ArgumentError If set to TextRotation.AUTO.
         * @throws  ArgumentError If the operation would result in nested rotations within a GroupElement.
         */
        std::string ContentElement::textRotation()         ;
        void ContentElement::textRotation(std::string value)       ;

        /**
         * Calling the new ContentElement() constructor throws an 
         * ArgumentError exception. You can, however, call constructors for 
         * the following subclasses of ContentElement:
         * 
         *   new GraphicElement()new GroupElement()new TextElement()
         * @param   elementFormat   The element format for the text in the element.  The default value is null.
         * @param   eventMirror The EventDispatcher object that receives copies of every
         *   event dispatched to valid text lines created based on this content element.  The default value is null.
         * @param   textRotation    The rotation applied the element as a unit. Use TextRotation
         *   constants for this property.  The default value is TextRotation.ROTATE_0.
         * @langversion 3.0
         * @playerversion   Flash 10
         * @playerversion   AIR 1.5
         * @playerversion   Lite 4
         */
        ContentElement::ContentElement(ElementFormat* elementFormat, EventDispatcher* eventMirror, std::string textRotation);
}
}
}

