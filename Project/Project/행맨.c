#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TRIES 6  // 최대 시도 횟수
#define MAX_WORD_LEN 20  // 최대 단어 길이

// 단어 목록
char* words[] = { "hello" };  // 문자열 포인터 배열
int num_words = 1; // 하나의 단어만 포함되어 있음을 의미

// 행맨 그림 출력 
void printHangman(int tries);  // tries : 사용자가 현재까지 틀린 횟수

int hanghang() {  // 정수를 반환하는 형태 -> 행맨 게임의 진행을 담당
    printf("\033[0m");      // 글자 색상 변경
    // srand  : 함수를 호출하여 시드(seed)를 설정
    srand(time(NULL)); // 무작위 수를 생성하기 위해 사용 -> 현재 시간을 기반으로 시드를 설정

    char guess[MAX_WORD_LEN];  // 사용자가 추측한 단어
    char word[MAX_WORD_LEN];  // 게임에서 선택된 단어
    int wordIndex, wordLen, i; // 단어 목록에서 선택된 단어의 인덱스, 선택된 단어의 길이
    int tries = 0;  // 용자의 실패 횟수
    int found;  // 입력한 글자가 단어에 존재 여부
    char letter;  // 입력한 글자
    char guessedLetters[MAX_WORD_LEN] = "";  // 이미 시도한 글자

    // 단어 랜덤 선택
    wordIndex = rand() % num_words; // rand() : 랜덤하게 단어를 선택
    strcpy(word, words[wordIndex]); // strcpy 함수를 사용하여 선택된 단어를 word에 복사, wordIndex 에 저장
    wordLen = strlen(word); // 선택된 단어의 길이를 계산

    // guess 배열을 초기화
    for (i = 0; i < wordLen; i++) // wordLen 변수에 저장된 단어의 길이만큼 반복하면서 
        guess[i] = '_'; // guess 배열의 각 요소를 언더스코어(_)로 초기화
    guess[wordLen] = '\0'; // 널 종료문자 -> 문자열의 끝

    printf("\n\n행맨을 시작합니다.\n");

    while (tries < MAX_TRIES) {
        printf("\n입력할 스펠링 개수: %s\n", guess);  // guess 배열에 저장된 글자표시
        printf("입력할 스펠링: \n");   
        scanf(" %c", &letter);

        if (strchr(guessedLetters, letter) != NULL) {  // // 이미 시도한 글자 입력한 경우 guessedLetters 배열에서 확인
            printf("이미 시도한 글자입니다. 다른 글자를 입력해주세요.\n");
            continue;
        }
        guessedLetters[strlen(guessedLetters)] = letter; // 사용자가 입력한 글자를 guessedLetters 배열에 추가
        guessedLetters[strlen(guessedLetters)] = '\0'; // 널 종료문자로 배열의 끝을 인식

        found = 0;  // 변수를 0으로 초기화 -> 입력한 글자가 단어에 포함 여부 확인위해
        for (i = 0; i < wordLen; i++) {
            if (word[i] == letter) { // 입력글자와 단어 일치여부 확인
                guess[i] = letter;  // 일치한다면 guess배열에 글자저장
                found = 1; // 올바른 추측 True
            }
        }

        if (!found) {  // 입력글자가 포함되지않은 경우 
            tries++; // 틀린 횟수 증가
            system("cls");
            //최대 시도 횟수에서 현재 시도 횟수를 뺀 값을 출력
            printf("\n\n틀렸습니다! 남은 입력 기회 : %d\n", MAX_TRIES - tries);  
            // 현재 시도 횟수에 따라 행맨 그림을 출력
            printHangman(tries);
        }
        else {
            system("cls");
            printf("\n\n맞았습니다!\n");
            // 현재 시도 횟수에 따라 행맨 그림을 출력
            printHangman(tries);
        }

        // 모든 글자를 맞춘 경우
        if (strcmp(word, guess) == 0) {  // strcmp 함수를 사용하여 word와 guess를 비교
            system("cls");
            printf("\n\n\n축하합니다! 완성된 단어: %s\n", word);
            clear();
            break;
        }
    }

    // 시도 가능한 횟수를 모두 사용한 경우
    if (tries == MAX_TRIES) { // 현재 시도한 횟수 = 최대 시도 횟수인지 확인
        system("cls");
        printf("\n\n단어는 %s 였습니다.\n", word);
        // 현재 시도 횟수에 따라 행맨 그림을 출력
        printHangman(tries);
        over();
    }

    
}

void printHangman(int tries) {
    switch (tries) {  // 시도횟수를 기준으로 나뉨
    // 시도 횟수에 따라 그림 출력
    case 0:
        printf("      ______\n");
        printf("     |      |\n");
        printf("            |\n");
        printf("            |\n");
        printf("            |\n");
        printf("            |\n");
        printf("            |\n");
        printf("            |\n");
        printf("            |\n");
        printf("            |\n");
        printf("            |\n");
        printf("            |\n");
        break;
    case 1:
        printf("      ______\n");
        printf("     |      |\n");
        printf("   /\\_/\\    |\n");
        printf("  ( o.o )   |\n");
        printf("   >   <    |\n");
        printf("            |\n");
        printf("            |\n");
        printf("            |\n");
        printf("            |\n");
        printf("            |\n");
        printf("            |\n");
        printf("            |\n");
        break;
    case 2:
        printf("      ______\n");
        printf("     |      |\n");
        printf("   /\\_/\\    |\n");
        printf("  ( o.o )   |\n");
        printf("   >   <    |\n");
        printf(" /          |\n");
        printf("/_/         |\n");
        printf("            |\n");
        printf("            |\n");
        printf("            |\n");
        printf("            |\n");
        printf("            |\n");
        break;
    case 3:
        printf("      ______\n");
        printf("     |      |\n");
        printf("   /\\_/\\    |\n");
        printf("  ( o.o )   |\n");
        printf("   >   <    |\n");
        printf(" /          |\n");
        printf("/_/|   |    |\n");
        printf("   |   |    |\n");
        printf("            |\n");
        printf("            |\n");
        printf("            |\n");
        printf("            |\n");
        break;
    case 4:
        printf("      ______\n");
        printf("     |      |\n");
        printf("   /\\_/\\    |\n");
        printf("  ( o.o )   |\n");
        printf("   >   <    |\n");
        printf(" /       \\  |\n");
        printf("/_/|   |\\_\\\ |\n");
        printf("   |   |    |\n");
        printf("            |\n");
        printf("            |\n");
        printf("            |\n");
        printf("            |\n");
        break;
    case 5:
        printf("      ______\n");
        printf("     |      |\n");
        printf("   /\\_/\\    |\n");
        printf("  ( o.o )   |\n");
        printf("   >   <    |\n");
        printf(" /       \\  |\n");
        printf("/_/|   |\\_\\\ |\n");
        printf("   |   |    |\n");
        printf("  / __      |\n");
        printf(" /_/        |\n");
        printf("            |\n");
        printf("            |\n");
        break;
    case 6:
        printf("      ______\n");
        printf("     |      |\n");
        printf("   /\\_/\\    |\n");
        printf("  ( o.o )   |\n");
        printf("   >   <    |\n");
        printf(" /       \\  |\n");
        printf("/_/|   |\\_\\\ |\n");
        printf("   |   |    |\n");
        printf("  / ___ \\   |\n");
        printf(" /_/   \\_\\  |\n");
        printf("            |\n");
        printf("            |\n");
        break;
    default:  // case에 해당하지 않는 경우
        printf("\n");
        break;
    }
}