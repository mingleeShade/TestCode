package main

import (
	"fmt"
	"time"
)

func main() {
	for i := 0; i < 10; i++ {
		fmt.Println("cycle: ", i)
		time.Sleep(5 * time.Second)
	}
}
