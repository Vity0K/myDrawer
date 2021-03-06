#pragma once

namespace myD3D11Framework
{
//------------------------------------------------------------------

	class DLL Render
	{
	public:
		Render();
		virtual ~Render();

		bool CreateDevice(HWND hwnd);
		virtual void Resize(int height, int width);
		void BeginFrame();
		void EndFrame();
		void Shutdown();

		virtual bool Init(HWND hwnd) = 0;
		virtual bool Draw() = 0;
		virtual void Close() = 0;

	protected:
		D3D_DRIVER_TYPE m_driverType;
		D3D_FEATURE_LEVEL m_featureLevel;
		ID3D11Device *m_pd3dDevice;
		ID3D11DeviceContext *m_pImmediateContext;
		IDXGISwapChain *m_pSwapChain;
		ID3D11RenderTargetView *m_pRenderTargetView;

		int m_width, m_height;
	};

//------------------------------------------------------------------
}