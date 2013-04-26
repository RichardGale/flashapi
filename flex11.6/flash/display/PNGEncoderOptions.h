#if !defined(FLEX11_6_FLASH_DISPLAY_PNGENCODEROPTIONS_AS)
#define FLEX11_6_FLASH_DISPLAY_PNGENCODEROPTIONS_AS
#if defined(__cplusplus)



namespace flash
{
    namespace display
    {
        class PNGEncoderOptions: public Object
        {
        public:
            bool fastCompression;

        public:
            PNGEncoderOptions(bool fastCompression);
        };
    }
}

#endif // FLEX11_6_FLASH_DISPLAY_PNGENCODEROPTIONS_AS
#endif // __cplusplus

