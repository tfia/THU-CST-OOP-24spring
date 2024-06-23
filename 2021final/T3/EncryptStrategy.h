#pragma once
# include <string>
#include <algorithm>

class EncryptStrategy{
public:
	virtual std::string encode(std::string mes) = 0;
};

class InsertStrategy : public EncryptStrategy
{
public:
	std::string encode(std::string mes) override
	{
		std::string res;
		for(auto & it : mes)
		{
			res.push_back(it);
			res.push_back('#');
		}
		return res;
	}
};

class InvertStrategy : public EncryptStrategy
{
public:
	std::string encode(std::string mes) override
	{
		std::reverse(mes.begin(), mes.end());
		return mes;
	}
};