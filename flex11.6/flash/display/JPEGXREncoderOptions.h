#if !defined(FLEX11_6_FLASH_DISPLAY_JPEGXRENCODEROPTIONS_AS)
#define FLEX11_6_FLASH_DISPLAY_JPEGXRENCODEROPTIONS_AS
#if defined(__cplusplus)



namespace flash
{
    namespace display
    {
        class JPEGXREncoderOptions: public Object
        {
        public:
            unsigned int quantization;
        public:
            std::string colorSpace;
        public:
            unsigned int trimFlexBits;

        public:
            JPEGXREncoderOptions(unsigned int quantization, std::string colorSpace, unsigned int trimFlexBits);
        };
    }
}

#endif // FLEX11_6_FLASH_DISPLAY_JPEGXRENCODEROPTIONS_AS
#endif // __cplusplus

