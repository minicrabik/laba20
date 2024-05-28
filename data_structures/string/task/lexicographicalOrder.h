#ifndef LABA17_LEXICOGRAPHICALORDER_H
#define LABA17_LEXICOGRAPHICALORDER_H

#include "../string_.h"
#include <assert.h>


int are_words_equal(WordDescriptor w1, WordDescriptor w2) {
    while (*w1.begin && (*w1.begin == *w2.begin)) {
        w1.begin++;
        w2.begin++;
    }

    return *(const unsigned char*) w1.begin - *(const unsigned char*) w2.begin;
}


bool is_lexicographical_order(char* s) {
    char* begin_search = s;
    WordDescriptor word1, word2;

    if (!getWord(begin_search, &word1))
        return true;

    begin_search = word1.end;

    while (getWord(begin_search, &word2)) {
        if (are_words_equal(word1, word2) <= 0)
            word1 = word2;
        else
            return false;

        begin_search = word2.end;
    }

    return true;
}


void test_6_empty() {
    char s[] = "";
    assert(is_lexicographical_order(s));
}


void test_6_one_letters() {
    char s[] = "a";
    assert(is_lexicographical_order(s));
}


void test_6_only_letters_ordered() {
    char s[] = "a b c d";
    assert(is_lexicographical_order(s));
}


void test_6_only_letters_unordered() {
    char s[] = "a n d";
    assert(!is_lexicographical_order(s));
}


void test_6_one_word_ordered() {
    char s[] = "absolute";
    assert(is_lexicographical_order(s));
}


void test_6_word_ordered() {
    char s[] = "abs abs absolute zero";
    assert(is_lexicographical_order(s));
}


void test_6_word_unordered() {
    char s[] = "zero start";
    assert(!is_lexicographical_order(s));
}


void test_6_lexicographical_order() {
    test_6_empty();
    test_6_one_letters();
    test_6_only_letters_ordered();
    test_6_only_letters_unordered();
    test_6_one_word_ordered();
    test_6_word_ordered();
    test_6_word_unordered();
}

#endif //LABA17_LEXICOGRAPHICALORDER_H
