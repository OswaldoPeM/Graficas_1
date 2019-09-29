//--------------------------------------------------------------------------------------
// File: Tutorial07.cpp
//
// This application demonstrates texturing
//
// Copyright (c) Microsoft Corporation. All rights reserved.
//--------------------------------------------------------------------------------------
#include <windows.h>

//DirectX
#include <d3d11.h>
#include <d3dx11.h>
#include <d3dcompiler.h>
#include <xnamath.h>

// Abstracciones 
#include"CDevice.h"
#include"CInterfaceDevice.h"
#include "CBuffer.h"
#include "CSwapChain.h"
#include "CRenderTargetView.h"
#include "CDepthStencilView.h"
#include "CVertexShader.h"
#include "CPixelShader.h"
#include"CInputLayout.h"
#include"CShaderResourceView.h"
#include"CSamplerState.h"

//Camara
#include"CCameraManager.h"

// ASSIMP
#include"dependences/Assimp/include/assimp/scene.h"
#include"dependences/Assimp/include/assimp/ai_assert.h"
#include"dependences/Assimp/include/assimp/cimport.h"
#include"dependences/Assimp/include/assimp/postprocess.h"
#include"dependences/Assimp/include/assimp/Importer.hpp"

#include "resource.h"



//--------------------------------------------------------------------------------------
// Global Variables
//--------------------------------------------------------------------------------------

HINSTANCE                           g_hInst = NULL;
HWND                                g_hWnd = NULL;
D3D_DRIVER_TYPE                     g_driverType = D3D_DRIVER_TYPE_NULL;
D3D_FEATURE_LEVEL                   g_featureLevel = D3D_FEATURE_LEVEL_11_0;


CDevice*							g_pd3dDevice = new CDevice();
CInterfaceDevice*					g_pImmediateContext = new CInterfaceDevice();
CSwapChain*							g_SwapChain = new CSwapChain();
CRenderTargetView*					g_RenderTargetView = new CRenderTargetView();
CDepthStencilView*					g_DepthStencilView = new CDepthStencilView();
CVertexShader*						g_VertexShader = new CVertexShader();
CPixelShader*						g_PixelShader = new CPixelShader();
CInputLayout*						g_VertexLayout = new CInputLayout();

//IDXGISwapChain*                     g_pSwapChain = NULL;
//ID3D11RenderTargetView*             g_pRenderTargetView = NULL;
//ID3D11Texture2D*                    g_pDepthStencil = NULL;
//ID3D11DepthStencilView*             g_pDepthStencilView = NULL;
//ID3D11VertexShader*                 g_pVertexShader = NULL;
//ID3D11PixelShader*                  g_pPixelShader = NULL;
//ID3D11InputLayout*                  g_pVertexLayout = NULL;


CBuffer*							g_pVBuffer = new CBuffer();
CBuffer*							g_pIBuffer = new CBuffer();
CBuffer*							g_pCBNCBuffer = new CBuffer();
CBuffer*							g_pCBChangeOnResiz = new CBuffer();
CBuffer*							g_pCBChangesEveryFram = new CBuffer();


//ID3D11Buffer*                       g_pVertexBuffer = NULL;
//ID3D11Buffer*                       g_pIndexBuffer = NULL;
//ID3D11Buffer*                       g_pCBNeverChanges = NULL;
//ID3D11Buffer*                       g_pCBChangeOnResize = NULL;
//ID3D11Buffer*                       g_pCBChangesEveryFrame = NULL;

CShaderResourceView*				g_TextureRV = new CShaderResourceView();
CSamplerState*						g_SamplerLinear = new CSamplerState();

//ID3D11ShaderResourceView*           g_pTextureRV = NULL;
//ID3D11SamplerState*                 g_pSamplerLinear = NULL;

XMMATRIX                            g_World;
//XMMATRIX                            g_View;
//XMMATRIX                            g_Projection;
XMFLOAT4                            g_vMeshColor( 0.7f, 0.7f, 0.7f, 1.0f );

const aiScene*                      g_model;
Assimp::Importer					importador;
//CDevice*							g_Device = new DeviceD3D11();

CCameraManager*						CamMan = new CCameraManager();


//--------------------------------------------------------------------------------------
// Forward declarations
//--------------------------------------------------------------------------------------
HRESULT InitWindow( HINSTANCE hInstance, int nCmdShow );
HRESULT InitDevice();
void CleanupDevice();
LRESULT CALLBACK    WndProc( HWND, UINT, WPARAM, LPARAM );
void Render();


