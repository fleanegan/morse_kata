//
// Created by fschlute on 1/31/22.
//

#ifndef TEST_MORSE_H
#define TEST_MORSE_H
#include <string.h>
#include <limits.h>
#include <stdlib.h>
#include <stdio.h>
#define MIN(a,b) (((a)<(b))?(a):(b))
char	*decodebits(char *in);
char	*translate(char *trimmed_in, int time_unit);
int is_valid_time_unit(char *in, int time_unit);
int		min_consecutive_char(char *in, int char_to_find);
#endif //TEST_MORSE_H
