#include <stdio.h>
#include <stdlib.h>

#import "int32list.h"

static int32_t expectedValue = 0;

static void checkValue(int32_t value, void *context) {
    if (value != expectedValue) {
        fprintf(stderr, "%d != expected value %d", value, expectedValue);
        exit(1);
    }
}

int main() {
    struct Int32List *list = Int32List_create();
    for (int32_t value = 0; value < 1000; ++value) {
        Int32List_add(list, value);
    }
    Int32List_forEach(list, 0, checkValue);
    Int32List_delete(list);
    return 0;
}
