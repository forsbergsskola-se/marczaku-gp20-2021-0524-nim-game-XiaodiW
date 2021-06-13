#include <iostream>
#include <sstream>
#include <unistd.h>
#include <string>
using std::cout; using std::endl;
using std::string; using std::cin;

string printMatches(int matches){
    string s(matches, '|');
    return s;
}

string printBoundary(){
    string s(24, '*');
    return s;
}

int playerTurn(int match){
    cout << "\n" << printBoundary() << endl;
    int number;
    choose:
    cout << "Now, it is Your turn" << endl;
    cout << "There are " << match << " matches left."<< endl;
    cout << printMatches(match) << endl;
    std::ostringstream oss;
    oss << "It is your turn, How much do you want to take? ";
    for (int i = 1; i < 4; ++i) if (match >= i) oss << i << ",";
    string str = oss.str();
    str.pop_back();
    cout << str << "? " << endl;
    cin >> number;
    if(number < 1 || number > 3 || number > match) {
        cout << "Please type in accepted number" << endl;
        goto choose; }
    cout << "You took " << number << " matches. There are "<< match - number <<" left." << endl;
    cout << printMatches(match - number) << endl;
    cout << printBoundary() << endl;
    return match - number;
}

int aiTurn(int match){
    cout << "\n" << printBoundary() << endl;
    cout << "Now, it is AI's turn" << endl;
    cout << "AI is thinking....." << endl;
    sleep(2);
    int number = (match-1) % 4;
    if(number == 0) number = rand() % 3 + 1;
    if(match == 1) number = 1;
    cout << "AI took " << number << " matches. There are "<< match - number <<" left." << endl;
    cout << printMatches(match - number) << endl;
    cout << printBoundary() << endl;
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
    cout << "\n" << printBoundary() << endl;
    if(isWin) cout << "AI took the last match. You WIN! " << endl;
    else cout << " You took the last match. AI WIN! " << endl;
    cout << printBoundary() << endl;
    return 0;
}
