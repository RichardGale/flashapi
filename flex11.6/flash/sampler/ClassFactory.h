#if !defined(FLEX11_6_FLASH_SAMPLER_CLASSFACTORY_AS)
#define FLEX11_6_FLASH_SAMPLER_CLASSFACTORY_AS
#if defined(__cplusplus)



namespace flash
{
    namespace sampler
    {
        class ClassFactory : public Object
        {
        public:
            static const Class *StackFrameClass;
        public:
            static const Class *SampleClass;
        public:
            static const Class *DeleteObjectSampleClass;
        public:
            static const Class *NewObjectSampleClass;

        public:
            ClassFactory();
        };
    }
}

#endif // FLEX11_6_FLASH_SAMPLER_CLASSFACTORY_AS
#endif // __cplusplus

