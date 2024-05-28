#ifndef LABA17_PRINTREVERSORDERED_H
#define LABA17_PRINTREVERSORDERED_H

#include "../string_.h"

void get_bag_of_words(BagOfWords* bag, char* s) {
    char* begin_search = s;
    bag->size = 0;

    while (getWord(begin_search, &bag->words[bag->size])) {
        begin_search = bag->words[bag->size].end;

        bag->size++;
    }
}


void print_word_1(WordDescriptor word) {
    while (word.begin != word.end) {
        printf("%c", *word.begin);
        word.begin++;
    }
    printf(" ");
}


void print_reverse_ordered(char* s) {
    get_bag_of_words(&_bag, s);

    if (_bag.size >= 1)
        for (int i = (int) _bag.size - 1; i >= 0; i--)
            print_word_1(_bag.words[i]);

    printf("\n");

    free_bag(&_bag);
}


void test_7_empty() {
    char s[] = "";
    print_reverse_ordered(s);
}


void test_7_one_word() {
    char s[] = "word";
    print_reverse_ordered(s);
}


void test_7_only_letters() {
    char s[] = "w o r";
    print_reverse_ordered(s);
}


void test_7_more_word() {
    char s[] = "i love python";
    print_reverse_ordered(s);
}


void test_7_print_reverse_ordered() {
    printf("Test 7: \n");
    test_7_empty();
    test_7_one_word();
    test_7_only_letters();
    test_7_more_word();
    printf("\n");
}

#endif //LABA17_PRINTREVERSORDERED_H
