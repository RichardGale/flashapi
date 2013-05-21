#if !defined(FLEX11_6_FLASH_ACCESSIBILITY_ISIMPLETEXTSELECTION_AS)
#define FLEX11_6_FLASH_ACCESSIBILITY_ISIMPLETEXTSELECTION_AS
#if defined(__cplusplus)


/**
 * The ISimpleTextSelection class can be used to add support for
 * the MSAA ISimpleTextSelection interface to an AccessibilityImplementation.
 *
 *   <p class="- topic/p ">If an AccessibilityImplementation subclass implements the two getters in this class,
 * a screen reader such as JAWS can determine the text selection range by calling them.
 * The AccessibilityImplementation subclass does not have to formally declare that it implements
 * this interface; you can simply declare getters for these two properties, as follows:</p><codeblock xml:space="preserve" class="+ topic/pre pr-d/codeblock ">
 * class TextAreaAccImpl extends AccesibilityImplementation
 * {
 * ...
 * public function get selectionAnchorIndex():int
 * {
 * ...
 * }
 * public function get selectionActiveIndex():int
 * {
 * ...
 * }
 * }
 * </codeblock>
 * @langversion 3.0
 * @playerversion   Flash 10.1
 */


namespace flash
{
    namespace accessibility
    {
        class ISimpleTextSelection
        {
            /**
             * The zero-based character index value of the first character in the current selection.
             * If you want a component to support inline IME or accessibility, override this method.
             * @langversion 3.0
             * @playerversion   Flash 10.1
             */virtual
            int          selectionAnchorIndex() = 0;

            /**
             * The zero-based character index value of the last character in the current selection.
             * If you want a component to support inline IME or accessibility, override this method.
             * @langversion 3.0
             * @playerversion   Flash 10.1
             */
            virtual
            int          selectionActiveIndex() = 0;
        };
    }
}

#endif // FLEX11_6_FLASH_ACCESSIBILITY_ISIMPLETEXTSELECTION_AS
#endif // __cplusplus

