

    /**
     * Lets you issue Flash JavaScript API (JSAPI) commands from ActionScript. 
     * In Flash Professional, the MMExecute() function can be called only by a movie that 
     * is used as a Flash Panel, by an XMLtoUI dialog box, or by the Custom UI 
     * of a component. JSAPI commands have no effect outside the authoring environment. 
     * The Flash JSAPI provides several objects, methods, and properties to duplicate 
     * or emulate commands that a user can enter in the authoring environment. Using the JSAPI,
     * you can write scripts that extend Flash in several ways: adding commands to menus,
     * manipulating objects on the Stage, repeating sequences of commands, and so on.In general, a user runs a JSAPI script by selecting Commands > Run Command. However,
     * you can use this function in an ActionScript script to call a JSAPI command directly. 
     * If you use MMExecute() in a script on Frame 1 of your file, the command executes when 
     * the SWF file is loaded.For more information on the JSAPI, 
     * see "Extending Flash" at http://www.adobe.com/go/jsapi_info_en.
     * @param   name    A string passed to MMExecute(). MMExecute() parses the string and 
     *   executes any JavaScript commands.
     *   You can assign the string a variable and then pass the variable to MMExecute(). You can also 
     *   separate your JavaScript function into smaller strings; 
     *   MMExecute() returns the value of the last function called.
     * @return  A string representation of the result, if any, sent by the JavaScript statement.
     * @langversion 3.0
     * @playerversion   Flash 9
     * @productversion  Flash CS3
     */
    std::string ::MMExecute(std::string name)         ;
    /**
     * Notifies an application hosting a SWF command that a command is done and instructs the application to commit or discard 
     * the changes submitted by the MMExecute() command.
     * @param   endStatus   A Boolean value; use true to commit changes, 
     *   otherwise false. If set to false, any pending changes are
     *   discarded.
     * @param   notifyString    A string containing an error message or the reason the changes will
     *   be discarded. If the endStatus parameter value is true, 
     *   use an empty string for the notifyString parameter value.
     * @langversion 3.0
     * @playerversion   Flash 10
     * @playerversion   AIR 1.5
     * @productversion  Flash CS4
     */
    void ::MMEndCommand(bool endStatus, std::string notifyString)       ;
