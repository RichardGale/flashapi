#if !defined(FLEX11_6_FLASH_DISPLAY_AVM1MOVIE_AS)
#define FLEX11_6_FLASH_DISPLAY_AVM1MOVIE_AS
#if defined(__cplusplus)


namespace flash
{
    namespace utils
    {
        class ByteArray;
    }
}

/**
 * AVM1Movie is a simple class that represents AVM1 movie clips, which use ActionScript 1.0 or 2.0.
 * (AVM1 is the ActionScript virtual machine used to run ActionScript 1.0 and 2.0.
 * AVM2 is the ActionScript virtual machine used to run ActionScript 3.0.)
 * When a Flash Player 8, or older, SWF file is loaded by a Loader object, an AVM1Movie
 * object is created. The AVM1Movie object can use methods and properties inherited from the
 * DisplayObject class (such as <codeph class="+ topic/ph pr-d/codeph ">x</codeph>, <codeph class="+ topic/ph pr-d/codeph ">y</codeph>, <codeph class="+ topic/ph pr-d/codeph ">width</codeph>, and so on).
 * However, no interoperability (such as calling methods or using parameters) between the AVM1Movie object
 * and AVM2 objects is allowed.
 *
 *   <p class="- topic/p ">There are several restrictions on an AVM1 SWF file loaded by an AVM2 SWF file:</p><ul class="- topic/ul "><li class="- topic/li ">The loaded AVM1Movie object operates as a psuedo-root object for the AVM1 SWF file and all AVM1 SWF files
 * loaded by it (as if the ActionScript 1.0 <codeph class="+ topic/ph pr-d/codeph ">lockroot</codeph> property were set to <codeph class="+ topic/ph pr-d/codeph ">true</codeph>).
 * The AVM1 movie is always the top of any ActionScript 1.0 or 2.0 code execution in any children.
 * The <codeph class="+ topic/ph pr-d/codeph ">_root</codeph> property for loaded children is always this AVM1 SWF file, unless the
 * <codeph class="+ topic/ph pr-d/codeph ">lockroot</codeph> property is set in a loaded AVM1 SWF file.</li><li class="- topic/li ">The AVM1 content cannot load files into levels. For example, it cannot load files by calling
 * <codeph class="+ topic/ph pr-d/codeph ">loadMovieNum("url", levelNum)</codeph>.</li><li class="- topic/li ">The AVM1 SWF file that is loaded by an AVM2 SWF file cannot load another SWF file into <codeph class="+ topic/ph pr-d/codeph ">this</codeph>.
 * That is, it cannot load another SWF file over itself.  However, child Sprite objects, MovieClip objects, or other AVM1
 * SWF files loaded by this SWF file can load into <codeph class="+ topic/ph pr-d/codeph ">this</codeph>.</li></ul>
 * @langversion 3.0
 * @playerversion   Flash 9
 * @playerversion   Lite 4
 */
using namespace flash::utils;

namespace flash
{
    namespace display
    {
        class AVM1Movie: public DisplayObject
        {
        public:
            AVM1Movie();

        public:
            void    *call(std::string functionName, ...);

        public:
            void     addCallback(std::string functionName, Function *closure);
        };
    }
}

#endif // FLEX11_6_FLASH_DISPLAY_AVM1MOVIE_AS
#endif // __cplusplus

