

#include "DRMErrorEvent.h"
#include "flash/events/Event.h"
#include "flash/net/drm/DRMContentData.h"

    /// @eventType  flash.events.DRMErrorEvent.DRM_ERROR

using namespace flash::events;
using namespace flash::net::drm;

namespace flash {
namespace events {


        /**
         * The DRMErrorEvent.DRM_ERROR constant defines the value of the 
         * type property of a drmError event object.
         * 
         *   This event has the following properties:PropertyValuebubblesfalsecancelablefalse; there is no default behavior to cancel.errorIDA numerical error code assigned to the problem.subErrorIDAn error code that indicates more detailed information about 
         * the underlying problem.targetThe NetStream object.
         * @langversion 3.0
         * @playerversion   AIR 1.0
         * @playerversion   Flash 10.1
         */
        const std::string DRMErrorEvent::DRM_ERROR   = "drmError";
        const std::string DRMErrorEvent::DRM_LOAD_DEVICEID_ERROR  ;

        /**
         * An error ID that indicates more detailed information about the underlying problem.
         * @langversion 3.0
         * @playerversion   AIR 1.0
         * @playerversion   Flash 10.1
         */
        int DRMErrorEvent::subErrorID()      ;

        /**
         * The DRMContentData for the media file.
         * 
         *   You can use the object referenced by the contentData property
         * to retrieve the related DRM voucher from the DRMManager voucher cache. The voucher
         * properties describe the license available to the user and may explain why the
         * DRM-protected content cannot be viewed.
         * @langversion 3.0
         * @playerversion   AIR 1.5
         * @playerversion   Flash 10.1
         */
        flash::net::drm::DRMContentData* DRMErrorEvent::contentData()                               ;
        void DRMErrorEvent::contentData(DRMContentData* value)       ;

        /**
         * Indicates whether a system update is needed to play the DRM-protected content.
         * @langversion 3.0
         * @playerversion   AIR 2
         * @playerversion   Flash 10.1
         */
        bool DRMErrorEvent::systemUpdateNeeded()          ;

        /**
         * Indicates whether a DRM update is needed to play the DRM-protected content.
         * @langversion 3.0
         * @playerversion   AIR 2
         * @playerversion   Flash 10.1
         */
        bool DRMErrorEvent::drmUpdateNeeded()          ;

        /**
         * Creates a copy of the DRMErrorEvent object and sets the value of each property to match
         * that of the original.
         * @return  A new DRMErrorEvent object with property values that match those of the original.
         * @langversion 3.0
         * @playerversion   AIR 1.0
         * @playerversion   Flash 10.1
         */
        flash::events::Event* DRMErrorEvent::clone()                     ;

        /**
         * Creates an Event object that contains specific information about DRM error events.
         * Event objects are passed as parameters to event listeners.
         * @param   type    The type of the event. Event listeners can access this information through the inherited type property. There is only one type of DRMAuthenticate event: DRMAuthenticateEvent.DRM_AUTHENTICATE.
         * @param   bubbles Determines whether the Event object participates in the bubbling stage of the event flow. Event listeners can access this information through the inherited bubbles property.
         * @param   cancelable  Determines whether the Event object can be canceled. Event listeners can access this information through the inherited cancelable property.
         * @param   inErrorDetail   Where applicable, the specific syntactical details of the error.
         * @param   inErrorCode The major error code.
         * @param   insubErrorID    The minor error ID.
         * @langversion 3.0
         * @playerversion   AIR 1.0
         * @playerversion   Flash 10.1
         */
        DRMErrorEvent::DRMErrorEvent(std::string type, bool bubbles, bool cancelable, std::string inErrorDetail, int inErrorCode, int insubErrorID, DRMContentData* inMetadata, bool inSystemUpdateNeeded, bool inDrmUpdateNeeded);

        /**
         * Returns a string that contains all the properties of the DRMErrorEvent object. 
         * The string is in the following format: 
         * [DRMErrorEvent type=value bubbles=value cancelable=value
         * eventPhase=value errroID=value subErrorID=value text=value
         * @return  A string that contains all the properties of the DRMErrorEvent object.
         * @langversion 3.0
         * @playerversion   AIR 1.0
         * @playerversion   Flash 10.1
         */
        std::string DRMErrorEvent::toString()         ;
}
}

