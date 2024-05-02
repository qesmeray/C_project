#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <stdbool.h>
#include <time.h>

#define WIDTH 40
#define HEIGHT 25
#define INITIAL_LENGTH 3        // 뱀 길이
#define DELAY 100       // 뱀 속도
#define MAX_FOOD 10     // 최대 먹이 개수 

enum Direction { UP, DOWN, LEFT, RIGHT };

struct Position {
    int x;
    int y;
};

struct Snake {
    struct Position body[WIDTH * HEIGHT];
    int length;
    enum Direction dir;
};

struct Snake snake;
struct Position food[MAX_FOOD];
bool game_over = false;
int point = 0;      // 먹은 먹이의 개수를 저장할 변수 (score를 나타내는데 장애물피하기랑 변수 이름 충돌되서 바꿈)

void setup() {
    snake.length = INITIAL_LENGTH;
    snake.dir = RIGHT;

    // 뱀 초기 위치 설정
    for (int i = 0; i < snake.length; i++) {
        snake.body[i].x = WIDTH / 2 - i;
        snake.body[i].y = HEIGHT / 2;
    }

    // 음식 초기 위치 설정
    srand(time(NULL));
    for (int i = 0; i < MAX_FOOD; i++) {
        food[i].x = rand() % WIDTH;
        food[i].y = rand() % HEIGHT;
    }
}
// 게임 초기화, 게임 규칙 설명
void iinit() {
    HWND console = GetConsoleWindow();
    RECT rect;
    GetWindowRect(console, &rect);
    MoveWindow(console, rect.left, rect.top, 500, 600, TRUE);

    // 게임 규칙 설명
    system("cls");
    printf("\033[0m");      // 글자 색상 변경
    printf("\n\n\n\n\n\n");
    printf("                      < 게임 설명 >\n\n");
    printf("              뱀을 움직여서 먹이를 먹으세요!\n\n");
    printf("               (방향키 ←,→,↑,↓로 조작)\n\n");
    printf("\n\n");
    printf("          게임을 시작하려면 아무 키나 누르세요...");

    // 아무 키나 입력받기
    getchar();
    getchar();
}


void draw() {
    // 콘솔 커서를 홈 위치로 이동
    COORD coord;
    coord.X = 0;
    coord.Y = 100;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);

    // 게임판 그리기
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            if (i == 0 || i == HEIGHT - 1 || j == 0 || j == WIDTH - 1) {
                printf("\033[1;36m#");
            }
            else {
                bool is_food = false;
                for (int k = 0; k < MAX_FOOD; k++) {
                    if (food[k].x == j && food[k].y == i) {
                        printf("\033[0m*");
                        is_food = true;
                        break;
                    }
                }

                if (!is_food) {
                    bool is_snake = false;
                    for (int k = 0; k < snake.length; k++) {
                        if (snake.body[k].x == j && snake.body[k].y == i) {
                            printf("\033[1;33mO");
                            is_snake = true;
                            break;
                        }
                    }
                    if (!is_snake) {
                        printf(" ");
                    }
                }
            }
        }
        printf("\n");
    }

    // 스코어 출력
    printf("\n");
    printf("                Score: %d", point);
    printf("\n");
}



void input() {
    if (_kbhit()) {
        int key = _getch();
        switch (key) {
        case 'x':
            game_over = true;
            break;
        case 72: // 화살표 위
            if (snake.dir != DOWN) {
                snake.dir = UP;
            }
            break;
        case 80: // 화살표 아래
            if (snake.dir != UP) {
                snake.dir = DOWN;
            }
            break;
        case 75: // 화살표 왼쪽
            if (snake.dir != RIGHT) {
                snake.dir = LEFT;
            }
            break;
        case 77: // 화살표 오른쪽
            if (snake.dir != LEFT) {
                snake.dir = RIGHT;
            }
            break;
        }
    }
}

void move() {
    // 뱀의 꼬리 위치 저장
    struct Position tail = snake.body[snake.length - 1];

    // 뱀의 몸통 이동
    for (int i = snake.length - 1; i > 0; i--) {
        snake.body[i] = snake.body[i - 1];
    }

    // 뱀의 머리 이동
    switch (snake.dir) {
    case UP:
        snake.body[0].y--;
        break;
    case DOWN:
        snake.body[0].y++;
        break;
    case LEFT:
        snake.body[0].x--;
        break;
    case RIGHT:
        snake.body[0].x++;
        break;
    }

    // 벽에 부딪히면 게임 종료
    if (snake.body[0].x <= 0 || snake.body[0].x >= WIDTH - 1 ||
        snake.body[0].y <= 0 || snake.body[0].y >= HEIGHT - 1) {
        game_over = true;
        return;
    }

    // 뱀의 몸에 부딪히면 게임 종료
    for (int i = 1; i < snake.length; i++) {
        if (snake.body[0].x == snake.body[i].x && snake.body[0].y == snake.body[i].y) {
            game_over = true;
            return;
        }
    }

    // 음식 먹으면 길이 증가
    for (int i = 0; i < MAX_FOOD; i++) {
        if (snake.body[0].x == food[i].x && snake.body[0].y == food[i].y) {
            snake.length++;
            snake.body[snake.length - 1] = tail;
            food[i].x = rand() % (WIDTH - 2) + 1;
            food[i].y = rand() % (HEIGHT - 2) + 1;
            point++;
        }
    }
}

int bamm() {

    HWND console = GetConsoleWindow();
    RECT rect;
    GetWindowRect(console, &rect);
    MoveWindow(console, rect.left, rect.top, 500, 600, TRUE);

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY | FOREGROUND_INTENSITY);

    char key;
    while (1) {
        game_over = false;
        point = 0;

        setup();

        iinit();
        while (!game_over) {
            draw();
            input();
            move();
            Sleep(DELAY);
        }

        system("cls");
        printf("\033[0m");
        printf("\n\n                         Score: %d", point);
        while (1) {
            // 키보드 입력이 있는지 확인
            if (_kbhit()) { _getch(); over(); break; }
        }


        printf("\n\n");
        printf("                                          다시 실행하시겠습니까? ( Y / N ): ");
        scanf("%c", &key);

        if (key != 'Y') {
            printf("\n\n\n\n");
            break;
        }
    }
    return 0;
}