#include <iostream>
#include <fstream>
using namespace std;

const int MAX_WORDS = 2000;

int str_len(const char* word) {
    int len = 0;
    while (word[len] != ' ' && word[len] != '\n' && word[len] != '\t' && word[len] != '\0') {
        len++;
    }
    return len;
}

void str_copy(const char* source, char* destination, int len) {
    for (int i = 0; i < len; i++) {
        destination[i] = source[i];
    }
    destination[len] = ' ';
}

bool has_letter_3(const char* word, int len) {
    int cnts[26] = {0};
    for (int i = 0; i < len; i++) {
        if (word[i] >= 'a' && word[i] <= 'z') {
            cnts[word[i] - 'a']++;
        } else if (word[i] >= 'A' && word[i] <= 'Z') {
            cnts[word[i] - 'A']++;
        }
    }
    for (int i = 0; i < 26; i++) {
        if (cnts[i] >= 3) {
            return true;
        }
    }
    return false;
}

bool isUnique(const char words[][MAX_WORDS], int word_len[], int word_cnt, const char* word, int len) {
    for (int i = 0; i < word_cnt; i++) {
        if (word_len[i] == len) {
            bool identical = true;
            for (int j = 0; j < len; j++) {
                if (words[i][j] != word[j]) {
                    identical = false;
                    break;
                }
            }
            if (identical) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    ifstream input("input.txt");
    ofstream output("output.txt");

    char words[MAX_WORDS][MAX_WORDS];
    int word_len[MAX_WORDS] = {0};
    int word_cnt = 0;

    char buffer[MAX_WORDS];
    while (input >> buffer) {
        int len = str_len(buffer);

        char del_word[MAX_WORDS];
        int del_len = 0;
        for (int i = 0; i < len; i++) {
            if ((buffer[i] >= 'a' && buffer[i] <= 'z') || (buffer[i] >= 'A' && buffer[i] <= 'Z')) {
                del_word[del_len++] = buffer[i];
            }
        }

        if (has_letter_3(del_word, del_len)) {
            if (isUnique(words, word_len, word_cnt, del_word, del_len)) {
                str_copy(del_word, words[word_cnt], del_len);
                word_len[word_cnt] = del_len;
                word_cnt++;

                if (word_cnt >= MAX_WORDS) {
                    break;
                }
            }
        }
    }

    for (int i = 0; i < word_cnt - 1; i++) {
        for (int j = 0; j < word_cnt - i - 1; j++) {
            if (word_len[j] > word_len[j + 1]) {

                char temp[MAX_WORDS];
                int tmp_len = word_len[j];

                str_copy(words[j], temp, tmp_len);
                str_copy(words[j + 1], words[j], word_len[j + 1]);
                str_copy(temp, words[j + 1], tmp_len);

                word_len[j] = word_len[j + 1];
                word_len[j + 1] = tmp_len;
            }
        }
    }

    for (int i = 0; i < word_cnt; i++) {
        for (int j = 0; j < word_len[i]; j++) {
            output << words[i][j];
        }
        output << endl;
    }

    input.close();
    output.close();

    return 0;
}
