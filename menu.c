#include "menu.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int readfile(char filename[100], Menu *p[]){
    int count = 0;
    FILE*file = fopen(filename, "r");
    while(!feof(file)){
        p[count] = (Menu *)malloc(sizeof(Menu));
        fscanf(file, "%d %d %s", &p[count]->day, &p[count]->price, p[count]->foodname);
        if(p[count]->foodname[strlen(p[count]->foodname) - 1] == '\n'){
        p[count]->foodname[strlen(p[count]->foodname) - 1] = '\0';
    }
        fgets(p[count]->restaurant, 100, file);
        if(p[count]->restaurant[strlen(p[count]->restaurant) - 1] == '\n'){
        p[count]->restaurant[strlen(p[count]->restaurant) - 1] = '\0';
    }
        count++;
    
    }
    return count;
    }



void printRestaurantMenu(char input[100], Menu *p[], int count) {
    printf("이번주 %s의 메뉴는\n", input);
    for (int i = 0; i < count; i++) {
        if (strstr(p[i]->restaurant, input) != NULL) {
            if(p[i]->price > 0){
                printf("%s %d %d\n", p[i]->foodname, p[i]->day, p[i]->price);
            }
        }
    }
}


void printDayMenu(int day, Menu *p[], int count){
    if(day == 0){
        printf("일요일 메뉴는\n");
    }
    else if(day == 1){
        printf("월요일 메뉴는\n");
    }
    else if(day == 2){
        printf("화요일 메뉴는\n");
    }
    else if(day == 3){
        printf("수요일 메뉴는\n");
    }
    else if(day == 4){
        printf("목요일 메뉴는\n");
    }
    else if(day == 5){
        printf("금요일 메뉴는\n");
    }
    else if(day == 6){
        printf("토요일 메뉴는\n");
    }

    for(int i = 0; i < count; i++){
        if(day == p[i]->day){
            if(p[i]->price > 0){
                printf("%s  %s  \n", p[i]->restaurant, p[i]->foodname);
            }
        }
    }
}


void deleteMenu(Menu *p){
    int r = 0;
    printf("정말로 삭제하시겠습니까?(삭제 :1)");
    scanf("%d", &r);
    if(r == 1){
        p->price = -1;
        printf("=> 삭제됨!\n");
    }
}


void add(Menu *p){
    printf("음식점 이름은?");
    getchar();
    fgets(p->restaurant, 100, stdin);
    if(p->restaurant[strlen(p->restaurant) - 1] == '\n'){
        p->restaurant[strlen(p->restaurant) - 1] = '\0';
    }
    printf("메뉴 이름은?");
    fgets(p->foodname, 100, stdin);
    if(p->foodname[strlen(p->foodname) - 1] == '\n'){
        p->foodname[strlen(p->foodname) - 1] = '\0';
    }
    printf("요일은?");
    scanf("%d", &p->day);

    printf("가격은?");
    scanf("%d", &p->price);

    printf("=> 추가되었습니다");
}

int selectMenu(){
    int input;
    printf("1 음식점별 메뉴 출력\n");
    printf("2 요일별 메뉴 출력\n");
    printf("3 메뉴 삭제\n");
    printf("4 메뉴 추가\n");
    printf("0 종료\n");
    scanf("%d", &input);
    return input;
}