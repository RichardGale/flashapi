#if !defined(FLEX11_6_ARRAY_AS)
#define FLEX11_6_ARRAY_AS
#if defined(__cplusplus)


/**
 * The Array class lets you access and manipulate arrays. Array indices are zero-based, which means that the first element in the array is <codeph class="+ topic/ph pr-d/codeph ">[0]</codeph>, the second element is <codeph class="+ topic/ph pr-d/codeph ">[1]</codeph>, and so on. To create an Array object, you use the <codeph class="+ topic/ph pr-d/codeph ">new Array()</codeph> constructor . <codeph class="+ topic/ph pr-d/codeph ">Array()</codeph> can also be
 * invoked as a function. In addition, you can use the array access (<codeph class="+ topic/ph pr-d/codeph ">[]</codeph>) operator to initialize an array or access the elements of an array.
 * <p class="- topic/p ">You can store a wide variety of data types in an array element, including numbers, strings, objects, and even other arrays. You can create a <i class="+ topic/ph hi-d/i ">multidimensional</i> array by creating an indexed array and assigning to each of its elements a different indexed array. Such an array is considered multidimensional because it can be used to represent data in a table.</p><p class="- topic/p "> Arrays are <i class="+ topic/ph hi-d/i ">sparse arrays</i>, meaning there might be an element at index 0 and another at index 5, but nothing in the index positions between those two elements. In such a case, the elements in positions 1 through 4 are undefined, which indicates the absence of an element, not necessarily the presence of an element with the value <codeph class="+ topic/ph pr-d/codeph ">undefined</codeph>.</p><p class="- topic/p ">Array assignment is by reference rather than by value. When you assign one array variable to another array variable, both refer to the same array:</p><codeblock xml:space="preserve" class="+ topic/pre pr-d/codeblock ">
 * var oneArray:Array = new Array("a", "b", "c");
 * var twoArray:Array = oneArray; // Both array variables refer to the same array.
 * twoArray[0] = "z";
 * trace(oneArray);               // Output: z,b,c.
 * </codeblock><p class="- topic/p ">Do not use the Array class to create <i class="+ topic/ph hi-d/i ">associative arrays</i> (also called <i class="+ topic/ph hi-d/i ">hashes</i>), which are data
 * structures that contain named elements instead of numbered elements. To create associative arrays, use the Object class.
 * Although ActionScript permits you to create associative arrays using the Array class, you cannot use any of the Array class methods or properties with associative arrays. </p><p class="- topic/p ">You can extend the Array class and override or add methods. However, you must specify the subclass as <codeph class="+ topic/ph pr-d/codeph ">dynamic</codeph>
 * or you will lose the ability to store data in an array.</p>
 *
 *   EXAMPLE:
 *
 *   The following example creates a new Array object <codeph class="+ topic/ph pr-d/codeph ">myArr</codeph> with no arguments
 * and an initial length of 0:
 * <codeblock xml:space="preserve" class="+ topic/pre pr-d/codeblock ">
 * package {
 * import flash.display.Sprite;
 *
 *   public class ArrayExample extends Sprite {
 * public function ArrayExample() {
 * var myArr:Array = new Array();
 * trace(myArr.length); // 0
 * }
 * }
 * }
 * </codeblock>
 * @langversion 3.0
 * @playerversion   Flash 9
 * @playerversion   Lite 4
 */

#include "flex11.6.h"



class Array : public Object
{
    /**
     * Specifies case-insensitive sorting for the Array class sorting methods. You can use this constant
     * for the options parameter in the sort() or sortOn() method.
     * The value of this constant is 1.
     * @langversion 3.0
     * @playerversion   Flash 9
     * @playerversion   Lite 4
     */
public:
    static const unsigned int CASEINSENSITIVE;

    /**
     * Specifies descending sorting for the Array class sorting methods.
     * You can use this constant for the options parameter in the sort()
     * or sortOn() method.
     * The value of this constant is 2.
     * @langversion 3.0
     * @playerversion   Flash 9
     * @playerversion   Lite 4
     */
public:
    static const unsigned int DESCENDING;

