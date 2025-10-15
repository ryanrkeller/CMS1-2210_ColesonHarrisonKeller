C0000005  ; JMP start
00000000  ; Data: count = 0
00000100  ; Data: limit = 256
00000008  ; Data: port_address = 8
00000001  ; Data: one = 1
00000001  ; start: LOAD [count]
30000008  ; WRITE 8
40000004  ; ADD [one]
10000001  ; STORE [count]
50000002  ; SUB [limit] 
E0000005  ; JLZ start 
C000000B  ; end: JMP end