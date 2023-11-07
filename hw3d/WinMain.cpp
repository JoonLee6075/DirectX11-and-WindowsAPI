#include <Windows.h>
#include "WindowsMessageMap.h"

//넌 뭔데 그렇게 인자들이 많냐.. 라고 생각 할수 있지만 
//그냥 외우자..
// Wndproc 하나만 짚고 넘어가자면 식별번호 같은거다. 메모장 A,B 가 있을때 메모장 A 에 뭔가 써도 
//메모장 B에는 아무것도 적히지 않는 것처럼
//WM 은 윈도우 이벤트
//이벤트가 발생하면 운영체제가 이를 감지해서 해당 프로그램에게 메시지를 전달하며 윈도우 메세지는
//꼭 순서대로 처리된다. Queue 자료 구조를 생각하면 편하다
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
}//WinMain 함수는 윈도우 Register Class, Create Window, ShowWindow, GetMessageLoop 담당

int CALLBACK WinMain(
    HINSTANCE hInstance, //현재 실행되고 있는 프로그램의 인스턴스 핸들
    HINSTANCE hPrevInstance, //바로 앞에 실행된 프로그램의 인스턴스 핸들, 통상 NULL
    LPSTR lpCmdLine, //명령행 인자. main 함수의 argv 에 해당
    int nCmdShow) //윈도우를 보여주는 형태의 플래그
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
