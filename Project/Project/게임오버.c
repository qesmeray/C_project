#include<stdio.h>
#include <windows.h>

int over() {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);  // 콘솔 창의 텍스트 색상을 변경

	SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);  // 콘솔 창의 텍스트 속성을 변경

	printf("\n\n\n\n");
	printf("    ########        ###       ###       ###   #########    #########    ###      ###   #########   #########\n");
	printf("   ###    ###     ##   ##     ####      ###   ###         ###     ###   ###      ###   ###         ###    ###\n");
	printf("   ###           ###   ###    ####     ####   ###         ###     ###   ###      ###   ###         ###    ###\n");
	printf("   ###   ####   ###########   ### ## ## ###   #########   ###     ###   ###      ###   #########   ######### \n");
	printf("   ###    ###   ###     ###   ###   #   ###   ###         ###     ###    ###    ###    ###         ###   ###\n");
	printf("   ###    ###   ###     ###   ###       ###   ###         ###     ###     ###  ###     ###         ###    ###\n");
	printf("    ########    ###     ###   ###       ###   #########    #########         ##        #########   ###     ### \n");

}

