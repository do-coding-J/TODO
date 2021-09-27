#pragma once
#include <fstream>
#include "todo.h"

class File : public Todo{
	private:
		size_t pos = 0, pos2 = 0;
		int index=0, index2=0;
		string temp;
		string  token, token2, divider = "|", divider_day = "/", divider_time = ":";
		string st_date, et_date, pt_date;

		struct Todo::Todo_line temp_struct;

		ofstream fout;
		ifstream fin;

		enum num_file
		{
			read = 1,
			save
		};

	public:

		void todo_file();
		void save_todo();
		void read_todo();

		void spliter(string token);
		struct tm split_time(string token);
		
	protected:

};