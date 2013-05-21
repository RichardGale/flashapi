

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
