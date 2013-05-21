#if !defined(FLEX11_6_FLASH_NET_SHAREDOBJECT_AS)
#define FLEX11_6_FLASH_NET_SHAREDOBJECT_AS
#if defined(__cplusplus)


#include "flex11.6.h"
#include "flash/events/EventDispatcher.h"

namespace flash
{
    namespace net
    {
        class NetConnection;
    }
}

/**
 * Dispatched when a remote shared object has been updated by the server.
 * @eventType   flash.events.SyncEvent.SYNC
 */
//[Event(name="sync",type="flash.events.SyncEvent")]

/**
 * Dispatched when a SharedObject instance is reporting its status or error condition.
 * @eventType   flash.events.NetStatusEvent.NET_STATUS
 */
//[Event(name="netStatus",type="flash.events.NetStatusEvent")]

/**
 * Dispatched when an exception is thrown asynchronously &#x2014; that is,
 * from native asynchronous code.
 * @eventType   flash.events.AsyncErrorEvent.ASYNC_ERROR
 */
//[Event(name="asyncError",type="flash.events.AsyncErrorEvent")]

using namespace flash::events;
using namespace flash::net;

namespace flash
{
    namespace net
    {
        /**
         * The SharedObject class is used to read and store limited amounts of data on a user's computer
         * or on a server.
         * Shared objects offer real-time data sharing between multiple client SWF files and objects
         * that are persistent on the local computer or remote server. Local shared objects are similar
         * to browser cookies and remote shared objects are similar to real-time data transfer devices.
         * To use remote shared objects, you need Adobe Flash Media Server.
         *
         *   <p class="- topic/p ">Use shared objects to do the following:</p><ul class="- topic/ul "><li class="- topic/li "><b class="+ topic/ph hi-d/b ">Maintain local persistence</b>.
         * This is the simplest way to use a shared object, and does not require Flash Media Server.
         * For example, you can call <codeph class="+ topic/ph pr-d/codeph ">SharedObject.getLocal()</codeph> to create a shared object in an
         * application, such as a calculator with memory. When the user closes the calculator,
         * Flash Player saves the last value in a shared object on the user's computer.
         * The next time the calculator is run, it contains the values it had previously.
         * Alternatively, if you set the shared object's properties to <codeph class="+ topic/ph pr-d/codeph ">null</codeph> before the
         * calculator application is closed,  the next time the
         * application runs, it opens without any values.
         *
         *   Another example of maintaining local persistence is tracking user preferences or
         * other data for a complex website, such as a record of which
         * articles a user read on a news site. Tracking this information allows you to display
         * articles that have already been read differently from new, unread articles.
         * Storing this information on the user's computer reduces server load.</li><li class="- topic/li "><b class="+ topic/ph hi-d/b ">Store and share data on Flash Media Server</b>.
         * A shared object can store data on the server for other clients to retrieve.
         * For example, call <codeph class="+ topic/ph pr-d/codeph ">SharedObject.getRemote()</codeph> to create a remote shared object,
         * such as a phone list, that is persistent on the server. Whenever a client makes changes
         * to the shared object, the revised data is available to all clients currently
         * connected to the object or who later connect to it. If the object is also persistent locally,
         * and a client changes data while not connected to the server, the data is copied to the remote shared
         * object the next time the client connects to the object.</li><li class="- topic/li "><b class="+ topic/ph hi-d/b ">Share data in real time</b>.
         * A shared object can share data among multiple clients in real time.
         * For example, you can open a remote shared object that stores
         * a list of users connected to a chat room that is visible to all clients
         * connected to the object. When a user enters or leaves the chat room, the object
         * is updated and all clients that are connected to the object see the revised list
         * of chat room users.</li></ul><p class="- topic/p "> To create a local shared object, call <codeph class="+ topic/ph pr-d/codeph ">SharedObject.getLocal()</codeph>. To create
         * a remote shared object, call <codeph class="+ topic/ph pr-d/codeph ">SharedObject.getRemote()</codeph>.</p><p class="- topic/p "> When an application closes, shared objects are <i class="+ topic/ph hi-d/i ">flushed</i>, or written to a disk.
         * You can also call the <codeph class="+ topic/ph pr-d/codeph ">flush()</codeph> method to explicitly write data to a disk.</p><p class="- topic/p "><b class="+ topic/ph hi-d/b ">Local disk space considerations.</b> Local shared objects have some limitations
         * that are important to consider as you design your application.
         * Sometimes SWF files may not be allowed to write local shared objects, and sometimes the data
         * stored in local shared objects can be deleted without your knowledge. Flash Player users
         * can manage the disk space that is available to individual domains or
         * to all domains. When users decrease the amount of disk space available, some local shared
         * objects may be deleted. Flash Player users also have privacy controls that can prevent
         * third-party domains (domains other than the domain in the current browser address bar) from
         * reading or writing local shared objects.</p><p class="- topic/p "><b class="+ topic/ph hi-d/b ">Note</b>: SWF files that are stored and run on a local computer, not from a remote server,
         * can always write third-party shared objects to disk.
         * For more information about third-party shared objects, see the
         * <xref href="http://www.macromedia.com/support/documentation/en/flashplayer/help/settings_manager03.html" scope="external" class="- topic/xref ">Global Storage Settings panel</xref> in Flash Player Help.</p><p class="- topic/p ">It's a good idea to check for failures related to the amount of disk space and to
         * user privacy controls. Perform these checks when you call <codeph class="+ topic/ph pr-d/codeph ">getLocal()</codeph> and
         * <codeph class="+ topic/ph pr-d/codeph ">flush()</codeph>:
         *
         *   <ul class="- topic/ul "><li class="- topic/li "><codeph class="+ topic/ph pr-d/codeph ">SharedObject.getLocal()</codeph>     Flash Player throws an exception when
         * a call to this method fails, such as when the user has disabled
         * third-party shared objects and the domain of your SWF file does not match the domain in the browser
         * address bar.</li><li class="- topic/li "><codeph class="+ topic/ph pr-d/codeph ">SharedObject.flush()</codeph>     Flash Player throws an exception
         * when a call to this method fails. It returns <codeph class="+ topic/ph pr-d/codeph ">SharedObjectFlushStatus.FLUSHED</codeph> when it succeeds.
         * It returns <codeph class="+ topic/ph pr-d/codeph ">SharedObjectFlushStatus.PENDING</codeph>
         * when additional storage space is needed. Flash Player prompts the user to allow an increase
         * in storage space for locally saved information. Thereafter, the <codeph class="+ topic/ph pr-d/codeph ">netStatus</codeph> event
         * is dispatched with an information object indicating whether the flush failed or succeeded.</li></ul></p><p class="- topic/p ">If your SWF file attempts to create or modify local shared objects, make sure
         * that your SWF file is at least 215 pixels wide and at least 138 pixels high (the
         * minimum dimensions for displaying the dialog box that prompts users to increase their
         * local shared object storage limit). If your SWF file is smaller than these dimensions and an
         * increase in the storage limit is required, <codeph class="+ topic/ph pr-d/codeph ">SharedObject.flush()</codeph> fails,
         * returning <codeph class="+ topic/ph pr-d/codeph ">SharedObjectFlushedStatus.PENDING</codeph> and dispatching the <codeph class="+ topic/ph pr-d/codeph ">netStatus</codeph> event.</p><p class="- topic/p "><b class="+ topic/ph hi-d/b ">Remote shared objects.</b>
         * With Flash Media Server, you can create and use remote shared objects,
         * that are shared in real-time by all clients connected to your application.
         * When one client changes a property of a remote shared object, the property
         * is changed for all connected clients.
         * You can use remote shared objects to synchronize clients, for example, users
         * in a multi-player game.
         * </p><p class="- topic/p ">
         * Each remote shared object has a <codeph class="+ topic/ph pr-d/codeph ">data</codeph> property which is an Object with properties
         * that store data. Call <codeph class="+ topic/ph pr-d/codeph ">setProperty()</codeph>
         * to change an property of the data object.
         * The server updates the properties, dispatches a <codeph class="+ topic/ph pr-d/codeph ">sync</codeph> event, and
         * sends the properties back to the connected clients.
         * </p><p class="- topic/p ">
         * You can choose to make remote shared objects persistent on the client, the server,
         * or both. By default, Flash Player saves locally persistent remote shared objects up to 100K in size.
         * When you try to save a larger object, Flash Player displays the Local Storage dialog box,
         * which lets the user allow or deny local storage for the shared object.
         * Make sure your Stage size is at least 215 by 138 pixels; this is the minimum size Flash
         * requires to display the dialog box.
         * </p><p class="- topic/p ">
         * If the user selects Allow, the server saves the shared object and
         * dispatches a <codeph class="+ topic/ph pr-d/codeph ">netStatus</codeph> event with a <codeph class="+ topic/ph pr-d/codeph ">code</codeph> property of
         * <codeph class="+ topic/ph pr-d/codeph ">SharedObject.Flush.Success</codeph>.
         * If the user select Deny, the server does not save the shared object and dispatches
         * a <codeph class="+ topic/ph pr-d/codeph ">netStatus</codeph> event
         * with a <codeph class="+ topic/ph pr-d/codeph ">code</codeph> property of <codeph class="+ topic/ph pr-d/codeph ">SharedObject.Flush.Failed</codeph>.
         * </p>
         *
         *   EXAMPLE:
         *
         *   The following code creates (and on subsequent executions, retrieves) a shared object
         * object using the ID <codeph class="+ topic/ph pr-d/codeph ">"application-name"</codeph>. When the Save button is clicked, the
         * <codeph class="+ topic/ph pr-d/codeph ">saveValue()</codeph> method attempts to save a property named <codeph class="+ topic/ph pr-d/codeph ">savedValue</codeph>
         * to the <codeph class="+ topic/ph pr-d/codeph ">data</codeph> property of the SharedObject object. If Flash Player must ask for permission to save
         * the data, when the user grants or denies permission the <codeph class="+ topic/ph pr-d/codeph ">onFlushStatus()</codeph> method is
         * called. When the Clear button is clicked, the <codeph class="+ topic/ph pr-d/codeph ">clearValue()</codeph> method deletes the value
         * saved in <codeph class="+ topic/ph pr-d/codeph ">savedValue</codeph>; the next time the SWF file is loaded, the value that is retrieved
         * is <codeph class="+ topic/ph pr-d/codeph ">undefined</codeph>.
         *
         *   <codeblock xml:space="preserve" class="+ topic/pre pr-d/codeblock ">
         * package {
         * import flash.display.Sprite;
         * import flash.events.MouseEvent;
         * import flash.events.NetStatusEvent;
         * import flash.net.SharedObject;
         * import flash.net.SharedObjectFlushStatus;
         * import flash.text.TextField;
         * import flash.text.TextFieldAutoSize;
         * import flash.text.TextFieldType;
         *
         *   public class SharedObjectExample extends Sprite {
         *
         *   private var mySo:SharedObject;
         *
         *   public function SharedObjectExample() {
         * buildUI();
         * saveBtn.addEventListener(MouseEvent.CLICK, saveValue);
         * clearBtn.addEventListener(MouseEvent.CLICK, clearValue);
         *
         *   mySo = SharedObject.getLocal("application-name");
         * output.appendText("SharedObject loaded...\n");
         * output.appendText("loaded value: " + mySo.data.savedValue + "\n\n");
         * }
         *
         *   private function saveValue(event:MouseEvent):void {
         * output.appendText("saving value...\n");
         * mySo.data.savedValue = input.text;
         *
         *   var flushStatus:String = null;
         * try {
         * flushStatus = mySo.flush(10000);
         * } catch (error:Error) {
         * output.appendText("Error...Could not write SharedObject to disk\n");
         * }
         * if (flushStatus != null) {
         * switch (flushStatus) {
         * case SharedObjectFlushStatus.PENDING:
         * output.appendText("Requesting permission to save object...\n");
         * mySo.addEventListener(NetStatusEvent.NET_STATUS, onFlushStatus);
         * break;
         * case SharedObjectFlushStatus.FLUSHED:
         * output.appendText("Value flushed to disk.\n");
         * break;
         * }
         * }
         * output.appendText("\n");
         * }
         *
         *   private function clearValue(event:MouseEvent):void {
         * output.appendText("Cleared saved value...Reload SWF and the value should be \"undefined\".\n\n");
         * delete mySo.data.savedValue;
         * }
         *
         *   private function onFlushStatus(event:NetStatusEvent):void {
         * output.appendText("User closed permission dialog...\n");
         * switch (event.info.code) {
         * case "SharedObject.Flush.Success":
         * output.appendText("User granted permission -- value saved.\n");
         * break;
         * case "SharedObject.Flush.Failed":
         * output.appendText("User denied permission -- value not saved.\n");
         * break;
         * }
         * output.appendText("\n");
         *
         *   mySo.removeEventListener(NetStatusEvent.NET_STATUS, onFlushStatus);
         * }
         *
         *   // UI elements
         * private var inputLbl:TextField;
         * private var input:TextField;
         * private var output:TextField;
         * private var saveBtn:Sprite;
         * private var clearBtn:Sprite;
         *
         *   private function buildUI():void {
         * // input label
         * inputLbl = new TextField();
         * addChild(inputLbl);
         * inputLbl.x = 10;
         * inputLbl.y = 10;
         * inputLbl.text = "Value to save:";
         *
         *   // input TextField
         * input = new TextField();
         * addChild(input);
         * input.x = 80;
         * input.y = 10;
         * input.width = 100;
         * input.height = 20;
         * input.border = true;
         * input.background = true;
         * input.type = TextFieldType.INPUT;
         *
         *   // output TextField
         * output = new TextField();
         * addChild(output);
         * output.x = 10;
         * output.y = 35;
         * output.width = 250;
         * output.height = 250;
         * output.multiline = true;
         * output.wordWrap = true;
         * output.border = true;
         * output.background = true;
         *
         *   // Save button
         * saveBtn = new Sprite();
         * addChild(saveBtn);
         * saveBtn.x = 190;
         * saveBtn.y = 10;
         * saveBtn.useHandCursor = true;
         * saveBtn.graphics.lineStyle(1);
         * saveBtn.graphics.beginFill(0xcccccc);
         * saveBtn.graphics.drawRoundRect(0, 0, 30, 20, 5, 5);
         * var saveLbl:TextField = new TextField();
         * saveBtn.addChild(saveLbl);
         * saveLbl.text = "Save";
         * saveLbl.selectable = false;
         *
         *   // Clear button
         * clearBtn = new Sprite();
         * addChild(clearBtn);
         * clearBtn.x = 230;
         * clearBtn.y = 10;
         * clearBtn.useHandCursor = true;
         * clearBtn.graphics.lineStyle(1);
         * clearBtn.graphics.beginFill(0xcccccc);
         * clearBtn.graphics.drawRoundRect(0, 0, 30, 20, 5, 5);
         * var clearLbl:TextField = new TextField();
         * clearBtn.addChild(clearLbl);
         * clearLbl.text = "Clear";
         * clearLbl.selectable = false;
         * }
         * }
         * }
         * </codeblock>
         * @langversion 3.0
         * @playerversion   Flash 9
         * @playerversion   Lite 4
         */
        class SharedObject : public flash::events::EventDispatcher
        {
            /**
             * The default object encoding (AMF version) for all local shared objects created in the SWF file.
             * When local shared objects are written to disk, the
             * SharedObject.defaultObjectEncoding property
             * indicates which Action Message Format version should be used: the ActionScript 3.0 format (AMF3) or the ActionScript 1.0 or 2.0 format (AMF0).
             *
             *   For more information about object encoding, including the difference between
             * encoding in local and remote shared objects, see the description of the
             * objectEncoding property.The default value of SharedObject.defaultObjectEncoding is set to use the
             * ActionScript 3.0 format, AMF3.
             * If you need to write local shared objects that ActionScript 2.0 or 1.0 SWF files can read,
             * set SharedObject.defaultObjectEncoding to use the
             * ActionScript 1.0 or ActionScript 2.0 format, flash.net.ObjectEncoding.AMF0,
             * at the beginning of your script, before you create any local shared objects.
             * All local shared objects
             * created thereafter will use AMF0 encoding and can interact with older content.
             * You cannot change the objectEncoding value of existing local shared objects
             * by setting SharedObject.defaultObjectEncoding after the local shared
             * objects have been created.To set the object encoding on a per-object basis, rather than for all shared objects
             * created by the SWF file, set the objectEncoding property of the local shared object instead.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            static unsigned int defaultObjectEncoding();
        public:
            static void         defaultObjectEncoding(unsigned int version);

            /**
             * The collection of attributes assigned to the data property of the object; these attributes can
             * be shared and stored. Each attribute can be an object of any ActionScript or JavaScript
             * type     Array, Number, Boolean, ByteArray, XML, and so on. For example, the following lines assign values to various aspects
             * of a shared object:
             *
             *   <codeblock>
             *
             *   var items_array:Array = new Array(101, 346, 483);
             * var currentUserIsAdmin:Boolean = true;
             * var currentUserName:String = "Ramona";
             *
             *   var my_so:SharedObject = SharedObject.getLocal("superfoo");
             * my_so.data.itemNumbers = items_array;
             * my_so.data.adminPrivileges = currentUserIsAdmin;
             * my_so.data.userName = currentUserName;
             *
             *   for (var prop in my_so.data) {
             * trace(prop+": "+my_so.data[prop]);
             * }
             *
             *   </codeblock>
             * All attributes of a shared object's data property are saved if the object is persistent, and
             * the shared object contains the following information:
             * <codeblock>
             *
             *   userName: Ramona
             * adminPrivileges: true
             * itemNumbers: 101,346,483
             *
             *   </codeblock>
             * Note: Do not assign values directly to the data property of a shared
             * object, as in so.data = someValue; Flash Player ignores these assignments.To delete attributes for local shared objects, use code such as
             * delete so.data.attributeName; setting an attribute to
             * null or undefined for a local shared object does not
             * delete the attribute.To create private values for a shared object     values that are available only to the client
             * instance while the object is in use and are not stored with the object when it is closed     create properties
             * that are not named data to store them, as shown in the following example:
             * <codeblock>
             *
             *   var my_so:SharedObject = SharedObject.getLocal("superfoo");
             * my_so.favoriteColor = "blue";
             * my_so.favoriteNightClub = "The Bluenote Tavern";
             * my_so.favoriteSong = "My World is Blue";
             *
             *   for (var prop in my_so) {
             * trace(prop+": "+my_so[prop]);
             * }
             *
             *   </codeblock>
             * The shared object contains the following data:
             * <codeblock>
             *
             *   favoriteSong: My World is Blue
             * favoriteNightClub: The Bluenote Tavern
             * favoriteColor: blue
             * data: [object Object]
             *
             *   </codeblock>
             *
             *   For remote shared objects used with a server, all attributes of the data
             * property are available to all clients connected to the shared object, and all attributes
             * are saved if the object is persistent.
             * If one client changes the value of an attribute, all clients now see the new value.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            Object      *data();

            /**
             * The current size of the shared object, in bytes.
             *
             *   Flash calculates the size of a shared object by stepping through all of its data
             * properties; the more data properties the object has, the longer it takes to estimate its size.
             * Estimating object size can take significant processing time, so you
             * may want to avoid using this method unless you have a specific need for it.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            unsigned int size();

            /**
             * Specifies the number of times per second that a client's changes to a
             * shared object are sent to the server.
             *
             *   Use this method when you want to control the amount of traffic between
             * the client and the server. For example, if the connection between the client
             * and server is relatively slow, you may want to set fps
             * to a relatively low value. Conversely, if the client is connected to a multiuser
             * application in which timing is important, you may want to set fps
             * to a relatively high value.Setting fps will trigger a sync event and update all changes to the server.
             * If you only want to update the server manually, set fps to 0.Changes are not sent to the server until the sync event has been dispatched.
             * That is, if the response time from the server is slow, updates may be sent to
             * the server less frequently than the value specified in this property.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             * @internal    server-specific: The info is relevant for Flash Media Server, but not Flex.
             */
        public:
            void         fps(float updatesPerSecond);

