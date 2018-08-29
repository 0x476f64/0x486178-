/*
 * OpenHandle.h
 *
 *  Created on: 29 août 2018
 *      Author: OwL
 */

#ifndef OPENHANDLE_H_
#define OPENHANDLE_H_

#include <iostream>
#include <Windows.h>
#include <tlhelp32.h>

HANDLE OpenHandle(const std::string& ProcessName);


#endif /* OPENHANDLE_H_ */
