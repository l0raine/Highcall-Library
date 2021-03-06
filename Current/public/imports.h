#ifndef HC_IMPORT_H
#define HC_IMPORT_H

#include "native.h"
#pragma comment(lib, "ntdll.lib") /* link against ntdll for all these juicy rtl/nt/ldr functions */

#define RtlGetProcessHeap() ((HANDLE)(NtCurrentPeb()->ProcessHeap))

typedef enum _RTL_PATH_TYPE
{
	RtlPathTypeUnknown,
	RtlPathTypeUncAbsolute,
	RtlPathTypeDriveAbsolute,
	RtlPathTypeDriveRelative,
	RtlPathTypeRooted,
	RtlPathTypeRelative,
	RtlPathTypeLocalDevice,
	RtlPathTypeRootLocalDevice,
} RTL_PATH_TYPE;

#define RTL_NT_PATH_NAME_TO_DOS_PATH_NAME_AMBIGUOUS   (0x00000001)
#define RTL_NT_PATH_NAME_TO_DOS_PATH_NAME_UNC         (0x00000002)
#define RTL_NT_PATH_NAME_TO_DOS_PATH_NAME_DRIVE       (0x00000003)
#define RTL_NT_PATH_NAME_TO_DOS_PATH_NAME_ALREADY_DOS (0x00000004)

