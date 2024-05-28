
#ifndef LABA17_LETTERSBELONGSTRING_H
#define LABA17_LETTERSBELONGSTRING_H

#include <assert.h>
#include "../string_.h"

#define LETTERS_SHIFT 97


bool letters_belong_string(char* string, WordDescriptor word) {
    bool include[26] = {0};

    char* start = string;
    char* end = getEndOfString(string);

    while (start != end) {
        if (isalpha(*start))
            include[*start - LETTERS_SHIFT] = true;

        start++;
    }

    while (word.begin != word.end) {
        if (!include[*word.begin - LETTERS_SHIFT])
            return false;

        word.begin++;
    }

    return true;
}


void test_19_empty() {
    char string[] = "";
    WordDescriptor word;
    getWord("", &word);

    assert(!letters_belong_string(string, word));
}


void test_19_empty_word() {
    char string[] = "word";
    WordDescriptor word;
    getWord("", &word);

    assert(!letters_belong_string(string, word));
}


void test_19_empty_string() {
    char string[] = "";
    WordDescriptor word;
    getWord("word", &word);

    assert(!letters_belong_string(string, word));
}


void test_19_letters_not_in_string() {
    char string[] = "abc";
    WordDescriptor word;
    getWord("word", &word);

    assert(!letters_belong_string(string, word));
}


void test_19_letters_in_string() {
    char string[] = "world";
    WordDescriptor word;
    getWord("word", &word);

    assert(letters_belong_string(string, word));
}


void test_19_letters_belong_string() {
    test_19_empty();
    test_19_empty_word();
    test_19_empty_string();
    test_19_letters_not_in_string();
    test_19_letters_in_string();
}


#endif //LABA17_LETTERSBELONGSTRING_H
