#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    string input;
    getline(cin, input);

    // Reverse the input string
    reverse(input.begin(), input.end());

    // Output the reversed string
    cout << "Reversed string: " << input << endl;

    return 0;
}
