#if !defined(FLEX11_6_FLASH_UTILS_DICTIONARY_AS)
#define FLEX11_6_FLASH_UTILS_DICTIONARY_AS
#if defined(__cplusplus)


/**
 * The Dictionary class lets you create a dynamic collection of properties, which uses strict equality
 * (<codeph class="+ topic/ph pr-d/codeph ">===</codeph>) for key comparison. When an object is used as a key, the object's
 * identity is used to look up the object, and not the value returned from calling <codeph class="+ topic/ph pr-d/codeph ">toString()</codeph> on it.
 * <p class="- topic/p ">The following statements show the relationship between a Dictionary object and a key object:</p><pre xml:space="preserve" class="- topic/pre ">
 * var dict = new Dictionary();
 * var obj = new Object();
 * var key:Object = new Object();
 * key.toString = function() { return "key" }
 *
 *   dict[key] = "Letters";
 * obj["key"] = "Letters";
 *
 *   dict[key] == "Letters"; // true
 * obj["key"] == "Letters"; // true
 * obj[key] == "Letters"; // true because key == "key" is true b/c key.toString == "key"
 * dict["key"] == "Letters"; // false because "key" === key is false
 * delete dict[key]; //removes the key
 * </pre>
 * @langversion 3.0
 * @playerversion   Flash 9
 * @playerversion   Lite 4
 */


namespace flash
{
    namespace utils
    {
        class Dictionary : public Object
        {
            /**
             * Creates a new Dictionary object. To remove a key from a Dictionary object, use the delete operator.
             * @param   weakKeys    Instructs the Dictionary object to use "weak" references on object keys.
             *   If the only reference to an object is in the specified Dictionary object, the key is eligible for
             *   garbage collection and is removed from the table when the object is collected.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            Dictionary(bool weakKeys   =false);
        };
    }
}

#endif // FLEX11_6_FLASH_UTILS_DICTIONARY_AS
#endif // __cplusplus

