

#include "DRMManager.h"
#include "flash/events/EventDispatcher.h"
#include "flash/net/drm/DRMManager.h"
#include "flash/utils/ByteArray.h"
#include "flash/net/drm/DRMContentData.h"
#include "flash/events/DRMAuthenticationCompleteEvent.h"
#include "flash/events/DRMAuthenticationErrorEvent.h"
#include "flash/events/DRMStatusEvent.h"
#include "flash/events/DRMErrorEvent.h"
#include "flash/net/drm/DRMVoucher.h"

    /**
     * The DRMManager dispatches a DRMErrorEvent object when a requested voucher
     * cannot be obtained from the media rights server.
     * @eventType   flash.events.DRMErrorEvent.DRM_ERROR
     */

using namespace flash::events;
using namespace flash::net::drm;
using namespace flash::utils;

namespace flash {
namespace net {
namespace drm {


        /**
         * The isSupported property is set to true if the 
         * DRMManager class is supported on the current platform, otherwise it is
         * set to false.
         * @langversion 3.0
         * @playerversion   Flash 10.1
         * @playerversion   AIR 2
         */
        bool DRMManager::isSupported()          ;

        DRMManager::DRMManager();

        /**
         * Returns an instance of the singleton DRMManager object.
         * 
         *   One DRMManager instance exists for each security domain.
         * @langversion 3.0
         * @playerversion   AIR 1.5
         * @playerversion   Flash 10.1
         */
        flash::net::drm::DRMManager* DRMManager::getDRMManager()                           ;

        /**
         * Authenticates a user.
         * 
         *   Listen for the authenticationComplete and authenticationError events to determine the
         * outcome of the authentication attempt. Multiple authenticate() calls are queued. The  
         * AuthenticationCompleteEvent object dispatched for the authenticationComplete event
         * contains contains an authentication token that your application can save.You can use a saved authentication token, or a token downloaded by another means,
         * to establish an authenticated session with the media rights server in the future. To establish a
         * session using a token, call the DRMManager setAuthenticationToken() method. The properties
         * of the token, such as expiration date, are determined by the settings of the server that generates the
         * token.Important (AIR only): The authenticate() method will not succeed when a user's Internet connection passes
         * through a proxy server requiring authentication. Although such users are not able to preload a DRM voucher that requires
         * authentication, your application can obtain the voucher by beginning playback and using the NetStream
         * setAuthenticationCredentials() method to log the user into both the proxy and the media rights servers.
         * Once the voucher has been obtained, the user can view the content offline (as long as the license represented by the 
         * voucher allows offline playback).
         * @param   serverURL   The URL of a media rights server that can provide a voucher for viewing protected content
         * @param   domain  A domain on the server (not a network or Internet domain name)
         * @param   username    The user name
         * @param   password    The user password
         * @langversion 3.0
         * @playerversion   AIR 1.5
         * @playerversion   Flash 10.1
         */
        void DRMManager::authenticate(std::string serverURL, std::string domain, std::string username, std::string password)       ;

        /**
         * Sets the authentication token to use for communication with the specified server and domain.
         * 
         *   Authentication tokens are available from the token property of the 
         * DRMAuthenticationCompleteEvent object dispatched after a successful call to the authenticate()
         * method. The token is cached automatically for the session, but you can use the 
         * setAuthenticationToken() method to manage tokens directly.Setting a token overwrites any existing cached token for the server and domain. 
         * Set the token parameter to null to clear the cached token.
         * @param   serverUrl   The URL of the media rights server
         * @param   domain  The domain on the media rights server
         * @param   token   The authentication token
         * @langversion 3.0
         * @playerversion   AIR 1.5
         * @playerversion   Flash 10.1
         */
        void DRMManager::setAuthenticationToken(std::string serverUrl, std::string domain, ByteArray* token)       ;

        /**
         * Loads a voucher from a media rights server or the local voucher cache.
         * 
         *   The voucher is loaded according to the setting parameter:LoadVoucherSetting.FORCE_REFRESH: The voucher is always downloaded from the media rights server.LoadVoucherSetting.LOCAL_ONLY: The voucher is only loaded from the local cache.LoadVoucherSetting.ALLOW_SERVER: The voucher is loaded from the local cache, if possible, but 
         * otherwise is downloaded from the server.The LoadVoucherSetting class defines string constants to use as values for the setting
         * parameter.When the voucher is successfully loaded, the DRMManager dispatches a DRM status event. Your application can
         * begin playback as soon as the voucher is loaded. The loaded voucher is available in the voucher 
         * property of the dispatched DRMStatusEvent object. You can use this voucher object to display the associated media 
         * rights information to the user. If a voucher cannot be loaded from the media rights server, a DRM error event is dispatched. The errorID property
         * of the dispatched DRMErrorEvent object indicates the reason for the failure. Common causes of failure include
         * attempting to connect to the media rights server when the user is offline and attempting to load a
         * voucher when the user is not logged in. Your application can respond to these errors and take corrective action.
         * For example, if authentication credentials are required to download the voucher, you can prompt the user
         * for their account user name and password, call the DRMManager authenticate() method, and then attempt
         * to load the voucher again.If a voucher cannot be obtained from the local cache and the localOnly setting is used, a 
         * DRMErrorEvent is not dispatched. Instead, a DRM status event is dispatched. The detail property of 
         * this DRMStatusEvent object is still DRM.voucherObtained, but the voucher property 
         * is null.
         * @param   contentData The DRMContentData object from a DRM-protected media file
         * @param   setting Determines whether the voucher is retrieved from the local cache or the media rights server
         * @langversion 3.0
         * @playerversion   AIR 1.5
         * @playerversion   Flash 10.1
         */
        void DRMManager::loadVoucher(DRMContentData* contentData, std::string setting)       ;

        /**
         * Gets a preview voucher from the license server, which you can use to let a user verify
         * that they can play content on particular computer. This capability lets users
         * verify that they can play content on their computer before buying and downloading the content. It is 
         * useful when the user's computer doesn't have the necessary output protection
         * capabilities or necessary software to play content.
         * 
         *   Like loadVoucher(), this method is an asynchronous call 
         * and issues a DRMStatusEvent on completion or a DRMErrorEvent in case of errors.
         * @langversion 3.0
         * @playerversion   AIR 2
         * @playerversion   Flash 10.1
         */
        void DRMManager::loadPreviewVoucher(DRMContentData* contentData)       ;

        void DRMManager::storeVoucher(ByteArray* voucher)       ;
}
}
}

