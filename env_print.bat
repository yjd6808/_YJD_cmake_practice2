@ECHO OFF
ECHO     env_print.bat ���۵�.

REM �θ��� CMake ���μ����� ȯ�溯�� �б�
SET env_arg1=%Jjangdo1%
SET env_arg2=%Jjangdo2%

REM ���鹮�� ������ ������� �ֵ���ǥ�� ����ؼ� ���������
SET "expected_arg=Hello World" 

IF "%env_arg1%"=="%expected_arg%" (
    IF "%env_arg2%"=="%expected_arg%" (        
        ECHO     ȯ�溯���� �����մϴ�.
        SET exit_val=0
        goto END_PROCESS
    ) ELSE (
        ECHO     ȯ�溯���� �������� �ʽ��ϴ�.(-1)
        SET exit_val=-1
        goto END_PROCESS
    )
) ELSE (
    ECHO     ȯ�溯���� �������� �ʽ��ϴ�.(-2)
    SET exit_val=-2
    goto END_PROCESS
)

:END_PROCESS
ECHO     env_print.bat �����.
EXIT %exit_val%
