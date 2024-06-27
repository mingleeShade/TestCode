package animal

import "fmt"

type Animal struct {
	name string
}

func (a *Animal) hahaha() {
	fmt.Println("hahaha")
}
