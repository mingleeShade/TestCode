package main

import "fmt"

var testMap map[string]string
var testByteMap map[string][]byte

func VisitAll(f func(k, v string)) {
	for k, v := range testMap {
		f(k, v)
	}
}

func VisitAllByte(f func(k, v []byte)) {
	for k, v := range testMap {
	}
}

func main() {
	VisitAll(func(k, v string) {
		fmt.Println(k, v)
	})

	VisitAllByte(func(k, v []byte) {
		fmt.Println(k, v)
	})
}
