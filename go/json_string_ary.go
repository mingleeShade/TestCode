package main

import (
	"encoding/json"
	"fmt"
)

type Test struct {
	Ary []string `json:"ary"`
}

func main() {
	var t Test
	content := "{\"ary\":[\"lihaiming\"]}"
	err := json.Unmarshal([]byte(content), &t)
	if err != nil {
		fmt.Println("error", err)
	}

	fmt.Println("ary: ", t.Ary)
}
