; Hc/NtUserCheckDesktopByThreadId
; This file was automatically generated by Highcall's syscall generator.

IFDEF RAX
; 64bit

EXTERNDEF sciUserCheckDesktopByThreadId:DWORD

.DATA
.CODE

HcUserCheckDesktopByThreadId PROC
	mov r10, rcx
	mov eax, sciUserCheckDesktopByThreadId
	syscall
	ret
HcUserCheckDesktopByThreadId ENDP

ELSE
; 32bit

EXTERNDEF C sciUserCheckDesktopByThreadId:DWORD

.586			  
.MODEL FLAT, C   
.STACK
.DATA
.CODE

ASSUME FS:NOTHING

HcUserCheckDesktopByThreadId PROC
	mov eax, sciUserCheckDesktopByThreadId
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
HcUserCheckDesktopByThreadId ENDP

ENDIF

END