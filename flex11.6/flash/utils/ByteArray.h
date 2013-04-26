#if !defined(FLEX11_6_FLASH_UTILS_BYTEARRAY_AS)
#define FLEX11_6_FLASH_UTILS_BYTEARRAY_AS
#if defined(__cplusplus)




/**
 * The ByteArray class provides methods and properties to optimize reading, writing,
 * and working with binary data.
 *
 *   <p class="- topic/p "><i class="+ topic/ph hi-d/i ">Note:</i> The ByteArray class is for advanced developers who need to access
 * data on the byte level.</p><p class="- topic/p ">In-memory data is a packed array (the most compact representation for the data type)
 * of bytes, but an instance of the ByteArray
 * class can be manipulated with the standard <codeph class="+ topic/ph pr-d/codeph ">[]</codeph> (array access) operators.
 * It also can be read and written to as an in-memory file, using
 * methods similar to those in the URLStream and Socket classes.</p><p class="- topic/p ">In addition, zlib compression and decompression are supported, as
 * well as Action Message Format (AMF) object serialization.</p><p class="- topic/p ">Possible uses of the ByteArray class include the following:
 *
 *   <ul class="- topic/ul "><li class="- topic/li ">Creating a custom protocol to connect to a server.</li><li class="- topic/li ">Writing your own URLEncoder/URLDecoder.</li><li class="- topic/li ">Writing your own AMF/Remoting packet.</li><li class="- topic/li ">Optimizing the size of your data by using data types.</li><li class="- topic/li ">Working with binary data loaded from a file in
 * Adobe<sup class="+ topic/ph hi-d/sup ">  </sup> AIR<sup class="+ topic/ph hi-d/sup ">  </sup>.</li></ul></p>
 *
 *   EXAMPLE:
 *
 *   The following example uses the class <codeph class="+ topic/ph pr-d/codeph ">ByteArrayExample</codeph> to write a Boolean
 * and the double-precision floating-point representation of pi to a byte array.  This is accomplished
 * using the following steps:
 * <ol class="- topic/ol "><li class="- topic/li ">Declare a new ByteArray object instance <codeph class="+ topic/ph pr-d/codeph ">byteArr</codeph>.</li><li class="- topic/li ">Write the byte-equivalent value of the Boolean <codeph class="+ topic/ph pr-d/codeph ">false</codeph> and then check the length and
 * read it back.</li><li class="- topic/li ">Write the double-precision floating-point equivalent of the mathematical value of pi.</li><li class="- topic/li ">Read back each of the nine bytes written into the byte array.</li></ol><p class="- topic/p "><b class="+ topic/ph hi-d/b ">Note: </b>when <codeph class="+ topic/ph pr-d/codeph ">trace()</codeph> is called on a byte, it prints the decimal equivalent
 * of the bytes stored in the byte array.</p><p class="- topic/p ">Notice how a code segment is added at the end to check for end of file errors to ensure that
 * the byte stream is not read past its end.</p><codeblock xml:space="preserve" class="+ topic/pre pr-d/codeblock ">
 * package {
 * import flash.display.Sprite;
 * import flash.utils.ByteArray;
 * import flash.errors.EOFError;
 *
 *   public class ByteArrayExample extends Sprite {
 * public function ByteArrayExample() {
 * var byteArr:ByteArray = new ByteArray();
 *
 *   byteArr.writeBoolean(false);
 * trace(byteArr.length);            // 1
 * trace(byteArr[0]);            // 0
 *
 *   byteArr.writeDouble(Math.PI);
 * trace(byteArr.length);            // 9
 * trace(byteArr[0]);            // 0
 * trace(byteArr[1]);            // 64
 * trace(byteArr[2]);            // 9
 * trace(byteArr[3]);            // 33
 * trace(byteArr[4]);            // 251
 * trace(byteArr[5]);            // 84
 * trace(byteArr[6]);            // 68
 * trace(byteArr[7]);            // 45
 * trace(byteArr[8]);            // 24
 *
 *   byteArr.position = 0;
 *
 *   try {
 * trace(byteArr.readBoolean() == false); // true
 * }
 * catch(e:EOFError) {
 * trace(e);           // EOFError: Error #2030: End of file was encountered.
 * }
 *
 *   try {
 * trace(byteArr.readDouble());        // 3.141592653589793
 * }
 * catch(e:EOFError) {
 * trace(e);           // EOFError: Error #2030: End of file was encountered.
 * }
 *
 *   try {
 * trace(byteArr.readDouble());
 * }
 * catch(e:EOFError) {
 * trace(e);            // EOFError: Error #2030: End of file was encountered.
 * }
 * }
 * }
 * }
 * </codeblock>
 * @langversion 3.0
 * @playerversion   Flash 9
 * @playerversion   Lite 4
 */

