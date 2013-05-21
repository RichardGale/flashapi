

    namespace AS3 {};
    bool ::bugzilla(int n)          ;
    /**
     * Decodes an encoded URI into a string. Returns a string in which all characters previously encoded 
     * by the encodeURI function are restored to their unencoded representation.
     * The following table shows the set of escape sequences that are not decoded to characters by the decodeURI function. Use decodeURIComponent() to decode the escape sequences in this table.Escape sequences not decodedCharacter equivalents%23#%24$%26&%2B+%2C,%2F/%3A:%3B;%3D=%3F?%40@
     * @param   uri A string encoded with the encodeURI function.
     * @return  A string in which all characters previously escaped by the encodeURI function are
     *   restored to their unescaped representation.
     * @langversion 3.0
     * @playerversion   Flash 9
     * @playerversion   Lite 4
     */
    std::string ::decodeURI(std::string uri)         ;
    /**
     * Decodes an encoded URI component into a string. Returns a string in which 
     * all characters previously escaped by the encodeURIComponent 
     * function are restored to their uncoded representation.
     * This function differs from the decodeURI() function in that it is intended for use only with a part of a URI string, called a URI component.
     * A URI component is any text that appears between special characters called component separators 
     * (: / ; and ? ). 
     * Common examples of a URI component are "http" and "www.adobe.com".Another important difference between this function and decodeURI() is that because this function
     * assumes that it is processing a URI component it treats the escape sequences that represent special separator characters (; / ? : @ & = + $ , #) as regular
     * text that should be decoded.
     * @param   uri A string encoded with the encodeURIComponent function.
     * @return  A string in which all characters previously escaped by the encodeURIComponent function are
     *   restored to their unescaped representation.
     * @langversion 3.0
     * @playerversion   Flash 9
     * @playerversion   Lite 4
     */
    std::string ::decodeURIComponent(std::string uri)         ;
    /**
     * Encodes a string into a valid URI (Uniform Resource Identifier). 
     * Converts a complete URI into a string in which all characters are encoded 
     * as UTF-8 escape sequences unless a character belongs to a small group of basic characters.
     * The following table shows the entire set of basic characters that are not converted to UTF-8 escape sequences by the encodeURI function.Characters not encoded0 1 2 3 4 5 6 7 8 9a b c d e f g h i j k l m n o p q r s t u v w x y zA B C D E F G H I J K L M N O P Q R S T U V W X Y Z; / ? : @ & = + $ , #- _ . ! ~ ~~ ' ( )
     * @param   uri A string representing a complete URI.
     * @return  A string with certain characters encoded as UTF-8 escape sequences.
     * @langversion 3.0
     * @playerversion   Flash 9
     * @playerversion   Lite 4
     */
    std::string ::encodeURI(std::string uri)         ;
    /**
     * Encodes a string into a valid URI component. Converts a substring of a URI into a 
     * string in which all characters are encoded as UTF-8 escape sequences unless a character
     * belongs to a very small group of basic characters.
     * The encodeURIComponent() function differs from the encodeURI() function in that it is intended for use only with a part of a URI string, called a URI component.
     * A URI component is any text that appears between special characters called component separators
     * (: / ; and ? ). 
     * Common examples of a URI component are "http" and "www.adobe.com".Another important difference between this function and encodeURI() is that because this function
     * assumes that it is processing a URI component it treats the special separator characters (; / ? : @ & = + $ , #) as regular
     * text that should be encoded. The following table shows all characters that are not converted to UTF-8 escape sequences by the encodeURIComponent function.Characters not encoded0 1 2 3 4 5 6 7 8 9a b c d e f g h i j k l m n o p q r s t u v w x y zA B C D E F G H I J K L M N O P Q R S T U V W X Y Z- _ . ! ~ ~~ ' ( )
     * @langversion 3.0
     * @playerversion   Flash 9
     * @playerversion   Lite 4
     */
    std::string ::encodeURIComponent(std::string uri)         ;
    /**
     * Returns true if the value is NaN(not a number). The isNaN() function is useful for checking whether a mathematical expression evaluates successfully to a number. 
     * The most common use of isNaN() is to check the value returned from the parseInt()and parseFloat() functions. The NaN value is a special member of the Number data type that represents a value that is "not a number." 
     * Note: The NaN value is not a member of the int or uint data types.The following table describes the return value of isNaN() on various input types and
     * values. (If your compiler warnings are set to Strict Mode, some of the following operations will generate
     * compiler warnings.)Input Type/ValueExampleReturn Value0 divided by 0isNaN(0/0)trueNon-zero number divided by 0isNaN(5/0)falseSquare root of a negative numberisNaN(Math.sqrt(-1))trueArcsine of number greater than 1 or less than 0isNaN(Math.asin(2))trueString that can be converted to NumberisNaN("5")falseString that cannot be converted to NumberisNaN("5a")true
     * @param   num A numeric value or mathematical expression to evaluate.
     * @return  Returns true if the value is NaN(not a number) and false otherwise.
     * @langversion 3.0
     * @playerversion   Flash 9
     * @playerversion   Lite 4
     */
    bool ::isNaN(float n)          ;
    /**
     * Returns true if the value is a finite number, 
     * or false if the value is Infinity or -Infinity.
     * The presence of Infinity or -Infinity indicates a mathematical
     * error condition such as division by 0.
     * @param   num A number to evaluate as finite or infinite.
     * @return  Returns true if it is a finite number 
     *   or false if it is infinity or negative infinity
     * @langversion 3.0.
     * @playerversion   Flash 9
     * @playerversion   Lite 4
     */
    bool ::isFinite(float n)          ;
    /**
     * Converts a string to an integer. If the specified string in the parameters cannot be converted to a number, the function returns NaN. Strings beginning with 0x are interpreted as hexadecimal numbers. Unlike in previous versions of ActionScript, integers beginning with 0 are not interpreted as octal numbers. You must specify a radix of 8 for octal numbers. White space and zeroes preceding valid integers are ignored, as are trailing nonnumeric characters.
     * @param   str A string to convert to an integer.
     * @param   radix   An integer representing the radix (base) of the number to parse. Legal values are from 2 to 36.
     * @return  A number or NaN (not a number).
     * @langversion 3.0
     * @playerversion   Flash 9
     * @playerversion   Lite 4
     */
    float ::parseInt(std::string s, int radix)         ;
    /**
     * Converts a string to a floating-point number. The function reads, or parses, and returns the numbers in a string until it reaches a character that is not a part of the initial number. If the string does not begin with a number that can be parsed, parseFloat() returns NaN. White space preceding valid integers is ignored, as are trailing nonnumeric characters.
     * @param   str The string to read and convert to a floating-point number.
     * @return  A number or NaN (not a number).
     * @langversion 3.0
     * @playerversion   Flash 9
     * @playerversion   Lite 4
     */
    float ::parseFloat(std::string str)         ;
    /**
     * Converts the parameter to a string and encodes it in a URL-encoded format, 
     * where most nonalphanumeric characters are replaced with % hexadecimal sequences. 
     * When used in a URL-encoded string, the percentage symbol (%) is used to introduce 
     * escape characters, and is not equivalent to the modulo operator (%).
     * The following table shows all characters that are not converted to escape sequences by the escape() function.Characters not encoded0 1 2 3 4 5 6 7 8 9a b c d e f g h i j k l m n o p q r s t u v w x y zA B C D E F G H I J K L M N O P Q R S T U V W X Y Z@ - _ . ~~ + /Note: Use the encodeURIComponent() function, instead of the escape() function, to treat 
     * special separator characters (@ + /) as regular
     * text to encode.
     * @param   str The expression to convert into a string and encode in a URL-encoded format.
     * @return  A URL-encoded string.
     * @langversion 3.0
     * @playerversion   Flash 9
     * @playerversion   Lite 4
     */
    std::string ::escape(std::string s)         ;
    /**
     * Evaluates the parameter str as a string, decodes the string from URL-encoded format 
     * (converting all hexadecimal sequences to ASCII characters), and returns the string.
     * @param   str A string with hexadecimal sequences to escape.
     * @return  A string decoded from a URL-encoded parameter.
     * @langversion 3.0
     * @playerversion   Flash 9
     * @playerversion   Lite 4
     */
    std::string ::unescape(std::string s)         ;
    /**
     * Determines whether the specified string is a valid name for an XML element or attribute.
     * @param   str A string to evaluate.
     * @return  Returns true if the str argument is a valid XML name; false otherwise.
     * @langversion 3.0
     * @playerversion   Flash 9
     * @playerversion   Lite 4
     */
    bool ::isXMLName(void* str)          ;



    /**
     * Displays expressions, or writes to log files, while debugging. A single trace statement can support multiple arguments. If any argument 
     * in a trace statement includes a data type other than a String, the trace function invokes the associated toString() method
     * for that data type. For example, if the argument is a Boolean value the trace function invokes Boolean.toString() and 
     * displays the return value.
     * @param   arguments   One or more (comma separated) expressions to evaluate. For multiple expressions, a space is inserted between each expression in the output.
     * @langversion 3.0
     * @playerversion   Flash 9
     * @playerversion   AIR 1.0
     * @playerversion   Lite 4
     */void ::trace(...)       ;
    bool ::watson(int n)          ;
