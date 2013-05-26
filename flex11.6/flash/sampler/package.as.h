#if !defined(FLEX11_6_FLASH_SAMPLER_PACKAGE_AS_AS)
#define FLEX11_6_FLASH_SAMPLER_PACKAGE_AS_AS
#if defined(__cplusplus)


/**
 * Clears the current set of Sample objects. This method is usually called after calling getSamples()
 * and iterating over the Sample objects.
 * For Flash Player debugger version only.
 * @langversion 3.0
 * @playerversion   Flash 9.0.115.0
 */
public:
void     clearSamples();
/**
 * Begins the process of collecting memory usage Sample objects.
 * For Flash Player debugger version only.
 * @langversion 3.0
 * @playerversion   Flash 9.0.115.0
 */
public:
void     startSampling();
/**
 * Ends the process of collecting memory usage Sample objects and frees resources dedicated to the sampling process.
 * You start the sampling process with startSampling().
 * For Flash Player debugger version only.
 * @langversion 3.0
 * @playerversion   Flash 9.0.115.0
 */
public:
void     stopSampling();
/**
 * Stops the sampling process momentarily. Restart the sampling process using startSampling().
 * For Flash Player debugger version only.
 * @langversion 3.0
 * @playerversion   Flash 9.0.115.0
 */
public:
void     pauseSampling();
/**
 * Tells the sampler if it should create NewObjectSamples for internal allocations from the flash player.
 * If this is set to true, then every allocation will generate a NewObjectSample.  These internal allocs will
 * not have a type, or a reference to the Object.  They will have the ActionScript stack trace that triggered the
 * allocation.  Defaults to false, which only collects allocations for ActionScript objects.
 * @langversion 3.0
 */
public:
void     sampleInternalAllocs(bool b);
/**
 * Sets a callback function for the sampler - this function will be called when the sample stream is almost
 * exhausted.  This should be used to process samples before the sample buffer is filled.  pauseSampling will be called
 * before the callback is called, and startSampling will be called after the callback has been executed.
 * @langversion 3.0
 */
public:
void     setSamplerCallback(Function *f);
public:
void     _setSamplerCallback(Function *f);
/**
 * Returns the size in memory of a specified object when used with the Flash Player 9.0.115.0 or later debugger version. If
 * used with a Flash Player that is not the debugger version, this method returns 0.
 * @param   o   The object to analyze for memory usage.
 * @return  The byte count of memory used by the specified object.
 * @langversion 3.0
 * @playerversion   Flash 9.0.115.0
 */
public:
float   getSize(void *o);
/**
 * Returns an object containing all members of a specified object, including private members. You can then
 * iterate over the returned object to see all values. This method is similar to the flash.utils.describeType()
 * method but also allows you to see private members and skips the intermediate step of creating an XML object.
 * For Flash Player debugger version only.
 * @param   o   The object to analyze.
 * @param   instanceNames   If object is a Class and instanceNames is true report the instance names as if o was an instance of class instead of the class's member names.
 * @return  An Object that you must iterate over with a for each..in loop to retrieve the QNames for
 *   each property.
 * @langversion 3.0
 * @playerversion   Flash 9.0.115.0
 */
public:
Object   *getMemberNames(Object *o, bool instanceNames=false);
/**
 * Returns an object of memory usage Sample instances from the last sampling session. For Flash Player debugger version only.
 * @return  An iterator of Sample instances.
 * @langversion 3.0
 * @playerversion   Flash 9.0.115.0
 */
public:
Object   *getSamples();
public:
Object   *_getSamples(Class *cf);
/**
 * Returns the number of samples collected. For Flash Player debugger version only.
 * @return  An iterator of Sample instances.
 * @langversion 3.0
 * @playerversion   Flash 9.0.115.0
 */
public:
float   getSampleCount();
/**
 * Returns the number of times a method was executed. If the parameter obj
 * is a Class and the parameter qname is undefined then this method
 * returns the number of iterations of the constructor function. For Flash Player debugger version only.
 * @param   obj A method instance or a class. A class can be used to get the invocation count of
 *   instance functions when a method instance isn't available. If obj is undefined,
 *   this method returns the count of the package-scoped function named by qname.
 * @param   qname   If qname is undefined return the number of iterations of the constructor function.
 * @return  The number of times a method was executed.
 * @langversion 3.0
 * @playerversion   Flash 9.0.115.0
 */
public:
float   getInvocationCount(Object *obj, QName *qname);
/**
 * Returns the number of times a set function was executed. Use
 * isGetterSetter() to verify that you have a get/set function before you use
 * getSetterInvocationCount(). For Flash Player debugger version only.
 * @param   obj A method instance or a class.
 * @param   qname   If qname is undefined return the number of iterations of the constructor function.
 * @return  The number of times a set method was executed.
 * @langversion 3.0
 * @playerversion   Flash 9.0.115.0
 */
public:
float   getSetterInvocationCount(Object *obj, QName *qname);
/**
 * Returns the number of times a get function was executed. Use
 * isGetterSetter() to verify that you have a get/set function before you use
 * getGetterInvocationCount(). For Flash Player debugger version only.
 * @param   obj A method instance or a class.
 * @param   qname   If qname is undefined return the number of iterations of the constructor function.
 * @return  The number of times a get method was executed.
 * @langversion 3.0
 * @playerversion   Flash 9.0.115.0
 */
public:
float   getGetterInvocationCount(Object *obj, QName *qname);
public:
float   _getInvocationCount(Object *obj, QName *qname, unsigned int type);
/**
 * Checks to see if a property is defined by a get/set function. If you want to use
 * getInvocationCount() on a get/set function for a property,
 * first call isGetterSetter() to check to see if it is a get/set function,
 * and then use either getSetterInvocationCount
 * or getGetterInvocationCount to get the respective counts. For Flash Player debugger version only.
 * @param   obj A method instance or a class.
 * @param   qname   If qname is undefined return the number of iterations of the constructor function.
 * @return  A Boolean value indicating if the property is defined by a get/set function (true)
 *   or not (false).
 * @langversion 3.0
 * @playerversion   Flash 9.0.115.0
 */
public:
bool  isGetterSetter(Object *obj, QName *qname);
/**
 * Exposes the lexical scope of a Function so that captured scope objects (including activation
 * objects and with scopes) are seen by the profiler as being retained by the Function instance.
 * @param   obj A function
 * @return  An array containings all the lexical scope elements
 */
public:
std::vector<void *>    getLexicalScopes(Function *obj);
/**
 * Returns the saved "this" from a Method closure that you normal can't see from AS.
 * @param   obj A MethodClosure instance
 * @return  An object that is the "this" of the MethodClosure
 */
public:
Object   *getSavedThis(Function *obj);
/**
 * Returns the master string upon which this string depends, or null if this
 * string does not depend on another string.  For example, if you call
 * String.substr(), the returned string will often actually be
 * implemented as just a pointer into the original string, for the sake of efficiency.
 * In normal usage, this is an implementation detail which is not visible to the user;
 * however, it can be confusing when using a profiler to analyze your program's
 * memory consumption, because the string may be shown as taking less memory
 * than would be needed for the string's value.  In addition, a string might
 * be retained in memory solely because it is the master for other strings.
 * getMasterString() allows profilers to show the user an accurate
 * graph of string dependencies.
 * @param   str A string
 * @return  The string upon which the passed-in string depends, or null if the
 *   passed-in string does not depend on another string
 * @langversion 3.0
 */
public:
std::string   getMasterString(std::string str);
#endif // FLEX11_6_FLASH_SAMPLER_PACKAGE_AS_AS
#endif // __cplusplus

