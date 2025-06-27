package main

import "fmt"

func main() {
	idList := make([]int64, 0)
	idList = append(idList, 1)
	idList = append(idList, 2)
	idList = append(idList, 3)
	idList = append(idList, 4)
	idList = append(idList, 5)
	fmt.Println("[5:]", idList[5:])
	fmt.Println("[0:5]", idList[0:5])
	fmt.Println("[1:1]", idList[1:1])
	fmt.Println("[1:2]", idList[1:2])
	fmt.Println("[1:10]", idList[1:10])
	fmt.Println("[-1:2]", idList[1:2])
}
