#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

int main() {
    vector<string> array;
    string input;

    while (true) {
        getline(cin, input);
        if (input == ".")
            break;
        array.push_back(input);
    }
    for (int k = 0; k < array.size(); k++) {
        stack<char> balance;
        bool b = true;
        for (int i = 0; i < array[k].size(); i++) {
            if ( array[k][i] == '(' ) balance.push(')');
            else if ( array[k][i] == '[' ) balance.push(']');
            else if ( array[k][i] == ')' || array[k][i] == ']' ) {
                if ( !balance.empty() && array[k][i] == balance.top() ) {
                    balance.pop();
                } else {
                    b = false;
                    break;
                }
            }
        }
        if ( b && balance.empty() ) cout << "yes" << endl;
        else cout << "no" << endl;
    }
}