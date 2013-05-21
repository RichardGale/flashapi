

#include "TextJustifier.h"
#include "flash/text/engine/TextJustifier.h"

    /**
     * The TextJustifier class is an abstract base class for the justifier types that you can apply to a TextBlock, specifically the
     * EastAsianJustifier and SpaceJustifier classes.
     * 
     *   <p class="- topic/p ">You cannot instantiate the TextJustifier class directly. Invoking <codeph class="+ topic/ph pr-d/codeph ">new TextJustifier()</codeph> throws an <codeph class="+ topic/ph pr-d/codeph ">ArgumentError</codeph> 
     * exception. Setting the properties of an EastAsianJustifier or SpaceJustifier object after you apply it to a TextBlock does not 
     * invalidate the TextBlock.</p>
     * @langversion 3.0
     * @playerversion   Flash 10
     * @playerversion   AIR 1.5
     * @playerversion   Lite 4
     */

using namespace flash::text::engine;

namespace flash {
namespace text {
namespace engine {


        /**
         * Specifies the locale to determine the justification rules for the text in a text block.
         * Standard locale identifiers are used.  For example "en", "en_US" and "en-US" are all
         * English, "ja" is Japanese.
         * @langversion 3.0
         * @playerversion   Flash 10
         * @playerversion   AIR 1.5
         * @playerversion   Lite 4
         * @throws  ArgumentError The locale specified is null or too short to represent a valid locale.
         */
        std::string TextJustifier::locale()         ;

        /**
         * Specifies the line justification for the text in a text block.
         * 
         *   Use the following constants defined by the LineJustification as valid values for this property:String valueDescriptionLineJustification.UNJUSTIFIEDGenerates unjustified lines.LineJustification.ALL_BUT_LASTGenerates all lines justified except for the last one.LineJustification.ALL_INCLUDING_LASTGenerates all lines justified.
         * @langversion 3.0
         * @playerversion   Flash 10
         * @playerversion   AIR 1.5
         * @playerversion   Lite 4
         */
        std::string TextJustifier::lineJustification()         ;
        void TextJustifier::lineJustification(std::string value)       ;

        /**
         * Constructs a default TextJustifier subclass appropriate to the specified locale.
         * 
         *   If the locale is Chinese, Korean, or Japanese, the method constructs a default EastAsianJustifier object.
         * Otherwise the text engine constructs a default SpaceJustifier object.
         * @param   locale  The locale to determine the justifier constructed.
         * @return  A reference to a TextJustifier object.
         * @langversion 3.0
         * @playerversion   Flash 10
         * @playerversion   AIR 1.5
         * @playerversion   Lite 4
         * @throws  ArgumentError The locale specified is null or too short to represent a valid locale.
         */
        flash::text::engine::TextJustifier* TextJustifier::getJustifierForLocale(std::string locale)                                  ;

        /**
         * Constructs a cloned copy of the TextJustifier.
         * 
         *   Subclasses of TextJustifier must override this method.
         * @return  A copy of the TextJustifier object.
         * @langversion 3.0
         * @playerversion   Flash 10
         * @playerversion   AIR 1.5
         * @playerversion   Lite 4
         */
        flash::text::engine::TextJustifier* TextJustifier::clone()                                  ;

        /**
         * Calling the new TextJustifier() constructor throws an 
         * ArgumentError exception. You can, however, call constructors for 
         * the following subclasses of TextJustifier:
         * 
         *   new SpaceJustifier()new EastAsianJustifier()
         * @param   locale  The locale to determine the justification rules.
         * @param   lineJustification   The type of line justification for the paragraph. 
         *   Use LineJustification constants for this property.
         * @langversion 3.0
         * @playerversion   Flash 10
         * @playerversion   AIR 1.5
         * @playerversion   Lite 4
         * @throws  ArgumentError The locale specified is null or too short to represent a valid locale.
         * @throws  ArgumentError The lineJustification specified is not a member of LineJustification.
         */
        TextJustifier::TextJustifier(std::string locale, std::string lineJustification);
}
}
}

