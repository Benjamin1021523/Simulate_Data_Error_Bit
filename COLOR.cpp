#include<windows.h>
void SetColor(int f=7){
    unsigned short ForeColor = f;
    HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hCon,ForeColor);
}

//No input will back to default.
