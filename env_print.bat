@ECHO OFF
ECHO     env_print.bat 시작됨.

REM 부모인 CMake 프로세스의 환경변수 읽기
SET env_arg1=%Jjangdo1%
SET env_arg2=%Jjangdo2%

REM 공백문자 변수를 만들려면 쌍따옴표를 사용해서 감싸줘야함
SET "expected_arg=Hello World" 

IF "%env_arg1%"=="%expected_arg%" (
    IF "%env_arg2%"=="%expected_arg%" (        
        ECHO     환경변수가 존재합니다.
        SET exit_val=0
        goto END_PROCESS
    ) ELSE (
        ECHO     환경변수가 존재하지 않습니다.(-1)
        SET exit_val=-1
        goto END_PROCESS
    )
) ELSE (
    ECHO     환경변수가 존재하지 않습니다.(-2)
    SET exit_val=-2
    goto END_PROCESS
)

:END_PROCESS
ECHO     env_print.bat 종료됨.
EXIT %exit_val%
