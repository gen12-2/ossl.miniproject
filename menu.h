// 메뉴 관리: 같은 형식의 txt파일로 주어진 식단 표 읽고 저장
// 		요일 별 메뉴 출력
// 		음식점 별 메뉴 출력
// 		메뉴 삭제
// 		메뉴 추가

#include <stdio.h>
#include <string>

typedef struct {
    char foodname[100];
    int day;//일요일 0, 월요일 1, 화요일 2, 수요일 3, 목요일 4, 금요일 5, 토요일 6
    char restaurant[100];
    int price;
} Menu;

void readfile(char filename[100], Menu *p[]);//파일 읽기

void printRestaurantMenu(char restaurant[100], Menu *p[], int count);//음식점별 메뉴 출력

void printDayMenu(int Day, Menu *p[], int count);//요일별 메뉴 출력

void deleteMenu(Menu *p[], char foodname[100]);//메뉴 삭제

void deleteMenu(char foodname[100]);//메뉴 추가
