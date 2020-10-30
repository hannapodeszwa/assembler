.data
zmienna DWORD 0
i_f DWORD 0
j_f DWORD 0
max DWORD 0

.code
MyProc1 proc
add RCX, RDX
mov RAX, RCX
ret
MyProc1 endp

swap_a proc tab:QWORD, i:DWORD , j:DWORD

;mov r14,rdx
;mov r9,r8
mov rbx,rcx
mov edi,[rcx+rdx*4]
mov ebx,[rcx+r8*4]
mov [rcx+rdx*4], ebx
mov [rcx+r8*4],edi
mov rcx,r14
ret
swap_a endp


ten_for proc tab: QWORD, p:DWORD, r:DWORD, pivot:DWORD
			;rcx			;rdx	;r8		;r9

mov r15, rcx	;tablica

mov r14d,edx	;r14 <- p
mov i_f, r14d   ;i_f <- p
dec i_f			; i=p-1;

mov j_f, r14d	;j_f <- p

mov ecx,j_f		; ecx <- p ; int j = p;

_for: 
mov r10d,r8d    ; r10 <- r
mov max,r10d	; max <- r
dec max			;max = r-1;
mov r12d,ecx
mov r10d,max
movd xmm0, r12d
movd xmm1,r10d
cmpleps xmm0,xmm1			;j <= (r - 1);
movss zmienna,xmm0
;mov max,r10d ;;;;;;;;;;;
and zmienna,1
jz _end_for
jmp dalej
;***************************************
cmp ecx, max	;j <= (r - 1);
jae _end_for
;**************************************
dalej:
mov r13d,pivot
mov r14d,[r15+rcx*4]

movd xmm0,r9d		;pivot	;xmm **************************************
movd xmm1,r14d

cmpltps xmm0,xmm1
movss zmienna,xmm0
and zmienna,1
jz mniejsze
jmp koniec_if
						;******************************************

cmp r14d, r13d		;if (tab[j] < pivot)  ;??????????????????????
jb koniec_if

;**************************************************
mniejsze:
inc i_f				;i++;


mov edx,i_f			;swap
mov r10d,j_f
mov edi,[r15+rdx*4]
mov ebx,[r15+r10*4]
mov [r15+rdx*4], ebx
mov [r15+r10*4],edi


jmp koniec_if


koniec_if:
inc ecx		;j++
inc j_f
jmp _for

_end_for:

mov rcx, r15 ;tablica
mov edx, i_f   ;w p wzraca i
ten_for endp


;mov rdi,tab
;mov eax,1
;mov [rdi],eax
;mov r11,4

;mov r8,4
;movd xmm0,i
;movd xmm1,r8
;mulss xmm0,xmm1
;movd r8, xmm0

;mov rax,4
;movd xmm0,rdx
;movd xmm1,rax
;mulss xmm0,xmm1
;movd rax, xmm0

;movups xmm0, i
;movups xmm1,eax
;mulps xmm0,4


;/////////// dziala


;mov eax, dword ptr[tab]
;mov rcx, dword ptr [eax+4]

;mov r11,1
;mov tab[0],  r11








;mov zmienna,eax

;mov ecx,1
;mov tab[0],ecx
;mov ecx,[tab]
;mov bx,0
;mov tab[bx],1





;movq mm0, rcx
;paddb mm0, [tab]
;movq tab[0], mm0

;mul i,4
;movups xmm0, 4*i
;mov eax,4*i
;mov zmienna, i

;mov ecx,  tab + eax
;mov rax, tab[0]
;mov [tab +4*i],  [tab+4*j]
;mov [tab+4*j],eax

;mov zmienna, [rcx]

end













