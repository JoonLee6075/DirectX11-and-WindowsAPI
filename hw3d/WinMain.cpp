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
*/