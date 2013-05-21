

#include "ProductManager.h"
#include "flash/events/EventDispatcher.h"

using namespace flash::events;

namespace adobe {
namespace utils {


        bool ProductManager::running()          ;

        bool ProductManager::installed()          ;

        std::string ProductManager::installedVersion()         ;

        ProductManager::ProductManager(std::string name, bool shared);

        bool ProductManager::launch(std::string parameters)          ;

        bool ProductManager::download(std::string caption, std::string fileName, std::vector<void*> pathElements)          ;

        bool ProductManager::doSelfUpgrade(std::string os)          ;
}
}

