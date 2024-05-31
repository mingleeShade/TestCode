package main

import (
	"TestCode/go/panic_test/init_panic"
	"fmt"
)

func init() {
	fmt.Println("main.init")
}

func main() {
	fmt.Println("hello world!")
	init_panic.InitPanicPrint()
}