            /**
             * The object encoding (AMF version) for this shared object. When a local shared object is written to disk,
             * the objectEncoding property indicates which Action
             * Message Format version should be used: the ActionScript 3.0 format (AMF3)
             * or the ActionScript 1.0 or 2.0 format (AMF0).
             *
             *   Object encoding is handled differently depending if the shared object
             * is local or remote.Local shared objects. You can get or set the value of the
             * objectEncoding property for local shared objects.
             * The value of objectEncoding
             * affects what formatting is used for writing this local shared object.
             * If this local shared object must be readable by
             * ActionScript 2.0 or 1.0 SWF files, set objectEncoding to
             * ObjectEncoding.AMF0.
             * Even if object encoding is set to write AMF3, Flash Player can still read AMF0 local shared objects.
             * That is, if you use the default value of this property, ObjectEncoding.AMF3,
             * your SWF file can still read shared objects created by ActionScript 2.0 or 1.0 SWF files.
             * Remote shared objects. When connected to the server, a remote shared object
             * inherits its objectEncoding setting from the associated NetConnection
             * instance (the instance used to connect to the remote shared object). When not connected
             * to the server, a remote shared object inherits the defaultObjectEncoding
             * setting from the associated NetConnection instance.
             * Because the value of a remote shared object's objectEncoding property is
             * determined by the NetConnection instance, this property is read-only for remote shared objects.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             * @throws  ReferenceError You attempted to set the value of the objectEncoding
             *   property on a remote shared object. This property is read-only for remote shared objects because
             *   its value is determined by the associated NetConnection instance.
             */
        public:
            unsigned int objectEncoding();
        public:
            void         objectEncoding(unsigned int version);

