#if !defined(FLEX11_6_FLASH_NET_DYNAMICPROPERTYOUTPUT_AS)
#define FLEX11_6_FLASH_NET_DYNAMICPROPERTYOUTPUT_AS
#if defined(__cplusplus)



namespace flash
{
    namespace net
    {
        class DynamicPropertyOutput : public Object, public IDynamicPropertyOutput
        {
        public:
            DynamicPropertyOutput();

        public:
            void     writeDynamicProperty(std::string name, void *value);
        };
    }
}

#endif // FLEX11_6_FLASH_NET_DYNAMICPROPERTYOUTPUT_AS
#endif // __cplusplus

