#include<iostream>
using namespace std;

int main() {
    string str = "sinstriiintng";
    int counts[26] = {0};

    for(int i=0; i<str.length(); i++)
        counts[str[i] - 'a']++;

    for(int i = 0; i < 26; i++)
        if(counts[i] > 1)
            cout << (char)(i + 'a') << " - " << counts[i] << "\n";

    return 0;
}