package init_panic

import "fmt"

func init() {
	fmt.Println("init_panic.init()")
	panic("init_panic")
}

func InitPanicPrint() {
	fmt.Println("init panic!")
}
