package main

import (
	"fmt"
	"time"

	"github.com/gorhill/cronexpr"
)

func main() {
	crontabExpr := fmt.Sprintf("CRON_TZ=%v 0 0 29 3 *", "Asia/Shanghai")
	nextTime := cronexpr.MustParse(crontabExpr).Next(time.Now())

	fmt.Println("nextTiem: ", nextTime)

}
