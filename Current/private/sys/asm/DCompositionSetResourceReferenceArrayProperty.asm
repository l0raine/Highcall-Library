; Hc/NtDCompositionSetResourceReferenceArrayProperty
; This file was automatically generated by Highcall's syscall generator.

IFDEF RAX
; 64bit

EXTERNDEF sciDCompositionSetResourceReferenceArrayProperty:DWORD

.DATA
.CODE

HcDCompositionSetResourceReferenceArrayProperty PROC
	mov r10, rcx
	mov eax, sciDCompositionSetResourceReferenceArrayProperty
	syscall
	ret
HcDCompositionSetResourceReferenceArrayProperty ENDP

ELSE
; 32bit

EXTERNDEF C sciDCompositionSetResourceReferenceArrayProperty:DWORD

.586			  
.MODEL FLAT, C   
.STACK
.DATA
.CODE

ASSUME FS:NOTHING

HcDCompositionSetResourceReferenceArrayProperty PROC
	mov eax, sciDCompositionSetResourceReferenceArrayProperty
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
HcDCompositionSetResourceReferenceArrayProperty ENDP

ENDIF

END