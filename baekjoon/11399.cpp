#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    int sum=0;
    cin >> n;
    vector <int> person(n);
    for(int j=0; j<n; j++){
        cin >> person[j];
    }
    sort(person.begin(), person.end());
    for(int i=0; i<n; i++){
        sum += person[i]*(n-i);
    }
    cout << sum;
}