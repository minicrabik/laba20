#ifndef LABA19_STRING_H
#define LABA19_STRING_H

#ifndef LABA17_STRING__H
#define LABA17_STRING__H

#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include <ctype.h>

#define ASSERT_STRING(expected, got) assert_string(expected, got, __FILE__, __FUNCTION__, __LINE__)

#define MAX_WORD_SIZE 30
#define MAX_N_WORDS_IN_STRING 100
#define MAX_STRING_SIZE 200

typedef struct WordDescriptor {
    char* begin;
    char* end;
} WordDescriptor;

typedef struct BagOfWords {
    WordDescriptor words[MAX_N_WORDS_IN_STRING];
    size_t size;
} BagOfWords;

extern BagOfWords _bag;
extern BagOfWords _bag2;

extern char _string_buffer[MAX_STRING_SIZE + 1];

size_t strlen_(const char *begin);

char* find(char *begin, char *end, int ch);

char* findNonSpace(char *begin);

char* findSpace(char *begin);

char* findNonSpaceReverse(char *rbegin, const char *rend);

char* findSpaceReverse(char *rbegin, const char *rend);

int strcmp(const char *lhs, const char *rhs);

char* copy(const char *beginSource, const char *endSource, char *beginDestination);

char* copyIf(char *beginSource, const char *endSource, char *beginDestination, int (*f)(int));

char* copyIfReverse(char *rbeginSource, const char *rendSource, char *beginDestination, int (*f)(int));

char* getEndOfString(char* s);

void assert_string(const char* expected, char* got,
                   char const* file_name, char const* func_name,
                   int line);

int getWord(char *beginSearch, WordDescriptor *word);

void freeString(char* string);

void free_bag(BagOfWords* bag);

bool isPalindromeWord(WordDescriptor * word);

bool getWordReverse(char* r_begin, char* r_end, WordDescriptor * word);

bool getWordWithoutSpace(char* begin_search, WordDescriptor * word);

void wordDescriptorToString(WordDescriptor word, char* dest);

bool isWordEqual(const WordDescriptor word1, const WordDescriptor word2);

bool get_word_without_space(char* begin_search, WordDescriptor * word);

#endif //LABA17_STRING__H

#endif //LABA19_STRING_H
