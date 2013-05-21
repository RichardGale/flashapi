

    /**
     * The XMLNodeType class contains constants used with 
     * <codeph class="+ topic/ph pr-d/codeph ">XMLNode.nodeType</codeph>. The values are defined
     * by the NodeType enumeration in the
     * W3C DOM Level 1 recommendation: 
     * <xref href="http://www.w3.org/TR/1998/REC-DOM-Level-1-19981001/level-one-core.html" scope="external" class="- topic/xref ">http://www.w3.org/TR/1998/REC-DOM-Level-1-19981001/level-one-core.html</xref>
     * @langversion 3.0
     * @playerversion   Flash 9
     * @playerversion   Lite 4
     */


namespace flash {
namespace xml {


        /**
         * Specifies that the node is an element.
         * This constant is used with XMLNode.nodeType. 
         * The value is defined by the NodeType enumeration in the
         * W3C DOM Level 1 recommendation: 
         * http://www.w3.org/TR/1998/REC-DOM-Level-1-19981001/level-one-core.html
         * @langversion 3.0
         * @playerversion   Flash 9
         * @playerversion   Lite 4
         */
        const unsigned int XMLNodeType::ELEMENT_NODE=1;

        /**
         * Specifies that the node is a text node.
         * This constant is used with XMLNode.nodeType. 
         * The value is defined by the NodeType enumeration in the
         * W3C DOM Level 1 recommendation: 
         * http://www.w3.org/TR/1998/REC-DOM-Level-1-19981001/level-one-core.html
         * @langversion 3.0
         * @playerversion   Flash 9
         * @playerversion   Lite 4
         */
        const unsigned int XMLNodeType::TEXT_NODE=3;
        const unsigned int XMLNodeType::CDATA_NODE;
        const unsigned int XMLNodeType::PROCESSING_INSTRUCTION_NODE;
        const unsigned int XMLNodeType::COMMENT_NODE;
        const unsigned int XMLNodeType::DOCUMENT_TYPE_NODE;
        const unsigned int XMLNodeType::XML_DECLARATION;

        XMLNodeType::XMLNodeType();
}
}

