/******************************************************************************************
*	Chili Direct3D Engine																  *
*	Copyright 2018 PlanetChili <http://www.planetchili.net>								  *
*																						  *
*	This file is part of Chili Direct3D Engine.											  *
*																						  *
*	Chili Direct3D Engine is free software: you can redistribute it and/or modify		  *
*	it under the terms of the GNU General Public License as published by				  *
*	the Free Software Foundation, either version 3 of the License, or					  *
*	(at your option) any later version.													  *
*																						  *
*	The Chili Direct3D Engine is distributed in the hope that it will be useful,		  *
*	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
*	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
*	GNU General Public License for more details.										  *
*																						  *
*	You should have received a copy of the GNU General Public License					  *
*	along with The Chili Direct3D Engine.  If not, see <http://www.gnu.org/licenses/>.    *
******************************************************************************************/
#include "Window.h"


int CALLBACK WinMain(
    HINSTANCE hInstance,
    HINSTANCE hPrevInstance,
    LPSTR     lpCmdLine,
    int       nCmdShow)
{
    Window wnd(800, 300, "Window");
    Window wnd2(800, 300, "Window");

    MSG msg;
    BOOL gResult;
    while ((gResult = GetMessage(&msg, nullptr, 0, 0)) > 0)
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    if (gResult == -1)
    {
        return -1;
    }
    return msg.wParam;
}

/*
#include <Windows.h>
#include "WindowsMessageMap.h"
#include <sstream>

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
    case WM_CHAR: {
        static std::string title;
        title.push_back((char)wParam);
        SetWindowText(hWnd, title.c_str());

    }
        break;
    case WM_LBUTTONDOWN:{
        POINTS pt = MAKEPOINTS(lParam);
        std::ostringstream oss;
        oss << "(" << pt.x << "," << pt.y << ")";
        SetWindowText(hWnd, oss.str().c_str());
        

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
*/