#include "main.h"

int main(int argc, char **argv)
{
	printf("[ transforms ]\n");

	const int N=100;
	int sigtype;
	PLFLT *sigx=NULL, *sigy=NULL, *real=NULL, *imag=NULL;
	params_t p;

	/* generate signal */
	sigx = (PLFLT *)calloc(N, sizeof(PLFLT));
	sigy = (PLFLT *)calloc(N, sizeof(PLFLT));

	/* get signal type */
	sigtype = (argc > 1) ? atoi(argv[1]) : 1;
	sigtype = ((sigtype >= 0) && (sigtype <= 4)) ? sigtype : 1;

	/* get parameters for signal generation */
	get_params(&p, argc, argv);

	/* generate specified signal */
	gen_signal(&p, sigtype, N, sigx, sigy);

	/* plot signal */
	printf("plotting signal: %s\n", p.name);
	plot(p.name, p.amp, N, sigx, sigy);

	/* compute dft with real and imaginary components */
	real = (PLFLT *)calloc(N, sizeof(PLFLT));
	imag = (PLFLT *)calloc(N, sizeof(PLFLT));
	printf("computing dft");
	dft(-1, N, sigy, real, imag);

	/* plot dft components  */
	printf("plotting dft real and imaginary components\n");
	plot_real_imag(p.amp, N, sigx, real, imag);
	printf("plotting dft magnitude and phase components\n");
	plot_mag_phase(p.amp, N, sigx, real, imag);

	/* free generated data */
	free(sigx);
	free(sigy);

	return EXIT_SUCCESS;
}

/* gets the signal generation parameters from the commandline arguments */
static void get_params(params_t *const p, int argc, char **argv)
{
	p->freq = 10.0;
	p->phase = 0.0;
	p->shift = 0;
	p->amp = 1.0;
	switch (argc) {
	case 5:
		p->amp = atof(argv[4]);
	case 4:
		p->phase = atof(argv[3]);
		p->shift = atoi(argv[3]);
	case 3:
		p->freq = atof(argv[2]);
	}
}

static void gen_signal(
	params_t *const p,
	const int sigtype,
	const int N,
	PLFLT *const sigx,
	PLFLT *const sigy)
{
	switch (sigtype) {
	/* generate sinusoid */
	case 1:
		strcpy(p->name, "sinusoid");
		printf("generating sinusoid signal\n"
			"frequency:\t%.2f\tHz\n"
			"phase:\t\t%.2f\tdegrees\n"
			"amplitude:\t%.2f\n",
			p->freq, p->phase, p->amp);
		/* set frequency, phase, and amplitude */
		gen_sinusoid(p->freq, p->phase, p->amp, N, sigx, sigy);
		break;
	/* generate square wave */
	case 2:
		strcpy(p->name, "square");
		printf("generating sinusoid signal\n"
				"frequency:\t%.2f\tHz\n"
				"shift:\t\t%d\n"
				"amplitude:\t%.2f\n",
				p->freq, p->shift, p->amp);
		/* set frequency, shift, and amplitude */
		gen_square(p->freq, p->shift, p->amp, N, sigx, sigy);
		break;
	/* generate ramp wave */
	case 3:
		strcpy(p->name, "ramp");
		printf("generating sinusoid signal\n"
				"frequency:\t%.2f\tHz\n"
				"shift:\t\t%d\n"
				"amplitude:\t%.2f\n",
				p->freq, p->shift, p->amp);
		/* set frequency, shift, and amplitude */
		gen_ramp(p->freq, p->shift, p->amp, N, sigx, sigy);
		break;
	/* generate impulse wave */
	case 4:
		strcpy(p->name, "impulse");
		printf("generating impulse signal\n"
				"shift:\t\t%d\n"
				"amplitude:\t%.2f\n",
				p->shift, p->amp);
		/* set shift and amplitude */
		gen_impulse(p->shift, p->amp, N, sigx, sigy);
		break;
	}
}
