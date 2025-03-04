#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>

/*
    Система управления библиотекой.
    Создайте систему для управления книгами в библиотеке. 
    Эта система должна позволить пользователям добавлять, 
    удалять и искать книги, а также управлять учетными записями пользователей.
*/

class User {
    public:
        std::string login;
        std::string password;
        std::string username;
        bool changeUsername() {return 0;};
        void changePassword() {};
        void deleteAccount() {}; 
        bool operator<(const User& other) const { // Хрень для сравнения элементов множеств. Не работает
            return login < other.login;
        }
};

class Book {
    public:
        std::string title;
        std::string author;
        int price;
        bool isAvailable;
};

// Набор процедур для входа в систему

void authMenu() {
    std::cout << "1. Войти." << std::endl;
    std::cout << "2. Зарегистрироваться." << std::endl;
    std::cout << " " << std::endl;
    std::cout << "Для выбора меню введите цифру 1 или 2: " << std::endl;
}

void mainMenu() {
    std::cout << "1. Поиск книги" << std::endl;
}

bool signIn(std::set<User>& userDB) {
    std::string login;
    std::string password;
    std::cout << "Введите логин: " << std::endl;
    std::cin >> login;

    // Проверка на наличие пользователя в БД

    auto isLoginExist = std::find_if(userDB.begin(), userDB.end(), [&login](const User& user) {
        return user.login == login;
    });

    if (isLoginExist == userDB.end()) {
        std::cout << "Данного пользователя не существует" << std::endl;
        std::cin >> login;
        return false;
    }

    std::cout << "Введите пароль: " << std::endl;
    std::cin >> password;

    // Проверка на совпадение пароля у юзера по логину

    for (auto& user : userDB) {
        if (isLoginExist->password == password) {
            std::cout << "Вы успешно вошли!" << std::endl;
            return true;
        } else if (user.password != password) {
            std::cout << "Пароль был введен неверно!" << std::endl;
            return false;
        }
    }
    std::cout << "Ошибка авторизации" << std::endl;
    return false;
}

bool signUp(std::set<User> userDB) {
    std::string login;
    std::string password;
    std::cout << "Введите логин: " << std::endl;
    std::cin >> login;

    // Проверка на наличие данного логина в БД юзеров
    for (const auto& user : userDB) {
        if (user.login == login) {
            std::cout << "Логин занят!" << std::endl;
            return false;
        }
    }

    std::cout << "Придумайте пароль: " << std::endl;
    std::cin >> password;
    User newUser;
    newUser.login = login;
    newUser.password = password;
    userDB.insert(newUser);
    std::cout << "Вы успешно зарегистрировались!" << std::endl;
    std::cout << "Для выхода в главное меню введите любую цифру: " << std::endl;
    std::cin >> login;
    return true;
}

int main(void) {
    std::set<Book> bookDB; 
    std::set<User> userDB;
    bool isAppRunning = true;
    int input;
    while (isAppRunning) {
        system("cls");
        authMenu();
        std::cin >> input;
        switch(input) {
            case 1:
                system("cls");
                signIn(userDB);
                break;
            case 2:
                system("cls");
                signUp(userDB);
                break;
            case 3: 
                system("cls");
                isAppRunning = false;
        }
    }
    return 0;
}
