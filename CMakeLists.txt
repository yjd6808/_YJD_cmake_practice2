message("현재 파일 : CMakeLists.txt [루트]")

# 안적어주면 경고떠서 일단 적어둠
cmake_minimum_required(VERSION 3.14)
project(v3 LANGUAGES CXX VERSION 1.0.0)

# 각 번호 별로 작업 진행 후 기존값으로 돌려놓기 위함
macro(fn_reset)
    set(a "abc")
    set(A "bcd")
endmacro()



# ===========================================================
# 환경 변수 테스트
set(ENV{Jjangdo1} "Hello World")
set(ENV{Jjangdo2} "Hello World")
message("환경변수 설정 완료")

# 자식 프로세스 생성 후 결과 받기
execute_process(COMMAND "${CMAKE_SOURCE_DIR}/env_print.bat" RESULT_VARIABLE result)
message("자식 프로세스 실행 결과 : ${result}")


# ===========================================================
# 참/거짓 문자열 테스트
function(fn_check_val var_name)
    message("    ${var_name} = ${${var_name}}")

    if (${var_name})
        message("    ${var_name} is true")
    else()
        message("    ${var_name} is false")
    endif()

    if (NOT ${var_name})
        message("NOT ${var_name} is true")
    else()
        message("NOT ${var_name} is false")
    endif()

    message("") #한줄 뛰우기용
endfunction()

set(var_1   "1")
set(var_2   "yes")
set(var_3   "yEs")
set(var_4   "YES")
set(var_5   "fsefesfs")
set(var_6   "")
set(var_7   "NO")
set(var_8   "No")
set(var_9   "TRUE")
set(var_10  "tRue")
set(var_11  "False")
set(var_12  "FALSE")
set(var_13  "Y")
set(var_14  "N")

fn_check_val(var_1)
fn_check_val(var_2)
fn_check_val(var_3)
fn_check_val(var_4)
fn_check_val(var_5)
fn_check_val(var_6)
fn_check_val(var_7)
fn_check_val(var_8)
fn_check_val(var_9)
fn_check_val(var_10)
fn_check_val(var_11)
fn_check_val(var_12)
fn_check_val(var_13)
fn_check_val(var_14)



# ===========================================================
# 논리 연산 테스트
set(yes "Y")
set(no  "N")

if(${yes} AND ${yes})
    message("true")
endif()

if( NOT (${yes} EQUAL ${no}) )
    message("true")
endif()

if(${yes} OR ${no})
    message("true")
endif()



# ===========================================================
# 비교 연산 테스트
set(a "1")
set(b "2")
set(c "0x1")
set(d "d-d")
set(e "d-d")

if (${a} EQUAL ${c})
    message("a와 b는 서로 같다. (숫자 비교)")
endif()

if (NOT ${a} STREQUAL ${c})
    message("a와 c는 서로 다르다. (문자열 비교)")
endif()

if (${b} GREATER ${a})
    message("b가 a보다 크다. (숫자 비교)")
endif()

if (NOT ${d} EQUAL ${e})
    message("d와 e는 서로 다르다. (숫자 비교)")
endif()

if (${d} STREQUAL ${e})
    message("d와 e는 서로 같다. (문자열 비교)")
endif()


# ===========================================================
# 반복문

set(li 1 2 3 4 5 6)  # 리스트 변수 생성

# 리스트 원소 순회
foreach(elem ${li})
    message("${elem}")
endforeach()

# 리스트 원소 순회2 (공백 단위)
foreach(elem 1 2 3 4 5 6)
    message("${elem}")
endforeach()

message("RANGE <stop>")
foreach (i RANGE 16)
    message("${i}")
endforeach()

message("RANGE <start> <stop> <step>")
foreach (i RANGE 0 16 2)
    message("${i}")
endforeach()


# ===========================================================
# 다른 cmake 파일 포함시키기
include(Functions.cmake)

fn_print_value(1)
fn_print_value("Hello World")

mac_print_value(4343)
mac_print_value(Robocop)


# ===========================================================
message("# 1. [변수 대소문자 구분]")

set(a "abc")
set(A "bcd")

message("root a : ${a}")
message("root A : ${A}")

# ===========================================================
message("# 2. [include로 실행할 경우 새로운 스코프를 생성 안함]")

include(IncVariable.cmake)

message("root a : ${a}")
message("root A : ${A}") 

fn_reset()

# ===========================================================
message("# 3. [add_subdirectory로 실행할 경우 새로운 스코프를 생성한다.]")

