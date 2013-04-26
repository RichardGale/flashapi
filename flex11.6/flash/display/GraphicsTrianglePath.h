#if !defined(FLEX11_6_FLASH_DISPLAY_GRAPHICSTRIANGLEPATH_AS)
#define FLEX11_6_FLASH_DISPLAY_GRAPHICSTRIANGLEPATH_AS
#if defined(__cplusplus)


#include "IGraphicsPath.h"
#include "IGraphicsData.h"

/**
 * Defines an ordered set of triangles that can be rendered using
 * either (u,v) fill coordinates or a normal fill.
 *
 *   Each triangle in the path is represented by three sets of (x, y)
 * coordinates, each of which is one point of the triangle.
 *
 *   <p class="- topic/p ">
 * The triangle vertices do not contain z coordinates and do not necessarily
 * represent 3D faces. However a triangle path can be used to support the rendering
 * of 3D geometry in a 2D space.
 * </p>
 * @langversion 3.0
 * @playerversion   Flash 10
 * @playerversion   AIR 1.5
 */
using namespace ;
using namespace ;

namespace flash
{
    namespace display
    {
        class GraphicsTrianglePath: public Object, public IGraphicsPath,, public IGraphicsData
        {
            /**
             * A Vector of integers or indexes, where every three indexes define a triangle. If the indexes parameter
             * is null then every three vertices (six x,y pairs in the vertices Vector) defines a triangle.
             * Otherwise each index refers to a vertex, which is a pair of numbers in the vertices Vector.
             * For example indexes[1] refers to (vertices[2], vertices[3]).
             * @langversion 3.0
             * @playerversion   Flash 10
             * @playerversion   AIR 1.5
             */
        public:
            std::vector<int> *indices;

            /**
             * A Vector of Numbers where each pair of numbers is treated as a point (an x, y pair).
             * @langversion 3.0
             * @playerversion   Flash 10
             * @playerversion   AIR 1.5
             */
        public:
            std::vector<float> *vertices;

            /**
             * A Vector of normalized coordinates used to apply texture mapping.
             * Each coordinate refers to a point on the bitmap used for the fill.
             * There must be one UV or one UVT coordinate per vertex.
             *
             *   In UV coordinates, (0,0) is the upper left of the bitmap, and (1,1) is the lower right of the bitmap.
             *
             *   If the length of this vector is twice the length of the vertices vector then normalized
             * coordinates are used without perspective correction.
             *
             *   If the length of this vector is three times the length of the vertices vector then the
             * third coordinate is interpreted as 't', the distance from the eye to the texture in eye space.
             * This helps the rendering engine correctly apply perspective when mapping textures in 3D.
             * @langversion 3.0
             * @playerversion   Flash 10
             * @playerversion   AIR 1.5
             */
        public:
            std::vector<float> *uvtData;

            /**
             * Specifies whether to render triangles that face in a given direction. Used to
             * prevent the rendering of triangles that cannot be seen in the current view.
             *
             *   Can be set to any value defined by the TriangleCulling class.
             * @langversion 3.0
             * @playerversion   Flash 10
             * @playerversion   AIR 1.5
             */
        public:
            std::string  culling();
        public:
            void         culling(std::string value);

            /**
             * Creates a new GraphicsTrianglePath object.
             * @param   vertices    A Vector of Numbers where each pair of numbers is treated as a point (an x, y pair). Required.
             * @param   indices A Vector of integers or indexes, where every three indexes define a triangle.
             * @param   uvtData A Vector of normalized coordinates used to apply texture mapping.
             * @param   culling Specifies whether to render triangles that face in a given direction. Used to
             *   prevent the rendering of triangles that cannot be seen in the current view.
             *   Can be set to any value defined by the TriangleCulling class.
             * @langversion 3.0
             * @playerversion   Flash 10
             * @playerversion   AIR 1.5
             */
        public:
            GraphicsTrianglePath(std::vector<float> *vertices, std::vector<int> *indices, std::vector<float> *uvtData, std::string culling);
        };
    }
}

#endif // FLEX11_6_FLASH_DISPLAY_GRAPHICSTRIANGLEPATH_AS
#endif // __cplusplus