namespace flash
{
    namespace utils
    {
        class ByteArray: public Object, public IDataInput2,, public IDataOutput2
        {
            /**
             * Denotes the default object encoding for the ByteArray class to use for a new ByteArray instance.
             * When you create a new ByteArray instance, the encoding on that instance starts
             * with the value of defaultObjectEncoding.
             * The defaultObjectEncoding property is initialized to ObjectEncoding.AMF3.
             *
             *   When an object is written to or read from binary data, the objectEncoding value
             * is used to determine whether the ActionScript 3.0, ActionScript2.0, or ActionScript 1.0 format should be used. The value is a
             * constant from the ObjectEncoding class.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            static unsigned int defaultObjectEncoding();
        public:
            static void         defaultObjectEncoding(unsigned int version);

            /**
             * The length of the ByteArray object, in bytes.
             *
             *   If the length is set to a value that is larger than the current length,
             * the right side  of the byte array is filled with zeros.If the length is set to a value that is smaller than the
             * current length, the byte array is truncated.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            unsigned int length();
        public:
            void         length(unsigned int value);

            /**
             * The number of bytes of data available for reading
             * from the current position in the byte array to the
             * end of the array.
             *
             *   Use the bytesAvailable property in conjunction
             * with the read methods each time you access a ByteArray object
             * to ensure that you are reading valid data.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            unsigned int bytesAvailable();

            /**
             * Moves, or returns the current position, in bytes, of the file
             * pointer into the ByteArray object. This is the
             * point at which the next call to a read
             * method starts reading or a write
             * method starts writing.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            unsigned int position();
        public:
            void         position(unsigned int offset);

            /**
             * Used to determine whether the ActionScript 3.0, ActionScript 2.0, or ActionScript 1.0 format should be
             * used when writing to, or reading from, a ByteArray instance. The value is a
             * constant from the ObjectEncoding class.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            unsigned int objectEncoding();
        public:
            void         objectEncoding(unsigned int version);

            /**
             * Changes or reads the byte order for the data; either Endian.BIG_ENDIAN or
             * Endian.LITTLE_ENDIAN.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            std::string  endian();
        public:
            void         endian(std::string type);

        public:
            bool         shareable();
        public:
            void         shareable(bool newValue);

            /**
             * Creates a ByteArray instance representing a packed array of bytes, so that you can use the methods and properties in this class to optimize your data storage and stream.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            ByteArray();

            /**
             * Reads the number of data bytes, specified by the length parameter, from the byte stream.
             * The bytes are read into the ByteArray object specified by the bytes parameter,
             * and the bytes are written into the destination ByteArray starting at the position specified by offset.
             * @param   bytes   The ByteArray object to read data into.
             * @param   offset  The offset (position) in bytes at which the read data should be written.
             * @param   length  The number of bytes to read.  The default value of 0 causes all available data to be read.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             * @throws  EOFError There is not sufficient data available
             *   to read.
             * @throws  RangeError The value of the supplied offset and length, combined, is greater than the maximum for a uint.
             */
        public:
            void     readBytes(ByteArray *bytes, unsigned int offset, unsigned int length);

