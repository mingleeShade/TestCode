package main

import "fmt"

func Func(fgs map[string]interface{}) ([]string, error) {
	fgKeys, ok := fgs["online"].([]string)
	if !ok {
		fmt.Println("not ok")
		return nil, nil
	}
	fmt.Println("ok")
	if len(fgKeys) == 0 {
		fgKeys = append(fgKeys, "test")
		fgs["online"] = fgKeys
		fmt.Println("empty slice")
	}
	return fgKeys, nil
}

func main() {
	fmt.Println("==== nil ====")
	Func(nil)
	fmt.Println("")

	fmt.Println("==== nil map ====")
	var fgs map[string]interface{}
	Func(fgs)
	fmt.Println("")

	fmt.Println("==== empty map ====")
	fgs = make(map[string]interface{})
	Func(fgs)
	fmt.Println("")

	fmt.Println("==== empty slice ====")
	fgs["online"] = make([]string, 0)
	Func(fgs)
	fmt.Println("")

	fmt.Println("==== slice ====")
	keys := []string{
		"one",
		"two",
	}
	fgs["online"] = keys
	Func(fgs)
	fmt.Println("")
}
