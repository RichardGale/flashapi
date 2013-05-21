

#include "IME.h"
#include "flash/events/EventDispatcher.h"

    /**
     * Dispatched when a user has completed an 
     * input method editor (IME) composition 
     * and the reading string is available.
     * @eventType   flash.events.IMEEvent.IME_COMPOSITION
     */

using namespace flash::events;

namespace flash {
namespace system {


        /**
         * Indicates whether the system IME is enabled (true) or disabled (false). 
         * An enabled IME performs multibyte input; a disabled IME performs alphanumeric input.
         * @langversion 3.0
         * @playerversion   Flash 9
         * @throws  Error A set attempt was not successful.
         */
        bool IME::enabled()          ;
        void IME::enabled(bool enabled)       ;

        /**
         * The conversion mode of the current IME.
         * Possible values are IME mode string constants that indicate the conversion mode:
         * ALPHANUMERIC_FULLALPHANUMERIC_HALFCHINESEJAPANESE_HIRAGANAJAPANESE_KATAKANA_FULLJAPANESE_KATAKANA_HALFKOREANUNKNOWN (read-only value; this value cannot be set)
         * @langversion 3.0
         * @playerversion   Flash 9
         * @throws  Error A set attempt was not successful.
         */
        std::string IME::conversionMode()         ;
        void IME::conversionMode(std::string mode)       ;

        /**
         * The isSupported property is set to true if the IME class is 
         * available on the current platform, otherwise it is set to false.
         * @langversion 3.0
         * @playerversion   Flash 10.1
         * @playerversion   AIR 2
         */
        bool IME::isSupported()          ;

        IME::IME();

        /**
         * Sets the IME composition string. When this string is set, the user 
         * can select IME candidates before committing the result to the text 
         * field that currently has focus.
         * If no text field has focus, this method fails and throws an error.
         * @param   composition The string to send to the IME.
         * @langversion 3.0
         * @playerversion   Flash 9
         * @internal    Need some examples of valid values for the param composition.
         * @throws  Error The call is not successful.
         */
        void IME::setCompositionString(std::string composition)       ;

        /**
         * Instructs the IME to select the first candidate for the current composition string.
         * @langversion 3.0
         * @playerversion   Flash 9
         * @throws  Error The call was not successful.
         */
        void IME::doConversion()       ;

        /**
         * Call this method when the selection within the composition has been updated, either interactively or 
         * programmatically.
         * @param   start   Specifies the offset in bytes of the start of the selection.
         * @param   end Specifies the offset in bytes of the end of the selection.
         * @langversion 3.0
         * @playerversion   Flash 10.1
         * @playerversion   AIR 2
         */
        void IME::compositionSelectionChanged(int start, int end)       ;

        /**
         * Causes the runtime to abandon any composition that is in progress. Call this method when the user clicks 
         * outside of the composition area or when the interactive object that has focus is being destroyed or reset. 
         * The runtime confirms the composition by calling confirmComposition() in the client. The
         * runtime also resets the IME to inform the operating system that the composition has been abandoned.
         * @langversion 3.0
         * @playerversion   Flash 10.1
         * @playerversion   AIR 2
         */
        void IME::compositionAbandoned()       ;
}
}

