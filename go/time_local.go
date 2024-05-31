package main

import (
	"fmt"
	"time"
)

func main() {
	loc := time.Local
	fmt.Printf("TZ=%v\n", *loc)
}
