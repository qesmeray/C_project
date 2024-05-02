#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

#define WIDTH 40
#define HEIGHT 30
#define MAX_FOOD 20  
#define PLAYER_SPEED 1
#define TRUE 1
#define FALSE 0

typedef struct {
    int x;
    int y;
    int act;
    char symbol;
}Poo;

typedef struct {
    int x;
}Player;

Poo poo[WIDTH];
Poo food[MAX_FOOD];
Player player;

int isKeyDown(int key) {
    return ((GetAsyncKeyState(key) & 0x8000) != 0);
}

// 게임 초기화, 게임 규칙 설명
void init() {
    int i;
    for (i = 0; i < WIDTH; i++)
        poo[i].act = FALSE;
    player.x = WIDTH / 2;

    // 게임 규칙 설명
    system("cls");
    printf("\033[0m");      // 글자 색상 변경
    printf("\n\n\n\n\n\n");
    printf("                            < 게임 설명 >\n\n");
    printf("        플레이어를 좌우 화살표로 움직여서 (방향키 ←,→로 조작)\n\n");
    printf("                장애물(o)을 피하고 먹이(w)를 먹으세요!\n\n");
    printf("                    먹이 한 개당 100점이 추가됩니다.\n\n");
    printf("\n\n");
    printf("                게임을 시작하려면 아무 키나 누르세요...");

    // 아무 키나 입력받기
    getchar();
    getchar();
}

void CreatePoo() {
    int i;
    for (i = 0; i < WIDTH; i++) {
        if (!poo[i].act) {
            poo[i].x = rand() % WIDTH;
            poo[i].y = HEIGHT - 1;
            poo[i].act = TRUE;
            return;
        }
    }
}

void CreateFood() {
    int i;
    int count = 0;

    for (i = 0; i < MAX_FOOD; i++) {
        if (!food[i].act && count < 1 && rand() % 20 == 0) { // 20번 중에 한 번씩 'W' 먹이 생성, 그리고 이미 5개가 생성되어 있다면 더 이상 생성하지 않음.
            food[i].x = rand() % (WIDTH);
            food[i].y = HEIGHT - 1;
            food[i].act = TRUE;
            food[i].symbol = 'W'; // "W" 먹이의 모양 지정
            count++;
        }
    }
}

//스코어
int score = 0;
int score2 = 0;
void MovePoo() {
    int i;
    for (i = 0; i < WIDTH; i++) {
        if (poo[i].act) {
            poo[i].y--;
            if (poo[i].y == 0) {
                score++; // 별을 피할 때마다 스코어 증가
            }
            if (food[i].y < 0) {
                food[i].act = FALSE;
            }
        }
    }
}

void MoveFood() {
    int i;
    for (i = 0; i < MAX_FOOD; i++) {
        if (food[i].act) {
            food[i].y--;

            if (food[i].y < 0) {
                food[i].act = FALSE;
            }
        }
    }
}

void DeletePoo() {
    int i;
    for (i = 0; i < WIDTH; i++) {
        if (poo[i].act && poo[i].y < 0) {
            poo[i].act = FALSE;
        }
    }
}

void DeleteFood() {
    int i;
    for (i = 0; i < MAX_FOOD; i++) {
        if (food[i].y < 0) {
            food[i].act = FALSE;
        }
    }
}

// 사용자와 별 충돌 여부 확인 
int PlayerContainsPoo() {
    int i;
    for (i = 0; i < WIDTH; i++) {
        if ((poo[i].act) && (poo[i].y == 0) && (poo[i].x == player.x)) {
            return TRUE;
        }
    }
    return FALSE;
}

// 먹이와 플레이어 충돌 여부 확인
int CheckFoodCollision() {
    int i;
    for (i = 0; i < MAX_FOOD; i++) {
        if (food[i].act && player.x == food[i].x && food[i].y == 0) {
            food[i].act = FALSE;
            return TRUE;
        }
    }
    return FALSE;
}

// 사용자 입력에 따라 플레이어 위치 변경
void MovePlayer() {
    if (isKeyDown(VK_LEFT))
        player.x -= PLAYER_SPEED;
    if (isKeyDown(VK_RIGHT))
        player.x += PLAYER_SPEED;

    if (player.x < 0)
        player.x = 0;
    if (player.x > WIDTH - 1)
        player.x = WIDTH - 1;
}

void PrintMap() {

    system("cls");
    int i;
    for (i = 0; i < WIDTH; i++) {
        if (poo[i].act) {
            gotoxy(poo[i].x, HEIGHT - poo[i].y);
            printf("\033[0mo");
        }
    }
    for (i = 0; i < MAX_FOOD; i++) {
        if (food[i].act) {
            gotoxy(food[i].x, HEIGHT - food[i].y + 1); // 이전 위치에서 삭제
            printf(" "); // 이전 위치를 지움
            gotoxy(food[i].x, HEIGHT - food[i].y); // 새 위치로 이동해서 출력
            printf("\033[31mw");
        }
    }

    gotoxy(player.x, HEIGHT);
    printf("\033[1;36mp");
    gotoxy(0, HEIGHT + 1);
    for (i = 0; i < WIDTH; i++)
        printf("\033[0mT");

    gotoxy(0, HEIGHT + 2);
    printf("\033[0m");
    printf("\n");
    printf("            Score: %d, 먹이 : %d", score, score2);
    printf("\n");
}

void jang() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY | FOREGROUND_INTENSITY);

    system("mode con:cols=70 lines=40");

    char key;
    while (1) {
        score = 0;
        score2 = 0;

        init();
        while (!PlayerContainsPoo()) {
            srand((unsigned int)malloc(NULL));

            CreatePoo();
            CreateFood();
            MovePoo();
            MoveFood();
            DeletePoo();
            DeleteFood();


            if (CheckFoodCollision()) {
                score2++;
            }

            MovePlayer();
            PrintMap();
            Sleep(150);
        }
        system("cls");
        printf("\n\n");
        printf("                                                    score :: %d", score + score2 * 100);
        while (1) {
            // 키보드 입력이 있는지 확인
            if (_kbhit()) {
                _getch();
                over();
                break;
            }
        }
        printf("\n\n");
        printf("                                          다시 실행하시겠습니까? ( Y / N ): ");
        scanf(" %c", &key);
        if (key == 'N') {
            over();
            printf("\n\n\n\n");
            break;
        }
        else if (key != 'Y') {
            printf("\n\n\n\n");
            break;
        }
    }
}