//--------------------------------------------------------------------------------------
// Entry point to the program. Initializes everything and goes into a message processing 
// loop. Idle time is used to render the scene.
//--------------------------------------------------------------------------------------
int WINAPI wWinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance, LPWSTR lpCmdLine, int nCmdShow )
{
    UNREFERENCED_PARAMETER( hPrevInstance );
    UNREFERENCED_PARAMETER( lpCmdLine );

    if( FAILED( InitWindow( hInstance, nCmdShow ) ) )
        return 0;

    if( FAILED( InitDevice() ) )
    {
        CleanupDevice();
        return 0;
    }

    // Main message loop
    MSG msg = {0};
    while( WM_QUIT != msg.message )
    {
		if (msg.message == WM_KEYDOWN)
		{
			XMVECTOR rot;
			XMFLOAT3 movement(0.0f, 0.0f, 0.0f);
			switch (msg.wParam)
			{
			case VK_LEFT:
			{
				movement.x -= 1;
				break;
			}

			case VK_RIGHT:
			{
				movement.x += 1;
				break;
			}

			case VK_UP:
			{
				movement.z += 1;
				break;
			}

			case VK_DOWN:
			{	
				movement.z -= 1;
				break;
			}
			case VK_NUMPAD1:
				movement.y -= 1;
				break;
			case VK_NUMPAD4:
				movement.y += 1;
				break;
			case VK_SPACE:
			{
				RECT rc;
				GetClientRect(g_hWnd, &rc);
				UINT width = rc.right - rc.left;
				UINT height = rc.bottom - rc.top;
				CamMan->swichProjection(width, height);

				CBChangeOnResize cbChangesOnResize;
				cbChangesOnResize.mProjection = XMMatrixTranspose(CamMan->getProjectionMatrix());
				g_pImmediateContext->UpdateSubresource(*g_pCBChangeOnResiz->getBuffer(), 0, NULL, &cbChangesOnResize, 0, 0);
				break;
			}
			default:
				break;
			}
			CamMan->move(&movement);
			CBNeverChanges cbNeverChanges;
			cbNeverChanges.mView = XMMatrixTranspose(CamMan->getViewMatrix());
			g_pImmediateContext->UpdateSubresource(*g_pCBNCBuffer->getBuffer(), 0, NULL, &cbNeverChanges, 0, 0);

			
		}
		if (msg.message == WM_SIZE) {

		}


        if( PeekMessage( &msg, NULL, 0, 0, PM_REMOVE ) )
        {
            TranslateMessage( &msg );
            DispatchMessage( &msg );
        }
        else
        {
            Render();
        }
    }

    CleanupDevice();
    return ( int )msg.wParam;
}


//--------------------------------------------------------------------------------------
// Register class and create window
//--------------------------------------------------------------------------------------
HRESULT InitWindow( HINSTANCE hInstance, int nCmdShow )
{
    // Register class
    WNDCLASSEX wcex;
    wcex.cbSize = sizeof( WNDCLASSEX );
    wcex.style = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc = WndProc;
    wcex.cbClsExtra = 0;
    wcex.cbWndExtra = 0;
    wcex.hInstance = hInstance;
    wcex.hIcon = LoadIcon( hInstance, ( LPCTSTR )IDI_TUTORIAL1 );
    wcex.hCursor = LoadCursor( NULL, IDC_ARROW );
    wcex.hbrBackground = ( HBRUSH )( COLOR_WINDOW + 1 );
    wcex.lpszMenuName = NULL;
    wcex.lpszClassName = L"TutorialWindowClass";
    wcex.hIconSm = LoadIcon( wcex.hInstance, ( LPCTSTR )IDI_TUTORIAL1 );
    if( !RegisterClassEx( &wcex ) )
        return E_FAIL;

    // Create window
    g_hInst = hInstance;
    RECT rc = { 0, 0, 640, 480 };
    AdjustWindowRect( &rc, WS_OVERLAPPEDWINDOW, FALSE );
    g_hWnd = CreateWindow( L"TutorialWindowClass", L"Direct3D 11 Tutorial 7", WS_OVERLAPPEDWINDOW,
                           CW_USEDEFAULT, CW_USEDEFAULT, rc.right - rc.left, rc.bottom - rc.top, NULL, NULL, hInstance,
                           NULL );
    if( !g_hWnd )
        return E_FAIL;

    ShowWindow( g_hWnd, nCmdShow );

    return S_OK;
}


//--------------------------------------------------------------------------------------
// Helper for compiling shaders with D3DX11
//--------------------------------------------------------------------------------------
HRESULT CompileShaderFromFile( WCHAR* szFileName, LPCSTR szEntryPoint, LPCSTR szShaderModel, ID3DBlob** ppBlobOut )
{
    HRESULT hr = S_OK;

    DWORD dwShaderFlags = D3DCOMPILE_ENABLE_STRICTNESS;
#if defined( DEBUG ) || defined( _DEBUG )
    // Set the D3DCOMPILE_DEBUG flag to embed debug information in the shaders.
    // Setting this flag improves the shader debugging experience, but still allows 
    // the shaders to be optimized and to run exactly the way they will run in 
    // the release configuration of this program.
    dwShaderFlags |= D3DCOMPILE_DEBUG;
#endif

    ID3DBlob* pErrorBlob;
    hr = D3DX11CompileFromFile( szFileName, NULL, NULL, szEntryPoint, szShaderModel, 
        dwShaderFlags, 0, NULL, ppBlobOut, &pErrorBlob, NULL );
    if( FAILED(hr) )
    {
        if( pErrorBlob != NULL )
            OutputDebugStringA( (char*)pErrorBlob->GetBufferPointer() );
        if( pErrorBlob ) pErrorBlob->Release();
        return hr;
    }
    if( pErrorBlob ) pErrorBlob->Release();

    return S_OK;
}
// Reflect https://takinginitiative.wordpress.com/2011/12/11/directx-1011-basic-shader-reflection-automatic-input-layout-creation/

