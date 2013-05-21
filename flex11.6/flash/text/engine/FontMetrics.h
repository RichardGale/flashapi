#if !defined(FLEX11_6_FLASH_TEXT_ENGINE_FONTMETRICS_AS)
#define FLEX11_6_FLASH_TEXT_ENGINE_FONTMETRICS_AS
#if defined(__cplusplus)


#include "flex11.6.h"
namespace flash
{
    namespace geom
    {
        class Rectangle;
    }
}

/**
 * The FontMetrics class contains measurement and offset information about a font.
 * The <codeph class="+ topic/ph pr-d/codeph ">ElementFormat.getFontMetrics()</codeph> method returns objects of this class.
 * @langversion 3.0
 * @playerversion   Flash 10
 * @playerversion   AIR 1.5
 * @playerversion   Lite 4
 */

using namespace flash::geom;

namespace flash
{
    namespace text
    {
        namespace engine
        {
            class FontMetrics : public Object
            {
                /**
                 * The emBox value represents the design space of the font and is used to place Chinese,
                 * Korean, or Japanese glyphs relative to the Roman baseline.
                 * Typically a square, sized to the point size of the font. The origin (coordinate 0,0)
                 * of the emBox is set to the left edge and Roman baseline of the rect.
                 * For example, for a 10-point font, the emBox can be a rect [L,T,R,B] of [0, -8.8, 10, 1.2].
                 * @langversion 3.0
                 * @playerversion   Flash 10
                 * @playerversion   AIR 1.5
                 * @playerversion   Lite 4
                 */
            public:
                flash::geom::Rectangle *emBox;

                /**
                 * The strikethroughOffset value is the suggested vertical offset from the Roman baseline for a strikethrough.
                 *
                 *   Note that depending on the rotation of the line, this value is either added or subtracted from the
                 * position of the line to find the position for the strikethrough.  In a line with TextRotation.ROTATE_0,
                 * strikethrough.y = line.y + strikethroughOffset.  In a line
                 * with TextRotation.ROTATE_90, strikethrough.x = line.x - strikethroughOffset.When applying decorations such as strikethroughs to a TextLine, the recommended procedure is to specify
                 * an eventMirror on the ContentElement which is to receive the decoration.
                 * In response to the Event.ADDED event, the bounds of the
                 * TextLineMirrorRegion can be used in conjunction
                 * with the strikethroughOffset to place the strikethrough.
                 * @langversion 3.0
                 * @playerversion   Flash 10
                 * @playerversion   AIR 1.5
                 * @playerversion   Lite 4
                 */
            public:
                float strikethroughOffset;

                /**
                 * The strikethroughThickness value is the suggested thickness for a strikethrough.
                 * @langversion 3.0
                 * @playerversion   Flash 10
                 * @playerversion   AIR 1.5
                 * @playerversion   Lite 4
                 */
            public:
                float strikethroughThickness;

                /**
                 * The underlineOffset value is the suggested vertical offset from the Roman baseline for an underline.
                 *
                 *   Note that depending on the rotation of the line, this value is either added or subtracted from the
                 * position of the line to find the position for the underline.  In a line with TextRotation.ROTATE_0,
                 * underline.y = line.y + underlineOffset.  In a line
                 * with TextRotation.ROTATE_90, underline.x = line.x - underlineOffset.When applying decorations such as underlines to a TextLine, the recommended procedure is to specify
                 * an eventMirror on the ContentElement which is to receive the decoration.
                 * In response to the Event.ADDED event, the bounds of the
                 * TextLineMirrorRegion can be used in conjunction
                 * with the underlineOffset to place the underline.
                 * @langversion 3.0
                 * @playerversion   Flash 10
                 * @playerversion   AIR 1.5
                 * @playerversion   Lite 4
                 */
            public:
                float underlineOffset;

                /**
                 * The underlineThickness value is the suggested thickness for an underline.
                 * @langversion 3.0
                 * @playerversion   Flash 10
                 * @playerversion   AIR 1.5
                 * @playerversion   Lite 4
                 */
            public:
                float underlineThickness;

                /**
                 * The subscriptOffset value is the suggested vertical offset from the Roman baseline for a subscript.
                 *
                 *   The subscriptOffset value is used with ElementFormat.baselineShift to position the subscript.
                 * @langversion 3.0
                 * @playerversion   Flash 10
                 * @playerversion   AIR 1.5
                 * @playerversion   Lite 4
                 */
            public:
                float subscriptOffset;

                /**
                 * The subscriptScale value is the suggested scale factor to apply to the point size for a subscript.
                 * A scale factor of 1.0 means no scaling.
                 * @langversion 3.0
                 * @playerversion   Flash 10
                 * @playerversion   AIR 1.5
                 * @playerversion   Lite 4
                 */
            public:
                float subscriptScale;

                /**
                 * The superscriptOffset value is the suggested vertical offset from the Roman baseline for a superscript.
                 *
                 *   The superscriptOffset value is used with ElementFormat.baselineShift to position the superscript.
                 * @langversion 3.0
                 * @playerversion   Flash 10
                 * @playerversion   AIR 1.5
                 * @playerversion   Lite 4
                 */
            public:
                float superscriptOffset;

                /**
                 * The superscriptScale value is the suggested scale factor to apply to the point size for a superscript.
                 * A scale factor of 1.0 means no scaling.
                 * @langversion 3.0
                 * @playerversion   Flash 10
                 * @playerversion   AIR 1.5
                 * @playerversion   Lite 4
                 */
            public:
                float superscriptScale;
            public:
                float lineGap;

                /**
                 * Creates a FontMetrics object.  The FontMetrics object contains information about
                 * the metrics of a font in an element format.
                 * The flash.text.engine.ElementFormat.getFontMetrics() method returns objects of this class.
                 * @param   emBox   The emBox of the font in pixels.
                 * @param   strikethroughOffset The offset for a strikethrough in pixels.
                 * @param   strikethroughThickness  The thickness for a strikethrough in pixels.
                 * @param   underlineOffset The offset for an underline in pixels.
                 * @param   underlineThickness  The thickness for an underline in pixels.
                 * @param   subscriptOffset The offset for a subscript in pixels.
                 * @param   subscriptScale  The scale to apply to the point size of a subscript.
                 * @param   superscriptOffset   The offset for a superscript in pixels.
                 * @param   superscriptScale    The scale to apply to the point size of a superscript.
                 * @langversion 3.0
                 * @playerversion   Flash 10
                 * @playerversion   AIR 1.5
                 * @playerversion   Lite 4
                 */
            public:
                FontMetrics(Rectangle *emBox, float strikethroughOffset, float strikethroughThickness, float underlineOffset, float underlineThickness, float subscriptOffset, float subscriptScale, float superscriptOffset, float superscriptScale, float lineGap =0);
            };
        }
    }
}

#endif // FLEX11_6_FLASH_TEXT_ENGINE_FONTMETRICS_AS
#endif // __cplusplus

