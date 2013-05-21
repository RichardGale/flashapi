#if !defined(FLEX11_6_FLASH_EVENTS_EVENTPHASE_AS)
#define FLEX11_6_FLASH_EVENTS_EVENTPHASE_AS
#if defined(__cplusplus)


/**
 * The EventPhase class provides values for the <codeph class="+ topic/ph pr-d/codeph ">eventPhase</codeph> property of the Event class.
 * @langversion 3.0
 * @playerversion   Flash 9
 * @playerversion   Lite 4
 * @internal    includeExample examples\EventPhaseExample.as -noswf
 */


namespace flash
{
    namespace events
    {
        class EventPhase : public Object
        {
            /**
             * The capturing phase, which is the first phase of the event flow.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            static const unsigned int CAPTURING_PHASE;

            /**
             * The target phase, which is the second phase of the event flow.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            static const unsigned int AT_TARGET;

            /**
             * The bubbling phase, which is the third phase of the event flow.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            static const unsigned int BUBBLING_PHASE;

        public:
            EventPhase();
        };
    }
}

#endif // FLEX11_6_FLASH_EVENTS_EVENTPHASE_AS
#endif // __cplusplus