            /**
             * Indicates the object on which
             * callback methods are invoked. The default object is this.
             * You can set the client property to another object, and callback methods will be
             * invoked on that other object.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             * @internal    Property documented; needs review.
             * @throws  TypeError The client property must be set to a non-null object.
             */
        public:
            Object      *client();
        public:
            void         client(Object *object);

        public:
            static int      deleteAll(std::string url);

        public:
            static int      getDiskUsage(std::string url);

            /**
             * Returns a reference to a locally persistent shared object that is only available to the current client.
             * If the shared object does not already exist, this method creates one. If any values
             * passed to getLocal() are invalid or if the call fails, Flash Player throws an exception.
             *
             *   The following code shows how you assign the returned shared object reference to a variable:var so:SharedObject = SharedObject.getLocal("savedData");Note: If the user has chosen to never allow local storage for this domain,
             * the object is not saved locally, even if a value for localPath is specified. The
             * exception to this rule is local content. Local content can always write shared objects
             * from third-party domains (domains other than the domain in the current browser address bar)
             * to disk, even if writing of third-party shared objects to disk is disallowed.
             * To avoid name conflicts, Flash looks at the location of the SWF file creating the
             * shared object. For example, if a SWF file at www.myCompany.com/apps/stockwatcher.swf creates a
             * shared object named portfolio, that shared object does not conflict with another
             * object named portfolio that was created by a SWF file at
             * www.yourCompany.com/photoshoot.swf because the SWF files originate from different directories. Although the localPath parameter is optional, you should give some
             * thought to its use, especially if other SWF files need to access the shared object. If the
             * data in the shared object is specific to one SWF file that will not be moved to another location,
             * then use of the default value makes sense. If other SWF files need access to the shared object, or
             * if the SWF file that creates the shared object will later be moved, then the value of this parameter
             * affects how accessible the shared object will be. For example, if you create a shared object with
             * localPath set to the default value of the full path to the SWF file, no other SWF
             * file can access that shared object. If you later move the original SWF file to another location,
             * not even that SWF file can access the data already stored in the shared object.To avoid inadvertently restricting access to a shared object, use
             * the localpath parameter. The most permissive approach is to set
             * localPath to / (slash), which makes the shared object available to all SWF files
             * in the domain, but increases the likelihood of name conflicts with other shared objects in
             * the domain. A more restrictive approach is to append localPath with folder names that are in
             * the full path to the SWF file. For example, for a portfolio shared object created by the SWF
             * file at www.myCompany.com/apps/stockwatcher.swf, you could set the localPath parameter to
             * /, /apps, or /apps/stockwatcher.swf. You must determine which
             * approach provides optimal flexibility for your application.When using this method, consider the following security model:
             *
             *   You cannot access shared objects across sandbox boundaries.Users can restrict shared object access by using the Flash Player Settings dialog box
             * or the Settings Manager. By default, an application can create shared objects of up 100 KB of data per domain.
             * Administrators and users can also place restrictions on the ability to write to the file system.Suppose you publish SWF file content to be played back as local files (either locally installed SWF files or
             * EXE files), and you need to access a specific shared object from more than one local SWF file. In this situation,
             * be aware that for local files, two different locations might be used to store shared objects. The domain that is
             * used depends on the security permissions granted to the local file that created the shared object. Local files
             * can have three different levels of permissions:
             *
             *   Access to the local filesystem only.Access to the network only.Access to both the network and the local filesystem.Local files with access to the local filesystem (level 1 or 3) store their shared objects in one location.
             * Local files without access to the local filesystem (level 2) store their shared objects in another location.You can prevent a SWF file from using this method by setting the
             * allowNetworking parameter of the the object and embed
             * tags in the HTML page that contains the SWF content.For more information, see the Flash Player Developer Center Topic:
             * Security.
             * @param   name    The name of the object. The name can include forward slashes (/); for example,
             *   work/addresses is a legal name. Spaces are not allowed in a shared
             *   object name, nor are the following characters:
             *
             *     ~ % & \ ; : " ' , < > ? #
             * @param   localPath   The full or partial path to the SWF file that created the shared object, and that
             *   determines where the shared object will be stored locally. If you do not specify this parameter, the
             *   full path is used.
             * @param   secure  Determines whether access to this shared object
             *   is restricted to SWF files that are delivered over an HTTPS connection.
             *   If your SWF file is delivered over HTTPS, this parameter's value has the following effects:
             *   If this parameter is set to true, Flash Player creates a new secure shared object or
             *   gets a reference to an existing secure shared object. This secure shared object
             *   can be read from or written to only by SWF files delivered over HTTPS that call
             *   SharedObject.getLocal() with the secure parameter set to
             *   true.If this parameter is set to false, Flash Player creates a new shared object or
             *   gets a reference to an existing shared object that can be read from
             *   or written to by SWF files delivered over non-HTTPS connections.If your SWF file is delivered over a non-HTTPS connection and you try to set this parameter
             *   to true, the creation of a new shared object (or the access of a previously
             *   created secure shared object) fails and null is returned. Regardless of the
             *   value of this parameter, the created shared objects count toward the total amount
             *   of disk space allowed for a domain.The following diagram shows the use of the secure parameter:
             * @return  A reference to a shared object that is persistent locally and is available only to the
             *   current client. If Flash Player can't create or find the shared object (for example, if
             *   localPath was
             *   specified but no such directory exists), this method throws an exception.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             * @throws  Error Flash Player cannot create the shared object for whatever reason.
             *   This error might occur is if persistent shared object creation
             *   and storage by third-party Flash content is prohibited (does not apply to local content).
             *   Users can prohibit third-party persistent shared objects on the Global Storage Settings panel of the
             *   Settings Manager, located at
             *   http://www.adobe.com/support/documentation/en/flashplayer/help/settings_manager03.html.
             */
        public:
            static flash::net::SharedObject *getLocal(std::string name, std::string localPath="", bool secure   =false);

