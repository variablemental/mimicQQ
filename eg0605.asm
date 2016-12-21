; eg0605.asm in Windows Graphic
	.686
	.model flat,stdcall
	option casemap:none
	includelib bin\kernel32.lib
	includelib bin\user32.lib
ExitProcess	proto,:dword
MessageBoxA	proto :dword,:dword,:dword,:dword
MessageBox	equ <MessageBoxA>
	;系统时间的结构类型说明
SYSTEMTIME	struct 
  wYear	word ?	;年（4位数）	
  wMonth	word ?	;月（1～12）
  wDayOfWeek	word ?	;星期（0～6，0＝星期日，1＝星期一，……）
  wDay	word ?	;日（1～31）	
  wHour	word ?	;时（0～23）	
  wMinute	word ?	;分（0～59）	
  wSecond	word ?	;秒（0～59）	
  wMillisconds	word ?	;毫秒（0～999）
SYSTEMTIME	ends	
	;函数声明，参数是指向结构变量的指针，也可以用PTR SYSTIME
GetLocalTime	proto,:dword
writedec	macro time	;;将二进制数转换为2位十进制数、再转为ASCII字符保存
	mov ax,time
	mov cl,10
	div cl	;;商AL是百位，余数AH是个位
	add ax,3030h	;;转换为ASCII
	mov [ebx],ax	;;对应显示顺序，百位先显示保存在低地址位置
	endm

	.data
mytime	SYSTEMTIME <>	;系统时间的结构变量定义
timestring	byte '--:--:--',0
timecaption	byte '当前时间',0

	.code
start:
	invoke GetLocalTime,addr mytime	;获得当前时间
	mov ebx,offset timestring	;EBX指向“时”的保存位置
	writedec mytime.wHour	;转换为ASCII字符
	add ebx,3	;EBX指向“分”的保存位置
	writedec mytime.wMinute
	add ebx,3	;EBX指向“秒”的保存位置
	writedec mytime.wSecond
	invoke MessageBox,0,addr timestring,addr timecaption,1
	invoke ExitProcess,0
	end start

