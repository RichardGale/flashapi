#if !defined(FLEX11_6_FLASH_SYSTEM_CAPABILITIES_AS)
#define FLEX11_6_FLASH_SYSTEM_CAPABILITIES_AS
#if defined(__cplusplus)


/**
 * <ph class="- topic/ph ">The Capabilities class provides properties that
 * describe the system and runtime that are hosting the application.
 * For example, a mobile phone's screen might be 100 square
 * pixels, black and white, whereas a PC screen might be 1000 square pixels, color.
 * By using the Capabilities class to determine what capabilities the client has,
 * you can provide appropriate content to as many users as possible. When you know
 * the device's capabilities, you can tell the server to send the appropriate SWF
 * files or tell the SWF file to alter its presentation.</ph><p class="- topic/p ">However, some capabilities of Adobe AIR are not listed as properties in the
 * Capabilities class. They are properties of other classes:</p><adobetable class="innertable"><tgroup cols="2" class="- topic/tgroup "><thead class="- topic/thead "><row class="- topic/row "><entry class="- topic/entry ">Property</entry><entry class="- topic/entry ">Description</entry></row></thead><tbody class="- topic/tbody "><row class="- topic/row "><entry class="- topic/entry "><codeph class="+ topic/ph pr-d/codeph ">NativeApplication.supportsDockIcon</codeph></entry><entry class="- topic/entry ">Whether the operating system supports application doc icons.</entry></row><row class="- topic/row "><entry class="- topic/entry "><codeph class="+ topic/ph pr-d/codeph ">NativeApplication.supportsMenu</codeph></entry><entry class="- topic/entry ">Whether the operating system supports a global application menu bar.</entry></row><row class="- topic/row "><entry class="- topic/entry "><codeph class="+ topic/ph pr-d/codeph ">NativeApplication.supportsSystemTrayIcon</codeph></entry><entry class="- topic/entry ">Whether the operating system supports system tray icons.</entry></row><row class="- topic/row "><entry class="- topic/entry "><codeph class="+ topic/ph pr-d/codeph ">NativeWindow.supportsMenu</codeph></entry><entry class="- topic/entry ">Whether the operating system supports window menus.</entry></row><row class="- topic/row "><entry class="- topic/entry "><codeph class="+ topic/ph pr-d/codeph ">NativeWindow.supportsTransparency</codeph></entry><entry class="- topic/entry ">Whether the operating system supports transparent windows.</entry></row></tbody></tgroup></adobetable><p class="- topic/p ">Do <i class="+ topic/ph hi-d/i ">not</i> use <codeph class="+ topic/ph pr-d/codeph ">Capabilities.os</codeph> or <codeph class="+ topic/ph pr-d/codeph ">Capabilities.manufacturer</codeph> to
 * determine a capability based on the operating system. Basing a capability on the operating system
 * is a bad idea, since it can lead to problems if an application does not consider all potential
 * target operating systems. Instead, use the property corresponding to the capability for which you
 * are testing.</p><p class="- topic/p ">You can send capabilities information, which is stored in the
 * <codeph class="+ topic/ph pr-d/codeph ">Capabilities.serverString</codeph> property as a URL-encoded string, using the
 * <codeph class="+ topic/ph pr-d/codeph ">GET</codeph> or <codeph class="+ topic/ph pr-d/codeph ">POST</codeph> HTTP method. The following example shows a server
 * string for a computer that has MP3 support and 1600 x 1200 pixel resolution and that is
 * running Windows XP with an input method editor (IME) installed:</p><pre xml:space="preserve" class="- topic/pre ">A=t&amp;SA=t&amp;SV=t&amp;EV=t&amp;MP3=t&amp;AE=t&amp;VE=t&amp;ACC=f&amp;PR=t&amp;SP=t&amp;
 * SB=f&amp;DEB=t&amp;V=WIN%209%2C0%2C0%2C0&amp;M=Adobe%20Windows&amp;
 * R=1600x1200&amp;DP=72&amp;COL=color&amp;AR=1.0&amp;OS=Windows%20XP&amp;
 * L=en&amp;PT=External&amp;AVD=f&amp;LFD=f&amp;WD=f&amp;IME=t</pre><p class="- topic/p ">The following table lists the properties of the Capabilities class and corresponding server strings:
 * <adobetable class="innertable"><tgroup cols="2" class="- topic/tgroup "><thead class="- topic/thead "><row class="- topic/row "><entry align="left" class="- topic/entry ">Capabilities class property</entry><entry align="left" class="- topic/entry ">Server string</entry></row></thead><tbody class="- topic/tbody "><row class="- topic/row "><entry class="- topic/entry "><codeph class="+ topic/ph pr-d/codeph ">avHardwareDisable</codeph></entry><entry class="- topic/entry "><codeph class="+ topic/ph pr-d/codeph ">AVD</codeph></entry></row><row class="- topic/row "><entry class="- topic/entry "><codeph class="+ topic/ph pr-d/codeph ">hasAccessibility</codeph></entry><entry class="- topic/entry "><codeph class="+ topic/ph pr-d/codeph ">ACC</codeph></entry></row><row class="- topic/row "><entry class="- topic/entry "><codeph class="+ topic/ph pr-d/codeph ">hasAudio</codeph></entry><entry class="- topic/entry "><codeph class="+ topic/ph pr-d/codeph ">A</codeph></entry></row><row class="- topic/row "><entry class="- topic/entry "><codeph class="+ topic/ph pr-d/codeph ">hasAudioEncoder</codeph></entry><entry class="- topic/entry "><codeph class="+ topic/ph pr-d/codeph ">AE</codeph></entry></row><row class="- topic/row "><entry class="- topic/entry "><codeph class="+ topic/ph pr-d/codeph ">hasEmbeddedVideo</codeph></entry><entry class="- topic/entry "><codeph class="+ topic/ph pr-d/codeph ">EV</codeph></entry></row><row class="- topic/row "><entry class="- topic/entry "><codeph class="+ topic/ph pr-d/codeph ">hasIME</codeph></entry><entry class="- topic/entry "><codeph class="+ topic/ph pr-d/codeph ">IME</codeph></entry></row><row class="- topic/row "><entry class="- topic/entry "><codeph class="+ topic/ph pr-d/codeph ">hasMP3</codeph></entry><entry class="- topic/entry "><codeph class="+ topic/ph pr-d/codeph ">MP3</codeph></entry></row><row class="- topic/row "><entry class="- topic/entry "><codeph class="+ topic/ph pr-d/codeph ">hasPrinting</codeph></entry><entry class="- topic/entry "><codeph class="+ topic/ph pr-d/codeph ">PR</codeph></entry></row><row class="- topic/row "><entry class="- topic/entry "><codeph class="+ topic/ph pr-d/codeph ">hasScreenBroadcast</codeph></entry><entry class="- topic/entry "><codeph class="+ topic/ph pr-d/codeph ">SB</codeph></entry></row><row class="- topic/row "><entry class="- topic/entry "><codeph class="+ topic/ph pr-d/codeph ">hasScreenPlayback</codeph></entry><entry class="- topic/entry "><codeph class="+ topic/ph pr-d/codeph ">SP</codeph></entry></row><row class="- topic/row "><entry class="- topic/entry "><codeph class="+ topic/ph pr-d/codeph ">hasStreamingAudio</codeph></entry><entry class="- topic/entry "><codeph class="+ topic/ph pr-d/codeph ">SA</codeph></entry></row><row class="- topic/row "><entry class="- topic/entry "><codeph class="+ topic/ph pr-d/codeph ">hasStreamingVideo</codeph></entry><entry class="- topic/entry "><codeph class="+ topic/ph pr-d/codeph ">SV</codeph></entry></row><row class="- topic/row "><entry class="- topic/entry "><codeph class="+ topic/ph pr-d/codeph ">hasTLS</codeph></entry><entry class="- topic/entry "><codeph class="+ topic/ph pr-d/codeph ">TLS</codeph></entry></row><row class="- topic/row "><entry class="- topic/entry "><codeph class="+ topic/ph pr-d/codeph ">hasVideoEncoder</codeph></entry><entry class="- topic/entry "><codeph class="+ topic/ph pr-d/codeph ">VE</codeph></entry></row><row class="- topic/row "><entry class="- topic/entry "><codeph class="+ topic/ph pr-d/codeph ">isDebugger</codeph></entry><entry class="- topic/entry "><codeph class="+ topic/ph pr-d/codeph ">DEB</codeph></entry></row><row class="- topic/row "><entry class="- topic/entry "><codeph class="+ topic/ph pr-d/codeph ">language</codeph></entry><entry class="- topic/entry "><codeph class="+ topic/ph pr-d/codeph ">L</codeph></entry></row><row class="- topic/row "><entry class="- topic/entry "><codeph class="+ topic/ph pr-d/codeph ">localFileReadDisable</codeph></entry><entry class="- topic/entry "><codeph class="+ topic/ph pr-d/codeph ">LFD</codeph></entry></row><row class="- topic/row "><entry class="- topic/entry "><codeph class="+ topic/ph pr-d/codeph ">manufacturer</codeph></entry><entry class="- topic/entry "><codeph class="+ topic/ph pr-d/codeph ">M</codeph></entry></row><row class="- topic/row "><entry class="- topic/entry "><codeph class="+ topic/ph pr-d/codeph ">maxLevelIDC</codeph></entry><entry class="- topic/entry "><codeph class="+ topic/ph pr-d/codeph ">ML</codeph></entry></row><row class="- topic/row "><entry class="- topic/entry "><codeph class="+ topic/ph pr-d/codeph ">os</codeph></entry><entry class="- topic/entry "><codeph class="+ topic/ph pr-d/codeph ">OS</codeph></entry></row><row class="- topic/row "><entry class="- topic/entry "><codeph class="+ topic/ph pr-d/codeph ">pixelAspectRatio</codeph></entry><entry class="- topic/entry "><codeph class="+ topic/ph pr-d/codeph ">AR</codeph></entry></row><row class="- topic/row "><entry class="- topic/entry "><codeph class="+ topic/ph pr-d/codeph ">playerType</codeph></entry><entry class="- topic/entry "><codeph class="+ topic/ph pr-d/codeph ">PT</codeph></entry></row><row class="- topic/row "><entry class="- topic/entry "><codeph class="+ topic/ph pr-d/codeph ">screenColor</codeph></entry><entry class="- topic/entry "><codeph class="+ topic/ph pr-d/codeph ">COL</codeph></entry></row><row class="- topic/row "><entry class="- topic/entry "><codeph class="+ topic/ph pr-d/codeph ">screenDPI</codeph></entry><entry class="- topic/entry "><codeph class="+ topic/ph pr-d/codeph ">DP</codeph></entry></row><row class="- topic/row "><entry class="- topic/entry "><codeph class="+ topic/ph pr-d/codeph ">screenResolutionX</codeph></entry><entry class="- topic/entry "><codeph class="+ topic/ph pr-d/codeph ">R</codeph></entry></row><row class="- topic/row "><entry class="- topic/entry "><codeph class="+ topic/ph pr-d/codeph ">screenResolutionY</codeph></entry><entry class="- topic/entry "><codeph class="+ topic/ph pr-d/codeph ">R</codeph></entry></row><row class="- topic/row "><entry class="- topic/entry "><codeph class="+ topic/ph pr-d/codeph ">version</codeph></entry><entry class="- topic/entry "><codeph class="+ topic/ph pr-d/codeph ">V</codeph></entry></row></tbody></tgroup></adobetable></p><p class="- topic/p ">There is also a <codeph class="+ topic/ph pr-d/codeph ">WD</codeph> server string that specifies whether windowless mode is disabled. Windowless mode
 * can be disabled in Flash Player due to incompatibility with the web browser or to a user setting in the mms.cfg file.
 * There is no corresponding Capabilities property.</p><p class="- topic/p ">All properties of the Capabilities class are read-only.</p>
 *
 *   EXAMPLE:
 *
 *   The following example outputs the values found in the
 * flash.system.Capabilities object. First, it outputs the values into a text field.
 * Then, it outputs the values using several calls to <codeph class="+ topic/ph pr-d/codeph ">trace()</codeph>.
 * <codeblock xml:space="preserve" class="+ topic/pre pr-d/codeblock ">
 *
 *   package {
 * import flash.display.Sprite;
 * import flash.system.Capabilities;
 * import flash.text.TextField;
 * import flash.text.TextFieldAutoSize;
 *
 *   public class CapabilitiesExample extends Sprite {
 *
 *   public function CapabilitiesExample() {
 * showCapabilities();
 * }
 *
 *   private function showCapabilities():void {
 * var tf:TextField = new TextField();
 * tf.height = 600;
 * tf.width = 400;
 * tf.autoSize = TextFieldAutoSize.LEFT;
 * tf.wordWrap = true;
 *
 *   tf.text = "avHardwareDisable: " + Capabilities.avHardwareDisable +
 *
 *   "\nhasAccessibility: " + Capabilities.hasAccessibility +
 * "\nhasAudio: " + Capabilities.hasAudio +
 * "\nhasAudioEncoder: " + Capabilities.hasAudioEncoder +
 * "\nhasEmbeddedVideo: " + Capabilities.hasEmbeddedVideo +
 * "\nhasIME: " + Capabilities.hasIME +
 * "\nhasMP3: " + Capabilities.hasMP3 +
 * "\nhasPrinting: " + Capabilities.hasPrinting +
 * "\nhasScreenBroadcast: " + Capabilities.hasScreenBroadcast +
 * "\nhasScreenPlayback: " + Capabilities.hasScreenPlayback +
 * "\nhasStreamingAudio: " + Capabilities.hasStreamingAudio +
 * "\nhasStreamingVideo: " + Capabilities.hasStreamingVideo +
 * "\nhasTLS: " + Capabilities.hasTLS +
 * "\nhasVideoEncoder: " + Capabilities.hasVideoEncoder +
 * "\nisDebugger: " + Capabilities.isDebugger +
 * "\nisEmbeddedInAcrobat: " + Capabilities.isEmbeddedInAcrobat +
 * "\nlanguage: " + Capabilities.language +
 * "\nlocalFileReadDisable: " + Capabilities.localFileReadDisable +
 * "\nmanufacturer: " + Capabilities.manufacturer +
 * "\nmaxLevelIDC: " + Capabilities.maxLevelIDC +
 * "\nos: " + Capabilities.os +
 * "\npixelAspectRatio: " + Capabilities.pixelAspectRatio +
 * "\nplayerType: " + Capabilities.playerType +
 * "\nscreenColor: " + Capabilities.screenColor +
 * "\nscreenDPI: " + Capabilities.screenDPI +
 * "\nscreenResolutionX: " + Capabilities.screenResolutionX +
 * "\nscreenResolutionY: " + Capabilities.screenResolutionY +
 * "\nserverString: " + Capabilities.serverString +
 * "\ntouchscreenType: " + Capabilities.touchscreenType +
 *
 *   // The following capabilities are supported only when publishing for AIR.
 * // If you are publishing for AIR, uncomment the following lines.
 * //"\nlanguages: " + Capabilities.languages +
 * //"\ncpuArchitecture: " + Capabilities.cpuArchitecture +
 * //"\nsupports32BitProcesses: " + Capabilities.supports32BitProcesses +
 * //"\nsupports64BitProcesses: " + Capabilities.supports64BitProcesses +
 *
 *   "\nversion: " + Capabilities.version;
 *
 *   addChild(tf);
 *
 *   trace("avHardwareDisable: " + Capabilities.avHardwareDisable);
 * trace("hasAccessibility: " + Capabilities.hasAccessibility);
 * trace("hasAudio: " + Capabilities.hasAudio);
 * trace("hasAudioEncoder: " + Capabilities.hasAudioEncoder);
 * trace("hasEmbeddedVideo: " + Capabilities.hasEmbeddedVideo);
 * trace("hasIME: " + Capabilities.hasIME);
 * trace("hasMP3: " + Capabilities.hasMP3);
 * trace("hasPrinting: " + Capabilities.hasPrinting);
 * trace("hasScreenBroadcast: " + Capabilities.hasScreenBroadcast);
 * trace("hasScreenPlayback: " + Capabilities.hasScreenPlayback);
 * trace("hasStreamingAudio: " + Capabilities.hasStreamingAudio);
 * trace("hasStreamingVideo: " + Capabilities.hasStreamingVideo);
 * trace("hasTLS: " + Capabilities.hasTLS);
 * trace("hasVideoEncoder: " + Capabilities.hasVideoEncoder);
 * trace("isDebugger: " + Capabilities.isDebugger);
 * trace("isEmbeddedInAcrobat: " + Capabilities.isEmbeddedInAcrobat);
 * trace("language: " + Capabilities.language);
 * trace("localFileReadDisable: " + Capabilities.localFileReadDisable);
 * trace("manufacturer: " + Capabilities.manufacturer);
 * trace("maxLevelIDC: " + Capabilities.maxLevelIDC);
 * trace("os: " + Capabilities.os);
 * trace("pixelAspectRatio: " + Capabilities.pixelAspectRatio);
 * trace("playerType: " + Capabilities.playerType);
 * trace("screenColor: " + Capabilities.screenColor);
 * trace("screenDPI: " + Capabilities.screenDPI);
 * trace("screenResolutionX: " + Capabilities.screenResolutionX);
 * trace("screenResolutionY: " + Capabilities.screenResolutionY);
 * trace("serverString: " + Capabilities.serverString);
 * trace("touchscreenType: " + Capabilities.touchscreenType);
 *
 *   // The following capabilities are supported only when publishing for AIR.
 * // If you are publishing for AIR, uncomment the following lines.
 * //trace("cpuArchitecture: " + Capabilities.cpuArchitecture);
 * //trace("languages: " + Capabilities.languages);
 * //trace("supports32BitProcesses: " + Capabilities.supports32BitProcesses);
 * //trace("supports64BitProcesses: " + Capabilities.supports64BitProcesses);
 *
 *   trace("version: " + Capabilities.version);
 *
 *   }
 * }
 * }
 *
 *   </codeblock>
 * @langversion 3.0
 * @playerversion   Flash 9
 * @playerversion   AIR 1.0
 * @playerversion   Lite 4
 */

