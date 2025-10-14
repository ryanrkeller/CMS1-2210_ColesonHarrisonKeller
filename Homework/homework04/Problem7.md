JMP     start

num1:      0
num2:      0
inport:    256
outport:   512
zero:      0

start:     READ    [inport]
           STORE   [num1]

           READ    [inport]
           STORE   [num2]

gcd:
           LOAD    [num1]
           SUB     [zero]
           JZ      zeronum1

           LOAD    [num2]
           SUB     [zero]
           JZ      zeronum2

           LOAD    [num1]
           SUB     [num2]
           JLZ     smallernum1

           LOAD    [num1]
           SUB     [num2]
           STORE   [num1]
           JMP     gcd

smallernum1:
           LOAD    [num2]
           SUB     [num1]
           STORE   [num2]
           JMP     gcd

zeronum1:
           LOAD    [num2]
           JMP     write

zeronum2:
           LOAD    [num1]
           JMP     write

write:
           WRITE   [outport]

end:       JMP     end