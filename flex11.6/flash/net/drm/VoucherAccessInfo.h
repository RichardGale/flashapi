#if !defined(FLEX11_6_FLASH_NET_DRM_VOUCHERACCESSINFO_AS)
#define FLEX11_6_FLASH_NET_DRM_VOUCHERACCESSINFO_AS
#if defined(__cplusplus)


/**
 * A VoucherAccessInfo object presents the information that is required
 * to successfully retrieve and consume a voucher, such as the type
 * of authentication and the content domain of the media rights server.
 * @langversion 3.0
 * @playerversion   AIR 2
 * @playerversion   Flash 10.1
 */


namespace flash
{
    namespace net
    {
        namespace drm
        {
            class VoucherAccessInfo : public Object
            {
                /**
                 * A user-friendly string that you can use to refer to the specified
                 * VoucherAccessInfo object in the user interface.
                 *
                 *   If the metadata file for a piece of media content has multiple vouchers,
                 * each with its own VoucherAccessInfo object, the user might need to decide
                 * which voucher to authenticate to. For example, you might have
                 * a subscription-level voucher with high privileges for viewing content,
                 * as well as a basic-level voucher with lower privileges. To distinguish
                 * between these two vouchers, use the descriptive string in the
                 * displayName property. The string is set by the media
                 * packager tool (the tool that packages and encrypts media in preparation
                 * for distribution with a media rights server, such as Flash Access).For applications that are localized, you can use this property as an identifier.
                 * The application can detect the locale and localize the strings accordingly.
                 * @langversion 3.0
                 * @playerversion   AIR 2
                 * @playerversion   Flash 10.1
                 */
            public:
                std::string  displayName();

                /**
                 * The type of authentication required to obtain a voucher for the associated content.
                 *
                 *   The supported types of authentication are:AuthenticationMethod.ANONYMOUS     anyone can obtain a voucher.AuthenticationMethod.USERNAME_AND_PASSWORD     the user must supply a valid
                 * username and password of an account that is authorized to view the associated content.The AuthenticationMethod class provides string constants to use with the
                 * authenticationMethod property.
                 * @langversion 3.0
                 * @playerversion   AIR 2
                 * @playerversion   Flash 10.1
                 */
            public:
                std::string  authenticationMethod();

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
                 * @playerversion   AIR 2
                 * @playerversion   Flash 10.1
                 */
            public:
                std::string  domain();

            public:
                VoucherAccessInfo();
            };
        }
    }
}

#endif // FLEX11_6_FLASH_NET_DRM_VOUCHERACCESSINFO_AS
#endif // __cplusplus

