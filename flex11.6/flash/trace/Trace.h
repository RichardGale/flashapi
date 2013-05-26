#if !defined(FLEX11_6_FLASH_TRACE_TRACE_AS)
#define FLEX11_6_FLASH_TRACE_TRACE_AS
#if defined(__cplusplus)



#include "flex11.6.h"



namespace flash
{
    namespace trace
    {
        class Trace : public Object
        {
        public:
            static const int OFF;
        public:
            static const int METHODS;
        public:
            static const int METHODS_WITH_ARGS;
        public:
            static const int METHODS_AND_LINES;
        public:
            static const int METHODS_AND_LINES_WITH_ARGS;
        public:
            static const void *FILE;
        public:
            static const void *LISTENER;

        public:
            static void        *setLevel(int l, int target=2);

        public:
            static int      getLevel(int target=2);

        public:
            static void        *setListener(Function *f);

        public:
            static Function *getListener();

        public:
            Trace();
        };
    }
}

#endif // FLEX11_6_FLASH_TRACE_TRACE_AS
#endif // __cplusplus

