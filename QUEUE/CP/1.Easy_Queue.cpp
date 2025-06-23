#include<iostream>
#include<queue>
using namespace std;

int main() {
    queue<int> q;
    int T;
    cin >> T;

    for (int i = 0; i < T; i++) {
        int token;
        cin >> token;

        if (token == 1) {
            int n;
            cin >> n;
            q.push(n);
        }
        else if (token == 2) {
            if (!q.empty()) {
                q.pop();
            }
        }
        else if (token == 3) {
            if (q.empty()) {
                cout << "Empty!" << endl;
            } else {
                cout << q.front() << endl;
            }
        }
    }

    return 0;
}
