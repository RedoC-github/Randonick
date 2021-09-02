#include <iostream>
#include <random>
#include <vector>
#include <algorithm>
#include <string>

int main(int argc, const char **argv) {

    // 난수 생성 with mt19937

    std::mt19937 mt;
    mt.seed((unsigned int)time(0));
    
    // 입력

    start:

    std::cout << "옵션을 선택하세요(1~3 숫자 입력)\n\n";
    std::cout << "1 알파벳 + 숫자\n";
    std::cout << "2 숫자 + 알파벳\n";
    std::cout << "3 알파벳 only\n\n";
    std::cout << ">> ";

    int option;
    std::cin >> option;

    int alphabetLength = 0, numberLength = 0;

    switch (option) {
        case 1:
            std::cout << "알파벳 길이를 입력하세요 >> ";
            std::cin >> alphabetLength;

            std::cout << "숫자 길이를 입력하세요 >> ";
            std::cin >> numberLength;
            break;

        case 2:
            std::cout << "숫자 길이를 입력하세요 >> ";
            std::cin >> numberLength;

            std::cout << "알파벳 길이를 입력하세요 >> ";
            std::cin >> alphabetLength;
            break;

        case 3:
            std::cout << "알파벳 길이를 입력하세요 >> ";
            std::cin >> alphabetLength;
            break;

        default:
            std::cout << "\n잘못된 옵션입니다.\n\n";
            goto start;
    }

    // 닉네임 생성

    std::vector<char> number;
    std::vector<char> alphabet;

    for (char c = 'a'; c <= 'z'; c++) {
        alphabet.push_back(c);
    }

    for (char c = '0'; c <= '9'; c++) {
        number.push_back(c);
    }

    std::string num = "";
    std::string alpha = "";

    for (int i = 0; i < numberLength; i++) {
        int rand_ = mt() % (unsigned int)number.size();
        num.push_back(number[rand_]);
    }

    for (int i = 0; i < alphabetLength; i++) {
        int rand_ = mt() % (unsigned int)alphabet.size();
        alpha.push_back(alphabet[rand_]);
    }

    std::string result;

    if (option == 1) {
        result = alpha + num;
    } else if (option == 2) {
        result = num + alpha;
    } else {
        result = alpha;
    }

    std::cout << '\n' << result << '\n';

    return 0;
}
