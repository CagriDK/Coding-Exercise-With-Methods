#include <iostream>
#include <string>

#ifdef _WIN32
#include<windows.h>
#include <tlhelp32.h>
#endif // WIN32

#ifdef _WIN32
void CheckProcessId(const std::wstring& processName)
{
	PROCESSENTRY32 processInfo;
	processInfo.dwSize = sizeof(processInfo);

	HANDLE processesSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, NULL);
	if (processesSnapshot == INVALID_HANDLE_VALUE) {
		std::cout << "FindProcessId::INVALID_HANDLE_VALUE\n";
	}


	Process32First(processesSnapshot, &processInfo);
	if (!processName.compare(processInfo.szExeFile))
	{
		CloseHandle(processesSnapshot);
		std::cout << "radarSim.exe is active\n";
	}

	while (Process32Next(processesSnapshot, &processInfo))
	{
		if (!processName.compare(processInfo.szExeFile))
		{
			CloseHandle(processesSnapshot);
			std::cout << "radarSim.exe is active\n";
		}
		else
		{
			std::wcout << "Could not find  " << processName.c_str() << std::endl;
			break;
		}

	}

}
#else
void FindProcessId(const std::wstring& processName) {
	// TO DO
	return 0;
}
#endif




int main()
{
	CheckProcessId(L"radarSim.exe"); 


	return 0;
}


