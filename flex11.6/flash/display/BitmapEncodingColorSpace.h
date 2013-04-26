#if !defined(FLEX11_6_FLASH_DISPLAY_BITMAPENCODINGCOLORSPACE_AS)
#define FLEX11_6_FLASH_DISPLAY_BITMAPENCODINGCOLORSPACE_AS
#if defined(__cplusplus)



namespace flash
{
    namespace display
    {
        class BitmapEncodingColorSpace: public Object
        {
        public:
            static const std::string COLORSPACE_AUTO;
        public:
            static const std::string COLORSPACE_4_4_4;
        public:
            static const std::string COLORSPACE_4_2_2;
        public:
            static const std::string COLORSPACE_4_2_0;

        public:
            BitmapEncodingColorSpace();
        };
    }
}

#endif // FLEX11_6_FLASH_DISPLAY_BITMAPENCODINGCOLORSPACE_AS
#endif // __cplusplus

