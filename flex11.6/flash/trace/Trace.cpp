


namespace flash {
namespace trace {


        const int Trace::OFF  ;
        const int Trace::METHODS  ;
        const int Trace::METHODS_WITH_ARGS  ;
        const int Trace::METHODS_AND_LINES  ;
        const int Trace::METHODS_AND_LINES_WITH_ARGS  ;
        const void* Trace::FILE;
        const void* Trace::LISTENER;

        void* Trace::setLevel(int l, int target)    ;

        int Trace::getLevel(int target)      ;

        void* Trace::setListener(Function* f)    ;

        Function* Trace::getListener()           ;

        Trace::Trace();
}
}

