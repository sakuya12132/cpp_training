#include <iostream>
#include <windows.h>
#include <vector>
#include <cstdint>

// 窗口全局变量
const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;

// 我们的内存帧缓冲（模拟显存）
std::vector<uint32_t> frameBuffer(SCREEN_WIDTH* SCREEN_HEIGHT, 0x0000FF);

// 窗口过程回调函数
LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
    switch (msg) {
    case WM_PAINT: {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hwnd, &ps);

        // 配置位图信息头
        BITMAPINFO bmi = {};
        bmi.bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
        bmi.bmiHeader.biWidth = SCREEN_WIDTH;
        bmi.bmiHeader.biHeight = -SCREEN_HEIGHT; // 注意：负数表示原点在上，Y轴向下
        bmi.bmiHeader.biPlanes = 1;
        bmi.bmiHeader.biBitCount = 32;
        bmi.bmiHeader.biCompression = BI_RGB;

        // 核心：将内存中的帧缓冲一次性刷到屏幕上
        StretchDIBits(hdc,
            0, 0, SCREEN_WIDTH, SCREEN_HEIGHT,       // 目标矩形
            0, 0, SCREEN_WIDTH, SCREEN_HEIGHT,       // 源矩形
            frameBuffer.data(), &bmi,                // 像素数据与位图信息
            DIB_RGB_COLORS, SRCCOPY);

        EndPaint(hwnd, &ps);
        break;
    }
    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;
    }
    return DefWindowProc(hwnd, msg, wParam, lParam);
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE, LPSTR, int nCmdShow) {
    // 1. 注册窗口类
    WNDCLASSEX wc = { sizeof(WNDCLASSEX), CS_HREDRAW | CS_VREDRAW, WndProc,
                      0, 0, hInstance, NULL, NULL, (HBRUSH)(COLOR_WINDOW + 1),
                      NULL, L"SoftRasterizerClass", NULL };
    RegisterClassEx(&wc);

    // 2. 创建窗口
    HWND hwnd = CreateWindowEx(0, L"SoftRasterizerClass", L"My Software Rasterizer",
        WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT,
        SCREEN_WIDTH, SCREEN_HEIGHT, NULL, NULL, hInstance, NULL);
    ShowWindow(hwnd, nCmdShow);
    UpdateWindow(hwnd);

    // 3. 消息循环（这里可以插入你的渲染循环逻辑）
    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
     
    return (int)msg.wParam;
}