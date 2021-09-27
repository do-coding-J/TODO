#include <algorithm>
#include"todo.h"
#pragma warning(disable : 4996)

using namespace std;

string Todo::set_todo_name() 
{
    cin.ignore();
    cout << "������ �Է��ϼ��� : ";
    getline(cin, temp);
    //cout << temp << endl;
    return temp;
}
int Todo::set_todo_year() 
{
    while (true)
    {
        cout << "�⵵�� �Է��ϼ���(YYYY) : ";
        cin >> temp;
        if (stoi(temp) > 9999 || stoi(temp) < 1000) 
        {
            system("cls");
            cout << "�߸��Է��߽��ϴ�. �ٽ��Է����ּ���" << endl;
        }
        else break;
    }

    saved_year = stoi(temp)+1900;
   // cout << stoi(temp) << endl;
    return saved_year;
}
int Todo::set_todo_mon() 
{
    while (true)
    {
        cout << "���� �Է��ϼ���(MM) : ";
        cin >> temp;
        if (stoi(temp) > 12 || stoi(temp) < 0)
        {
            system("cls");
            cout << "�߸��Է��߽��ϴ�. �ٽ��Է����ּ���" << endl;
        }
        else break;
    }

    if (stoi(temp) == 2) {
        days_in_month = 2;
        if (saved_year % 4 == 0) {
            if (saved_year % 100 == 0) {
                if (saved_year % 400 == 0) {
                    leap_year = 1;
                }
                else leap_year = 0;
            }
            else leap_year = 1;
        }
        else leap_year = 0;
    }
    else if (stoi(temp) == 4 || stoi(temp) == 6 || stoi(temp) == 9 || stoi(temp) == 11) days_in_month = 1;
    else days_in_month = 0;

    //cout << leap_year << "\t" << days_in_month << endl;
   // cout << stoi(temp) << endl;

    return stoi(temp)+1;
}
int Todo::set_todo_day()
{ 
    while (true) {
        cout << "���� �Է��ϼ���(DD) : ";
        cin >> temp;
        if (days_in_month == 0) {
            if (stoi(temp) > 31 || stoi(temp) < 0) {
                system("cls");
                cout << "�߸��Է��߽��ϴ�. �ٽ��Է����ּ���" << endl;
            }
            else break;
        }
        else if (days_in_month == 1) {
            if (stoi(temp) > 30 || stoi(temp) < 0) {
                system("cls");
                cout << "�߸��Է��߽��ϴ�. �ٽ��Է����ּ���" << endl;
            }
            else break;
        }
        else if (days_in_month == 2) {
            if (leap_year) {
                if (stoi(temp) > 29 || stoi(temp) < 0) {
                    system("cls");
                    cout << "�߸��Է��߽��ϴ�. �ٽ��Է����ּ���" << endl;
                }
                else break;
            }
            else {
                if (stoi(temp) > 28 || stoi(temp) < 0) {
                    system("cls");
                    cout << "�߸��Է��߽��ϴ�. �ٽ��Է����ּ���" << endl;
                }
                else break;
            }
        }
    }
    //cout << stoi(temp) << endl;
    return stoi(temp);
}
int Todo::set_todo_hour()
{
    while (true) {
        cout << "�ð��� �Է��ϼ��� (24h) : ";
        cin >> temp;
        if (stoi(temp) > 24 || stoi(temp) < 0)
        {
            system("cls");
            cout << "�߸��Է��߽��ϴ�. �ٽ��Է����ּ���" << endl;
        }
        else break;
    }
    //cout << stoi(temp) << endl;
    return stoi(temp);
}
int Todo::set_todo_min()
{
    while (true) {
        cout << "���� �Է��ϼ��� (mm) : ";
        cin >> temp;
        if (stoi(temp) > 60 || stoi(temp) < 0)
        {
            system("cls");
            cout << "�߸��Է��߽��ϴ�. �ٽ��Է����ּ���" << endl;
        }
        else break;
    }
    //cout << stoi(temp) << endl;
    return stoi(temp);
}



struct tm Todo::set_todo_time() 
{
    struct tm temp1 = { 0 };
    temp1.tm_year = set_todo_year()-1900;
    temp1.tm_mon = set_todo_mon()-1;
    temp1.tm_mday = set_todo_day();
    temp1.tm_hour = set_todo_hour();
    temp1.tm_min = set_todo_min();

    return temp1;
}

void Todo::print_todo_time(tm temp)
{
    cout << temp.tm_year << "/" << temp.tm_mon << "/"
        << temp.tm_mday << " " << temp.tm_hour << ":"
        << temp.tm_min;
}

tm Todo::write_edit_time()
{
    struct tm* temp;
    time_t timer = time(NULL);
    temp = localtime(&timer);
    temp->tm_year += 1900;
    temp->tm_mon += 1;

    return *temp;
}


