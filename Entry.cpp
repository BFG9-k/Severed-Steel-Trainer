#include "Hooked.hpp"

unsigned long InitThread(HMODULE Module)
{
    Trainer_Handlers::HandleTrainerInitialization();

    return 0;
}

bool __stdcall DllMain(HMODULE hModule, DWORD reason, LPVOID lpReserved)
{
    switch (reason)
    {
    case DLL_PROCESS_ATTACH:
        DisableThreadLibraryCalls(hModule);
        HANDLE hInitThread = CreateThread(0, 0, reinterpret_cast<LPTHREAD_START_ROUTINE>(InitThread), hModule, 0, 0);
        CloseHandle(hInitThread);
        break;
    }

    return true;
}