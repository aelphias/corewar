.name "Alex"
.comment "Another day in McDonalds"


start:
		live %1
start1:
		zjmp %:add
		ld %100, r2
add:
		live %1
		sti r1, %:add, %1
		add r2, r2, r2
		sti r1, %0, r2
		ld %0, r4
		zjmp %:add

