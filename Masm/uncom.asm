.model small
.data

m1 db 0dh,0ah,"Enter the size of first array:$"
m2 db 0dh,0ah,"Enter first array:$"
m3 db 0dh,0ah,"Enter the size of second array:$"
m4 db 0dh,0ah,"Enter second array:$"
m5 db 0dh,0ah,"The uncommon elements are:$"
m6 db 0dh,0ah,"No uncommon elements $"
en db 0dh,0ah,"$"
space db " $"

array1 db 100 dup('0')
array2 db 100 dup('0')
array3 db 100 dup('0')

n1 dw 0
n2 dw 0
k dw 0

readnum macro
        mov ah,01h
        int 21h
        sub al,30h
        mov ah,00
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
        display m1
        readnum
        mov bh,00
        mov n1,bx
        mov cx,n1
        display m2
        mov si,00
  next1:readnum
        mov array1[si],bl
        display en
        inc si
        loop next1
        display m3
        mov cx,00
        readnum
        mov bh,00
        mov n2,bx
        mov cx,n2
        display m4
        mov di,00
  next2:readnum
        mov array2[di],bl
        display en
        inc di
        loop next2
        mov si,00
   for1:cmp si,n1
        jge second
        mov bh,01
        mov di,00
   for2:cmp di,n2
        jge check
        mov ch,array1[si]
        cmp ch,array2[di]
        jne incdi
        mov bh,00
  check:cmp bh,01
        jne incsi
        xchg k,di
        mov array3[di],ch
        inc di
        xchg k,di
  incsi:inc si
        jmp for1
  incdi:inc di
        jmp for2
 second:mov si,00
   for3:cmp si,n2
        jge disp
        mov bh,01
        mov di,00
   for4:cmp di,n1
        jge check2
        mov ch,array2[si]
        cmp ch,array1[di]
        jne incdi2
        mov bh,00
 check2:cmp bh,01
        jne incsi2
        xchg k,di
        mov array3[di],ch
        inc di
        xchg k,di
 incsi2:inc si
        jmp for3
 incdi2:inc di
        jmp for4
   disp:mov si,00
        mov al,array3[si]
        cmp al,30h
        jz empty
        display m5
  disp1:display space
        cmp si,k
        jge stop
        mov ch,00
        mov cl,array3[si]
        shownum cx
        inc si
        jmp disp1
   empty:display m6
   stop:
.exit
end

        

        
        
        
        
