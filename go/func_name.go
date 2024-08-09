package main

import "fmt"

type TFunc func(a int) error

func A(a int) error {
	fmt.Println("func a")
	return nil
}

func B(a int) error {
	fmt.Println("func b")
	return nil
}

var funcList = []TFunc{
	A,
	B,
}

func main() {
	for _, f := range funcList {
		f(1)
		fmt.Printf("funcname :%v\n", f)
	}
}
