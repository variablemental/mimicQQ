; eg0605.asm in Windows Graphic
	.686
	.model flat,stdcall
	option casemap:none
	includelib bin\kernel32.lib
	includelib bin\user32.lib
ExitProcess	proto,:dword
MessageBoxA	proto :dword,:dword,:dword,:dword
MessageBox	equ <MessageBoxA>
	;ϵͳʱ��Ľṹ����˵��
SYSTEMTIME	struct 
  wYear	word ?	;�꣨4λ����	
  wMonth	word ?	;�£�1��12��
  wDayOfWeek	word ?	;���ڣ�0��6��0�������գ�1������һ��������
  wDay	word ?	;�գ�1��31��	
  wHour	word ?	;ʱ��0��23��	
  wMinute	word ?	;�֣�0��59��	
  wSecond	word ?	;�루0��59��	
  wMillisconds	word ?	;���루0��999��
SYSTEMTIME	ends	
	;����������������ָ��ṹ������ָ�룬Ҳ������PTR SYSTIME
GetLocalTime	proto,:dword
writedec	macro time	;;����������ת��Ϊ2λʮ����������תΪASCII�ַ�����
	mov ax,time
	mov cl,10
	div cl	;;��AL�ǰ�λ������AH�Ǹ�λ
	add ax,3030h	;;ת��ΪASCII
	mov [ebx],ax	;;��Ӧ��ʾ˳�򣬰�λ����ʾ�����ڵ͵�ַλ��
	endm

	.data
mytime	SYSTEMTIME <>	;ϵͳʱ��Ľṹ��������
timestring	byte '--:--:--',0
timecaption	byte '��ǰʱ��',0

	.code
start:
	invoke GetLocalTime,addr mytime	;��õ�ǰʱ��
	mov ebx,offset timestring	;EBXָ��ʱ���ı���λ��
	writedec mytime.wHour	;ת��ΪASCII�ַ�
	add ebx,3	;EBXָ�򡰷֡��ı���λ��
	writedec mytime.wMinute
	add ebx,3	;EBXָ���롱�ı���λ��
	writedec mytime.wSecond
	invoke MessageBox,0,addr timestring,addr timecaption,1
	invoke ExitProcess,0
	end start

