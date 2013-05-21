

#include "XMLParser.h"
#include "flash/xml/XMLTag.h"

using namespace flash::xml;

namespace flash {
namespace xml {


        void XMLParser::startParse(std::string source, bool ignoreWhite)       ;

        int XMLParser::getNext(XMLTag* tag)      ;

        XMLParser::XMLParser();
}
}

