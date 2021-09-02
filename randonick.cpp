// 2021 yuanie324. All rights reserved.

#include <iostream>
#include <random>
#include <vector>
#include <algorithm>
#include <string>

unsigned int getRandomNumber(void);
std::string generateNick(const int, const int, const int);

int main(int argc, const char **argv) {
    
    // input
    bool flag = false;
    int alphabetLength = 0, numberLength = 0;
    int option;

    while (!flag) {
        std::cout << "Please choose an option(1 to 3)\n\n";
        std::cout << "1 Alphabets + Numbers\n";
        std::cout << "2 Numbers + Alphabets\n";
        std::cout << "3 Alphabets only\n\n";
        std::cout << ">> ";

        std::cin >> option;

        switch (option) {
            case 1:
                std::cout << "Enter the number of alphabets >> ";
                std::cin >> alphabetLength;

                std::cout << "Enter the number of numbers >> ";
                std::cin >> numberLength;

                flag = true;
                break;

            case 2:
                std::cout << "Enter the number of numbers >> ";
                std::cin >> numberLength;

                std::cout << "Enter the number of alphabets >> ";
                std::cin >> alphabetLength;

                flag = true;
                break;

            case 3:
                std::cout << "Enter the number of alphabets >> ";
                std::cin >> alphabetLength;

                flag = true;
                break;

            default:
                std::cout << "\nError: Undefined option.\n\n";
        }
    }

    // generate nickname
    std::string nickname = generateNick(option, alphabetLength, numberLength);
    std::cout << "\nYour nickname is:\n" << nickname << '\n';

    return 0;
}

unsigned int getRandomNumber(void) {
    std::random_device random;
    std::mt19937 engine(random());
    std::uniform_int_distribution<unsigned int> __rand(0, 100000000);

    return (unsigned int)__rand(engine);
}

std::string generateNick(const int opt, const int al, const int nu) {
    std::string ret = "";

    std::vector<char> number;
    std::vector<char> alphabet;

    for (char c = '0'; c <= '9'; c++) number.push_back(c);
    for (char c = 'a'; c <= 'z'; c++) alphabet.push_back(c);

    std::string alpha = "";
    std::string num = "";

    for (int i = 0; i < al; i++) {
        int rand_ = getRandomNumber() % (unsigned int)(alphabet.size());
        alpha.push_back(alphabet[rand_]);
    }

    for (int i = 0; i < nu; i++) {
        int rand_ = getRandomNumber() % (unsigned int)(number.size());
        num.push_back(number[rand_]);
    }

    if (opt == 1) {
        ret = alpha + num;
    } else if (opt == 2) {
        ret = num + alpha;
    } else if (opt == 3) {
        ret = alpha;
    }

    return ret;
}