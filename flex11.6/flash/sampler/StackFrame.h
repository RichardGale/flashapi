#if !defined(FLEX11_6_FLASH_SAMPLER_STACKFRAME_AS)
#define FLEX11_6_FLASH_SAMPLER_STACKFRAME_AS
#if defined(__cplusplus)


/**
 * The StackFrame class provides access to the properties of a data block
 * containing a function. For Flash Player debugger version only.
 * @langversion 3.0
 * @playerversion   Flash 9.0.115.0
 */

#include "flex11.6.h"



namespace flash
{
    namespace sampler
    {
        class StackFrame : public Object
        {
            /**
             * The function name in the stack frame. For Flash Player debugger version only.
             * @langversion 3.0
             * @playerversion   Flash 9.0.115.0
             */
        public:
            const std::string name;

            /**
             * The file name of the SWF file being debugged. For Flash Player debugger version only.
             * @langversion 3.0
             * @playerversion   Flash 9.0.115.0
             */
        public:
            const std::string file;

            /**
             * The line number for the function in the SWF file being debugged. For Flash Player debugger version only.
             * @langversion 3.0
             * @playerversion   Flash 9.0.115.0
             */
        public:
            const unsigned int line;

            /**
             * The identifier for the script function in the application being profiled.
             * @langversion 3.0
             */
        public:
            const float scriptID;

        public:
            StackFrame();

            /**
             * Converts the StackFrame to a string of its properties.
             * @return  A string containing the name property, and optionally the file
             *   and line properties (if a SWF file is being debugged) of the StackFrame object. For Flash Player debugger version only.
             * @langversion 3.0
             * @playerversion   Flash 9.0.115.0
             */
        public:
            std::string   toString();
        };
    }
}

#endif // FLEX11_6_FLASH_SAMPLER_STACKFRAME_AS
#endif // __cplusplus