add_subdirectory(libsub)

message("root a : ${a}")
message("root A : ${A}")

fn_reset()

# ===========================================================
message("# 4. [함수는 새로운 스코프를 생성한다.]")
function(fn_print_a)
    message("fn_print_a 함수 진입")
    message("\troot a : ${a}") 
    message("\troot A : ${A}") 

    message("\ta, b변수 생성")
    set(a "ggg")
    set(A "kkk")

    # 수정하고나서는 인자를 전달하지않으면 함수 내부에서 외부 변수 접근 불가능
    message("\tnew a : ${a}")
    message("\tnew A : ${A}")
    message("fn_print_a 함수 탈출")
endfunction()


fn_print_a()
message("root a : ${a}")
message("root A : ${A}")

fn_reset()

# ===========================================================
message("# 5. [매크로는 스코프를 생성하지 않는다.]")
macro(mac_print_a)
    message("mac_print_a 매크로 진입")
    message("\troot a : ${a}") 
    message("\troot A : ${A}") 

    message("\ta, b변수 변경")
    set(a "ggg")
    set(A "kkk")

    message("\troot a : ${a}")
    message("\troot A : ${A}")
    message("mac_print_a 매크로 탈출")
endmacro()
mac_print_a()

message("root a : ${a}")
message("root A : ${A}")

fn_reset()

# ===========================================================
message("# 6. [함수에서 부모 스코프 변수의 값 변경]")

function(fn_change_val)
    message("fn_change_val 함수 진입")
    # 새로운 변수 생성
    message("\t로컬 스코프에서 a, b변수 생성")
    set(a 555)
    set(A 666)

    # 부모 스코프의 변수 값을 변경
    message("\t부모 스코프의 a, b변수 변경")
    set(a 333 PARENT_SCOPE)
    set(A 444 PARENT_SCOPE)

    # 현재 스코프의 변수는 변경되지 않는다.
    message("\tnew a : ${a}")
    message("\tnew A : ${A}")

    message("fn_change_val 함수 탈출")
endfunction()

fn_change_val()

message("root a : ${a}")
message("root A : ${A}")

fn_reset()


# ===========================================================
message("# 7. [리스트 변수]")

set(li "1;2;3 4;5")
message("li : ${li}")

# 리스트 길이 가져오기
list(LENGTH li li_len)
message("li_length : ${li_len}")

# 리스트 값 가져오기
list(GET li 2 elem)
message("li[2] : ${elem}")

message("리스트 출력")
foreach(item ${li})
    message("\t${item}")
endforeach()



# ===========================================================
message("# 8. [함수로 인자 전달]")
function(fn_print_args param0 param1)
    # 이름있는 매개 변수
    message("매개변수0 : ${param0}")
    message("매개변수1 : ${param1}")

    # 이름을 모를 때 출력하는 방법
    #
    # ARGV  : 전달된 인자값들의 리스트
    # ARGN  : 추가적으로 전달된 인자값들의 리스트
    # ARGC  : 전달된 모든 인자들의 총 갯수
    # ARGV0 : 첫번째 매개변수
    # ARGV1 : 두번째 매개변수
    # ARGV2 : 세번째 매개변수
    # ...
    # ARGVx : (x + 1)번째 매개변수
    message("ARGV : ${ARGV}")
    message("ARGN : ${ARGN}")
    message("ARGC : ${ARGC}")
    message("ARGVx 형식의 매개변수 출력")
    message("\t매개변수0 : ${ARGV0}")
    message("\t매개변수1 : ${ARGV1}")
    message("\t매개변수2 : ${ARGV2}")
    message("\t매개변수3 : ${ARGV3}")

    message("인덱스로 접근해서 매개변수 출력")
    math(EXPR last_idx "${ARGC} - 1")
    foreach(idx RANGE ${last_idx})
        message("${ARGV${idx}}")
    endforeach()
endfunction()


fn_print_args(1 2 3 4 5 6 7)
fn_print_args("aaa" "b" "cc" "eeeee")


# ===========================================================
message("# 9. [캐시 변수의 스코프]")

function(fn_create_cache_val cache_val_name cache_val)
    set(${cache_val_name} ${cache_val} CACHE INTERNAL "")
endfunction()

fn_create_cache_val(where busan)
fn_create_cache_val(who_are_you yjd)

# 함수 내부에서 캐시변수를 생성했는데 부모 스코프에서 아무문제없이 접근 가능함
message("where : ${where}")
message("who_are_you : ${who_are_you}")
