#include "int32list.h"

#import <stdint.h>
#import <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct Int32List {
    int32_t *data;
    size_t size;
    size_t capacity;
};

struct Int32List * Int32List_create() {
    struct Int32List *instance = malloc(sizeof(struct Int32List));
    if (instance == 0) {
        fprintf(stderr, "Out of memory");
        exit(1);
    }
    const size_t initialSize = 32;
    instance->data = calloc(initialSize, sizeof(int32_t));
    instance->size = 0;
    instance->capacity = initialSize;
    return instance;
}

void Int32List_delete(struct Int32List *self) {
    free(self->data);
    free(self);
}

void Int32List_add(struct Int32List *self, int32_t value) {
    if (self->size == self->capacity) {
        size_t newCapacity = 2 * self->capacity;
        int32_t *newData = calloc(newCapacity, sizeof(int32_t));
        memcpy(newData, self->data, self->capacity * sizeof(int32_t));
        if (newData == 0) {
            fprintf(stderr, "Out of memory");
            exit(1);
        }
        free(self->data);
        self->data = newData;
        self->capacity = newCapacity;
    }
    self->data[self->size] = value;
    ++self->size;
}

void Int32List_forEach(
        struct Int32List *self,
        void *context,
        void (*action)(int32_t value, void *context)) {
    for (size_t index = 0; index < self->size; ++index) {
        action(self->data[index], context);
    }
}
