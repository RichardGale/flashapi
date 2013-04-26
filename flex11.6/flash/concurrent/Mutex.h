#if !defined(FLEX11_6_FLASH_CONCURRENT_MUTEX_AS)
#define FLEX11_6_FLASH_CONCURRENT_MUTEX_AS
#if defined(__cplusplus)



namespace flash
{
    namespace concurrent
    {
        class Mutex: public Object
        {
        public:
            static bool         isSupported();

        public:
            void     lock();

        public:
            Mutex();

        public:
            bool     tryLock();

        public:
            void     unlock();
        };
    }
}

#endif // FLEX11_6_FLASH_CONCURRENT_MUTEX_AS
#endif // __cplusplus

