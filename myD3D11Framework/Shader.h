#pragma once

namespace myD3D11Framework
{
//------------------------------------------------------------------

	class DLL Shader
	{
	public:
		Shader(ID3D11Device *device, ID3D11DeviceContext *context);
		// ������ ������� �� ������ �������� �� ������ CreateShader
		void AddInputElementDesc(const char *SemanticName, DXGI_FORMAT format);

		bool CreateShader(wchar_t *namevs, wchar_t *nameps);

		void Draw();
		void Close();

	private:
		HRESULT m_compileshaderfromfile(WCHAR* FileName, LPCSTR EntryPoint, LPCSTR ShaderModel, ID3DBlob** ppBlobOut);

		ID3D11Device *m_device;
		ID3D11DeviceContext *m_context;
		ID3D11VertexShader *m_vertexShader;
		ID3D11PixelShader *m_pixelShader;
		ID3D11InputLayout *m_layout;
		std::vector<ID3D11ShaderResourceView *> m_textures;
		D3D11_INPUT_ELEMENT_DESC *m_layoutformat;
		unsigned int m_numlayout;
	};

//------------------------------------------------------------------
}