            /**
             * Returns a reference to a shared object on Flash Media Server that multiple
             * clients can access.
             * If the remote shared object does not already exist, this method creates one.
             *
             *   To create a remote shared object, call getRemote() the call
             * connect() to connect the remote shared object to the server, as in
             * the following:
             * <codeblock>
             *
             *   var nc:NetConnection = new NetConnection();
             * nc.connect("rtmp://somedomain.com/applicationName");
             * var myRemoteSO:SharedObject = SharedObject.getRemote("mo", nc.uri, false);
             * myRemoteSO.connect(nc);
             *
             *   </codeblock>
             *
             *   To confirm that the local and remote copies of the shared object are synchronized,
             * listen for and handle the sync event.
             * All clients that want to share this object must pass the same values for
             * the name and remotePath parameters.
             * To create a shared object that is available only to the current client,
             * use SharedObject.getLocal().
             * @param   name    The name of the remote shared object. The name can include forward slashes (/);
             *   for example, work/addresses is a legal name. Spaces are not allowed in a shared object name,
             *   nor are the following characters:
             *   ~ % & \ ; :  " ' , > ? ? #
             * @param   remotePath  The URI of the server on which the shared object will be stored.
             *   This URI must be identical to the URI of the NetConnection object passed to the
             *   connect() method.
             * @param   persistence Specifies whether the attributes of the shared
             *   object's data property are persistent locally, remotely, or both. This parameter can also specify
             *   where the shared object will be stored locally. Acceptable values are as follows:
             *   A value of false specifies that the shared object is not persistent
             *   on the client or server.A value of true specifies that the shared object is persistent only on the server.A full or partial local path to the shared object indicates that the shared
             *   object is persistent on the client and the server. On the client, it is stored in the
             *   specified path; on the server, it is stored in a subdirectory within the application
             *   directory.Note: If the user has chosen to never allow local storage
             *   for this domain, the object will not be saved locally, even if a local path is
             *   specified for persistence. For more information, see the class description.
             * @param   secure  Determines whether access to this shared object is restricted to SWF
             *   files that are delivered over an HTTPS connection. For more information, see the
             *   description of the secure parameter in the
             *   getLocal method entry.
             * @return  A reference to an object that can be shared across multiple clients.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             * @internal    server-specific: This info is relevant for Flash Media Server, but not Flex Data Services.
             * @throws  Error Flash Player can't create or find the shared object. This might occur if nonexistent paths were
             *   specified for the remotePath and persistence parameters.
             */
        public:
            static flash::net::SharedObject *getRemote(std::string name, std::string remotePath="", Object *persistence=false, bool secure   =false);

