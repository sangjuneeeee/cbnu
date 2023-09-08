#include <iostream>
using namespace std;

int main () {
    int a, b, v;
    int day = 1;
    cin >> a >> b >> v;
    if ( (v-a)%(a-b) != 0) {
        day += (v-a)/(a-b)+1;
    } else {
        day += (v-a)/(a-b);
    }
    cout << day;
}