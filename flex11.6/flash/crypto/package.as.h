#if !defined(FLEX11_6_FLASH_CRYPTO_PACKAGE_AS_AS)
#define FLEX11_6_FLASH_CRYPTO_PACKAGE_AS_AS
#if defined(__cplusplus)


#include "flex11.6.h"
namespace flash
{
    namespace utils
    {
        class ByteArray;
    }
}

public:
ByteArray *generateRandomBytes(unsigned int numberRandomBytes);
#endif // FLEX11_6_FLASH_CRYPTO_PACKAGE_AS_AS
#endif // __cplusplus

