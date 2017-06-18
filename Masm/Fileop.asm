.model small
.data
m1 db 0dh,0ah,"MENU",0dh,0ah,"1.Create",0dh,0ah,"2.Read",0dh,0ah,"3.Write",0dh,0ah,"4.Delete",0dh,0ah,"5.Exit",0dh,0ah,"Enter your choice:$"
m2 db 0dh,0ah,"Invalid input $"
array db 10 dup(?)
m3 db 0dh,0ah,"sucess $"
m4 db 0dh,0ah,"Error $"
m5 db 0dh,0ah,"Enter the name of file:$"
enter1 db 0dh,0ah,"$"
buffer db 255 dup('$')
.code
.startup
        begin:  lea dx,m1
                mov ah,09h
                int 21h
                mov ah,01h
                int 21h
                cmp al,31h
                je create
                cmp al,32h
                je read
                cmp al,33h
                je write
                cmp al,34h
                je delete
                cmp al,35h
                je stop
                lea dx,m2
                mov ah,009h
                int 21h
                jmp begin
        create: lea dx,m5
                mov ah,09h
                int 21h
                mov si,00
        loop1:  mov ah,01h
                int 21h
                cmp al,0dh
                je proceed1
                mov array[si],al
                inc si
                jmp loop1
        proceed1:inc si
                mov array[si],0h
                mov ah,3ch
                lea dx,array
                mov cx,00
                int 21h
                jc error
                mov bx,ax
                mov ah,3eh
                int 21h
                jmp begin
        read:   lea dx,m5
                mov ah,09h
                int 21h
                mov si,00
        loop2:  mov ah,01h
                int 21h
                cmp al,0dh
                je proceed2
                mov array[si],al
                inc si
                jmp loop2
        proceed2:inc si
                mov array[si],0h
                mov ah,3dh
                lea dx,array
                mov al,00
                int 21h
                jc error
                mov bx,ax
                mov ah,3fh
                mov cx,50
                lea dx,enter1
                mov ah,09h
                int 21h
                lea dx,buffer
                mov ah,09h
                int 21h
                mov ah,3eh
                int 21h
                jmp begin
        write:  lea dx,m5
                mov ah,09h
                int 21h
                mov si,00
        loop3:  mov ah,01h
                int 21h
                cmp al,0dh
                je proceed3
                mov array[si],al
                inc si
                jmp loop3
        proceed3:inc si
                mov array[si],0h
                mov ah,3dh
                lea dx,array
                mov al,01h
                int 21h
                jc error
                lea dx,enter1
                mov ah,09h
                int 21h
                mov si,00
        get:    mov ah,01h
                int 21h
                cmp al,0dh
                je proceed4
                mov buffer[si],al
                inc si
                jmp get
        proceed4:mov buffer[si],'$'
                lea dx,buffer
                mov ah,40h
                int 21h
                mov ah,3eh
                int 21h
                jmp begin
        delete: lea dx,m5
                mov ah,09h
                int 21h
                mov si,00
        loop5:  mov ah,01h
                int 21h
                cmp al,0dh
                je proceed5
                mov array[si],al
                inc si
                jmp loop5
        proceed5:inc si
                mov array[si],dh
                lea dx,array
                mov ah,41h
                int 21h
                jc error
                lea dx,m3
                mov ah,09h
                int 21h
                jmp begin
        error:lea dx,m4
                mov ah,09h
                int 21h
                jmp begin
                stop:
                .exit
                end



