package main

import "fmt"

func main() {

	err := fmt.Errorf("hello world")
	fmt.Printf("err: %s\n", err)
}
