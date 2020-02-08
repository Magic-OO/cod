/* Marmote is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

Marmote is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with Marmote. If not, see <http://www.gnu.org/licenses/>.

Copyright 2015 Alain Jean-Marie, Jean-Michel Fourneau, Jean-Marc Vincent, Issam Rabhi */

#ifndef erlangDistribution_H
#define erlangDistribution_H

#include "gamma_distribution.h"

/**
 * @brief The general template distribution to be instantiated
 *
 */
class ErlangDistribution : public virtual GammaDistribution {

public:
  /**
   * @brief Constructor for the Erlang distribution from its shape and rate parameters.
   * The mean is calculated at creation.
   * @author	Alain Jean-Marie
   * @param phases the number of phases (the shape parameter for Gamma distributions)
   * @param scale the scale parameter (the scale parameter for Gamma distributions)
   * @return	an object of type ErlangDistribution
   */
  ErlangDistribution( int phases, double scale );

private:
  // private variables specific to the distribution
  int phases_;
  
public:
  // accessors to specific variables
  int phases() { return phases_; }
  
public: 
  // probabilistic member functions
  /**
   * @copydoc Distribution::Mean()
   */
  double	Mean();
  /**
   * @copydoc Distribution::Rate()
   */
  double	Rate(); 
  /**
   * These distributions always have a moment.
   */
  double	Moment( int order );
  /**
   * @copydoc Distribution::Variance()
   */
  double	Variance();
  /**
   * @copydoc Distribution::Laplace(double)
   */
  double	Laplace( double s ); // Laplace transform at real points
  /**
   * @copydoc Distribution::DLaplace(double)
   */
  double	DLaplace( double s ); // derivative of the Laplace transform
  /**
   * @copydoc Distribution::Cdf()
   */
  double	Cdf( double x );
  /**
   * @copydoc Distribution::Ccdf()
   */
  double	Ccdf( double x );
  /**
   * @copydoc Distribution::HasMoment(int)
   */
  bool		HasMoment( int order ); 
  /**
   * @copydoc Distribution::Rescale(double)
   */
  ErlangDistribution *Rescale( double factor );
  /**
   * @copydoc Distribution::Copy()
   */
  ErlangDistribution *Copy();
  /**
   * @copydoc Distribution::Sample()
   */
  double	Sample();
  /**
   * @copydoc Distribution::IidSample()
   */
  void		IidSample( int n, double* s );

 public:
  /**
   * @copydoc Distribution::toString()
   */
  std::string toString();
  /**
   * @copydoc Distribution::Write(FILE*,int)
   */
  void Write( FILE *out, int mode );

};

#endif // templateDistribution_H
