

    /**
     * The GraphicsPathWinding class provides values for the <codeph class="+ topic/ph pr-d/codeph ">flash.display.GraphicsPath.winding</codeph> property 
     * and the <codeph class="+ topic/ph pr-d/codeph ">flash.display.Graphics.drawPath()</codeph> method
     * to determine the direction to draw a path.
     * A clockwise path is positively wound, and 
     * a counter-clockwise path is negatively wound:
     * <p class="- topic/p "><adobeimage alt="positive and negative winding directions" href="../../images/winding_positive_negative.gif" placement="inline" class="+ topic/image adobe-d/adobeimage " /></p><p class="- topic/p "> When paths intersect or overlap, the winding
     * direction determines the rules for filling the areas created by the intersection or overlap:</p><p class="- topic/p "><adobeimage alt="a comparison of even-odd and non-zero winding rules" href="../../images/winding_rules_evenodd_nonzero.gif" placement="inline" class="+ topic/image adobe-d/adobeimage " /></p>
     * @langversion 3.0
     * @playerversion   Flash 10
     * @playerversion   AIR 1.5
     */


namespace flash {
namespace display {


        /**
         * Establishes the even-odd winding type. The even-odd winding type is the rule used by all of the 
         * original drawing API and is the default type for the flash.display.Graphics.drawPath() method. 
         * Any overlapping paths will alternate between open and closed fills. If two squares drawn with the same fill 
         * intersect, the area of the intersection is not filled. Adjacent areas are not the same (neither both filled nor both unfilled).
         * @langversion 3.0
         * @playerversion   Flash 10
         * @playerversion   AIR 1.5
         */
        const std::string GraphicsPathWinding::EVEN_ODD="evenOdd";

        /**
         * Establishes the non-zero winding type. The non-zero winding type determines that
         * when paths of opposite winding intersect, the intersection area is unfilled (as with the even-odd winding type). 
         * For paths of the same winding, the intersection area is filled.
         * @langversion 3.0
         * @playerversion   Flash 10
         * @playerversion   AIR 1.5
         */
        const std::string GraphicsPathWinding::NON_ZERO="nonZero";

        GraphicsPathWinding::GraphicsPathWinding();
}
}