#include "flex11.6.h"



namespace flash
{
    namespace system
    {
        class Capabilities : public Object
        {
            /**
             * Specifies whether the Flash runtime is embedded in a PDF file that is open in Acrobat 9.0 or higher
             * (true) or not (false).
             * @langversion 3.0
             * @playerversion   Flash 9.0.127.0
             * @playerversion   AIR 1.1
             * @playerversion   Lite 4
             */
        public:
            static bool      isEmbeddedInAcrobat();

            /**
             * Specifies whether the system supports
             * (true) or does not support (false)
             * embedded video. The server string is EV.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   AIR 1.0
             * @playerversion   Lite 4
             */
        public:
            static bool      hasEmbeddedVideo();

            /**
             * Specifies whether the system has audio
             * capabilities. This property is always true.  The server
             * string is A.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   AIR 1.0
             * @playerversion   Lite 4
             */
        public:
            static bool      hasAudio();

            /**
             * Specifies whether access to the user's camera and microphone has
             * been administratively prohibited (true) or allowed (false).
             * The server string is AVD.
             *
             *   For content in Adobe AIR   , this property applies only to content in security
             * sandboxes other than the application security sandbox. Content in the application
             * security sandbox can always access the user's camera and microphone.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   AIR 1.0
             * @playerversion   Lite 4
             */
        public:
            static bool      avHardwareDisable();

