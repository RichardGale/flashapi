#if !defined(FLEX11_6_FLASH_XML_XMLTAG_AS)
#define FLEX11_6_FLASH_XML_XMLTAG_AS
#if defined(__cplusplus)



namespace flash
{
    namespace xml
    {
        class XMLTag: public Object
        {
        public:
            unsigned int type();
        public:
            void         type(unsigned int value);

        public:
            bool         empty();
        public:
            void         empty(bool value);

        public:
            std::string  value();
        public:
            void         value(std::string v);

        public:
            Object      *attrs();
        public:
            void         attrs(Object *value);

        public:
            XMLTag();
        };
    }
}

#endif // FLEX11_6_FLASH_XML_XMLTAG_AS
#endif // __cplusplus

