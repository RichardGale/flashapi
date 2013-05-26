#if !defined(FLEX11_6_FLASH_TEXT_IME_IIMECLIENT_AS)
#define FLEX11_6_FLASH_TEXT_IME_IIMECLIENT_AS
#if defined(__cplusplus)


#include "flex11.6.h"
namespace flash
{
    namespace text
    {
        namespace ime
        {
            class CompositionAttributeRange;
        }
    }
}
namespace flash
{
    namespace geom
    {
        class Rectangle;
    }
}

/**
 * Dispatched when the user enters text.
 * @eventType   flash.events.TextEvent.TEXT_INPUT
 */
//[Event(name="textInput",type="flash.events.TextEvent")]

/**
 * Dispatched when the user begins to use an IME (input method editor).
 * @eventType   flash.events.IMEEvent.IME_START_COMPOSITION
 */
//[Event(name="imeStartComposition",type="flash.events.IMEEvent")]

using namespace flash::geom;
using namespace flash::text::ime;

namespace flash
{
    namespace text
    {
        namespace ime
        {
            /**
             * Interface for IME (input method editor) clients.  Components based on the flash.text.engine package must implement
             * this interface to support editing text inline using an IME. This interface is not used with TextField objects.
             * TextLayoutFramework (TLF) uses this interface to support inline IME, so clients using TLF do not need to implement this
             * interface.
             * <p class="- topic/p ">To support inline IME, set the <codeph class="+ topic/ph pr-d/codeph ">imeClient</codeph> property of an <codeph class="+ topic/ph pr-d/codeph ">ImeEvent.IME_START_COMPOSITION</codeph> event to
             * an object which implements this interface.</p><p class="- topic/p ">The following terms are often used in the IME related API:</p><ul class="- topic/ul "><li class="- topic/li ">A <i class="+ topic/ph hi-d/i ">conversation</i> is the interchange between the IME and the application. During a conversation, a composition is
             * updated one or more times and then confirmed by the user.</li><li class="- topic/li ">A <i class="+ topic/ph hi-d/i ">composition</i> identifies the text entered by the user through the IME; including associated input state information
             * such as the selected range and the extent of any clauses.</li><li class="- topic/li ">A <i class="+ topic/ph hi-d/i ">clause</i> is a range of the composition possibly sharing semantic information, such as indicating whether the input is
             * in a selected or converted state. A composition contains zero or more clauses.</li></ul>
             * @langversion 3.0
             * @playerversion   Flash 10.1
             * @playerversion   AIR 2
             */
            class IIMEClient
            {
                /**
                 * The zero-based character index value of the start of the current edit session text (such as
                 * all text in the inline session that is not confirmed to the document).
                 * @langversion 3.0
                 * @playerversion   Flash 10.1
                 * @playerversion   AIR 2
                 */virtual
                int          compositionStartIndex() = 0;

                /**
                 * The zero-based character index value of the end of the current edit session text (such as
                 * all text in the inline session that is not confirmed to the document).
                 * @langversion 3.0
                 * @playerversion   Flash 10.1
                 * @playerversion   AIR 2
                 */
                virtual
                int          compositionEndIndex() = 0;

                /**
                 * Indicates whether the text in the component is vertical or not. This property directs the positioning
                 * of the candidate window (such as beside vertical text or below horizontal text).
                 * @langversion 3.0
                 * @playerversion   Flash 10.1
                 * @playerversion   AIR 2
                 */
                virtual
                bool      verticalTextLayout() = 0;

                /**
                 * The zero-based character index value of the first character in the current selection.
                 * @langversion 3.0
                 * @playerversion   Flash 10.1
                 * @playerversion   AIR 2
                 */
                virtual
                int          selectionAnchorIndex() = 0;

                /**
                 * The zero-based character index value of the last character in the current selection.
                 * @langversion 3.0
                 * @playerversion   Flash 10.1
                 * @playerversion   AIR 2
                 */
                virtual
                int          selectionActiveIndex() = 0;

                /**
                 * Callback for updating the contents of the inline editing session.
                 * This method is called whenever the text being edited with the IME has changed
                 * and its contents are used by the client to redraw the entire inline editing session.
                 * @param   text    Contains the text of the inline edit session from the IME.
                 * @param   attributes  Contains an array of composition clauses with adornment info.
                 * @param   compositionStartIndex   Start of the inline session relative to the start of the text object.
                 * @param   compositionEndIndex End of the inline session relative to the start of the text object.
                 * @langversion 3.0
                 * @playerversion   Flash 10.1
                 * @playerversion   AIR 2
                 */
                virtual
                void     updateComposition(std::string text, std::vector<flash::text::ime::CompositionAttributeRange *> attributes, int compositionStartIndex, int compositionEndIndex) = 0;

                /**
                 * Use this callback to end the inline editing session and confirm the text.
                 * @param   text    the final state of the text in the inline session (the confirmed text).
                 * @param   preserveSelection   when true, you should not reset the current selection to the end of the confirmed text.
                 * @langversion 3.0
                 * @playerversion   Flash 10.1
                 * @playerversion   AIR 2
                 */
                virtual
                void     confirmComposition(std::string text="", bool preserveSelection=false) = 0;

                /**
                 * The IME uses this method to query the bounding box of the text currently edited with the IME client.
                 * Use this method to place the candidate window and set the mouse cursor in the IME client when the mouse is over the
                 * text field or other component that supports IME.
                 * @param   startIndex  An integer that specifies the starting location of the range of text from the bounding box you are measuring.
                 * @param   endIndex    Optional; an integer that specifies the ending location of the range of text from the bounding box you are measuring.
                 * @return  The bounding box of the specified range of text, or null if one or both of the indexes are invalid.
                 *   This method returns the same value if startIndex is greater or less than endIndex. The same value should be returned whether or not startIndex is greater or less than endIndex.
                 * @langversion 3.0
                 * @playerversion   Flash 10.1
                 * @playerversion   AIR 2
                 */
                virtual
                flash::geom::Rectangle *getTextBounds(int startIndex, int endIndex) = 0;

                /**
                 * Sets the range of selected text in the component.
                 * If either of the arguments is out of bounds the selection should not be changed.
                 * @param   anchorIndex The zero-based index value of the character at the anchor end of the selection
                 * @param   activeIndex The zero-based index value of the character at the active end of the selection.
                 * @langversion 3.0
                 * @playerversion   Flash 10.1
                 * @playerversion   AIR 2
                 */
                virtual
                void     selectRange(int anchorIndex, int activeIndex) = 0;

                /**
                 * Gets the specified range of text from the component.  This method is called during IME reconversion.
                 * @param   startIndex  an integer that specifies the starting location of the range of text to be retrieved.
                 * @param   endIndex    an integer that specifies the ending location of the range of text to be retrieved.
                 * @return  The requested text, or null if no text is available in the requested range
                 *   or if either or both of the indexes are invalid.  The same value should be returned
                 *   independant of whether startIndex is greater or less than endIndex.
                 * @langversion 3.0
                 * @playerversion   Flash 10.1
                 * @playerversion   AIR 2
                 */
                virtual
                std::string   getTextInRange(int startIndex, int endIndex) = 0;
            };
        }
    }
}

#endif // FLEX11_6_FLASH_TEXT_IME_IIMECLIENT_AS
#endif // __cplusplus

