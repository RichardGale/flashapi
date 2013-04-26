#if !defined(FLEX11_6_FLASH_EVENTS_DRMSTATUSEVENT_AS)
#define FLEX11_6_FLASH_EVENTS_DRMSTATUSEVENT_AS
#if defined(__cplusplus)


#include "flash/events/Event.h"
namespace flash
{
    namespace net
    {
        namespace drm
        {
            class DRMContentData;
        }
    }
}
namespace flash
{
    namespace net
    {
        namespace drm
        {
            class DRMVoucher;
        }
    }
}

/// @eventType  flash.events.DRMStatusEvent.DRM_STATUS
//[Event(name="drmStatus",type="flash.events.DRMStatusEvent")]

/**
 * A NetStream object dispatches a DRMStatusEvent object when the content protected using
 * digital rights management (DRM) begins playing successfully (when the voucher is
 * verified, and when the user is authenticated and authorized to view the content).
 * The DRMStatusEvent object contains information related to the voucher, such as
 * whether the content can be made available offline or when the voucher will expire
 * and the content can no longer be viewed. The application can use this data to
 * inform the user of the status of her policy and permissions.
 * @langversion 3.0
 * @playerversion   AIR 1.0
 * @playerversion   Flash 10.1
 */
using namespace flash::events;
using namespace flash::net::drm;
using namespace flash::net::drm;

namespace flash
{
    namespace events
    {
        class DRMStatusEvent: public Event
        {
            /**
             * The DRMStatusEvent.DRM_STATUS constant defines the value of the
             * type property of a drmStatus event object.
             *
             *   This event has the following properties:PropertyValuebubblesfalsecancelablefalse; there is no default behavior to cancel.detailA string explaining the context of the status event.isAnonymousIndicates whether the content protected with DRM
             * encryption is available without requiring a user to provide authentication credentials.isAvailableOfflineIndicates whether the content protected with DRM
             * encryption is available offline.offlineLeasePeriodThe remaining number of days that content can be
             * viewed offline.policiesA custom object of the DRM status event.targetThe NetStream object.voucherEndDateThe absolute date on which the voucher expires
             * and the content can no longer be viewed by userscontentDataThe DRMContentData for the contentvoucherThe DRMVoucher object for the content.isLocalIndicates whether the content is stored on the local file system
             * @langversion 3.0
             * @playerversion   AIR 1.0
             * @playerversion   Flash 10.1
             */
        public:
            static const std::string DRM_STATUS;

            /**
             * A DRMContentData object containing the information necessary
             * to obtain a voucher for viewing the DRM-protected content.
             * @langversion 3.0
             * @playerversion   AIR 1.5
             * @playerversion   Flash 10.1
             */
        public:
            flash::net::drm::DRMContentData *contentData();
        public:
            void         contentData(DRMContentData *value);

            /**
             * A DRMVoucher object for the content.
             * @langversion 3.0
             * @playerversion   AIR 1.5
             * @playerversion   Flash 10.1
             */
        public:
            flash::net::drm::DRMVoucher *voucher();
        public:
            void         voucher(DRMVoucher *value);

            /**
             * Indicates whether the voucher is cached in the local voucher store.
             * @langversion 3.0
             * @playerversion   AIR 1.5
             * @playerversion   Flash 10.1
             */
        public:
            bool         isLocal();
        public:
            void         isLocal(bool value);

            /**
             * Creates a copy of the DRMStatusEvent object and sets the value of each property to match
             * that of the original.
             * @return  A new DRMStatusEvent object with property values that match those of the original.
             * @langversion 3.0
             * @playerversion   AIR 1.0
             */
        public:
            flash::events::Event *clone();

            /**
             * Creates an Event object that contains specific information about DRM status events.
             * Event objects are passed as parameters to event listeners.
             * @param   type    The type of the event. Event listeners can access this information through the inherited type property. There is only one type of DRMAuthenticate event: DRMAuthenticateEvent.DRM_AUTHENTICATE.
             * @param   bubbles Determines whether the Event object participates in the bubbling stage of the event flow. Event listeners can access this information through the inherited bubbles property.
             * @param   cancelable  Determines whether the Event object can be canceled. Event listeners can access this information through the inherited cancelable property.
             * @param   inMetadata  The custom object that contains custom DRM properties.
             * @param   inVoucher   The context of the Event.
             * @param   inLocal Indicates if content can be viewed offline.
             * @langversion 3.0
             * @playerversion   AIR 1.0
             * @playerversion   Flash 10.1
             */
        public:
            DRMStatusEvent(std::string type, bool bubbles, bool cancelable, DRMContentData *inMetadata, DRMVoucher *inVoucher, bool inLocal);

            /**
             * Returns a string that contains all the properties of the DRMStatusEvent object.
             * @return  A string that contains all the properties of the DRMStatusEvent object.
             * @playerversion   AIR 1.0
             */
        public:
            std::string toString();
        };
    }
}

#endif // FLEX11_6_FLASH_EVENTS_DRMSTATUSEVENT_AS
#endif // __cplusplus

