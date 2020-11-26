#include "Debugger.h"

using namespace sdb;

std::string Debugger::_executableName = "";
bool Debugger::_readyFlag = false;
bool Debugger::_continue_flag = true;
std::list<Breakpoint> dbList;
HANDLE glDebugProcess = INVALID_HANDLE_VALUE;

bool Debugger::init(std::string execName) {
	STARTUPINFOA startupInfo;
	PROCESS_INFORMATION procInfo;

	RtlZeroMemory(&startupInfo, sizeof(startupInfo));
	RtlZeroMemory(&procInfo, sizeof(procInfo));
	startupInfo.cb = sizeof(startupInfo);
	startupInfo.dwFlags = STARTF_USESHOWWINDOW;
	startupInfo.wShowWindow = SW_SHOWNORMAL;

	Debugger::_readyFlag = CreateProcessA(
		execName.c_str(),
		NULL,
		NULL,
		NULL,
		TRUE,
		DEBUG_ONLY_THIS_PROCESS,
		NULL,
		NULL,
		&startupInfo,
		&procInfo
	);
	if (Debugger::_readyFlag)
		Debugger::_executableName = execName;
	Debugger::glDebugProcess = procInfo.hProcess;
	CloseHandle(procInfo.hThread);
	return Debugger::_readyFlag;
}

std::optional<Debugger::DebugEventCode> Debugger::nextDebugEvent() {
	return std::nullopt;
}