            /**
             * Writes a sequence of length bytes from the
             * specified byte array, bytes,
             * starting offset(zero-based index) bytes
             * into the byte stream.
             *
             *   If the length parameter is omitted, the default
             * length of 0 is used; the method writes the entire buffer starting at
             * offset.
             * If the offset parameter is also omitted, the entire buffer is
             * written. If offset or length
             * is out of range, they are clamped to the beginning and end
             * of the bytes array.
             * @param   bytes   The ByteArray object.
             * @param   offset  A zero-based index indicating the position into the array to begin writing.
             * @param   length  An unsigned integer indicating how far into the buffer to write.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            void     writeBytes(ByteArray *bytes, unsigned int offset, unsigned int length);

            /**
             * Writes a Boolean value. A single byte is written according to the value parameter,
             * either 1 if true or 0 if false.
             * @param   value   A Boolean value determining which byte is written. If the parameter is true,
             *   the method writes a 1; if false, the method writes a 0.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            void     writeBoolean(bool value);

            /**
             * Writes a byte to the byte stream.
             * The low 8 bits of the
             * parameter are used. The high 24 bits are ignored.
             * @param   value   A 32-bit integer. The low 8 bits are written to the byte stream.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            void     writeByte(int value);

            /**
             * Writes a 16-bit integer to the byte stream. The low 16 bits of the parameter are used.
             * The high 16 bits are ignored.
             * @param   value   32-bit integer, whose low 16 bits are written to the byte stream.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            void     writeShort(int value);

            /**
             * Writes a 32-bit signed integer to the byte stream.
             * @param   value   An integer to write to the byte stream.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            void     writeInt(int value);

            /**
             * Writes a 32-bit unsigned integer to the byte stream.
             * @param   value   An unsigned integer to write to the byte stream.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            void     writeUnsignedInt(unsigned int value);

            /**
             * Writes an IEEE 754 single-precision (32-bit) floating-point number to the byte stream.
             * @param   value   A single-precision (32-bit) floating-point number.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            void     writeFloat(float value);

            /**
             * Writes an IEEE 754 double-precision (64-bit) floating-point number to the byte stream.
             * @param   value   A double-precision (64-bit) floating-point number.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            void     writeDouble(float value);

            /**
             * Writes a multibyte string to the byte stream using the specified character set.
             * @param   value   The string value to be written.
             * @param   charSet The string denoting the character set to use. Possible character set strings
             *   include "shift-jis", "cn-gb", "iso-8859-1", and others.
             *   For a complete list, see Supported Character Sets.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            void     writeMultiByte(std::string value, std::string charSet);

            /**
             * Writes a UTF-8 string to the byte stream. The length of the UTF-8 string in bytes
             * is written first, as a 16-bit integer, followed by the bytes representing the
             * characters of the string.
             * @param   value   The string value to be written.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             * @throws  RangeError If the length is larger than
             *   65535.
             */
        public:
            void     writeUTF(std::string value);

            /**
             * Writes a UTF-8 string to the byte stream. Similar to the writeUTF() method,
             * but writeUTFBytes() does not prefix the string with a 16-bit length word.
             * @param   value   The string value to be written.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            void     writeUTFBytes(std::string value);

            /**
             * Reads a Boolean value from the byte stream. A single byte is read,
             * and true is returned if the byte is nonzero,
             * false otherwise.
             * @return  Returns true if the byte is nonzero, false otherwise.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             * @throws  EOFError There is not sufficient data available
             *   to read.
             */
        public:
            bool     readBoolean();

            /**
             * Reads a signed byte from the byte stream.
             * The returned value is in the range -128 to 127.
             * @return  An integer between -128 and 127.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             * @throws  EOFError There is not sufficient data available
             *   to read.
             */
        public:
            int      readByte();

            /**
             * Reads an unsigned byte from the byte stream.
             *
             *   The returned value is in the range 0 to 255.
             * @return  A 32-bit unsigned integer between 0 and 255.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             * @throws  EOFError There is not sufficient data available
             *   to read.
             */
        public:
            unsigned int readUnsignedByte();

            /**
             * Reads a signed 16-bit integer from the byte stream.
             *
             *   The returned value is in the range -32768 to 32767.
             * @return  A 16-bit signed integer between -32768 and 32767.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             * @throws  EOFError There is not sufficient data available
             *   to read.
             */
        public:
            int      readShort();

            /**
             * Reads an unsigned 16-bit integer from the byte stream.
             *
             *   The returned value is in the range 0 to 65535.
             * @return  A 16-bit unsigned integer between 0 and 65535.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             * @throws  EOFError There is not sufficient data available
             *   to read.
             */
        public:
            unsigned int readUnsignedShort();

            /**
             * Reads a signed 32-bit integer from the byte stream.
             *
             *   The returned value is in the range -2147483648 to 2147483647.
             * @return  A 32-bit signed integer between -2147483648 and 2147483647.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             * @throws  EOFError There is not sufficient data available
             *   to read.
             */
        public:
            int      readInt();

            /**
             * Reads an unsigned 32-bit integer from the byte stream.
             *
             *   The returned value is in the range 0 to 4294967295.
             * @return  A 32-bit unsigned integer between 0 and 4294967295.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             * @throws  EOFError There is not sufficient data available
             *   to read.
             */
        public:
            unsigned int readUnsignedInt();

            /**
             * Reads an IEEE 754 single-precision (32-bit) floating-point number from the byte stream.
             * @return  A single-precision (32-bit) floating-point number.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             * @throws  EOFError There is not sufficient data available
             *   to read.
             */
        public:
            float    readFloat();

            /**
             * Reads an IEEE 754 double-precision (64-bit) floating-point number from the byte stream.
             * @return  A double-precision (64-bit) floating-point number.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             * @throws  EOFError There is not sufficient data available
             *   to read.
             */
        public:
            float    readDouble();

