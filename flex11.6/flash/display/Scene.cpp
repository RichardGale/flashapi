

    /**
     * The Scene class includes properties for identifying the name, labels, and number of frames 
     * in a scene. A Scene object instance is created in Flash Professional, not by
     * writing ActionScript code.
     * The MovieClip class includes a <codeph class="+ topic/ph pr-d/codeph ">currentScene</codeph> property, which is 
     * a Scene object that identifies the scene in which the playhead is located in the 
     * timeline of the MovieClip instance. The <codeph class="+ topic/ph pr-d/codeph ">scenes</codeph> property of the 
     * MovieClip class is an array of Scene objects. Also, the <codeph class="+ topic/ph pr-d/codeph ">gotoAndPlay()</codeph> 
     * and <codeph class="+ topic/ph pr-d/codeph ">gotoAndStop()</codeph> methods of the MovieClip class use Scene objects as 
     * parameters.
     * @langversion 3.0
     * @playerversion   Flash 9
     * @playerversion   Lite 4
     */


namespace flash {
namespace display {


        /**
         * The name of the scene.
         * @langversion 3.0
         * @playerversion   Flash 9
         * @playerversion   Lite 4
         */
        std::string Scene::name()         ;

        /**
         * An array of FrameLabel objects for the scene. Each FrameLabel object contains
         * a frame property, which specifies the frame number corresponding to the 
         * label, and a name property.
         * @langversion 3.0
         * @playerversion   Flash 9
         * @playerversion   Lite 4
         */
        std::vector<void*> Scene::labels()        ;

        /**
         * The number of frames in the scene.
         * @langversion 3.0
         * @playerversion   Flash 9
         * @playerversion   Lite 4
         */
        int Scene::numFrames()      ;

        Scene::Scene(std::string name, std::vector<void*> labels, int numFrames);
}
}

