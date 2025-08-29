#include "Hooked.hpp"

void UEngine_PostRender::hk_PostRender(SDK::UObject* ViewportClient, SDK::UCanvas* Canvas)
{
	Canvas->K2_DrawText(Roboto, L"Severed Steel Trainer", SDK::FVector2D(Canvas->SizeX - 200, Canvas->SizeY - 1000), SDK::FVector2D(1,1), SDK::FLinearColor(0, 255, 208, 255), 1.f, SDK::FLinearColor(51, 255, 0, 200), SDK::FVector2D(0, 0), true, true, true, SDK::FLinearColor(51, 255, 0));
	Canvas->K2_DrawText(Roboto, L"https://github.com/BFG9-k", SDK::FVector2D(Canvas->SizeX - 220, Canvas->SizeY - 980), SDK::FVector2D(1, 1), SDK::FLinearColor(255, 0, 229, 255), 1.f, SDK::FLinearColor(51, 255, 0, 200), SDK::FVector2D(0, 0), true, true, true, SDK::FLinearColor(51, 255, 0));

    const auto& pActors = pWorld->PersistentLevel->Actors;
    if (!pActors || !Global_Variables::aLocalPlayers || !Global_Variables::pPlayerController || !Global_Variables::pLocalPlayerPawn)
        return;

    Trainer_Handlers::HadleTrainerVariablesKeys();

   for (const auto& pCurrentActor : pActors)
   {
      if (!pCurrentActor || !pCurrentActor->RootComponent)
           continue;

      if (!pCurrentActor->IsA(SDK::ANPC::StaticClass()))
          continue;

      const auto& ActorLocation = pCurrentActor->RootComponent->RelativeLocation;
      const auto& ActorRotation = pCurrentActor->RootComponent->RelativeRotation;

      const auto& pCurrentActorPawn = reinterpret_cast<SDK::ANPC*>(pCurrentActor);
      if (pCurrentActorPawn->bIsDead)
          continue;
    
      SDK::FVector2D ProjectedLocation{};

      if (Trainer_Features::bNPC_ESPEnabled)
      {
          if (Global_Variables::pPlayerController->ProjectWorldLocationToScreen(SDK::FVector(ActorLocation.X, ActorLocation.Y, ActorLocation.Z), &ProjectedLocation, false))
          {
              Canvas->K2_DrawText(pEngine->SmallFont, L"NPC", SDK::FVector2D(ProjectedLocation.X, ProjectedLocation.Y - 45), SDK::FVector2D(1, 1), SDK::FLinearColor(255, 255, 255, 255), 1.f, SDK::FLinearColor(51, 255, 0, 200), SDK::FVector2D(0, 0), true, true, true, SDK::FLinearColor(51, 255, 0));
              Canvas->K2_DrawText(pEngine->SmallFont, std::to_wstring(pCurrentActorPawn->HP).c_str(), SDK::FVector2D(ProjectedLocation.X - 65, ProjectedLocation.Y - 45), SDK::FVector2D(1, 1), SDK::FLinearColor(255, 255, 255, 255), 1.f, SDK::FLinearColor(51, 255, 0, 200), SDK::FVector2D(0, 0), true, true, true, SDK::FLinearColor(51, 255, 0));
          }
      }

      if (Trainer_Features::bNPC_DontAttackLocalActor)
      {
          Canvas->K2_DrawText(Roboto, L"Trainer_Features::bNPC_DontAttackLocalActor", SDK::FVector2D(Canvas->SizeX - 220, Canvas->SizeY - 950), SDK::FVector2D(1, 1), SDK::FLinearColor(0, 255, 208, 255), 1.f, SDK::FLinearColor(51, 255, 0, 200), SDK::FVector2D(0, 0), true, true, true, SDK::FLinearColor(51, 255, 0));
          pCurrentActorPawn->bShouldShoot = false; // NPCs Don't attack player
      }

      if (Trainer_Features::bExploit_TeleportEnabled)
      {
          Canvas->K2_DrawText(Roboto, L"Trainer_Features::bExploit_TeleportEnabled", SDK::FVector2D(Canvas->SizeX - 220, Canvas->SizeY - 900), SDK::FVector2D(1, 1), SDK::FLinearColor(0, 255, 208, 255), 1.f, SDK::FLinearColor(51, 255, 0, 200), SDK::FVector2D(0, 0), true, true, true, SDK::FLinearColor(51, 255, 0));
          Global_Variables::pLocalPlayerPawn->K2_TeleportTo(SDK::FVector(ActorLocation.X, ActorLocation.Y, ActorLocation.Z), SDK::FRotator(ActorRotation.Pitch, ActorRotation.Yaw, ActorRotation.Roll)); // Teleport exploit
      }

     /*if (Trainer_Features::bExploit_SpeedhackEnabled)
      {
          Canvas->K2_DrawText(Roboto, L"Trainer_Features::bExploit_SpeedhackEnabled", SDK::FVector2D(Canvas->SizeX - 220, Canvas->SizeY - 850), SDK::FVector2D(1, 1), SDK::FLinearColor(0, 255, 208, 255), 1.f, SDK::FLinearColor(51, 255, 0, 200), SDK::FVector2D(0, 0), true, true, true, SDK::FLinearColor(51, 255, 0));
          pLocalPlayerMovement->MaxWalkSpeed = 10000.f;
      }

      if (Trainer_Features::bExploit_JumphackEnabled)
      {
          Canvas->K2_DrawText(Roboto, L"Trainer_Features::bExploit_JumphackEnabled", SDK::FVector2D(Canvas->SizeX - 220, Canvas->SizeY - 800), SDK::FVector2D(1, 1), SDK::FLinearColor(0, 255, 208, 255), 1.f, SDK::FLinearColor(51, 255, 0, 200), SDK::FVector2D(0, 0), true, true, true, SDK::FLinearColor(51, 255, 0));
          pLocalPlayerMovement->JumpZVelocity = 10000.f;
      }*/
   }

	UEngine_PostRender::o_PostRender(ViewportClient, Canvas);
}