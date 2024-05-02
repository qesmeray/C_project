#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

#define clear_X 0
#define clear_Y 6



void lear() {

    system("mode con:cols=100 lines=30");
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    while (1) {
        if (_kbhit()) {
            _getch();
            break;
        }
        system("cls");

        // 프린트되는 모양을 반전시켜 반짝이는 효과를 줌
        gotoxy(clear_X, clear_Y + 1);  printf("                         　　  　  　  ∧___∧        \n");
        gotoxy(clear_X, clear_Y + 2);  printf(" 　                     　            (ㆍωㆍ)  п__ ★  \n");
        gotoxy(clear_X, clear_Y + 3);  printf(" 　                                п  >     ＼/(∃   \n");
        gotoxy(clear_X, clear_Y + 4);  printf(" 　                              (Е)/ /     ＼__/    \n");
        gotoxy(clear_X, clear_Y + 5);  printf("　                                 ＼_/ ＼     )      \n");
        gotoxy(clear_X, clear_Y + 6);  printf("　　                                　　／ y  /       \n");
        gotoxy(clear_X, clear_Y + 7);  printf(" 　                     　            ／ ／ ／        \n");
        gotoxy(clear_X, clear_Y + 8);  printf(" 　                         　        (  ( 〈         \n");
        gotoxy(clear_X, clear_Y + 9);  printf(" 　                     　　           ＼ ＼ ＼       \n");
        gotoxy(clear_X, clear_Y + 10); printf(" 　                     　　           （__(__）      \n");

        SetConsoleTextAttribute(hConsole, 0x0B);
        printf("\n\n\n");
        printf("             ########    ###         #########       ###       #########     ###\n");
        printf("            ###    ###   ###         ###           ##   ##     ###    ###    ###\n");
        printf("            ###          ###         ###          ###   ###    ###    ###    ###\n");
        printf("            ###          ###         #########   ###########   #########     ###\n");
        printf("            ###          ###         ###         ###     ###   ###   ###        \n");
        printf("            ###    ###   ###         ###         ###     ###   ###    ###    ###\n");
        printf("             ########    #########   #########   ###     ###   ###     ###   ###\n");




        Sleep(300);
        system("cls");
        // 프린트되는 모양을 반전시켜 반짝이는 효과를 줌
        gotoxy(clear_X, clear_Y + 1);  printf("                         　　  　  　 ∧___∧         \n");
        gotoxy(clear_X, clear_Y + 2);  printf("                     　    ★  __п  (ㆍω< )         \n");
        gotoxy(clear_X, clear_Y + 3);  printf("                     　         Е)＼/  　  < п      \n");
        gotoxy(clear_X, clear_Y + 4);  printf("                     　           ＼__/     | (Е)    \n");
        gotoxy(clear_X, clear_Y + 5);  printf("                     　              ｒ     ＼_/      \n");
        gotoxy(clear_X, clear_Y + 6);  printf("                     　　      　     ＼  Y ＼        \n");
        gotoxy(clear_X, clear_Y + 7);  printf("                     　　　             ＼ ＼ ＼      \n");
        gotoxy(clear_X, clear_Y + 8);  printf("                     　　　               〉 )  )     \n");
        gotoxy(clear_X, clear_Y + 9);  printf("                     　　　              /  /  /      \n");
        gotoxy(clear_X, clear_Y + 10); printf("                     　　　             （__)__）     \n");



        SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
        printf("\n\n\n");
        printf("             ########    ###         #########       ###       #########     ###\n");
        printf("            ###    ###   ###         ###           ##   ##     ###    ###    ###\n");
        printf("            ###          ###         ###          ###   ###    ###    ###    ###\n");
        printf("            ###          ###         #########   ###########   #########     ###\n");
        printf("            ###          ###         ###         ###     ###   ###   ###        \n");
        printf("            ###    ###   ###         ###         ###     ###   ###    ###    ###\n");
        printf("             ########    #########   #########   ###     ###   ###     ###   ###\n");




        Sleep(300);

    }
}

int clear() {
    lear();
    return 0;
}