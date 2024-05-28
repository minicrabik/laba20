#include <stdio.h>
#include <malloc.h>
#include <ctype.h>
#include "string_.h"

BagOfWords _bag = {.words = NULL, .size = 0};
BagOfWords _bag2 = {.words = NULL, .size = 0};

size_t strlen_(const char *begin) {
    char *end = begin;
    while (*end != '\0')
        end++;
    return end - begin;
}

char* find(char *begin, char *end, int ch) {
    while (begin != end && *begin != ch)
        begin++;
    return begin;
}

char* findNonSpace(char *begin) {
    while (begin != '\0' && isspace(*begin))
        begin++;
    return begin;
}

char* findSpace(char* begin) {
    while (*begin != '\0' && !isspace(*begin))
        begin++;

    return begin;
}

char* findNonSpaceReverse(char* r_begin, const char* r_end) {
    while (r_begin != r_end && isspace(*r_begin))
        r_begin--;
    return r_begin;
}

char* find_space_reverse(char* r_begin, const char* r_end) {
    while (r_begin != r_end && !isspace(*r_begin))
        r_begin--;
    return r_begin;
}

int strcmp(const char *lhs, const char *rhs){
    while (*lhs != '\0' && *rhs != '\0' && *lhs == *rhs) {
        lhs++;
        rhs++;
    }

    return *(const unsigned char*) lhs - *(const unsigned char*) rhs;
}

char* copy(const char* begin_source, const char* end_source, char* begin_destination) {
    while (begin_source != end_source) {
        *begin_destination = *begin_source;
        ++begin_source;
        ++begin_destination;
    }
    return begin_destination;
}

char* copyIf(const char* begin_source, const char* end_source, char* begin_destination, int (*f)(int)) {
    char* start = begin_source;

    while (start != end_source) {
        if (f(*start)) {
            *begin_destination = *start;
            begin_destination++;
        }

        start++;
    }

    return begin_destination;
}

char* copyIfReverse(const char* r_begin_source, const char* r_end_source, char* begin_destination, int (*f)(int)) {
    char* start = r_begin_source;

    while (start != r_end_source) {
        if (f(*start)) {
            *begin_destination = *start;
            begin_destination++;
        }

        start--;
    }

    return begin_destination;
}

char* getEndOfString(char* s) {
    char* start = s;
    while (*start != '\0')
        start++;

    return start;
}

void assert_string(const char* expected, char* got,
                   char const* file_name, char const* func_name,
                   int line) {
    if (strcmp(expected, got)) {
        fprintf(stderr, "File %s\n", file_name);
        fprintf(stderr, "%s - failed on line %d\n", func_name, line);
        fprintf(stderr, "Expected: \"%s\"\n", expected);
        fprintf(stderr, "Got: \"%s\"\n\n", got);
    } else
        fprintf(stderr, "%s - OK\n", func_name);
}

int getWord(char *beginSearch, WordDescriptor *word) {
    word->begin = findNonSpace(beginSearch);
    if (*word->begin == '\0')
        return 0;
    word->end = findSpace(word->begin);
    return 1;
}

void freeString(char* string) {
    char* ptr = string;
    while (*ptr) {
        *ptr = '\0';
        ptr++;
    }
}

void freeBag(BagOfWords* bag) {
    for (size_t i = 0; i < bag->size; i++) {
        bag->words[i].begin = NULL;
        bag->words[i].end = NULL;
    }

    bag->size = 0;
}

bool isPalindromeWord(WordDescriptor * word) {
    char* start = word->begin;
    char* end = word->end - 1;

    while (start < end) {
        if (*start != *end)
            return false;

        start++;
        end--;
    }

    return true;
}

bool getWordReverse(char* r_begin, char* r_end, WordDescriptor * word) {
    if (word->begin == r_end)
        return false;

    word->end = findNonSpaceReverse(r_begin, r_end);

    word->begin = find_space_reverse(r_begin, r_end);
    word->begin = word->begin == r_end ? word->begin : word->begin + 1;

    return true;
}

bool getWordWithoutSpace(char* begin_search, WordDescriptor * word) {
    word->begin = findNonSpace(begin_search);
    if (*word->begin == '\0')
        return false;

    word->end = findSpace(word->begin) - 1;

    return true;
}

void wordDescriptorToString(WordDescriptor word, char* dest) {
    if (word.begin == NULL && word.end == NULL)
        return;

    while (word.begin <= word.end) {
        *dest = *word.begin;
        word.begin++;
        dest++;
    }

    *dest = '\0';
}

bool isWordEqual(const WordDescriptor word1, const WordDescriptor word2) {
    char* begin1 = word1.begin;
    char* begin2 = word2.begin;

    while (begin1 < word1.end && begin2 < word2.end) {
        if (*begin1 != *begin2)
            return false;

        begin1++;
        begin2++;
    }

    if (word1.end - begin1 > 0 || word2.end - begin2 > 0)
        return false;

    return true;
}

bool get_word_without_space(char* begin_search, WordDescriptor * word) {
    word->begin = findNonSpace(begin_search);
    if (*word->begin == '\0')
        return false;

    word->end = findSpace(word->begin) - 1;

    return true;
}