            /**
             * Specifies whether the system supports
             * (true) or does not support (false) communication
             * with accessibility aids.
             * The server string is ACC.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   AIR 1.0
             * @playerversion   Lite 4
             */
        public:
            static bool      hasAccessibility();

            /**
             * Specifies whether the system can (true) or cannot (false)
             * encode an audio stream, such as that coming from a microphone.
             * The server string is AE.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   AIR 1.0
             * @playerversion   Lite 4
             */
        public:
            static bool      hasAudioEncoder();

            /**
             * Specifies whether the system does (true)
             * or does not (false) have an MP3 decoder.
             * The server string is MP3.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   AIR 1.0
             * @playerversion   Lite 4
             */
        public:
            static bool      hasMP3();

            /**
             * Specifies whether the system does (true)
             * or does not (false) support printing.
             * The server string is PR.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   AIR 1.0
             * @playerversion   Lite 4
             */
        public:
            static bool      hasPrinting();

            /**
             * Specifies whether the system does (true) or does not (false)
             * support the development of screen broadcast applications to be run through Flash Media
             * Server.
             * The server string is SB.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   AIR 1.0
             * @playerversion   Lite 4
             */
        public:
            static bool      hasScreenBroadcast();

            /**
             * Specifies whether the system does (true) or does not
             * (false) support the playback of screen broadcast applications
             * that are being run through Flash Media Server.
             * The server string is SP.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   AIR 1.0
             * @playerversion   Lite 4
             */
        public:
            static bool      hasScreenPlayback();

