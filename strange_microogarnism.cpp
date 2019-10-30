#include <iostream>
#include <iomanip>

using namespace std;

int k;

int q(int cells,int remain_time){
    cout << "C, R) " << cells << ", " << remain_time << endl;
    if(remain_time<=0){
        return cells;
    }
    int max_cells=cells;
    int temp,track1=0,track2=0,track3=0;
    for(int i=cells/2;i>=2;i--){
        if(cells%i==0){
            temp=i*q(cells/i,remain_time-1);
            if(max_cells<temp){
                max_cells=temp;
                track1=2;
                track2=cells/i;
            }
        }
    }
    temp=q(cells+k,remain_time-1);
    if(max_cells<temp){
        max_cells=temp;
        track1 = 1;
        track2 = cells;
        track3 = k;
    }
    //cout << "Track: " << track1 << " * " << track2 << " + " << track3 << endl;
    return max_cells;
}

int q2(int cells,int remain_time){
    //cout << "C, R) " << cells << ", " << remain_time << endl;
    if(remain_time<=0){
        return cells;
    }
    int max_cells=cells;
    int temp,track1=0,track2=0,track3=0;
    for(int i=2;i<=cells/2;i++){
        if(cells%i==0){
            temp=i*q(cells/i,remain_time-1);
            if(max_cells<temp){
                max_cells=temp;
                track1=2;
                track2=cells/i;
            }
        }
    }
    temp=q(cells+k,remain_time-1);
    if(max_cells<temp){
        max_cells=temp;
        track1 = 1;
        track2 = cells;
        track3 = k;
    }
    //cout << "Track: " << track1 << " * " << track2 << " + " << track3 << endl;
    return max_cells;
}
int main(){
    int c,t;
    cin >> c >> k >> t;
    cout << q(c,t) << endl;
    return 0;
}