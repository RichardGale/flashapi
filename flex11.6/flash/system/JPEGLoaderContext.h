#if !defined(FLEX11_6_FLASH_SYSTEM_JPEGLOADERCONTEXT_AS)
#define FLEX11_6_FLASH_SYSTEM_JPEGLOADERCONTEXT_AS
#if defined(__cplusplus)


namespace flash
{
    namespace system
    {
        class ApplicationDomain;
    }
}
namespace flash
{
    namespace system
    {
        class SecurityDomain;
    }
}

/**
 * The JPEGLoaderContext class includes a property for enabling a deblocking filter when loading a JPEG image.
 * The deblocking filter improves an image's quality at higher compression settings by smoothing neighboring pixels.
 * To apply deblocking when loading a JPEG image, create a JPEGLoaderContext object, and set its
 * <codeph class="+ topic/ph pr-d/codeph ">deblockingFilter</codeph> property. Then use the JPEGLoaderContext object name as the value of the
 * <codeph class="+ topic/ph pr-d/codeph ">context</codeph> parameter of the <codeph class="+ topic/ph pr-d/codeph ">load()</codeph> method of the Loader object used to load the image.
 *
 *   <p class="- topic/p ">The JPEGLoaderContext class extends the LoaderContext class. Set the <codeph class="+ topic/ph pr-d/codeph ">checkPolicyFile</codeph>
 * property to <codeph class="+ topic/ph pr-d/codeph ">true</codeph> if you need programmatic access to the pixels of the loaded image
 * (for example, if you're using the <codeph class="+ topic/ph pr-d/codeph ">BitmapData.draw()</codeph> method). Setting the <codeph class="+ topic/ph pr-d/codeph ">checkPolicyFile</codeph>
 * property is not necessary for AIR content running in the application sandbox.</p>
 * @langversion 3.0
 * @playerversion   Flash 10
 * @playerversion   AIR 1.5
 * @playerversion   Lite 4
 */
using namespace flash::system;
using namespace flash::system;

namespace flash
{
    namespace system
    {
        class JPEGLoaderContext: public LoaderContext
        {
            /**
             * Specifies the strength of the deblocking filter. A value of 1.0
             * applies a full strength deblocking filter, a value of 0.0 disables the deblocking filter.
             * @langversion 3.0
             * @playerversion   Flash 10
             * @playerversion   AIR 1.5
             * @playerversion   Lite 4
             */
        public:
            float deblockingFilter;

            /**
             * Creates a new JPEGLoaderContext object with the specified settings.
             * @param   deblockingFilter    Specifies the strength of the deblocking filter. A value of 1.0
             *   applies a full strength deblocking filter, a value of 0.0 disables the deblocking filter.
             * @param   checkPolicyFile Specifies whether Flash Player should check for the existence
             *   of a URL policy file before loading the object. Does not apply for AIR content running in the application sandbox.
             * @param   applicationDomain   Specifies the ApplicationDomain object to use for a Loader object.
             * @param   securityDomain  Specifies the SecurityDomain object to use for a Loader object.
             * @langversion 3.0
             * @playerversion   Flash 10
             * @playerversion   AIR 1.5
             * @playerversion   Lite 4
             */
        public:
            JPEGLoaderContext(float deblockingFilter, bool checkPolicyFile, ApplicationDomain *applicationDomain, SecurityDomain *securityDomain);
        };
    }
}

#endif // FLEX11_6_FLASH_SYSTEM_JPEGLOADERCONTEXT_AS
#endif // __cplusplus

