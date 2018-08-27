/**
 * $Date: 2014/09/29 09:04:07 $
 * $Revision: db831d4cfaf0 $
 * $Author: mezekus $
 * $Id: ExternalFCN.h,v db831d4cfaf0 2014/09/29 09:04:07 mezekus $
 *
 * @file
 * @brief	Header file for external function.
 */

#ifndef EXTERNALFCN_H
#define EXTERNALFCN_H

#include <vector>

#include "GenericFCN.h"

class ExternalFCN : public GenericFCN
{
  private:
	int fN;
	std::vector<double> fX;
	double FCNval;

  protected:

  public:

	ExternalFCN ( const int& n, const std::vector<double>& x ) : fN(n), fX(x) {}
	virtual std::vector<double> operator() ( const std::vector<double>& x ) const;
	virtual ~ExternalFCN () {};

};

#endif // EXTERNALFCN_H
