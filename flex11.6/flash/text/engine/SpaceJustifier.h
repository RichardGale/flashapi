#if !defined(FLEX11_6_FLASH_TEXT_ENGINE_SPACEJUSTIFIER_AS)
#define FLEX11_6_FLASH_TEXT_ENGINE_SPACEJUSTIFIER_AS
#if defined(__cplusplus)


#include "flash/text/engine/TextJustifier.h"


/**
 * The SpaceJustifier class represents properties that control the justification options for text lines in a text block.
 *
 *   <p class="- topic/p "> Use the constructor <codeph class="+ topic/ph pr-d/codeph ">new SpaceJustifier()</codeph> to create a SpaceJustifier object before setting its properties.
 * Setting the properties of a SpaceJustifier object after you apply it to a TextBlock does not invalidate the TextBlock.</p>
 *
 *   EXAMPLE:
 *
 *   The following example uses letter spacing and justifies all of a block of text
 * except for the last line.
 * <codeblock xml:space="preserve" class="+ topic/pre pr-d/codeblock ">
 *
 *   package {
 * import flash.display.Sprite;
 * import flash.text.engine.TextBlock;
 * import flash.text.engine.TextElement;
 * import flash.text.engine.TextLine;
 * import flash.text.engine.ElementFormat;
 * import flash.text.engine.SpaceJustifier;
 * import flash.text.engine.LineJustification;
 *
 *   public class SpaceJustifierExample extends Sprite {
 *
 *   public function SpaceJustifierExample():void {
 * var str:String = "Lorem ipsum dolor sit amet, consectetur adipisicing elit, " +
 * "sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut " +
 * "enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut " +
 * "aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit " +
 * "in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur " +
 * "sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt " +
 * "mollit anim id est laborum.";
 *
 *   var format:ElementFormat = new ElementFormat(null, 12, 0xCC0000);
 * var textElement:TextElement = new TextElement(str, format);
 * var spaceJustifier:SpaceJustifier = new SpaceJustifier("en", LineJustification.ALL_BUT_LAST);
 * spaceJustifier.letterSpacing = true;
 * var textBlock:TextBlock = new TextBlock();
 * textBlock.content = textElement;
 * textBlock.textJustifier = spaceJustifier;
 * createLines(textBlock);
 * }
 *
 *   private function createLines(textBlock:TextBlock):void {
 *
 *   var yPos = 20;
 * var textLine:TextLine = textBlock.createTextLine (null, 150);
 *
 *   while (textLine)
 * {
 * addChild(textLine);
 * textLine.x = 15;
 * yPos += textLine.textHeight+2;
 * textLine.y = yPos;
 * textLine = textBlock.createTextLine(textLine, 150);
 * }
 * }
 * }
 * }
 * </codeblock>
 * @langversion 3.0
 * @playerversion   Flash 10
 * @playerversion   AIR 1.5
 * @playerversion   Lite 4
 */
using namespace flash::text::engine;

namespace flash
{
    namespace text
    {
        namespace engine
        {
            class SpaceJustifier: public TextJustifier
            {
                /**
                 * Specifies whether to use letter spacing during justification.
                 *
                 *   The default value is false
                 * @langversion 3.0
                 * @playerversion   Flash 10
                 * @playerversion   AIR 1.5
                 * @playerversion   Lite 4
                 */
            public:
                bool         letterSpacing();
            public:
                void         letterSpacing(bool value);

                /**
                 * Specifies the minimum spacing (as a multiplier of the width of a normal space) between words to use during justification.
                 *
                 *   The default value is 0.5
                 * @langversion 3.0
                 * @playerversion   Flash 10.1
                 * @playerversion   AIR 2
                 * @throws  ArgumentError The value specified is less than zero or greater than optimumSpacing.
                 */
            public:
                float        minimumSpacing();
            public:
                void         minimumSpacing(float value);

                /**
                 * Specifies the optimum spacing (as a multiplier of the width of a normal space) between words to use during justification.
                 *
                 *   The default value is 1.0
                 * @langversion 3.0
                 * @playerversion   Flash 10.1
                 * @playerversion   AIR 2
                 * @throws  ArgumentError The value specified is less than minimumSpacing or greater than maximumSpacing.
                 */
            public:
                float        optimumSpacing();
            public:
                void         optimumSpacing(float value);

                /**
                 * Specifies the maximum spacing (as a multiplier of the width of a normal space) between words to use during justification.
                 * If letterSpacing is true, letter spacing will be used after the spaces between words reach the maximum.
                 * If letterSpacing is false, the spaces between words will be expanded beyond the maximum.
                 *
                 *   The default value is 1.5
                 * @langversion 3.0
                 * @playerversion   Flash 10.1
                 * @playerversion   AIR 2
                 * @throws  ArgumentError The value specified is less than optimumSpacing.
                 */
            public:
                float        maximumSpacing();
            public:
                void         maximumSpacing(float value);

                /**
                 * Constructs a cloned copy of the SpaceJustifier.
                 * @return  A copy of the SpaceJustifier object.
                 * @langversion 3.0
                 * @playerversion   Flash 10
                 * @playerversion   AIR 1.5
                 * @playerversion   Lite 4
                 * @internal    This class is currently stored as a live reference, but there is no way to track when its
                 *   properties change.  This means that when changes are made, text blocks are not invalidated, which in
                 *   the current implementation can lead to player crashes.  Even from the API perspective its wrong, as
                 *   the affected text lines should be marked INVALID when format changes are made, but they   re not. The
                 *   solution is to use a copy-on-set model.  When the object is passed in, the player copies it, so later
                 *   changes to the object that was passed in have no effect. The setter makes an internal copy of the
                 *   array; the getter returns a copy of the internal copy. Operations like
                 *   myBlock.textJustifier.spaceJustifier.letterSpacing = true will have no effect. Users who subclass
                 *   this class in the future will need to use the clone() method to implement this technique of
                 *   'locking' the format once it has been set.
                 */
            public:
                flash::text::engine::TextJustifier *clone();

                /**
                 * Creates a SpaceJustifier object. The LineJustification class contains constants for specifying the types of
                 * line justification that you can apply.
                 * @param   locale  The locale to determine the justification rules.
                 *   The default value is "en".
                 * @param   lineJustification   The type of line justification for the paragraph.
                 *   Use LineJustification constants for this property.
                 *   The default value is LineJustification.UNJUSTIFIED.
                 * @param   letterSpacing   Specifies whether to use letter spacing during justification.
                 *   The default value is false.
                 * @langversion 3.0
                 * @playerversion   Flash 10
                 * @playerversion   AIR 1.5
                 * @playerversion   Lite 4
                 * @internal
                 * @throws  ArgumentError The locale specified is null or too short to represent a valid locale.
                 * @throws  ArgumentError The lineJustification specified is not a member of LineJustification.
                 */
            public:
                SpaceJustifier(std::string locale, std::string lineJustification, bool letterSpacing);
            };
        }
    }
}

#endif // FLEX11_6_FLASH_TEXT_ENGINE_SPACEJUSTIFIER_AS
#endif // __cplusplus

