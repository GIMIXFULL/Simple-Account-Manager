#include <iostream>
#include <string>
#include <map>
#include <variant>
#include "person.h"

using namespace std;

// Определяем тип, который будет хранить значение переменной (в данном случае person)
using VariableValue = std::variant<person>;

int main() {
    setlocale(LC_ALL, "ru");
    map<string, VariableValue> variables;
    string command;

    while (true)
    {
        cout << "Введите команду (add, print, exit): ";
        cin >> command;

        if (command == "add")
        {
            string name;
            string type;
            cout << "Введите имя переменной: ";
            cin >> name;
            cout << "Введите тип переменной (person): ";
            cin >> type;

            if (type == "person")
            {
                string valueName;
                string email;
                string password;
                cout << "Введите имя пользователя: ";
                cin >> valueName;
                cout << "Введите email: ";
                cin >> email;
                cout << "Введите пароль: ";
                cin >> password;

                // Проверка корректности введенных данных
                if (email.find('@') == string::npos) {
                    cout << "Некорректный email." << endl;
                    continue;
                }

                // Создаем объект person с введенными данными
                person p(valueName);
                p.login(email, password);

                // Сохраняем объект в карту переменных
                variables[name] = p;
            }
            else
            {
                cout << "Неверный тип переменной." << endl;
            }
        }
        else if (command == "print")
        {
            string name;
            cout << "Введите имя переменной для печати: ";
            cin >> name;

            auto it = variables.find(name);
            if (it != variables.end())
            {
                std::visit([](const auto& arg) { cout << arg << endl; }, it->second);
            }
            else {
                cout << "Переменная не найдена." << endl;
            }
        }
        else if (command == "exit")
        {
            break; // Выход из цикла и завершение программы
        }
        else
        {
            cout << "Неизвестная команда." << endl;
        }
    }
    return 0;
}
