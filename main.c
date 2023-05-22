#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menu.h"

int main(void) {
    Menu *p[100];
    int count = 0, menu;
    count = readfile("menu.txt", p) - 1;
    if (count == -1) {
        count += 1;
    }
    while (1) {
        menu = selectMenu();
        if (menu == 0) {
            break;
        }
        if (menu == 1) {
            char input[100];
            printf("원하는 음식점 이름은?");
            getchar();
            fgets(input, 100, stdin);
            if (input[strlen(input) - 1] == '\n') {
                input[strlen(input) - 1] = '\0';
            }
            printRestaurantMenu(input, p, count);


        } else if (menu == 2) {
            int input;
            printf("원하는 요일은?(일요일 0, 월요일 1, 화요일 2, 수요일 3, 목요일 4, 금요일 5, 토요일 6)");
            scanf("%d", &input);
            printDayMenu(input, p, count);
        } else if (menu == 3) {
            int num = 0;
            printf("No. 요일    음식점  가격    메뉴명\n");
            for (int i = 0; i < count; i++) {
                if(p[i]->price > 0){
                    printf("%d %d  %s  %d  %s\n", i + 1, p[i]->day, p[i]->restaurant, p[i]->price, p[i]->foodname);
                }

            }
            printf("\n번호는 (취소 :0)? ");
            scanf("%d", &num);
            if (num != 0) {
                deleteMenu(p[num - 1]);
            }
        } else if (menu == 4) {
            p[count] = (Menu *)malloc(sizeof(Menu));
            add(p[count]);
            count++;
        }
    }
    printf("종료됨!\n");
    return 0;
}