            /**
             * Connects to a remote shared object on a server through a specified NetConnection object.
             * Use this method after calling getRemote().
             * When a connection is successful, the sync event is dispatched.
             *
             *   Before attempting to work with a remote shared object,
             * first check for any errors using a try..catch..finally statement.
             * Then, listen for and handle the sync event before
             * you make changes to the shared object. Any changes made
             * locally     before the sync event is dispatched     might be lost.
             *
             *   Call the connect() method
             * to connect to a remote shared object, for example:
             *
             *   <codeblock>
             *
             *   var myRemoteSO:SharedObject = SharedObject.getRemote("mo", myNC.uri, false);
             * myRemoteSO.connect(myNC);
             *
             *   </codeblock>
             * @param   myConnection    A NetConnection object that uses the Real-Time Messaging Protocol (RTMP),
             *   such as a NetConnection object used to communicate with Flash Media Server.
             * @param   params  A string defining a message to pass to the remote shared object on the server.
             *   Cannot be used with Flash Media Server.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             * @internal    server-specific: On FMS, can connect to a shared object, but cannot pass a message as a second param.
             * @throws  Error Flash Player could not connect to the specified remote shared object.
             *   Verify that the NetConnection instance is valid and connected and that the
             *   remote shared object was successfully created on the server.
             */
        public:
            void     connect(NetConnection *myConnection, std::string params="");

