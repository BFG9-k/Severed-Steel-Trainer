#include "SDK.hpp"
#include <Windows.h>
#include <iostream>
#include <chrono>
#include <thread>
#include <dxgi.h>
#include <d3d11.h>
#include <stdint.h>
#include <vector>

inline SDK::UEngine* pEngine = SDK::UEngine::GetEngine();

inline SDK::UWorld* pWorld = SDK::UWorld::GetWorld();

inline SDK::UFont* Roboto = SDK::UObject::FindObject<SDK::UFont>("Font Roboto.Roboto");

inline const auto& pLocal = pWorld->OwningGameInstance->LocalPlayers[0];

inline const auto& pPlayerController = pLocal->PlayerController;

inline const auto& pLocalPlayerPawn = pPlayerController->AcknowledgedPawn;

inline const auto& pLocalViewportClient = pLocal->ViewportClient;

inline const auto& pLocalPlayerMovement = pPlayerController->Character->CharacterMovement;

inline void** ppViewportClientVTable = pLocalViewportClient->VTable;

namespace Trainer_Features
{
	inline bool bNPC_ESPEnabled = true;
	inline bool bNPC_DontAttackLocalActor = true;

	inline bool bExploit_TeleportEnabled = true;
	inline bool bExploit_SpeedhackEnabled = true;
	inline bool bExploit_JumphackEnabled = true;

	inline int nExploit_SpeedhackFactor{ 10000 };
	inline int nExploit_JumphackFactor{ 10000 };
}

namespace Trainer_Handlers
{
	void HadleTrainerVariablesKeys();

	void HandleTrainerInitialization();
}