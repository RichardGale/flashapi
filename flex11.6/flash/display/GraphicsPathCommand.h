#if !defined(FLEX11_6_FLASH_DISPLAY_GRAPHICSPATHCOMMAND_AS)
#define FLEX11_6_FLASH_DISPLAY_GRAPHICSPATHCOMMAND_AS
#if defined(__cplusplus)


/**
 * Defines the values to use for specifying path-drawing commands.
 *
 *   <p class="- topic/p ">The values in this class are used by the <codeph class="+ topic/ph pr-d/codeph ">Graphics.drawPath()</codeph> method,
 * or stored in the <codeph class="+ topic/ph pr-d/codeph ">commands</codeph> vector of a GraphicsPath object.</p>
 * @langversion 3.0
 * @playerversion   Flash 10
 * @playerversion   AIR 1.5
 */

#include "flex11.6.h"



namespace flash
{
    namespace display
    {
        class GraphicsPathCommand : public Object
        {
            /**
             * Represents the default "do nothing" command.
             * @langversion 3.0
             * @playerversion   Flash 10
             * @playerversion   AIR 1.5
             */
        public:
            static const int NO_OP;

            /**
             * Specifies a drawing command that moves the current drawing position to the x- and y-coordinates specified in the data vector.
             * This command produces the same effect as the Graphics.moveTo() method, and
             * uses one point in the data vector: (x,y).
             * @langversion 3.0
             * @playerversion   Flash 10
             * @playerversion   AIR 1.5
             */
        public:
            static const int MOVE_TO;

            /**
             * Specifies a drawing command that draws a line from the current drawing position to the x- and y-coordinates
             * specified in the data vector.
             * This command produces the same effect as the Graphics.lineTo() method, and
             * uses one point in the data vector: (x,y).
             * @langversion 3.0
             * @playerversion   Flash 10
             * @playerversion   AIR 1.5
             */
        public:
            static const int LINE_TO;

            /**
             * Specifies a drawing command that draws a curve from the current drawing position to the x- and y-coordinates
             * specified in the data vector, using a control point.
             * This command produces the same effect as the Graphics.lineTo() method, and
             * uses two points in the data vector control and anchor: (cx, cy, ax, ay ).
             * @langversion 3.0
             * @playerversion   Flash 10
             * @playerversion   AIR 1.5
             */
        public:
            static const int CURVE_TO;

            /**
             * Specifies a "move to" drawing command, but uses two sets of coordinates (four values) instead of one set.
             * This command allows you to switch between "move to" and "curve to" commands without changing the number of data values used per command.
             * This command uses two sets in the data vector: one dummy location and one (x,y) location.
             *
             *   The WIDE_LINE_TO and WIDE_MOVE_TO command variants consume the same number of parameters
             * as does the CURVE_TO command.
             * @langversion 3.0
             * @playerversion   Flash 10
             * @playerversion   AIR 1.5
             */
        public:
            static const int WIDE_MOVE_TO;

            /**
             * Specifies a "line to" drawing command, but uses two sets of coordinates (four values) instead of one set.
             * This command allows you to switch between "line to" and "curve to" commands without changing the number of data values used per command.
             * This command uses two sets in the data vector: one dummy location and one (x,y) location.
             *
             *   The WIDE_LINE_TO and WIDE_MOVE_TO command variants consume the same number of parameters
             * as does the CURVE_TO command.
             * @langversion 3.0
             * @playerversion   Flash 10
             * @playerversion   AIR 1.5
             */
        public:
            static const int WIDE_LINE_TO;
        public:
            static const int CUBIC_CURVE_TO;

        public:
            GraphicsPathCommand();
        };
    }
}

#endif // FLEX11_6_FLASH_DISPLAY_GRAPHICSPATHCOMMAND_AS
#endif // __cplusplus

