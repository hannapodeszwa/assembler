.data
zmienna DWORD 0
i_f DWORD 0
j_f DWORD 0
max DWORD 0

.code

swap_a proc tab:QWORD, i:DWORD , j:DWORD

mov rbx,rcx
mov edi,[rcx+rdx*4]
mov ebx,[rcx+r8*4]
mov [rcx+rdx*4], ebx
mov [rcx+r8*4],edi
mov rcx,r14
ret
swap_a endp


ten_for1 proc tab: QWORD, p:DWORD, r:DWORD, pivot:DWORD
			;rcx			;rdx	;r8		;r9

mov r15, rcx	;tablica

mov r14d,edx	;r14 <- p
mov i_f, r14d   ;i_f <- p
dec i_f			; i=p-1;

mov j_f, r14d	;j_f <- p

mov ecx,j_f		; ecx <- p ; int j = p;

mov r10d,r8d    ; r10 <- r
mov max,r10d	; max <- r
dec max			;max = r-1;

_for: 

mov r12d,ecx
movd xmm0, r12d
movd xmm1,max
cmpleps xmm0,xmm1			;j <= (r - 1);
movss zmienna,xmm0
and zmienna,1
jz _end_for
jmp dalej
;***************************************
cmp ecx, max	;j <= (r - 1);
jae _end_for
;**************************************
dalej:
mov r14d,[r15+rcx*4]

movd xmm0,r9d		;pivot	;xmm **************************************
movd xmm1,r14d

cmpltps xmm0,xmm1
movss zmienna,xmm0
and zmienna,1
jz mniejsze
jmp koniec_if
						;******************************************

;cmp r14d, r13d		;if (tab[j] < pivot)  ;??????????????????????
;jb koniec_if

;**************************************************
mniejsze:
inc i_f				;i++;


mov edx,i_f			;swap
mov r10d,j_f
mov edi,[r15+rdx*4]
mov r11d,[r15+r10*4]
mov [r15+rdx*4], r11d
mov [r15+r10*4],edi


jmp koniec_if


koniec_if:
inc ecx		;j++
inc j_f
jmp _for

_end_for:

mov rcx, r15 ;tablica
mov eax,i_f  ;funkcja zwraca i_f
mov r8d, max
ret
ten_for1 endp










ten_for proc tab: QWORD, p:DWORD, r:DWORD, pivot:DWORD
			;rcx			;rdx	;r8		;r9

mov r15, rcx	;tablica

mov r14d,edx	;r14 <- p
;mov i_f, r14d   ;i_f <- p
dec edx			; i=p-1;

mov ecx, r14d	;j_f <- p

;mov ecx,j_f		; ecx <- p ; int j = p;

mov r10d,r8d    ; r10 <- r
;mov max,r10d	; max <- r
dec r10d		;max = r-1;

_for: 

mov r12d,ecx		;j
movd xmm0, r12d		;j
movd xmm1,r10d		;max
cmpleps xmm0,xmm1			;j <= (r - 1);
;movss ebx,xmm0 ;//////////////////////////////////////////////
movd r13,xmm0
and r13,1
;and xmm0,1
jz _end_for

mov r12d,[r15+rcx*4] ;;if (tab[j] < pivot)
movd xmm0,r9d		;pivot	
movd xmm1,r12d

cmpltps xmm0,xmm1
movd r13,xmm0
and r13,1
jz mniejsze
jmp koniec_if

mniejsze:
inc edx			;i++;


;mov edx,i_f			;swap
;mov r10d,j_f
mov edi,[r15+rdx*4]
mov r11d,[r15+rcx*4]
mov [r15+rdx*4], r11d
mov [r15+rcx*4],edi


jmp koniec_if


koniec_if:
inc ecx		;j++
;inc j_f
jmp _for

_end_for:

mov eax, edx  ;funkcja zwraca i_f
mov rcx, r15 ;tablica
mov r8d, r10d
ret
ten_for endp


end













