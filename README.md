[GNL.pdf](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/7f4a8b4b-8d3d-49bb-9fa2-e2319c4824a5/GNL.pdf)

[](https://github.com/326eunjin/get_next_line)

*"The aim of this project is to make you code a function that returns a line,
read from a file descriptor."*

---

## 코드 짜기 전 구상

- 파일 디스크립터(fd)
    - 유닉스 계열에서 디렉터리,소켓 등의 객체들은 "**파일"**로 관리됨
    - 시스템에서 이러한 파일에 접근할 때, 파일 디스크립터를 통해 파일에 접근하게됨
    - 파일 디스크립터는 에러가 아니라면 양수를 가진다.
    - open할 때마다 하나씩 부여
    - 0을 표준 입력, 1은 표준 출력, 2는 표준 에러을 가리킨다.
    - 파일 디스크립터 테이블
    - 각 프로세스마다 각자의 파일 디스크립터 테이블을 가지고 있음
    
    ![Untitled](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/a5009e0f-56c8-41db-905a-d72d168a83ce/Untitled.png)
    
- read()
    - [https://badayak.com/4486](https://badayak.com/4486)
    - [https://www.it-note.kr/201?category=1068199](https://www.it-note.kr/201?category=1068199)
    - 읽은 수만큼 리턴
    - bytes 수 만큼 fd를 읽어 buf에 저장한다.
- static 변수
    - 정적 전역 변수는 파일 외부에서 사용할 수 없음
    - 정적 변수는 초기화 안해도 0으로 초기화되어있음
    - 정적 변수는 매개변수로 사용할 수 없음
    - ~~정적함수도 있음,,,~~
- gcc -D
    - D[매크로] 옵션 : 매크로를 외부에서 define 할 때 사용한다
- ~~open()~~
    
    ```c
    #include <stdio.h>
    #include <stdlib.h>
    #include <fcntl.h>
    #include <unistd.h>
    
    int main()
    
    {
    
            int fd;
    		fd = open("test2.txt",O_RDONLY|O_CREAT,0644);//0644는 O_CREAT시 이용(?)
    		printf("%d\n",fd);
            if (fd < 1)
    
            {
    
                    printf("open() error");
    
                    exit(1);
            }
    
            printf("FD : %d\n", fd);
    
            close(fd);
    
            return 0;
    }
    ```
    
    - open 성공시 파일 디스크립터 반환
    - 의문이 드는건 왜 test1 test2 이렇게 코드를 수정해서 2번 돌리면 왜 파일 디스크립터 값이 둘다 3으로 나오는걸까..?🤔

## subject 분석

- 과제 분석
    
    ![Untitled](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/473a6573-26fc-4fd2-941a-7ddd2452e9a9/Untitled.png)
    
    - 반환 값 : 읽은 문장/ 에러나 읽을게 없을 때 : NULL
    - 
- 과제 구상
    - 초반
        - 임시 버퍼 tmp
        - tmp를 백업할 static 버퍼 *backup[OPEN_MAX]
        - read(fd, tmp, BUFFER_SIZE)를 해서 읽고
        - 이를 backup에 백업(ft_strjoin)
        - backup에 개행이 있는지 없는지 확인
            - 개행이 있다면 : 개행 전후로 잘라서 그전은 출력(리턴), 개행 이후에는 backup에 백업
            - 개행이 없다면 : 다시 개행이 있을 때까지 읽고 합침(이전의 과정을 반복)
    - 보너스까지 고민 이중배열 정적 변수
        - static *backup[OPEN_MAX]
        - 멀티스레드를 고려하기 위해 이중포인터로 설정
