#ifndef LABA17_COUNTERPALINDROMEWORDS_H
#define LABA17_COUNTERPALINDROMEWORDS_H

#include "../string_.h"
#include <assert.h>


int get_separate_word(char* begin_search, WordDescriptor * word) {
    word->begin = findNonSpace(begin_search);
    if (*word->begin == '\0')
        return false;

    word->end = findSpace(word->begin);

    if (ispunct(*(word->end - 1)))
        word->end--;

    return true;
}


int counter_palindrome_words(char* s) {
    int amount_palindrome = 0;
    char* begin_search = s;
    WordDescriptor word;

    while (get_separate_word(begin_search, &word)) {
        if (isPalindromeWord(&word))
            amount_palindrome++;

        if (ispunct(*(word.end)))
            word.end++;

        begin_search = word.end;
    }

    return amount_palindrome;
}


void test_8_non_palindrome() {
    char s[] = "palindrome, not, in, string";
    assert(counter_palindrome_words(s) == 0);
}


void test_8_only_letters() {
    char s[] = "a b c d";
    assert(counter_palindrome_words(s) == 4);
}


void test_8_only_palindrome() {
    char s[] = "radar, non, anna";
    assert(counter_palindrome_words(s) == 3);
}


void test_8_different_string() {
    char s[] = "radar, word, non, anna, vector, heh";
    assert(counter_palindrome_words(s) == 4);
}


void test_8_counter_palindrome_word() {
    test_8_non_palindrome();
    test_8_only_letters();
    test_8_only_palindrome();
    test_8_different_string();
}


#endif //LABA17_COUNTERPALINDROMEWORDS_H
