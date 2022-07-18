message("Functions.cmake 파일 실행")

# ===========================================================
# 함수 정의
function(fn_print_value arg)
    message(${arg})
endfunction()


# ===========================================================
# 매크로 정의
macro(mac_print_value arg)
    message(${arg})
endmacro()


message("Functions.cmake 파일 탈출")






