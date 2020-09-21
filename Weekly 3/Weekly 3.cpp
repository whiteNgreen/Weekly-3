// Weekly 3     Adrian Roos Stræte

#include <iostream>
#include <ctime>
#include <random>
#include <vector>

namespace MyRandom {
    std::mt19937 mersenne{ static_cast<std::mt19937::result_type>(std::time(nullptr)) };
}

int counter = 0;
int place;
int highScore[5];
bool gamePlay[5];

int getRN(int min, int max) {
    min = 1;
    std::uniform_int_distribution <> die{ min, max };
    return die(MyRandom::mersenne);
}

void guessLvl1();
void guessLvl2();
void guessLvl3(int num);

void highScoreText(int num);

int main()
{
    bool exit = false;
        
    do {
        int taskChoice;


        std::cout << "Which task would you like to see?\n";
        std::cout << "1. Guess against a set constant ";
        if (gamePlay[0] == true) {
            std::cout << '\t' << "HighScore: " << highScore[0];
        }
        std::cout << '\n';
        
        std::cout << "2. Guess against a user set constant \n";

        std::cout << "3. Guess against a random number \n";
        std::cout << "4. Exit" << std::endl;
        
        std::cin >> taskChoice;

        if (taskChoice == 1) {
            guessLvl1();
            std::cout << std::endl;
        }
        if (taskChoice == 2) {
            guessLvl2();
            std::cout << std::endl;
        }
        if (taskChoice == 3) {
            int num = 0;
            int opt;
            
            std::cout << "Chose a difficulty\n";
            std::cout << "1. 1 - 5";
            if (gamePlay[2] == true) {
                std::cout << '\t' << "HighScore: " << highScore[2];
            }
            std::cout << '\n';
            std::cout << "2. 1 - 10";
            if (gamePlay[3] == true) {
                std::cout << '\t' << "HighScore: " << highScore[3];
            }
            std::cout << '\n';
            std::cout << "3. 1 - 30";
            if (gamePlay[4] == true) {
                std::cout << '\t' << "HighScore: " << highScore[4];
            }
            std::cout << '\n';
            std::cout << "4. 1 - Custom\n";
            std::cin >> opt;
            std::cout << std::endl;

            switch (opt)
            {
            case 1:
                num = 5;
                place = 2;
                break;
            case 2:
                num = 10;
                place = 3;
                break;
            case 3:
                num = 30;
                place = 4;
                break;
            case 4:
                std::cout << "Write a new number to guess between " << std::endl;
                std::cin >> num;
                
            default:
                break;
            }
            std::cout << "You have chosen 1 - " << num << std::endl;
            guessLvl3(num);
            if (opt != 4) { highScoreText(place); }
            
            
        }
        if (taskChoice == 4) {
            exit = true;
        }
    } while(exit == false);

    return 0;
}

void guessLvl1() {
    int com = 3;
    int ans;

    std::cout << "What number am i thinking of?" << std::endl;
    std::cin >> ans;

    while (ans != com) {
        if (ans > com) {
            counter++;
            std::cout << "Thats too high. " << std::endl;
            std::cin >> ans;
        }
        if (ans < com) {
            counter++;
            std::cout << "Too low. " << std::endl;
            std::cin >> ans;
        }
    }
    if (ans == com) {
        counter++;
        std::cout << "CORRECT. " << std::endl;
        std::cout << "You did it in " << counter << " tries" << std::endl;
    }
    highScoreText(0);
}

void guessLvl2() {
    int com;
    int ans;
    int counter = 0;

    std::cout << "Write a number to guess: " << std::endl;
    std::cin >> com;
    system("cls");      // Yuck?


    std::cout << "Now please guess the number: " << std::endl;
    std::cin >> ans;

    while (ans != com) {
        if (ans > com) {
            counter++;
            std::cout << "Thats too HIGH. " << std::endl;
            std::cin >> ans;
        }
        if (ans < com) {
            counter++;
            std::cout << "Too Low. " << std::endl;
            std::cin >> ans;
        }


    }
    if (ans == com) {
        counter++;
        std::cout << "CORRECT! " << std::endl;
        std::cout << "You did it in " << counter << " tries." << std::endl;
        return;
    }
}

void guessLvl3(int max) {
    int ans;
    int r = getRN(1, max);
    
    std::cin >> ans;

    while (ans != r) {
        if (ans < r) {
            std::cout << "Low" << std::endl;
            std::cin >> ans;
            counter++;
        }
        if (ans > r) {
            std::cout << "High" << std::endl;
            std::cin >> ans;
            counter++;
        }
    }
    if (ans == r) {
        counter++;
        std::cout << "CORRECT!\n" << std::endl;
    }
}

void highScoreText(int num) {
    
    if (gamePlay[num] == false) {
        highScore[num] = counter;
        std::cout << "First time score: " << highScore[num] << '\n' << '\n';
        gamePlay[num] = true;
    }
    else if (gamePlay[num] == true) {
        if (counter < highScore[num]) {
            highScore[num] = counter;
            std::cout << "New high score: " << highScore[num] << '\n' << '\n';

        }
        if (counter > highScore[num]) {
            std::cout << "Current high score: " << highScore[num] << '\n' << '\n';
        }
    }
    
    std::cout << "You used " << counter << " tries to get the right answer.\n\n";

    counter = 0;
}



