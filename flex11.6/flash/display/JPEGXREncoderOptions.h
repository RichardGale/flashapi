#if !defined(FLEX11_6_FLASH_DISPLAY_JPEGXRENCODEROPTIONS_AS)
#define FLEX11_6_FLASH_DISPLAY_JPEGXRENCODEROPTIONS_AS
#if defined(__cplusplus)



namespace flash
{
    namespace display
    {
        class JPEGXREncoderOptions : public Object
        {
        public:
            unsigned int quantization;
        public:
            std::string colorSpace;
        public:
            unsigned int trimFlexBits;

        public:
            JPEGXREncoderOptions(unsigned int quantization=20, std::string colorSpace="auto", unsigned int trimFlexBits=0);
        };
    }
}

#endif // FLEX11_6_FLASH_DISPLAY_JPEGXRENCODEROPTIONS_AS
#endif // __cplusplus

