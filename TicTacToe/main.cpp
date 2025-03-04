#include <iostream>

void mainMenu() {
    system("cls");
    std::cout << "1. Начать игру." << std::endl;
    std::cout << "2. Результаты прошлых игр." << std::endl;
    std::cout << "3. Выход." << std::endl;
    std::cout << " " << std::endl;
    std::cout << "Введите цифру от 1 до 3 для перемещения по меню: " << std::endl;
}

void lastRecordsMenu(int gameCount, int gameWinners[], int firstPlayerWinCount, int secondPlayerWinCount) {
    system("cls");
    int temp;
    if (gameCount != 0) {
        std::cout << "Общий счет побед: " << std::endl;
        std::cout << " " << std::endl;
        if (firstPlayerWinCount > secondPlayerWinCount) {
            std::cout << firstPlayerWinCount << " : " << secondPlayerWinCount << std::endl;
            std::cout << "Игрок 1 впереди." << std::endl;
        } else if (secondPlayerWinCount > firstPlayerWinCount) {
            std::cout << secondPlayerWinCount << " : " << firstPlayerWinCount << std::endl;
            std::cout << "Игрок 2 впереди." << std::endl;
        } else {
            std::cout << secondPlayerWinCount << " : " << firstPlayerWinCount << std::endl;
            std::cout << "Вы идете вровень!" << std::endl;
        }
        std::cout << " " << std::endl;
        for (int i = 1; i <= gameCount; i++) {
            if (gameWinners[i] == 1) {
                std::cout << i << ". Победитель: Игрок 1" << std::endl;
            } else if (gameWinners[i] == 2) {
                std::cout << i << ". Победитель: Игрок 2" << std::endl;
            } else if (gameWinners[i] == 3) {
                std::cout << i << ". Ничья." << std::endl;
            }
        }
        std::cout << " " << std::endl;
        std::cout << "Для выхода в главное меню напишите любую цифру: " << std::endl;
        std::cin >> temp;
    } else {
        std::cout << "Вы еще не сыграли ни одной игры." << std::endl;
        std::cout << " " << std::endl;
        std::cout << "Для выхода в главное меню напишите любую цифру: " << std::endl; 
        std::cin >> temp;
    }
}

void drawBoard(char board[3][3]) {
    std::cout << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << std::endl;
    std::cout << "-- --- --" << std::endl;
    std::cout << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << std::endl;
    std::cout << "-- --- --" << std::endl;
    std::cout << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << std::endl;
}

void emptyBoard(char board[3][3]) {
    char temp[3][3] = {{' ', ' ', ' '}, 
                       {' ', ' ', ' '},
                       {' ', ' ', ' '}};

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = temp[i][j];
        }
    }
}

void playerMove(char board[3][3], int player) {
    bool isValidInput = false;
    int x,y;
    std::cout << "" << std::endl;
    std::cout << "Для хода введите координаты поля в формате X Y (числа могут принимать значения от 1 до 3):" << std::endl;
    while (!isValidInput) {
        std::cin >> x;
        std::cin >> y;
        if (board[x - 1][y - 1] == 'X' || board[x - 1][y - 1] == 'O') {
            std::cout << "Поле занято" << std::endl;
            std::cout << "Повторите попытку ввода координат поля: " << std::endl;
        } else if (x > 3 || x < 1 || y > 3 || y < 1) {
            std::cout << "Введенные координаты выходят за пределы игрового поля" << std::endl;
            std::cout << "Повторите попытку ввода координат поля: " << std::endl;
        } else {
            board[x - 1][y - 1] = (player % 2 == 0) ? 'X' : 'O';
            isValidInput = true;
        }
    }
}

