#if !defined(FLEX11_6_FLASH_DISPLAY_GRAPHICSPATH_AS)
#define FLEX11_6_FLASH_DISPLAY_GRAPHICSPATH_AS
#if defined(__cplusplus)


/**
 * A collection of drawing commands and the coordinate parameters for those commands.
 * <p class="- topic/p ">
 * Use a GraphicsPath object with the <codeph class="+ topic/ph pr-d/codeph ">Graphics.drawGraphicsData()</codeph> method.
 * Drawing a GraphicsPath object is the equivalent of calling the <codeph class="+ topic/ph pr-d/codeph ">Graphics.drawPath()</codeph> method.
 * </p><p class="- topic/p ">The GraphicsPath class also has its own set of methods (<codeph class="+ topic/ph pr-d/codeph ">curveTo()</codeph>, <codeph class="+ topic/ph pr-d/codeph ">lineTo()</codeph>, <codeph class="+ topic/ph pr-d/codeph ">moveTo()</codeph><codeph class="+ topic/ph pr-d/codeph ">wideLineTo()</codeph> and <codeph class="+ topic/ph pr-d/codeph ">wideMoveTo()</codeph>) similar to those in the Graphics class
 * for making adjustments to the <codeph class="+ topic/ph pr-d/codeph ">GraphicsPath.commands</codeph> and <codeph class="+ topic/ph pr-d/codeph ">GraphicsPath.data</codeph> vector arrays.</p>
 * @langversion 3.0
 * @playerversion   Flash 10
 * @playerversion   AIR 1.5
 */


namespace flash
{
    namespace display
    {
        class GraphicsPath : public Object, public IGraphicsPath, public IGraphicsData
        {
            /**
             * The Vector of drawing commands as integers representing the path. Each command can be one of the values defined
             * by the GraphicsPathCommand class.
             * @langversion 3.0
             * @playerversion   Flash 10
             * @playerversion   AIR 1.5
             */
        public:
            std::vector<int> commands;

            /**
             * The Vector of Numbers containing the parameters used with the drawing commands.
             * @langversion 3.0
             * @playerversion   Flash 10
             * @playerversion   AIR 1.5
             */
        public:
            std::vector<float> data;

            /**
             * Specifies the winding rule using a value defined in the GraphicsPathWinding class.
             * @langversion 3.0
             * @playerversion   Flash 10
             * @playerversion   AIR 1.5
             */
        public:
            std::string  winding();
        public:
            void         winding(std::string value);

            /**
             * Creates a new GraphicsPath object.
             * @param   commands    A Vector of integers representing commands defined by the GraphicsPathCommand class.
             * @param   data    A Vector of Numbers where each pair of numbers is treated as a point (an x, y pair).
             * @param   winding Specifies the winding rule using a value defined in the GraphicsPathWinding class.
             * @langversion 3.0
             * @playerversion   Flash 10
             * @playerversion   AIR 1.5
             */
        public:
            GraphicsPath(std::vector<int> commands=std::vector<int>(), std::vector<float> data=std::vector<float>(), std::string winding="evenOdd");

            /**
             * Adds a new "moveTo" command to the commands vector and
             * new coordinates to the data vector.
             * @param   x   The x coordinate of the destination point.
             * @param   y   The y coordinate of the destination point.
             * @langversion 3.0
             * @playerversion   Flash 10
             * @playerversion   AIR 1.5
             */
        public:
            void     moveTo(float x, float y);

            /**
             * Adds a new "lineTo" command to the commands vector and
             * new coordinates to the data vector.
             * @param   x   The x coordinate of the destination point for the line.
             * @param   y   The y coordinate of the destination point for the line.
             * @langversion 3.0
             * @playerversion   Flash 10
             * @playerversion   AIR 1.5
             */
        public:
            void     lineTo(float x, float y);

            /**
             * Adds a new "curveTo" command to the commands vector and
             * new coordinates to the data vector.
             * @param   controlX    A number that specifies the horizontal position of the control
             *   point relative to the registration point of the parent display object.
             * @param   controlY    A number that specifies the vertical position of the control
             *   point relative to the registration point of the parent display object.
             * @param   anchorX A number that specifies the horizontal position of the next anchor
             *   point relative to the registration point of the parent display object.
             * @param   anchorY A number that specifies the vertical position of the next anchor
             *   point relative to the registration point of the parent display object.
             * @langversion 3.0
             * @playerversion   Flash 10
             * @playerversion   AIR 1.5
             */
        public:
            void     curveTo(float controlX, float controlY, float anchorX, float anchorY);

        public:
            void     cubicCurveTo(float controlX1, float controlY1, float controlX2, float controlY2, float anchorX, float anchorY);

            /**
             * Adds a new "wideLineTo" command to the commands vector and
             * new coordinates to the data vector.
             * @param   x   The x-coordinate of the destination point for the line.
             * @param   y   The y-coordinate of the destination point for the line.
             * @langversion 3.0
             * @playerversion   Flash 10
             * @playerversion   AIR 1.5
             */
        public:
            void     wideLineTo(float x, float y);

            /**
             * Adds a new "wideMoveTo" command to the commands vector and
             * new coordinates to the data vector.
             * @param   x   The x-coordinate of the destination point.
             * @param   y   The y-coordinate of the destination point.
             * @langversion 3.0
             * @playerversion   Flash 10
             * @playerversion   AIR 1.5
             */
        public:
            void     wideMoveTo(float x, float y);
        };
    }
}

#endif // FLEX11_6_FLASH_DISPLAY_GRAPHICSPATH_AS
#endif // __cplusplus

