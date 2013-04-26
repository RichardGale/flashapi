#if !defined(FLEX11_6_REGEXP_AS)
#define FLEX11_6_REGEXP_AS
#if defined(__cplusplus)


/**
 * The RegExp class lets you work with regular expressions, which are patterns that you can use
 * to perform searches in strings and to replace text in strings.
 *
 *   <p class="- topic/p ">You can create a new RegExp object by using the <codeph class="+ topic/ph pr-d/codeph ">new RegExp()</codeph> constructor or by
 * assigning a RegExp literal to a variable:</p><codeblock xml:space="preserve" class="+ topic/pre pr-d/codeblock "> var pattern1:RegExp = new RegExp("test-\\d", "i");
 * var pattern2:RegExp = /test-\d/i;
 * </codeblock><p class="- topic/p ">For more information, see "Using Regular Expressions" in the <i class="+ topic/ph hi-d/i ">ActionScript 3.0 Developer's Guide</i>.</p>
 *
 *   EXAMPLE:
 *
 *   The following example shows how you can use regular expressions to parse
 * strings and return a new string or a Boolean value, based on the string passed in.  The
 * <codeph class="+ topic/ph pr-d/codeph ">informalizeGreeting()</codeph> method simply replaces the word <codeph class="+ topic/ph pr-d/codeph ">Hello</codeph> with <codeph class="+ topic/ph pr-d/codeph ">Hi</codeph>,
 * regardless of case.  It also strips out the surname in the name in the string
 * (assuming that name matches the specified pattern). In the <codeph class="+ topic/ph pr-d/codeph ">validateEmail()</codeph> and
 * <codeph class="+ topic/ph pr-d/codeph ">validatePhoneNumber()</codeph> methods, the string passed is checked to see if its pattern matches a valid
 * email address or a specific phone number pattern, and the methods return Boolean values based on the results.
 * <codeblock xml:space="preserve" class="+ topic/pre pr-d/codeblock ">
 * package {
 * import flash.display.Sprite;
 *
 *   public class RegExpExample extends Sprite {
 * public function RegExpExample() {
 * var formalGreeting:String = "Hello, John Smith.";
 * trace(informalizeGreeting(formalGreeting));    // Hi, John.
 *
 *   var validEmail:String = "name@domain.com";
 *   trace(validateEmail(validEmail));        // true
 *
 *     var invalidEmail:String = "foo";
 *   trace(validateEmail(invalidEmail));  // false
 *
 *     var validPhoneNumber:String = "415-555-1212";
 *   trace(validatePhoneNumber(validPhoneNumber));    // true
 *
 *     var invalidPhoneNumber:String = "312-867-530999";
 *   trace(validatePhoneNumber(invalidPhoneNumber));  // false
 *   }
 *   private function informalizeGreeting(str:String):String {
 *   var pattern:RegExp = new RegExp("hello, (\\w+) \\w+", "i");
 *   return str.replace(pattern, "Hi, $1");
 *   }
 *   private function validateEmail(str:String):Boolean {
 *   var pattern:RegExp = /(\w|[_.\-])+@((\w|-)+\.)+\w{2,4}+/;
 *   var result:Object = pattern.exec(str);
 *   if(result == null) {
 *   return false;
 *   }
 *   return true;
 *   }
 *   private function validatePhoneNumber(str:String):Boolean {
 *   var pattern:RegExp = /^\d{3}-\d{3}-\d{4}$/;
 *   var result:Object = pattern.exec(str);
 *   if(result == null) {
 *   return false;
 *   }
 *   return true;
 *   }
 *   }
 *   }
 *   </codeblock>
 * @langversion 3.0
 * @playerversion   Flash 9
 * @playerversion   Lite 4
 */

class RegExp: public Object
{
public:
    static const int length;

    /**
     * Specifies the pattern portion of the regular expression.
     * @langversion 3.0
     * @playerversion   Flash 9
     * @playerversion   Lite 4
     */
public:
    std::string  source();

    /**
     * Specifies whether to use global matching for the regular expression. When
     * global == true, the lastIndex property is set after a match is
     * found. The next time a match is requested, the regular expression engine starts from
     * the lastIndex position in the string. Use the g flag when
     * constructing a regular expression  to set global to true.
     * @langversion 3.0
     * @playerversion   Flash 9
     * @playerversion   Lite 4
     */
public:
    bool         global();

    /**
     * Specifies whether the regular expression ignores case sensitivity. Use the
     * i flag when constructing a regular expression to set
     * ignoreCase = true.
     * @langversion 3.0
     * @playerversion   Flash 9
     */
public:
    bool         ignoreCase();

    /**
     * Specifies whether the m (multiline) flag is set. If it is set,
     * the caret (^) and dollar sign ($) in a regular expression
     * match before and after new lines.
     * Use the m flag when constructing a regular expression to set
     * multiline = true.
     * @langversion 3.0
     * @playerversion   Flash 9
     * @playerversion   Lite 4
     */
public:
    bool         multiline();