int checkWinCondition(char board[3][3], int player) {
    int winner = 0;
    // Строки X
    if (board[0][0] == 'X' && board[0][1] == 'X' && board[0][2] == 'X') winner = 1;
    if (board[1][0] == 'X' && board[1][1] == 'X' && board[1][2] == 'X') winner = 1;
    if (board[2][0] == 'X' && board[2][1] == 'X' && board[2][2] == 'X') winner = 1;
    // Строки O
    if (board[0][0] == 'O' && board[0][1] == 'O' && board[0][2] == 'O') winner = 2;
    if (board[1][0] == 'O' && board[1][1] == 'O' && board[1][2] == 'O') winner = 2;
    if (board[2][0] == 'O' && board[2][1] == 'O' && board[2][2] == 'O') winner = 2;
    // Столбцы X
    if (board[0][0] == 'X' && board[1][0] == 'X' && board[2][0] == 'X') winner = 1;
    if (board[0][1] == 'X' && board[1][1] == 'X' && board[2][1] == 'X') winner = 1;
    if (board[0][2] == 'X' && board[1][2] == 'X' && board[2][2] == 'X') winner = 1;
    // Столбцы O
    if (board[0][0] == 'O' && board[1][0] == 'O' && board[2][0] == 'O') winner = 2;
    if (board[0][1] == 'O' && board[1][1] == 'O' && board[2][1] == 'O') winner = 2;
    if (board[0][2] == 'O' && board[1][2] == 'O' && board[2][2] == 'O') winner = 2;
    // Диагонали X
    if (board[0][0] == 'X' && board[1][1] == 'X' && board[2][2] == 'X') winner = 1;
    if (board[2][0] == 'X' && board[1][1] == 'X' && board[0][2] == 'X') winner = 1;
    // Диагонали O
    if (board[0][0] == 'O' && board[1][1] == 'O' && board[2][2] == 'O') winner = 2;
    if (board[2][0] == 'O' && board[1][1] == 'O' && board[0][2] == 'O') winner = 2;
    if (player == 9 && winner == 0) {
        winner = 3;
    }
    return winner;
}

void playGame(char board[3][3], int gameWinners[], int gameCount, int &firstPlayerWinCount, int &secondPlayerWinCount) {
    system("cls");
    int player = 0;
    int retry;
    int winner;
    bool isGameRunning = true;
    while (isGameRunning) {
        drawBoard(board);
        playerMove(board, player++);
        std::cout << " " << std::endl;
        winner = checkWinCondition(board, player);
        switch(winner) {
            case 3:
                gameWinners[gameCount] = 3;
                std::cout << "Ничья!" << std::endl;
                std::cout << "Сыграть еще? (1 - да, 2 - нет): " << std::endl;
                break;
            case 1:
                gameWinners[gameCount] = 1;
                firstPlayerWinCount++;
                std::cout << "Победил 1 игрок!" << std::endl;
                std::cout << "Сыграть еще? (1 - да, 2 - нет): " << std::endl;
                break;
            case 2:
                gameWinners[gameCount] = 2;
                secondPlayerWinCount++;
                std::cout << "Победил 2 игрок!" << std::endl;
                std::cout << "Сыграть еще? (1 - да, 2 - нет): " << std::endl;
                break;
        }
        if (winner != 0) {
            std::cin >> retry;
            if (retry == 1) {
                emptyBoard(board);
                player = 0;
                system("cls");    
            } else if (retry == 2) {
                isGameRunning = false;
                emptyBoard(board);
                player = 0;
                system("cls");    
            }
        }
    }
}
int main(void) {
    int gameWinners[256];
    char board[3][3];
    int menuOption;
    int gameCount = 0;
    int firstPlayerWinCount = 0;
    int secondPlayerWinCount = 0;
    bool isAppRunning = true;
    emptyBoard(board);  
    system("cls");
    while (isAppRunning) {
        mainMenu();
        std::cin >> menuOption;
        switch (menuOption) {
        case 1:
            gameCount++;
            playGame(board, gameWinners, gameCount, firstPlayerWinCount, secondPlayerWinCount);
            break;
        case 2:
            lastRecordsMenu(gameCount, gameWinners, firstPlayerWinCount, secondPlayerWinCount);
            break;
        case 3:
            system("cls");
            isAppRunning = false;
            break;
        }
    }
    return 0;
}
