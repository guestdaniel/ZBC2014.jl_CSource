# ZBC2014.jl_CSource
This repository contains C source code and header files used to implement the Zilany, Bruce, and Carney (2014) auditory-nerve model.
They are stored here publicly to allow for compiled binaries to be generated for users when they download the [ZilanyBruceCarney2014.jl](https://github.com/guestdaniel/ZilanyBruceCarney2014.jl) package, which allows users to run the auditory-nerve model from Julia.

The files included here are modified versions of the original files, which are available on the [Carney lab website](https://www.urmc.rochester.edu/MediaLibraries/URMCMedia/labs/carney-lab/codes/Zilany-2014-Code-and-paper.zip) and based on this paper:

> Zilany, M. S. A., Bruce, I. C., & Carney, L. H. (2014). Updated parameters and expanded simulation options for a model of the auditory periphery. The Journal of the Acoustical Society of America, 135(1), 283–286. https://doi.org/10.1121/1.4837815

Code modifications were modest, being limited to:
  - Improvements in the consistency of formatting/style
  - Removal of Mex/MATLAB-specific code
  - Removal of callbacks to ffGn function (replaced with pointer to input array)
  - Addition of C1 and C2 filter outputs in `model_IHC` function (allows examination of "basilar membrane" stage of model)

This code is licensed under the GNU GPLv3 license.