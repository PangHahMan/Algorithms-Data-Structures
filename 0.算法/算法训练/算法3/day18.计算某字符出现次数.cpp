

#include <iostream>
#include <string>
using namespace std;

int main() {
    string str;
    char c;
    while (getline(cin, str) && cin >> c) {
        //hash表
        int hash[128] = {0};
        for (int i = 0; i < str.size(); i++) {
            if (str[i] >= 'A' && str[i] <= 'Z') {
                hash[str[i] + 32]++;//遇到大写字母就将他转换成小写字母++
            } else {
                hash[str[i]]++;
            }
        }
        //如果是大写就直接+32算小写字母次数即可
        if (c >= 'A' && c <= 'Z') {
            cout << hash[c + 32] << endl;
        } else {
            cout << hash[c] << endl;
        }
    }
    return 0;
}