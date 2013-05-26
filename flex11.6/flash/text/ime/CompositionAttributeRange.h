#if !defined(FLEX11_6_FLASH_TEXT_IME_COMPOSITIONATTRIBUTERANGE_AS)
#define FLEX11_6_FLASH_TEXT_IME_COMPOSITIONATTRIBUTERANGE_AS
#if defined(__cplusplus)


/**
 * The CompositionAttributeRange class represents a range of composition attributes for use with IME (input method editor) events.
 * For example, when editing text in the IME, the text is divided by the IME into composition ranges.
 * These composition ranges are flagged as selected (such as currently being lengthened, shortened, or edited),
 * and/or converted (meaning the range went through the IME dictionary lookup, already).
 *
 *   <p class="- topic/p ">By convention, the client should adorn these composition ranges with underlining or highlighting according to
 * the flags.</p><p class="- topic/p ">For example:</p><codeblock xml:space="preserve" class="+ topic/pre pr-d/codeblock ">
 * !converted              = thick gray underline (raw text)
 * !selected &amp;&amp; converted  = thin black underline
 * selected &amp;&amp; converted  = thick black underline
 * </codeblock>
 * @langversion 3.0
 * @playerversion   Flash 10.1
 * @playerversion   AIR 2
 */

#include "flex11.6.h"



namespace flash
{
    namespace text
    {
        namespace ime
        {
            class CompositionAttributeRange : public Object
            {
                /**
                 * The relative start position from the beginning of the current inline editing session.
                 * For example, 0 equals the start of the text the IME reads (however, text might exist
                 * before that position in the edit field).
                 * @langversion 3.0
                 * @playerversion   Flash 10.1
                 * @playerversion   AIR 2
                 */
            public:
                int relativeStart;

                /**
                 * The position of the end of the composition clause, relative to the beginning
                 * of the inline edit session.
                 * For example, 0 equals the start of the text the IME reads (however, text might exist
                 * before that position in the edit field).
                 * @langversion 3.0
                 * @playerversion   Flash 10.1
                 * @playerversion   AIR 2
                 */
            public:
                int relativeEnd;

                /**
                 * A property defining the current composition clause is active and
                 * lengthened or shortened or edited with the IME while the neighboring
                 * clauses are not changing.
                 * @langversion 3.0
                 * @playerversion   Flash 10.1
                 * @playerversion   AIR 2
                 */
            public:
                bool selected;

                /**
                 * A property defining the current clause has been processed by the IME
                 * and the clause is waiting to be accepted or confirmed by the user.
                 * @langversion 3.0
                 * @playerversion   Flash 10.1
                 * @playerversion   AIR 2
                 */
            public:
                bool converted;

                /**
                 * Creates a CompositionAttributeRange object.
                 * @param   relativeStart   The zero based index of the first character included in the character range.
                 * @param   relativeEnd The zero based index of the last character included in the character range.
                 * @param   selected    Defines the current composition clause as active or not.
                 * @param   converted   Defines the current clause as processed by the IME and waiting for user confirmation.
                 * @langversion 3.0
                 * @playerversion   Flash 10.1
                 * @playerversion   AIR 2
                 */
            public:
                CompositionAttributeRange(int relativeStart, int relativeEnd, bool selected, bool converted);
            };
        }
    }
}

#endif // FLEX11_6_FLASH_TEXT_IME_COMPOSITIONATTRIBUTERANGE_AS
#endif // __cplusplus

