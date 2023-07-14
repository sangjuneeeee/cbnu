#include <iostream>
#include <vector>
using namespace std;

int main() {
    int num;
    vector<string> text;
    cin >> num;
    text.resize(num);
    //텍스트 입력
    for(int i = 0; i < num; i++) {
        text[i].resize(50);
        cin >> text[i];
    }
    string searchTxt = text[0];
    //탐색
    for(int j = 1; j < num; j++) {
        for(int k = 0; k < searchTxt.size(); k++)
            if( searchTxt[k] != text[j][k] ) {
                searchTxt[k] = '?';
            }
    }
    cout << searchTxt;
}



/* 
문제점 : vector를 잘 활용하고 있지 않음
개선 :
```cpp
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int num;
    vector<string> text;
    cin >> num;
    //텍스트 입력
    for(int i = 0; i < num; i++) {
        string t;
        cin >> t;
        text.push_back(t)
    }
    string searchTxt = text[0];
    //탐색
    for(int j = 1; j < num; j++) {
        for(int k = 0; k < searchTxt.size(); k++)
            if( searchTxt[k] != text[j][k] ) {
                searchTxt[k] = '?';
            }
    }
    cout << searchTxt;
}
```
*/