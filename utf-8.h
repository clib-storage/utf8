// Include this file in your project to enable UTF-8 support.
// call enableUTF8() at the beginning of your program to enable UTF-8 support.

#ifndef __UTF_8_H__
#define __UTF_8_H__

#ifdef _WIN32 // (Windows)
    #include <windows.h>
    u_int UTF8_storage;
#elif __linux__ // (Linux)
    #include <locale.h>
    #include <cstring>
    char* UTF8_storage;
#endif


void disableUTF8(){
    #if _WIN32
        SetConsoleOutputCP(UTF8_storage); // (Windows)
    #elif __linux__
        setlocale(LC_ALL, UTF8_storage); //  (Linux)
    #endif
}

void enableUTF8(){
    atexit(disableUTF8);
    #if _WIN32
        UTF8_storage = GetConsoleOutputCP();
        SetConsoleOutputCP(CP_UTF8); // (Windows)
    #elif __linux__
        UTF8_storage = setlocale(LC_ALL, ""); //  (Linux)
    #endif
}


#endif