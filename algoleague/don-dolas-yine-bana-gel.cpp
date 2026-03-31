#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> arr(n + 1);
    vector<bool> visited(n + 1);

    for(int i = 1; i <= n; ++i) {
        cin >> arr[i];
    }

    int counter = 0;
    int last = -1;
    int current = 1;

    while(true) {
        if(visited[current]) {
            break;
        }

        counter++;
        visited[current] = true;

        last = current;
        current = arr[current];
        arr[last] = counter;
    }

    cout << current << " " << arr[last] - arr[current] + 1 << endl;
}


/*
#include <iostream>
#include <vector>
using namespace std;


int main() {
    int n;
    cin >> n;

    vector<int> arr(n + 1);

    for(int i = 1; i <= n; ++i) {
        cin >> arr[i];
    }

    int counter = 0;
    int last = -1;
    int current = 1;

    while(true) {
        if(arr[current] < 0) {
            break;
        }

        counter++;

        last = current;
        current = arr[current];
        arr[last] = -counter;
    }

    cout << current << " " << -(arr[last] - arr[current]) + 1 << endl;
}

*/