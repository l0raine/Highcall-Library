; Hc/NtUserSetMenuFlagRtoL
; This file was automatically generated by Highcall's syscall generator.

IFDEF RAX
; 64bit

EXTERNDEF sciUserSetMenuFlagRtoL:DWORD

.DATA
.CODE

HcUserSetMenuFlagRtoL PROC
	mov r10, rcx
	mov eax, sciUserSetMenuFlagRtoL
	syscall
	ret
HcUserSetMenuFlagRtoL ENDP

ELSE
; 32bit

EXTERNDEF C sciUserSetMenuFlagRtoL:DWORD

.586			  
.MODEL FLAT, C   
.STACK
.DATA
.CODE

ASSUME FS:NOTHING

HcUserSetMenuFlagRtoL PROC
	mov eax, sciUserSetMenuFlagRtoL
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
HcUserSetMenuFlagRtoL ENDP

ENDIF

END