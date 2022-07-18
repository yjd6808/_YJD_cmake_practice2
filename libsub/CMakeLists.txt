message("subdir/CMakeLists.txt 파일 진입")
message("\troot a : ${a}")
message("\troot A : ${A}")

set(a "777")
set(A "666")

message("\tnew a : ${a}")
message("\tnew A : ${A}")
message("subdir/CMakeLists.txt 파일 탈출")

fn_reset()



