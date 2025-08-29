#include "Hooked.hpp"

void Trainer_Handlers::HadleTrainerVariablesKeys()
{
    if (GetAsyncKeyState(VK_F1) & 1)
        Trainer_Features::bNPC_ESPEnabled = !Trainer_Features::bNPC_ESPEnabled;

    if (GetAsyncKeyState(VK_F2) & 1)
        Trainer_Features::bNPC_DontAttackLocalActor = !Trainer_Features::bNPC_DontAttackLocalActor;

    if (GetAsyncKeyState(VK_F3) & 1)
        Trainer_Features::bExploit_TeleportEnabled = !Trainer_Features::bExploit_TeleportEnabled;

    if (GetAsyncKeyState(VK_F4) & 1)
        Trainer_Features::bExploit_SpeedhackEnabled = !Trainer_Features::bExploit_SpeedhackEnabled;

    if (GetAsyncKeyState(VK_F5) & 1)
        Trainer_Features::bExploit_JumphackEnabled = !Trainer_Features::bExploit_JumphackEnabled;
}

void Trainer_Handlers::HandleTrainerInitialization()
{
    AllocConsole();
    FILE* Dummy;
    freopen_s(&Dummy, "CONOUT$", "w", stdout);
    freopen_s(&Dummy, "CONIN$", "r", stdin);

    std::cout << "Severed Steel Trainer\n";
    std::cout << "https://github.com/BFG9-k\n\n";
    Hooked_Setup();

    std::cout << "Initialization is complete\n";

    std::cout << "Available features & exploits: \n";
    std::cout << "[F1] >> NPC ESP\n";
    std::cout << "[F2] >> NPCs Don't attack Local actor\n";
    std::cout << "[F3] >> Exploit: Teleport to NPC\n";
}