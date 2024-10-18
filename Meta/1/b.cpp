//
// Created by 21911 on 24-10-8.
//
#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <cmath>

using namespace std;

int countVowelsAndConsonants(string word) {
    int vowels = 0, consonants = 0;
    for (char ch : word) {
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
            vowels++;
        } else {
            consonants++;
        }
    }
    return abs(vowels - consonants);
}

vector<string> solution(const string& text) {
    vector<string> words;
    istringstream is(text);
    string word;

    while (is >> word) {
        words.push_back(word);
    }

    sort(words.begin(), words.end(), [](const auto a, const auto b) {
        if (countVowelsAndConsonants(a) == countVowelsAndConsonants(b)) {
            return a < b;
        }
        return countVowelsAndConsonants(a) < countVowelsAndConsonants(b);
    });

    return words;
}

int main() {
    string text = "penelope lives in hawaii";
    vector<string> result = solution(text);

    // Print the result
    for (const string& word : result) {
        cout << word << " ";
    }
    cout << endl;

    return 0;
}
