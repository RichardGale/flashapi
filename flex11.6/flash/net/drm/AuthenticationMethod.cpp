

    /**
     * The AuthenticationMethod class provides string constants enumerating the
     * different types of authentication used by the <codeph class="+ topic/ph pr-d/codeph ">authenticationMethod</codeph> 
     * property of the DRMContentData class.
     * @langversion 3.0
     * @playerversion   AIR 1.5
     * @playerversion   Flash 10.1
     */


namespace flash {
namespace net {
namespace drm {


        /**
         * Indicates that no authentication is required.
         * @langversion 3.0
         * @playerversion   AIR 1.5
         * @playerversion   Flash 10.1
         */
        const std::string AuthenticationMethod::ANONYMOUS   = "anonymous";

        /**
         * Indicates that a valid user name and password are required.
         * @langversion 3.0
         * @playerversion   AIR 1.5
         * @playerversion   Flash 10.1
         */
        const std::string AuthenticationMethod::USERNAME_AND_PASSWORD   = "usernameAndPassword";

        AuthenticationMethod::AuthenticationMethod();
}
}
}

