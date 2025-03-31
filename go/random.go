package main

import (
	"fmt"
	"math/rand"
)

func R() {
	fmt.Println(rand.Intn(100))
}

func main() {
	R()
	R()
	R()
	R()
	R()
}
