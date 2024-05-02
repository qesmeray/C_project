#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

#define clear_X 0
#define clear_Y 0



void over() {
    system("mode con cols=130 lines=50 ");
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    while (1) {
        if (_kbhit()) {
            _getch();
            break;
        }
        system("cls");
        SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
        // 프린트되는 모양을 반전시켜 반짝이는 효과를 줌
        gotoxy(clear_X, clear_Y + 21);  printf("                                  ■■■■■■■■■■■\n");
        gotoxy(clear_X, clear_Y + 22);  printf("                                ■■■■■■■■■■■■■■\n");
        gotoxy(clear_X, clear_Y + 23);  printf("                              ■■■■■■■■■■■■■■■■\n");
        gotoxy(clear_X, clear_Y + 24);  printf("                            ■■■■■■■■■■■■■■■■■■\n");
        gotoxy(clear_X, clear_Y + 25);  printf("                            ■■■■■■■■■■■■■■■■■■■\n");
        gotoxy(clear_X, clear_Y + 26);  printf("                          ■■■■■■■■■■■■■■■■■■■■\n");
        gotoxy(clear_X, clear_Y + 27);  printf("                          ■■                            ■■■■■\n");
        gotoxy(clear_X, clear_Y + 28);  printf("       하아..             ■                                ■■■■\n");
        gotoxy(clear_X, clear_Y + 29);  printf("                          ■  ■■■■          ■■■      ■■■■      애석한 인.간 이로군                \n");
        gotoxy(clear_X, clear_Y + 30);  printf("                          ■        ■■  ■  ■            ■■■■         이런걸 틀리다니             \n");
        gotoxy(clear_X, clear_Y + 31);  printf("                        ■■■          ■                  ■■■■                           \n");
        gotoxy(clear_X, clear_Y + 32);  printf("                      ■■  ■■■■■        ■■■■■■    ■■■\n");
        gotoxy(clear_X, clear_Y + 33);  printf("                    ■■    ■        ■    ■            ■  ■■■\n");
        gotoxy(clear_X, clear_Y + 34);  printf("                    ■    ■■        ■■■■              ■■■■\n");
        gotoxy(clear_X, clear_Y + 35);  printf("                  ■■    ■          ■    ■            ■■  ■■\n");
        gotoxy(clear_X, clear_Y + 36);  printf("                ■■■    ■■■■■■■      ■■■■■■      ■■\n");
        gotoxy(clear_X, clear_Y + 37);  printf("                ■      ■■          ■    ■                  ■■\n");
        gotoxy(clear_X, clear_Y + 38);  printf("              ■■          ■■  ■  ■■■■      ■  ■    ■■                 흠..\n");
        gotoxy(clear_X, clear_Y + 39);  printf("              ■            ■                              ■■\n");
        gotoxy(clear_X, clear_Y + 40);  printf("            ■■      ■■  ■  ■      ■■■■■    ■    ■■■■ \n");
        gotoxy(clear_X, clear_Y + 41);  printf("            ■        ■    ■■        ■■■■■■      ■■■■■■■\n");
        gotoxy(clear_X, clear_Y + 42);  printf("          ■■      ■■■■■■■                    ■■  ■■■■■■■■\n");
        gotoxy(clear_X, clear_Y + 43);  printf("          ■■      ■  ■■■■■■■          ■■■      ■■■■■■    ■\n");
        gotoxy(clear_X, clear_Y + 44);  printf("        ■  ■■■■■■■■■■■    ■■■■■■        ■■■■■■        ■\n");
        gotoxy(clear_X, clear_Y + 45);  printf("      ■            ■  ■■■■■                    ■■■■■■■            ■\n");
        gotoxy(clear_X, clear_Y + 46);  printf("      ■            ■  ■■■■  ■■■■■■■■■■■  ■■■■■             ■\n");
        gotoxy(clear_X, clear_Y + 47);  printf("    ■              ■  ■■■■                          ■■■■■              ■\n");

        SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
        gotoxy(clear_X, clear_Y + 4);
        printf("\n\n\n");
        printf("    ########        ###       ###       ###   #########    #########    ###      ###   #########   #########\n");
        printf("   ###    ###     ##   ##     ####      ###   ###         ###     ###   ###      ###   ###         ###    ###\n");
        printf("   ###           ###   ###    ####     ####   ###         ###     ###   ###      ###   ###         ###    ###\n");
        printf("   ###   ####   ###########   ### ## ## ###   #########   ###     ###   ###      ###   #########   ######### \n");
        printf("   ###    ###   ###     ###   ###   #   ###   ###         ###     ###    ###    ###    ###         ###   ###\n");
        printf("   ###    ###   ###     ###   ###       ###   ###         ###     ###     ###  ###     ###         ###    ###\n");
        printf("    ########    ###     ###   ###       ###   #########    #########         ##        #########   ###     ### \n");




        Sleep(300);
        system("cls");
        SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
        // 프린트되는 모양을 반전시켜 반짝이는 효과를 줌
        gotoxy(clear_X, clear_Y + 21);  printf("                                  ■■■■■■■■■■■\n");
        gotoxy(clear_X, clear_Y + 22);  printf("                                ■■■■■■■■■■■■■■\n");
        gotoxy(clear_X, clear_Y + 23);  printf("                              ■■■■■■■■■■■■■■■■\n");
        gotoxy(clear_X, clear_Y + 24);  printf("                            ■■■■■■■■■■■■■■■■■■\n");
        gotoxy(clear_X, clear_Y + 25);  printf("                            ■■■■■■■■■■■■■■■■■■■\n");
        gotoxy(clear_X, clear_Y + 26);  printf("                          ■■■■■■■■■■■■■■■■■■■■\n");
        gotoxy(clear_X, clear_Y + 27);  printf("                          ■■                            ■■■■■\n");
        gotoxy(clear_X, clear_Y + 28);  printf("                          ■                                ■■■■       이리 쉬운 것을                        \n");
        gotoxy(clear_X, clear_Y + 29);  printf("                          ■  ■■■■          ■■■      ■■■■            못하다니                      \n");
        gotoxy(clear_X, clear_Y + 30);  printf("                        ■■■      ■■  ■  ■            ■■■■            야레야레                   \n");
        gotoxy(clear_X, clear_Y + 31);  printf("                      ■    ■■■■■  ■    ■■■■■■  ■■■■                              \n");
        gotoxy(clear_X, clear_Y + 32);  printf("      후,,          ■      ■        ■    ■            ■  ■■■                             \n");
        gotoxy(clear_X, clear_Y + 33);  printf("                  ■■    ■          ■■■■              ■■■■\n");
        gotoxy(clear_X, clear_Y + 34);  printf("                ■■      ■■        ■    ■            ■■  ■■                  못말리는 아가씨로군♥\n");
        gotoxy(clear_X, clear_Y + 35);  printf("                ■      ■  ■■■■■■      ■■■■■■      ■■\n");
        gotoxy(clear_X, clear_Y + 36);  printf("            ■■      ■■■          ■                        ■■\n");
        gotoxy(clear_X, clear_Y + 37);  printf("            ■            ■          ■    ■                  ■\n");
        gotoxy(clear_X, clear_Y + 38);  printf("          ■        ■■  ■  ■  ■  ■■■■      ■  ■    ■■\n");
        gotoxy(clear_X, clear_Y + 39);  printf("          ■        ■    ■                                ■■\n");
        gotoxy(clear_X, clear_Y + 40);  printf("          ■        ■■■■    ■      ■■■■■    ■    ■■■■\n");
        gotoxy(clear_X, clear_Y + 41);  printf("          ■        ■■■■■                    ■      ■■■■■■■\n");
        gotoxy(clear_X, clear_Y + 42);  printf("          ■■■■■■■■■■■        ■■■■■    ■■  ■■■■■■■■\n");
        gotoxy(clear_X, clear_Y + 43);  printf("        ■          ■  ■■■■■■                ■■    ■■■■■■    ■\n");
        gotoxy(clear_X, clear_Y + 44);  printf("      ■            ■■■■■■■  ■■■■■■■■      ■■■■■■        ■\n");
        gotoxy(clear_X, clear_Y + 45);  printf("      ■            ■  ■■■■■                    ■■■■■■■            ■\n");
        gotoxy(clear_X, clear_Y + 46);  printf("      ■            ■  ■■■■  ■■■■■■■■■■■  ■■■■■             ■\n");
        gotoxy(clear_X, clear_Y + 47);  printf("    ■              ■  ■■■■                          ■■■■■              ■\n");



        SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
        gotoxy(clear_X, clear_Y + 4);
        printf("\n\n\n");
        printf("    ########        ###       ###       ###   #########    #########    ###      ###   #########   #########\n");
        printf("   ###    ###     ##   ##     ####      ###   ###         ###     ###   ###      ###   ###         ###    ###\n");
        printf("   ###           ###   ###    ####     ####   ###         ###     ###   ###      ###   ###         ###    ###\n");
        printf("   ###   ####   ###########   ### ## ## ###   #########   ###     ###   ###      ###   #########   ######### \n");
        printf("   ###    ###   ###     ###   ###   #   ###   ###         ###     ###    ###    ###    ###         ###   ###\n");
        printf("   ###    ###   ###     ###   ###       ###   ###         ###     ###     ###  ###     ###         ###    ###\n");
        printf("    ########    ###     ###   ###       ###   #########    #########         ##        #########   ###     ### \n");



        Sleep(300);

    }
}

