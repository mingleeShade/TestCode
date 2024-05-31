package main

import (
	"encoding/json"
	"fmt"
	"os"
)

type TestStruct struct {
	Int1  int   `json:"int1" default:10`
	Bool2 bool  `json:"bool2"`
	Bool3 *bool `json:"bool3,omitempty"`
}

func main() {
	var t = TestStruct{Int1: 10, Bool2: true}
	resultByte, err := json.Marshal(&t)
	if err != nil {
		fmt.Errorf("serialize struct fail")
		os.Exit(1)
	}

	fmt.Printf("Result: %s\n", resultByte)

	var t2 TestStruct
	b2 := []byte(`{"int1":2333}`)
	json.Unmarshal(b2, &t2)
	fmt.Printf("t2: %v\n", t2)

	t2.Bool3 = new(bool)
	*t2.Bool3 = false
	b3, err := json.Marshal(t2)
	fmt.Printf("b3: %s\n", b3)
}
