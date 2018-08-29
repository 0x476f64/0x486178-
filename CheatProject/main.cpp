#include <iostream>
#include <Windows.h>
#include <tlhelp32.h>
#include "OpenHandle.h"

int main()
{
	std::cout << "Test" << std::endl;
	HANDLE chrome = OpenHandle("chrome.exe");
	std::cout << "HANDLE: " << chrome << std::endl;
	return 0;
}