    /**
     * Specifies the unique sorting requirement for the Array class sorting methods.
     * You can use this constant for the options parameter in the sort() or sortOn()
     * method. The unique sorting option terminates the sort if any two elements
     * or fields being sorted have identical values.
     * The value of this constant is 4.
     * @langversion 3.0
     * @playerversion   Flash 9
     * @playerversion   Lite 4
     */
public:
    static const unsigned int UNIQUESORT;

    /**
     * Specifies that a sort returns an array that consists of array indices. You can use this constant
     * for the options parameter in the sort() or sortOn()
     * method, so you have access to multiple views of the array elements while the original array is unmodified.
     * The value of this constant is 8.
     * @langversion 3.0
     * @playerversion   Flash 9
     * @playerversion   Lite 4
     */
public:
    static const unsigned int RETURNINDEXEDARRAY;

    /**
     * Specifies numeric (instead of character-string) sorting for the Array class sorting methods.
     * Including this constant in the options
     * parameter causes the sort() and sortOn() methods
     * to sort numbers as numeric values, not as strings of numeric characters.
     * Without the NUMERIC constant, sorting treats each array element as a
     * character string and produces the results in Unicode order.
     *
     *   For example, given the array of values [2005, 7, 35], if the NUMERIC
     * constant is not included in the options parameter, the
     * sorted array is [2005, 35, 7], but if the NUMERIC constant is included,
     * the sorted array is [7, 35, 2005]. This constant applies only to numbers in the array; it does
     * not apply to strings that contain numeric data such as ["23", "5"].The value of this constant is 16.
     * @langversion 3.0
     * @playerversion   Flash 9
     * @playerversion   Lite 4
     */
public:
    static const unsigned int NUMERIC;
public:
    static const int length;

    /**
     * A non-negative integer specifying the number of elements in the array. This property is automatically updated when new elements are added to the array. When you assign a value to an array element (for example, my_array[index] = value), if index is a number, and index+1 is greater than the length property, the length property is updated to index+1.
     * Note: If you assign a value to the length property that is shorter than the existing length, the array will be truncated.
     * @langversion 3.0
     * @playerversion   Flash 9
     * @playerversion   Lite 4
     */
public:
    unsigned int         length();
public:
    void         length(unsigned int newLength);

public:
    Array(...);

    /**
     * Converts the elements in an array to strings, inserts the specified separator between the
     * elements, concatenates them, and returns the resulting string. A nested array is always
     * separated by a comma (,), not by the separator passed to the join() method.
     * @param   sep A character or string that separates array elements in
     *   the returned string. If you omit this parameter, a comma is used as the default
     *   separator.
     * @return  A string consisting of the elements of an array
     *   converted to strings and separated by the specified parameter.
     * @langversion 3.0
     * @playerversion   Flash 9
     * @playerversion   Lite 4
     */
    std::string   join(void *sep=NULL);

    /**
     * Removes the last element from an array and returns the value of that element.
     * @return  The value of the last element (of any data type) in the specified array.
     * @langversion 3.0
     * @playerversion   Flash 9
     * @playerversion   Lite 4
     */
    void        *pop();

    /**
     * Adds one or more elements to the end of an array and returns the new length of the array.
     * @param   args    One or more values to append to the array.
     * @return  An integer representing the length of the new array.
     * @langversion 3.0
     * @playerversion   Flash 9
     * @playerversion   Lite 4
     */
    unsigned int     push(...);

    /**
     * Reverses the array in place.
     * @return  The new array.
     * @langversion 3.0
     * @playerversion   Flash 9
     * @playerversion   Lite 4
     */
    std::vector<void *>    reverse();

    /**
     * Concatenates the elements specified in the parameters with the elements in an array and creates a new array.
     * If the parameters specify an array, the elements of that array are concatenated. If you don't
     * pass any parameters, the new array is a duplicate (shallow clone) of the original array.
     * @param   args    A value of any data type (such as numbers, elements, or strings) to be concatenated in a new array.
     * @return  An array that contains the elements from this array followed by elements from
     *   the parameters.
     * @langversion 3.0
     * @playerversion   Flash 9
     * @playerversion   Lite 4
     */
    std::vector<void *>    concat(...);

