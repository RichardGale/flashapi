

    /**
     * Defines the values to use for specifying path-drawing commands.
     * 
     *   <p class="- topic/p ">The values in this class are used by the <codeph class="+ topic/ph pr-d/codeph ">Graphics.drawPath()</codeph> method,
     * or stored in the <codeph class="+ topic/ph pr-d/codeph ">commands</codeph> vector of a GraphicsPath object.</p>
     * @langversion 3.0
     * @playerversion   Flash 10
     * @playerversion   AIR 1.5
     */


namespace flash {
namespace display {


        /**
         * Represents the default "do nothing" command.
         * @langversion 3.0
         * @playerversion   Flash 10
         * @playerversion   AIR 1.5
         */
        const int GraphicsPathCommand::NO_OP   = 0;

        /**
         * Specifies a drawing command that moves the current drawing position to the x- and y-coordinates specified in the data vector.
         * This command produces the same effect as the Graphics.moveTo() method, and 
         * uses one point in the data vector: (x,y).
         * @langversion 3.0
         * @playerversion   Flash 10
         * @playerversion   AIR 1.5
         */
        const int GraphicsPathCommand::MOVE_TO   = 1;

        /**
         * Specifies a drawing command that draws a line from the current drawing position to the x- and y-coordinates 
         * specified in the data vector.
         * This command produces the same effect as the Graphics.lineTo() method, and 
         * uses one point in the data vector: (x,y).
         * @langversion 3.0
         * @playerversion   Flash 10
         * @playerversion   AIR 1.5
         */
        const int GraphicsPathCommand::LINE_TO   = 2;

        /**
         * Specifies a drawing command that draws a curve from the current drawing position to the x- and y-coordinates 
         * specified in the data vector, using a control point.
         * This command produces the same effect as the Graphics.lineTo() method, and 
         * uses two points in the data vector control and anchor: (cx, cy, ax, ay ).
         * @langversion 3.0
         * @playerversion   Flash 10
         * @playerversion   AIR 1.5
         */
        const int GraphicsPathCommand::CURVE_TO   = 3;

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
        const int GraphicsPathCommand::WIDE_MOVE_TO   = 4;

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
        const int GraphicsPathCommand::WIDE_LINE_TO   = 5;
        const int GraphicsPathCommand::CUBIC_CURVE_TO  ;

        GraphicsPathCommand::GraphicsPathCommand();
}
}

