#ifndef DFT_H
#define DFT_H

#include <math.h>
#include <stdio.h>

#include <plplot/plplot.h>

void dft(
	const int mode,
	const int N,
	const PLFLT *const sig,
	PLFLT *const real,
	PLFLT *const imag);
void plot_real_imag(
	const PLFLT amp,
	const PLINT N,
	const PLFLT *const x,
	const PLFLT *const real,
	const PLFLT *const imag);
void plot_mag_phase(
	const PLFLT amp,
	const PLINT N,
	const PLFLT *const x,
	const PLFLT *const real,
	const PLFLT *const imag);

#endif
