.name "Mufasa"
.comment "Mufasa is a major character in Disney's 1994 animated feature film, The Lion King. He was the king of the Pride Lands and the father of Simba. In the midst of his reign, Mufasa was killed by his envious brother, Scar, in an effort to steal the throne. Despite his death, Mufasa endures in the memories of his loved ones. His spirit manifested in clouds, stars, and sunlight, which has occasionally appeared to guide his descendants."

ld %77, r1
ld %117, r2
ld %102, r3
ld %77, r4
aff r1
aff r2
add r1, r3, r2
st	r4, 400
add r2, r3, r4
st	r3, 400
aff r3
ld %97, r4
aff r4
add r3, r4, r1
st	r3, 400
add r4, r1, r3
sub r4, r3, r2
ld %115, r5
ld %97, r6
aff r5
aff r6
sub r5, r4, r3
live %0
live %1