            /**
             * Closes the connection between a remote shared object and the server.
             * If a remote shared object is locally persistent, the user can make changes
             * to the local copy of the object after this method is called. Any changes made
             * to the local object are sent to the server the next time the user connects
             * to the remote shared object.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             * @internal    server-specific: This info is relevant for Flash Media Server, but not Flex Data Services.
             */
        public:
            void     close();

            /**
             * Immediately writes a locally persistent shared object to a local file. If you don't use this
             * method, Flash Player writes the shared object to a file when the shared object session ends
             * that is, when the SWF file is closed, when the shared object is garbage-collected
             * because it no longer has any references to it, or when you call SharedObject.clear()
             * or SharedObject.close().
             *
             *   If this method returns SharedObjectFlushStatus.PENDING,
             * Flash Player displays a dialog box asking
             * the user to increase the amount of disk space available to objects from this domain. To allow
             * space for the shared object to  grow when it is saved in the future, which avoids return values
             * of PENDING, pass a value for minDiskSpace. When Flash Player
             * tries to write the file, it looks for the number of bytes passed to
             * minDiskSpace, instead of looking for enough space to save the shared
             * object at its current size. For example, if you expect a shared object to grow to a maximum size of 500 bytes, even
             * though it might start out much smaller, pass 500 for minDiskSpace. If
             * Flash asks the user to allot disk space for the shared object, it asks for 500 bytes. After
             * the user allots the requested amount of space, Flash won't have to ask for more space on future
             * attempts to flush the object (as long as its size doesn't exceed 500 bytes). After the user responds to the dialog box, this method is called again. A
             * netStatus event is dispatched with a code property of
             * SharedObject.Flush.Success or SharedObject.Flush.Failed.
             * @param   minDiskSpace    The minimum disk space, in bytes,
             *   that must be allotted for this object.
             * @return  Either of the following values:
             *   SharedObjectFlushStatus.PENDING: The user has permitted local information
             *   storage for objects from this domain, but the
             *   amount of space allotted is not sufficient to store the object. Flash Player prompts
             *   the user to allow more space.
             *   To allow space for the shared object to grow when it is saved, thus avoiding
             *   a SharedObjectFlushStatus.PENDING return value, pass a value
             *   for minDiskSpace.
             *   SharedObjectFlushStatus.FLUSHED: The shared object has been
             *   successfully written to a file on the local disk.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             * @throws  Error Flash Player cannot write the shared object to disk. This error might
             *   occur if the user has permanently disallowed local information storage for
             *   objects from this domain.
             *
             *     Note: Local content can always write shared objects
             *   from third-party domains (domains other than the domain in the current browser address bar)
             *   to disk, even if writing of third-party shared objects to disk is disallowed.
             */
        public:
            std::string flush(int minDiskSpace=0);

