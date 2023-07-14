#include <iostream>
using namespace std;

int main() {
    int y, m ,d;
    int dy, dm ,dd;
    int Dday=0;
    int dMax;
    cin >> y >> m >> d;
    cin >> dy >> dm >> dd;
    if(dy-y>1000 || (dy-y==1000 && dm>m)||(dy-y==1000 && dm==m && dd >=d)){
        cout << "gg";
        return 0;
    }
    for(int i = y; i<=dy; i++) {
        int j;
        for(j = m; j<=12; j++) {
            switch (j) {
                case 1:
                case 3:
                case 5:
                case 7:
                case 8:
                case 10:
                case 12:
                    dMax = 31;
                    break;
                case 2:
                    dMax = 28;
                    if( (i%4 == 0) && (i%100 != 0) || (i%400==0)) {
                        dMax=29;
                    }
                    break;
                case 4:
                case 6:
                case 9:
                case 11:
                    dMax = 30;
                    break;
            }        
                for(int k = d; k<=dMax; k++) {
                    if( i==dy && j==dm && k==dd) {
                        cout << "D-" << Dday;
                        return 0;
                    }
                    Dday+=1;
                }
                d=1;
        }
        m=1;
    }
}