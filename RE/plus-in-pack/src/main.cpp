#include <windows.h>
#include <iostream>
#include <string>

bool checkPassword(std::string input)
{
    if (input.length() != 32)
    {
        return false;
    }

    std::string part_one = "VSL{";
    std::string part_two = "}";
    std::string mid_part = "4n_3x4mple_";

    if (input.substr(0, 4) != part_one)
    {
        return false;
    }

    if (input.substr(31, 1) != part_two)
    {
        return false;
    }

    if (input.substr(4, 11) != mid_part)
    {
        return false;
    }

    if (input[21] != 'r' || input[27] != 'a' || input[16] != '4' || input[24] != 'f' || input[17] != 's' || input[18] != '5' || input[28] != 'c' || input[19] != 'w' || input[20] != '0' || input[22] != 'd' || input[30] != '9' || input[15] != 'p' || input[23] != '_' || input[29] != '0' || input[25] != '4' || input[26] != 'k')
    {
        return false;
    }

    return true;
}

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg)
    {
    case WM_COMMAND:
        switch (LOWORD(wParam))
        {
        case 1:
        {
            int length = GetWindowTextLength(GetDlgItem(hwnd, 2)) + 1;
            char *buffer = new char[length];
            GetDlgItemText(hwnd, 2, buffer, length);

            if (checkPassword(buffer))
            {
                MessageBox(hwnd, "Correct", "Result", MB_OK | MB_ICONINFORMATION);
            }
            else
            {
                MessageBox(hwnd, "Wrong", "Result", MB_OK | MB_ICONERROR);
            }

            delete[] buffer;
            break;
        }
        }
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;
    default:
        return DefWindowProc(hwnd, uMsg, wParam, lParam);
    }
    return 0;
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    HWND hwnd;
    WNDCLASSEX wc;
    ZeroMemory(&wc, sizeof(WNDCLASSEX));
    wc.cbSize = sizeof(WNDCLASSEX);
    wc.lpfnWndProc = WindowProc;
    wc.hInstance = hInstance;
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wc.lpszClassName = "WindowClass";
    RegisterClassEx(&wc);
    hwnd = CreateWindowEx(0, "WindowClass", "Password Machine", WS_OVERLAPPEDWINDOW, 100, 100, 400, 200, NULL, NULL, hInstance, NULL);

    CreateWindow("BUTTON", "Check", WS_VISIBLE | WS_CHILD, 150, 100, 80, 25, hwnd, (HMENU)1, NULL, NULL);
    CreateWindowEx(WS_EX_CLIENTEDGE, "EDIT", "", WS_VISIBLE | WS_CHILD | ES_AUTOHSCROLL, 100, 50, 200, 25, hwnd, (HMENU)2, NULL, NULL);

    ShowWindow(hwnd, nCmdShow);

    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return msg.wParam;
}
