#include <iostream>
#include <cstring>
using namespace std;
void encryptMessage(char* text, int key) {
    for (int i = 0; i < strlen(text); ++i) {
        text[i] =static_cast<char>(text[i] + key); // for adding key into asci
    }
}

void decryptMessage(char* text, int key) {
    for (int i = 0; i < strlen(text); ++i) {
            text[i] = static_cast<char>(text[i] - key); // for subtractingkey into asci
    }
}

int main() {
    cout << "Enter a text: ";
    char* text = new char[20];
    cin.getline(text, 20);
    cout << "Enter key (1-26): ";
    int key;
    cin >> key;
    encryptMessage(text, key);

    cout << "Encrypted text: " << text << endl;

    decryptMessage(text, key);

    cout << "Decrypted text: " << text << endl;

    delete[] text; // Release the dynamically allocated memory

    return 0;
}
