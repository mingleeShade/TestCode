package main

import (
	"bytes"
	"fmt"
)

type Val struct {
	ID   int64
	Name string
}

func GetValAry() []*Val {
	ary := make([]*Val, 0)

	ary = append(ary, nil)
	ary = append(ary, &Val{
		ID:   10,
		Name: "sss",
	})
	ary = append(ary, &Val{
		ID:   11,
		Name: "str11",
	})
	return ary
}

func main() {
	ary := GetValAry()
	fmt.Printf("ary: %+v", ary)

	var buffer bytes.Buffer
	buffer.WriteString("[")
	for _, val := range ary {
		if val == nil {
			buffer.WriteString("nil, ")
		} else {
			buffer.WriteString(fmt.Sprintf("%v", *val))
			buffer.WriteString(", ")
		}
	}
	buffer.WriteString("]")
	fmt.Printf("ary: %s", buffer.String())
}
