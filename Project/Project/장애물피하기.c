#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

#define WIDTH 40
#define HEIGHT 40

#define PLAYER_SPEED 3

typedef struct {
    int x;
    int y;
    int act;
}Poo;

typedef struct {
    int x;
}Player;

Poo poo[WIDTH];
Player player;

int isKeyDown(int key) {
    return ((GetAsyncKeyState(key) & 0x8000) != 0);
}

// 게임 초기화, 게임 규칙 설명
void init() {
    int i;
    for (i = 0; i < WIDTH; i++)
        poo[i].act = FALSE;
    player.x = WIDTH / 1;

    // 게임 규칙 설명
    printf("\033[0m");      // 글자 색상 변경
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    printf("                    게임 설명: 플레이어를 좌우 화살표로 움직여서 o을 피하세요!(방향키 ←,→로 조작)\n\n");
    printf("                                       게임을 시작하려면 아무 키나 누르세요...");
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");

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

//스코어
int score = 0;
void MoveePoo() {
    int i;
    for (i = 0; i < WIDTH; i++) {
        if (poo[i].act) {
            poo[i].y--;
            if (poo[i].y == 0) {
                score++; // 별을 피할 때마다 스코어 증가
            }
        }
    }
}

// 별 이동 함수
void MovePoo() {
    int i;
    for (i = 0; i < WIDTH; i++) {
        if (poo[i].act) {
            poo[i].y--;

            // 별이 맨 위에 도달했을 때 스코어 증가
            if (poo[i].y == 0) {
                score++;
            }

            // 별이 화면 밖으로 벗어나면 비활성화
            if (poo[i].y < 0) {
                poo[i].act = FALSE;
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
            printf("o");
        }
    }
    gotoxy(player.x, HEIGHT);
    printf("¶");
    gotoxy(0, HEIGHT + 1);
    for (i = 0; i < WIDTH - 19; i++)
        printf("▤");

    gotoxy(0, HEIGHT + 2);
    printf("\n");
    printf("                Score: %d", score);
    printf("\n");
}

void jang() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY | FOREGROUND_INTENSITY);

    char key;
    while (1) {
        score = 0;

        init();
        while (!PlayerContainsPoo()) {
            srand((int)malloc(NULL));

            CreatePoo();
            MovePoo();
            DeletePoo();

            MovePlayer();
            PrintMap();
            Sleep(100);
        }
        system("cls");
        over();

        printf("\n\n");
        printf("                                          다시 실행하시겠습니까? ( Y / N ): ");
        scanf(" %c", &key);

        if (key != 'Y') {
            printf("\n\n\n\n");
            break;
        }
    }

}