

    /**
     * Defines codes for culling algorithms that determine which triangles not to render when drawing triangle paths.
     * 
     *   <p class="- topic/p ">
     * The terms <codeph class="+ topic/ph pr-d/codeph ">POSITIVE</codeph> and <codeph class="+ topic/ph pr-d/codeph ">NEGATIVE</codeph> refer to the sign of a triangle's normal along the z-axis. 
     * The normal is a 3D vector that is perpendicular to the surface of the triangle.
     * </p><p class="- topic/p ">
     * A triangle whose vertices 0, 1, and 2 are arranged in a clockwise order has a positive normal value. That is,
     * its normal points in a positive z-axis direction, away from the current view point.  
     * When the <codeph class="+ topic/ph pr-d/codeph ">TriangleCulling.POSITIVE</codeph> algorithm is used, triangles with positive normals
     * are not rendered. Another term for this is backface culling.
     * </p><p class="- topic/p ">
     * A triangle whose vertices are arranged in a counter-clockwise order has a negative normal value. That is,
     * its normal points in a negative z-axis direction, toward the current view point. 
     * When the <codeph class="+ topic/ph pr-d/codeph ">TriangleCulling.NEGATIVE</codeph> algorithm is used, triangles with negative normals will not 
     * be rendered.
     * </p>
     * @langversion 3.0
     * @playerversion   Flash 10
     * @playerversion   AIR 1.5
     */


namespace flash {
namespace display {


        /// Specifies no culling. All triangles in the path are rendered.
        const std::string TriangleCulling::NONE   = "none";

        /**
         * Specifies culling of all triangles facing away from the current view point. 
         * This is also known as backface culling.
         */
        const std::string TriangleCulling::POSITIVE   = "positive";

        /// Specifies culling of all triangles facing toward the current view point.
        const std::string TriangleCulling::NEGATIVE   = "negative";

        TriangleCulling::TriangleCulling();
}
}

