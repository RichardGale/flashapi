#if !defined(FLEX11_6_FLASH_SYSTEM_SYSTEM_AS)
#define FLEX11_6_FLASH_SYSTEM_SYSTEM_AS
#if defined(__cplusplus)


#include "flex11.6.h"
namespace flash
{
    namespace system
    {
        class IME;
    }
}

/**
 * The System class contains properties related to local settings and operations. Among these are <ph class="- topic/ph ">
 * settings for camers and microphones, operations with shared objects and</ph> the use of the Clipboard.
 *
 *   <p class="- topic/p ">Additional properties and methods are in other classes within the flash.system package:
 * the Capabilities class, <ph class="- topic/ph ">the IME class,</ph> and the
 * Security class.</p><p class="- topic/p ">This class contains only static methods and properties. You cannot
 * create new instances of the System class.</p>
 *
 *   EXAMPLE:
 *
 *   The following example shows how to copy information about your system's total memory to the
 * system Clipboard using a call to <codeph class="+ topic/ph pr-d/codeph ">System.totalMemory</codeph> within a call to the
 * <codeph class="+ topic/ph pr-d/codeph ">System.setClipboard()</codeph> method.
 * <codeblock xml:space="preserve" class="+ topic/pre pr-d/codeblock ">
 * package {
 * import flash.display.Sprite;
 * import flash.system.System;
 *
 *   public class SystemExample extends Sprite {
 * public function SystemExample() {
 * System.setClipboard("System.totalMemory: " + System.totalMemory);
 * }
 * }
 * }
 * </codeblock>
 * @langversion 3.0
 * @playerversion   Flash 9
 * @playerversion   Lite 4
 */

using namespace flash::system;

namespace flash
{
    namespace system
    {
        class System : public Object
        {
            /**
             * The currently installed system IME.
             * To register for imeComposition events, call
             * addEventListener() on this instance.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            static flash::system::IME *ime();

            /**
             * The amount of memory (in bytes) currently in use that has been directly allocated by
             * Flash Player or AIR.
             *
             *   This property does not return all memory used by an Adobe AIR application or by
             * the application (such as a browser) containing Flash Player content. The browser or
             * operating system may consume other memory. The System.privateMemory property reflects all memory used by
             * an application.If the amount of memory allocated is greater than the maximum value for a uint object (uint.MAX_VALUE,
             * or 4,294,967,295), then this property is set to 0. The System.totalMemoryNumber property allows
             * larger values.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            static unsigned int         totalMemory();

            /**
             * The amount of memory (in bytes) currently in use that has been directly allocated by
             * Flash Player or AIR.
             *
             *   This property is expressed as a Number, which allows higher values than the
             * System.totalMemory property, which is of type int.This property does not return all memory used by an Adobe AIR application or by
             * the application (such as a browser) containing Flash Player content. The browser or
             * operating system may consume other memory. The System.privateMemory property reflects all memory used by
             * an application.
             * @langversion 3.0
             * @playerversion   Flash 10.1
             * @playerversion   AIR 2
             */
        public:
            static float       totalMemoryNumber();

            /**
             * The amount of memory (in bytes) that is allocated to
             * Adobe   Flash   Player or
             * Adobe   AIR   and that is not in use. This unused portion of
             * allocated memory (System.totalMemory) fluctuates as garbage collection takes place.
             * Use this property to monitor garbage collection.
             * @langversion 3.0
             * @playerversion   Flash 10.1
             * @playerversion   AIR 2
             */
        public:
            static float       freeMemory();

            /**
             * The entire amount of memory (in bytes) used by an application. This is the amount of resident private memory for the entire process.
             *
             *   AIR developers should use this property to determine the entire memory consumption of an application.For Flash Player, this includes the memory used by the container application,
             * such as the web browser.
             * @langversion 3.0
             * @playerversion   Flash 10.1
             * @playerversion   AIR 2
             */
        public:
            static float       privateMemory();

        public:
            static float       processCPUUsage();

