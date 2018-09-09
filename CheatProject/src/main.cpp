
#include <iostream>
#include "Process/ProcessClientDll.hpp"
#include "Tools/MemoryManager.hpp"

int main()
{
   MemoryManager* memManager = new MemoryManager();

      // debug
      //memManager -> readAll();


      if (memManager->attach("csgo.exe")) {
         if (memManager->grabModule("client_panorama.dll")) {
            for (ModuleWrapper modWrapper : memManager->getModules()) {
               MODULEENTRY32* clientModule = modWrapper.getModule();
               processClientModule(memManager, clientModule);

            }
         }
         else {
            std::cout << "Module not found. Exiting" << std::endl;
         }
      }
      else {
         std::cout << "CS:GO process not found. Exiting" << std::endl;
      }
}



