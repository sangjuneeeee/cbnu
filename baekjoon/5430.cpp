#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int num;
    int arraySize;
    cin >> num;

    while (num--) {
        deque<int> arr; 
        string cmd;
        string numArray;
        bool err = false;
        bool rev = false;

        cin >> cmd;
        cin >> arraySize;
        cin >> numArray;

        string tmpNum = "";
        for (int k = 0; k < numArray.length(); k++) {
            if ( isdigit(numArray[k]) ) {
                tmpNum += numArray[k];
            } else {
                if (!tmpNum.empty()) {
                    arr.push_back(stoi(tmpNum));
                    tmpNum = "";
                }
            }
        }
        
        for (int j = 0; j < cmd.length(); j++) {
            if ( cmd[j] == 'R' ) {
                rev = !rev;
            } else {
                if (arr.empty()) {
                    err = true;
                    break;
                }
                if ( cmd[j] == 'D' && rev == false ) {
                    arr.pop_front();
                } else {
                    arr.pop_back();
                }
            }
        }

        if ( !err && rev == false ) {
            cout << '[';
            for (int n = 0; n < arr.size(); n++) {
                cout << arr[n];
                if ( n < arr.size()-1 ) {
                    cout << ',';
                }
            }
            cout << ']' << '\n';
        } else if( !err && rev == true ) {
            cout << '[';
            for (int n = arr.size() - 1; n >= 0; n--) {
                cout << arr[n];
                if ( n > 0 ) {
                    cout << ',';
                }
            }
            cout << ']' << '\n';
        } else cout << "error" << '\n';
    }
}