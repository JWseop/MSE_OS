#include "func.h"

int main(int argc, char *argv[]){
    // pid 관련 변수 선언
    pid_t pid;
    int status;
    
    // 입력값이 조건을 충족하는지 확인
    status = Input_Error_identifier(argc, argv);
    if(status!=0) return 0;

    // 입력받은 매개변수 정수화
    int value[3] = {atoi(argv[1]),atoi(argv[2]),atoi(argv[3])};

    // x y interval 값이 양의 정수인지 확인
    status = Input_Error_identifier2(value);
    if(status!=0) return 0;

    // creating child process by fork()
    pid = fork();
    pid_process(pid, value);
    
    return 0;
}

