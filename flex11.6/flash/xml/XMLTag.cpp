


namespace flash {
namespace xml {


        unsigned int XMLTag::type()       ;
        void XMLTag::type(unsigned int value)       ;

        bool XMLTag::empty()          ;
        void XMLTag::empty(bool value)       ;

        std::string XMLTag::value()         ;
        void XMLTag::value(std::string v)       ;

        Object* XMLTag::attrs()         ;
        void XMLTag::attrs(Object* value)       ;

        XMLTag::XMLTag();
}
}

