
#ifndef WKWORMORDER_UTILS_H
#define WKWORMORDER_UTILS_H

#include <string>
#include <vector>
#include <set>
#include <optional>
#include <filesystem>

class Utils {
public:
	static void hexDump(const char *desc, const void *addr, int len);
	static void tokenize(std::string &str, const char* delim, std::vector<std::string> &out);
	static void tokenizeSet(std::string &str, const char* delim, std::set<std::string> &out);
	static std::optional<std::string> readFile(std::filesystem::path path);
	static void stripNonAlphaNum(std::string & s);
	static void replaceString(std::string & subject, const std::string& search, const std::string& replace);
};


#endif //WKWORMORDER_UTILS_H
