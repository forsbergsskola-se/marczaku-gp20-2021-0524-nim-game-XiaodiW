#include <iostream>
#include <array>
#include <iterator>
#include <algorithm>

using std::cout; using std::endl;
using std::array; using std::fill;
using std::string;

int Grid[3][3];
array<array<int,2>,9> Index;
string s(5, '*');

void printGrid(bool result){
    int index = 0;
    Index.fill({-1,-1});
    for (int i = 0; i < 3; ++i) {
        string str;
        for (int j = 0; j < 3; ++j) {
            switch (Grid[i][j]) {
                case 0:
                    if(result) str += " ";
                    else {
                        Index[index][0] = i;
                        Index[index][1] = j;
                        index ++;
                        str += std::to_string(index);
                    }
                    break;
                case 1:
                    str += "X";
                    break;
                case 4:
                    str += "O";
                    break;
            }
            str += "|";
        }
        str.pop_back();
        cout << str << endl;
    }
}

int winConditionCheck(){
    int emptyCount = 0;
    for (auto & i : Grid)
        for (int j : i)
            if(j==0) emptyCount ++;
    if(emptyCount == 0) return 3;
    int sum = 0;
    for (auto & i : Grid) {
        for (int j : i)
            sum += j;
        if(sum == 3 || sum == 12) goto end;
        sum = 0;
    }
    sum = 0;
    for (int i = 0; i < 3; ++i) {
        for (auto & j : Grid)
            sum += j[i];
        if(sum == 3 || sum == 12) goto end;
        sum = 0;
    }
    sum = 0;
    sum = Grid[0][0] + Grid[1][1] + Grid[2][2];
    if(sum == 3 || sum == 12) goto end;
    sum = 0;
    sum = Grid[0][2] + Grid[1][1] + Grid[2][0];
    if(sum == 3 || sum == 12) goto end;
    end:
    if(sum == 3) return 1;
    if(sum == 12) return 2;
    return 0;
}

void playerTurn(){
    printGrid(false);
    string options;
    int size = 0;
    for (int i = 0; i < 9; ++i) {
        if (Index[i][0] != -1) {
            size++;
            options += std::to_string(i + 1) + ',';
        }
    }
    options.pop_back();
    cout << "Now, it is Your turn" << endl;
    int chosen;
    choose:
    cout << "Where do you want to place your chess? " << options + '?' << endl;
    std::cin >> chosen;
    if(chosen > size | chosen <1) {
        cout << "Please type in accepted number" << endl;
        goto choose; }
    Grid[Index[chosen-1][0]][Index[chosen-1][1]] = 1;
}

int main() {
    cout << "Hello, World!" << endl;
    while (winConditionCheck() == 0) {
        playerTurn();
        cout << "Result:" << "\n" << s << endl;
        printGrid(true);
        cout << s << endl;
    }
    string str;
    switch (winConditionCheck()) {
        case 3:
            str = "Draw";
            break;
        case 2:
            str = "AI WIN!";
            break;
        case 1:
            str = "You WIN!";
            break;
    }
    cout << "Game Over! " << str << endl;
    return 0;
}
