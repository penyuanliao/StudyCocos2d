
#include "cocos2d.h"

using namespace cocos2d;

class CustomClass : public Ref
{
public:
	CustomClass() {};
	virtual ~CustomClass(){};
	bool init() { return true; };
	CREATE_FUNC(CustomClass);

	bool HellWorld(const char* name);

};