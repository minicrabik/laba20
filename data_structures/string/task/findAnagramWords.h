#ifndef LABA17_FINDANAGRAMWORDS_H
#define LABA17_FINDANAGRAMWORDS_H

#include <stdlib.h>
#include <assert.h>
#include "../string_.h"


int compare_letters(const void* s1, const void* s2) {
    return *(char *) s1 - *(char *) s2;
}

void sort_word_letters(WordDescriptor * word) {
    qsort(word->begin, word->end - word->begin, sizeof(char), compare_letters);
}


bool are_identical_words_in_string(char* s) {
    char* begin_buff = _string_buffer;

    copy(s, s + strlen_(s), _string_buffer);

    while (getWordWithoutSpace(begin_buff, &_bag.words[_bag.size])) {
        begin_buff = _bag.words[_bag.size].end + 2;
        _bag.size++;
    }

    freeString(_string_buffer);

    if (_bag.size <= 1)
        return false;

    for (size_t i = 0; i < _bag.size; i++)
        sort_word_letters(&_bag.words[i]);

    for (size_t i = 0; i < _bag.size; i++)
        for (size_t j = i + 1; j < _bag.size; j++)
            if (isWordEqual(_bag.words[i], _bag.words[j])) {
                free_bag(&_bag);
                return true;
            }

    free_bag(&_bag);
    return false;
}


void test_14_empty() {
    char s[] = "";
    assert(!are_identical_words_in_string(s));
}


void test_14_one_word() {
    char s[] = "word";
    assert(!are_identical_words_in_string(s));
}


void test_14_anagram_not_in_string() {
    char s[] = "duplicate not in string";
    assert(!are_identical_words_in_string(s));
}


void test_14_anagram_in_string() {
    char s[] = "string in string";
    assert(are_identical_words_in_string(s));
}


void test_14_find_anagram_words() {
    test_14_empty();
    test_14_one_word();
    test_14_anagram_not_in_string();
    test_14_anagram_in_string();
}

#endif //LABA17_FINDANAGRAMWORDS_H
