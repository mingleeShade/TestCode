package main

import "fmt"

type DP struct {
	m map[int]string
}

var dp DP

func GetDP() DP {
	return dp
}

func main() {
	dp.m = make(map[int]string, 0)
	dp.m[1] = "test1"
	dp.m[2] = "test2"

	dpCpoy := GetDP()
	dpCpoy.m[1] = "other1"
	dpCpoy.m[3] = "other3"

	fmt.Println("dp: ", dp)
	fmt.Println("doCopy: ", dpCpoy)
}
