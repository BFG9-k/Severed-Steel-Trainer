#include "Hooked.hpp"

DWORD MainThread(HMODULE Module)
{
    Trainer_Handlers::HandleTrainerInitialization();

    return 0;
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD reason, LPVOID lpReserved)
{
    switch (reason)
    {
    case DLL_PROCESS_ATTACH:
        DisableThreadLibraryCalls(hModule);
        auto InitThread = CreateThread(0, 0, reinterpret_cast<LPTHREAD_START_ROUTINE>(MainThread), hModule, 0, 0);
        CloseHandle(InitThread);
        break;
    }

    return TRUE;
}