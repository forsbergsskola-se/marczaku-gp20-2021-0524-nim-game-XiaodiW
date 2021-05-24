#include <iostream>
#include <sstream>



int playerTurn(int match){
    int number;
    choose:
    std::cout << "There are " << match << " matches left."<< std::endl;
    std::ostringstream oss;
    oss << "It is your turn, How much do you want to take?";
    for (int i = 1; i < 4; ++i) if (match > i) oss << i << ",";
    oss << "?";
    std::string str = oss.str();
    std::cout << str << std::endl;
    std::cin >> number;
    if(number < 1 || number > 3) {
        std::cout << "Please type in accepted number" << std::endl;
        goto choose; }
    std::cout << "Player took " << number << " matches. There are "<< match <<" left." << std::endl;
    return match - number;
}


int main() {
    int match = 24;
    match = playerTurn(match);
    std::cout << match << std::endl;
    return 0;
}
