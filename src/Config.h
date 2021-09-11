#ifndef WKWORMORDER_CONFIG_H
#define WKWORMORDER_CONFIG_H

#include <string>
#include <set>
#include <filesystem>

class Config {
public:
	static inline const std::string iniFile = "wkWormOrder.ini";
	static inline const std::string cacheFile = "wkWormOrder.cache";
	static inline const std::string moduleName = "wkWormOrder";

private:
	static inline bool moduleEnabled = true;
	static inline bool ignoreVersionCheck = false;
	static inline std::filesystem::path waDir;

	static inline bool useOffsetCache = true;
	static inline bool scrambleWormOrder = false;
	static inline bool teamNameShowOwner = false;

	static inline std::string wormNameFormat;
	static inline std::string teamNameFormat;

public:
	static void readConfig();
	static bool isModuleEnabled();
	static int waVersionCheck();
	static const std::filesystem::path &getWaDir();

	static std::string getVersionStr();
	static std::string getBuildStr();
	static std::string getModuleStr();
	static std::string getFullStr();
	static std::string getModuleStrWithWebsite();
	static std::string getModuleStrWithVersion();

	static bool isUseOffsetCache();
	static std::string getWaVersionAsString();

	static const std::string &getCacheFile();

	static bool isScrambleWormOrderEnabled();

	static bool isTeamNameShowOwnerEnabled();

	static const std::string &getWormNameFormat();
	static const std::string &getTeamNameFormat();
};


#endif //WKWORMORDER_CONFIG_H
