
#ifndef WKWORMORDER_CHAT_H
#define WKWORMORDER_CHAT_H

#include <string>
#include <vector>

class Chat {
private:
	static int handleOrderCommand(std::string & message, std::vector<std::string> & parts, int a1, int a3);
	static int handleOwnerCommand(std::string & message, std::vector<std::string> & parts, int a1, int a3);

	static int __stdcall callOriginalOnChatInput(int a1, char * msg, int a3);
	static int onChatInput(int a1, char * msg, int a3);
	static void __stdcall hookOnChatInput(int a3);
public:
	static void callShowChatMessage(std::string msg, int color);
	static void install();
};


#endif //WKWORMORDER_CHAT_H
