package animal

var (
	a Animal
)

func init() {
	a = Animal{}
}

type Dog struct {
	name string
}

func (d *Dog) WangWang() {
	a.hahaha()
}

func TTT() {
	a.hahaha()
}
