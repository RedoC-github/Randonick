// 2021 jhhan128. All rights reserved.

#include <iostream>
#include <random>
#include <vector>
#include <algorithm>
#include <string>
#include <limits>

namespace getRandom {
    unsigned int getRandomNumber(void) {
        std::random_device random;
        std::mt19937 engine(random());
        std::uniform_int_distribution<unsigned int> __rand(0, std::numeric_limits<unsigned int>::max());
        return (unsigned int)__rand(engine);
    }

    char getRandomCons(void) {
        std::vector<char> cons;

        for (char c = 'b'; c <= 'z'; c++) {
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') continue;
            else cons.push_back(c);
        }

        std::random_shuffle(cons.begin(), cons.end());
        return cons[getRandomNumber() % (unsigned int)cons.size()];
    }

    char getRandomVowel(void) {
        std::vector<char> vowel = { 'a', 'e', 'i', 'o', 'u', 'y' };
        std::random_shuffle(vowel.begin(), vowel.end());
        return vowel[getRandomNumber() % (unsigned int)vowel.size()];
    }

    char getRandomDigit(void) {
        std::vector<char> dig = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' };
        std::random_shuffle(dig.begin(), dig.end());
        return dig[getRandomNumber() % (unsigned int)dig.size()];
    }
};

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

            case 324:
                std::cout << "\nFor you\n\n";
                return 0;

            default:
                std::cout << "\nError: Undefined option.\n\n";
        }
    }

    // generate nickname
    std::string nickname = generateNick(option, alphabetLength, numberLength);
    std::cout << "\nYour nickname is:\n" << nickname << "\n\n";

    return 0;
}

std::string generateNick(const int opt, const int al, const int nu) {
    std::string ret = "";
    std::string num = "";
    std::string alpha = "";

    const unsigned int firstAlpha = getRandom::getRandomNumber() % 2;

    for (int i = 0; i < al; i++) {
        if (i % 2 == firstAlpha) {
            char nw = getRandom::getRandomCons();
            while (alpha.back() == nw) nw = getRandom::getRandomCons();
            alpha.push_back(nw);
        } else {
            char nw = getRandom::getRandomVowel();
            while (alpha.back() == nw) nw = getRandom::getRandomVowel();
            alpha.push_back(nw);
        }
    }

    for (int i = 0; i < nu; i++) {
        num.push_back(getRandom::getRandomDigit());
    }

    switch (opt) {
        case 1: ret = alpha + num; break;
        case 2: ret = num + alpha; break;
        case 3: ret = alpha; break;
        default: return "Error!"; break;
    }

    return ret;
}