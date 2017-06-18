.model small
.data

m1 db 0dh,0ah,"MENU",0dh,0ah,"1.Create",0dh,0ah,"2.Push",0dh,0ah,"3.Pop",0dh,0ah,"4.Top",0dh,0ah,"5.traverse",0dh,0ah,"6.Exit",0dh,0ah,"Enter your choice:$"
m2 db 0dh,0ah,"Enter the size of the stack:$"
m3 db 0dh,0ah,"The stack is created with size of $"
m4 db 0dh,0ah,"Stack overflow $"
m5 db 0dh,0ah,"Stack is empty $"
m6 db 0dh,0ah,"Enter the element:$"
m7 db 0dh,0ah,"Do you want to push more?(1=Yes/2=No) $"
m8 db 0dh,0ah,"Poped element is $"
m9 db 0dh,0ah,"Do you want to pop more?(1=Yes/2=No) $"
m10 db 0dh,0ah,"Invalid choice $"
m11 db 0dh,0ah,"Top element is:$"
m12 db 0dh,0ah,"The stack is:$"

space db " $"
en db 0dh,0ah,"$"
top dw 0
sz dw 0
stack db 100 dup(?)

readnum macro
        mov ah,01h
        int 21h
        sub al,30h
        mov bl,0ah
        mul bl
        mov bl,al
        mov ah,01h
        int 21h
        sub al,30h
        add bl,al
endm

display macro msg
        lea dx,msg
        mov ah,09h
        int 21h
endm

shownum macro num
        mov ax,num
        mov bl,0ah
        div bl
        mov bl,ah
        
        mov dl,al
        add dl,30h
        mov ah,02h
        int 21h
        mov dl,bl
        add dl,30h
        mov ah,02h
        int 21h
endm

.code
.startup
        begin:  display m1
                mov ah,01h
                int 21h
                cmp al,31h
                je create
                cmp al,32h
                je push1
                cmp al,33h
                je pop1
                cmp al,34h
                je top1
                cmp al,35h
                je traverse
                cmp al,36h
                je stop
                display m10
                jmp begin
        create: display m2
                readnum
                mov bh,00
                mov sz,bx
                mov si,-1
                mov top,si
                display m3
                display space
                shownum bx
                jmp begin
        push1:  mov si,top
                mov di,sz
                dec di
        pushagain:cmp si,di
                je overflow
                display m6
                inc si
                mov top,si
                readnum
                mov stack[si],bl
                display m7
                mov ah,01h
                int 21h
                cmp al,31h
                je pushagain
                jmp begin
        overflow:display m4
                jmp begin
        pop1:   mov si,top
        popagain:cmp si,-1
                je empty
                display m8
                mov ch,00
                mov cl,stack[si]
                shownum cx
                dec si
                mov top,si
                display m9
                mov ah,01h
                int 21h
                cmp al,31h
                je popagain
                jmp begin
        empty:  display m5
                jmp begin
        top1:   mov si,top
                cmp si,-1
                je empty
                display m11
                display space
                mov ch,00
                mov cl,stack[si]
                shownum cx
                jmp begin
        traverse:mov si,top
                cmp si,-1
                je empty
                display m12
                display space
                mov di,0
        tryagain:cmp di,top
                jg begin
                mov ch,00
                mov cl,stack[di]
                shownum cx
                display space
                inc di
                jmp tryagain
        stop:
.exit
end
