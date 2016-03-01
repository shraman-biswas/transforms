#ifndef MAIN_H
#define MAIN_H

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <plplot/plplot.h>

#include "dft/dft.h"
#include "siggen/siggen.h"

/* structure for parameter variables */
typedef struct __params_t {
	int shift;
	double freq, phase, amp;
	char name[100];
} params_t;

static void get_params(params_t *const p, int argc, char **argv);
static void gen_signal(
	params_t *const p,
	const int sigtype,
	const int N,
	PLFLT *const sigx,
	PLFLT *const sigy);

#endif
