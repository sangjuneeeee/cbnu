#include <iostream>

using namespace std;

int main() {
    int n, k;
    long long max, mid, min=0;
    cin >> n >> k;
    int lanCable[n];
    for(int i = 0; i<n; i++) {
        cin >> lanCable[i];
        if (lanCable[i]>max) max = lanCable[i];
    }
    int ans=0;
    while(min <= max) {
        int tmp = 0;
        mid = (max+min)/2;
        for(int j = 0; j<n; j++) {
            tmp += lanCable[j]/mid;
        }
        if(tmp<k) {
            max = mid-1;
        }else {
            min = mid+1;
            if(ans<mid) ans=mid;
        }
    }
    cout << ans;
}