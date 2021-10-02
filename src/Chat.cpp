
#include "Chat.h"
#include "Hooks.h"
#include "Utils.h"
#include "Config.h"
#include <fmt/format.h>
#include "entities/CTaskWorm.h"
#include "Debugf.h"
#include "W2App.h"
#include "entities/CTaskTeam.h"

int Chat::handleOrderCommand(std::string &message, std::vector<std::string> &parts, int a1, int a3) {
	auto orderState = CTaskWorm::getOrderState();
	if (parts.size() >= 2) {
		auto &option = parts[1];
		if (option == "off") {
			if (orderState != CTaskWorm::OrderOff) {
				CTaskWorm::setOrderState(CTaskWorm::OrderOff);
				callOriginalOnChatInput(a1, (char*)fmt::format("/me has disabled displaying worm order - {}", Config::getModuleStrWithWebsite()).c_str(), a3);
			}
		} else if (option == "my" || option == "me") {
			if (orderState != CTaskWorm::OrderMy) {
				CTaskWorm::setOrderState(CTaskWorm::OrderMy);
				callOriginalOnChatInput(a1, (char*)fmt::format("/me has enabled displaying order of worms belonging to him - {}", Config::getModuleStrWithWebsite()).c_str(), a3);
				sendMyTeamOrder(a1, a3);
			}
		} else if (option == "all") {
			if (orderState != CTaskWorm::OrderAll) {
				CTaskWorm::setOrderState(CTaskWorm::OrderAll);
				callOriginalOnChatInput(a1, (char *) fmt::format("/me has enabled displaying order of worms belonging to all players - {}", Config::getModuleStrWithWebsite()).c_str(), a3);
				sendMyTeamOrder(a1, a3);
			}
		} else if (option == "print") {
			sendMyTeamOrder(a1, a3);
		} else throw std::runtime_error(fmt::format("Unknown option: {}. Available options: /order my|all|off|print", parts[1]));
	} else throw std::runtime_error("Not enough arguments. Format: /order my|all|off|print");
	return 1;
}

void Chat::sendMyTeamOrder(int a1, int a3) {
	std::vector<std::pair<std::string, std::vector<std::string>>> teams;
	CTaskTeam::getMyTeams(teams);
	for(auto & team : teams) {
		callOriginalOnChatInput(a1, (char *)fmt::format("/me {}:    {}", team.first, fmt::join(team.second,"   ")).c_str(), a3);
	}
}

int Chat::handleOwnerCommand(std::string &message, std::vector<std::string> &parts, int a1, int a3) {
	auto ownerState = CTaskTeam::getOwnerState();
	if(ownerState == CTaskTeam::OwnerOff) {
		CTaskTeam::setOwnerState(CTaskTeam::OwnerOn);
		callShowChatMessage(fmt::format("Team owner feature enabled.    ({})", Config::getModuleStrWithVersion()), 6);
	} else {
		CTaskTeam::setOwnerState(CTaskTeam::OwnerOff);
		callShowChatMessage(fmt::format("Team owner feature disabled.    ({})", Config::getModuleStrWithVersion()), 6);
	}
	return 1;
}


int Chat::onChatInput(int a1, char * msg, int a3) {
	try {
		std::string message(msg);
		if (message.length() > 1 && message.starts_with("/")) {
			std::transform(message.begin(), message.end(), message.begin(), [](unsigned char c) { return std::tolower(c); });
			message.erase(0, 1);
			std::vector<std::string> parts;
			Utils::tokenize(message, " ", parts);
			if(parts.size() >= 1) {
				if (parts[0] == "order") {
					return handleOrderCommand(message, parts, a1, a3);
				} else if (parts[0] == "owner") {
					return handleOwnerCommand(message, parts, a1, a3);
				}
			}
		}
	} catch(std::exception & e) {
		callShowChatMessage(fmt::format("{}    ({})", e.what(), Config::getModuleStrWithVersion()), 1);
	}
	return 0;
}

DWORD origOnChatInput = 0;
int __stdcall Chat::callOriginalOnChatInput(int a1, char * msg, int a3) {
	_asm mov ecx, a1
	_asm mov eax, msg
	_asm push a3
	_asm call origOnChatInput
}

#pragma optimize( "", off )
char* onchat_eax;
int onchat_ecx;
void __stdcall Chat::hookOnChatInput(int a3) {
	_asm mov onchat_eax, eax
	_asm mov onchat_ecx, ecx
	if(!onChatInput(onchat_ecx, (char*)onchat_eax, a3)) {
		callOriginalOnChatInput(onchat_ecx, onchat_eax, a3);
	}
}
#pragma optimize( "", on )

void (__stdcall *addrShowChatMessage)(DWORD addrResourceObject, int color, char * msg, int unk);
void Chat::callShowChatMessage(std::string msg, int color) {
	auto ddgame = W2App::getAddrDdGame();
	if (!ddgame) return;
	addrShowChatMessage(ddgame, color, (char*)msg.c_str(), 1);
}

void Chat::install() {
	DWORD addrOnChatInput = _ScanPattern("OnChatInput", "\x81\xEC\x00\x00\x00\x00\x55\x56\x57\x8B\xF8\x8A\x07\x84\xC0\x8B\xF1\x0F\x84\x00\x00\x00\x00\x3C\x2F\x0F\x85\x00\x00\x00\x00\x8D\x44\x24\x40", "??????xxxxxxxxxxxxx????xxxx????xxxx");
	addrShowChatMessage = (void (__stdcall *)(DWORD, int, char *, int))
		_ScanPattern("ShowChatMessage", "\x81\xEC\x00\x00\x00\x00\x53\x55\x8B\xAC\x24\x00\x00\x00\x00\x80\xBD\x00\x00\x00\x00\x00\x8B\x85\x00\x00\x00\x00\x8B\x48\x24\x56\x8B\xB1\x00\x00\x00\x00\x57", "??????xxxxx????xx?????xx????xxxxxx????x");
	_HookDefault(OnChatInput);
}
