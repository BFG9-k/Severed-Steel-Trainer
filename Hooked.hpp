#include "SDK_Defines.hpp"
#include "3rdParty/Minhook/minhook.h"
#include "3rdParty/ImGui/imgui.h"
#include "3rdParty/ImGui/imgui_impl_win32.h"
#include "3rdParty/ImGui/imgui_impl_dx11.h"

namespace UEngine_PostRender
{
	using PostRender_t = void(__thiscall*)(SDK::UObject*, SDK::UObject*);
	inline PostRender_t o_PostRender;
	inline int PostRender_IDX = 99;

	void __stdcall hk_PostRender(SDK::UObject* ViewportClient, SDK::UCanvas* Canvas);
}

inline void Hooked_Setup()
{
	if (MH_Initialize() != MH_OK) 
		throw std::runtime_error("Minhook initialization failed.");

	if (MH_CreateHook(ppViewportClientVTable[99], &UEngine_PostRender::hk_PostRender, reinterpret_cast<void**>(&UEngine_PostRender::o_PostRender)) != MH_OK)
		throw std::runtime_error("hk_PostRender was not installed.");

	if (MH_EnableHook(MH_ALL_HOOKS) != MH_OK) 
		throw std::runtime_error(("Hooked_Setup: MH_EnableHook(MH_ALL_HOOKS) != MH_OK"));

}