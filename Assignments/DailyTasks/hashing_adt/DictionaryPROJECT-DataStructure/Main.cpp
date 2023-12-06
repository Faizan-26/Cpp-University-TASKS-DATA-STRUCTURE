#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>
#include <conio.h>
#include <sstream>

using namespace std;

struct TrieNode {
    TrieNode* children[26]; 
    bool isWordEnd; // tells if word in completed 
    string meaning; // contains meaning of word 

    TrieNode() : isWordEnd(false), meaning("") {
        for (int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
    }
};


class Trie {
    TrieNode* root;

public:
    Trie() : root(new TrieNode()) {}

    TrieNode* getRoot() {
        return root;
    }

    void insert(string word, string meaning) {
        TrieNode* curNode = root;
        for (int i = 0; i < word.length(); i++) {
            char cur = word[i];
            if (curNode->children[cur - 'a'] == NULL) {
                TrieNode* newNode = new TrieNode();
                newNode->meaning = meaning;
                curNode->children[cur - 'a'] = newNode;
            }
            curNode = curNode->children[cur - 'a'];
        }
        curNode->isWordEnd = true;
    }

    bool search(string word) {
        TrieNode* curNode = root;
        for (int i = 0; i < word.length(); i++) {
            char cur = word[i];
            if (!curNode->children[cur - 'a']) {
                return false;
            }
            curNode = curNode->children[cur - 'a'];
        }
        return curNode->isWordEnd;
    }

    void findMeaning(string word) {
        TrieNode* curNode = root;
        for (int i = 0; i < word.length(); i++) {
            char cur = word[i];
            curNode = curNode->children[cur - 'a'];
        }
        cout << "\nWord: " << word;
        cout << "\nMeaning: " << curNode->meaning;
    } 
    
    void editWord(string word , string meaning) {
        TrieNode* curNode = root;
        for (int i = 0; i < word.length(); i++) {
            char cur = word[i];
            curNode = curNode->children[cur - 'a'];
        }
        curNode->meaning = meaning;
        cout << "\nUpdated info :\n";
        cout << "\nWord: " << word;
        cout << "\nMeaning: " << curNode->meaning << endl;
    }

    bool isEmptyNode(TrieNode* node) {
        for (int i = 0; i < 26; i++) {
            if (node->children[i] != NULL) {
                return false;
            }
        }
        return true;
    }

    void deleteWord(string word) {
        performDeletion(root, word, 0);
    }

    void performDeletion(TrieNode* curNode, string word, int dept) {
        if (curNode == NULL) {
            return;
        }

        if (dept == word.length()) {
            curNode->isWordEnd = false;
            curNode->meaning = "";
            return;
        }

        int index = word[dept] - 'a';
        TrieNode* nextNode = curNode->children[index];

        if (nextNode != NULL) {
            performDeletion(nextNode, word, dept + 1);
            if (nextNode->isWordEnd == false && isEmptyNode(nextNode)) {
                delete nextNode;
                curNode->children[index] = NULL;
            }
        }
    }

    void loadDataFromFile() {
        cout << "\nLOADING...\n";
        ifstream fin("Dictionary.txt");
        if (!fin.is_open()) {
            cout << "\nFile not found!\n";
            return;
        }
        string line;
        string word, meaning;
        while (getline(fin, line)) {
            istringstream wordAndMeaning(line);
            wordAndMeaning >> word >> meaning;
            insert(word, meaning);
        }
        cout << "\nDictionary LOADED.\n";
        Sleep(500);
        system("cls");
    }

    void storeWords(TrieNode* curNode, ofstream& fout, string curWord) {
        if (curNode == NULL) {
            return;
        }
        if (curNode->isWordEnd) {
            fout << curWord << "\t" << curNode->meaning << "\n";
        }
        for (int i = 0; i < 26; i++) {
            if (curNode->children[i] != NULL) {
                char nextCh = 'a' + i;
                storeWords(curNode->children[i], fout, curWord + nextCh);
            }
        }
    }

    void safeToFile() {
        ofstream fout("Dictionary.txt", ios::out);
        if (!fout.is_open()) {
            cout << "\nFile not found.\n";
            return;
        }
        storeWords(root, fout, "");
        fout.close();
    }

