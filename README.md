Transforms
==========

A Discrete Fourier Transform (DFT) implementation with signal generation and plotting.  
DFT results are produced and plotted in terms of real and imaginary components.  
DFT magnitude and phase components are also calculated and plotted.  
Signal generation produces specified signal type with specified parameters.  
Generated signal is plotted as well.  
Uses the PLplot C library for plotting.

Signal generation features:
* sinusoid generation
* square wave generation
* ramp wave generation
* impulse signal generation
* plotting helper function

Signal generation parameters:
* frequency (Hz)
* phase (degrees)
* amplitude
* shift (for non-sinusoids)

Discrete Fourier Transform (DFT) features:
* DFT / IDFT calculation
* Real and imaginary component plotting
* Magnitude and phase component plotting

Discrete Fourier Transform (DFT) parameters:
* mode selection (DFT or IDFT)
* number of input data points (N)
* input signal data (N points)
* DFT real component result
* DFT imaginary component result
