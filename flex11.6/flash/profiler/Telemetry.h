#if !defined(FLEX11_6_FLASH_PROFILER_TELEMETRY_AS)
#define FLEX11_6_FLASH_PROFILER_TELEMETRY_AS
#if defined(__cplusplus)



namespace flash
{
    namespace profiler
    {
        class Telemetry : public Object
        {
        public:
            static float        spanMarker();

        public:
            static bool         connected();

        public:
            static void     sendMetric(std::string metric, void *value);

        public:
            static void     sendSpanMetric(std::string metric, float startSpanMarker, void *value=NULL);

        public:
            static bool     registerCommandHandler(std::string commandName, Function *handler);

        public:
            Telemetry();

        public:
            static bool     unregisterCommandHandler(std::string commandName);
        };
    }
}

#endif // FLEX11_6_FLASH_PROFILER_TELEMETRY_AS
#endif // __cplusplus

