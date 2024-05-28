#ifndef LABA17_REARRANGINGWORDS_H
#define LABA17_REARRANGINGWORDS_H

#include "../string_.h"


void append_word(char* result, WordDescriptor * word) {
    char* ptr = result;
    while (*ptr != '\0') {
        ptr++;
    }

    char* start = word->begin;
    while (*start != *word->end) {
        *ptr = *start;
        ptr++;
        start++;
    }

    *ptr = ' ';
    ptr++;
    *ptr = '\0';
}


void merge_words(char* s1, char* s2, char* result) {
    WordDescriptor word1, word2;
    bool isW1Found, isW2Found;
    char *beginSearch1 = s1, *beginSearch2 = s2;

    while ((isW1Found = getWord(beginSearch1, &word1)),
            (isW2Found = getWord(beginSearch2, &word2)),
            isW1Found || isW2Found) {
        if (isW1Found) {
            append_word(result, &word1);
            beginSearch1 = word1.end;
        }
        if (isW2Found) {
            append_word(result, &word2);
            beginSearch2 = word2.end;
        }
    }
}


void test_9_empty() {
    char result[100] = "";

    char s1[] = "";
    char s2[] = "";

    merge_words(s1, s2, result);

    ASSERT_STRING("", result);
}


void test_9_one_string_empty_1() {
    char result[100] = "";

    char s1[] = "";
    char s2[] = "word";

    merge_words(s1, s2, result);

    ASSERT_STRING("word ", result);
}


void test_9_one_string_empty_2() {
    char result[100] = "";

    char s1[] = "word";
    char s2[] = "";

    merge_words(s1, s2, result);

    ASSERT_STRING("word ", result);
}


void test_9_different_string() {
    char result[100] = "";

    char s1[] = "word";
    char s2[] = "vector";

    merge_words(s1, s2, result);

    ASSERT_STRING("word vector ", result);
}


void test_9_different_amount_word_1() {
    char result[100] = "";

    char s1[] = "word";
    char s2[] = "vector love";

    merge_words(s1, s2, result);

    ASSERT_STRING("word vector love ", result);
}


void test_9_different_amount_word_2() {
    char result[100] = "";

    char s1[] = "word vector";
    char s2[] = "love";

    merge_words(s1, s2, result);

    ASSERT_STRING("word love vector ", result);
}


void test_9_rearranging_words() {
    test_9_empty();
    test_9_one_string_empty_1();
    test_9_one_string_empty_2();
    test_9_different_string();
    test_9_different_amount_word_1();
    test_9_different_amount_word_2();
}

#endif //LABA17_REARRANGINGWORDS_H
