#if !defined(FLEX11_6_FLASH_EVENTS_PROGRESSEVENT_AS)
#define FLEX11_6_FLASH_EVENTS_PROGRESSEVENT_AS
#if defined(__cplusplus)


#include "flex11.6.h"
#include "flash/events/Event.h"

/// @eventType  flash.events.ProgressEvent.PROGRESS
//[Event(name="progress",type="flash.events.ProgressEvent")]

/// @eventType  flash.events.ProgressEvent.SOCKET_DATA
//[Event(name="socketData",type="flash.events.ProgressEvent")]

/// @eventType  flash.events.ProgressEvent.STANDARD_ERROR_DATA
//[Event(name="errorData",type="flash.events.ProgressEvent")]

/// @eventType  flash.events.ProgressEvent.STANDARD_INPUT_PROGRESS
//[Event(name="errorData",type="flash.events.ProgressEvent")]


//[Event(name="outputData",type="flash.events.ProgressEvent")]

using namespace flash::events;

namespace flash
{
    namespace events
    {
        /// @eventType  flash.events.ProgressEvent.STANDARD_OUTPUT_DATA


        /**
         * A ProgressEvent object is dispatched when a load operation has begun or a socket has received data.
         * These events are usually generated when SWF files, images or data are loaded into an application.
         * There are two types of progress events:
         * <codeph class="+ topic/ph pr-d/codeph ">ProgressEvent.PROGRESS</codeph> and <codeph class="+ topic/ph pr-d/codeph ">ProgressEvent.SOCKET_DATA</codeph>.
         * Additionally, in AIR ProgressEvent objects are dispatched
         * when a data is sent to or from a child process using the NativeProcess class.
         *
         *   EXAMPLE:
         *
         *   The following example uses the <codeph class="+ topic/ph pr-d/codeph ">ProgressEventExample</codeph> class to illustrate how various
         * event listeners are used when a file is being downloaded.  The example carries out the following tasks:
         * <ol class="- topic/ol "><li class="- topic/li ">The properties <codeph class="+ topic/ph pr-d/codeph ">downloadURL</codeph> and <codeph class="+ topic/ph pr-d/codeph ">fileName</codeph> are created, which indicate the location
         * and name of the download file.</li><li class="- topic/li ">In the <codeph class="+ topic/ph pr-d/codeph ">ProgressEventExample</codeph> constructor, a new FileReference object named <codeph class="+ topic/ph pr-d/codeph ">file</codeph> is
         * created and then passed to the <codeph class="+ topic/ph pr-d/codeph ">configureListeners()</codeph> method.</li><li class="- topic/li ">The <codeph class="+ topic/ph pr-d/codeph ">downloadURL</codeph> and <codeph class="+ topic/ph pr-d/codeph ">fileName</codeph> properties are then passed to <codeph class="+ topic/ph pr-d/codeph ">file.download()</codeph>,
         * which prompts for the location to download the file.</li><li class="- topic/li ">The <codeph class="+ topic/ph pr-d/codeph ">configureListeners()</codeph> method adds seven event listeners and their associated subscriber
         * methods:
         * <ol outputclass="A" class="- topic/ol "><li class="- topic/li "><codeph class="+ topic/ph pr-d/codeph ">cancel</codeph>/<codeph class="+ topic/ph pr-d/codeph ">cancelHandler()</codeph> is dispatched if the file download is canceled.</li><li class="- topic/li "><codeph class="+ topic/ph pr-d/codeph ">complete</codeph>/<codeph class="+ topic/ph pr-d/codeph ">complereHandler()</codeph> is dispatched when the file download process is
         * finished.</li><li class="- topic/li "><codeph class="+ topic/ph pr-d/codeph ">ioError</codeph>/<codeph class="+ topic/ph pr-d/codeph ">ioErrorHandler()</codeph> is dispatched if the download file is unavailable or
         * inaccessible.</li><li class="- topic/li "><codeph class="+ topic/ph pr-d/codeph ">open</codeph>/<codeph class="+ topic/ph pr-d/codeph ">openHandler()</codeph> is dispatched when the download operation has started.</li><li class="- topic/li "><codeph class="+ topic/ph pr-d/codeph ">progress</codeph>/<codeph class="+ topic/ph pr-d/codeph ">progressHandler()</codeph> is dispatched when the download process begins and again
         * when it ends.</li><li class="- topic/li "><codeph class="+ topic/ph pr-d/codeph ">securityError</codeph>/<codeph class="+ topic/ph pr-d/codeph ">securityErrorHandler</codeph> is dispatched if the local playback
         * security setting does not match the type of data access for the download file (local versus network);
         * see the notes below.</li><li class="- topic/li "><codeph class="+ topic/ph pr-d/codeph ">select</codeph>/<codeph class="+ topic/ph pr-d/codeph ">selectHandler()</codeph> is dispatched when the download object is selected.</li></ol></li></ol><p class="- topic/p "><b class="+ topic/ph hi-d/b ">Notes:</b><ul class="- topic/ul "><li class="- topic/li ">You need to compile the SWF file with Local Playback Security set to Access Network Files Only.</li><li class="- topic/li ">This example requires a file named SomeFile.pdf.</li><li class="- topic/li ">Although this example makes use of all events available to the FileReference object, most situations
         * require only a subset.</li></ul></p><codeblock xml:space="preserve" class="+ topic/pre pr-d/codeblock ">
         *
         *   package {
         * import flash.display.Sprite;
         * import flash.events.*;
         * import flash.net.FileReference;
         * import flash.net.URLRequest;
         *
         *   public class ProgressEventExample extends Sprite {
         * private var downloadURL:String = "http://www.[yourDomain].com/SomeFile.pdf";
         * private var fileName:String = "SomeFile.pdf";
         * private var file:FileReference;
         *
         *   public function ProgressEventExample() {
         * var request:URLRequest = new URLRequest(downloadURL);
         * file = new FileReference();
         * configureListeners(file);
         * file.download(request, fileName);
         * }
         *
         *   private function configureListeners(dispatcher:IEventDispatcher):void {
         * dispatcher.addEventListener(Event.CANCEL, cancelHandler);
         * dispatcher.addEventListener(Event.COMPLETE, completeHandler);
         * dispatcher.addEventListener(IOErrorEvent.IO_ERROR, ioErrorHandler);
         * dispatcher.addEventListener(Event.OPEN, openHandler);
         * dispatcher.addEventListener(ProgressEvent.PROGRESS, progressHandler);
         * dispatcher.addEventListener(SecurityErrorEvent.SECURITY_ERROR, securityErrorHandler);
         * dispatcher.addEventListener(Event.SELECT, selectHandler);
         * }
         *
         *   private function cancelHandler(event:Event):void {
         * trace("cancelHandler: " + event);
         * }
         *
         *   private function completeHandler(event:Event):void {
         * trace("completeHandler: " + event);
         * }
         *
         *   private function ioErrorHandler(event:IOErrorEvent):void {
         * trace("ioErrorHandler: " + event);
         * }
         *
         *   private function openHandler(event:Event):void {
         * trace("openHandler: " + event);
         * }
         *
         *   private function progressHandler(event:ProgressEvent):void {
         * var file:FileReference = FileReference(event.target);
         * trace("progressHandler: name=" + file.name + " bytesLoaded=" + event.bytesLoaded + " bytesTotal=" + event.bytesTotal);
         * }
         *
         *   private function securityErrorHandler(event:SecurityErrorEvent):void {
         * trace("securityErrorHandler: " + event);
         * }
         *
         *   private function selectHandler(event:Event):void {
         * var file:FileReference = FileReference(event.target);
         * trace("selectHandler: name=" + file.name + " URL=" + downloadURL);
         * }
         * }
         * }
         * </codeblock>
         * @langversion 3.0
         * @playerversion   Flash 9
         * @playerversion   Lite 4
         */
        class ProgressEvent : public flash::events::Event
        {
            /**
             * Defines the value of the type property of a progress event object.
             *
             *   This event has the following properties:PropertyValuebubblesfalsebytesLoadedThe number of items or bytes loaded at the time the listener processes the event.bytesTotalThe total number of items or bytes that ultimately will  be loaded if the loading process succeeds.cancelablefalse; there is no default behavior to cancel.currentTargetThe object that is actively processing the Event
             * object with an event listener.targetThe object reporting progress.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            static const std::string PROGRESS;

            /**
             * Defines the value of the type property of a socketData event object.
             *
             *   This event has the following properties:PropertyValuebubblesfalsecancelablefalse; there is no default behavior to cancel.currentTargetThe object that is actively processing the Event.bytesLoadedThe number of items or bytes loaded at the time the listener processes the event.bytesTotal0; this property is not used by socketData event objects.targetThe socket reporting progress.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            static const std::string SOCKET_DATA;

            /**
             * The number of items or bytes loaded when the listener processes the event.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            float        bytesLoaded();
        public:
            void         bytesLoaded(float value);

            /**
             * The total number of items or bytes that will be loaded if the loading process succeeds.
             * If the progress event is dispatched/attached to a Socket object, the bytesTotal will always be 0
             * unless a value is specified in the bytesTotal parameter of the constructor.
             * The actual number of bytes sent back or forth is not set and is up to the application developer.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            float        bytesTotal();
        public:
            void         bytesTotal(float value);

            /**
             * Creates an Event object that contains information about progress events.
             * Event objects are passed as parameters to event listeners.
             * @param   type    The type of the event. Possible values are:ProgressEvent.PROGRESS,
             *   ProgressEvent.SOCKET_DATA, ProgressEvent.STANDARD_ERROR_DATA, ProgressEvent.STANDARD_INPUT_PROGRESS, and ProgressEvent.STANDARD_OUTPUT_DATA.
             * @param   bubbles Determines whether the Event object participates in the bubbling stage of the event flow.
             * @param   cancelable  Determines whether the Event object can be canceled.
             * @param   bytesLoaded The number of items or bytes loaded at the time the listener processes the event.
             * @param   bytesTotal  The total number of items or bytes that will be loaded if the loading process succeeds.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            ProgressEvent(std::string type, bool bubbles   =false, bool cancelable   =false, float bytesLoaded =0, float bytesTotal =0);

            /**
             * Creates a copy of the ProgressEvent object and sets each property's value to match that of the original.
             * @return  A new ProgressEvent object with property values that match those of the original.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            flash::events::Event *clone();

            /**
             * Returns a string that contains all the properties of the ProgressEvent object. The string is in the following format:
             * [ProgressEvent type=value bubbles=value cancelable=value bytesLoaded=value bytesTotal=value]
             * @return  A string that contains all the properties of the ProgressEvent object.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            std::string toString();
        };
    }
}

#endif // FLEX11_6_FLASH_EVENTS_PROGRESSEVENT_AS
#endif // __cplusplus

