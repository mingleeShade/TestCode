package main

import "fmt"

type FilterCondition struct {
	Cond    string
	Filters []interface{}
}

func TFunc(f FilterCondition) {
	fmt.Println(f)
}

func GetCondition() FilterCondition {
	filter := []int64{
		1, 2, 4,
	}

	f := FilterCondition{
		Cond: "id = ?",
	}
	f.Filters = make([]interface{}, len(filter))
	for i, a := range filter {
		f.Filters[i] = a
	}
	return f
}

func main() {
	TFunc(GetCondition())
}
