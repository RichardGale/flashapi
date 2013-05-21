#if !defined(FLEX11_6_FLASH_XML_XMLNODETYPE_AS)
#define FLEX11_6_FLASH_XML_XMLNODETYPE_AS
#if defined(__cplusplus)


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


namespace flash
{
    namespace xml
    {
        class XMLNodeType : public Object
        {
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
        public:
            static const unsigned int ELEMENT_NODE;

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
        public:
            static const unsigned int TEXT_NODE;
        public:
            static const unsigned int CDATA_NODE;
        public:
            static const unsigned int PROCESSING_INSTRUCTION_NODE;
        public:
            static const unsigned int COMMENT_NODE;
        public:
            static const unsigned int DOCUMENT_TYPE_NODE;
        public:
            static const unsigned int XML_DECLARATION;

        public:
            XMLNodeType();
        };
    }
}

#endif // FLEX11_6_FLASH_XML_XMLNODETYPE_AS
#endif // __cplusplus

