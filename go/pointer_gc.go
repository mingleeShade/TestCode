package main

import (
	"fmt"
	"os"
	"runtime"
	"time"
)

type ItemInfo struct {
	Version          *int64  `protobuf:"varint,1,opt,name=Version" json:"Version,omitempty"`
	UserETag         *string `protobuf:"bytes,2,opt,name=UserETag" json:"UserETag,omitempty"`
	DataETag         *string `protobuf:"bytes,3,opt,name=DataETag" json:"DataETag,omitempty"`
	XXX_unrecognized []byte  `json:"-"`
}

func main() {
	const N = 30e5
	if len(os.Args) != 2 {
		fmt.Printf("usage: %s [1 2 3 4]\n(number selects the test)\n", os.Args[0])
		return
	}
	switch os.Args[1] {
	case "1":
		// Big map with a pointer in the value
		m := make(map[int32]*int32)
		for i := 0; i < N; i++ {
			n := int32(i)
			m[n] = &n
		}
		runtime.GC()
		fmt.Printf("With %T, GC took %s\n", m, timeGC())
		_ = m[0] // Preserve m until here, hopefully
	case "2":
		// Big map, no pointer in the value
		m := make(map[int32]int32)
		for i := 0; i < N; i++ {
			n := int32(i)
			m[n] = n
		}
		runtime.GC()
		fmt.Printf("With %T, GC took %s\n", m, timeGC())
		_ = m[0]
	case "3":
		// A slice, just for comparison to show that
		// merely holding onto millions of int32s is fine
		// if they're in a slice.
		type t struct {
			p, q int32
		}
		var s []t
		for i := 0; i < N; i++ {
			n := int32(i)
			s = append(s, t{n, n})
		}
		runtime.GC()
		fmt.Printf("With a plain slice (%T), GC took %s\n", s, timeGC())
		_ = s[0]
	case "4":
		// A slice of pointer
		type t struct {
			p, q int32
		}
		var s []*t
		for i := 0; i < N; i++ {
			n := int32(i)
			s = append(s, &t{n, n})
		}
		runtime.GC()
		fmt.Printf("With a plain slice (%T), GC took %s\n", s, timeGC())
		_ = s[0]
	case "5":
		m := make(map[string][]byte)
		for i := 0; i < N; i++ {
			key := fmt.Sprintf("key_%d", i)
			value := fmt.Sprintf("value_xxxxx_xxxx_%d", i)
			m[key] = []byte(value)
		}
		runtime.GC()
		fmt.Printf("With a plain slice (%T), GC took %s\n", m, timeGC())
		_ = m["key_0"]
	}

}

func timeGC() time.Duration {
	start := time.Now()
	runtime.GC()
	return time.Since(start)
}
