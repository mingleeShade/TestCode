package main

import (
	"context"
	"fmt"
)

// 测试类型断言

type Processor interface {
	GetApiName() string
	SimpleProcess(ctx context.Context, input string) (string, error)
}

type SimpleProcessor struct {
}

func (p *SimpleProcessor) GetApiName() string {
	return "SimpleProcessor"
}

func (p *SimpleProcessor) SimpleProcess(ctx context.Context, input string) (string, error) {
	return input, nil
}

type TValue struct {
	A int
	B string
}

func f(i interface{}) string {
	defer func() {
		if err := recover(); err != nil {
			fmt.Println("panic:", err)
		}
	}()
	s := i.(string)
	return s
}

func main() {
	var mp map[string]Processor
	mp = make(map[string]Processor)
	var p Processor
	p = &SimpleProcessor{}
	mp[p.GetApiName()] = p
	output, err := p.(*SimpleProcessor).SimpleProcess(context.Background(), "111")
	fmt.Println("output:", output, "err:", err)

	var t TValue
	t.A = 1
	t.B = "2"
	r := f(t) // 应该会 panic
	fmt.Println("r: ", r)
}