    // Recursive function to print auto-suggestions for given node.
    void suggestionsRec(TrieNode* cur, string& currPrefix, int &count) {
        if (count >= 10) { // limit displaying number of maximum suggestions
            return;
        }
        if (cur->isWordEnd) {
            cout << currPrefix;
            cout << endl;
            count++;
        }

        if (isEmptyNode(cur)) { // if cur Node is empty then remove last character and return  this will go to one level up in tree
            currPrefix.pop_back();
            return;
        }

        for (int i = 0; i < 26; i++) { // search in children array if it is not null then add that character to end of curPrefix and recursive call 
            if (cur->children[i]) {
                currPrefix.push_back('a' + i);
                suggestionsRec(cur->children[i], currPrefix, count);
            }
        }
        currPrefix.pop_back();
    }
    int getSuggestions(string wordTosuggest) {
        return printAutoSuggestions(root, wordTosuggest);
    }
   
    int printAutoSuggestions(TrieNode* Root, string wordTosuggest) {
        TrieNode* pCrawl = Root;
        int level; //current depth
        int n = wordTosuggest.length(); // n is length of word
        for (level = 0; level < n; level++) {
            int index = wordTosuggest[level] -'a';

            if (!pCrawl->children[index]) // children[index] == NULL
                return 0;

            pCrawl = pCrawl->children[index]; // else traverse to next children[index] node
        }

        bool isWord = (pCrawl->isWordEnd == true); // this mean when pCrawl reach down length of word then check if isWordEnd is true?
        bool isLast = isEmptyNode(pCrawl); // isEmptyNode Checks next children node to pCrawl that it is completly NULL or not

        if (isWord && isLast) { // if it is both word and last word then print it 
            cout << wordTosuggest << endl;
            return -1;
        }

        if (!isLast) { // if it is not last then go to suggestionsRecursive function that will display in preOrder traversal
            int count = 0;
            suggestionsRec(pCrawl, wordTosuggest, count);  // count gives number of max suggestions to display prefix is 
            return 1;
        }

        return 0;
    }
};

void menu() {
    cout << "\n1. Add Word.\n2. Delete Word.\n3. Search Word.\n4. Suggest Word.\n5. Edit word.\n6. Save and Exit.\n";
}

string toLowerCase(string S) {
    for (int i = 0; i < S.length(); i++)
    {
        S[i] = tolower(S[i]);
    }
    return S;
}
int main() {
    Trie dict;
    dict.loadDataFromFile();
    int choice = 0;
    string currentInput = "";

    while (true) {
        menu();
        cin >> choice;
        if (choice == 1) {
            string word, meaning;
            cout << "\nEnter Word :";
            cin >> word;
            word = toLowerCase(word);
            if (!dict.search(word)) {
                cout << "Enter Meaning :";
                cin >> meaning;
               meaning = toLowerCase(meaning);
                dict.insert(word, meaning);
            }
            else {
                cout << "\nWord already exists in the dictionary.\n";
            }
        }
        else if (choice == 2) {
            string word;
            cout << "\nEnter Word to delete :";
            cin >> word;
            word = toLowerCase(word);
            if (dict.search(word)) {
                dict.deleteWord(word);
            }
            else {
                cout << "\nWord does not exist.\n";
            }
        }
        else if (choice == 3) {
            string word;
            cout << "\nEnter Word to find meaning :";
            cin >> word;
            word = toLowerCase(word);
            if (dict.search(word)) {
                dict.findMeaning(word);
            }
            else {
                cout << "\nWord does not exist.\n";
            }
        }
        else if (choice == 4) {
            cout << "\nEnter the word to suggest: ";
            currentInput = "";
            while (true) {
                if (_kbhit()) {
                    char key = _getch();
                    cout << key;
                    if (key == 13) { // Enter key pressed
                        break;
                    }
                    else if (key == 8) { // Backspace key pressed
                        if (!currentInput.empty()) {
                            currentInput.pop_back(); // removes last character and reduce size by 1
                            system("cls");
                            menu();
                            if (_kbhit()) {
                                key = _getch();
                            }
                            cout << "Current Input: " << currentInput;
                        }
                    }
                    if (isalpha(key)) {
                        currentInput += tolower(key); // if case is upper it convert that into lower
                        system("cls");
                        menu();
                        cout << "Current Input: " << currentInput;
                        cout << endl;
                        dict.printAutoSuggestions(dict.getRoot(), currentInput);
                    }
                    else if(key!= 8) {
                        cout << "\nInvalid Input!!!\n";
                    }
                }
            }
        }
        else if (choice == 5) {
            string word, meaning = "";
            cout << "\nEnter Word to edit :";
            cin >> word;
            word = toLowerCase(word);
            if (dict.search(word)) {
                cout << "Enter new meaning : ";
                cin >> meaning;
                meaning = toLowerCase(meaning);
                dict.editWord(word, meaning);
            }
            else {
                cout << "\nWord does not exist.\n";
            }
        }
        else if (choice == 6) {
            dict.safeToFile();
            break;
        }
        else {
            cout << "\nWrong Input.\n";
        }
    }
    return 0;
}
