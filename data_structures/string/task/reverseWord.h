
#ifndef LABA17_GETWORD_H
#define LABA17_GETWORD_H

#include "../string_.h"


void digit_to_start(WordDescriptor word) {
    char* end_string_buffer = copy(word.begin, word.end, _string_buffer);

    char* resPosition = copyIfReverse(end_string_buffer - 1, _string_buffer - 1, word.begin, isdigit);

    copyIf(_string_buffer, end_string_buffer, resPosition, isalpha);
}


void inverted_digit_to_start_letters_to_end(char* s) {
    char* begin_search = s;
    WordDescriptor word;

    while (getWord(begin_search, &word)) {
        digit_to_start(word);
        begin_search = word.end;
    }
}


void reverse_word(WordDescriptor word) {
    char* start = word.begin;
    char* end = word.end - 1;

    while (start < end) {
        char temp = *start;
        *start = *end;
        *end = temp;

        start++;
        end--;
    }
}


void reverse_word_in_string(char* s) {
    char* begin_search = s;
    WordDescriptor word;

    while (getWord(begin_search, &word)) {
        reverse_word(word);
        begin_search = word.end;
    }
}


void test_3_empty() {
    char s[] = "";
    reverse_word_in_string(s);
    ASSERT_STRING("", s);
}


void test_3_one_letters() {
    char s[] = "a";
    reverse_word_in_string(s);
    ASSERT_STRING("a", s);
}


void test_3_one_word() {
    char s[] = "absolute";
    reverse_word_in_string(s);
    ASSERT_STRING("etulosba", s);
}


void test_3_two_word() {
    char s[] = "absolute radar";
    reverse_word_in_string(s);
    ASSERT_STRING("etulosba radar", s);
}


void test_3_reverse_word() {
    test_3_empty();
    test_3_one_letters();
    test_3_one_word();
    test_3_two_word();
}

#endif //LABA17_GETWORD_H
