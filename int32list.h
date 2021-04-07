#pragma once

#import <stdint.h>

struct Int32List;

struct Int32List * Int32List_create();

void Int32List_delete(struct Int32List *self);

void Int32List_add(struct Int32List *self, int32_t value);

void Int32List_forEach(struct Int32List *self,
                       void *context,
                       void (*action)(int32_t value, void *context));
