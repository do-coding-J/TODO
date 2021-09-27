#include<iostream>
#include<stdlib.h>
#include<Windows.h>
#include "menu.h"

using namespace std;

void Menu::running()
{
	init_menu();
	system("pause");
}

void Menu::init_menu()
{
	system("cls");
	while (true) {
		cout << "메인 메뉴 입니다. 무엇을 하시겠습니까?" << endl
			<< "1. 일정 보기" << endl
			<< "2. 일정 추가" << endl
			<< "3. 일정 삭제" << endl
			<< "4. 일정 편집" << endl
			<< "5. 일정 정렬" << endl
			<< "6. 저장/불러오기" << endl
			<< "7. 종료" << endl
			<< "몇번을 선택하시겠습니까? : ";
		cin >> menu_num;
		if (menu_num < 1 || menu_num > no_more) {
			system("cls");
			cout << "잘못 고르셨습니다." << endl;
		}
		else break;
	}

	switch_menu();
}

void Menu::show_menu() {
	system("cls");
	cout << "무엇을 선택하겠습니까?" << endl
		<< "1. 전체보기" << endl
		<< "2. 태그 필터" << endl;
	cin >> temp;

	switch (stoi(temp))
	{
	case 1:
		Todo::todo_show();
		break;
	case 2:
		Todo::todo_filter();
		break;
	default:
		break;
	}
}


void Menu::add_menu() {
	Menu::todo_add();
}
void Menu::del_menu() {
	Menu::todo_del();
}
void Menu::edit_menu() {
	Menu::todo_edit();
}

void Menu::file_menu()
{
	Menu::todo_file();
}

void Menu::show_sort_menu()
{
	Menu::todo_sort();
}

void Menu::switch_menu() {
	switch (menu_num) {
	case show:
		show_menu();
		break;
	case add:
		add_menu();
		break;
	case del:
		del_menu();
		break;
	case edit:
		edit_menu();
		break;
	case sorting:
		show_sort_menu();
		break;
	case file:
		file_menu();
		break;
	case end:
		//sleep_delay();
		exit(0);
		break;
	default:
		break;
	}
}

void Menu::sleep_delay()
{
	cout << "5초 뒤에 종료됩니다," << endl;
	Sleep(5000); //sleep for ms
}
