        global  _main
        extern  _printf

        section .text
_main:
;        mov     edx, 0  ;change this number to whatever for it to print the right thing
        mov     edx, 123457
        mov     eax, 0
        mov     ecx, 8

count:
        dec     ecx
        cmp     ecx, 0
        jl      checkparity
        mov     ebx, edx
        shr     edx, 1
        and     ebx, 1
        cmp     ebx, 1
        jne     count
        inc     eax
        cmp     ecx, 0
        jge      count

checkparity:
        and     eax, 1
        xor     eax, 1
        push    eax
        push    msg
        call    _printf
        add     esp, 8
        ret

         section .data
msg:     db      "%d"
