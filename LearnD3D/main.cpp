#include "main.h"

using namespace Microsoft::WRL;

HWND MainWnd = 0; // Window Handle


LRESULT CALLBACK MainWndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	// Message Processing
	switch (msg)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	default:
		break;
	}
	// Default Window Processing
	return DefWindowProc(hwnd, msg, wParam, lParam);
}


int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE prevInstance, _In_ LPSTR lpCmdLine, _In_ int nCmdShow)
{
	// Initialize WNDCLASS
	WNDCLASSEX windowClass = { 0 };
	windowClass.cbSize = sizeof(WNDCLASSEX);
	windowClass.style = CS_HREDRAW | CS_VREDRAW;
	windowClass.lpfnWndProc = MainWndProc;
	windowClass.hInstance = hInstance;
	windowClass.hIcon = LoadIcon(0, IDC_ARROW);
	windowClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	windowClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	windowClass.lpszClassName = L"RenderClass"; // Window Name

	if (!RegisterClassEx(&windowClass))
	{
		MessageBox(0, L"RegisterClass Failed", 0, 0);
		return 0;
	}

	int width = 1280;
	int height = 720;

	MainWnd = CreateWindow(windowClass.lpszClassName, L"D12X Demo", WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, width, height, 0, 0, hInstance, 0);
	if (!MainWnd)
	{
		MessageBoxW(0, L"CreatWindow Failed", 0, 0);
		return 0;
	}

	ShowWindow(MainWnd, nCmdShow);
	//UpdateWindow(MainWnd);

	MSG msg = { 0 };
	while (msg.message != WM_QUIT)
	{
		if (PeekMessageW(&msg, NULL, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}

	return 0;
}
