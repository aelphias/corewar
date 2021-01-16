.name ""
.comment ""

loop:
        sti r16, %:live, %1
live:
        live %111
        ld %0, r2
        zjmp %:loop
        :