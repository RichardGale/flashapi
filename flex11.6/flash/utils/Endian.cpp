

    /**
     * The Endian class contains values that denote the byte order used to represent multibyte 
     * numbers. The byte order is either bigEndian (most significant byte first) or littleEndian (least 
     * significant byte first).
     * 
     *   <p class="- topic/p ">Content in <ph class="- topic/ph ">Flash Player or</ph> Adobe<sup class="+ topic/ph hi-d/sup ">  </sup> 
     * AIR    can interface with a server by using the binary protocol of that 
     * server, directly. Some servers use the bigEndian byte order and some servers use the
     * littleEndian byte order. Most servers on the Internet use the bigEndian byte order 
     * because "network byte order" is bigEndian. The littleEndian byte order is 
     * popular because the Intel x86 architecture uses it. Use the endian byte order that 
     * matches the protocol of the server that is sending or receiving data.</p>
     * @langversion 3.0
     * @playerversion   Flash 9
     * @playerversion   Lite 4
     */


namespace flash {
namespace utils {


        /**
         * Indicates the most significant byte of the multibyte number appears first in the sequence of bytes.
         * The hexadecimal number 0x12345678 has 4 bytes (2 hexadecimal digits per byte). 
         * The most significant byte is 0x12.  The least significant byte is 0x78. (For the equivalent
         * decimal number, 305419896, the most significant digit is 3, and the least significant digit
         * is 6).A stream using the bigEndian byte order (the most significant byte first)
         * writes:
         * 12 34 56 78
         * @langversion 3.0
         * @playerversion   Flash 9
         * @playerversion   Lite 4
         */
        const std::string Endian::BIG_ENDIAN="bigEndian";

        /**
         * Indicates the least significant byte of the multibyte number appears first in the sequence of bytes.
         * The hexadecimal number 0x12345678 has 4 bytes (2 hexadecimal digits per byte). 
         * The most significant byte is 0x12.  The least significant byte is 0x78. (For the equivalent
         * decimal number, 305419896, the most significant digit is 3, and the least significant digit
         * is 6).A stream using the littleEndian byte order (the least significant byte 
         * first) writes:
         * 78 56 34 12
         * @langversion 3.0
         * @playerversion   Flash 9
         * @playerversion   Lite 4
         */
        const std::string Endian::LITTLE_ENDIAN="littleEndian";

        Endian::Endian();
}
}

