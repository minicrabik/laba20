
#ifndef LABA17_REPLACEWORDTOWORD_H
#define LABA17_REPLACEWORDTOWORD_H

#include "../string_.h"

int compare(char* lhs, char* rhs, size_t size) {
    size_t i = 0;
    while (i != size && *lhs == *rhs) {
        i++;
        lhs++;
        rhs++;
    }

    if (i == size)
        return 1;
    return 0;
}



void replace(char* source, char* w1, char* w2) {
    size_t w1_size = strlen_(w1);
    size_t w2_size = strlen_(w2);

    WordDescriptor word1 = {w1, w1 + w1_size};
    WordDescriptor word2 = {w2, w2 + w2_size};

    char *read_ptr;
    char *rec_ptr;

    if (w1_size >= w2_size) {
        read_ptr = source;
        rec_ptr = source;
    } else {
        copy(source, getEndOfString(source), _string_buffer);
        read_ptr = _string_buffer;
        rec_ptr = source;
    }

    while (*read_ptr != '\0') {
        if (compare(read_ptr, word1.begin, word1.end - word1.begin)) {
            copy(word2.begin, word2.end, rec_ptr);
            rec_ptr += word2.end - word2.begin;
            read_ptr += word1.end - word1.begin;
        } else {
            *rec_ptr = *read_ptr;
            rec_ptr++;
            read_ptr++;
        }
    }

    *rec_ptr = '\0';

    freeString(_string_buffer);
}


void test_5_empty() {
    char source[] = "";
    char w1[] = "word";
    char w2[] = "ground";

    replace(source, w1, w2);

    ASSERT_STRING("", source);
}


void test_5_word_not_in_string() {
    char source[] = "hello world";
    char w1[] = "dad";
    char w2[] = "bread";

    replace(source, w1, w2);

    ASSERT_STRING("hello world", source);
}


void test_5_word_equal_length() {
    char source[] = "hello world";
    char w1[] = "world";
    char w2[] = "bread";

    replace(source, w1, w2);

    ASSERT_STRING("hello bread", source);
}


void test_5_word_different_length() {
    char source[] = "hello world";
    char w1[] = "world";
    char w2[] = "word";

    replace(source, w1, w2);

    ASSERT_STRING("hello word", source);
}


void test_5_word_different_length_2() {
    char source[] = "hello world";
    char w1[] = "world";
    char w2[] = "different";

    replace(source, w1, w2);

    ASSERT_STRING("hello different", source);
}


void test_5_replace_word_to_word() {
    test_5_empty();
    test_5_word_not_in_string();
    test_5_word_equal_length();
    test_5_word_different_length();
    test_5_word_different_length_2();
}

#endif //LABA17_REPLACEWORDTOWORD_H
