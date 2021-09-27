#pragma once
#include<ctime>
#include<vector>
#include<string>
#include<stdlib.h>
#include<iostream>
#include<algorithm>

using namespace std;

class Todo{
    private:
        string temp, temp2;
        int view_num=0;
        int saved_year=0;
        int days_in_month=0; // 0이면 31일, 1이면 30일, 2면 28/29일
        bool leap_year = 0; // 0이면 28일 1이면 29일

    protected:

        struct Todo_line
        {
            string todo_name;
            struct tm todo_st = { 0 }; // start time
            struct tm todo_et = { 0 }; // end time
            string todo_tag;
            struct tm todo_pt; // present time
        };

        vector<Todo_line> Todo_lines;

    public:

        string set_todo_name();

        int set_todo_year();
        int set_todo_mon();
        int set_todo_day();
        int set_todo_hour();
        int set_todo_min();

        tm set_todo_time();
        void print_todo_time(struct tm temp);
        tm write_edit_time();

        string set_todo_tag();

        void todo_print(Todo_line temp);

        void todo_show();
        void todo_add();
        void todo_del();
        void todo_edit();
        void todo_sort();
        void todo_filter();

        void sort_st();
        void sort_et();
        void sort_pt();

        void test();
};