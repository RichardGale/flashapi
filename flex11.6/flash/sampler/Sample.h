#if !defined(FLEX11_6_FLASH_SAMPLER_SAMPLE_AS)
#define FLEX11_6_FLASH_SAMPLER_SAMPLE_AS
#if defined(__cplusplus)


/**
 * The Sample class creates objects that hold memory analysis information over distinct durations.
 * For Flash Player debugger version only.
 *
 *   EXAMPLE:
 *
 *   The following example uses the <codeph class="+ topic/ph pr-d/codeph ">stack</codeph> and <codeph class="+ topic/ph pr-d/codeph ">time</codeph> properties of a Sample object
 * <codeph class="+ topic/ph pr-d/codeph ">s</codeph> to collect memory samples. The samples contain NewObjectSample objects (the
 * <codeph class="+ topic/ph pr-d/codeph ">newSamples</codeph> array), DeleteObjectSample objects (the <codeph class="+ topic/ph pr-d/codeph ">delSamples</codeph> array), and CPU memory sample
 * objects (the <codeph class="+ topic/ph pr-d/codeph ">cpuSamples</codeph> array). To use
 * the memory profiler, you need to have Flash Player debugger version 9.0.115.0 or later installed.
 * <codeblock xml:space="preserve" class="+ topic/pre pr-d/codeblock ">
 * package
 * {
 * import flash.sampler.*
 * import flash.system.*
 * import flash.utils.*
 * import flash.display.Sprite
 * public class sampleTypes extends Sprite
 * {
 * var b:Boolean = true
 * public function sampleTypes() {
 * flash.sampler.startSampling();
 * for(var i:int=0;i&lt;10000;i++)
 * new Object();
 *
 *   var cpuSamples:Array=[];
 * var newSamples:Array=[];
 * var delSamples:Array=[];
 * var ids:Array=[]
 *
 *   var lastTime:Number=0;
 * for each(var s:Sample in getSamples()) {
 *
 *   assert(s.time &gt; 0); // positive
 * assert(Math.floor(s.time) == s.time, s.time); // integral
 * assert(s.time &gt;= lastTime, s.time + ":" + lastTime); // ascending
 * assert(s.stack == null || s.stack is Array)
 * if(s.stack) {
 * assert(s.stack[0] is StackFrame);
 * assert(s.stack[0].name is String);
 * }
 *
 *   if(s is NewObjectSample) {
 * var nos = NewObjectSample(s);
 * assert(s.id &gt; 0, s.id);
 * assert(s.type is Class, getQualifiedClassName(s.type));
 * newSamples.push(s);
 * ids[s.id] = "got one";
 * } else if(s is DeleteObjectSample) {
 * var dos = DeleteObjectSample(s);
 * delSamples.push(s);
 * assert(ids[dos.id] == "got one");
 * } else if(s is Sample)
 * cpuSamples.push(s);
 * else {
 * assert(false);
 * }
 * lastTime = s.time;
 * }
 *
 *   trace(b)
 * trace(newSamples.length &gt; 0)
 * trace(cpuSamples.length &gt; 0)
 * trace(delSamples.length &gt; 0)
 *
 *   }
 *
 *   private function assert(e:Boolean, mess:String=null):void {
 * b = e &amp;&amp; b;
 * if(true &amp;&amp; !e) {
 * if(mess) trace(mess);
 * trace(new Error().getStackTrace());
 * }
 * }
 * }
 * }
 * </codeblock>
 * @langversion 3.0
 * @playerversion   Flash 9.0.115.0
 */

#include "flex11.6.h"



namespace flash
{
    namespace sampler
    {
        class Sample : public Object
        {
            /**
             * The microseconds that define the duration of the Sample instance. For Flash Player debugger version only.
             * @langversion 3.0
             * @playerversion   Flash 9.0.115.0
             */
        public:
            const float time;

            /**
             * Contains information about the methods executed by Flash Player over a specified period of time. The format for the
             * stack trace is similiar to the content shown in the exception dialog box of the Flash Player debugger version.
             * For Flash Player debugger version only.
             * @langversion 3.0
             * @playerversion   Flash 9.0.115.0
             */
        public:
            const std::vector<void *> stack;

        public:
            Sample();
        };
    }
}

#endif // FLEX11_6_FLASH_SAMPLER_SAMPLE_AS
#endif // __cplusplus

