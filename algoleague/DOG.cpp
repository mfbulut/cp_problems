#include <iostream>
#include <stack>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        string str;
        cin >> str;

        int count = 0;

        stack<int> st;

        for (char c : str) {
            if (c == 'G' && !st.empty() && st.top() == 'O') {
                st.pop();

                if(!st.empty() && st.top() == 'D') {
                    st.pop();
                    count++;
                } else {
                    st.push('O');
                }

            } else {
                st.push(c);
            }
        }

        cout << count << endl;
    }
}