    /**
     * Specifies the index position in the string at which to start the next search. This property
     * affects the exec() and test() methods of the RegExp class.
     * However, the match(), replace(), and search() methods
     * of the String class ignore the lastIndex property and start all searches from
     * the beginning of the string.
     *
     *   When the exec() or test() method finds a match and the g
     * (global) flag is set to true for the regular expression, the method
     * automatically sets the lastIndex property to the index position of the character
     * after the last character in the matching substring of the last match. If the
     * g (global) flag is set to false, the method does not
     * set the lastIndexproperty.You can set the lastIndex property to adjust the starting position
     * in the string for regular expression matching.
     * @langversion 3.0
     * @playerversion   Flash 9
     * @playerversion   Lite 4
     */
public:
    float        lastIndex();
public:
    void         lastIndex(int i);

    /**
     * Specifies whether the dot character (.) in a regular expression pattern matches
     * new-line characters. Use the s flag when constructing
     * a regular expression to set dotall = true.
     * @langversion 3.0
     * @playerversion   Flash 9
     * @playerversion   Lite 4
     */
public:
    bool         dotall();

    /**
     * Specifies whether to use extended mode for the regular expression.
     * When a RegExp object is in extended mode, white space characters in the constructor
     * string are ignored. This is done to allow more readable constructors.
     *
     *   Use the x flag when constructing a regular expression to set
     * extended = true.
     * @langversion 3.0
     * @playerversion   Flash 9
     * @playerversion   Lite 4
     */
public:
    bool         extended();

    /**
     * Lets you construct a regular expression from two strings. One string defines the pattern of the
     * regular expression, and the other defines the flags used in the regular expression.
     * @param   re  The pattern of the regular expression (also known as the constructor string). This is the
     *   main part  of the regular expression (the part that goes within the "/" characters).
     *
     *     Notes:Do not include the starting and trailing "/" characters; use these only when defining a regular expression
     *   literal without using the constructor. For example, the following two regular expressions are equivalent:
     *
     *     <codeblock>
     *   var re1:RegExp = new RegExp("bob", "i");
     *   var re2:RegExp = /bob/i;
     *   </codeblock>
     *   In a regular expression that is defined with the RegExp() constructor method, to use a
     *   metasequence that begins with the backslash (\) character, such as \d (which matches any digit),
     *   type the backslash character twice. For example, the following two regular expressions are equivalent:
     *
     *     <codeblock>
     *   var re1:RegExp = new RegExp("\\d+", "");
     *   var re2:RegExp = /\d/;
     *   </codeblock>
     *   In the first expression, you must type the backlash character twice in this case, because the first parameter of the RegExp()
     *   constructor method is a string, and in a string literal you must type a backslash character twice to have it
     *   recognized as a single  backslash character.
     * @param   flags   The modifiers of the regular expression. These can include the following:
     *
     *     g    When using the replace() method of the String class,
     *   specify this modifier to replace all matches, rather than only the first one.
     *   This modifier corresponds to the global property of the RegExp instance.i    The regular expression is evaluated without case
     *   sensitivity. This modifier corresponds to the ignoreCase property of the RegExp instance.s    The dot (.) character matches new-line characters. Note
     *   This modifier corresponds to the dotall property of the RegExp instance.m    The caret (^) character and dollar sign ($) match
     *   before and after new-line characters. This modifier corresponds to the
     *   multiline property of the RegExp instance.x    White space characters in the re string are ignored,
     *   so that you can write more readable constructors. This modifier corresponds to the
     *   extended property of the RegExp instance.All other characters in the flags string are ignored.
     * @langversion 3.0
     * @playerversion   Flash 9
     */
public:
    RegExp(void *pattern, void *options);

    /**
     * Performs a search for the regular expression on the given string str.
     *
     *   If the g (global) flag is not set for the regular
     * expression, then the search starts
     * at the beginning of the string (at index position 0); the search ignores
     * the lastIndex property of the regular expression.If the g (global) flag is set for the regular
     * expression, then the search starts
     * at the index position specified by the lastIndex property of the regular expression.
     * If the search matches a substring, the lastIndex property changes to match the position
     * of the end of the match.
     * @param   str The string to search.
     * @return  If there is no match, null; otherwise, an object with the following properties:
     *
     *     An array, in which element 0 contains the complete matching substring, and
     *   other elements of the array (1 through n) contain substrings that match parenthetical groups
     *   in the regular expression index    The character position of the matched substring within
     *   the stringinput    The string (str)
     * @langversion 3.0
     * @playerversion   Flash 9
     * @playerversion   Lite 4
     */
    Object  *exec(std::string s);

    /**
     * Tests for the match of the regular expression in the given string str.
     *
     *   If the g (global) flag is not set for the regular expression,
     * then the search starts at the beginning of the string (at index position 0); the search ignores
     * the lastIndex property of the regular expression.If the g (global) flag is set for the regular expression, then the search starts
     * at the index position specified by the lastIndex property of the regular expression.
     * If the search matches a substring, the lastIndex property changes to match the
     * position of the end of the match.
     * @param   str The string to test.
     * @return  If there is a match, true; otherwise, false.
     * @langversion 3.0
     * @playerversion   Flash 9
     * @playerversion   Lite 4
     */
    bool     test(std::string s);
};

#endif // FLEX11_6_REGEXP_AS
#endif // __cplusplus

