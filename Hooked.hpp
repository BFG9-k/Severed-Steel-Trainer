#include "Includes.hpp"

namespace UEngine_PostRender
{
	using PostRender_t = void(__thiscall*)(SDK::UObject*, SDK::UObject*);
	inline PostRender_t o_PostRender;
	inline constexpr int PostRender_IDX = 99;

	void __stdcall hk_PostRender(SDK::UObject* ViewportClient, SDK::UCanvas* Canvas);
}

namespace D3D12_Present
{
	using Present_t = HRESULT(__stdcall*)(IDXGISwapChain*, UINT, UINT);
	inline Present_t o_Present;
	inline constexpr int Present_IDX = 140;

	HRESULT __stdcall hk_Present(IDXGISwapChain3* pSwapChain, UINT SyncInterval, UINT Flags);
}

inline void Hooked_Setup()
{
	if (MH_Initialize() != MH_OK) 
		throw std::runtime_error("Minhook initialization failed.");

	if (MH_CreateHook(ppViewportClientVTable[UEngine_PostRender::PostRender_IDX], &UEngine_PostRender::hk_PostRender, reinterpret_cast<void**>(&UEngine_PostRender::o_PostRender)) != MH_OK)
		throw std::runtime_error("hk_PostRender was not installed.");

	if (MH_EnableHook(MH_ALL_HOOKS) != MH_OK) 
		throw std::runtime_error(("Hooked_Setup: MH_EnableHook(MH_ALL_HOOKS) != MH_OK"));
}