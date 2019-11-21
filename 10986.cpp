#include <iostream>
#include <vector>

using namespace std;

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    vector<long long> v,c;
    int n,m,s{};
    int i,j;
    long long res = 0;
    cin >> n >> m;
    v.resize(n);
    c.resize(m);
    for(i=0;i<n;i++){
        cin >> v[i];
        s = (s + v[i])%m;
        if(s == 0){
            res++;
        }
        c[s]++;
    }
    for(i=0;i<m;i++){
        res += c[i]*(c[i]-1)/2;
    }
    cout << res << endl;
    return 0;
}