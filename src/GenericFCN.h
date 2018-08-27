/**
 * $Date: 2014/09/29 09:04:07 $
 * $Revision: db831d4cfaf0 $
 * $Author: mezekus $
 * $Id: GenericFCN.h,v db831d4cfaf0 2014/09/29 09:04:07 mezekus $
 *
 * @file
 * @brief	Header file for generic function.
 */

#ifndef GENERICFCN_H
#define GENERICFCN_H


/**
 * Generic class from which all functions inherit.
 * That is why it defines only one method, the operator(),
 * which allows to call the function.
 *
 * @param x the vector of variables
 */

class GenericFCN

{
  private:

  protected:

  public:

	virtual std::vector<double> operator() ( const std::vector<double>& x ) const = 0;
	virtual ~GenericFCN () {};
};

#endif // GENERICFCN_H
