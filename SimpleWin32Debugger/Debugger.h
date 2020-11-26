#pragma once

#include <string>
#include <optional>
#include <list>

#include <Windows.h>

namespace sdb {

	struct Breakpoint {
		unsigned int state;
		unsigned int type;
		unsigned int addr;
		unsigned int saveByte;
	};

	class Debugger
	{
	public:
		using DebugEventCode = DWORD;
		static bool init(std::string execName);
		static std::optional<DebugEventCode> nextDebugEvent();
	private:
		static std::string _executableName;
		static std::list<Breakpoint> bpList;

		static bool _readyFlag;
		static bool _continue_flag;

		static HANDLE glDebugProcess;
	};

}