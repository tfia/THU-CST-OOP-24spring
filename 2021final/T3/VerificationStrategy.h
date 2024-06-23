#pragma once
# include <string>

class VerificationStrategy{
public:
	virtual std::string verify(std::string mes) = 0;
};

class PrefixStrategy : public VerificationStrategy
{
public:
	std::string verify(std::string mes) override
	{
		std::string res;
		res.push_back(mes[0]);
		res.push_back(mes[1]);
		res.push_back(mes[2]);
		return res;
	}
};

class IntervalStrategy : public VerificationStrategy
{
public:
	std::string verify(std::string mes) override
	{
		std::string res;
		for(int i = 0; i <= (int)mes.size() - 1; i++)
		{
			if(i & 1) continue;
			res.push_back(mes[i]);
		}
		return res;
	}
};