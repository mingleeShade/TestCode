package main

import "fmt"

type TestStruct struct {
	A string
	B int
}

func DeferCode(t *TestStruct, err *error) {
	curErr := *err
	fmt.Printf("t: %+v, err: %s, err != nil: %v\n", t, curErr, curErr != nil)
}

func Test() {
	var a int
	defer func() {
		fmt.Println("last")
	}()
	defer func() {
		if a == 1 {
			// defer 的 return 只影响本 func
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

func TestDeferTime() {
	defer func() {
		fmt.Println("first push")
	}()

	if 1 == 1 {
		return
	}

	// 未 push 的 defer 不会执行
	defer func() {
		fmt.Println("after return")
	}()
}

func main() {
	var t = TestStruct{A: "1", B: 1}
	var err error
	defer DeferCode(&t, &err)
	t.A = "2"
	t.B = 2
	Test()
	TestDeferTime()
	err = fmt.Errorf("test error")
}
