#include "../Hooked.hpp"

HRESULT __stdcall D3D12_Present::hk_Present(IDXGISwapChain3* pSwapChain, UINT SyncInterval, UINT Flags)
{
	return o_Present(pSwapChain, SyncInterval, Flags);
}