    /**
     * Removes the first element from an array and returns that element. The remaining array elements are moved
     * from their original position, i, to i-1.
     * @return  The first element (of any data type) in an array.
     * @langversion 3.0
     * @playerversion   Flash 9
     * @playerversion   Lite 4
     */
    void        *shift();

    /**
     * Returns a new array that consists of a range of elements from the original array, without modifying the original array.
     * The returned array includes the startIndex element and all elements up to, but not including, the endIndex element.
     *
     *   If you don't pass any parameters, the new array is a duplicate (shallow clone) of the original array.
     * @param   startIndex  A number specifying the index of the starting point
     *   for the slice. If startIndex is a negative number, the starting
     *   point begins at the end of the array, where -1 is the last element.
     * @param   endIndex    A number specifying the index of the ending point for
     *   the slice. If you omit this parameter, the slice includes all elements from the
     *   starting point to the end of the array. If endIndex is a negative
     *   number, the ending point is specified from the end of the array, where -1 is the
     *   last element.
     * @return  An array that consists of a range of elements from the original array.
     * @langversion 3.0
     * @playerversion   Flash 9
     * @playerversion   Lite 4
     */
    std::vector<void *>    slice(void *A=0, void *B=4294967295);

    /**
     * Adds one or more elements to the beginning of an array and returns the new length of the array. The other
     * elements in the array are moved from their original position, i, to i+1.
     * @param   args    One or more numbers, elements, or variables to be inserted at the beginning of the array.
     * @return  An integer representing the new length of the array.
     * @langversion 3.0
     * @playerversion   Flash 9
     * @playerversion   Lite 4
     */
    unsigned int     unshift(...);

    /**
     * Adds elements to and removes elements from an array. This method modifies the array without
     * making a copy.
     * Note: To override this method in a subclass of Array, use ...args for the parameters,
     * as this example shows:
     * public override function splice(...args) {
     * // your statements here
     * }
     * @param   startIndex  An integer that specifies the index of the element in the array where the insertion or
     *   deletion begins. You can use a negative integer to specify a position relative to the end of the array
     *   (for example, -1 is the last element of the array).
     * @param   deleteCount An integer that specifies the number of elements to be deleted. This number includes the
     *   element specified in the startIndex parameter. If you do not specify a value for the
     *   deleteCount parameter, the method deletes all of the values from the startIndex
     *   element to the last element in the array. If the value is 0, no elements are deleted.
     * @param   values  An optional list of one or more comma-separated values
     *   to insert into the array at the position specified in the startIndex parameter.
     *   If an inserted value is of type Array, the array is kept intact and inserted as a single element.
     *   For example, if you splice an existing array of length three with another array of length three,
     *   the resulting array will have only four elements. One of the elements, however, will be an array of length three.
     * @return  An array containing the elements that were removed from the original array.
     * @langversion 3.0
     * @playerversion   Flash 9
     * @playerversion   Lite 4
     */
    std::vector<void *>    splice(...);

    /**
     * Sorts the elements in an array. This method sorts according to Unicode values. (ASCII is a subset of Unicode.)
     * By default, Array.sort() works in the following way:Sorting is case-sensitive (Z precedes a).Sorting is ascending (a precedes b). The array is modified to reflect the sort order; multiple elements that have identical sort fields are placed consecutively in the sorted array in no particular order.All elements, regardless of data type, are sorted as if they were strings, so 100 precedes 99, because "1" is a lower string value than "9".
     * To sort an array by using settings that deviate from the default settings,
     * you can either use one of the sorting options described in the sortOptions portion of the ...args parameter description, or you can create your own custom function to do the sorting.
     * If you create a custom function, you call the sort() method, and use the name
     * of your custom function as the first argument (compareFunction)
     * @param   args    The arguments specifying a comparison function and one or more values that determine the behavior of the sort.
     *   This method uses the syntax and argument order Array.sort(compareFunction, sortOptions) with the arguments defined as follows:compareFunction - A comparison function used to determine the sorting order of elements in an array. This argument is optional. A comparison function should take two arguments to compare. Given the elements A and B, the result of compareFunction can have a negative, 0, or positive value:
     *   A negative return value specifies that A appears before B in the sorted sequence.A return value of 0 specifies that A and B have the same sort order.A positive return value specifies that A appears after B in the sorted sequence.sortOptions - One or more numbers or defined constants, separated by the | (bitwise OR) operator, that change the behavior of the sort from the default. This argument is optional. The following values are acceptable for sortOptions:
     *   1 or Array.CASEINSENSITIVE2 or Array.DESCENDING4 or Array.UNIQUESORT8 or Array.RETURNINDEXEDARRAY16 or Array.NUMERIC
     *   For more information, see the Array.sortOn() method.
     * @return  The return value depends on whether you pass any arguments, as described in
     *   the following list:
     *   If you specify a value of 4 or Array.UNIQUESORT for the sortOptions argument
     *   of the ...args parameter and two or more elements being sorted have identical sort fields,
     *   Flash returns a value of 0 and does not modify the array. If you specify a value of 8 or Array.RETURNINDEXEDARRAY for
     *   the sortOptions argument of the ...args parameter, Flash returns a sorted numeric
     *   array of the indices that reflects the results of the sort and does not modify the array. Otherwise, Flash returns nothing and modifies the array to reflect the sort order.
     * @langversion 3.0
     * @playerversion   Flash 9
     * @playerversion   Lite 4
     */
    std::vector<void *>    sort(...);

