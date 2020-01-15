#pragma once
#include <string>

class DateTime {
private:
	//time_t current;
	struct tm tm_;

	static std::string month[];
	static std::string weekdays[];
public:
	DateTime(unsigned int, unsigned int, unsigned int);
	DateTime(const DateTime &);
	DateTime();
	std::string getToday();
	std::string getYesterday();
	std::string getTomorrow();
	std::string getFuture(unsigned int);
	std::string getPast(unsigned int);
	unsigned int getDifference(DateTime &);
	std::string toStringg(struct tm *time);
};
