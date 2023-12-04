#include "main.h"

void HackFunction(HINSTANCE instance)
{
    AllocConsole();
    FILE* fp;
    freopen_s(&fp, "CONOUT$", "w", stdout);

    printf("Console was allocated succesfully!\n");
    while (!GetAsyncKeyState(VK_ESCAPE))
    {
        Sleep(100);
    }
    FreeConsole();
    FreeLibraryAndExitThread(instance, EXIT_SUCCESS);
}

bool __stdcall DllMain(HINSTANCE instance, unsigned long reason, void* reserved)
{
    if ( reason == DLL_PROCESS_ATTACH )
    {
        void* thread = CreateThread
        (
            NULL,
         0,
          (void*)HackFunction,
           instance,
            0,
             NULL
        );
        if (thread == NULL)
        {
            CloseHandle(thread);
        }
    }
    return true;
}
