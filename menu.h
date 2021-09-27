#pragma once
#include "file.h"

using namespace std;

class Menu : public File {
	public:
		void running();
		void init_menu();
		void show_menu();
		void add_menu();
		void del_menu();
		void edit_menu();
		void file_menu();
		void show_sort_menu();
		void switch_menu();
		
		void sleep_delay();

	private:
		int menu_num=0;
		string temp;

		enum num_menu {
			show = 1,
			add,
			del,
			edit,
			sorting,
			file,
			end,
			no_more
		};
		
};