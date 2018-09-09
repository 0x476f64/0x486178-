/*
 * ProcessClientDll.hpp
 *
 *  Created on: 2 sept. 2018
 *      Author: Nous
 */

#ifndef PROCESS_PROCESSCLIENTDLL_HPP_
#define PROCESS_PROCESSCLIENTDLL_HPP_

#include <Windows.h>
#include <tlhelp32.h>
#include <MemoryManager.hpp>

#define RADAR_BASE_OFFSET 0x5071E6C
#define LOCAL_PLAYER_OFFSET 0xC6086C
#define M_FLAGS_OFFSET 0x100
#define FORCE_ATTACK_OFFSET 0x307E878

void processClientModule(MemoryManager* memManager, MODULEENTRY32* clientModule);

#endif /* PROCESS_PROCESSCLIENTDLL_HPP_ */
