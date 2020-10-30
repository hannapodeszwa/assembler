.code

ten_for proc tab: QWORD, p:DWORD, r:DWORD, pivot:DWORD
			;rcx			;rdx	;r8		;r9

		;Push(rAX);
        ;Push(rCX);
        ;Push(rDX);
        ;Push(rBX);
        Push(rSI);
        Push(rDI);
        Push(rsp);
        Push(rBP);
        Push(r8);
        Push(r9);
        Push(r10);
        Push(r11);
        Push(r12);
        Push(r13);
        Push(r14);
        Push(r15);

mov r15, rcx	;tablica

mov r14d,edx	;r14 <- p
dec edx			; i=p-1;

mov ecx, r14d	;j <- p


mov r10d,r8d    ; r10 <- r
dec r10d		;max = r-1;

_for: 

mov r12d,ecx		;j
movd xmm0, r12d		;j
movd xmm1,r10d		;max
cmpleps xmm0,xmm1			;j <= (r - 1);
movd r13,xmm0
and r13,1
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

mov edi,[r15+rdx*4]		;swap
mov r11d,[r15+rcx*4]
mov [r15+rdx*4], r11d
mov [r15+rcx*4],edi


jmp koniec_if


koniec_if:
inc ecx		;j++
jmp _for

_end_for:    
mov rcx, r15
        pop(r15);
        pop(r14);
        pop(r13);
        pop(r12);
        pop(r11);
        pop(r10);
        pop(r9);
        pop(r8);
        pop(rBP);
        pop(rsp);
        pop(rDI);
        pop(rSI);
        ;pop(rBX);
        ;pop(rDX);
        ;pop(rCX);
        ;Pop(rAX);

mov eax, edx  ;funkcja zwraca i_f
;mov rcx, r15 ;tablica
;mov r8d, r10d
;mov edx,r14d

ret
ten_for endp
end













