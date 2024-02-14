#include <windows.h>
#include <string>
#include <iostream>

#define ID_EDIT 1001
#define ID_BUTTON 1002

const std::string PART_ONE = "VSL{";
const std::string MID_PART = "4n_3x4mple_";
const std::string PART_TWO = "}";

std::string check_password(const std::string &password)
{
    std::cout << password << std::endl;
    if (password.length() != 32)
    {
        return "Wrong password length!";
    }

    if (password.substr(0, PART_ONE.length()) != PART_ONE)
    {
        return "Wrong password!";
    }

    if (password.substr(31, 1) != PART_TWO)
    {
        return "Wrong password!";
    }

    if (password.substr(4, MID_PART.length()) != MID_PART)
    {
        return "Wrong password!";
    }

    if (password[21] != 'r' || password[27] != 'a' || password[16] != '4' || password[24] != 'f' || password[17] != 's' || password[18] != '5' || password[28] != 'c' || password[19] != 'w' || password[20] != '0' || password[22] != 'd' || password[30] != '9' || password[15] != 'p' || password[23] != '_' || password[29] != '0' || password[25] != '4' || password[26] != 'k')
    {
        return "Wrong password!";
    }

    return "Correct password!";
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    switch (msg)
    {
    case WM_CREATE:
    {
        HWND hEdit = CreateWindow("EDIT", NULL, WS_VISIBLE | WS_CHILD | WS_BORDER | ES_AUTOHSCROLL,
                                  50, 50, 200, 25, hwnd, (HMENU)ID_EDIT, NULL, NULL);
        SendMessage(hEdit, EM_LIMITTEXT, 100, 0); 
        CreateWindow("BUTTON", "OK", WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
                     100, 100, 100, 30, hwnd, (HMENU)ID_BUTTON, NULL, NULL);
        break;
    }
    case WM_COMMAND:
    {
        if (LOWORD(wParam) == 1002)
        {
            char buffer[256];
            GetWindowText(GetDlgItem(hwnd, 0), buffer, 256);
            std::string password(buffer);
            std::cout << buffer << std::endl;
            MessageBox(NULL, check_password(password).c_str(), "Password Check", MB_OK);
        }
        break;
    }
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hwnd, msg, wParam, lParam);
    }
    return 0;
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    WNDCLASS wc = {0};
    HWND hwnd;
    MSG Msg;

    wc.lpfnWndProc = WndProc;
    wc.hInstance = hInstance;
    wc.lpszClassName = "MyWindowClass";

    RegisterClass(&wc);

    hwnd = CreateWindow("MyWindowClass", "Password Checker", WS_OVERLAPPEDWINDOW,
                        CW_USEDEFAULT, CW_USEDEFAULT, 300, 200, NULL, NULL, hInstance, NULL);

    ShowWindow(hwnd, nCmdShow);
    UpdateWindow(hwnd);

    while (GetMessage(&Msg, NULL, 0, 0) > 0)
    {
        TranslateMessage(&Msg);
        DispatchMessage(&Msg);
    }

    return Msg.wParam;
}
