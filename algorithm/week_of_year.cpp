#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <unordered_map>
#include <string>
#include <cstdint>
using namespace std;

enum
{
    MINUTE_SECONDS = 60,                        // 分钟的秒数
    HOUR_SECONDS = MINUTE_SECONDS * 60,         // 小时的秒数
    DAY_SECONDS = HOUR_SECONDS * 24,            // 一天的秒数
    WEEK_SECONDS = 7 * DAY_SECONDS,             // 一周的秒数
    DAILY_RESET_HOUR_DIFF = 5,
};

time_t sec() {
    time_t t = time(NULL);
    return t;
}

time_t getTimeByFormatStr(const std::string& strTime)
{
    struct tm tmp = {0};

    return ::strptime(strTime.c_str(), "%Y-%m-%d_%H:%M:%S", &tmp) ? ::mktime(&tmp) : 0;
}

uint32_t getWeekNo(time_t tm_, uint32_t benchmark_ = 5 * HOUR_SECONDS)
{
    tm_ = (tm_ == 0) ? sec() : tm_;
    tm_ -= benchmark_;
    struct tm tmVal = { 0 };
    ::localtime_r(&tm_, &tmVal);
    tmVal.tm_hour = tmVal.tm_min = tmVal.tm_sec = 0;
    tm_ = ::mktime(&tmVal);
    int dwWeekNo = (tmVal.tm_wday == 0) ? 7 : tmVal.tm_wday;
    tm_ = tm_ - (dwWeekNo - 1) * DAY_SECONDS;
    char buf[5];
    struct tm tm {};
    ::strftime(buf, 5, "%U", ::localtime_r(&tm_, &tm));
    return atoi(buf) + 1;
}

int main()
{
    while (true) {
        string date1;
        std::cout << "Please input date (like 2010-10-10_00:10:01), empty to exit:";
        std::cin >> date1;
        if (date1.empty()) {
            break;
        }
        time_t t = getTimeByFormatStr(date1);
        int weekno = getWeekNo(t);
        std::cout << "The week number in yeay of date[" << date1 << "] is:" << weekno << std::endl;
    }
    return 0;
}