HRESULT CreateInputLayoutDescFromVertexShaderSignature(ID3DBlob* pShaderBlob)
{
	// Reflect shader info
	ID3D11ShaderReflection* pVertexShaderReflection = NULL;
	if (FAILED(D3DReflect(pShaderBlob->GetBufferPointer(), pShaderBlob->GetBufferSize(), IID_ID3D11ShaderReflection, (void**)&pVertexShaderReflection)))
	{
		return S_FALSE;
	}

	// Get shader info
	D3D11_SHADER_DESC shaderDesc;
	pVertexShaderReflection->GetDesc(&shaderDesc);

	// Read input layout description from shader info
	std::vector<D3D11_INPUT_ELEMENT_DESC> inputLayoutDesc;
	for (unsigned int i = 0; i < shaderDesc.InputParameters; i++)
	{
		D3D11_SIGNATURE_PARAMETER_DESC paramDesc;
		pVertexShaderReflection->GetInputParameterDesc(i, &paramDesc);

		// fill out input element desc
		D3D11_INPUT_ELEMENT_DESC elementDesc;
		elementDesc.SemanticName = paramDesc.SemanticName;
		elementDesc.SemanticIndex = paramDesc.SemanticIndex;
		elementDesc.InputSlot = 0;
		elementDesc.AlignedByteOffset = D3D11_APPEND_ALIGNED_ELEMENT;
		elementDesc.InputSlotClass = D3D11_INPUT_PER_VERTEX_DATA;
		elementDesc.InstanceDataStepRate = 0;

		// determine DXGI format
		if (paramDesc.Mask == 1)
		{
			if (paramDesc.ComponentType == D3D_REGISTER_COMPONENT_UINT32) elementDesc.Format = DXGI_FORMAT_R32_UINT;
			else if (paramDesc.ComponentType == D3D_REGISTER_COMPONENT_SINT32) elementDesc.Format = DXGI_FORMAT_R32_SINT;
			else if (paramDesc.ComponentType == D3D_REGISTER_COMPONENT_FLOAT32) elementDesc.Format = DXGI_FORMAT_R32_FLOAT;
		}
		else if (paramDesc.Mask <= 3)
		{
			if (paramDesc.ComponentType == D3D_REGISTER_COMPONENT_UINT32) elementDesc.Format = DXGI_FORMAT_R32G32_UINT;
			else if (paramDesc.ComponentType == D3D_REGISTER_COMPONENT_SINT32) elementDesc.Format = DXGI_FORMAT_R32G32_SINT;
			else if (paramDesc.ComponentType == D3D_REGISTER_COMPONENT_FLOAT32) elementDesc.Format = DXGI_FORMAT_R32G32_FLOAT;
		}
		else if (paramDesc.Mask <= 7)
		{
			if (paramDesc.ComponentType == D3D_REGISTER_COMPONENT_UINT32) elementDesc.Format = DXGI_FORMAT_R32G32B32_UINT;
			else if (paramDesc.ComponentType == D3D_REGISTER_COMPONENT_SINT32) elementDesc.Format = DXGI_FORMAT_R32G32B32_SINT;
			else if (paramDesc.ComponentType == D3D_REGISTER_COMPONENT_FLOAT32) elementDesc.Format = DXGI_FORMAT_R32G32B32_FLOAT;
		}
		else if (paramDesc.Mask <= 15)
		{
			if (paramDesc.ComponentType == D3D_REGISTER_COMPONENT_UINT32) elementDesc.Format = DXGI_FORMAT_R32G32B32A32_UINT;
			else if (paramDesc.ComponentType == D3D_REGISTER_COMPONENT_SINT32) elementDesc.Format = DXGI_FORMAT_R32G32B32A32_SINT;
			else if (paramDesc.ComponentType == D3D_REGISTER_COMPONENT_FLOAT32) elementDesc.Format = DXGI_FORMAT_R32G32B32A32_FLOAT;
		}

		//save element desc
		inputLayoutDesc.push_back(elementDesc);
	}

	// Try to create Input Layout
	HRESULT hr = g_pd3dDevice->CreateInputLayout(&inputLayoutDesc[0], inputLayoutDesc.size(), pShaderBlob->GetBufferPointer(), pShaderBlob->GetBufferSize(), g_VertexLayout->getInputLayout());

	//Free allocation shader reflection memory
	pVertexShaderReflection->Release();

	
	return hr;
}
//--------------------------------------------------------------------------------------
// Create Direct3D device and swap chain
//--------------------------------------------------------------------------------------
HRESULT InitDevice()
{
    HRESULT hr = S_OK;

    RECT rc;
    GetClientRect( g_hWnd, &rc );
    UINT width = rc.right - rc.left;
    UINT height = rc.bottom - rc.top;

    UINT createDeviceFlags = 0;
#ifdef _DEBUG
    createDeviceFlags |= D3D11_CREATE_DEVICE_DEBUG;
#endif

    D3D_DRIVER_TYPE driverTypes[] =
    {
        D3D_DRIVER_TYPE_HARDWARE,
        D3D_DRIVER_TYPE_WARP,
        D3D_DRIVER_TYPE_REFERENCE,
    };
    UINT numDriverTypes = ARRAYSIZE( driverTypes );

    D3D_FEATURE_LEVEL featureLevels[] =
    {
        D3D_FEATURE_LEVEL_11_0,
        D3D_FEATURE_LEVEL_10_1,
        D3D_FEATURE_LEVEL_10_0,
    };
    UINT numFeatureLevels = ARRAYSIZE( featureLevels );

    /*DXGI_SWAP_CHAIN_DESC sd;
    ZeroMemory( &sd, sizeof( sd ) );
    sd.BufferCount = 1;
    sd.BufferDesc.Width = width;
    sd.BufferDesc.Height = height;
    sd.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
    sd.BufferDesc.RefreshRate.Numerator = 60;
    sd.BufferDesc.RefreshRate.Denominator = 1;
    sd.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
    sd.OutputWindow = g_hWnd;
    sd.SampleDesc.Count = 1;
    sd.SampleDesc.Quality = 0;
    sd.Windowed = TRUE;*/

	g_SwapChain->init(width, height, g_hWnd);

    for( UINT driverTypeIndex = 0; driverTypeIndex < numDriverTypes; driverTypeIndex++ )
    {
        g_driverType = driverTypes[driverTypeIndex];
		hr = g_pd3dDevice->CreateDeviceAndSwapChain(NULL, g_driverType, NULL, createDeviceFlags, featureLevels, numFeatureLevels,
			D3D11_SDK_VERSION, g_SwapChain->getSwapChainDesc(), g_SwapChain->getSwapChain(), &g_featureLevel, g_pImmediateContext->getInterface());
        if( SUCCEEDED( hr ) )
            break;
    }
    if( FAILED( hr ) )
        return hr;

    // Create a render target view
    ID3D11Texture2D* pBackBuffer = NULL;

    //hr = g_pSwapChain->GetBuffer( 0, __uuidof( ID3D11Texture2D ), ( LPVOID* )&pBackBuffer );
	hr = g_SwapChain->GetBuffer(0, __uuidof(ID3D11Texture2D), (LPVOID*)&pBackBuffer);
    if( FAILED( hr ) )
        return hr;

	hr = g_pd3dDevice->CreateRenderTargetView(pBackBuffer, NULL, g_RenderTargetView->getRenderTargetView());

    pBackBuffer->Release();
    if( FAILED( hr ) )
        return hr;

    // Create depth stencil texture

    /*D3D11_TEXTURE2D_DESC descDepth;

    ZeroMemory( &descDepth, sizeof(descDepth) );
    descDepth.Width = width;
    descDepth.Height = height;
    descDepth.MipLevels = 1;
    descDepth.ArraySize = 1;
    descDepth.Format = DXGI_FORMAT_D24_UNORM_S8_UINT;
    descDepth.SampleDesc.Count = 1;
    descDepth.SampleDesc.Quality = 0;
    descDepth.Usage = D3D11_USAGE_DEFAULT;
    descDepth.BindFlags = D3D11_BIND_DEPTH_STENCIL;
    descDepth.CPUAccessFlags = 0;
    descDepth.MiscFlags = 0;*/


	g_DepthStencilView->init(width, height);

	hr = g_pd3dDevice->CreateTexture2D(g_DepthStencilView->getDescDepth(), NULL, g_DepthStencilView->getDepthStencil());
    if( FAILED( hr ) )
        return hr;

    // Create the depth stencil view
    /*D3D11_DEPTH_STENCIL_VIEW_DESC descDSV;
    ZeroMemory( &descDSV, sizeof(descDSV) );
    descDSV.Format = descDepth.Format;
    descDSV.ViewDimension = D3D11_DSV_DIMENSION_TEXTURE2D;
    descDSV.Texture2D.MipSlice = 0;*/

	hr = g_pd3dDevice->CreateDepthStencilView(*g_DepthStencilView->getDepthStencil(), g_DepthStencilView->getDescDepthStencilView(), g_DepthStencilView->getDepthStencilView());
    if( FAILED( hr ) )
        return hr;

    g_pImmediateContext->OMSetRenderTargets( 1, g_RenderTargetView->getRenderTargetView(), *g_DepthStencilView->getDepthStencilView());

    // Setup the viewport
    D3D11_VIEWPORT vp;
    vp.Width = (FLOAT)width;
    vp.Height = (FLOAT)height;
    vp.MinDepth = 0.0f;
    vp.MaxDepth = 1.0f;
    vp.TopLeftX = 0;
    vp.TopLeftY = 0;
    g_pImmediateContext->RSSetViewports( 1, &vp );

    // Compile the vertex shader
    ID3DBlob* pVSBlob = NULL;
    hr = CompileShaderFromFile( L"Tutorial07.fx", "VS", "vs_4_0", &pVSBlob );
    if( FAILED( hr ) )
    {
        MessageBox( NULL,
                    L"The FX file cannot be compiled.  Please run this executable from the directory that contains the FX file.", L"Error", MB_OK );
        return hr;
    }

    // Create the vertex shader
    hr = g_pd3dDevice->CreateVertexShader( pVSBlob->GetBufferPointer(), pVSBlob->GetBufferSize(), NULL, g_VertexShader->getVertexShader());
    if( FAILED( hr ) )
    {    
        pVSBlob->Release();
        return hr;
    }

    // Define the input layout
    

	g_VertexLayout->setLayoutDesc("POSITION", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, 0, INPUT_PER_VERTEX_DATA, 0);
	g_VertexLayout->setLayoutDesc("TEXCOORD", 0, DXGI_FORMAT_R32G32_FLOAT, 0, 12, INPUT_PER_VERTEX_DATA, 0);

	//// Create the input layout

	hr = CreateInputLayoutDescFromVertexShaderSignature(pVSBlob);
	if (FAILED(hr))
	{
		pVSBlob->Release();
		return hr;
	}

 //   UINT numElements = g_VertexLayout->getLayoutSize();
	//
 //   hr = g_pd3dDevice->CreateInputLayout(g_VertexLayout->getLayoutDesc(), numElements, pVSBlob->GetBufferPointer(),
 //                                         pVSBlob->GetBufferSize(), g_VertexLayout->getInputLayout());
 //   pVSBlob->Release();
 //   if( FAILED( hr ) )
 //       return hr;

	pVSBlob->Release();
    // Set the input layout
    g_pImmediateContext->IASetInputLayout(*g_VertexLayout->getInputLayout());

    // Compile the pixel shader
    ID3DBlob* pPSBlob = NULL;
    hr = CompileShaderFromFile( L"Tutorial07.fx", "PS", "ps_4_0", &pPSBlob );
    if( FAILED( hr ) )
    {
        MessageBox( NULL,
                    L"The FX file cannot be compiled.  Please run this executable from the directory that contains the FX file.", L"Error", MB_OK );
        return hr;
    }

    // Create the pixel shader
    hr = g_pd3dDevice->CreatePixelShader( pPSBlob->GetBufferPointer(), pPSBlob->GetBufferSize(), NULL, g_PixelShader->getPixelShader());
    pPSBlob->Release();
    if( FAILED( hr ) )
        return hr;

    // Create vertex buffer
    SimpleVertex vertices[] =
    {
        { XMFLOAT4( -1.0f, 1.0f, -1.0f ,1), XMFLOAT2( 0.0f, 1.0f ) },
        { XMFLOAT4( 1.0f, 1.0f, -1.0f ,1), XMFLOAT2( 1.0f, 1.0f ) },
        { XMFLOAT4( 1.0f, 1.0f, 1.0f ,1), XMFLOAT2( 1.0f, 0.0f ) },
        { XMFLOAT4( -1.0f, 1.0f, 1.0f ,1), XMFLOAT2( 0.0f, 0.0f ) },
				 
        { XMFLOAT4( -1.0f, -1.0f, -1.0f ,1), XMFLOAT2( 0.0f, 1.0f ) },
        { XMFLOAT4( 1.0f, -1.0f, -1.0f ,1), XMFLOAT2( 1.0f, 1.0f ) },
        { XMFLOAT4( 1.0f, -1.0f, 1.0f,1 ), XMFLOAT2( 1.0f, 0.0f ) },
        { XMFLOAT4( -1.0f, -1.0f, 1.0f ,1), XMFLOAT2( 0.0f, 0.0f ) },
				 
        { XMFLOAT4( -1.0f, -1.0f, 1.0f ,1), XMFLOAT2( 0.0f, 1.0f ) },
        { XMFLOAT4( -1.0f, -1.0f, -1.0f ,1), XMFLOAT2( 1.0f, 1.0f ) },
        { XMFLOAT4( -1.0f, 1.0f, -1.0f ,1), XMFLOAT2( 1.0f, 0.0f ) },
        { XMFLOAT4( -1.0f, 1.0f, 1.0f,1 ), XMFLOAT2( 0.0f, 0.0f ) },
				 
        { XMFLOAT4( 1.0f, -1.0f, 1.0f,1 ), XMFLOAT2( 0.0f, 1.0f ) },
        { XMFLOAT4( 1.0f, -1.0f, -1.0f ,1), XMFLOAT2( 1.0f, 1.0f ) },
        { XMFLOAT4( 1.0f, 1.0f, -1.0f,1 ), XMFLOAT2( 1.0f, 0.0f ) },
        { XMFLOAT4( 1.0f, 1.0f, 1.0f,1 ), XMFLOAT2( 0.0f, 0.0f ) },
				 
        { XMFLOAT4( -1.0f, -1.0f, -1.0f,1 ), XMFLOAT2( 0.0f, 1.0f ) },
        { XMFLOAT4( 1.0f, -1.0f, -1.0f,1 ), XMFLOAT2( 1.0f, 1.0f ) },
        { XMFLOAT4( 1.0f, 1.0f, -1.0f,1 ), XMFLOAT2( 1.0f, 0.0f ) },
        { XMFLOAT4( -1.0f, 1.0f, -1.0f,1 ), XMFLOAT2( 0.0f, 0.0f ) },
				 
        { XMFLOAT4( -1.0f, -1.0f, 1.0f,1 ), XMFLOAT2( 0.0f, 1.0f ) },
        { XMFLOAT4( 1.0f, -1.0f, 1.0f,1 ), XMFLOAT2( 1.0f, 1.0f ) },
        { XMFLOAT4( 1.0f, 1.0f, 1.0f,1 ), XMFLOAT2( 1.0f, 0.0f ) },
        { XMFLOAT4( -1.0f, 1.0f, 1.0f,1 ), XMFLOAT2( 0.0f, 0.0f ) },
    };

    //D3D11_BUFFER_DESC bd;
    //ZeroMemory( &bd, sizeof(bd) );
    //bd.Usage = D3D11_USAGE_DEFAULT;
    //bd.ByteWidth = sizeof( SimpleVertex ) * 24;
    //bd.BindFlags = D3D11_BIND_VERTEX_BUFFER;//solo almacena vertices
    //bd.CPUAccessFlags = 0;
    //D3D11_SUBRESOURCE_DATA InitData;
    //ZeroMemory( &InitData, sizeof(InitData) );
    //InitData.pSysMem = vertices;


	g_pVBuffer->init(24,VERTEX,vertices);


    hr = g_pd3dDevice->CreateBuffer(g_pVBuffer->getBufferDesc(), g_pVBuffer->getInitData(), g_pVBuffer->getBuffer());
    if( FAILED( hr ) )
        return hr;

    // Set vertex buffer
    UINT stride = sizeof( SimpleVertex );
    UINT offset = 0;
    g_pImmediateContext->IASetVertexBuffers( 0, 1, g_pVBuffer->getBuffer(), &stride, &offset );

    // Create index buffer
    // Create vertex buffer
    WORD indices[] =
    {
        3,1,0,
        2,1,3,

        6,4,5,
        7,4,6,

        11,9,8,
        10,9,11,

        14,12,13,
        15,12,14,

        19,17,16,
        18,17,19,

        22,20,21,
        23,20,22
    };

    /*bd.Usage = D3D11_USAGE_DEFAULT;
    bd.ByteWidth = sizeof( WORD ) * 36;
    bd.BindFlags = D3D11_BIND_INDEX_BUFFER;
    bd.CPUAccessFlags = 0;
    InitData.pSysMem = indices;*/

	g_pIBuffer->init(36, INDEX, indices);

	hr = g_pd3dDevice->CreateBuffer(g_pIBuffer->getBufferDesc(), g_pIBuffer->getInitData() , g_pIBuffer->getBuffer());
    if( FAILED( hr ) )
        return hr;

    // Set index buffer
	g_pImmediateContext->IASetIndexBuffer(*g_pIBuffer->getBuffer(), DXGI_FORMAT_R16_UINT, 0);

    // Set primitive topology
    g_pImmediateContext->IASetPrimitiveTopology( D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST );

    // Create the constant buffers
    /*bd.Usage = D3D11_USAGE_DEFAULT;
    bd.ByteWidth = sizeof(CBNeverChanges);
    bd.BindFlags = D3D11_BIND_CONSTANT_BUFFER;
    bd.CPUAccessFlags = 0;*/

	g_pCBNCBuffer->init(sizeof(CBNeverChanges), CONSTANT);

    hr = g_pd3dDevice->CreateBuffer(g_pCBNCBuffer->getBufferDesc(), NULL, g_pCBNCBuffer->getBuffer());
    if( FAILED( hr ) )
        return hr;
    
    //bd.ByteWidth = sizeof(CBChangeOnResize);
	g_pCBChangeOnResiz->init(sizeof(CBChangeOnResize), CONSTANT);

    hr = g_pd3dDevice->CreateBuffer(g_pCBChangeOnResiz->getBufferDesc(), NULL, g_pCBChangeOnResiz->getBuffer());
    if( FAILED( hr ) )
        return hr;
    
    //bd.ByteWidth = sizeof(CBChangesEveryFrame);

	g_pCBChangesEveryFram->init(sizeof(CBChangesEveryFrame), CONSTANT);

	hr = g_pd3dDevice->CreateBuffer(g_pCBChangesEveryFram->getBufferDesc() , NULL, g_pCBChangesEveryFram->getBuffer());
    if( FAILED( hr ) )
        return hr;

    // Load the Texture
	hr = g_pd3dDevice->CreateShaderResourceViewFromFile(L"rails.dds", NULL, NULL, g_TextureRV->getTextureRV(), NULL);
    if( FAILED( hr ) )
        return hr;

    // Create the sample state
    D3D11_SAMPLER_DESC sampDesc;
    ZeroMemory( &sampDesc, sizeof(sampDesc) );
    sampDesc.Filter = D3D11_FILTER_MIN_MAG_MIP_LINEAR;
    sampDesc.AddressU = D3D11_TEXTURE_ADDRESS_WRAP;
    sampDesc.AddressV = D3D11_TEXTURE_ADDRESS_WRAP;
    sampDesc.AddressW = D3D11_TEXTURE_ADDRESS_WRAP;
    sampDesc.ComparisonFunc = D3D11_COMPARISON_NEVER;
    sampDesc.MinLOD = 0;
    sampDesc.MaxLOD = D3D11_FLOAT32_MAX;
    hr = g_pd3dDevice->CreateSamplerState( &sampDesc, g_SamplerLinear->getSamplerLinear());
    if( FAILED( hr ) )
        return hr;

    // Initialize the world matrices
    g_World = XMMatrixIdentity();

    // Initialize the view matrix
    XMVECTOR Eye = XMVectorSet( 0.0f, 3.0f, -6.0f, 0.0f );
    XMVECTOR At = XMVectorSet( 0.0f, 1.0f, 0.0f, 0.0f );
    XMVECTOR Up = XMVectorSet( 0.0f, 1.0f, 0.0f, 0.0f );
    //g_View = XMMatrixLookAtLH( Eye, At, Up );

	CamMan->init();

    CBNeverChanges cbNeverChanges;
	cbNeverChanges.mView = XMMatrixTranspose(CamMan->getViewMatrix());
    g_pImmediateContext->UpdateSubresource(*g_pCBNCBuffer->getBuffer(), 0, NULL, &cbNeverChanges, 0, 0 );

    // Initialize the projection matrix
    //g_Projection = XMMatrixPerspectiveFovLH( XM_PIDIV4, width / (FLOAT)height, 0.01f, 100.0f );
	CamMan->setProjectionMatrix(width, height);

	//g_Projection = XMMatrixOrthographicLH(width/90, height/90, 0.001f, 100.0f);
    CBChangeOnResize cbChangesOnResize;
	cbChangesOnResize.mProjection = XMMatrixTranspose(CamMan->getProjectionMatrix());
    g_pImmediateContext->UpdateSubresource(*g_pCBChangeOnResiz->getBuffer(), 0, NULL, &cbChangesOnResize, 0, 0 );

    return S_OK;
}


