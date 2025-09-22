#include <iostream>
using namespace std;

int main() {
    int start, stop;
    long long sum = 0;

    cout << "starting value of X: ";
    cin >> start;

    cout << "stopping value of X: ";
    cin >> stop;

    for (int i = start; i <= stop; i++) {
        sum += (i * i);
    }

    cout << "The summation of X^2 from " << start << " to " << stop
         << " is: " << sum << endl;

    return 0;
}