            /**
             * Specifies whether the system can (true) or cannot (false)
             * play streaming audio.
             * The server string is SA.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   AIR 1.0
             * @playerversion   Lite 4
             */
        public:
            static bool      hasStreamingAudio();

            /**
             * Specifies whether the system can (true) or cannot
             * (false) play streaming video.
             * The server string is SV.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   AIR 1.0
             * @playerversion   Lite 4
             */
        public:
            static bool      hasStreamingVideo();

            /**
             * Specifies whether the system can (true) or cannot
             * (false) encode a video stream, such as that coming
             * from a web camera.
             * The server string is VE.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   AIR 1.0
             * @playerversion   Lite 4
             */
        public:
            static bool      hasVideoEncoder();

            /**
             * Specifies whether the system is a special debugging version
             * (true) or an officially released version (false).
             * The server string is DEB. This property is set to true
             * when running in the debug version of Flash Player or
             * the AIR Debug Launcher (ADL).
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   AIR 1.0
             * @playerversion   Lite 4
             */
        public:
            static bool      isDebugger();

            /**
             * Specifies whether read access to the user's hard disk has been
             * administratively prohibited (true) or allowed
             * (false). For content in Adobe AIR, this property
             * applies only to content in security sandboxes other
             * than the application security sandbox. (Content in the application
             * security sandbox can always read from the file system.)
             * If this property is true,
             * Flash Player cannot read files (including the first file that
             * Flash Player launches with) from the user's hard disk.
             * If this property is true, AIR content outside of the
             * application security sandbox cannot read files from the user's
             * hard disk. For example, attempts to read a file on the user's
             * hard disk using load methods will fail if this property
             * is set to true.
             *
             *   Reading runtime shared libraries is also blocked
             * if this property is set to true, but reading local shared objects
             * is allowed without regard to the value of this property.The server string is LFD.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   AIR 1.0
             * @playerversion   Lite 4
             */
        public:
            static bool      localFileReadDisable();

