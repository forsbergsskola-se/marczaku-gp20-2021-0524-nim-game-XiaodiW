#include <iostream>
#include <sstream>
#include <unistd.h>
#include <string>


int playerTurn(int match){
    std::cout << "\n" << "*************************************" << std::endl;
    int number;
    choose:
    std::cout << "Now, it is Your turn" << std::endl;
    std::cout << "There are " << match << " matches left."<< std::endl;
    std::ostringstream oss;
    oss << "It is your turn, How much do you want to take? ";
    for (int i = 1; i < 4; ++i) if (match >= i) oss << i << ",";
    std::string str = oss.str();
    str.pop_back();
    std::cout << str << "? " << std::endl;
    std::cin >> number;
    if(number < 1 || number > 3 || number > match) {
        std::cout << "Please type in accepted number" << std::endl;
        goto choose; }
    std::cout << "You took " << number << " matches. There are "<< match - number <<" left." << std::endl;
    std::cout << "*************************************" << std::endl;
    return match - number;
}

int aiTurn(int match){
    std::cout << "\n" << "*************************************" << std::endl;
    std::cout << "Now, it is AI turn" << std::endl;
    sleep(1);
    std::cout << "AI is thinking....." << std::endl;
    sleep(3);
    int number = (match-1) % 4;
    if(number == 0) number = 1;
    std::cout << "AI took " << number << " matches. There are "<< match - number <<" left." << std::endl;
    std::cout << "*************************************" << std::endl;
    return match - number;
}

int main() {
    int match = 24;
    bool isWin;
    while (true) {
        match = playerTurn(match);
        if(match == 0) {
            isWin = false;
            break;
        }
        match = aiTurn(match);
        if(match == 0) {
            isWin = true;
            break;
        }
    }
    std::cout << "\n" << "*************************************" << std::endl;
    if(isWin) std::cout << "AI took the last match. You WIN! " << std::endl;
    else std::cout << " You took the last match. AI WIN! " << std::endl;
    std::cout << "*************************************" << std::endl;
    return 0;
}
