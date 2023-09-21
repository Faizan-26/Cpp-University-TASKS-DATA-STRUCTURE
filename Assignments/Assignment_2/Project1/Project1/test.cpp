//#include <iostream>
//#include <cstring>
//using namespace std;
//const int MAX_SIZE = 200; // size of sentence
//const int MAX_WORDS = 100; // size of words
//
//
//void countOccurrences(char words[][MAX_SIZE], int wordCount) {
//    int wordFrequency[MAX_WORDS] = { 0 }; // frequencies are initialized to zero
//
//    for (int i = 0; i < wordCount; ++i) { // runs for each word
//        if (wordFrequency[i] == 0) { // 1st time everyword frequence is 0
//            wordFrequency[i] = 1; // set to 1
//            for (int j = i + 1; j < wordCount; ++j) { //this loop compare a word to rest of words same like searching a number in array
//                if (strcmp(words[i], words[j]) == 0) { // compare two words  if both are same then add by 1
//                    wordFrequency[i]++;
//                    wordFrequency[j] = -1; // for avoiding word duplication 
//                }
//            }
//        }
//    }
//
//    cout << "Word Frequencies:" << endl;
//    for (int i = 0; i < wordCount; ++i) {
//        if (wordFrequency[i] > 0) {
//            cout << words[i] << ": " << wordFrequency[i] << endl;
//        }
//    }
//}
//
//int main() {
//    char sentence[MAX_SIZE];
//    char words[MAX_WORDS][MAX_SIZE] = {}; // 1 word for every row
//    int wordCount = 0;
//
//    cout << "Enter a sentence: ";
//    cin.getline(sentence, MAX_SIZE);
//
//    int j = 0; // move sentences into words 2d array
//    for (int i = 0; i < strlen(sentence); ++i) {
//        if (sentence[i] == ' ' || sentence[i] == '.' || sentence[i] == ',' || sentence[i] == '?' || sentence[i] == '!' || sentence[i] == '\0') {
//            if (j > 0) {
//                words[wordCount][j] = '\0';
//                wordCount++;
//                j = 0;
//            }
//        }
//        else {
//            words[wordCount][j] = sentence[i];
//            j++;
//        }
//    }
//    if (j > 0) {
//        words[wordCount][j] = '\0';
//        wordCount++;
//    }
//
//    countOccurrences(words, wordCount);
//
//    return 0;
//}
