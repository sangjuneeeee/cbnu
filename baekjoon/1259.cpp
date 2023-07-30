#include <iostream>
#include <string>

using namespace std;

int main() {
    while (true) {
        string n;
        bool p = true;
        cin >> n;
        if (n == "0") {
            break;
        } else {
            int length = n.length();
            for (int i = 0; i < length / 2; i++) {
                if (n[i] != n[length - 1 - i]) {
                    p = false;
                    break;
                }
            }
        }
        if (p) {
            cout << "yes\n";
        } else {
            cout << "no\n";
        }
    }
    return 0;
}


/* Best Case
#include <stdio.h>
int main()
{
	while(1){
		int n;
		scanf("%d", &n);
		if(!n) break;
		int q=0, m=n;
		while(n){
			q=10*q+n%10;        
			n/=10;
		}
		if(q==m) printf("yes\n");
		else printf("no\n");
	}
	return 0;
}
//원래 있던 q를 10을 곱하고 n을 10으로 나눠 순서를 바꿈
if 1231
q       n
1       1231
13      123
132     12
1321    1
1231 != 1321  >>  no
*/