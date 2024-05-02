#include <stdio.h>
#include <stdbool.h>
#include <Windows.h>



#define BOARD_SIZE 9



// 오목판 배열 초기화
void initializeBoard(char board[BOARD_SIZE][BOARD_SIZE]) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = '.';
        }
    }
}



// 오목판 출력
void printBoard(char board[BOARD_SIZE][BOARD_SIZE]) {
    printf("\033[0m");
    printf("     ");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("  %2d", i);
    }
    printf("\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("  %2d", i);
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("  %2c", board[i][j]);
        }
        printf(" \n\n");
    }
}



// 승리 여부 확인 :: 5개가 나열 되었는가?   (참/거짓
bool checkWin(char board[BOARD_SIZE][BOARD_SIZE], int row, int col, char player) {
    int count = 1; // 현재 돌의 수
    int r, c; // 임시 변수




    // 1. 가로 방향 확인
    r = row;
    c = col - 1;
    while (c >= 0 && board[r][c] == player) { count++; c--; }
    c = col + 1;
    while (c < BOARD_SIZE && board[r][c] == player) { count++; c++; }

    if (count >= 5) return true;




    // 2.세로 방향 확인
    count = 1;
    r = row - 1;
    c = col;
    while (r >= 0 && board[r][c] == player) { count++; r--; }
    r = row + 1;

    while (r < BOARD_SIZE && board[r][c] == player) { count++; r++; }
    if (count >= 5) return true;




    // 3_1.대각선 방향 확인 (왼쪽 위에서 오른쪽 아래)
    count = 1;
    r = row - 1;
    c = col - 1;
    while (r >= 0 && c >= 0 && board[r][c] == player) { count++; r--; c--; }

    r = row + 1;
    c = col + 1;
    while (r < BOARD_SIZE && c < BOARD_SIZE && board[r][c] == player) { count++; r++; c++; }

    if (count >= 5) return true;


    // 3_2.대각선 방향 확인 (오른쪽 위에서 왼쪽 아래)
    count = 1;
    r = row - 1;
    c = col + 1;
    while (r >= 0 && c < BOARD_SIZE && board[r][c] == player) { count++; r--; c++; }

    r = row + 1;
    c = col - 1;
    while (r < BOARD_SIZE && c >= 0 && board[r][c] == player) { count++; r++; c--; }


    if (count >= 5) return true;


    return false;
}

int omok() {
    printf("\033[0m");
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);


    char board[BOARD_SIZE][BOARD_SIZE];
    int row, col;    // 사용자가 입력할 행과 열의 위치값
    char currentPlayer = 'X'; // 현재 플레이어, X부터 시작

    initializeBoard(board);
    printf("\033[0m");
    printf("\n\n승부를 시작하겠습니다!\n\n");
    printf("첫번째 사람은 X 두번째 사람은 O이 됩니다.\n\n");
    printf("5개를 연속으로 먼저 잇는 사람이 승리합니다.(세로,가로,대각선 전부 가능합니다.) \n\n");

    while (true) {
        printBoard(board);


        printf("\n참가자 '%c'의 차례입니다. \n\n", currentPlayer);
        printf("행과 열 번호(0~%d)를 공백으로 구분하여 입력하세요.: ", BOARD_SIZE - 1);

        scanf("%d %d", &row, &col);
        getchar();  // scanf 함수 형식 지정자에 맞지않는 단어들을 앞 함수를 호풀하여 개행문자를 제거해줌,


        system("cls");  // 화면 지우기


        if (row < 0 || row >= BOARD_SIZE || col < 0 || col >= BOARD_SIZE || board[row][col] != '.') {
            printf("잘못된 행동입니다. 다시 실행해 주세요.\n");
            continue;
        }

        board[row][col] = currentPlayer;  // 사용자가 선택한 위치(row,col)에 currentPlayer(플레이어 X/0) 값을 할당하는것. 

        if (checkWin(board, row, col, currentPlayer)) {
            printBoard(board);
            printf("\n\n            참가자 '%c'의 승리!\n\n", currentPlayer);
            break;
        }


        // 플레이어를 교체합니다.
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';


    }

    printf("            즐겨주셔서 감사합니다.\n");
    while (1) {
        // 키보드 입력이 있는지 확인
        if (_kbhit()) { _getch();  clear(); break; }
    }
    clear();


    return 0;
}