        public:
            SharedObject();

            /**
             * Broadcasts a message to all clients connected to a remote shared object,
             * including the client that sent the message. To process and respond to the message,
             * create a callback function attached to the shared object.
             * @param   arguments   One or more arguments: A string that identifies the message,
             *   the name of one or more handler functions to attach to the shared object,
             *   and optional parameters of any type.
             *   The handler name can be only one level deep (that is, it can't be of the
             *   form parent/child) and is relative to the shared object.
             *   The arguments are serialized and sent over the connection, and the
             *   receiving handler receives them in the same order. If a parameter is a
             *   circular object (for example, a linked list that is circular), the
             *   serializer handles the references correctly.
             *
             *     Note: Do not use a reserved term for the function names.
             *   For example, myRemoteSO.send("close") will fail.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             * @internal    Needs better documentation, examples.
             */
        public:
            void     send(...);

            /**
             * For local shared objects, purges all of the data and deletes the shared object from the disk.
             * The reference to the shared object is still active, but its data properties are deleted.
             *
             *   For remote shared objects used with Flash Media Server,
             * clear() disconnects the object and purges
             * all of the data. If the shared object is locally persistent, this method also deletes the shared object
             * from the disk. The reference to the shared object is still active, but its data properties
             * are deleted.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            void     clear();

            /**
             * Indicates to the server that the value of a property
             * in the shared object has changed.
             * This method marks properties as dirty, which means changed.
             *
             *   Call the SharedObject.setProperty() to create properties for a shared object.
             *
             *   The SharedObject.setProperty() method implements setDirty().
             * In most cases, such as when the value of a property is a primitive type like String or Number,
             * you can call setProperty() instead of calling setDirty().
             * However, when the value of a property is an object that contains its own properties,
             * call setDirty() to indicate when a value within the object has changed.
             * @param   propertyName    The name of the property that has changed.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             * @internal    The AS2 player automatically marks properties dirty as they are changed.
             *   The FMS server, however, requires an explicit setProperty() call to indicate when a property
             *   of data has changed.
             *
             *     does not support auto-dirtying the properties, so we are introducing setDirty() to explicitly
             *   indicate when a property has changed, and setProperty() to match the method provided with the server.
             *
             *     It's probably best to read the FMS Actionscript reference (search for SharedObject.setProperty at
             *   www.adobe.com) before writing this documentation, as the details should be similar.
             */
        public:
            void     setDirty(std::string propertyName);

            /**
             * Updates the value of a property in a shared object and indicates to the server
             * that the value of the property has changed. The setProperty() method
             * explicitly marks properties as changed, or dirty.
             *
             *   For more information about remote shared objects see the
             *
             *   Flash Media Server documentation.Note: The SharedObject.setProperty() method implements the setDirty() method.
             * In most cases, such as when the value of a property is a primitive type like String or Number,
             * you would use setProperty() instead of setDirty.
             * However, when the value of a property is an object that contains its own properties,
             * use setDirty() to indicate when a value within the object has changed.
             * In general, it is a good idea to call setProperty() rather than setDirty(), because
             * setProperty() updates a property value only when that value has changed, whereas setDirty()
             * forces synchronization on all subscribed clients.
             * @param   propertyName    The name of the property in the shared object.
             * @param   value   The value of the property (an ActionScript object), or null to delete the property.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            void     setProperty(std::string propertyName, Object *value=NULL);
        };
    }
}

#endif // FLEX11_6_FLASH_NET_SHAREDOBJECT_AS
#endif // __cplusplus

