#include <iostream>
#include <fstream>
using namespace std;

const int MAX_WORDS = 1000;
const char vowels[] = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};

bool isPalindrome(const char word[], int len) {
    for (int i = 0; i < len / 2; i++) {
        if (word[i] != word[len - 1 - i]) {
            return false;
        }
    }
    return len > 1;
}

int count_vowels(const char word[], int len) {
    int cnt = 0;
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < 10; j++) {
            if (word[i] == vowels[j]) {
                cnt++;
                break;
            }
        }
    }
    return cnt;
}

void copy_word(char dest[], const char src[], int len) {
    for (int i = 0; i < len; i++) {
        dest[i] = src[i];
    }
    dest[len] = '\0';
}

bool compare_words(const char word1[], int len1, const char word2[], int len2) {
    int min_len = (len1 < len2) ? len1 : len2;
    for (int i = 0; i < min_len; i++) {
        if (word1[i] < word2[i]) return true;
        if (word1[i] > word2[i]) return false;
    }
    return len1 < len2;
}

void sort_words(char words[MAX_WORDS][100], int lengths[MAX_WORDS], int cnts[MAX_WORDS], int word_cnt, bool by_vowels) {
    for (int i = 0; i < word_cnt - 1; i++) {
        for (int j = 0; j < word_cnt - i - 1; j++) {
            bool condition;
            if (by_vowels) {
                condition = cnts[j] < cnts[j + 1];
            } else {
                condition = compare_words(words[j], lengths[j], words[j + 1], lengths[j + 1]);
            }
            if (condition) {
                char tmp[100];
                int temp_len = lengths[j];
                int tmp_cnt = cnts[j];

                copy_word(tmp, words[j], lengths[j]);
                copy_word(words[j], words[j + 1], lengths[j + 1]);
                copy_word(words[j + 1], tmp, temp_len);

                lengths[j] = lengths[j + 1];
                lengths[j + 1] = temp_len;
                cnts[j] = cnts[j + 1];
                cnts[j + 1] = tmp_cnt;
            }
        }
    }
}

int duplicate_vowels(char word[], int len) {
    char tmp[200];
    int indx = 0;
    for (int i = 0; i < len; i++) {
        tmp[indx++] = word[i];
        for (int j = 0; j < 10; j++) {
            if (word[i] == vowels[j]) {
                tmp[indx++] = word[i];
                break;
            }
        }
    }
    for (int i = 0; i < indx; i++) {
        word[i] = tmp[i];
    }
    return indx;
}

int main() {
    char input[10000];
    cin.getline(input, 10000);

    char words[MAX_WORDS][100];
    int lengths[MAX_WORDS];
    int vowel_counts[MAX_WORDS];
    int word_cnt = 0;

    int i = 0;
    while (input[i] != '\0') {
        char current_word[100];
        int len = 0;

        while (input[i] != ' ' && input[i] != '\0') {
            current_word[len++] = input[i++];
        }
        if (len > 0) {
            copy_word(words[word_cnt], current_word, len);
            lengths[word_cnt] = len;
            vowel_counts[word_cnt] = count_vowels(current_word, len);
            word_cnt++;
        }
        if (input[i] == ' ') {
            i++;
        }
    }

    bool has_palindrome = false;
    for (int i = 0; i < word_cnt; i++) {
        if (isPalindrome(words[i], lengths[i])) {
            has_palindrome = true;
            break;
        }
    }

    if (has_palindrome) {
        sort_words(words, lengths, vowel_counts, word_cnt, true);
    } else {
        for (int i = 0; i < word_cnt; i++) {
            lengths[i] = duplicate_vowels(words[i], lengths[i]);
        }
        sort_words(words, lengths, vowel_counts, word_cnt, false);
    }

    for (int i = 0; i < word_cnt; i++) {
        for (int j = 0; j < lengths[i]; j++) {
            cout << words[i][j];
        }
        cout << endl;
    }

    return 0;
}
