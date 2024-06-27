package main

import (
	"fmt"
	"time"
)

func main() {
	loc := time.Local
	fmt.Printf("TZ=%v\n", *loc)
	var t = time.Now()
	fmt.Printf("TZ=%v\n", *t.Location())

	t2 := time.Date(t.Year(), t.Month(), t.Day(), t.Hour(), 0, 0, 0, loc)
	name, offset := t2.Zone()
	fmt.Printf("t2: %v, zone name: %s, offset: %d\n", t2, name, offset)

}
