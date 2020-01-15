#include <time.h>
#include "DateTime.h"

std::string DateTime::month[12] = { "january", "february", "march", "april", "may", "june", "july", "august", "september",
		"october", "november", "december" };

std::string DateTime::weekdays[7] = { "sunday", "monday", "tuesday", "wednesday", "thursday", "friday", "saturday" };

DateTime::DateTime(unsigned int day, unsigned int month, unsigned int year) {
	time_t current = time(nullptr); //time(&current);
	tm_ = *localtime(&current);
	tm_.tm_mday = day;
	tm_.tm_mon = month - 1;
	tm_.tm_year = year - 1900;
	current = mktime(&tm_);
	tm_ = *localtime(&current);
}

DateTime::DateTime(const DateTime & datetime) {
	this->tm_ = datetime.tm_;
}

DateTime::DateTime() {
	time_t current = time(nullptr); //time(&current);
	tm_ = *localtime(&current);
}


std::string DateTime::toStringg(struct tm *time) {
	std::string today("");
	if (time->tm_mday < 10)	
		today += "0" + std::to_string(time->tm_mday);
	else 
		today += std::to_string(time->tm_mday);
	today += " " + month[time->tm_mon] + " " + std::to_string(time->tm_year + 1900) + ", " + weekdays[time->tm_wday];
	return today;
}

std::string DateTime::getToday() {
	return toStringg(&tm_);
}

std::string DateTime::getYesterday() {
	return getPast(1);
}

std::string DateTime::getTomorrow() {
	return getFuture(1);
}

std::string DateTime::getPast(unsigned int num) {
	tm newTm_ = tm_;
	newTm_.tm_mday -= num;
	time_t newTm_InSeconds = mktime(&newTm_);
	newTm_ = *localtime(&newTm_InSeconds);
	return toStringg(&newTm_);
}

std::string DateTime::getFuture(unsigned int num){
	tm newTm_ = tm_;
	newTm_.tm_mday += num;
	time_t newTm_InSeconds = mktime(&newTm_);
	newTm_ = *localtime(&newTm_InSeconds);
	return toStringg(&newTm_);
}

unsigned int DateTime::getDifference(DateTime & datetime) {
	unsigned long long difference = abs(mktime(&tm_) - mktime(&datetime.tm_));;
	return difference / (3600 * 24);
}