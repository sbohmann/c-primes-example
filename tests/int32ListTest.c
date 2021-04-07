#include <stdio.h>
#include <stdlib.h>

#import "int32list.h"

static int32_t expectedValue = 0;

static void checkValue(int32_t value, void *context) {
    if (value != expectedValue) {
        fprintf(stderr, "%d != expected value %d", value, expectedValue);
        exit(1);
    }
    ++expectedValue;
}

int main() {
    struct Int32List *list = Int32List_create();
    for (int32_t value = 0; value < 1000; ++value) {
        Int32List_add(list, value);
    }
    Int32List_forEach(list, 0, checkValue);
    Int32List_delete(list);
    int nextExpectedValue = 1000;
    if (expectedValue != nextExpectedValue) {
        fprintf(stderr, "next expected value %d != expected value %d", expectedValue, nextExpectedValue);
        exit(1);
    }
    return 0;
}
