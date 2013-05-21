#if !defined(FLEX11_6_FLASH_NET_DRM_DRMCONTENTDATA_AS)
#define FLEX11_6_FLASH_NET_DRM_DRMCONTENTDATA_AS
#if defined(__cplusplus)


#include "flex11.6.h"
namespace flash
{
    namespace utils
    {
        class ByteArray;
    }
}
namespace flash
{
    namespace net
    {
        namespace drm
        {
            class VoucherAccessInfo;
        }
    }
}

/**
 * The DRMContentData class provides the information required to
 * obtain the voucher necessary to view DRM-protected content.
 *
 *   <p class="- topic/p ">(AIR only) A DRMContentData object can be obtained from a NetStream instance by calling
 * the NetStream <codeph class="+ topic/ph pr-d/codeph ">preloadEmbeddedContent()</codeph> method and providing an
 * <codeph class="+ topic/ph pr-d/codeph ">onDRMContentData</codeph> callback function on the NetStream client object.
 * Use the DRMContentData object passed to the callback function as a parameter
 * for the DRMManager <codeph class="+ topic/ph pr-d/codeph ">loadVoucher()</codeph> method.</p><p class="- topic/p ">When you package content with Flash Access, you have the option of saving the content's metadata
 * as a separate file. To create a new DRMContentData object, get this metadata with a URLLoader object
 * and pass it to the DRMContentData constructor.</p>
 * @langversion 3.0
 * @playerversion   AIR 1.5
 * @playerversion   Flash 10.1
 */

using namespace flash::net::drm;
using namespace flash::utils;

namespace flash
{
    namespace net
    {
        namespace drm
        {
            class DRMContentData : public Object
            {
                /**
                 * The URL of a media rights server that
                 * provides the voucher that is required to view the associated content.
                 * @langversion 3.0
                 * @playerversion   AIR 1.5
                 * @playerversion   Flash 10.1
                 */
            public:
                std::string  serverURL();

                /**
                 * The type of authentication required to obtain a voucher for the associated content.
                 *
                 *   The supported types of authentication are:AuthenticationMethod.ANONYMOUS     anyone can obtain a voucher.AuthenticationMethod.USERNAME_AND_PASSWORD     the user must supply a valid
                 * username and password of an account that is authorized to view the associated content.The AuthenticationMethod class provides string constants to use with the
                 * authenticationMethod property.
                 * @langversion 3.0
                 * @playerversion   AIR 1.5
                 * @playerversion   Flash 10.1
                 */
            public:
                std::string  authenticationMethod();

                /**
                 * A unique id identifying the content associated with this metadata on
                 * the media rights server.
                 * @langversion 3.0
                 * @playerversion   AIR 1.5
                 * @playerversion   Flash 10.1
                 */
            public:
                std::string  licenseID();

                /**
                 * The content domain of the media rights server to which the user must be authenticated
                 * to obtain the voucher for the associated content.
                 *
                 *   If authentication is to the default domain or no authentication is required,
                 * the value of domainName is null.Note: The domain returned by this property has nothing to do with
                 * network or Internet domain names. In this case, a domain is a group
                 * of content or user accounts. For example, a single server could support several
                 * domains, each with its own set of content channels and subscribers.
                 * @langversion 3.0
                 * @playerversion   AIR 1.5
                 * @playerversion   Flash 10.1
                 */
            public:
                std::string  domain();

                /**
                 * Constructor.
                 * @langversion 3.0
                 * @playerversion   AIR 2
                 * @playerversion   Flash 10.1
                 */
            public:
                DRMContentData(ByteArray *rawData=NULL);

                /**
                 * Retrieves an array of VoucherAccessInfo objects. The array contains at least 1
                 * VoucherAccessInfo object, the default.
                 *
                 *   Each VoucherAccessInfo object represents a policy, which contains
                 * the requirements for retrieving a voucher from the media rights server.
                 * For example, if the server requires the user to authenticate, the VoucherAccessInfo object
                 * contains the authentication method. If the server requires the computer to be registered
                 * with a Realm server, the object contains the URL to the Realm server.
                 * @langversion 3.0
                 * @playerversion   AIR 2
                 * @playerversion   Flash 10.1
                 */
            public:
                std::vector<flash::net::drm::VoucherAccessInfo *> getVoucherAccessInfo();
            };
        }
    }
}

#endif // FLEX11_6_FLASH_NET_DRM_DRMCONTENTDATA_AS
#endif // __cplusplus

