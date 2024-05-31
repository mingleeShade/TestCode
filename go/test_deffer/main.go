package main

import "fmt"

func TestFunc() func() {
	fmt.Println("Enter TestFunc")

	return func() {
		fmt.Println("Return func()")
	}
}

func main() {
	fmt.Println("Main begin")
	defer TestFunc()()
	fmt.Println("Main End")
}
