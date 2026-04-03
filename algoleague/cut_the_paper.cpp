#include <iostream>
#include <vector>
#include <set>

using namespace std;
#define int long long

signed main() {
    int w, h, n;
    cin >> w >> h >> n;

    set<int> mx;
    mx.insert(w);

    set<int> my;
    my.insert(h);

    int x_max = w;

    int x_start = 0;
    int x_end = w;

    int y_max = h;

    int y_start = 0;
    int y_end = h;

    while(n--) {
        char c;
        int x;
        cin >> c >> x;

        if(c == 'w') {
            mx.insert(x);

            if(x_start < x && x < x_end) {
                x_max = 0;
                int last = 0;

                for(int i : mx) {
                    if(x_max < i - last) {
                        x_max = i - last;
                        x_start = last;
                        x_end = i;
                    }
                    last = i;
                }
            }
        } else {
            my.insert(x);

            if(y_start < x && x < y_end) {
                y_max = 0;
                int last = 0;

                for(int i : my) {
                    if(y_max < i - last) {
                        y_max = i - last;
                        y_start = last;
                        y_end = i;
                    }
                    last = i;
                }
            }
        }

        cout << x_max * y_max << endl;
    }
}
