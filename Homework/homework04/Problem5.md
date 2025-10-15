JMP     start
count:     0
limit:     256
port_address: 8     

start:     LOAD    [count]
           WRITE   [port_address]
           ADD     1  
           STORE   [count]
           SUB     [limit]
           JLZ     start
end:       JMP     end