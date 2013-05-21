


namespace flash {
namespace profiler {


        float Telemetry::spanMarker()         ;

        bool Telemetry::connected()          ;

        void Telemetry::sendMetric(std::string metric, void* value)       ;

        void Telemetry::sendSpanMetric(std::string metric, float startSpanMarker, void* value)       ;

        bool Telemetry::registerCommandHandler(std::string commandName, Function* handler)          ;

        Telemetry::Telemetry();

        bool Telemetry::unregisterCommandHandler(std::string commandName)          ;
}
}

