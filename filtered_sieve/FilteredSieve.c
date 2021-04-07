#include <stdlib.h>
#include <stdio.h>

#include "FilteredSieve.h"

struct FilteredSieve {
    size_t maximumNumber;
};

struct FilteredSieve * filteredSieve(size_t maximumNumber) {
    struct FilteredSieve *self = malloc(sizeof(struct FilteredSieve));
    if (self == 0) {
        fprintf(stderr, "Out of memory");
        exit(1);
    }
    self->maximumNumber = maximumNumber;
}
