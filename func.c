//
//  func.c
//  ㅇㅇ
//
//  Created by 정우섭 on 2022/10/10.
//

#include "func.h"

int child_process(int x, int y, int interval){
    int sum=0;
    
    // 주어진 세 양의 정수 x, y, interval에 대해 x에서 y까지 interval 간격으로 더한 총합 sum
    for(int i=x;i<=y;){
        sum=sum+i;
        i=i+interval;
    }
    
    // child process 결과출력
    printf("Child says that the sum of numbers from %d to %d with interval of %d is %d.\n",x,y,interval,sum);
 
    // return값 반환
    if(sum<1000) exit(0);
    else if(sum==1000) exit(1);
    else exit(2);  // (sum > 1000)인 경우
}

void parent_process(int child_process_result){
    // child_process return값에 따라 출력 결과 달라짐
    if(child_process_result==0) printf("Parent says that it is less than 1000.\n");
    if(child_process_result==1) printf("Parent says that it is 1000.\n");
    if(child_process_result==2) printf("Parent says that it is greater than 1000.\n");
}

int Input_Error_identifier(int argc, int value[]){
    // 입력받은 매개변수 개수가 4개가 아니면 에러문구 출력.(실행파일명, x, y, interval)
    if(argc!=4){
        printf("[usage]: ./oshw1 x y interval\n");
        printf("[condition]: x,y, and interval are positive integers.\n");
        return -1;
    }
    
    // 입력받은 매개변수 개수가 양수가 아니면 에러문구 출력.
    if(value[0]<=0){
        printf("x is not a positive integer.\n");
        return -2;
    }
    if(value[1]<=0){
        printf("y is not a positive integer.\n");
        return -2;
    }
    if(value[2]<=0){
        printf("interval is not a positive integer.\n");
        return -2;
    }
    return 0;
}

int pid_process(int pid, int value[]){
    int status;
    
    // parent process
    if(pid>0){
        //child process가 끝날 때까지 대기, status에 종료 코드 받음
        wait(&status);
        parent_process(WEXITSTATUS(status));
        return 0;
    }
    
    // child process
    else if(pid==0){
        child_process(value[0], value[1], value[2]);
        return 0;
    }
    
    // fork error
    else{
        printf("fork 오류");
        return 0;
    }
}
