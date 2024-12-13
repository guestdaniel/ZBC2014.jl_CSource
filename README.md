# ZBC2014.jl_CSource

## About
This repository contains C source code and header files used to implement the Zilany, Bruce, and Carney (2014) auditory-nerve model.
They are stored here publicly to allow for compiled binaries to be generated for users when they download the [ZilanyBruceCarney2014.jl](https://github.com/guestdaniel/ZilanyBruceCarney2014.jl) package, which allows users to run the auditory-nerve model from Julia.

The files included here are modified versions of the original files, which are available on the [Carney lab website](https://www.urmc.rochester.edu/MediaLibraries/URMCMedia/labs/carney-lab/codes/Zilany-2014-Code-and-paper.zip) and based on this paper:

```
Zilany, M. S. A., Bruce, I. C., & Carney, L. H. (2014). Updated parameters and expanded simulation options for a model of the auditory periphery. The Journal of the Acoustical Society of America, 135(1), 283–286. https://doi.org/10.1121/1.4837815
```

Code modifications were minor, being limited to:
  - Improvements in the consistency of formatting/style
  - Removal of Mex/MATLAB-specific code
  - Removal of callbacks to `ffGn` function (replaced with pointer to input array to be provided by wrapper function — refer to the original source code for an example of how to implement this function in MATLAB, or ZilanyBruceCarney2014.jl for an example of how to implement this function in Julia)
  - Addition of C1 and C2 filter outputs in `model_IHC` function (allows examination of "basilar membrane" stage of model)

## License
This code is licensed under the GNU AGPLv3 license (see the text of the license in `LICENSE`).
The original code, as of publication of this repository, is unlicensed.
Relevant portions of an email chain authorizing release of this modified derivative code under the GNU AGPL license is provided in the file `license_change.txt`.