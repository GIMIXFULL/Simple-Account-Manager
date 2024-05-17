#include <iostream>
#include <string>
#include <map>
#include <variant>
#include "person.h"

using namespace std;

// ���������� ���, ������� ����� ������� �������� ���������� (� ������ ������ person)
using VariableValue = std::variant<person>;

int main() {
    setlocale(LC_ALL, "ru");
    map<string, VariableValue> variables;
    string command;

    while (true)
    {
        cout << "������� ������� (add, print, exit): ";
        cin >> command;

        if (command == "add")
        {
            string name;
            string type;
            cout << "������� ��� ����������: ";
            cin >> name;
            cout << "������� ��� ���������� (person): ";
            cin >> type;

            if (type == "person")
            {
                string valueName;
                string email;
                string password;
                cout << "������� ��� ������������: ";
                cin >> valueName;
                cout << "������� email: ";
                cin >> email;
                cout << "������� ������: ";
                cin >> password;

                // �������� ������������ ��������� ������
                if (email.find('@') == string::npos) {
                    cout << "������������ email." << endl;
                    continue;
                }

                // ������� ������ person � ���������� �������
                person p(valueName);
                p.login(email, password);

                // ��������� ������ � ����� ����������
                variables[name] = p;
            }
            else
            {
                cout << "�������� ��� ����������." << endl;
            }
        }
        else if (command == "print")
        {
            string name;
            cout << "������� ��� ���������� ��� ������: ";
            cin >> name;

            auto it = variables.find(name);
            if (it != variables.end())
            {
                std::visit([](const auto& arg) { cout << arg << endl; }, it->second);
            }
            else {
                cout << "���������� �� �������." << endl;
            }
        }
        else if (command == "exit")
        {
            break; // ����� �� ����� � ���������� ���������
        }
        else
        {
            cout << "����������� �������." << endl;
        }
    }
    return 0;
}
