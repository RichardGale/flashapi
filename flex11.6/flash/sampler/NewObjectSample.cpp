

    /**
     * The NewObjectSample class represents objects that are created within a <codeph class="+ topic/ph pr-d/codeph ">getSamples()</codeph> stream.
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


namespace flash {
namespace sampler {


                     







                     

        /**
         * The NewObjectSample object if it still exists. If the object has been garbage collected, this property is
         * undefined and a corresponding DeleteObjectSample exists. For Flash Player debugger version only.
         * @langversion 3.0
         * @playerversion   Flash 9.0.115.0
         */
        void* NewObjectSample::object()    ;

        /**
         * The NewObjectSample object size. If the object has been garbagecollected, this property is
         * undefined and a corresponding DeleteObjectSample exists. For FlashPlayer debugger version only.
         * @langversion 3.0
         * @playerversion   Flash 9.0.115.0
         */
        float NewObjectSample::size()         ;

        NewObjectSample::NewObjectSample();
}
}

