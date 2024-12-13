/*
  This file is part of a variant of version 5.2 of the Zilany, Bruce, and Carney (2014)
  auditory-nerve model. Licensing information can be found below. See README.md for a list
  of changes made versus the original version, which is available at:
  https://www.urmc.rochester.edu/labs/carney/publications-code/auditory-models.aspx.


  Papers related to this code are cited below:

  Zilany, M. S., & Bruce, I. C. (2006). Modeling auditory-nerve responses for high sound 
  pressure levels in the normal and impaired auditory periphery. The Journal of the 
  Acoustical Society of America, 120(3), 1446-1466.

  * Zilany, M.S.A., Bruce, I.C., Nelson, P.C., and Carney, L.H. (2009). "A
  Phenomenological model of the synapse between the inner hair cell and auditory
  nerve : Long-term adaptation with power-law dynamics," Journal of the
  Acoustical Society of America 126(5): 2390-2412.
 
  Ibrahim, R. A., and Bruce, I. C. (2010). "Effects of peripheral tuning
  on the auditory nerve's representation of speech envelope and temporal fine
  structure cues," in The Neurophysiological Bases of Auditory Perception, eds.
  E. A. Lopez-Poveda and A. R. Palmer and R. Meddis, Springer, NY, pp. 429-438.

  Zilany, M.S.A., Bruce, I.C., Ibrahim, R.A., and Carney, L.H. (2013).
  "Improved parameters and expanded simulation options for a model of the
  auditory periphery," in Abstracts of the 36th ARO Midwinter Research Meeting.

  * Zilany, M. S., Bruce, I. C., & Carney, L. H. (2014). Updated parameters and expanded 
  simulation options for a model of the auditory periphery. The Journal of the Acoustical 
  Society of America, 135(1), 283-286.

  Please cite these papers marked with asterisks (*) if you publish any research results 
  obtained with this code or any modified versions of this code.


  Zilany, Bruce, Carney (2014) auditory-nerve model source code, Copyright (C) 2024 
    M. S. A. Zilany <msazilany@gmail.com> 
    Ian C. Bruce <ibruce@ieee.org> 
    Laurel H. Carney <laurel_carney@urmc.rochester.edu>
    Daniel R. Guest <dguest2@urmc.rochester.edu>

  This program is free software: you can redistribute it and/or modify it under the terms of
  the GNU Affero General Public License as published by the Free Software Foundation, either
  version 3 of the License, or (at your option) any later version.

  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; 
  without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. 
  See the GNU Affero General Public License for more details.

  You should have received a copy of the GNU Affero General Public License along with this
  program. If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef _COMPLEX_H
#define _COMPLEX_H

/* Structure of the complex */
struct __COMPLEX{ double x,y; };
/* structure COMPLEX same as __COMPLEX */
typedef struct __COMPLEX COMPLEX;

/* for below, X, Y are complex structures, and one is returned */

/* real part of the complex multiplication */
#define CMULTR(X,Y) ((X).x*(Y).x-(X).y*(Y).y)
/* image part of the complex multiplication */
#define CMULTI(X,Y) ((X).y*(Y).x+(X).x*(Y).y)
/* used in the Division : real part of the division */
#define CDRN(X,Y) ((X).x*(Y).x+(Y).y*(X).y)
/* used in the Division : image part of the division */
#define CDIN(X,Y) ((X).y*(Y).x-(X).x*(Y).y)
/* used in the Division : denumerator of the division */
#define CNORM(X) ((X).x*(X).x+(X).y*(X).y)
/* real part of the complex */
#define CREAL(X) (double((X).x))
/* conjunction value */
#define CONJG(z,X) {(z).x=(X).x;(z).y= -(X).y;}
/* conjunction value */
#define CONJ(X) {(X).y= -(X).y;}
/* muliply : z could not be same variable as X or Y, same rule for other Macro */
#define CMULT(z,X,Y) {(z).x=CMULTR((X),(Y));(z).y=CMULTI((X),(Y));}
/* division */
#define CDIV(z,X,Y){double d=CNORM(Y); (z).x=CDRN(X,Y)/d; (z).y=CDIN(X,Y)/d;}
/* addition */
#define CADD(z,X,Y) {(z).x=(X).x+(Y).x;(z).y=(X).y+(Y).y;}
/* subtraction */
#define CSUB(z,X,Y) {(z).x=(X).x-(Y).x;(z).y=(X).y-(Y).y;}
/* assign */
#define CLET(to,from) {(to).x=(from).x;(to).y=(from).y;}
/* abstract value(magnitude) */
#define CABS(X) sqrt((X).y*(X).y+(X).x*(X).x)
/* real to complex */
#define CMPLX(X,real,imag) {(X).x=(real);(X).y=(imag);}
/* multiply with real */
#define CTREAL(z,X,real) {(z).x=(X).x*(real);(z).y=(X).y*(real);}


/* implementation using function : for compatibility */
/* divide */
COMPLEX compdiv(COMPLEX ne,COMPLEX de);
/* this returns a complex number equal to exp(i*theta) */
COMPLEX compexp(double theta);
/* Multiply a complex number by a scalar */
COMPLEX compmult(double scalar,COMPLEX compnum);
/* Find the product of 2 complex numbers */
COMPLEX compprod(COMPLEX compnum1, COMPLEX compnum2);
/* add 2 complex numbers */
COMPLEX comp2sum(COMPLEX summand1, COMPLEX summand2);
/* add three complex numbers */
COMPLEX comp3sum(COMPLEX summand1, COMPLEX summand2, COMPLEX summand3);
/* subtraction: complexA - complexB */
COMPLEX compsubtract(COMPLEX complexA, COMPLEX complexB);
/* Get the real part of the complex */
double  REAL(COMPLEX compnum);/*{double(compnum.x);}; */
/* Get the imaginary part of the complex */
double IMAG(COMPLEX compnum);
/* Get the conjugate of the complex */
COMPLEX compconj(COMPLEX complexA);


#endif
