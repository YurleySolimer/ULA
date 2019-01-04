#ifndef PROCESSOR_H
#define PROCESSOR_H

#include "component.h"

class Processor : public Component {

	int coresNum;
	int cache;
	float frequency;

public:
	Processor();
	~Processor();

	int getCoresNum();
	void setCoresNum(int coresNum);

	int getCache();
	void setCache(int cache);

	float getFrequency();
	void setFrequency(float frequency);

};

#endif //PROCESSOR_H