    /**
     * Sorts the elements in an array according to one or more fields in the array.
     * The array should have the following characteristics:
     * The array is an indexed array, not an associative array.Each element of the array holds an object with one or more properties.All of the objects have at least one property in common, the values of which can be used
     * to sort the array. Such a property is called a field.If you pass multiple fieldName parameters, the first field represents the primary sort field, the second represents the next sort field, and so on. Flash sorts according to Unicode values. (ASCII is a subset of Unicode.) If either of the elements being compared does not contain the field that is specified in the fieldName parameter, the field is assumed to be set to undefined, and the elements are placed consecutively in the sorted array in no particular order.By default, Array.sortOn() works in the following way:Sorting is case-sensitive (Z precedes a).Sorting is ascending (a precedes b). The array is modified to reflect the sort order; multiple elements that have identical sort fields are placed consecutively in the sorted array in no particular order.Numeric fields are sorted as if they were strings, so 100 precedes 99, because "1" is a lower string value than "9".Flash Player 7 added the options parameter, which you can use to override the default sort behavior. To sort a simple array (for example, an array with only one field), or to specify a sort order that the options parameter doesn't support, use Array.sort().To pass multiple flags, separate them with the bitwise OR (|) operator:
     * <codeblock>
     *
     *   my_array.sortOn(someFieldName, Array.DESCENDING | Array.NUMERIC);
     *
     *   </codeblock>
     * Flash Player 8 added the ability to specify a different sorting option for each field when you sort by more than one field. In Flash Player 8 and later, the options parameter accepts an array of sort options such that each sort option corresponds to a sort field in the fieldName parameter. The following example sorts the primary sort field, a, using a descending sort; the secondary sort field, b, using a numeric sort; and the tertiary sort field, c, using a case-insensitive sort:
     * <codeblock>
     *
     *   Array.sortOn (["a", "b", "c"], [Array.DESCENDING, Array.NUMERIC, Array.CASEINSENSITIVE]);
     *
     *   </codeblock>
     * Note: The fieldName and options arrays must have the same number of elements; otherwise, the options array is ignored. Also, the Array.UNIQUESORT and Array.RETURNINDEXEDARRAY options can be used only as the first element in the array; otherwise, they are ignored.
     * @param   fieldName   A string that identifies a field to be used as the sort value, or an
     *   array in which the first element represents the primary sort field, the  second represents
     *   the secondary sort field, and so on.
     * @param   options One or more numbers or names of defined constants, separated by the bitwise OR (|) operator, that change the sorting behavior. The following values are acceptable for the options parameter:
     *   Array.CASEINSENSITIVE or 1Array.DESCENDING or 2Array.UNIQUESORT or 4Array.RETURNINDEXEDARRAY or 8Array.NUMERIC or 16Code hinting is enabled if you use the string form of the flag (for example, DESCENDING) rather than the numeric form (2).
     * @return  The return value depends on whether you pass any parameters:
     *   If you specify a value of 4 or Array.UNIQUESORT for the options parameter, and two or more elements being sorted have identical sort fields, a value of 0 is returned and the array is not modified. If you specify a value of 8 or Array.RETURNINDEXEDARRAY for the options parameter, an array is returned that reflects the results of the sort and the array is not modified.Otherwise, nothing is returned and the array is modified to reflect the sort order.
     * @langversion 3.0
     * @playerversion   Flash 9
     * @playerversion   Lite 4
     */
    std::vector<void *>    sortOn(void *names, void *options=0, ...);

