; Hc/NtOpenPrivateNamespace
; This file was automatically generated by Highcall's syscall generator.

IFDEF RAX
; 64bit

EXTERNDEF sciOpenPrivateNamespace:DWORD

.DATA
.CODE

HcOpenPrivateNamespace PROC
	mov r10, rcx
	mov eax, sciOpenPrivateNamespace
	syscall
	ret
HcOpenPrivateNamespace ENDP

ELSE
; 32bit

EXTERNDEF C sciOpenPrivateNamespace:DWORD

.586			  
.MODEL FLAT, C   
.STACK
.DATA
.CODE

ASSUME FS:NOTHING

HcOpenPrivateNamespace PROC
	mov eax, sciOpenPrivateNamespace
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
HcOpenPrivateNamespace ENDP

ENDIF

END