//--------------------------------------------------------------------------------------
// Clean up the objects we've created
//--------------------------------------------------------------------------------------
void CleanupDevice()
{
    if( g_pImmediateContext ) g_pImmediateContext->ClearState();
	if (CamMan) CamMan->destroy();
    //if( g_pSamplerLinear ) g_pSamplerLinear->Release();
	if (g_SamplerLinear) g_SamplerLinear->destroy();
    //if( g_pTextureRV ) g_pTextureRV->Release();
	if (g_TextureRV) g_TextureRV->destoy();
    //if( g_pCBNeverChanges ) g_pCBNeverChanges->Release();
	if (g_pCBNCBuffer)g_pCBNCBuffer->destroy();
    //if( g_pCBChangeOnResize ) g_pCBChangeOnResize->Release();
	if (g_pCBChangeOnResiz) g_pCBChangeOnResiz->destroy();
    //if( g_pCBChangesEveryFrame ) g_pCBChangesEveryFrame->Release();
	if (g_pCBChangesEveryFram)g_pCBChangesEveryFram->destroy();
    //if( g_pVertexBuffer ) g_pVertexBuffer->Release();
	if (g_pVBuffer)g_pVBuffer->destroy();
    //if( g_pIndexBuffer ) g_pIndexBuffer->Release();
	if(g_pIBuffer)g_pIBuffer->destroy();
    //if( g_pVertexLayout ) g_pVertexLayout->Release();
	if (g_VertexLayout)g_VertexLayout->destoy();
    //if( g_pVertexShader ) g_pVertexShader->Release();
	if (g_VertexShader) g_VertexShader->destroy();
   // if( g_pPixelShader ) g_pPixelShader->Release();
	if (g_PixelShader) g_PixelShader->destroy();
    //if( g_pDepthStencil ) g_pDepthStencil->Release();
	//if( g_pDepthStencilView ) g_pDepthStencilView->Release();
	if (g_DepthStencilView)g_DepthStencilView->destroy();
    //if( g_pRenderTargetView ) g_pRenderTargetView->Release();
	if (g_RenderTargetView)g_RenderTargetView->destroy();
    //if( g_pSwapChain ) g_pSwapChain->Release();
	if (g_SwapChain)g_SwapChain->destroy();
	if (g_pImmediateContext) { g_pImmediateContext->destroy(); }
	if (g_pd3dDevice) { g_pd3dDevice->destroy(); }
}


