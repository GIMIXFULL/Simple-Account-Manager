#pragma once
#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <string>

class person
{
private:
    std::string name;

    class Register
    {
    public:
        std::string email;
        std::string password;

        Register() {}
        Register(std::string email, std::string password)
        {
            this->email = email;
            this->password = password;
        }
    };

    Register Account;

public:
    person() {}
    person(std::string name)
    {
        this->name = name;
    }
    void login(std::string email, std::string password)
    {
        Account = Register(email, password);
    }
    void print() const
    {
        std::cout << "Your account\n\n" << "User name: " << name << std::endl
            << "Login: " << Account.email << std::endl
            << "Password: " << Account.password << std::endl;
    }
    std::string getInfo() const
    {
        return "Name: " + name + ", Email: " + Account.email + ", Password: " + Account.password;
    }
};

// Перегрузка оператора << для вывода данных об объекте person
std::ostream& operator<<(std::ostream& stream, const person& p);

#endif // PERSON_H