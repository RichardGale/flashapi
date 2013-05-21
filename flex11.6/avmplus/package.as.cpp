

    Object* ::describeTypeJSON(void* o, unsigned int flags)         ;
    void ::describeParams(XML* x, Object* parameters)       ;
    void ::describeMetadata(XML* x, std::vector<void*> metadata)       ;
    void ::finish(XML* e, Object* i)       ;
    void ::describeTraits(XML* x, Object* traits)       ;
    XML* ::describeType(void* value, unsigned int flags)      ;
    std::string ::getQualifiedClassName(void* value)         ;
    std::string ::getQualifiedSuperclassName(void* value)         ;