            /**
             * Specifies the language code of the system on which the content is running. The language is
             * specified as a lowercase two-letter language code from ISO 639-1. For Chinese, an additional
             * uppercase two-letter country code from ISO 3166 distinguishes between Simplified and
             * Traditional Chinese. The languages codes are based on the English names of the language: for example,
             * hu specifies Hungarian.
             *
             *   On English systems, this property returns only the language code (en), not
             * the country code. On Microsoft Windows systems, this property returns the user interface (UI)
             * language, which refers to the language used for all menus, dialog boxes, error messages, and help
             * files. The following table lists the possible values:
             *
             *   LanguageValueCzechcsDanishdaDutchnlEnglishenFinnishfiFrenchfrGermandeHungarianhuItalianitJapanesejaKoreankoNorwegiannoOther/unknownxuPolishplPortugueseptRussianruSimplified Chinesezh-CNSpanishesSwedishsvTraditional Chinesezh-TWTurkishtrNote: The value of Capabilities.language property is limited
             * to the possible values on this list. Because of this limitation, Adobe AIR applications
             * should use the first element in the Capabilities.languages
             * array to determine the primary user interface language for the system. The server string is L.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   AIR 1.0
             * @playerversion   Lite 4
             */
        public:
            static std::string       language();

            /**
             * Specifies the manufacturer of the running version of
             * Flash Player or  the AIR runtime, in the format "AdobeOSName". The value for OSName
             * could be "Windows", "Macintosh",
             * "Linux", or another operating system name. The server string is M.
             *
             *   Do not use Capabilities.manufacturer to determine a capability based on
             * the operating system if a more specific capability property exists. Basing a capability on the operating
             * system is a bad idea, since it can lead to problems if an application does not consider all potential
             * target operating systems. Instead, use the property corresponding to the capability for which you
             * are testing. For more information, see the Capabilities class description.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   AIR 1.0
             * @playerversion   Lite 4
             */
        public:
            static std::string       manufacturer();

