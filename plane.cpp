#include <iostream>

using namespace std;

int main() {

    int C;
    int P;
    int F;

    cin >> C >> P >> F;

    if (C * F <= P) {
        cout << "S";
    } else {
        cout << "N";
    }

    return 0;
}