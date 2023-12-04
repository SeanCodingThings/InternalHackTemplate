#include "main.h"

void HackFunction(HINSTANCE instance)
{
    AllocConsole();
    FILE* fp;
    freopen_s(&fp, "CONOUT$", "w", stdout);

    printf("Console was allocated succesfully!\n");
    while (!GetAsyncKeyState(VK_ESCAPE))
    {
        Sleep(100); // I do not wan't to put to much stress on the CPU!
    }
    FreeConsole();
    // FreeLibray unloads the .dll of the program, ExitThread closes the current thread. (They are two functions combined into one!)
    FreeLibraryAndExitThread(instance, EXIT_SUCCESS);
}

// The reason we are using __stdcall, is because this is the function call that the windows API uses.
bool __stdcall DllMain(HINSTANCE instance, unsigned long reason, void* reserved)
{
    if ( reason == DLL_PROCESS_ATTACH )
    {
        // We are creating an extra thread to be able to write code with out the whole program stopping.
        void* thread = CreateThread
        (
            NULL,
         0,
          (void*)HackFunction,
           instance,
            0,
             NULL
        );
        // Checking if Creating the thread failed, and if it does, we close the thread.
        if (thread == NULL)
        {
            CloseHandle(thread);
        }
    }
    // Returning true on success. (PS: that is how the DllMain function works.)
    return true;
}