            /**
             * Reads a multibyte string of specified length from the byte stream using the
             * specified character set.
             * @param   length  The number of bytes from the byte stream to read.
             * @param   charSet The string denoting the character set to use to interpret the bytes.
             *   Possible character set strings include "shift-jis", "cn-gb",
             *   "iso-8859-1", and others.
             *   For a complete list, see Supported Character Sets.
             *   Note: If the value for the charSet parameter
             *   is not recognized by the current system, the application uses the system's default
             *   code page as the character set. For example, a value for the charSet parameter,
             *   as in myTest.readMultiByte(22, "iso-8859-01") that uses 01 instead of
             *   1 might work on your development system, but not on another system.
             *   On the other system, the application will use the system's default code page.
             * @return  UTF-8 encoded string.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             * @throws  EOFError There is not sufficient data available
             *   to read.
             */
        public:
            std::string readMultiByte(unsigned int length, std::string charSet);

            /**
             * Reads a UTF-8 string from the byte stream.  The string
             * is assumed to be prefixed with an unsigned short indicating
             * the length in bytes.
             * @return  UTF-8 encoded  string.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             * @throws  EOFError There is not sufficient data available
             *   to read.
             */
        public:
            std::string readUTF();

            /**
             * Reads a sequence of UTF-8 bytes specified by the length
             * parameter from the byte stream and returns a string.
             * @param   length  An unsigned short indicating the length of the UTF-8 bytes.
             * @return  A string composed of the UTF-8 bytes of the specified length.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             * @throws  EOFError There is not sufficient data available
             *   to read.
             */
        public:
            std::string readUTFBytes(unsigned int length);

            /**
             * Writes an object into the byte array in AMF
             * serialized format.
             * @param   object  The object to serialize.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            void     writeObject(void *object);

            /**
             * Reads an object from the byte array, encoded in AMF
             * serialized format.
             * @return  The deserialized object.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             * @throws  EOFError There is not sufficient data available
             *   to read.
             */
        public:
            void    *readObject();

            /**
             * Compresses the byte array using the deflate compression algorithm.
             * The entire byte array is compressed.
             *
             *   After the call, the length property of the ByteArray is set to the new length.
             * The position property is set to the end of the byte array.The deflate compression algorithm is described at
             * http://www.ietf.org/rfc/rfc1951.txt.In order to use the deflate format to compress a ByteArray instance's
             * data in a specific format such as gzip or zip, you cannot simply call
             * deflate(). You must create a ByteArray structured
             * according to the compression format's specification, including the appropriate
             * metadata as well as the compressed data obtained using the deflate format.
             * Likewise, in order to decode data compressed in a format such
             * as gzip or zip, you can't simply call inflate()
             * on that data. First, you must separate the metadata from the compressed data, and you can
             * then use the deflate format to decompress the compressed data.
             * @langversion 3.0
             * @playerversion   Flash 10
             * @playerversion   AIR 1.5
             * @playerversion   Lite 4
             */
        public:
            void     deflate();

            /**
             * Compresses the byte array. The entire byte array is compressed. For content
             * running in Adobe AIR, you can specify a compression algorithm by passing a
             * value (defined in the CompressionAlgorithm class) as the algorithm
             * parameter. Flash Player supports only the default
             * algorithm, zlib.After the call, the length property of the ByteArray is set to the new length.
             * The position property is set to the end of the byte array.The zlib compressed data format is described at
             * http://www.ietf.org/rfc/rfc1950.txt.The deflate compression algorithm is described at
             * http://www.ietf.org/rfc/rfc1951.txt.The deflate compression algorithm is used in several compression
             * formats, such as zlib, gzip, some zip implementations, and others. When data is
             * compressed using one of those compression formats, in addition to storing
             * the compressed version of the original data, the compression format data
             * (for example, the .zip file) includes metadata information. Some examples of
             * the types of metadata included in various file formats are file name,
             * file modification date/time, original file size, optional comments, checksum
             * data, and more.For example, when a ByteArray is compressed using the zlib algorithm,
             * the resulting ByteArray is structured in a specific format. Certain bytes contain
             * metadata about the compressed data, while other bytes contain the actual compressed
             * version of the original ByteArray data. As defined by the zlib compressed data
             * format specification, those bytes (that is, the portion containing
             * the compressed version of the original data) are compressed using the deflate
             * algorithm. Consequently those bytes are identical to the result of calling
             * compress(air.CompressionAlgorithm.DEFLATE)
             * on the original ByteArray. However, the result from
             * compress(air.CompressionAlgorithm.ZLIB) includes
             * the extra metadata, while the compress(CompressionAlgorithm.DEFLATE)
             * result includes only the compressed version of the original ByteArray data and nothing else.In order to use the deflate format to compress a ByteArray instance's
             * data in a specific format such as gzip or zip, you cannot simply call
             * compress(CompressionAlgorithm.DEFLATE).
             * You must create a ByteArray structured
             * according to the compression format's specification, including the appropriate
             * metadata as well as the compressed data obtained using the deflate format.
             * Likewise, in order to decode data compressed in a format such
             * as gzip or zip, you can't simply call uncompress(CompressionAlgorithm.DEFLATE)
             * on that data. First, you must separate the metadata from the compressed data, and you can
             * then use the deflate format to decompress the compressed data.
             * @param   algorithm   The compression algorithm to use when compressing. Valid values are defined as
             *   constants in the CompressionAlgorithm class. The default is to use zlib format.
             *   This parameter is only recognized for content running in Adobe AIR.
             *   Flash Player supports only the default algorithm, zlib, and throws an exception if you attempt to pass
             *   a value for this parameter. Calling compress(CompressionAlgorithm.DEFLATE)
             *   has the same effect as calling the deflate() method.
             * @langversion 3.0
             * @playerversion   Flash 9
             */
        public:
            void     compress(std::string algorithm);

