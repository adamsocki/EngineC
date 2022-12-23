#include <windows.h>
#include <windowsx.h>

#include "types.h"

struct WindowsPlatform {
    HWND *window;
    int32 screenHeight;
    int32 screenWidth;

    WSADATA wsaData;
};


WindowsPlatform *Platform = NULL;

bool PlatformRunning = true;

LRESULT CALLBACK MainWindowCallback(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
    LRESULT result = 0;

    switch(msg) {
        case WM_SIZE: {
        } break;

        case WM_DESTROY: {
            PlatformRunning = false;
        } break;

        case WM_CLOSE: {
            PlatformRunning = false;
        } break;

        case WM_QUIT: {
            PlatformRunning = false;
        } break;

        case WM_ACTIVATEAPP: {
        } break;

        // the default case means that if none of the other cases happened, we fall thru
        // to this one "Calls the default window procedure to provide default processing
        // for any window messages that an application does not process. This function
        // ensures that every message is processed"
        default: {
            result = DefWindowProc(hwnd, msg, wParam, lParam);
        } break;
    }


    return result;
}

int CALLBACK WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmndLine, int nCndShow) 
{
    return 0;
}