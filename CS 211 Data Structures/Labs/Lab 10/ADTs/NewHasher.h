#ifndef NEW_HASHER_H
#define NEW_HASHER_H

#include "ADTs/HasherBase.h"
#include <string>
using namespace std;

//An example of a very bad hashing technique
class NewHasher : public HasherBase<string>
{
	virtual int getHash(const string &item, int mod_by)
	{
		int hash = 0;
		int count = 0;
		for (char ch : item)
		{
			//method 3:
			//hash += (ch * ch * ch);
			// method 2:
			//hash += hash + ch;
			// method 1:
			hash += (ch * ch) + hash;
		}
		return hash % mod_by;
	}

};
#endif
#pragma once