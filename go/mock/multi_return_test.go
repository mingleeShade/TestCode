package main

import (
	"fmt"

	"github.com/stretchr/testify/mock"
)

// MyInterface 定义一个接口
type MyInterface interface {
	GetData() string
}

// MockMyInterface 定义一个模拟结构体
type MockMyInterface struct {
	mock.Mock
}

// GetData 实现接口方法
func (m *MockMyInterface) GetData() string {
	args := m.Called()
	return args.String(0)
}

func main() {
	mockObj := new(MockMyInterface)

	// 设置多次调用的返回值
	mockObj.On("GetData").Return("first result")
	mockObj.On("GetData").Return("second result")
	mockObj.On("GetData").Return("third result")

	// 多次调用模拟函数
	fmt.Println(mockObj.GetData())
	fmt.Println(mockObj.GetData())
	fmt.Println(mockObj.GetData())
}
