

    /**
     * The Orientation3D class is an enumeration of constant values for representing the orientation style
     * of a Matrix3D object. The three types of orientation are Euler angles, axis angle, and quaternion. 
     * The <codeph class="+ topic/ph pr-d/codeph ">decompose</codeph> and <codeph class="+ topic/ph pr-d/codeph ">recompose</codeph> methods of the Matrix3D object take one of these 
     * enumerated types to identify the rotational components of the Matrix.
     * @langversion 3.0
     * @playerversion   Flash 10
     * @playerversion   AIR 1.5
     */


namespace flash {
namespace geom {


        /**
         * Euler angles, the default orientation for decompose() and recompose() methods, 
         * defines the orientation with three separate angles of rotation for each axis. Usually,
         * a rotation around the x axis is followed by a rotation around the y axis, which is followed by a 
         * rotation around the z axis.
         * 
         *   Euler angles can sometimes lead to animation errors because of problems such as singularities when
         * rotating around the x axis or gimbal lock. For example, since with Euler angles each axis is handled 
         * independently, gimbal lock can occur during the rotation around two or more axes. The axes 
         * can become aligned, leading to unexpected results.The axis rotation properties of the display object perform Euler angles rotation.
         * @langversion 3.0
         * @playerversion   Flash 10
         * @playerversion   AIR 1.5
         */
        const std::string Orientation3D::EULER_ANGLES="eulerAngles";

        /**
         * The axis angle orientation uses a combination of an axis and an angle to determine the orientation. 
         * A line or vector from the center of a three-dimensional globe to the surface is an example of an axis.
         * The axis around which the object is rotated is a unit vector that represents any possible direction
         * in the three-dimensional space.  The angle represents the magnitude of the rotation 
         * about the vector. The direction determines where a display object is facing and the roll angle determines 
         * which way is up. You can use Vector3D and the Matrix3D objects to determine 
         * the various matrix transformations as well as to determine important three-dimensional programming 
         * values such as the distance to the intersection of two objects that can be used to detect simple 
         * collision between three-dimensional objects.
         * 
         *   The Matrix3D.appendRotation() and Matrix3D.prependRotation() methods 
         * use the axis angle orientation.
         * @langversion 3.0
         * @playerversion   Flash 10
         * @playerversion   AIR 1.5
         */
        const std::string Orientation3D::AXIS_ANGLE="axisAngle";

        /**
         * The quaternion orientation uses complex numbers. An orientation in quaternion is by the three axes of 
         * rotation (x,y,z) and an angle of rotation (w).  Quaternion guarantees the shortest, most efficient 
         * path for the rotation. It also produces a smooth, gimbal-lock-free rotation. A gimbal lock can occur 
         * when during the rotation around two or more axes the axes are aligned, leading to unexpected results.
         * 
         *   The Matrix3D.interpolate() method uses quaternion.
         * @langversion 3.0
         * @playerversion   Flash 10
         * @playerversion   AIR 1.5
         */
        const std::string Orientation3D::QUATERNION="quaternion";

        Orientation3D::Orientation3D();
}
}