string Todo::set_todo_tag()
{
    cin.ignore();
    cout << "�±׸� �Է��ϼ��� : ";
    getline(cin, temp);
    return temp;
}

void Todo::todo_print(Todo_line temp)
{
    cout << "����     : " << temp.todo_name << endl;
    cout << "���۽ð� : "; print_todo_time(temp.todo_st); cout << endl;
    cout << "����ð� : "; print_todo_time(temp.todo_et); cout << endl;
    cout << "�±�     : " << temp.todo_tag << endl;
    cout << "�ۼ��ð� : "; print_todo_time(temp.todo_pt); cout << endl;
}



void Todo::todo_show()
{
    system("cls");
    if (Todo_lines.size() == 0) cout << "������ �����ϴ�." << endl;
    else 
    {
        cout << "�����Դϴ�." << endl;
        size_t size = Todo_lines.size();
        for (int i = 0; i < size; i++)
        {
            cout << i + 1 << "��." << endl;
            todo_print(Todo_lines[i]);
        }
        cout << "\n �̻��Դϴ�" << endl;
    }
}

void Todo::todo_add()
{
    Todo_line line;
    system("cls");
    cout << "������ �߰��մϴ�." << endl;
    line.todo_name = set_todo_name();
    system("cls");
    cout << "���۽ð��� �Է��մϴ�." << endl;
    line.todo_st = set_todo_time();
    system("cls");
    cout << "����ð��� �Է��մϴ�." << endl;
    line.todo_et = set_todo_time();
    system("cls");
    cout << "���� �±׸� �Է��մϴ�." << endl;
    line.todo_tag = set_todo_tag();

    line.todo_pt = write_edit_time();

    Todo_lines.push_back(line);
}

void Todo::todo_del()
{
    if (Todo_lines.size() == 0) {
        todo_show();
    }
    else {
        todo_show();
        cout << "������ �׸��� �����ϼ���. : ";
        cin >> temp;
        Todo_lines.erase(Todo_lines.begin() + stoi(temp) - 1);
    }
}

void Todo::todo_edit()
{
    if (Todo_lines.size() == 0) {
        todo_show();
    }
    else {
        todo_show();
        cout << "������ �׸��� �����ϼ���. : ";
        cin >> temp;
        view_num = stoi(temp)-1;
        cout << "1. ����     : " << Todo_lines[view_num].todo_name << endl;
        cout << "2. ���۽ð� : "; print_todo_time(Todo_lines[view_num].todo_st); cout << endl;
        cout << "3. ����ð� : "; print_todo_time(Todo_lines[view_num].todo_et); cout << endl;
        cout << "4. �����±� : " << Todo_lines[view_num].todo_tag << endl;

        cout << "������ �׸��� �����ϼ���. : ";
        cin >> temp;
        switch (stoi(temp)) {
        case 1:
            cout << "����        : " << Todo_lines[view_num].todo_name << endl;
            cout << "->  ����    : ";
            cin.ignore();
            getline(cin, temp2);
            Todo_lines[view_num].todo_name = temp2;
            break;
        case 2:
            cout << "���۽ð�    : "; print_todo_time(Todo_lines[view_num].todo_st); cout << endl;
            cout << "-> ���۽ð� : ";
            Todo_lines[view_num].todo_st = set_todo_time();
            break;
        case 3:
            cout << "����ð�    : "; print_todo_time(Todo_lines[view_num].todo_et); cout << endl;
            cout << "-> ����ð� : ";
            Todo_lines[view_num].todo_et = set_todo_time();
            break;
        case 4:
            cout << "�±�        : " << Todo_lines[view_num].todo_tag << endl;
            cout << "->  �±�    : "; 
            cin.ignore();
            getline(cin, temp2);
            Todo_lines[view_num].todo_tag = temp2;
            break;
        default:
            break;
        }
        Todo_lines[view_num].todo_pt = write_edit_time();
    }
}

void Todo::todo_sort()
{
    system("cls");
    while (true) {
        cout << "�������� �����Ͻðڽ��ϱ�? " << endl
            << "1. ���۽ð�" << endl
            << "2. ����ð�" << endl
            << "3. �ۼ�/���� �ð�" << endl;
        cin >> temp;
        if (stoi(temp) < 1 || stoi(temp) > 3) {
            system("cls");
            cout << "�߸� �Է��߽��ϴ�. �ٽ� �Է����ּ���" << endl;
        }
        else break;
    }
    switch (stoi(temp))
    {
    case 1:
        sort_st();
        break;
    case 2:
        sort_et();
        break;
    case 3:
        sort_pt();
        break;
    default:
        break;
    }
}

