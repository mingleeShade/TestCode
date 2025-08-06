package main

import "fmt"

func main() {

	f := func() {
		println("f: ")
	}
	for i := 0; i < 3; i++ {
		// 循环内 defer 函数的参数在循环开始时就已经确定了，所以这里的 i 始终为 3
		{
			defer func() {
				println("defer: ", i)
			}()
		}
		fmt.Println("cycle: ", i)
	}

	println("main")
}
