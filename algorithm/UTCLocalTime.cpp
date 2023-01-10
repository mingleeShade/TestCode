#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <unordered_map>
#include <string>
using namespace std;


time_t sec() {
    time_t t = time(NULL);
    return t;
}
time_t LocalSec(time_t now)
{
    uint64_t m_nTimeZone = 8 * 60 * 60;
    if (now == 0) {
        return sec() + m_nTimeZone;
    }
    return now + m_nTimeZone; 
}

uint32_t GetUTCLocalWeek(time_t now, uint32_t benchmark_)
{
    time_t nowSec = 259200 + LocalSec(now) - benchmark_;
    uint32_t utcWeek = nowSec / (86400 * 7) + 1;
    return utcWeek;
}

int main()
{
    time_t now;
    cout << "Please input now second: ";
    cin >> now;
    cout << "UTCweek: " << GetUTCLocalWeek(now, 0) << endl;
    return 0;
}