            /**
             * Decompresses the byte array using the deflate compression algorithm.
             * The byte array must have been compressed using the same algorithm.
             *
             *   After the call, the length property of the ByteArray is set to the new length.
             * The position property is set to 0.The deflate compression algorithm is described at
             * http://www.ietf.org/rfc/rfc1951.txt.In order to decode data compressed in a format that uses the deflate compression algorithm,
             * such as data in gzip or zip format, it will not work to simply call inflate() on
             * a ByteArray containing the compression formation data. First, you must separate the metadata that is
             * included as part of the compressed data format from the actual compressed data. For more
             * information, see the compress() method description.
             * @langversion 3.0
             * @playerversion   Flash 10
             * @throws  IOError The data is not valid compressed data; it was not compressed with the
             *   same compression algorithm used to compress.
             */
        public:
            void     inflate();

            /**
             * Decompresses the byte array. For content running in Adobe AIR, you can specify
             * a compression algorithm by passing a value (defined in the CompressionAlgorithm class)
             * as the algorithm parameter. The byte array must have been compressed
             * using the same algorithm. Flash Player supports only the
             * default algorithm, zlib.After the call, the length property of the ByteArray is set to the new length.
             * The position property is set to 0.The zlib compressed data format is described at
             * http://www.ietf.org/rfc/rfc1950.txt.The deflate compression algorithm is described at
             * http://www.ietf.org/rfc/rfc1951.txt.In order to decode data compressed in a format that uses the deflate compression algorithm,
             * such as data in gzip or zip format, it will not work to call
             * uncompress(CompressionAlgorithm.DEFLATE) on
             * a ByteArray containing the compression formation data. First, you must separate the metadata that is
             * included as part of the compressed data format from the actual compressed data. For more
             * information, see the compress() method description.
             * @param   algorithm   The compression algorithm to use when decompressing. This must be the
             *   same compression algorithm used to compress the data. Valid values are defined as
             *   constants in the CompressionAlgorithm class. The default is to use zlib format. This parameter
             *   is only recognized for content running in Adobe AIR. Flash Player
             *   supports only the default algorithm, zlib, and throws an exception if you attempt to pass
             *   a value for this parameter.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             * @throws  IOError The data is not valid compressed data; it was not compressed with the
             *   same compression algorithm used to compress.
             */
        public:
            void     uncompress(std::string algorithm);

            /**
             * Converts the byte array to a string.
             * If the data in the array begins with a Unicode byte order mark, the application will honor that mark
             * when converting to a string. If System.useCodePage is set to true, the
             * application will treat the data in the array as being in the current system code page when converting.
             * @return  The string representation of the byte array.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            std::string toString();

            /**
             * Clears the contents of the byte array and resets the length
             * and position properties to 0. Calling this method explicitly
             * frees up the memory used by the ByteArray instance.
             * @langversion 3.0
             * @playerversion   Flash 10
             * @playerversion   AIR 1.5
             * @playerversion   Lite 4
             */
        public:
            void     clear();

        public:
            int      atomicCompareAndSwapIntAt(int byteIndex, int expectedValue, int newValue);

        public:
            int      atomicCompareAndSwapLength(int expectedLength, int newLength);
        };
    }
}

#endif // FLEX11_6_FLASH_UTILS_BYTEARRAY_AS
#endif // __cplusplus

