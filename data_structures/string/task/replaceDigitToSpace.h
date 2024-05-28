#ifndef LABA17_REPLACEDIGITTOSPACE_H
#define LABA17_REPLACEDIGITTOSPACE_H

#include "../string_.h"

#define ASCII_SHIFT_FOR_DIGIT 48


void replace_digit_to_space(char* s) {
    char* rec_ptr = s;
    char* read_ptr = _string_buffer;

    char* end = getEndOfString(s);
    char* end_in_buff = copy(s, end, _string_buffer);
    *end_in_buff = '\0';

    while (*read_ptr != '\0') {
        if (isdigit(*read_ptr))
            for (int i = 0; i < *read_ptr - ASCII_SHIFT_FOR_DIGIT; i++) {
                *rec_ptr = ' ';
                rec_ptr++;
            }
        else {
            *rec_ptr = *read_ptr;
            rec_ptr++;
        }

        read_ptr++;
    }

    *rec_ptr = '\0';

    freeString(_string_buffer);
}


void test_4_empty() {
    char s[] = "";
    replace_digit_to_space(s);
    ASSERT_STRING("", s);
}


void test_4_non_digit() {
    char s[] = "abcd";
    replace_digit_to_space(s);
    ASSERT_STRING("abcd", s);
}

void test_4_non_letters() {
    char s[] = "2";
    replace_digit_to_space(s);
    ASSERT_STRING("  ", s);
}


void test_4_letters_and_digit() {
    char s[] = "a2b0c3";
    replace_digit_to_space(s);
    ASSERT_STRING("a  bc   ", s);
}


void test_4_replace_digit_to_space() {
    test_4_empty();
    test_4_non_digit();
    test_4_non_letters();
    test_4_letters_and_digit();
}

#endif //LABA17_REPLACEDIGITTOSPACE_H
