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
		cout << "���� �޴� �Դϴ�. ������ �Ͻðڽ��ϱ�?" << endl
			<< "1. ���� ����" << endl
			<< "2. ���� �߰�" << endl
			<< "3. ���� ����" << endl
			<< "4. ���� ����" << endl
			<< "5. ���� ����" << endl
			<< "6. ����/�ҷ�����" << endl
			<< "7. ����" << endl
			<< "����� �����Ͻðڽ��ϱ�? : ";
		cin >> menu_num;
		if (menu_num < 1 || menu_num > no_more) {
			system("cls");
			cout << "�߸� ���̽��ϴ�." << endl;
		}
		else break;
	}

	switch_menu();
}

void Menu::show_menu() {
	system("cls");
	cout << "������ �����ϰڽ��ϱ�?" << endl
		<< "1. ��ü����" << endl
		<< "2. �±� ����" << endl;
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
	cout << "5�� �ڿ� ����˴ϴ�," << endl;
	Sleep(5000); //sleep for ms
}
