; Hc/NtGdiScaleViewportExtEx
; This file was automatically generated by Highcall's syscall generator.

IFDEF RAX
; 64bit

EXTERNDEF sciGdiScaleViewportExtEx:DWORD

.DATA
.CODE

HcGdiScaleViewportExtEx PROC
	mov r10, rcx
	mov eax, sciGdiScaleViewportExtEx
	syscall
	ret
HcGdiScaleViewportExtEx ENDP

ELSE
; 32bit

EXTERNDEF C sciGdiScaleViewportExtEx:DWORD

.586			  
.MODEL FLAT, C   
.STACK
.DATA
.CODE

ASSUME FS:NOTHING

HcGdiScaleViewportExtEx PROC
	mov eax, sciGdiScaleViewportExtEx
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
HcGdiScaleViewportExtEx ENDP

ENDIF

END