            /**
             * Specifies the current operating system. The os property
             * can return the following strings:
             *
             *   Operating systemValueWindows 7"Windows 7"Windows Vista"Windows Vista"Windows Server 2008 R2"Windows Server 2008 R2"Windows Server 2008"Windows Server 2008"Windows Home Server"Windows Home Server"Windows Server 2003 R2"Windows Server 2003 R2"Windows Server 2003"Windows Server 2003"Windows XP 64"Windows Server XP 64"Windows XP"Windows XP"Windows 98"Windows 98"Windows 95"Windows 95"Windows NT"Windows NT"Windows 2000"Windows 2000"Windows ME"Windows ME"Windows CE"Windows CE"Windows SmartPhone"Windows SmartPhone"Windows PocketPC"Windows PocketPC"Windows CEPC"Windows CEPC"Windows Mobile"Windows Mobile"Mac OS"Mac OS X.Y.Z" (where X.Y.Z is the version number, for example:
             * "Mac OS 10.5.2")Linux"Linux" (Flash Player attaches the Linux version, such as "Linux 2.6.15-1.2054_FC5smp"iPhone OS 4.1"iPhone3,1"The server string is OS.Do not use Capabilities.os to determine a capability based on
             * the operating system if a more specific capability property exists. Basing a capability on the operating
             * system is a bad idea, since it can lead to problems if an application does not consider all potential
             * target operating systems. Instead, use the property corresponding to the capability for which you
             * are testing. For more information, see the Capabilities class description.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   AIR 1.0
             * @playerversion   Lite 4
             */
        public:
            static std::string       os();

