#ifndef LABA17_REMOVEADJACENTEQUALLETTERS_H
#define LABA17_REMOVEADJACENTEQUALLETTERS_H

#include <ctype.h>
#include "../string_.h"


void remove_adjacent_equal_letters(char* s) {
    char* i_write = s;
    char* i_read = s;
    char last_symbol = *s;

    while (*i_read != '\0') {
        while (*i_read == last_symbol)
            i_read++;

        *i_write = last_symbol;
        i_write++;
        last_symbol = *i_read;
    }

    *i_write = '\0';
}


void test_2_empty() {
    char s[] = "";
    remove_adjacent_equal_letters(s);
    ASSERT_STRING("", s);
}


void test_2_one_letters() {
    char s[] = "a";
    remove_adjacent_equal_letters(s);
    ASSERT_STRING("a", s);
}

void test_2_one_letters_duplicate() {
    char s[] = "aa";
    remove_adjacent_equal_letters(s);
    ASSERT_STRING("a", s);
}


void test_2_two_letters_duplicate() {
    char s[] = "aaa bbb";
    remove_adjacent_equal_letters(s);
    ASSERT_STRING("a b", s);
}


void test_2_remove_adjacent_equal_letters() {
    test_2_empty();
    test_2_one_letters();
    test_2_one_letters_duplicate();
    test_2_two_letters_duplicate();
}

#endif //LABA17_REMOVEADJACENTEQUALLETTERS_H
