#include "file.h"
#include <iostream>

using namespace std;

void File::todo_file()
{
	system("cls");
	string temp;
	
	while (true) {
		cout << "1. 불러오기" << endl
			<< "2. 저장하기" << endl
			<< "무엇을 하시겠습니까? : ";
		cin >> temp;
		if (stoi(temp) < 0 || stoi(temp) > 2) {
			system("cls");
			cout << "잘못 입력했습니다. " << endl;
		}
		else break;
	}
	
	switch (stoi(temp)) {
	case read:
		File::read_todo();
		break;
	case save:
		File::save_todo();
		break;
	default:
		break;
	}
	return;
}


void File::save_todo()
{
	fout.open("todo.txt");
	for (int i = 0; i < Todo_lines.size(); i++) {
		temp = Todo_lines[i].todo_name + '|' 
			+ to_string(Todo_lines[i].todo_st.tm_year) + "/" + to_string(Todo_lines[i].todo_st.tm_mon) + "/"
			+ to_string(Todo_lines[i].todo_st.tm_mday) + "/" + to_string(Todo_lines[i].todo_st.tm_hour) + "/"
			+ to_string(Todo_lines[i].todo_st.tm_min) + "/|"
			+ to_string(Todo_lines[i].todo_et.tm_year) + "/" + to_string(Todo_lines[i].todo_et.tm_mon) + "/"
			+ to_string(Todo_lines[i].todo_et.tm_mday) + "/" + to_string(Todo_lines[i].todo_et.tm_hour) + "/"
			+ to_string(Todo_lines[i].todo_et.tm_min) + "/|"
			+ Todo_lines[i].todo_tag + '|'
			+ to_string(Todo_lines[i].todo_pt.tm_year) + "/" + to_string(Todo_lines[i].todo_pt.tm_mon) + "/"
			+ to_string(Todo_lines[i].todo_pt.tm_mday) + "/" + to_string(Todo_lines[i].todo_pt.tm_hour) + "/"
			+ to_string(Todo_lines[i].todo_pt.tm_min) + "/|\n";
		fout << temp;
	}
	fout.close();
	cout << "저장되었습니다." << endl;
}


void File::read_todo()
{
	fin.open("todo.txt");
	while (fin)
	{
		getline(fin, temp);
		index = 0;
		while ((pos = temp.find(divider)) != string::npos)
		{
			token = temp.substr(0,pos);
			cout << token << endl;
			spliter(token);
			temp.erase(0, pos + divider.length());
		}
		Todo_lines.push_back(temp_struct);
	}

	cout << "불러왔습니다. " << endl;
	fin.close();
}

void File::spliter(string token)
{
	index++;
	switch (index) // 저장장소
	{
	case 1:
		// 이름
		temp_struct.todo_name = token;
		break;
	case 2:
		// 시작 시간
		temp_struct.todo_st = split_time(token);
		break;
	case 3:
		// 종료시간
		temp_struct.todo_et = split_time(token);
		break;
	case 4:
		// 태그
		temp_struct.todo_tag = token;
		break;
	case 5:
		// 작성시간
		temp_struct.todo_pt = split_time(token);
		break;
	default:
		break;
	}
}

tm File::split_time(string token)
{
	index2 = 0;
	while ((pos2 = token.find(divider_day)) != string::npos) {
		index2++;
		token2 = token.substr(0, pos2);
		switch (index2) {
		case 1:
			temp_struct.todo_st.tm_year = stoi(token2);
			break;
		case 2:
			temp_struct.todo_st.tm_mon = stoi(token2);
			break;
		case 3:
			temp_struct.todo_st.tm_mday = stoi(token2);
			break;
		case 4:
			temp_struct.todo_st.tm_hour = stoi(token2);
			break;
		case 5:
			temp_struct.todo_st.tm_min = stoi(token2);
			break;
		default:
			break;
		}
		token.erase(0, pos2 + divider_day.length());
	}
	return temp_struct.todo_st;
}
