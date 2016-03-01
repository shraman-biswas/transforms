#ifndef SIGGEN_H
#define SIGGEN_H

#include <math.h>
#include <stdio.h>

#include <plplot/plplot.h>

void gen_sinusoid(
	const float freq,
	const float phase,
	const float amp,
	const int N,
	PLFLT *const sigx,
	PLFLT *const sigy);
void gen_square(
	const float freq,
	const int shift,
	const float amp,
	const int N,
	PLFLT *const sigx,
	PLFLT *const sigy);
void gen_ramp(
	const float freq,
	const int shift,
	const float amp,
	const int N,
	PLFLT *const sigx,
	PLFLT *const sigy);
void gen_impulse(
	const int shift,
	const float amp,
	const int N,
	PLFLT *const sigx,
	PLFLT *const sigy);
void plot(
	const char *const title,
	const PLFLT amp,
	const PLINT N,
	const PLFLT *const sigx,
	const PLFLT *const sigy);

#endif