            /**
             * Specifies the current CPU architecture. The cpuArchitecture property
             * can return the following strings: "PowerPC", "x86",
             * "SPARC", and "ARM".
             * The server string is ARCH.
             * @langversion 3.0
             * @playerversion   Flash 10.0.32
             * @playerversion   AIR 1.5.1
             * @oldexample  The following example traces the value of this read-only property:
             *   <pre xml:space="preserve" class="- topic/pre ">
             *   trace(Capabilities.cpuArchitecture);
             *   </pre>
             */
        public:
            static std::string       cpuArchitecture();

            /**
             * Specifies the type of runtime environment. This property can have one of the following
             * values:
             *
             *   "ActiveX" for the Flash Player ActiveX control used by Microsoft Internet Explorer"Desktop" for the Adobe AIR runtime (except for SWF content loaded by an HTML page, which
             * has Capabilities.playerType set to "PlugIn")"External" for the external Flash Player or in test mode"PlugIn" for the Flash Player browser plug-in (and for SWF content loaded by
             * an HTML page in an AIR application)"StandAlone" for the stand-alone Flash PlayerThe server string is PT.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   AIR 1.0
             * @playerversion   Lite 4
             */
        public:
            static std::string       playerType();

            /**
             * A URL-encoded string that specifies values for each Capabilities
             * property.
             *
             *   The following example shows a URL-encoded string:
             * A=t&SA=t&SV=t&EV=t&MP3=t&AE=t&VE=t&ACC=f&PR=t&SP=t&
             * SB=f&DEB=t&V=WIN%208%2C5%2C0%2C208&M=Adobe%20Windows&
             * R=1600x1200&DP=72&COL=color&AR=1.0&OS=Windows%20XP&
             * L=en&PT=External&AVD=f&LFD=f&WD=f
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   AIR 1.0
             * @playerversion   Lite 4
             */
        public:
            static std::string       serverString();

            /**
             * Specifies the Flash Player or Adobe   AIR
             * platform and version information. The format of the version number is:
             * platform majorVersion,minorVersion,buildNumber,internalBuildNumber.
             * Possible values for platform are "WIN", `
             * "MAC", "LNX", and "AND". Here are some
             * examples of version information:
             *
             *   WIN 9,0,0,0  // Flash Player 9 for Windows
             * MAC 7,0,25,0   // Flash Player 7 for Macintosh
             * LNX 9,0,115,0  // Flash Player 9 for Linux
             * AND 10,2,150,0 // Flash Player 10 for Android
             * Do not use Capabilities.version to determine a capability based on
             * the operating system if a more specific capability property exists. Basing a capability on the operating
             * system is a bad idea, since it can lead to problems if an application does not consider all potential
             * target operating systems. Instead, use the property corresponding to the capability for which you
             * are testing. For more information, see the Capabilities class description.The server string is V.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   AIR 1.0
             * @playerversion   Lite 4
             */
        public:
            static std::string       version();

