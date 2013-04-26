#if !defined(FLEX11_6_FLASH_TEXT_TEXTRUN_AS)
#define FLEX11_6_FLASH_TEXT_TEXTRUN_AS
#if defined(__cplusplus)


namespace flash
{
    namespace text
    {
        class TextFormat;
    }
}

using namespace flash::text;

namespace flash
{
    namespace text
    {
        class TextRun: public Object
        {
        public:
            int beginIndex;
        public:
            int endIndex;
        public:
            TextFormat *textFormat;

        public:
            TextRun(int beginIndex, int endIndex, TextFormat *textFormat);
        };
    }
}

#endif // FLEX11_6_FLASH_TEXT_TEXTRUN_AS
#endif // __cplusplus

