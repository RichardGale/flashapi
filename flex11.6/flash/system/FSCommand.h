#if !defined(FLEX11_6_FLASH_SYSTEM_FSCOMMAND_AS)
#define FLEX11_6_FLASH_SYSTEM_FSCOMMAND_AS
#if defined(__cplusplus)



namespace flash
{
    namespace system
    {
        class FSCommand: public Object
        {
        public:
            static void     _fscommand(std::string command, std::string args);

        public:
            FSCommand();
        };
    }
}

#endif // FLEX11_6_FLASH_SYSTEM_FSCOMMAND_AS
#endif // __cplusplus

