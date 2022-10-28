import time
import datetime

def get_cur_zero_time():
    localtime = time.localtime(time.time())
    d1 = datetime.datetime(localtime.tm_year, localtime.tm_mon, localtime.tm_mday, 0, 0, 0)
    print(d1.timestamp())
    return int(d1.timestamp())

def get_cur_timestamp():
    return int(time.time())

def get_timestamp_from_formatstr(datetime_str):
    time_array = time.strptime(datetime_str, "%Y-%m-%d %H:%M:%S")
    return int(time.mktime(time_array))

def get_time_diff_week(min_sec, max_sec):
    week_sec = 7 * 24 * 3600
    diff_sec = max_sec - min_sec
    return int(diff_sec / week_sec)

if __name__ == "__main__":
    get_cur_zero_time()

    print(get_cur_timestamp())
    begin_sec = get_timestamp_from_formatstr("2022-10-17 00:00:00")
    print(get_time_diff_week(begin_sec, get_cur_timestamp()))
