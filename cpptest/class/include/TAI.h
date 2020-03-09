#ifndef TAI_H
#define TAI_H

#include "Time.h"

class TAI : public Time
{
public:
	TAI();
	~TAI();

private:
	enum {taiStart=1958};
};
#endif // TAI_H
