#include <iostream>
#include <string.h>
using namespace std;

int main() {
    int n = 0;
    int ch;
    n = 0;
    for (ch = getchar(); ch != '\n'; n++)
        ;

    cout << n << endl;
    return 0;
}
