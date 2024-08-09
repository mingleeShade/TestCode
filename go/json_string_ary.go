package main

import (
	"encoding/json"
	"fmt"
)

type Test struct {
	Str string   `json:"str,string"`
	Ary []string `json:"ary"`
}

func main() {
	var t Test
	content := "{\"str\": \"xxx\", \"ary\":[\"lihaiming\"]}"
	err := json.Unmarshal([]byte(content), &t)
	if err != nil {
		fmt.Println("error", err)
	}

	fmt.Println("struct: ", t)
}
