

#include "IDataInput.h"
#include "flash/utils/ByteArray.h"

    /**
     * The IDataInput interface provides a set of methods for reading binary data. 
     * This interface is the I/O counterpart to the IDataOutput interface, which 
     * writes binary data.
     * <p class="- topic/p ">All IDataInput and IDataOutput operations are "bigEndian" by default (the most significant 
     * byte in the sequence is stored at the lowest or first storage address), 
     * and are nonblocking.  
     * If insufficient data is available, an <codeph class="+ topic/ph pr-d/codeph ">EOFError</codeph> exception  
     * is thrown. Use the <codeph class="+ topic/ph pr-d/codeph ">IDataInput.bytesAvailable</codeph> property to determine 
     * how much data is available to read.</p><p class="- topic/p ">Sign extension matters only when you read data, not when you write it. Therefore you do not need separate
     * write methods to work with <codeph class="+ topic/ph pr-d/codeph ">IDataInput.readUnsignedByte()</codeph> and 
     * <codeph class="+ topic/ph pr-d/codeph ">IDataInput.readUnsignedShort()</codeph>. In other words:</p><ul class="- topic/ul "><li class="- topic/li ">Use <codeph class="+ topic/ph pr-d/codeph ">IDataOutput.writeByte()</codeph> with <codeph class="+ topic/ph pr-d/codeph ">IDataInput.readUnsignedByte()</codeph> and 
     * <codeph class="+ topic/ph pr-d/codeph ">IDataInput.readByte()</codeph>.</li><li class="- topic/li ">Use <codeph class="+ topic/ph pr-d/codeph ">IDataOutput.writeShort()</codeph> with <codeph class="+ topic/ph pr-d/codeph ">IDataInput.readUnsignedShort()</codeph> and 
     * <codeph class="+ topic/ph pr-d/codeph ">IDataInput.readShort()</codeph>.</li></ul>
     * 
     *   EXAMPLE:
     * 
     *   The following example uses the class <codeph class="+ topic/ph pr-d/codeph ">DataInputExample</codeph> to write a boolean
     * and the double-precision floating-point representation of pi to a byte array.  This is accomplished 
     * using the following steps:
     * <ol class="- topic/ol "><li class="- topic/li ">Declare a new ByteArray object instance <codeph class="+ topic/ph pr-d/codeph ">byteArr</codeph>.</li><li class="- topic/li ">Write the byte-equivalent value of the Boolean <codeph class="+ topic/ph pr-d/codeph ">false</codeph> and the  double-precision 
     * floating-point equivalent of the mathematical value of pi.</li><li class="- topic/li ">Read back the boolean and double-precision floating-point number.</li></ol><p class="- topic/p ">Notice how a code segment is added at the end to check for end of file errors to ensure that
     * the byte stream is not read past its end.</p><codeblock xml:space="preserve" class="+ topic/pre pr-d/codeblock ">
     * package {
     * import flash.display.Sprite;
     * import flash.utils.ByteArray;
     * import flash.errors.EOFError;
     * 
     *   public class DataInputExample extends Sprite {        
     * public function DataInputExample() {
     * var byteArr:ByteArray = new ByteArray();
     * 
     *   byteArr.writeBoolean(false);
     * byteArr.writeDouble(Math.PI);
     * 
     *   byteArr.position = 0;
     * 
     *   try {
     * trace(byteArr.readBoolean()); // false
     * } 
     * catch(e:EOFError) {
     * trace(e);           // EOFError: Error #2030: End of file was encountered.
     * }
     * 
     *   try {
     * trace(byteArr.readDouble());    // 3.141592653589793
     * } 
     * catch(e:EOFError) {
     * trace(e);           // EOFError: Error #2030: End of file was encountered.
     * }
     * 
     *   try {
     * trace(byteArr.readDouble());
     * } 
     * catch(e:EOFError) {
     * trace(e);        // EOFError: Error #2030: End of file was encountered.
     * }
     * }
     * }
     * }
     * </codeblock>
     * @langversion 3.0
     * @playerversion   Flash 9
     * @playerversion   Lite 4
     */
