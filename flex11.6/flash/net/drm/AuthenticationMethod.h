#if !defined(FLEX11_6_FLASH_NET_DRM_AUTHENTICATIONMETHOD_AS)
#define FLEX11_6_FLASH_NET_DRM_AUTHENTICATIONMETHOD_AS
#if defined(__cplusplus)


/**
 * The AuthenticationMethod class provides string constants enumerating the
 * different types of authentication used by the <codeph class="+ topic/ph pr-d/codeph ">authenticationMethod</codeph>
 * property of the DRMContentData class.
 * @langversion 3.0
 * @playerversion   AIR 1.5
 * @playerversion   Flash 10.1
 */

namespace flash
{
    namespace net
    {
        namespace drm
        {
            class AuthenticationMethod: public Object
            {
                /**
                 * Indicates that no authentication is required.
                 * @langversion 3.0
                 * @playerversion   AIR 1.5
                 * @playerversion   Flash 10.1
                 */
            public:
                static const std::string ANONYMOUS;

                /**
                 * Indicates that a valid user name and password are required.
                 * @langversion 3.0
                 * @playerversion   AIR 1.5
                 * @playerversion   Flash 10.1
                 */
            public:
                static const std::string USERNAME_AND_PASSWORD;

            public:
                AuthenticationMethod();
            };
        }
    }
}

#endif // FLEX11_6_FLASH_NET_DRM_AUTHENTICATIONMETHOD_AS
#endif // __cplusplus

