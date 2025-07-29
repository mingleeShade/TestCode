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

func main() {
	var mp map[string]Processor
	var p Processor
	p = &SimpleProcessor{}
	mp[p.GetApiName()] = p
	output, err := p.(*SimpleProcessor).SimpleProcess(context.Background(), "111")
	fmt.Println("output:", output, "err:", err)
}
