#include "siggen.h"

/* generate sinusoid signal of specified frequency, amplitude, and phase */
void gen_sinusoid(
	const float freq,
	const float phase,
	const float amp,
	const int N,
	PLFLT *const sigx,
	PLFLT *const sigy)
{
	int n;
	float phase_rad, omega;
	/* calculate sinusoid paramters */
	omega = 2 * M_PI * freq;
	phase_rad = fmod(phase, 360) * M_PI / 180.0;
	/* generate sinusoid signal */
	for (n=0; n<N; ++n) {
		sigx[n] = n;
		sigy[n] = amp * cos((omega * n / N) + phase_rad);
	}
}

/* generate square signal of specified frequency, shift, and amplitude */
void gen_square(
	const float freq,
	const int shift,
	const float amp,
	const int N,
	PLFLT *const sigx,
	PLFLT *const sigy)
{
	int n, w;
	/* calculate square wave parameters */
	w = N / (2 * freq);
	/* generate square wave signal */
	for (n=0; n<N; ++n) {
		sigx[n] = n;
		sigy[n] = ((n / w) % 2) ? -amp : amp;
	}
}

/* generate ramp signal of specified given frequency, shift, and amplitude */
void gen_ramp(
	const float freq,
	const int shift,
	const float amp,
	const int N,
	PLFLT *const sigx,
	PLFLT *const sigy)
{
	int n, w;
	float scale;
	/* calculate ramp wave parameters */
	w = N / freq;
	scale = 2 * amp;
	/* generate ramp wave signal */
	for (n=0; n<N; ++n) {
		sigx[n] = n;
		sigy[n] = ((float)(n % w) / (float)(w - 1)) * scale - amp;
	}
}

/* generate impulse signal of given shift and amplitude */
void gen_impulse(
	const int shift,
	const float amp,
	const int N,
	PLFLT *const sigx,
	PLFLT *const sigy)
{
	int n;
	/* generate impulse wave signal */
	for (n=0; n<N; ++n) {
		sigx[n] = n;
		sigy[n] = 0;
	}
	sigy[shift] = amp;
}

/* plot data using plplot */
void plot(
	const char *const title,
	const PLFLT amp,
	const PLINT N,
	const PLFLT *const sigx,
	const PLFLT *const sigy)
{
	float margin = amp * 0.1;
	plsdev("xwin");
	plinit();
	plenv(0, N, -amp - margin, amp + margin, 0, 0);
	pllab("samples", "amplitude", title);
	plline(N, sigx, sigy);
	plend();
}
