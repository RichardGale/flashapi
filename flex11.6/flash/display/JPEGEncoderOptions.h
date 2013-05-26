#if !defined(FLEX11_6_FLASH_DISPLAY_JPEGENCODEROPTIONS_AS)
#define FLEX11_6_FLASH_DISPLAY_JPEGENCODEROPTIONS_AS
#if defined(__cplusplus)



#include "flex11.6.h"



namespace flash
{
    namespace display
    {
        class JPEGEncoderOptions : public Object
        {
        public:
            unsigned int quality;

        public:
            JPEGEncoderOptions(unsigned int quality=80);
        };
    }
}

#endif // FLEX11_6_FLASH_DISPLAY_JPEGENCODEROPTIONS_AS
#endif // __cplusplus