void Todo::todo_filter()
{
    int count = 1;
    vector<string> temp1;
    for (int i = 0; i < Todo_lines.size(); i++) {
        temp1.push_back(Todo_lines[i].todo_tag);
    }
    sort(temp1.begin(), temp1.end());
    temp1.erase(unique(temp1.begin(), temp1.end()), temp1.end());

    cout << "�±� ��� �Դϴ�. ���͸� �� ��ȣ�� ���� �ϼ���." << endl;
    for (int i = 0; i < temp1.size(); i++) {
        cout << i + 1 << ". " << temp1[i] << endl;
    }

    cin >> temp;

    for (int i = 0; i < Todo_lines.size(); i++) {
        int a = stoi(temp) - 1;
        if (Todo_lines[i].todo_tag == temp1[a]) {
            cout << count << "��." << endl; count++;
            todo_print(Todo_lines[i]);
        }
    }
    cout << "�̻��Դϴ�. " << endl;
}



void Todo::sort_st()
{
    sort(Todo_lines.begin(), Todo_lines.end(), [](Todo_line i1, Todo_line i2){
        //������ ������
        if (i1.todo_st.tm_year == i2.todo_st.tm_year) {
            if (i1.todo_st.tm_mon == i2.todo_st.tm_mon) {
                if (i1.todo_st.tm_mday == i2.todo_st.tm_mday) {
                    if (i1.todo_st.tm_hour == i2.todo_st.tm_hour) {
                        return i1.todo_st.tm_min < i2.todo_st.tm_min;
                    }
                    else return i1.todo_st.tm_hour < i2.todo_st.tm_hour;
                }
                else return i1.todo_st.tm_mday < i2.todo_st.tm_mday;
            }
            else return i1.todo_st.tm_mon < i2.todo_st.tm_mon;
        }
        else return i1.todo_st.tm_year < i2.todo_st.tm_year;
        });
    cout << "���ĵǾ����ϴ�." << endl;
}

void Todo::sort_et()
{
    sort(Todo_lines.begin(), Todo_lines.end(), [](Todo_line i1, Todo_line i2) {
        //������ ������
        if (i1.todo_et.tm_year == i2.todo_et.tm_year) {
            if (i1.todo_et.tm_mon == i2.todo_et.tm_mon) {
                if (i1.todo_et.tm_mday == i2.todo_et.tm_mday) {
                    if (i1.todo_et.tm_hour == i2.todo_et.tm_hour) {
                        return i1.todo_et.tm_min < i2.todo_et.tm_min;
                    }
                    else return i1.todo_et.tm_hour < i2.todo_et.tm_hour;
                }
                else return i1.todo_et.tm_mday < i2.todo_et.tm_mday;
            }
            else return i1.todo_et.tm_mon < i2.todo_et.tm_mon;
        }
        else return i1.todo_et.tm_year < i2.todo_et.tm_year;
        });
    cout << "���ĵǾ����ϴ�." << endl;
}

void Todo::sort_pt()
{
    sort(Todo_lines.begin(), Todo_lines.end(), [](Todo_line i1, Todo_line i2) {
        //������ ������
        if (i1.todo_pt.tm_year == i2.todo_pt.tm_year) {
            if (i1.todo_pt.tm_mon == i2.todo_pt.tm_mon) {
                if (i1.todo_pt.tm_mday == i2.todo_pt.tm_mday) {
                    if (i1.todo_pt.tm_hour == i2.todo_pt.tm_hour) {
                        return i1.todo_pt.tm_min < i2.todo_pt.tm_min;
                    }
                    else return i1.todo_pt.tm_hour < i2.todo_pt.tm_hour;
                }
                else return i1.todo_pt.tm_mday < i2.todo_pt.tm_mday;
            }
            else return i1.todo_pt.tm_mon < i2.todo_pt.tm_mon;
        }
        else return i1.todo_pt.tm_year < i2.todo_pt.tm_year;
        });
    cout << "���ĵǾ����ϴ�." << endl;
}

void Todo::test()
{
    Todo_line line;
    system("cls");
    cout << "������ �߰��մϴ�." << endl;
    line.todo_name = "���� �̸�";
    system("cls");
    cout << "���۽ð��� �Է��մϴ�." << endl;
    struct tm* temp;
    time_t timer = time(NULL);
    temp = localtime(&timer);
    temp->tm_year += 1900;
    temp->tm_mon += 1;
    line.todo_st = *temp;
    system("cls");
    cout << "����ð��� �Է��մϴ�." << endl;
    temp = localtime(&timer);
    temp->tm_year += 1900;
    temp->tm_mon += 1;
    line.todo_et = *temp;
    system("cls");
    cout << "���� �±׸� �Է��մϴ�." << endl;
    line.todo_tag = "�±� �̸�";
    temp = localtime(&timer);
    temp->tm_year += 1900;
    temp->tm_mon += 1;
    line.todo_pt = *temp;
    
    Todo_lines.push_back(line);

    todo_show();

    system("pause");
}