            /**
             * Specifies the screen color. This property can have the value
             * "color", "gray" (for grayscale), or
             * "bw" (for black and white).
             * The server string is COL.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   AIR 1.0
             * @playerversion   Lite 4
             */
        public:
            static std::string       screenColor();

            /**
             * Specifies the pixel aspect ratio of the screen. The server string
             * is AR.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   AIR 1.0
             * @playerversion   Lite 4
             */
        public:
            static float       pixelAspectRatio();

            /**
             * Specifies the dots-per-inch (dpi) resolution of the screen, in pixels.
             * The server string is DP.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   AIR 1.0
             * @playerversion   Lite 4
             */
        public:
            static float       screenDPI();

            /**
             * Specifies the maximum horizontal resolution of the screen.
             * The server string is R (which returns both the width and height of the screen).
             * This property does not update with a user's screen resolution and instead only indicates the resolution
             * at the time Flash Player or  an Adobe AIR application started.
             * Also, the value only specifies the primary screen.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   AIR 1.0
             * @playerversion   Lite 4
             */
        public:
            static float       screenResolutionX();

            /**
             * Specifies the maximum vertical resolution of the screen.
             * The server string is R (which returns both the width and height of the screen).
             * This property does not update with a user's screen resolution and instead only indicates the resolution
             * at the time Flash Player or  an Adobe AIR application started.
             * Also, the value only specifies the primary screen.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   AIR 1.0
             * @playerversion   Lite 4
             */
        public:
            static float       screenResolutionY();

            /**
             * Specifies the type of touchscreen supported, if any. Values are defined in the flash.system.TouchscreenType class.
             * @langversion 3.0
             * @playerversion   Flash 10.1
             * @playerversion   AIR 2
             */
        public:
            static std::string       touchscreenType();

            /**
             * Specifies whether the system does (true)
             * or does not (false) have an input method editor (IME) installed.
             * The server string is IME.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   AIR 1.0
             * @playerversion   Lite 4
             */
        public:
            static bool      hasIME();

            /**
             * Specifies whether the system supports native SSL sockets through NetConnection
             * (true) or does not (false).
             * The server string is TLS.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   AIR 1.0
             * @playerversion   Lite 4
             */
        public:
            static bool      hasTLS();

            /**
             * Retrieves the highest H.264 Level IDC that the client hardware supports.
             * Media run at this level are guaranteed to run; however, media run at
             * the highest level might not run with the highest quality.
             * This property is useful for servers trying to target a client's capabilities.
             * Using this property, a server can determine the level of video to send to the client.
             *
             *   The server string is ML.
             * @langversion 3.0
             * @playerversion   Flash 10
             * @playerversion   AIR 1.5
             * @playerversion   Lite 4
             */
        public:
            static std::string       maxLevelIDC();

            /**
             * Specifies whether the system supports running 32-bit processes.
             * The server string is PR32.
             * @langversion 3.0
             * @playerversion   Flash 10.0.32
             * @playerversion   AIR 1.5.2
             * @oldexample  The following example traces the value of this read-only property:
             *   <pre xml:space="preserve" class="- topic/pre ">
             *   trace(Capabilities.supports32BitProcesses);
             *   </pre>
             */
        public:
            static bool      supports32BitProcesses();

            /**
             * Specifies whether the system supports running 64-bit processes.
             * The server string is PR64.
             * @langversion 3.0
             * @playerversion   Flash 10.0.32
             * @playerversion   AIR 1.5.2
             * @oldexample  The following example traces the value of this read-only property:
             *   <pre xml:space="preserve" class="- topic/pre ">
             *   trace(Capabilities.supports64BitProcesses);
             *   </pre>
             */
        public:
            static bool      supports64BitProcesses();

        public:
            static unsigned int         _internal();

        public:
            Capabilities();

        public:
            static bool  hasMultiChannelAudio(std::string type);
        };
    }
}

#endif // FLEX11_6_FLASH_SYSTEM_CAPABILITIES_AS
#endif // __cplusplus