    /**
     * Searches for an item in an array by using strict equality (===) and returns the index
     * position of the item.
     * @param   searchElement   The item to find in the array.
     * @param   fromIndex   The location in the array from which to start searching for the item.
     * @return  A zero-based index position of the item in the array. If the searchElement argument
     *   is not found, the return value is -1.
     * @langversion 3.0
     * @playerversion   Flash 9
     * @playerversion   Lite 4
     */
    int      indexOf(void *searchElement, void *fromIndex=0);

    /**
     * Searches for an item in an array, working backward from the last item, and returns the index position of the matching item using strict equality (===).
     * @param   searchElement   The item to find in the array.
     * @param   fromIndex   The location in the array from which to start searching for the item. The default is the maximum
     *   value allowed for an index. If you do not specify fromIndex, the search starts at the last item
     *   in the array.
     * @return  A zero-based index position of the item in the array. If the searchElement argument is
     *   not found, the return value is -1.
     * @langversion 3.0
     * @playerversion   Flash 9
     * @playerversion   Lite 4
     */
    int      lastIndexOf(void *searchElement, void *fromIndex=2147483647);

    /**
     * Executes a test function on each item in the array until an item is reached that returns false for the
     * specified function. You use this method to determine whether all items in an array meet a criterion, such as having values
     * less than a particular number.
     *
     *   For this method, the second parameter, thisObject, must be null if the
     * first parameter, callback, is a method closure. Suppose you create a function in a movie clip
     * called me:
     * function myFunction(obj:Object):void {
     * //your code here
     * }
     * Suppose you then use the every() method on an array called myArray:
     * myArray.every(myFunction, me);
     * Because myFunction is a member of the Timeline class, which cannot be overridden
     * by me, the Flash runtime will throw an exception.
     * You can avoid this runtime error by assigning the function to a variable, as follows:
     * var myFunction:Function = function(obj:Object):void {
     * //your code here
     * };
     * myArray.every(myFunction, me);
     * @param   callback    The function to run on each item in the array. This function can contain a simple comparison (for example, item < 20) or a more complex operation, and is invoked with three arguments; the
     *   value of an item, the index of an item, and the Array object:
     *   function callback(item:*, index:int, array:Array):Boolean;
     * @param   thisObject  An object to use as this for the function.
     * @return  A Boolean value of true if all items in the array return true for the specified function; otherwise, false.
     * @langversion 3.0
     * @playerversion   Flash 9
     * @playerversion   Lite 4
     */
    bool  every(Function *callback, void *thisObject=NULL);

    /**
     * Executes a test function on each item in the array and constructs a new array for all items that return true for the specified function. If an item returns false, it is not included in the new array.
     *
     *   For this method, the second parameter, thisObject, must be null if the
     * first parameter, callback, is a method closure. Suppose you create a function in a movie clip
     * called me:
     * function myFunction(obj:Object):void {
     * //your code here
     * }
     * Suppose you then use the filter() method on an array called myArray:
     * myArray.filter(myFunction, me);
     * Because myFunction is a member of the Timeline class, which cannot be overridden
     * by me, the Flash runtime will throw an exception.
     * You can avoid this runtime error by assigning the function to a variable, as follows:
     * var myFunction:Function = function(obj:Object):void {
     * //your code here
     * };
     * myArray.filter(myFunction, me);
     * @param   callback    The function to run on each item in the array. This function can contain a simple comparison (for example, item < 20) or a more complex operation, and is invoked with three arguments; the
     *   value of an item, the index of an item, and the Array object:
     *   function callback(item:*, index:int, array:Array):Boolean;
     * @param   thisObject  An object to use as this for the function.
     * @return  A new array that contains all items from the original array that returned true.
     * @langversion 3.0
     * @playerversion   Flash 9
     * @playerversion   Lite 4
     */
    std::vector<void *>    filter(Function *callback, void *thisObject=NULL);

