#include <windows.h>
#include <string>
#include <stdexcept>
#include <ctime>
#include "Config.h"
#include "BitmapImage.h"
#include "BitmapTextbox.h"
#include "W2App.h"
#include "entities/CTaskWorm.h"
#include "entities/CTaskTeam.h"
#include "LobbyScrambler.h"
#include "Hooks.h"
#include <chrono>

void install() {
	srand(time(0) * GetCurrentProcessId());
//	WaLibc::install();
	BitmapTextbox::install();
	W2App::install();
	CTaskWorm::install();
	CTaskTeam::install();
	LobbyScrambler::install();
}

// Thanks StepS
bool LockGlobalInstance(LPCTSTR MutexName)
{
	if (!CreateMutex(NULL, 0, MutexName)) return 0;
	if (GetLastError() == ERROR_ALREADY_EXISTS) return 0;
	return 1;
}

char LocalMutexName[MAX_PATH];
bool LockCurrentInstance(LPCTSTR MutexName)
{
	_snprintf_s(LocalMutexName, _TRUNCATE,"P%u/%s", GetCurrentProcessId(), MutexName);
	return LockGlobalInstance(LocalMutexName);
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved) {
	switch(ul_reason_for_call) {
		case DLL_PROCESS_ATTACH: {
			auto start = std::chrono::high_resolution_clock::now();
			decltype(start) finish;
			try {
				Config::readConfig();
				if (Config::isModuleEnabled() && Config::waVersionCheck() && LockCurrentInstance("wkWormOrder")) {
					Hooks::loadOffsets();
					install();
					Hooks::saveOffsets();
				}
				finish = std::chrono::high_resolution_clock::now();
			} catch (std::exception &e) {
				finish = std::chrono::high_resolution_clock::now();
				MessageBoxA(0, e.what(), Config::getFullStr().c_str(), MB_ICONERROR);
			}
			std::chrono::duration<double> elapsed = finish - start;
			printf("wkWormOrder startup took %lf seconds\n", elapsed.count());
		}
		break;
		case DLL_THREAD_ATTACH:
		case DLL_THREAD_DETACH:
		case DLL_PROCESS_DETACH:
		default:
			break;
	}
	return TRUE;
}
