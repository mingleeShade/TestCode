package main

import (
	"fmt"
	"time"
)

func main() {
	now := time.Now()
	fmt.Println("yeay: ", now.Year())
	fmt.Println("month: ", now.Month())
	fmt.Println("day: ", now.Day())
	fmt.Printf("WeekDay: %d\n", now.Weekday())
	fmt.Println("Hour: ", now.Hour())
}
