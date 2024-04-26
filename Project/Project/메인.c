// 헤더 파일들은 각종 표준 라이브러리 함수들과 윈도우즈 API를 사용하기 위해 포함
#include <ctype.h>
#include <stdio.h>
#include <string.h>// 명령문들 모아둔 공간...
#include <stdlib.h>
#include <stdbool.h> 
#include <time.h> // 움직이는 시간
#include <Windows.h> // 색바뀌는


// gotoxy : 콘솔 창에서 특정 좌표로 이동하여 출력 위치를 설정하는 함수
// 매개변수 x, y  구조체 COORD
void gotoxy(int x, int y)  
{
    COORD pos = { x,y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos); // 특정 위치에 텍스트나 그래픽을 출력
}
// 콘솔 화면이 반짝이는 효과를 생성하는 함수
void blinkEffect() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); // 콘솔 출력 핸들을 가져오는 역할
    char c;
    while (1) { // 무한 루프를 사용하여 반짝이는 효과를 계속해서 표시
        // 키보드 입력을 확인 및 키를 누르면 반짝이는 효과를 종료
        if (_kbhit()) {  // 키보드 입력이 있는지 확인
            _getch();   // 키보드 입력을 읽음
            break;
        }
        // 콘솔 텍스트의 색상을 설정 (녹색 + 빨강색)
        SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
        system("cls");  // 콘솔 화면 지우는 명령어

        printf("\n\n\n\n");

        printf("                        ┌─────────────────────────────────────────────────────────────────────────┐\n");
        printf("                        │                                                                         │\n");
        printf("                        │                                                                         │\n");
        printf("                        │                                                                         │\n");
        printf("                        │                 ■■      ■■   ■■  ■■    ■■  ■■               │\n");
        printf("                        │                 ■■■  ■■■   ■■  ■■■  ■■  ■■               │\n");
        printf("                        │                 ■■  ■  ■■   ■■  ■■  ■■■  ■■               │\n");
        printf("                        │                 ■■      ■■   ■■  ■■    ■■  ■■               │\n");
        printf("                        │                 ■■      ■■   ■■  ■■    ■■  ■■               │\n");
        printf("                        │                                                                         │\n");
        printf("                        │          ■■■■■■    ■■■■    ■■      ■■  ■■■■■■       │\n");
        printf("                        │          ■■■■■■  ■■    ■■  ■■      ■■  ■■■■■■       │\n");
        printf("                        │          ■■          ■■ ■ ■■  ■■■  ■■■  ■■               │\n");
        printf("                        │          ■■  ■■■  ■■ ■ ■■  ■■  ■  ■■  ■■■■■■       │\n");
        printf("                        │          ■■    ■■  ■■    ■■  ■■      ■■  ■■               │\n");
        printf("                        │          ■■■■■■  ■■    ■■  ■■      ■■  ■■■■■■       │\n");
        printf("                        │          ■■■■■■  ■■    ■■  ■■      ■■  ■■■■■■       │\n");
        printf("                        │                                                                         │\n");
        printf("                        │                                                                         │\n");
        printf("                        │                                                                         │\n");
        printf("                        └─────────────────────────────────────────────────────────────────────────┘\n");
        //일정 시간 동안 대기하는 함수
        Sleep(300); // 텍스트 출력후 300ms동안 대기
        system("cls");  
        Sleep(300);     // 다음 화면을 재생하기 위해 대기
    }
}

// 게임 메뉴를 표시하는 함수 -> 선택된 값을 반환
int displayMenu() {
    // 사용자의 선택을 저장할 변수를 선언
    int choice; 
    printf("\033[0m"); // ANSI 이스케이프 시퀀스 -> 텍스트 색상을 초기화
    printf("\n\n\n\n\n");  // 공백출력
    printf("                                            ┌───────────────────────┐\n");
    printf("                                            │    1 .   행   맨      │\n");
    printf("                                            └───────────────────────┘\n");
    printf("                                            ┌───────────────────────┐\n");
    printf("                                            │    2 .   오   목      │\n");
    printf("                                            └───────────────────────┘\n");
    printf("                                            ┌───────────────────────┐\n");
    printf("                                            │    3 . 장애물 피하기  │\n");
    printf("                                            └───────────────────────┘\n");
    printf("                                            ┌───────────────────────┐\n");
    printf("                                            │    4 .  스네이크      │\n");
    printf("                                            └───────────────────────┘\n");
    printf("                                            ┌───────────────────────┐\n");
    printf("                                            │    5 .  허들 넘기     │\n");
    printf("                                            └───────────────────────┘\n");
    printf("\n\n");
    printf("                                         원하는 게임을 선택하세요 (1 - 5): ");
    scanf("%d", &choice);

    return choice;  // 사용자가 선택한 값을 반환
}
// 메인함수
int main() {
    // 사용자의 선택을 저장할 변수를 선언
    int choice;

    // 화면 반짝이는 효과를 생성
    blinkEffect();

    // 게임 메뉴를 표시하고 선택을 받음
    system("cls");
    choice = displayMenu();

    // 선택된 게임에 따라서 해당하는 기능을 수행
    switch (choice) {
    case 1:
        system("cls");
        hanghang();
        // 행맨 게임 실행
        break;
    case 2:
        system("cls");
        omok();
        // 오목 게임 실행
        break;
    case 3:
        jang();
        // 장애물 피하기 게임 실행
        break;
    case 4:
        bamm();
        // 스네이크 게임 실행
        break;
    case 5:
        system("cls");
        dino();
        // 점프 게임 실행
        break;

    default:
        printf("잘못된 선택입니다.\n");
        break;

    }
}
