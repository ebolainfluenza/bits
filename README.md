# bits
bit-twiddles

A silly, but non-trivial project.  Silly because reversing bits has no known value (to me).  Non-trivial because of the logic, the succession of thought, and the necessary separation (and unification via the makefile) of compilation units.

First, I wrote the reverseBits1() and the tests.  While writing them, I noticed that each nibble has a fixed reverse (I know, logical, right?).  That lead to reverseBits2().  I then transliterated that into the Go version for ease of Benchmark testing.  Since the reverseBits2() was consistently faster, then reverseBits3() would logically be even faster.  However, I did not desire to manually create an 16X16 map of reversed bytes, so I did it programatically, and tied it all together with the makefile.
