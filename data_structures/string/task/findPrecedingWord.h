#ifndef LABA17_FINDPRECEDINGWORD_H
#define LABA17_FINDPRECEDINGWORD_H

#include "../string_.h"


WordDescriptor find_preceding_word(char* s1, char* s2) {
    char* begin_search_1 = s1;
    char* begin_search_2 = s2;

    while (get_word_without_space(begin_search_1, &_bag.words[_bag.size])) {
        begin_search_1 = _bag.words[_bag.size].end + 1;
        _bag.size++;
    }

    while (get_word_without_space(begin_search_2, &_bag2.words[_bag2.size])) {
        begin_search_2 = _bag2.words[_bag2.size].end + 1;
        _bag2.size++;
    }

    bool stop = false;
    WordDescriptor w;
    WordDescriptor preceding_w = {.begin = NULL, .end = NULL};

    for (size_t i = 1; i < _bag.size; i++) {
        w = _bag.words[i];
        for (size_t j = 0; j < _bag2.size; j++)
            if (isWordEqual(w, _bag2.words[j])) {
                stop = true;
                break;
            }

        if (stop) {
            preceding_w = _bag.words[i - 1];
            break;
        }

    }

    free_bag(&_bag);
    free_bag(&_bag2);

    return preceding_w;
}


void test_16_empty() {
    char s1[] = "";
    char s2[] = "";

    char dest[40] = "";
    WordDescriptor word = find_preceding_word(s1, s2);

    wordDescriptorToString(word, dest);

    ASSERT_STRING("", dest);
}


void test_16_first_empty() {
    char s1[] = "";
    char s2[] = "word";

    char dest[40] = "";
    WordDescriptor word = find_preceding_word(s1, s2);

    wordDescriptorToString(word, dest);

    ASSERT_STRING("", dest);
}


void test_16_second_empty() {
    char s1[] = "i love";
    char s2[] = "";

    char dest[40] = "";
    WordDescriptor word = find_preceding_word(s1, s2);

    wordDescriptorToString(word, dest);

    ASSERT_STRING("", dest);
}


void test_16_not_in_string() {
    char s1[] = "i love python";
    char s2[] = "hate c";

    char dest[40] = "";
    WordDescriptor word = find_preceding_word(s1, s2);

    wordDescriptorToString(word, dest);

    ASSERT_STRING("", dest);
}


void test_16_first_in_string() {
    char s1[] = "i love python";
    char s2[] = "is love butterfly";

    char dest[40] = "";
    WordDescriptor word = find_preceding_word(s1, s2);

    wordDescriptorToString(word, dest);

    ASSERT_STRING("i", dest);
}


void test_16_find_preceding_word() {
    test_16_empty();
    test_16_first_empty();
    test_16_second_empty();
    test_16_not_in_string();
    test_16_first_in_string();
}

#endif //LABA17_FINDPRECEDINGWORD_H
