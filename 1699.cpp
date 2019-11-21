//????????????
#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n;
    vector<int> v;
    int i,j,mn;
    cin >> n;
    v.resize(n+1,0);
    for(i=1;i*i<=n;i++){
        v[i*i]=1;
    }
    for(i=2;i<=n;i++){
        if(v[i]==0){
            mn = i;
            //cout << i << " " << mn << endl;
            for(j=1;j*j<=i;j++){
                //cout << i << " " << (i/(j*j)) + v[i%(j*j)] << endl;
                if(mn > (i/(j*j)) + v[i%(j*j)])
                    mn = (i/(j*j)) + v[i%(j*j)];                
            }
            v[i] = mn;
        }
    }
    cout << v[n] << endl;
    return 0;
}