#ifdef __cplusplus
extern "C" {
#endif

/* LDR AND RTL FUNCTIONS */
NTSYSAPI
NTSTATUS
NTAPI RtlNtPathNameToDosPathName(
	ULONG Flags,
	PRTL_UNICODE_STRING_BUFFER Path,
	PULONG Disposition,
	PWSTR* FilePart);

NTSYSAPI NTSTATUS NTAPI RtlGetVersion(
	_Out_ PRTL_OSVERSIONINFOW lpInformation);

NTSYSAPI BOOLEAN NTAPI RtlEqualUnicodeString(
	_In_ PUNICODE_STRING String1,
	_In_ PUNICODE_STRING String2,
	_In_ BOOLEAN         CaseInSensitive);

NTSYSAPI VOID NTAPI RtlInitUnicodeString(
	_Out_    PUNICODE_STRING DestinationString,
	_In_opt_ PCWSTR          SourceString);

NTSYSAPI NTSTATUS NTAPI LdrUnloadDll(IN HANDLE ModuleHandle);

NTSYSAPI NTSTATUS NTAPI LdrLoadDll(
	IN PWCHAR		   PathToFile OPTIONAL,
	IN ULONG           Flags OPTIONAL,
	IN PUNICODE_STRING ModuleFileName,
	OUT PHANDLE        ModuleHandle);

NTSYSAPI
NTSTATUS
NTAPI
RtlUnicodeStringToInteger(
	_In_ PUNICODE_STRING String,
	_In_opt_ ULONG Base,
	_Out_ PULONG Value
);

NTSYSAPI VOID NTAPI RtlAcquirePebLock(VOID);
NTSYSAPI VOID NTAPI RtlReleasePebLock(VOID);

NTSYSAPI NTSTATUS NTAPI RtlLeaveCriticalSection(IN PRTL_CRITICAL_SECTION CriticalSection);
NTSYSAPI NTSTATUS NTAPI RtlEnterCriticalSection(IN PRTL_CRITICAL_SECTION CriticalSection);

NTSYSAPI BOOLEAN NTAPI RtlDosPathNameToNtPathName_U(
	_In_opt_z_ PCWSTR 	DosPathName,
	_Out_ PUNICODE_STRING 	NtPathName,
	_Out_opt_ PCWSTR * 	NtFileNamePart,
	_Out_opt_ PRTL_RELATIVE_NAME_U 	DirectoryInfo);

NTSYSAPI BOOLEAN NTAPI RtlFreeHeap(
	IN PVOID HeapHandle,
	IN ULONG 	Flags,
	IN PVOID 	HeapBase);

NTSYSAPI PVOID NTAPI RtlAllocateHeap(
	IN PVOID HeapHandle,
	IN ULONG 	Flags,
	IN SIZE_T 	Size);

NTSYSAPI BOOLEAN NTAPI RtlFreeHeap(IN PVOID HeapHandle,
	IN ULONG 	Flags,
	IN PVOID 	HeapBase);

//
// LdrLockLoaderLock Flags
//
#define LDR_LOCK_LOADER_LOCK_FLAG_RAISE_ON_ERRORS   0x00000001
#define LDR_LOCK_LOADER_LOCK_FLAG_TRY_ONLY          0x00000002

NTSYSAPI NTSTATUS NTAPI LdrLockLoaderLock(IN ULONG Flags,
	OUT PULONG Disposition OPTIONAL,
	OUT PULONG_PTR Cookie OPTIONAL);

NTSYSAPI NTSTATUS NTAPI LdrUnlockLoaderLock(IN ULONG Flags,
	IN ULONG_PTR Cookie OPTIONAL);

NTSYSAPI ULONG NTAPI RtlGetFullPathName_U(_In_ PCWSTR FileName,
	_In_ ULONG 	Size,
	_Out_z_bytecap_(Size) PWSTR Buffer,
	_Out_opt_ PWSTR* ShortName);

NTSYSAPI NTSTATUS NTAPI RtlQueryEnvironmentVariable_U(PWSTR Environment,
	PUNICODE_STRING Name,
	PUNICODE_STRING Value);

/* NT FUNCTIONS */

NTSYSAPI NTSTATUS NTAPI NtQueryInformationFile(
	IN  HANDLE                 FileHandle,
	OUT PIO_STATUS_BLOCK       IoStatusBlock,
	OUT PVOID                  FileInformation,
	IN  ULONG                  Length,
	IN  FILE_INFORMATION_CLASS FileInformationClass
);

NTSYSAPI NTSTATUS NTAPI NtWaitForSingleObject(IN HANDLE hObject,
	IN BOOLEAN bAlertable,
	IN PLARGE_INTEGER Timeout);

NTSYSAPI NTSTATUS NTAPI NtReadFile(
	_In_     HANDLE           FileHandle,
	_In_opt_ HANDLE           Event,
	_In_opt_ PIO_APC_ROUTINE  ApcRoutine,
	_In_opt_ PVOID            ApcContext,
	_Out_    PIO_STATUS_BLOCK IoStatusBlock,
	_Out_    PVOID            Buffer,
	_In_     ULONG            Length,
	_In_opt_ PLARGE_INTEGER   ByteOffset,
	_In_opt_ PULONG           Key
);


NTSYSAPI NTSTATUS NTAPI NtQueryEaFile(
	HANDLE           hFile,
	PIO_STATUS_BLOCK iosb,
	PVOID            buffer,
	ULONG            length,
	BOOLEAN          single_entry,
	PVOID            ea_list,
	ULONG            ea_list_len,
	PULONG           ea_index,
	BOOLEAN          restart);

NTSYSAPI NTSTATUS NTAPI NtCreateFile(
	OUT    PHANDLE            FileHandle,
	IN     ACCESS_MASK        DesiredAccess,
	IN     POBJECT_ATTRIBUTES ObjectAttributes,
	OUT    PIO_STATUS_BLOCK   IoStatusBlock,
	IN	   PLARGE_INTEGER	  AllocationSize OPTIONAL,
	IN     ULONG              FileAttributes,
	IN     ULONG              ShareAccess,
	IN     ULONG              CreateDisposition,
	IN     ULONG              CreateOptions,
	IN     PVOID              EaBuffer,
	IN     ULONG              EaLength
);

NTSYSAPI NTSTATUS NTAPI NtClose(HANDLE hObject);

NTSYSAPI NTSTATUS NTAPI NtSetInformationFile(
	_In_  HANDLE                 FileHandle,
	_Out_ PIO_STATUS_BLOCK       IoStatusBlock,
	_In_  PVOID                  FileInformation,
	_In_  ULONG                  Length,
	_In_  FILE_INFORMATION_CLASS FileInformationClass
);

NTSYSAPI NTSTATUS NTAPI NtQueryVirtualMemory(IN HANDLE ProcessHandle,
	IN LPVOID BaseAddress,
	IN MEMORY_INFORMATION_CLASS MemoryInformationClass,
	OUT LPVOID MemoryInformation,
	IN SIZE_T MemoryInformationLength,
	OUT PSIZE_T ReturnLength);

NTSYSAPI
NTSTATUS
NTAPI
NtResumeThread(
	IN HANDLE ThreadHandle,
	OUT PULONG PreviousSuspendCount OPTIONAL
);

NTSYSAPI
NTSTATUS
NTAPI
RtlDestroyProcessParameters(
	PRTL_USER_PROCESS_PARAMETERS ProcessParameters
);

NTSYSAPI
NTSTATUS
NTAPI
RtlCreateUserProcess(
	PUNICODE_STRING NtImagePathName,
	ULONG Attributes,
	PRTL_USER_PROCESS_PARAMETERS ProcessParameters,
	PSECURITY_DESCRIPTOR ProcessSecurityDescriptor,
	PSECURITY_DESCRIPTOR ThreadSecurityDescriptor,
	HANDLE ParentProcess,
	BOOLEAN InheritHandles,
	HANDLE DebugPort,
	HANDLE ExceptionPort,
	PRTL_USER_PROCESS_INFORMATION ProcessInformation
);


NTSYSAPI
NTSTATUS
NTAPI
RtlCreateProcessParameters(
	PRTL_USER_PROCESS_PARAMETERS *ProcessParameters,
	PUNICODE_STRING ImagePathName,
	PUNICODE_STRING DllPath,
	PUNICODE_STRING CurrentDirectory,
	PUNICODE_STRING CommandLine,
	PVOID Environment,
	PUNICODE_STRING WindowTitle,
	PUNICODE_STRING DesktopInfo,
	PUNICODE_STRING ShellInfo,
	PUNICODE_STRING RuntimeData
);

#ifdef __cplusplus
} // extern "C"
#endif

#endif