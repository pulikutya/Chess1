#include "main.h"
#pragma once
#define foreach(type, var, iterable) {(iterable).iter_reset();(iterable).iter_next();} for(type var = *(iterable).iter; (iterable).iter_next(); var = *(iterable).iter)