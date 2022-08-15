#include<iostream>
#include<vector>

using namespace std;

void setTime(vector<bool>* time, int p, int q) {
    if(time->size()<q) time->resize(q, false);
    for(int i=p; i<q; i++) {
        (*time)[i] = true;
    }
    return;
}

int main() {
    int N, p, q, max_busy, max_relax;
    bool record;
    vector<bool> time;
    while(cin >> N) {
        time.clear();
        for(int n=0; n < N; n++) {
            cin >> p >> q;
            setTime(&time, p, q);
        }

        max_busy = 0;
        max_relax = 0;
        record = false;
        for(int i=0, tmp_busy=0, tmp_relax=0; i<time.size(); i++) {
            if(time[i]) record = true;
            if(!record) continue;

            if(time[i]) {
                if(tmp_relax > max_relax) max_relax = tmp_relax;
                tmp_relax = 0;

                tmp_busy++;
            } else {
                if(tmp_busy > max_busy) max_busy = tmp_busy;
                tmp_busy = 0;

                tmp_relax++;
            }

            if(i==time.size()-1) {
                if(tmp_relax > max_relax) max_relax = tmp_relax;
                if(tmp_busy > max_busy) max_busy = tmp_busy;
            }
        }
        
        cout << max_busy << ' ' << max_relax << endl;
    }
    return 0;
}
