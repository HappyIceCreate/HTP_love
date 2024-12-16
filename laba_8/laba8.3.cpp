#include <iostream>
#include <fstream>
using namespace std;

char lower_case(char c) {
    if (c >= 'A' && c <= 'Z') {
        return c + ('a' - 'A');
    }
    return c;
}

bool isAlpha(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

bool isPalindrome(const char* word, int len) {
    int start = 0;
    int end = len - 1;

    while (start < end) {
        if (lower_case(word[start]) != lower_case(word[end])) {
            return false;
        }
        start++;
        end--;
    }

    return true;
}

bool isPrime(int num) {
    if (num <= 1) return false;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return false;
    }
    return true;
}

void upper_case(char* word, int len) {
    for (int i = 0; i < len; i++) {
        if (word[i] >= 'a' && word[i] <= 'z') {
            word[i] -= ('a' - 'A');
        }
    }
}

void has_letter_4(const char* text, int text_len, char* top_letters, int* top_rate) {
    int rate[26] = {0};

    for (int i = 0; i < text_len; i++) {
        if (isAlpha(text[i])) {
            rate[lower_case(text[i]) - 'a']++;
        }
    }

    for (int i = 0; i < 4; i++) {
        int max_rate = -1;
        int max_indx = -1;
        for (int j = 0; j < 26; j++) {
            if (rate[j] > max_rate) {
                max_rate = rate[j];
                max_indx = j;
            }
        }
        if (max_indx != -1) {
            top_letters[i] = 'a' + max_indx;
            top_rate[i] = max_rate;
            rate[max_indx] = -1;
        }
    }
}

void process_text(const char* text, int text_len, ofstream& output) {
    char top_letters[4] = {0};
    int top_rate[4] = {0};

    has_letter_4(text, text_len, top_letters, top_rate);

    int i = 0;
    while (i < text_len) {
        char word[100];
        int word_len = 0;
        while (i < text_len && isAlpha(text[i])) {
            word[word_len++] = text[i++];
        }
        if (word_len > 0) {
            bool found = false;
            if (isPalindrome(word, word_len)) {
                for (int j = 0; j < word_len - 1; j++) {
                    char first = lower_case(word[j]);
                    char second = lower_case(word[j + 1]);
                    bool firstUp = false;
                    bool secondUp = false;

                    for (int k = 0; k < 4; k++) {
                        if (first == top_letters[k]) {
                            firstUp = true;
                        }
                        if (second == top_letters[k]) {
                            secondUp = true;
                        }
                    }
                    if (firstUp && secondUp) {
                        found = true;
                        upper_case(word, word_len);
                        for (int k = 0; k < word_len; k++) {
                            output << word[k];
                        }
                        output << "(" << first << second << ")";
                        break;
                    }
                }
            }
            if (!found) {
                for (int k = 0; k < word_len; k++) {
                    output << word[k];
                }
            }
        }
        if (i < text_len && !isAlpha(text[i])) {
            output << text[i];
            i++;
        }
    }
}

int main() {
    ifstream input("input.txt");
    ofstream output("output.txt");

    char text[10000];
    int text_len = 0;
    char c;
    while (input.get(c)) {
        text[text_len++] = c;
    }

    process_text(text, text_len, output);

    input.close();
    output.close();

    return 0;
}
