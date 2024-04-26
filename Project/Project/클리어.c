#include <stdio.h>
#include <Windows.h>

void clear() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);   // 콘솔 창의 텍스트 색상을 변경
    SetConsoleTextAttribute(hConsole, 0x0B); // 연한 청록 색상으로 변경

    printf("\n\n\n\n");
    printf("             ########    ###         #########       ###       #########     ###\n");
    printf("            ###    ###   ###         ###           ##   ##     ###    ###    ###\n");
    printf("            ###          ###         ###          ###   ###    ###    ###    ###\n");
    printf("            ###          ###         #########   ###########   #########     ###\n");
    printf("            ###          ###         ###         ###     ###   ###   ###        \n");
    printf("            ###    ###   ###         ###         ###     ###   ###    ###    ###\n");
    printf("             ########    #########   #########   ###     ###   ###     ###   ###\n");

  
}
