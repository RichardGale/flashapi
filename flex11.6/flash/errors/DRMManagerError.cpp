

    /**
     * The DRMManager dispatches a DRMManagerError event to report errors.
     * @langversion 3.0
     * @playerversion   AIR 1.5
     */


namespace flash {
namespace errors {


        /**
         * The specific error number.
         * @langversion 3.0
         * @playerversion   AIR 1.5
         */
        int DRMManagerError::subErrorID()      ;

        /**
         * Creates a new instance of the DRMManagerError class.
         * @param   message The error description
         * @param   id  The general error number
         * @param   subErrorID  The specific error number
         * @langversion 3.0
         * @playerversion   AIR 1.5
         */
        DRMManagerError::DRMManagerError(std::string message, int id, int subErrorID);

        /**
         * Returns the string "Error" by default or the value contained in the Error.message property,
         * if defined.
         * @return  The error message.
         */
        std::string DRMManagerError::toString()         ;
}
}

