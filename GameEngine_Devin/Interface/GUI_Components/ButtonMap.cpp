#include "ButtonMap.h"

std::map<std::string, Button*>& ButtonMap::GetMap()
{
	// // O: insert return statement here
	static std::map<std::string, Button*> map;
	return map;
}
