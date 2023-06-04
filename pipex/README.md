# Pipex

[pipex.pdf](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/3187f42d-8096-4b13-875d-f59ba3d6106a/pipex.pdf)

[326eunjin/pipex](https://github.com/326eunjin/pipex.git)

*“This project is the discovery in detail and by programming of a UNIX
mechanism that you already know.”*

---

## 코드 짜기전

### 허용 함수

- access
    - 프로세스가 지정한 파일이 존재하는지, 읽거나 쓰거나 실행이 가능한 지를 확인하는 함수 만일 지정한 파일이 심볼릭 링크라면 링크의 원본을 체크합니다.
    - 반환: 0 == 가능 또는 파일이 존재함1 == mode 에 대해 하나 이상 거절되었거나 에러가 있음. 자세한 내용은 errno에 세팅됨
    - F_OK 파일 존재?
    - W_OK 쓰기 가능?
    - R_OK 읽기 가능?
    - X_OK 실행 가능?
    
    ```c
    #include <stdio.h>
    #include <unistd.h>
    
    int main()
    {
        char *file_name = "./allow.c";
        if(0 == access(file_name, F_OK)){
            printf("%s file exists\n",file_name);
            if( 0 == access(file_name, R_OK | W_OK))
                printf("file can be written or read");
            else
                printf("you can't read the file or change the file");
        }
        else
        {
            printf("file doesn't exist");
        }
    }
    ```
    
- open
    - 파일 여는 함수
    - **int** 0 < 파일 열기에 성공하면 파일 디스크립터의 양의 정수 값 반환
        
              -1 == 실패
        
- unlink
    - 링크를 삭제하는 함수
    - 인노드 심볼릭링크 하드링크 관계도
        
        ![Untitled](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/94542e21-8579-4842-9948-97a5c138ba9f/Untitled.png)
        
        OS는 hard link 참조 count가 0이고 file open 참조 count가 0일 때에 파일의 내용이 저장된 disk space를 해제합니다.
        
        출처:[https://www.it-note.kr/177](https://www.it-note.kr/177)
        
        [https://bubble-dev.tistory.com/entry/CC-link2-unlink2](https://bubble-dev.tistory.com/entry/CC-link2-unlink2)
        
    
- close
    - [open](https://bubble-dev.tistory.com/entry/CC-open-%ED%95%A8%EC%88%98-%ED%8C%8C%EC%9D%BC-%EC%83%9D%EC%84%B1-%EC%9D%BD%EA%B8%B0-%EC%93%B0%EA%B8%B0)으로 열었던 파일을 닫아주는 함수
    - 성공 시 0 리턴
        
        실패 시 -1 리턴 후 errno 설정
        
- read
    - [open()](https://badayak.com/4398) 함수로 열기한 파일의 내용을 읽기
    - ssize_t == -1 실패
        
                     >  0 정상적으로 실행되었다면 읽어들인 바이트 수
        
- write
    - [open()](https://badayak.com/4398) 함수로 열기를 한 파일에 쓰기
    - • ssize_t 쓰기에 성공했다면 쓰기한 바이트 개수를, 실패했다면 -1을 반환
- malloc
    - 동적 메모리 할당 함수
- waitpid
    - [https://bubble-dev.tistory.com/entry/CC-wait2-waitpid2](https://bubble-dev.tistory.com/entry/CC-wait2-waitpid2)
- wait
    - 자식 프로세스 작업이 끝날 때 까지 대기하며, 자식 프로세스가 종료한 상태를 구합니다.
    - 부모 프로세스가 자식 프로세스가 종료될 때까지 기다리게 함
    - fork()와 wait()를 사용할 경우, 부모와 자식프로세스의 실행 순서는 다음과 같음
    - wait()를 사용하여 실행순서를 보장받을 수 있음
    
    ![Untitled](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/b67bc194-b1bd-494d-9704-c6b2b80bab37/Untitled.png)
    
    ---
    
    - [https://www.it-note.kr/132](https://www.it-note.kr/132)
    - [https://badayak.com/entry/C언어-자식-프로세스가-종료될-때까지-대기-함수-wait](https://badayak.com/entry/C%EC%96%B8%EC%96%B4-%EC%9E%90%EC%8B%9D-%ED%94%84%EB%A1%9C%EC%84%B8%EC%8A%A4%EA%B0%80-%EC%A2%85%EB%A3%8C%EB%90%A0-%EB%95%8C%EA%B9%8C%EC%A7%80-%EB%8C%80%EA%B8%B0-%ED%95%A8%EC%88%98-wait)
    - [https://bubble-dev.tistory.com/entry/CC-wait2-waitpid2](https://bubble-dev.tistory.com/entry/CC-wait2-waitpid2)
- free
    - 동적 할당으로 받은 메모리 해제시키는 함수
    
- pipe
    - [https://gracefulprograming.tistory.com/92](https://gracefulprograming.tistory.com/92)
    - [https://velog.io/@hidaehyunlee/minishell-5.-파이프Pipe-처리](https://velog.io/@hidaehyunlee/minishell-5.-%ED%8C%8C%EC%9D%B4%ED%94%84Pipe-%EC%B2%98%EB%A6%AC)
    - [https://nomad-programmer.tistory.com/110](https://nomad-programmer.tistory.com/110)
- dup
    - 리눅스 시스템에서는 열려진 file descriptor를 복제하는 함수
    - `int dup(int oldfd);`
    - 원본 디스크립터와 복사된 디스크립터의 읽기/쓰기 포인터는 공유됩니다.
    - **int** 복사된 파일 디스크립터 번호로 사용되지 않은 가장 작은 번호가 자동으로 지정되어 반환됩니다. 함수 실행이 실패되면 -1 이 반환됩니다.
    - [https://ehpub.co.kr/tag/dup-함수/](https://ehpub.co.kr/tag/dup-%ED%95%A8%EC%88%98/)
- dup2
    - `int dup2(int oldfd, int newfd);`
    - dup2(fd1, fd2); 파일 식별자를 복제해 fd2를 fd1으로 바꾼다.
    - [https://reakwon.tistory.com/104](https://reakwon.tistory.com/104)
    
    ![Untitled](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/b00e6984-22a4-4ecd-94e4-3a25d48475e9/Untitled.png)
    
- execve
    - 다른 프로그램을 실행하고 자신은 종료
    - **int** execve( **const** **char** *path, **const** **char** *arg , ..., **char** * **const** envp[])
    - 인수: **char** *char 디레토리 포함 전체 파일 명**const** **char** *arg 인수 목록**char** * **const** envp[] 환경 설정 목록
    - 반환: 실패일 때만 -1
- fork
    - 자식 프로세스 생성 함수
    - 반환: pid_t -1 : 실패0 == 자식 프로세스, 새로 생성된 프로세스임0 < 생성된 자식 프로세스 PID
    - 자식 프로세스는 부모 프로세스의 복사본
    - 성공 시 부모 프로세스에게는 생성된 자식 프로세스의 pid 를 리턴 하고, 자식 프로세스에게는 0을 리턴함
        
        에러 시 -1 리턴하고 errno 설정
        
    
    ```c
    #include <stdio.h>
    #include <stdlib.h>
    #include <unistd.h>
    
    char global_str[]="write to standard ouput\n";
    int glob_val = 10;
    
    int main(int argc, char *argv[], char *envpp[])
    {
        pid_t pid;
        int loc_val;
    
        loc_val = 100;
        if (write(STDOUT_FILENO, global_str, sizeof(global_str) - 1) != sizeof(global_str) - 1) {
            fprintf(stderr, "write error\n");
            exit(1);//STDOUT_FILENO standard output
        }
        printf("before fork\n");
    
        if ((pid = fork()) < 0) {
            fprintf(stderr, "fork error\n");
            exit(1);
        }
        //child process
         if (pid == 0) {
            glob_val++;
            loc_val++;
        }
        //parent process wait for 3 seconds
        //so that child process first 실행
        else {
            sleep(3);
        }
        printf("pid = %d, glob_val = %d, loc_val = %d\n", getpid(), glob_val, loc_val);
        exit(0);
    }
    ```
    
- perror
    - 오류메시지 출력
    - 출력 결과 : 에러 내용은: : No such file or directory
    
    ```c
    #include <stdio.h>
    
    int main( void)
    {
       FILE *fp;
    
       fp = fopen( "nofile.c", "r"); // 존재하지 않는 파일을 열기 시도
       perror( "에러 내용은: ");
    
       if ( fp) fclose( fp);
    
       return 0;
    }
    ```
    
- strerror
    - errno는 함수가 아닙니다. 광역변수로서 라이브러리 함수 수행 중 에러가 발생하면 에러 코드를 가지게 됩니다. 함수 실행 중 에러없이 복귀되었다면 errno는 0 값을 가지지만 수행 중 에러가 발생했다면 0 이외의 값을 갖습니다.
    - [errno](https://badayak.com/4370) 에 대한 에러 내용을 구하는 함수
    - strerror() 함수는 에러 코드를 인수로 그에 해당하는 에러 메시지를 돌려 줍니다.
        
        perror() 함수는 현재 errno에 해당하는 에러 메시지를 표준 출력(stderr)으로 출력합니다.
        
- exit
    - exit()는 프로그램을 종료
    - status - 부모 프로세스로 넘겨줄 값을 설정합니다. status가 0이면 보통 정상종료로 인식합니다. 부모 프로세스는 wait(2) 또는 waitpid(2) 등으로 status 값을 받을 수 있습니다.
        
        출처:[https://www.it-note.kr/48](https://www.it-note.kr/48)[IT 개발자 Note]
        
        **[출처]** [C언어 'main에서 return' & 'exit(0), exit(1)' 의 차이](https://blog.naver.com/mokdonjr/220813555163)|**작성자** [궁디쑹디](https://blog.naver.com/mokdonjr)
        
    - exit(0)은 '정상종료', exit(1)은 '에러메시지 종료'

['C언어 header/unistd.h' 카테고리의 글 목록 (2 Page)](https://www.it-note.kr/category/C%EC%96%B8%EC%96%B4%20header/unistd.h?page=2)

고아 프로세스와 좀비 프로세스 정의는 아래와 같습니다.

부모 프로세스가 자식 프로세스보다 먼저 종료되면 자식 프로세스는 고아프로세스가 됩니다.

그리고 자식 프로세스가 종료되었지만 부모 프로세스가 자식 프로세스의 종료 상태를 회수하지 않았을 경우에 자식 프로세스를 좀비 프로세스라고 합니다.

[https://tigercoin.tistory.com/39](https://tigercoin.tistory.com/39)

## 서브젝트 분석

[pipex tutorial - 42 project](https://csnotes.medium.com/pipex-tutorial-42-project-4469f5dd5901)

**실행 흐름은 다음과 같다.**

- 인자가 제대로 들어오는지 확인한다.
    - 제대로 들어오지 않았다면 → 에러 함수 호출 및 강제 종료
    - 제대로 들어왔다면
        - 자식 프로세스 (cmd 1)
            - STDIN을 infile에 연결
            - STDOUT을 pipe의 왼쪽(fd[1])에 연결
            - fd[0] 닫기
            - exec 함수를 통해 명령어 실행
        - 부모 프로세스 (cmd 2)
            - STDIN을 pipe의 오른쪽(fd[0])에 연결
            - STDOUT을 outfile에 연결
            - fd[1] 닫기
            - exec 함수를 통해 명령어 실행
        - 명령어 실행 함수 작동 방식
            - / 가 없다면 : 환경변수를 이용하여 PATH(명령어 파일들의 위치를 찾음)
                
                하나하나 붙여가며 실행 가능한지 확인
                
                실행 가능하다면 실행, 아님 에러
                
            - /가 있다면 : 그 명령어 자체가 실행 가능한지 확인
                
                실행 가능하다면 실행, 아님 에러
                

---

왜 pipe은 일방향 통신인데 왜 fd[1]이 왼쪽,  fd[0]이 오른쪽일까?

→ [https://velog.io/@hidaehyunlee/minishell-5.-파이프Pipe-처리](https://velog.io/@hidaehyunlee/minishell-5.-%ED%8C%8C%EC%9D%B4%ED%94%84Pipe-%EC%B2%98%EB%A6%AC)

![스크린샷 2022-04-09 오후 7.32.39.png](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/062f9e7a-2c10-4bf1-abc6-43848fafdcb8/스크린샷_2022-04-09_오후_7.32.39.png)

![Untitled](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/0c26c3d0-00ec-4439-b765-d326af42df31/Untitled.png)

## 코드 짜기

```c
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejang <ejang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 17:15:02 by ejang             #+#    #+#             */
/*   Updated: 2022/03/31 21:26:53 by ejang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <string.h>
# include <sys/types.h>
# include <stdio.h>
# include "../libft/libft.h"

void	path_exec(char	*argv, char	**envp);//명령어 실행 함수
void	pipex(int infile, int outfile, char **argv, char **envp);
void	error_handle(void);
char	*find_path(char *cmd, char **envp);
void	free_split(char **args);

#endif
```

```c
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejang <ejang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 21:46:29 by ejang             #+#    #+#             */
/*   Updated: 2022/03/31 21:38:56 by ejang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

char	*find_path(char *cmd, char **envp)
//envp는 리눅스 명령어 printenv 와 같다고 생각하면 된다
{
	char	**paths;
	char	*path;
	int		i;
	char	*part_path;

	i = 0;
	while (ft_strnstr(envp[i], "PATH", 4) == 0)//printenv의 결과 중 PATH를 찾을 것
		i++;
	paths = ft_split(envp[i] + 5, ':');
	i = 0;
	while (paths[i])
	{
		part_path = ft_strjoin(paths[i], "/");// /을 붙여가며 실행 가능한지 확인
		path = ft_strjoin(part_path, cmd);
		free(part_path);
		if (!access(path, F_OK))
		{
			free_split(paths);
			return (path);
		}
		free(path);
		i++;
	}
	free_split(paths);
	return (0);
}

void	free_split(char **args)
{
	int	size;
	int	i;

	i = 0;
	size = 0;
	while (args[size])
		size++;
	while (i < size)
		free(args[i++]);
	free(args);
}
```

```c
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejang < ejang@student.42seoul.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 21:25:02 by ejang             #+#    #+#             */
/*   Updated: 2022/04/01 12:47:46 by ejang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	path_exec(char	*argv, char	**envp)
{
	char	*path;
	char	**cmd;

	cmd = ft_split(argv, ' ');
	path = cmd[0];
	if (!ft_strchr(cmd[0], '/'))
	{
		path = find_path(cmd[0], envp);
		if ((access(path, F_OK) == -1) || (path == 0))
		{
			free(path);
			free_split(cmd);
			exit(127);
		}
		execve(path, cmd, envp);
		free(path);//이 경우 실행이 안된다. 메모리 해제는 어덯게 할 수 없는 것...
	}
	else
	{
		execve(path, cmd, envp);
	}
	free_split(cmd);
}

void	pipex(int infile, int outfile, char **argv, char **envp)
{
	int		fd[2];
	pid_t	pid;
	int		status;

	if (pipe(fd) == -1)
		error_handle();
	pid = fork();
	if (pid == 0)
	{
		dup2(infile, STDIN_FILENO);
		dup2(fd[1], STDOUT_FILENO);
		close(fd[0]);
		path_exec(argv[2], envp);
	}
	else
	{
		dup2(outfile, STDOUT_FILENO);
		dup2(fd[0], STDIN_FILENO);
		close(fd[1]);
		waitpid(-1, &status, WNOHANG);
		path_exec(argv[3], envp);
	}
}

void	error_handle(void)
{
	perror("ERROR");
	exit(1);
}

int	main(int argc, char **argv, char **envp)
{
	int	infile;
	int	outfile;

	if (argc == 5)
	{
		infile = open(argv[1], O_RDONLY);
		outfile = open(argv[4], O_RDWR | O_CREAT | O_TRUNC, 0644);
		if (infile == -1 || outfile == -1)
			error_handle();
		pipex(infile, outfile, argv, envp);
		return (0);
	}
	else
		error_handle();
}
```
