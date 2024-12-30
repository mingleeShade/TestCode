package main

import "fmt"

func TestPanicAndDeffer() {
	defer func() {
		fmt.Println("deffer")
	}()
	panic(fmt.Errorf("test panic"))
}

func main() {
	defer func() {
		if r := recover(); r != nil {
			fmt.Println("recover, panic %v", r)
		}
	}()
	TestPanicAndDeffer()
}
