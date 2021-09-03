
#include <windows.h>
#include "Config.h"
#include "Debugf.h"
#include <filesystem>

namespace fs = std::filesystem;

void Config::readConfig() {
	char wabuff[MAX_PATH];
	GetModuleFileNameA(0, (LPSTR)&wabuff, sizeof(wabuff));
	waDir = fs::path(wabuff).parent_path();
	auto inipath = (waDir / iniFile).string();
	moduleEnabled = GetPrivateProfileIntA("general", "EnableModule", 1, inipath.c_str());
	useOffsetCache = GetPrivateProfileIntA("general", "UseOffsetCache", 1, inipath.c_str());
	ignoreVersionCheck = GetPrivateProfileIntA("general", "IgnoreVersionCheck", 0, inipath.c_str());

	scrambleWormOrder = GetPrivateProfileIntA("general", "ScrambleWormOrder", 0, inipath.c_str());
	teamNameShowOwner = GetPrivateProfileIntA("general", "TeamNameShowOwner", 0, inipath.c_str());

	char buff[MAX_PATH];
	GetPrivateProfileStringA("general", "WormNameFormat", "#{number} {name}", buff, sizeof(buff), inipath.c_str());
	wormNameFormat = buff;

	GetPrivateProfileStringA("general", "TeamNameFormat", "{name} ({owner})", buff, sizeof(buff), inipath.c_str());
	teamNameFormat = buff;
}


bool Config::isModuleEnabled() {
	return moduleEnabled;
}

//StepS tools
typedef unsigned long long QWORD;
#define MAKELONGLONG(lo,hi) ((LONGLONG(DWORD(lo) & 0xffffffff)) | LONGLONG(DWORD(hi) & 0xffffffff) << 32 )
#define QV(V1, V2, V3, V4) MAKEQWORD(V4, V3, V2, V1)
#define MAKEQWORD(LO2, HI2, LO1, HI1) MAKELONGLONG(MAKELONG(LO2,HI2),MAKELONG(LO1,HI1))
QWORD GetModuleVersion(HMODULE hModule)
{
	char WApath[MAX_PATH]; DWORD h;
	GetModuleFileNameA(hModule,WApath,MAX_PATH);
	DWORD Size = GetFileVersionInfoSizeA(WApath,&h);
	if(Size)
	{
		void* Buf = malloc(Size);
		GetFileVersionInfoA(WApath,h,Size,Buf);
		VS_FIXEDFILEINFO *Info; DWORD Is;
		if(VerQueryValueA(Buf, "\\", (LPVOID*)&Info, (PUINT)&Is))
		{
			if(Info->dwSignature==0xFEEF04BD)
			{
				return MAKELONGLONG(Info->dwFileVersionLS, Info->dwFileVersionMS);
			}
		}
		free(Buf);
	}
	return 0;
}

int Config::waVersionCheck() {
	if(ignoreVersionCheck)
		return 1;

	auto version = GetModuleVersion((HMODULE)0);
	char versionstr[64];
	_snprintf_s(versionstr, _TRUNCATE, "Detected game version: %u.%u.%u.%u", PWORD(&version)[3], PWORD(&version)[2], PWORD(&version)[1], PWORD(&version)[0]);
	debugf("%s\n", versionstr);

	std::string tversion = getFullStr();
	char buff[512];
	if (version < QV(3,8,0,0)) {
		_snprintf_s(buff, _TRUNCATE, "wkWormOrder is not compatible with WA versions older than 3.8.0.0.\n\n%s", versionstr);
		MessageBoxA(0, buff, tversion.c_str(), MB_OK | MB_ICONERROR);
		return 0;
	}
	if (version >= QV(3,9,0,0)) {
		_snprintf_s(buff, _TRUNCATE, "wkWormOrder is not compatible with WA versions 3.9.x.x and newer.\n\n%s", versionstr);
		MessageBoxA(0, buff, tversion.c_str(), MB_OK | MB_ICONERROR);
		return 0;
	}
	if(version == QV(3,8,0,0) || version == QV(3,8,1,0)) {
		return 1;
	}

	_snprintf_s(buff, _TRUNCATE, "wkWormOrder is not designed to work with your WA version and may malfunction.\n\nTo disable this warning set IgnoreVersionCheck=1 in wkWormOrder.ini file.\n\n%s", versionstr);
	return MessageBoxA(0, buff, tversion.c_str(), MB_OKCANCEL | MB_ICONWARNING) == IDOK;
}

std::string Config::getModuleStr() {
	return "wkWormOrder";
}
std::string Config::getVersionStr() {
	return "v0.1.0";
}

std::string Config::getBuildStr() {
	return __DATE__ " " __TIME__;
}

std::string Config::getFullStr() {
	return getModuleStr() + " " + getVersionStr() + " (build: " + getBuildStr() + ")";
}

const std::filesystem::path &Config::getWaDir() {
	return waDir;
}


bool Config::isUseOffsetCache() {
	return useOffsetCache;
}

std::string Config::getWaVersionAsString() {
	char buff[32];
	auto version = GetModuleVersion(0);
	sprintf_s(buff, "%u.%u.%u.%u", PWORD(&version)[3], PWORD(&version)[2], PWORD(&version)[1], PWORD(&version)[0]);
	return buff;
}

const std::string &Config::getCacheFile() {
	return cacheFile;
}

bool Config::isScrambleWormOrderEnabled() {
	return scrambleWormOrder;
}

const std::string &Config::getWormNameFormat() {
	return wormNameFormat;
}

const std::string &Config::getTeamNameFormat() {
	return teamNameFormat;
}

bool Config::isTeamNameShowOwnerEnabled() {
	return teamNameShowOwner;
}