    /**
     * Executes a function on each item in the array.
     *
     *   For this method, the second parameter, thisObject, must be null if the
     * first parameter, callback, is a method closure. Suppose you create a function in a movie clip
     * called me:
     * function myFunction(obj:Object):void {
     * //your code here
     * }
     * Suppose you then use the forEach() method on an array called myArray:
     * myArray.forEach(myFunction, me);
     * Because myFunction is a member of the Timeline class, which cannot be overridden
     * by me, the Flash runtime will throw an exception.
     * You can avoid this runtime error by assigning the function to a variable, as follows:
     * var myFunction:Function = function(obj:Object):void {
     * //your code here
     * };
     * myArray.forEach(myFunction, me);
     * @param   callback    The function to run on each item in the array. This function can contain a simple command
     *   (for example, a trace() statement) or a more complex operation, and is invoked with three arguments; the
     *   value of an item, the index of an item, and the Array object:
     *   function callback(item:*, index:int, array:Array):void;
     * @param   thisObject  An object to use as this for the function.
     * @langversion 3.0
     * @playerversion   Flash 9
     * @playerversion   Lite 4
     */
    void     forEach(Function *callback, void *thisObject=NULL);

    /**
     * Executes a function on each item in an array, and constructs a new array of items corresponding to the results of the function on
     * each item in the original array.
     *
     *   For this method, the second parameter, thisObject, must be null if the
     * first parameter, callback, is a method closure. Suppose you create a function in a movie clip
     * called me:
     * function myFunction(obj:Object):void {
     * //your code here
     * }
     * Suppose you then use the map() method on an array called myArray:
     * myArray.map(myFunction, me);
     * Because myFunction is a member of the Timeline class, which cannot be overridden
     * by me, the Flash runtime will throw an exception.
     * You can avoid this runtime error by assigning the function to a variable, as follows:
     * var myFunction:Function = function(obj:Object):void {
     * //your code here
     * };
     * myArray.map(myFunction, me);
     * @param   callback    The function to run on each item in the array. This function can contain a simple command (such as changing the case of an array of strings) or a more complex operation, and is invoked with three arguments; the
     *   value of an item, the index of an item, and the Array object:
     *   function callback(item:*, index:int, array:Array):String;
     * @param   thisObject  An object to use as this for the function.
     * @return  A new array that contains the results of the function on each item in the original array.
     * @langversion 3.0
     * @playerversion   Flash 9
     * @playerversion   Lite 4
     */
    std::vector<void *>    map(Function *callback, void *thisObject=NULL);

    /**
     * Executes a test function on each item in the array until an item is reached that returns true. Use this method to determine whether any items in an array meet a criterion, such as having a value less than a particular number.
     *
     *   For this method, the second parameter, thisObject, must be null if the
     * first parameter, callback, is a method closure. Suppose you create a function in a movie clip
     * called me:
     * function myFunction(obj:Object):void {
     * //your code here
     * }
     * Suppose you then use the some() method on an array called myArray:
     * myArray.some(myFunction, me);
     * Because myFunction is a member of the Timeline class, which cannot be overridden
     * by me, the Flash runtime will throw an exception.
     * You can avoid this runtime error by assigning the function to a variable, as follows:
     * var myFunction:Function = function(obj:Object):void {
     * //your code here
     * };
     * myArray.some(myFunction, me);
     * @param   callback    The function to run on each item in the array. This function can contain a simple comparison (for example
     *   item < 20) or a more complex operation, and is invoked with three arguments; the
     *   value of an item, the index of an item, and the Array object:
     *   function callback(item:*, index:int, array:Array):Boolean;
     * @param   thisObject  An object to use as this for the function.
     * @return  A Boolean value of true if any items in the array return true for the specified function; otherwise false.
     * @langversion 3.0
     * @playerversion   Flash 9
     * @playerversion   Lite 4
     */
    bool  some(Function *callback, void *thisObject=NULL);
};

#endif // FLEX11_6_ARRAY_AS
#endif // __cplusplus

