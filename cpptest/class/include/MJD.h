#ifndef MJD_H
#define MJD_H

#include "Time.h"

class MJD : public Time
{
public:
	MJD();
	~MJD();

private:
	enum {mjdStart=1970};
};
#endif // MJD_H
