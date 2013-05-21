

    /**
     * The methods of the CustomActions class allow a SWF file playing in the Flash authoring 
     * tool to manage any custom actions that are registered with the authoring tool. A SWF 
     * file can install and uninstall custom actions, retrieve the XML definition of a custom 
     * action, and retrieve the list of registered custom actions.
     * <p class="- topic/p ">You can use these methods to build SWF files that are extensions of the Flash 
     * authoring tool. Such an extension could, for example, use the Flash Application 
     * Protocol to navigate a Universal Description, Discovery and Integration (UDDI) 
     * repository and download web services into the Actions toolbox.</p>
     * @langversion 3.0
     * @playerversion   Flash 9
     * @productversion  Flash CS3
     */


namespace adobe {
namespace utils {


        /**
         * Returns an Array object containing the names of all the custom actions that are registered
         * with the Flash authoring tool. The elements of the array are simple names, without the .xml file
         * extension, and without any directory separators (for example, ":", "/", 
         * or "\"). If there are no registered custom actions, actionsList() 
         * returns a zero-length array. If an error occurs, actionsList() returns the value
         * undefined.
         * @langversion 3.0
         * @playerversion   Flash 9
         * @productversion  Flash CS3
         */
        std::vector<void*> CustomActions::actionsList()        ;

        CustomActions::CustomActions();

        /**
         * Installs a new custom action XML definition file indicated by the 
         * name parameter. The contents of the file is specified 
         * by the string data.
         * The name of the definition file must be a simple filename, without the .xml 
         * file extension, and without any directory separators (':', '/' or 
         * '\'). If a custom actions file already exists with the name 
         * name, it is overwritten.If the Configuration/ActionsPanel/CustomActions directory does not exist when 
         * this method is invoked, the directory is created.
         * @param   name    The name of the custom action definition to install.
         * @param   data    The text of the XML definition to install.
         * @return  A Boolean value of false if an error occurs during 
         *   installation; otherwise, a value of true is returned to indicate that 
         *   the custom action has been successfully installed.
         * @langversion 3.0
         * @playerversion   Flash 9
         * @productversion  Flash CS3
         */
        void CustomActions::installActions(std::string name, std::string data)       ;

        /**
         * Removes the Custom Actions XML definition file named name.
         * The name of the definition file must be a simple filename, without the .xml file extension, and without any directory separators (':', '/' or '\').
         * @param   name    The name of the custom action definition to uninstall.
         * @langversion 3.0
         * @playerversion   Flash 9
         * @productversion  Flash CS3
         */
        void CustomActions::uninstallActions(std::string name)       ;

        /**
         * Reads the contents of the custom action XML definition file named name.
         * The name of the definition file must be a simple filename, without the .xml file extension, and without any directory separators (':', '/' or '\'). If the definition file specified by the name cannot be found, a value of undefined is returned. If the custom action XML definition specified by the name parameter is located, it is read in its entirety and returned as a string.
         * @param   name    The name of the custom action definition to retrieve.
         * @return  If the custom action XML definition is located, returns a string; otherwise, returns undefined.
         * @langversion 3.0
         * @playerversion   Flash 9
         * @productversion  Flash CS3
         */
        std::string CustomActions::getActions(std::string name)         ;
}
}

