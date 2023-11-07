#include <Windows.h>
#include "WindowsMessageMap.h"

//�� ���� �׷��� ���ڵ��� ����.. ��� ���� �Ҽ� ������ 
//�׳� �ܿ���..
// Wndproc �ϳ��� ¤�� �Ѿ�ڸ� �ĺ���ȣ �����Ŵ�. �޸��� A,B �� ������ �޸��� A �� ���� �ᵵ 
//�޸��� B���� �ƹ��͵� ������ �ʴ� ��ó��
//WM �� ������ �̺�Ʈ
//�̺�Ʈ�� �߻��ϸ� �ü���� �̸� �����ؼ� �ش� ���α׷����� �޽����� �����ϸ� ������ �޼�����
//�� ������� ó���ȴ�. Queue �ڷ� ������ �����ϸ� ���ϴ�
LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {
    static WindowsMessageMap mm;
    OutputDebugString(mm(msg, lParam, wParam).c_str());
    switch (msg) {
    case WM_CLOSE:
        PostQuitMessage(24);
        break;
    
    case WM_KEYDOWN:
        if (wParam == 'F') {
            SetWindowText(hWnd, "Respect");
            
            break;
        }
        break;
    }
    return DefWindowProc(hWnd, msg, wParam, lParam);
}//WinMain �Լ��� ������ Register Class, Create Window, ShowWindow, GetMessageLoop ���

int CALLBACK WinMain(
    HINSTANCE hInstance, //���� ����ǰ� �ִ� ���α׷��� �ν��Ͻ� �ڵ�
    HINSTANCE hPrevInstance, //�ٷ� �տ� ����� ���α׷��� �ν��Ͻ� �ڵ�, ��� NULL
    LPSTR lpCmdLine, //����� ����. main �Լ��� argv �� �ش�
    int nCmdShow) //�����츦 �����ִ� ������ �÷���
{
    const auto pClassName = "hw3d";  // Changed to a non-const character array
    // Register window class
    WNDCLASSEX wc = { 0 };
    wc.cbSize = sizeof(wc);
    wc.style = CS_OWNDC;
    wc.lpfnWndProc = WndProc;
    wc.cbClsExtra = 0;
    wc.cbWndExtra = 0;
    wc.hInstance = hInstance;
    wc.hIcon = nullptr;
    wc.hCursor = nullptr;
    wc.hbrBackground = nullptr;
    wc.lpszMenuName = nullptr;
    wc.hIconSm = nullptr;
    wc.lpszClassName = pClassName; // Assign the character array
    RegisterClassEx(&wc);
    // Create window instance

    HWND hWnd = CreateWindowEx(
        0, pClassName,
        "Joon Window",
        WS_CAPTION | WS_MINIMIZEBOX | WS_SYSMENU,
        200, 200, 640, 480,
        nullptr, nullptr, hInstance, nullptr
    );
    ShowWindow(hWnd, SW_SHOW);
    MSG msg;
    BOOL gResult;

    while ((gResult = GetMessage(&msg, nullptr, 0, 0)) > 0) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
        OutputDebugString("here");
    }
    if (gResult == -1) {
        OutputDebugString("-1");
        return -1;
        
    }
    else {
        OutputDebugString("nothing");
        return msg.wParam;
        
    }
    return 0;
}
