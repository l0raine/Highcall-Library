; Hc/NtUnBindCompositionSurface
; This file was automatically generated by Highcall's syscall generator.

IFDEF RAX
; 64bit

EXTERNDEF sciUnBindCompositionSurface:DWORD

.DATA
.CODE

HcUnBindCompositionSurface PROC
	mov r10, rcx
	mov eax, sciUnBindCompositionSurface
	syscall
	ret
HcUnBindCompositionSurface ENDP

ELSE
; 32bit

EXTERNDEF C sciUnBindCompositionSurface:DWORD

.586			  
.MODEL FLAT, C   
.STACK
.DATA
.CODE

ASSUME FS:NOTHING

HcUnBindCompositionSurface PROC
	mov eax, sciUnBindCompositionSurface
	mov ecx, fs:[0c0h]
	test ecx, ecx
	jne _wow64
	lea edx, [esp + 4]
	INT 02eh
	ret
	_wow64:
	xor ecx, ecx
	lea edx, [esp + 4h]
	call dword ptr fs:[0c0h]
	ret
HcUnBindCompositionSurface ENDP

ENDIF

END