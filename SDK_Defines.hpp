#include "SDK.hpp"
#include <Windows.h>
#include <iostream>
#include <chrono>
#include <thread>
#include <dxgi.h>
#include <stdint.h>

inline SDK::UEngine* pEngine = SDK::UEngine::GetEngine();

inline SDK::UWorld* pWorld = SDK::UWorld::GetWorld();

inline SDK::UFont* Roboto = SDK::UObject::FindObject<SDK::UFont>("Font Roboto.Roboto");

namespace Global_Variables
{
	inline const SDK::ULocalPlayer* aLocalPlayers = pWorld->OwningGameInstance->LocalPlayers[0];
	inline const SDK::APlayerController* pPlayerController = aLocalPlayers->PlayerController;
	inline const auto& pLocalPlayerPawn = pPlayerController->AcknowledgedPawn;
	inline const SDK::UGameViewportClient* pLocalViewportClient = aLocalPlayers->ViewportClient;
}

inline void** ppViewportClientVTable = Global_Variables::pLocalViewportClient->VTable;

namespace Trainer_Features
{
	inline bool bNPC_ESPEnabled = true;
	inline bool bNPC_DontAttackLocalActor = true;

	inline bool bExploit_TeleportEnabled = false;
	inline bool bExploit_SpeedhackEnabled = false;
	inline bool bExploit_JumphackEnabled = false;

	inline int nExploit_SpeedhackFactor{ 10000 };
	inline int nExploit_JumphackFactor{ 10000 };
}

namespace Trainer_Handlers
{
	void HadleTrainerVariablesKeys();

	void HandleTrainerInitialization();
}