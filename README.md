Flash API for C/C++

Experiments in bringing Flash like functionality to C/C++.

Having spent a few years porting games and applications written in ActionScript to mobile and C/C++ some pieces can be shared; having a Flash like API can be handy as code is migrated to native APIs.

Huge props to Flash Develop (http://www.flashdevelop.org/) for its integrated editing environment and tools for examining and scraping ActionScript code.

Initial conditioning through a custom tool, final formatting through astyle (http://astyle.sourceforge.net/astyle.html)

astyle --recursive --style=ansi --indent=spaces --indent-switches --indent-namespaces --align-pointer=name --align-reference=name --lineend=linux "flex11.6/*.h"
