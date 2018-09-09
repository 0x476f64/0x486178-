/*
 * ProcessClientDll.cpp
 *
 *  Created on: 2 sept. 2018
 *      Author: Nous
 */

#include <ProcessClientDll.hpp>

void processClientModule(MemoryManager* memManager, MODULEENTRY32* clientModule) {
   // Get module base address
   DWORD dwClientBase = reinterpret_cast<DWORD>(clientModule->modBaseAddr);
   std::cout << "CLIENT BASE VALUE: " << dwClientBase << std::endl;

   //DWORD dwRadarBase = 0;
   //memManager -> readMem(dwClientBase + RADAR_BASE_OFFSET, dwRadarBase);
   //std::cout << "DWRADARBASE VALUE: " << dwRadarBase << std::endl;

   while (true) {
      std::cout << "## --- --- --- --- --- " << std::endl;
      DWORD dwLocalPlayer;
      memManager->readMem<DWORD>(dwClientBase + LOCAL_PLAYER_OFFSET, dwLocalPlayer);
      //std::cout << "LOCAL PLAYER VALUE: " << dwLocalPlayer << std::endl;

      BYTE playerFlags;
      memManager->readMem<BYTE>(dwLocalPlayer + M_FLAGS_OFFSET, playerFlags);
      std::cout << "PLAYER FLAGS: " << playerFlags << std::endl;

      BYTE forceAttack;
      memManager->readMem<BYTE>(dwLocalPlayer + FORCE_ATTACK_OFFSET, forceAttack);
      //std::cout << "FORCE ATTACK VALUE: " << forceAttack << std::endl;

      memManager->writeMem<int>(dwLocalPlayer + FORCE_ATTACK_OFFSET, 5);
      Sleep(1500);
      memManager->writeMem<int>(dwLocalPlayer + FORCE_ATTACK_OFFSET, 4);
            Sleep(1500);

      /*
      if (playerFlags & (1 << 0)) {
         std::cout << "## PLAYER ON GROUND !" << std::endl;
      }
      if (playerFlags & (1 << 1)) {
         std::cout << "## PLAYER DUCKING !" << std::endl;
      }
      */
   }
}

