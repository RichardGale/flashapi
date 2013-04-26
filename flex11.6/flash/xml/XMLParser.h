#if !defined(FLEX11_6_FLASH_XML_XMLPARSER_AS)
#define FLEX11_6_FLASH_XML_XMLPARSER_AS
#if defined(__cplusplus)


namespace flash
{
    namespace xml
    {
        class XMLTag;
    }
}

using namespace flash::xml;

namespace flash
{
    namespace xml
    {
        class XMLParser: public Object
        {
        public:
            void     startParse(std::string source, bool ignoreWhite);

        public:
            int      getNext(XMLTag *tag);

        public:
            XMLParser();
        };
    }
}

#endif // FLEX11_6_FLASH_XML_XMLPARSER_AS
#endif // __cplusplus

