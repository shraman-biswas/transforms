#include "dft.h"

/* compute dft or idft of signal based on mode parameter */
void dft(
	const int mode,
	const int N,
	const PLFLT *const sig,
	PLFLT *const real,
	PLFLT *const imag)
{
	int k, n;
	float PI_2 = 2 * M_PI;
	/* loop over N result data points */
	for (k=0; k<N; ++k) {
		/* clear initial real and imaginary data point */
		real[k] = 0;
		imag[k] = 0;
		/* loop over N input signal data points */
		for (n=0; n<N; ++n){
			/* calculate real and imaginary dft components */
			real[k] += sig[n] * cos(PI_2 * k * n / N);
			imag[k] += sig[n] * sin(PI_2 * k * n / N) * mode;
		}
		/* apply normalizing constant based on mode */
		real[k] /= (mode == -1) ? N : 1;
		imag[k] /= (mode == -1) ? N : 1;
	}
}

/* plot dft real and imaginary components */
void plot_real_imag(
	const PLFLT amp,
	const PLINT N,
	const PLFLT *const x,
	const PLFLT *const real,
	const PLFLT *const imag)
{
	/* setup plplot */
	plsdev("xwin");
	plinit();
	plssub(1, 2);
	/* plot dft real component */
	plenv(0, N, -amp, amp, 0, 0);
	pllab("k", "real", "discrete fourier transform - real and imaginary");
	plline(N, x, real);
	/* plot dft imaginary component */
	pladv(1);
	plenv(0, N, -amp, amp, 0, 0);
	pllab("k", "imaginary", "");
	plline(N, x, imag);
	/* end plplot */
	plend();
}

/* compute and plot dft magnitude and phase components */
void plot_mag_phase(
	const PLFLT amp,
	const PLINT N,
	const PLFLT *const x,
	const PLFLT *const real,
	const PLFLT *const imag)
{
	int n;
	float degrees = 180.0 / M_PI;
	/* allocate memory for magnitude and phase dft components */
	PLFLT *mag = (PLFLT *)calloc(N, sizeof(PLFLT));
	PLFLT *phase = (PLFLT *)calloc(N, sizeof(PLFLT));
	/* compute magnitude and phase from real and imaginary dft components */
	for (n=0; n<N; ++n) {
		mag[n] = 20.0 * log10(sqrt(real[n] * real[n] + imag[n] * imag[n]));
		phase[n] = fmod(atan2(imag[n], real[n] + 1e-3) * degrees, 180.0);
	}
	/* setup plplot */
	plsdev("xwin");
	plinit();
	plssub(1, 2);
	/* plot dft magnitude component */
	plenv(0, N, -25, 0, 0, 0);
	pllab("k", "magnitude (dB)", "discrete fourier transform - magnitude and phase");
	plline(N, x, mag);
	/* plot dft phase component */
	pladv(1);
	plenv(0, N, -180, 180, 0, 0);
	pllab("k", "phase (degrees)", "");
	plline(N, x, phase);
	/* end plplot */
	plend();
	/* free memory */
	free(mag);
	free(phase);
}
