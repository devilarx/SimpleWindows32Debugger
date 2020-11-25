#pragma once

#include <string>
#include <optional>
#include <Windows.h>

class Debugger
{
public:
	using DebugEventCode = DWORD;
	static bool init(std::string execName);
	static std::optional<DebugEventCode> nextDebugEvent();
private:
	static std::string _executableName;
	static bool _readyFlag;
	static bool _continue_flag;
};

