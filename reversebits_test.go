package main

import (
	"math/bits"
	"testing"
)

var tests = []Test{
	{0, 0},
	{1, 1 << (bits.UintSize - 1)},
	{0xf, 0xf << (bits.UintSize - 4)},
	{0xf0f, 0xf0f << (bits.UintSize - 12)},
	{0xa, 0x5 << (bits.UintSize - 4)},
	{0xabcdef, 0xf7b3d5 << (bits.UintSize - 24)},
	{0xcafebabe, 0x7d5d7f53 << (bits.UintSize - 32)},
}

func Test_reversebits1(t *testing.T) {
	var got uint

	for _, test := range tests {
		got = reverseBits1(test.input)
		if got != test.expected {
			t.Fatalf("reversebits1:\n\tinput:    0x%x\n\texpected: 0x%x\n\tgot:      0x%x\n",
				test.input, test.expected, got)
		}
	}
}

func Test_reversebits2(t *testing.T) {
	var got uint

	for _, test := range tests {
		got = reverseBits2(test.input)
		if got != test.expected {
			t.Fatalf("reversebits2:\n\tinput:    0x%x\n\texpected: 0x%x\n\tgot:      0x%x\n",
				test.input, test.expected, got)
		}
	}
}

func Test_reversebits3(t *testing.T) {
	var got uint

	for _, test := range tests {
		got = reverseBits3(test.input)
		if got != test.expected {
			t.Fatalf("reversebits3:\n\tinput:    0x%x\n\texpected: 0x%x\n\tgot:      0x%x\n",
				test.input, test.expected, got)
		}
	}
}

func Benchmark_reversebits1(b *testing.B) {
	for i := 0; i < b.N; i++ {
		reverseBits1(0xcafebabe)
	}
}

func Benchmark_reversebits2(b *testing.B) {
	for i := 0; i < b.N; i++ {
		reverseBits2(0xcafebabe)
	}
}

func Benchmark_reversebits3(b *testing.B) {
	for i := 0; i < b.N; i++ {
		reverseBits3(0xcafebabe)
	}
}