//--------------------------------------------------------------------------------------
// Called every time the application receives a message
//--------------------------------------------------------------------------------------
LRESULT CALLBACK WndProc( HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam )
{
    PAINTSTRUCT ps;
    HDC hdc;

    switch( message )
    {
        case WM_PAINT:
            hdc = BeginPaint( hWnd, &ps );
            EndPaint( hWnd, &ps );
            break;

        case WM_DESTROY:
            PostQuitMessage( 0 );
            break;

        default:
            return DefWindowProc( hWnd, message, wParam, lParam );
    }

    return 0;
}


//--------------------------------------------------------------------------------------
// Render a frame
//--------------------------------------------------------------------------------------
void Render()
{
    // Update our time
    static float t = 0.0f;
    if( g_driverType == D3D_DRIVER_TYPE_REFERENCE )
    {
        t += ( float )XM_PI * 0.0125f;
    }
    else
    {
        static DWORD dwTimeStart = 0;
        DWORD dwTimeCur = GetTickCount();
        if( dwTimeStart == 0 )
            dwTimeStart = dwTimeCur;
        t = ( dwTimeCur - dwTimeStart ) / 1000.0f;
    }

    // Rotate cube around the origin
    g_World = XMMatrixRotationY( t );



    // Modify the color
    g_vMeshColor.x = ( sinf( t * 1.0f ) + 1.0f ) * 0.5f;
    g_vMeshColor.y = ( cosf( t * 3.0f ) + 1.0f ) * 0.5f;
    g_vMeshColor.z = ( sinf( t * 5.0f ) + 1.0f ) * 0.5f;

    //
    // Clear the back buffer
    //
    float ClearColor[4] = { 0.0f, 0.125f, 0.3f, 1.0f }; // red, green, blue, alpha

	g_pImmediateContext->ClearRenderTargetView(*g_RenderTargetView->getRenderTargetView(), ClearColor);

    //
    // Clear the depth buffer to 1.0 (max depth)
    //
    g_pImmediateContext->ClearDepthStencilView(*g_DepthStencilView->getDepthStencilView(), D3D11_CLEAR_DEPTH, 1.0f, 0 );

    //
    // Update variables that change once per frame
    //
	XMMATRIX cpy_g = XMMatrixIdentity();
    CBChangesEveryFrame cb;
	CBChangesEveryFrame cb1;
	cpy_g = XMMatrixMultiplyTranspose(XMMatrixScaling(cos(t)*cos(t), cos(t)*cos(t), cos(t)*cos(t)), cpy_g);
    cb1.mWorld = XMMatrixMultiplyTranspose(cpy_g, XMMatrixTranslation(2, 0, 0));
    cb1.vMeshColor = g_vMeshColor;

    g_pImmediateContext->UpdateSubresource(*g_pCBChangesEveryFram->getBuffer(), 0, NULL, &cb1, 0, 0 );

    //
    // Render the cube
    //
    g_pImmediateContext->VSSetShader(*g_VertexShader->getVertexShader(), NULL, 0 );
    g_pImmediateContext->VSSetConstantBuffers( 0, 1, g_pCBNCBuffer->getBuffer());
    g_pImmediateContext->VSSetConstantBuffers( 1, 1, g_pCBChangeOnResiz->getBuffer());
    g_pImmediateContext->VSSetConstantBuffers( 2, 1, g_pCBChangesEveryFram->getBuffer());
    g_pImmediateContext->PSSetShader( *g_PixelShader->getPixelShader(), NULL, 0 );
    g_pImmediateContext->PSSetConstantBuffers( 2, 1, g_pCBChangesEveryFram->getBuffer());
    g_pImmediateContext->PSSetShaderResources( 0, 1, g_TextureRV->getTextureRV());
    g_pImmediateContext->PSSetSamplers( 0, 1, g_SamplerLinear->getSamplerLinear());
    g_pImmediateContext->DrawIndexed( 36, 0, 0 );

	// cubo de la izquierda
    cb.mWorld = XMMatrixTranspose( g_World );
    cb.vMeshColor = g_vMeshColor;
    g_pImmediateContext->UpdateSubresource(*g_pCBChangesEveryFram->getBuffer(), 0, NULL, &cb, 0, 0 );

	cb.mWorld = XMMatrixMultiplyTranspose(g_World, XMMatrixTranslation(-2, 0, 0));
	cb.vMeshColor = g_vMeshColor;
	g_pImmediateContext->UpdateSubresource(*g_pCBChangesEveryFram->getBuffer(), 0, NULL, &cb, 0, 0);
    g_pImmediateContext->DrawIndexed( 36, 0, 0 );

	//cubo de la centro
	g_World = XMMatrixMultiplyTranspose(g_World, XMMatrixTranslation(0, 0, 0));
	g_World = XMMatrixMultiplyTranspose(XMMatrixScaling(sin(t)*sin(t),sin(t)*sin(t), sin(t)*sin(t)), g_World);
	cb.mWorld = XMMatrixTranspose(g_World);
	cb.vMeshColor = g_vMeshColor;
	g_pImmediateContext->UpdateSubresource(*g_pCBChangesEveryFram->getBuffer(), 0, NULL, &cb, 0, 0);

    g_pImmediateContext->DrawIndexed( 36, 0, 0 );
	
    //
    // Present our back buffer to our front buffer
    //
    //g_pSwapChain->Present( 0, 0 );
	g_SwapChain->Present(0, 0);
}