            /**
             * A Boolean value that determines which code page to use to interpret external text files.
             * When the property is set to false, external text files are interpretted as Unicode.
             * (These files must be encoded as Unicode when you save them.) When the property is set to
             * true, external text files are interpretted using the traditional code page of the
             * operating system running the application. The default value of useCodePage is false.
             *
             *   Text that you load as an external file (using Loader.load(), the URLLoader class or
             * URLStream) must have been saved as Unicode in order for the application to recognize it
             * as Unicode. To encode external files as Unicode, save the files in an application that
             * supports Unicode, such as Notepad on Windows.If you load external text files that are not Unicode-encoded, set useCodePage to true.
             * Add the following as the first line of code of the file that
             * is loading the data (for Flash Professional, add it to the first frame):System.useCodePage = true;When this code is present, the application interprets external text
             * using the traditional code page of the operating system.
             * For example, this is generally CP1252 for an English Windows operating
             * system and Shift-JIS for a Japanese operating system.If you set useCodePage to true,
             * Flash Player 6 and later treat text as Flash Player 5 does. (Flash Player 5
             * treated all text as if it were in the traditional code page of the operating
             * system running the player.)If you set useCodePage to true, remember that the
             * traditional code page of the operating system running the application must include
             * the characters used in your external text file in order to display your text.
             * For example, if you load an external text file that contains Chinese characters,
             * those characters cannot display on a system that uses the CP1252 code page because
             * that code page does not include Chinese characters.To ensure that users on all platforms can view external text files used in your
             * application, you should encode all external text files as Unicode and leave
             * useCodePage set to false. This way, the application
             * (Flash Player 6 and later, or AIR) interprets the text as Unicode.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            static bool      useCodePage();
        public:
            static void         useCodePage(bool value);

        public:
            static std::string       vmVersion();

            /**
             * Replaces the contents of the Clipboard with a specified text string. This method works from any security
             * context when called as a result of a user event (such as a keyboard or input device event handler).
             *
             *   This method is provided for SWF content running in Flash Player 9. It allows only adding
             * String content to the Clipboard.Flash Player 10 content and content in the application security sandbox in an AIR application can call
             * the Clipboard.setData() method.
             * @param   string  A plain-text string of characters to put on the system Clipboard, replacing its current contents (if any).
             * @langversion 3.0
             * @playerversion   Flash 9
             */
        public:
            static void     setClipboard(std::string string);

        public:
            System();

            /**
             * Pauses Flash Player or the AIR Debug Launcher (ADL).
             * After calling this method, nothing in the application continues except the delivery of Socket events.
             *
             *   For the Flash Player debugger version or the AIR Debug Launcher (ADL) only.
             * @langversion 3.0
             * @playerversion   Flash 9.0.115.0
             * @playerversion   Lite 4
             */
        public:
            static void     pause();

            /**
             * Resumes the application after calling System.pause().
             *
             *   For the Flash Player debugger version or the AIR Debug Launcher (ADL) only.
             * @langversion 3.0
             * @playerversion   Flash 9.0.115.0
             * @playerversion   Lite 4
             */
        public:
            static void     resume();

            /**
             * Closes Flash Player.
             *
             *   For the standalone Flash Player debugger version only.AIR applications should call the NativeApplication.exit() method to exit the application.
             * @param   code    A value to pass to the operating system. Typically, if
             *   the process exits normally, the value is 0.
             * @langversion 3.0
             * @playerversion   Flash 9.0.115.0
             */
        public:
            static void     exit(unsigned int code);

            /**
             * Forces the garbage collection process.
             *
             *   For the Flash Player debugger version and AIR applications only.
             * In an AIR application, the System.gc() method is only enabled in content running in the AIR Debug Launcher
             * (ADL) or, in an installed applcation, in content in the application security sandbox.
             * @langversion 3.0
             * @playerversion   Flash 9.0.115.0
             * @playerversion   Lite 4
             */
        public:
            static void     gc();

        public:
            static void     pauseForGCIfCollectionImminent(float imminence=0.75);

            /**
             * Makes the specified XML object immediately available for garbage collection.
             * This method will remove parent and child connections between all the nodes
             * for the specified XML node.
             * @param   node    XML reference that should be made available for garbage collection.
             * @langversion 3.0
             * @playerversion   Flash 10.1
             * @playerversion   AIR 1.5.2
             */
        public:
            static void     disposeXML(XML *node);
        };
    }
}

#endif // FLEX11_6_FLASH_SYSTEM_SYSTEM_AS
#endif // __cplusplus

