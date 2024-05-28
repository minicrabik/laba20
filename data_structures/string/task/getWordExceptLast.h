#ifndef LABA17_GETWORDEXCEPTLAST_H
#define LABA17_GETWORDEXCEPTLAST_H

#include "../string_.h"


void get_word_except_last(char* source, char* dest) {
    char* begin_search = source;

    while (get_word_without_space(begin_search, &_bag.words[_bag.size])) {
        begin_search = _bag.words[_bag.size].end + 1;
        _bag.size++;
    }

    if (_bag.size == 0) {
        free_bag(&_bag);
        return;
    }

    WordDescriptor last_word = _bag.words[_bag.size - 1];
    char* rec_ptr = dest;

    for (size_t i = 0; i < _bag.size - 1; i++) {
        if (!isWordEqual(_bag.words[i], last_word)) {
            rec_ptr = copy(_bag.words[i].begin, _bag.words[i].end + 1, rec_ptr);
            if (i != _bag.size - 2)
                *rec_ptr++ = ' ';
        }
    }

    *rec_ptr = '\0';

    free_bag(&_bag);
}


void test_15_empty() {
    char source[] = "";
    char dest[40] = "";

    get_word_except_last(source, dest);

    ASSERT_STRING("", dest);
}


void test_15_one_word() {
    char source[] = "word";
    char dest[40] = "";

    get_word_except_last(source, dest);

    ASSERT_STRING("", dest);
}


void test_15_last_unique() {
    char source[] = "word map";
    char dest[40] = "";

    get_word_except_last(source, dest);

    ASSERT_STRING("word", dest);
}


void test_15_last_not_unique() {
    char source[] = "word map is map";
    char dest[40] = "";

    get_word_except_last(source, dest);

    ASSERT_STRING("word is", dest);
}


void test_15_get_word_except_last() {
    test_15_empty();
    test_15_one_word();
    test_15_last_unique();
    test_15_last_not_unique();
}

#endif //LABA17_GETWORDEXCEPTLAST_H
