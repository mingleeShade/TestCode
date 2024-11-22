package main

import "fmt"

func Test() {
	var a int
	defer func() {
		fmt.Println("last")
	}()
	defer func() {
		if a == 1 {
			fmt.Println("a == 1")
			return
		}
		fmt.Println("a != 1")
	}()
	defer func() {
		fmt.Println("first")
	}()

	fmt.Println("Test()")
	a = 1
}

func main() {
	Test()
}
