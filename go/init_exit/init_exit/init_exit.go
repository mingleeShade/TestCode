package init_exit

import (
	"fmt"
	"os"
)

func init() {
	fmt.Println("before exit")
	os.Exit(0)
}

func Print() {
	fmt.Println("hello")
}
