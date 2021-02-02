.name "tester"
.comment "test sti"


ld %2147483647, r2
ld %3, r3
ld %4, r4
sti r2, r3, r4

#will do nothing if r is <= 0 or > REG_NUM
