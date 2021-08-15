# part1

- ft_memset
    1. 함수 설명
        - memset -- fill a byte string with a byte value
        - memset 함수는 메모리의 내용(값)을 원하는 크기만큼 특정 값으로 세팅할 수 있는 함수
        - memory + setting
    2. 유의할 점 및 신경 쓴 부분
        - b : 채우고자 하는 메모리의 시작 주소
        - c : 메모리에 채우고자하는 값
        - len : 채우고자 하는 메모리의 크기 (바이트 수)
        - void pointer는 모든 데이터 자료형을 가리킬 수 있는 포인터이다. 그래서 역참조를 하려면 (char *)b 처럼 명시적 형 변환이 필요하다.
    3. 코드

    ```c
    void	*ft_memset(void *b, int c, size_t len)
    {
    	size_t	i;

    	i = 0;
    	while (i < len)
    	{
    		*((char *)b + i) = c;
    		i++;
    	}
    	return (b);
    }
    ```

- ft_bzero
    1. 함수 설명
        - bzero -- write zeroes to a byte string
        - 바이트 스트링 s 의 처음 n 바이트를 0으로 채운다.
    2. 유의할 점 및 신경 쓴 부분
        - memset과 동일 대신 c가 아닌 0으로 채운다.
    3. 코드

    ```c
    void	ft_bzero(void *s, size_t len)
    {
    	size_t i;

    	i = 0;
    	while (i < len)
    	{
    		*((char *)s + i) = 0;
    		i++;
    	}
    }
    ```

- ft_memcpy
    1. 함수 설명
        - The memcpy() function copies n bytes from memory area src to memory area
        dst.
        - src에서 n바이트만큼 dst에 메모리의 값를 복사한다.
        - memory + copy
    2. 유의할 점 및 신경 쓴 부분
        - 처음엔 무작정 char *로 왜 dest와 source라는 변수를 설정해야 하는지 몰랐다.. 당연히 1바이트씩 복사하니깐 그렇지
        - dest가 아니라 dst 를 리턴한다.
        - memcpy는 지정된 크기(size_t n)만큼 복사하는 반면, strcpy는 null값을 만나게 되면 멈춘다.
    3. 코드

    ```c
    void	*ft_memcpy(void *dst, const void *src, size_t n)
    {
    	size_t			i;
    	char			*dest;
    	const	char	*source;

    	if (!dst && !src)
    		return (NULL);
    	dest = (char *)dst;
    	source = (const char*)src;
    	i = 0;
    	while (i < n)
    	{
    		dest[i] = source[i];
    		i++;
    	}
    	return (dst);
    }
    ```

- ft_memccpy
    1. 함수 설명
        - memccpy -- copy string until character found
        - src에서 c가 발견되면, 복사를 멈추고 dst에서 c 다음 바이트 주소가 리턴된다.
        - 그 외의 경우에는 n바이트가 복사되고 널포인터가 리턴된다.
    2. 유의할 점 및 신경 쓴 부분
        - 형변환!! → (as converted to an unsigned char) c는 unsigned char로 형변환된다.
        - 그래서 dest source도 처음부터 unsigned char로 캐스팅해줬다.
    3. 코드

    ```c
    void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
    {
    	unsigned	char	*dest;
    	unsigned	char	*source;
    	size_t				i;

    	dest = (unsigned char *)dst;
    	source = (unsigned char *)src;
    	i = 0;
    	while (i < n)
    	{
    		dest[i] = source[i];
    		if ((unsigned char)c == dest[i])
    			return (void *)(dest + i + 1);
    		i++;
    	}
    	return (0);
    }
    ```

- ft_memmove
    1. 함수 설명
        - The memmove() function copies len bytes from string src to string dst.
        - dst에 src의 len바이트만큼 복사한다.
        - dst를 항상 리턴한다.
    2. 유의할 점 및 신경 쓴 부분
        - memcpy는 메모리의 내용을 직접 copy하고, memmove는 copy할 메모리의 내용을 임시공간에 저장한 후 copy한다. (대신 memcpy는 직접 복사하기 때문에, 오버랩현상을 막을 수 없다..)
        - 메모리 공간이 겹친 경우에는 복사/이동을 수행하는 과정에서 src의 값 자체가 변경이 될 수 있는데, 이러한 문제를 메모리의 위치를 비교해서 앞에서부터 복사를 수행할지 뒤에서부터 수행할지 선택하는걸로 피할 수 있습니다. —> 이 때문에  if else구문으로 앞에서부터 복사할지 뒤에서부터 복사할지 결정!!
    3. 코드

    ```c
    void	*ft_memmove(void *dst, const void *src, size_t len)
    {
    	char		*dest;
    	const char	*source;
    	size_t		i;

    	if (!dst && !src)
    		return (NULL);
    	dest = (char *)dst;
    	source = (const char *)src;
    	i = 0;
    	if (dest <= source)
    	{
    		while (len--)
    		{
    			*dest++ = *source++;
    		}
    	}
    	else//역순으로 복사
    	{
    		dest += len;
    		source += len;
    		while (len--)
    			*(--dest) = *(--source);
    	}
    	return (dst);
    }
    ```

- ft_memchr
    1. 함수 설명
        - The memchr() function locates the first occurrence of c (converted to an
        unsigned char) in string s.
        - 문자열에서 n길이만큼 c 문자가 처음 발견된 곳을 찾고 해당 포인터를 리턴해준다. 만약 찾지 못하면, 널포인터 리턴
    2. 유의할 점 및 신경 쓴 부분
        - 리턴할때 void * 로 캐스팅해서 리턴하기
        - unsigned char로 바꿔주기
    3. 코드

    ```c
    ~~void	*ft_memchr(const void *s, int c, size_t n)
    {
    	const	char	*tmp;
    	size_t			i;

    	i = 0;
    	tmp = (const char *)s;
    	while (i < n)
    	{
    		if (tmp[i] == c)
    			return (void *)(tmp + i);
    		i++;
    	}
    	return (NULL);
    }~~

    void	*ft_memchr(const void *s, int c, size_t n)
    {
    	const char	*tmp;
    	size_t		i;

    	i = 0;
    	tmp = (const char *)s;
    	while (i < n)
    	{
    		if ((unsigned char)tmp[i] == (unsigned char)c)
    			return ((void *)(tmp + i));
    		i++;
    	}
    	return (NULL);
    }
    ```

- ft_memcmp
    1. 함수 설명
        - memcmp -- compare byte string
    2. 유의할 점 및 신경 쓴 부분
        - memcmp 는 s1과 s2의 변수에 모두 0 이 나오더라도 상관없이 서로 다른 값이 나오거나 n 개가 될때까지 비교를 계속 합니다. (문자열 비교 함수는 널문자 만나면 종료)
        - othererwise returns the difference between the first two differing bytes
        (treated as unsigned char values) —> unsigned char로 지정한 이유!
    3. 코드

    ```c
    int	ft_memcmp(const void *s1, const void *s2, size_t n)
    {
    	unsigned	char	*tmp1;
    	unsigned	char	*tmp2;
    	size_t				i;

    	i = 0;
    	tmp1 = (unsigned char*)s1;
    	tmp2 = (unsigned char*)s2;
    	while (i < n)
    	{
    		if (tmp1[i] != tmp2[i])
    			return (tmp1[i] - tmp2[i]);
    		i++;
    	}
    	return (0);
    }
    ```

- ft_strlen
    1. 함수 설명
        - The strlen() function computes the length of the string s.
        - 문자열 길이를 계산하는 함수
    2. 유의할 점 및 신경 쓴 부분
    3. 코드

    ```c
    size_t	ft_strlen(const char *str)
    {
    	size_t i;

    	i = 0;
    	while (str[i] != '\0')
    		i++;
    	return (i);
    }
    ```

- ft_strlcat
    1. 함수 설명
        - strlcat() appends string src to the end of dst.  It will append at most
        dstsize - strlen(dst) - 1 characters.  It will then NUL-terminate, unless
        dstsize is 0 or the original dst string was longer than dstsize (in prac-
        tice this should not happen as it means that either dstsize is incorrect
        or that dst is not a proper string).
        - dest에 dstsize길이만큼 src를 붙인다. 단, dstsize-1만큼만 붙이고 마지막에는 널문자가 삽입된다.
    2. 유의할 점 및 신경 쓴 부분
        - dstsize < dest_len이냐 아니냐에 따라 리턴값이 달라짐
        - unless 부분 처리 안해서 테스트케이스 통과 못했었다..
        - i + dest_len + 1로 한건,, unsigned char이라 뭐 상관없을테지만, 그래도 혹시몰라서
        - 아마 피신때는 그냥 int로 선언했었던걸로 기억
    3. 코드

    ```c
    size_t			ft_strlcat(char *dest, const char *src, size_t dstsize)
    {
    	size_t	src_len;
    	size_t	dest_len;
    	size_t	i;

    	src_len = ft_strlen(src);
    	dest_len = ft_strlen(dest);
    	i = 0;
    	while ((i + dest_len + 1 < dstsize) && (i < src_len))
    	{
    		dest[dest_len + i] = src[i];
    		i++;
    	}
    //It will then NUL-terminate, unless dstsize is 0 or the original dst string was longer than dstsize 
    	if (!(dstsize == 0 || dest_len > dstsize))
    		dest[dest_len + i] = 0;
    	if (dstsize < dest_len)
    		return (src_len + dstsize);
    	else
    		return (src_len + dest_len);
    }
    ```

- ft_strlcpy
    1. 함수 설명
        - strlcpy() copies up to dstsize - 1 characters from the string src to dst,
        NUL-terminating the result if dstsize is not 0.
        - dest에 src의  dstsize - 1만큼 복사한다
        - src의 길이를 리턴
    2. 유의할 점 및 신경 쓴 부분
    3. 코드

    ```c
    size_t	ft_strlcpy(char *dest, const char *src, size_t dstsize)
    {
    	size_t i;
    	size_t count;

    	count = 0;
    	i = 0;
    	if (dest == 0 || src == 0)
    		return (0);
    	while (src[count] != '\0')
    		count++;
    	while ((i + 1 < dstsize) && (src[i] != '\0'))
    	{
    		dest[i] = src[i];
    		i++;
    	}
    	if (dstsize > 0)
    		dest[i] = '\0';
    	return (count);
    }
    ```

- ft_strchr
    1. 함수 설명
        - 문자열 내에 일치하는 문자가 있는지 검사하는 함수
        - s : 찾을 문자열 c : 찾으려는 문자
        - strchr() and strrchr() functions return a pointer to the matched character or NULL if the character is not found.  The terminating null byte is considered part of the string, so that if c is specified as '\0', these functions return a pointer to the terminator.
    2. 유의할 점 및 신경 쓴 부분
        - 설명한거 그대로 구현,,,
    3. 코드

    ```c
    char	*ft_strchr(const char *s, int c)
    {
    	while (*s)
    	{
    		if (*s == (unsigned char)c)
    			return ((char *)s);
    		s++;
    	}
    	if (c == '\0')
    		return ((char *)s);
    	return (NULL);
    }
    ```

- ft_strrchr
    1. 함수 설명
        - strrchr() 함수는 string에서 c의 마지막 표시를 찾습니다(문자로 변환됨).
        - strchr이랑 같은 원리이지만, 마지막 위치를 반환한다.
    2. 유의할 점 및 신경 쓴 부분
        - 없다,,?
        - int형이 아닌  char 형이랑 비교
    3. 코드

    ```c
    ~~char	*ft_strrchr(const char *str, int c)
    {
    	int len;

    	len = ft_strlen(str);
    	if (c == '\0')
    		return (char *)(str + len);
    	while (len--)
    	{
    		if (str[len] == c)
    			return (char *)(str + len);
    	}
    	return (NULL);
    }~~

    char	*ft_strrchr(const char *str, int c)
    {
    	int	len;

    	len = ft_strlen(str);
    	if (c == '\0')
    		return ((char *)(str + len));
    	while (len--)
    	{
    		if (str[len] == (char)c)
    			return ((char *)(str + len));
    	}
    	return (NULL);
    }
    ```

- ft_strnstr
    1. 함수 설명
        - The strnstr() function locates the first occurrence of the null-termi-
        nated string needle in the string haystack, where not more than len char-
        acters are searched.  Characters that appear after a `\0' character are
        not searched.  Since the strnstr() function is a FreeBSD specific API, it
        should only be used when portability is not a concern.
        - len 길이 안에서   big에서 little  문자열 찾기
    2. 유의할 점 및 신경 쓴 부분
    3. 코드

    ```c
    char	*ft_strnstr(const char *big, const char *little, size_t len)
    {
    	size_t	i;
    	size_t	j;

    	i = 0;
    	if (*little == 0)
    		return (char *)(big);
    	while (i < len && big[i])
    	{
    		if (little[0] == big[i])
    		{
    			j = 0;
    			while (little[j])
    			{
    				if ((big[i + j] == little[j]) && (i + j < len))
    					j++;
    				else
    					break ;
    			}
    			if (little[j] == '\0')
    				return ((char *)big + i);
    		}
    		i++;
    	}
    	return (NULL);
    }
    ```

- ft_strncmp
    1. 함수 설명
        - The strncmp() function compares not more than n characters.  Because
        strncmp() is designed for comparing strings rather than binary data,
        characters that appear after a `\0' character are not compared.
        - 비교해서 다르면 그 순간 차이값 리턴
    2. 유의할 점 및 신경 쓴 부분
    3. 코드

    ```c
    int	ft_strncmp(const char *s1, const char *s2, size_t n)
    {
    	size_t	i;

    	i = 0;
    	if (n == i)
    		return (0);
    	while ((s1[i] || s2[i]) && (i < n))
    	{
    		if (s1[i] != s2[i])
    			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
    		i++;
    	}
    	return (0);
    }
    ```

- ft_atoi
    1. 함수 설명
        - 문자열을 int  값으로 변환
        - max value이건 여기서 int값까지만 처리하면 되니까 아직 안함 (printf에서 다시 하지 뭐..)
        - 
    2. 유의할 점 및 신경 쓴 부분
        - 앞에 음수인지 양수인지 구분하는거!
        - 앞에 꼭 개행 아니여도 \n \v등등도 들어올 수 있음
        - 처음에 isdigit쓸 생각 왜 안했지..?
    3. 코드

    ```c
    int		res(int neg, long long nbr)
    {
    	if (((neg % 2) == 1) && (nbr == 2147483648))
    		return (-2147483648);
    	else if ((neg % 2) == 1)
    		return ((int)(-1 * nbr));
    	else
    		return ((int)nbr);
    }

    int		ft_atoi(const char *str)
    {
    	int				neg;
    	int				i;
    	int				result;
    	long	long	nbr;

    	i = 0;
    	neg = 0;
    	nbr = 0;
    	result = 0;
    	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v' ||
    	str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
    		i++;
    	if (str[i] == '+' || str[i] == '-')
    	{
    		if (str[i] == '-')
    			neg++;
    		i++;
    	}
    	while (ft_isdigit(str[i]))
    	{
    		nbr = nbr * 10 + (str[i] - 48);
    		i++;
    	}
    	result = res(neg, nbr);
    	return (result);
    }
    ```

- ft_isalpha
    1. 함수 설명
        - 알파벳인지 아닌지
    2. 유의할 점 및 신경 쓴 부분
    3. 코드

    ```c
    int	ft_isalpha(int c)
    {
    	if (('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z'))
    		return (c);
    	else
    		return (0);
    }
    ```

- ft_isdigit
    1. 함수 설명
        - 숫자인지 아닌지보단 0~9 안에 있는지 아닌지!
    2. 유의할 점 및 신경 쓴 부분
    3. 코드

    ```c
    int	ft_isdigit(int c)
    {
    	if ('0' <= c && c <= '9')
    		return (c);
    	else
    		return (0);
    }
    ```

- ft_isalnum
    1. 함수 설명
        - isdigit || isalpha
    2. 유의할 점 및 신경 쓴 부분
    3. 코드

    ```c
    int	ft_isalnum(int c)
    {
    	return (ft_isdigit(c) || ft_isalpha(c));
    }
    ```

- ft_isascii
    1. 함수 설명
        - 아스키코드 값 사이인지
    2. 유의할 점 및 신경 쓴 부분
    3. 코드

    ```c
    int	ft_isascii(int c)
    {
    	if (0 <= c && c <= 127)
    		return (1);
    	else
    		return (0);
    }
    ```

- ft_isprint
    1. 함수 설명
        - 출력가능한지 아닌지 (google로 범위 찾기)
    2. 유의할 점 및 신경 쓴 부분
    3. 코드

    ```c
    int	ft_isprint(int c)
    {
    	if (32 <= c && c <= 126)
    		return (c);
    	else
    		return (0);
    }
    ```

- ft_toupper
    1. 함수 설명
        - 소문자면 대문자로 바꾸기
    2. 유의할 점 및 신경 쓴 부분
    3. 코드

    ```c
    int	ft_toupper(int c)
    {
    	if ('a' <= c && c <= 'z')
    	{
    		c = c - 'a' + 'A';
    	}
    	return (c);
    }
    ```

- ft_tolower
    1. 함수 설명
        - 대문자면 소문자로 바꾸기
    2. 유의할 점 및 신경 쓴 부분
    3. 코드

    ```c
    int	ft_tolower(int c)
    {
    	if ('A' <= c && c <= 'Z')
    		c = c - 'A' + 'a';
    	return (c);
    }
    ```

## Part2

## Part2

- ft_substr
    1. 함수 설명
        - s에서 start범위에서 len  길이만큼 동적 할당하여 복붙!!
    2. 유의할 점 및 신경 쓴 부분
        - ""는 문자열 리터럴이라 함수가 종료되면 메모리 공간이 날아갑니다. ft_strdup("")으로 리턴하게되면 문자열 리터럴을 사용하는건 같지만 힙 메모리에 할당해서 리턴하죠. 그래서 함수 종료 이후에 전자는 접근이 불가능하지만 후자는 접근이 가능합니다.
        - strdup이 무조건 말록보다 먼저 나와야함! 안그러면 할당하고, return (ft_strdup(""));이 나오니까 메모리 누수가 생김! 이전에 할당한건 왜 해제안하고 튀냐,,,?
        - start[시작 위치의 인덱스] + len[문자열 복사 최댓값] > strlen(s)[하위 대상문자열]의 경우 하위 문자열의 길이를 변경하여 문자열의 버퍼를 넘어가지 않도록 작성했다.

        ![https://user-images.githubusercontent.com/77968875/120053899-c5586080-c067-11eb-982e-4b6f5631efc5.png](https://user-images.githubusercontent.com/77968875/120053899-c5586080-c067-11eb-982e-4b6f5631efc5.png)

        - [https://github.com/codewhite7777/Libft_Study](https://github.com/codewhite7777/Libft_Study)[출처]
        - 해당 경우에 대해서 처리를 안함...
    3. 코드

    ```c
    ~~char	*ft_substr(char const *s, unsigned int start, size_t len)
    {
    	char	*ptr;
    	size_t	i;
    	int		length;

    	i = 0;
    	if (!s)
    		return (NULL);
    	length = ft_strlen(s);
    	if ((unsigned int)length <= start)
    		return (ft_strdup(""));
    	ptr = (char *)malloc(sizeof(char) * len + 1);
    	if (!ptr)
    		return (NULL);
    	ft_strlcpy(ptr, (char *)s + start, len + 1);
    	return (ptr);
    }~~

    char	*ft_substr(char const *s, unsigned int start, size_t len)
    {
    	char	*ptr;
    	size_t	i;
    	size_t	substr_len;
    	size_t	length;

    	i = 0;
    	if (!s)
    		return (NULL);
    	length = ft_strlen(s);
    	if (length <= start)
    		return (ft_strdup(""));
    	substr_len = len;
    	if (start + len > length)
    		substr_len = length - start;
    	ptr = (char *)malloc(sizeof(char) * (substr_len + 1));
    	if (!ptr)
    		return (NULL);
    	ft_strlcpy(ptr, (char *)s + start, substr_len + 1);
    	return (ptr);
    }
    ```

- ft_strjoin
    1. 함수 설명
        - 뒤에 붙이기!
    2. 유의할 점 및 신경 쓴 부분
        - strlcpy가 끝에 항상 널문자를 넣기 때문에  ptr+len1부터 다시 strlcpy를 해줬다.
        - 그리고 두번 째 strlcpy에서도 len2 + 1로 길이를 지정해줌 그래야 문자열이 그대로 복사되기 때문
    3. 코드

    ```c
    char	*ft_strjoin(char *s1, char *s2)
    {
    	int		len1;
    	int		len2;
    	char	*ptr;

    	if (!s1 || !s2)
    		return (0);
    	len1 = ft_strlen(s1);
    	len2 = ft_strlen(s2);
    	ptr = (char *)malloc(len1 + len2 + 1);
    	if (!ptr)
    		return (NULL);
    	ft_strlcpy(ptr, s1, len1 + 1);
    	ft_strlcpy(ptr + len1, s2, len2 + 1);
    	return (ptr);
    }
    ```

- ft_strtrim
    1. 함수 설명
        - 앞뒤 잘라낸다!
        - 

        ### 예외 처리

        1. **s1이 null일 경우**

            처리할 문자열이 없으므로 null을 반환한다.

        2. **set이 null일 경우**

            제거할 문자가 없으므로 s1을 복제하여 반환한다

        3. **s1의 모든 문자가 set에 포함된 경우**

            s1의 모든 문자가 제거되므로 빈 문자열을 반환한다.

        4. **malloc 실패할 경우**

            null을 반환한다.

        ### 함수 진행 과정

        1. 예외 상황 (1, 2) 처리
        2. s1 문자열의 시작과 끝으로 시작 포인터 (start), 끝 포인터 (end) 설정
        3. 문자열의 앞에서 set에 포함된 문자가 등장하지 않을 때 까지 start 이동시키기
        4. 예외 상황 (3) 처리
        5. 문자열의 뒤에서 set에 포함된 문자가 등장하지 않을 때 까지 end 이동시키기
        6. 문자열의 길이 계산하고 (`len = end - start + 1`) 메모리 할당하기
        7. 할당한 공간에 start부터 len만큼의 문자 복사하기 (with `ft_strlcpy`)
    2. 유의할 점 및 신경 쓴 부분
        - 함수 자체를 이해하지 못해서 위에 로직대로 다시 짬!
    3. 코드

    ```c
    static	int	in_set(char c, char const *set)
    {
    	int	i;

    	i = 0;
    	while (set[i])
    	{
    		if (c == set[i])
    			return (1);
    		i++;
    	}
    	return (0);
    }

    char		*ft_strtrim(char const *s1, char const *set)
    {
    	int		start;
    	int		end;
    	int		i;
    	char	*ptr;

    	if (!s1 || !set)
    		return (NULL);
    	start = 0;
    	end = ft_strlen(s1);
    	i = 0;
    	while (in_set(s1[i++], set))
    		start++;
    	if (start == end)
    		return (ft_strdup(""));
    	i = ft_strlen(s1) - 1;
    	while (in_set(s1[i--], set))
    		end--;
    	ptr = (char *)malloc(end - start + 1);
    	if (!ptr)
    		return (NULL);
    	ft_strlcpy(ptr, (char *)s1 + start, end - start + 1);
    	return (ptr);
    }
    ```

- ft_split
    1. 함수 설명
        - 문자열에서 char c를 기준으로 잘라서 다시 새로운 2차원 문자배열에 넣어서 해당 배열 리턴하기
    2. 유의할 점 및 신경 쓴 부분
        - ptr[][] 할당 실패 시, 이전에 했던 할당들도 다 free를 해줘야 메모리 누수가 생기지 않는다.
        - ft_malloc_error에서 j 이전까지 다 할당 해제하고 ptr로 할당 해제해준다.
        - ft_split2(); return (ptr);이 아니라 return (ft_split2(ptr, s, c, count)); 해야지 말록 에러 처리가 제대로 된다 안그러면 단순히 함수 호출에 그치지 않으니까 문자열에 하나씩 할당하는 과정에서 할당 에러가 생긴다고해도 리턴을 안해주니 문제가 생김..
        - 아마 메모리 누수를 확인할 때는 단순하게 내가 올바른 값을 넣으려고하다보니 그런것 같다.
    3. 코드

    ```c
    static	char	**ft_malloc_error(char **ptr, int j)
    {
    	int	i;

    	i = 0;
    	while (i < j)
    	{
    		free(ptr[i]);
    		**ptr[i] = 0;**
    		i++;
    	}
    	free(ptr);
    	**ptr = 0;**
    	return (NULL);
    }

    static	int		get_count(char const *s, char c)//총 몇개의 문자열을 만들것인가?
    {
    	int	i;
    	int	count;

    	i = 0;
    	count = 0;
    	while (s[i])
    	{
    		if (s[i] != c && s[i])
    		{
    			count++;
    			while (s[i] != c && s[i])
    				i++;
    		}
    		else if (s[i])
    			i++;
    	}
    	return (count);
    }

    static	char	**ft_split2(char **ptr, char const *s, char c, int count)
    //각 문자열에 내용넣기
    {
    	int	i;
    	int	j;
    	int	word_len;
    	int	start;

    	i = 0;
    	j = -1;
    	while (s[i] && ++j < count)
    	{
    		word_len = 0;
    		while (s[i] == c && s[i])
    			i++;
    		while (s[i] != c && s[i])
    		{
    			i++;
    			word_len++;
    			if (word_len == 1)//해당 시작 값을 넣을 것이다
    				start = i - 1;
    		}
    		if (!(ptr[j] = (char *)malloc((word_len + 1) * sizeof(char))))
    			return (ft_malloc_error(ptr, j));
    		ft_strlcpy(ptr[j], (char *)s + start, word_len + 1);
    		j++;
    	}
    	return (ptr);
    }

    char			**ft_split(char const *s, char c)
    {
    	char	**ptr;
    	int		count;

    	if (!s)
    		return (0);
    	count = get_count(s, c);
    	ptr = (char **)malloc(sizeof(char *) * (count + 1));
    	if (!ptr)
    		return (NULL);
    	ptr[count] = NULL;
    	return (ft_split2(ptr, s, c, count));
    }
    ```

- ft_itoa
    1. 함수 설명
        - atoi랑 반대로 작동!
    2. 유의할 점 및 신경 쓴 부분
    3. 코드

    ```c
    static	void	ft_make(int len, char *ptr, long long tmp)
    {
    	while (len)
    	{
    		ptr[len] = tmp % 10 + '0';
    		tmp = tmp / 10;
    		len--;
    	}
    }

    static	int		get_len(int n)//음수값이 들어오면 할당할 길이를 양수 + 1을 해준다. 
    {
    	int	i;

    	i = 0;
    	if (n == 0)
    		return (1);
    	if (n < 0)
    		i++;
    	while (n)
    	{
    		i++;
    		n = n / 10;
    	}
    	return (i);
    }

    char			*ft_itoa(int n)
    {
    	int				len;
    	char			*ptr;
    	long long		tmp;

    	len = get_len(n);
    	ptr = (char *)malloc(len + 1);
    	if (!ptr)
    		return (NULL);
    	ptr[len] = 0;//끝에는 문자열이니까 널 값을 넣어준다.
    	if (n < 0)
    	{
    		tmp = (long long)n * -1;//오버플로 처리하기 싫어서 long long으로 처리해줬다.
    		ptr[0] = '-';
    		len = len - 1;
    		ft_make(len, ptr, tmp);
    	}
    	else
    	{
    		while (len--)
    		{
    			ptr[len] = n % 10 + '0';
    			n = n / 10;
    		}
    	}
    	return (ptr);
    }
    ```

- ft_strmapi
    1. 함수 설명
        - 함수 포인터란?
        - 함수 포인터는 함수를 저장하는 포인터를 뜻하며 함수 포인터를 주고 받거나 함수 포인터로 함수를 호출할 수 있습니다.
        - main.c 예시

        ```c
        #include <stdio.h>

        char f(unsigned int i, char c)
        {
        	char str;
        	str = c + 1;
        	return (str);
        }

        int main()
        {
        	char str1[] = "abc";
        	char* str2;
        	str2 = ft_strmapi(str1, *f);
        	printf("%s\n", str2);
        }
        ```

    2. 유의할 점 및 신경 쓴 부분
    3. 코드

    ```c
    char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
    {
    	char			*ptr;
    	unsigned int	i;
    	unsigned int	len;

    	i = 0;
    	if (!s || !f)
    		return (NULL);
    	len = ft_strlen(s);
    	ptr = (char *)malloc(sizeof(char) * (len + 1));
    	if (!ptr)
    		return (NULL);
    	while (s[i])
    	{
    		ptr[i] = f(i, s[i]);
    		i++;
    	}
    	ptr[i] = '\0';
    	return (ptr);
    }
    ```

- ft_putchar_fd
    1. 함수 설명
        - 흔히 유닉스 시스템에서 모든 것은 파일이라고 한다. 일반적인 정규파일(Regular File)에서부터 디렉토리(Directory), 소켓(Socket), 파이프(PIPE), 블록 디바이스, 캐릭터 디바이스 등등 모든 객체들은 파일로써 관리된다. 유닉스 시스템에서 프로세스가 이 파일들을 접근할 때에 파일 디스크립터(File Descriptor)라는 개념을 이용한다.

            출처: [https://dev-ahn.tistory.com/96](https://dev-ahn.tistory.com/96)

        - 파일 디스크립터 : 0은 표준 입력 1은 표준 출력, 2는 표준 에러
    2. 유의할 점 및 신경 쓴 부분
        - fd값은 항상 0 이상이여서 혹시 몰라 이거 따로 예외처리
    3. 코드

    ```c
    void	ft_putchar_fd(char c, int fd)
    {
    	if (fd < 0)
    		return ;
    	write(fd, &c, 1);
    }
    ```

- ft_putstr_fd
    1. 함수 설명
        - 문자열을 해당  fd에 지정하여 출력
    2. 유의할 점 및 신경 쓴 부분
    3. 코드

    ```c
    void	ft_putstr_fd(char *s, int fd)
    {
    	int	len;

    	if (fd < 0 || s == NULL)
    		return ;
    	len = ft_strlen(s);
    	write(fd, s, len);
    }
    ```

- ft_putendl_fd
    1. 함수 설명
        - Outputs the string ’s’ to the given file
        descriptor, followed by a newline.
        - new line
    2. 유의할 점 및 신경 쓴 부분
    3. 코드

    ```c
    void	ft_putendl_fd(char *s, int fd)
    {
    	if (fd < 0)
    		return ;
    	ft_putstr_fd(s, fd);
    	write(fd, "\n", 1);
    }
    ```

- ft_putnbr_fd
    1. 함수 설명
        - 숫자를 출력!
    2. 유의할 점 및 신경 쓴 부분
    3. 코드

    ```c
    static	void	prtostring(int n, int fd)
    {
    	char	c;

    	c = n + '0';
    	write(fd, &c, 1);
    }

    void			ft_putnbr_fd(int n, int fd)
    {
    	if (fd < 0)
    		return ;
    	if (n == -2147483648)
    		write(fd, "-2147483648", 11);
    	if ((n < 10) && (n >= 0))
    		prtostring(n, fd);
    	if (n >= 10)
    	{
    		ft_putnbr_fd(n / 10, fd);
    		prtostring(n % 10, fd);
    	}
    	if (n >= -2147483647 && n < 0)
    	{
    		n = -1 * n;
    		write(fd, "-", 1);
    		if (n < 10 && n >= 0)
    		{
    			prtostring(n, fd);
    			return ;
    		}
    		ft_putnbr_fd(n / 10, fd);
    		prtostring(n % 10, fd);
    	}
    }
    ```

# Bonus

```c
typedef struct s_list
{
	void          *content;
	struct s_list *next;
}              t_list;//typedef를 사용하여 구조체 s_list 별칭을 t_list으로 정의
```

![https://s3-us-west-2.amazonaws.com/secure.notion-static.com/29752a5a-ec19-4d15-8ffb-154ca47a6984/Untitled.png](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/29752a5a-ec19-4d15-8ffb-154ca47a6984/Untitled.png)

- ft_lstnew
    1. 함수 설명
        - 새로운 노드 생성
        - Allocates (with malloc(3)) and returns a new element. The variable ’content’ is initialized with the value of the parameter ’content’. The variable ’next’ is initialized to NULL.
    2. 유의할 점 및 신경 쓴 부분
        - 새로운 노드를 할당
        - 해당 노드의 content값을 주어진 content값으로 초기화
        - 해당 노드의 다음 값은 널 값!
    3. 코드

    ```c
    t_list	*ft_lstnew(void *content)
    {
    	t_list	*new;

    	new = (t_list *)malloc(sizeof(t_list));
    	if (!new)
    		return (NULL);
    	new->next = NULL;
    	new->content = content;
    	return (new);
    }
    ```

- ft_lstadd_front
    1. 함수 설명
        - Adds the element ’new’ at the beginning of the list.
    2. 유의할 점 및 신경 쓴 부분
        - *lst는 소위 헤드를 가리킬 것이다.
        - 헤드 대신  new를 가리키게 하면 됩니당 😉
    3. 코드

    ```c
    void	ft_lstadd_front(t_list **lst, t_list *new)
    {
    	if (!lst || !new)
    		return ;
    	new->next = *lst;
    	*lst = new;
    }
    ```

- ft_lstsize
    1. 함수 설명
        - 연결리스트 노드 개수 구하기
        - 

            ![https://s3-us-west-2.amazonaws.com/secure.notion-static.com/8d092cbf-c547-4439-8127-0193771f11ae/Untitled.jpeg](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/8d092cbf-c547-4439-8127-0193771f11ae/Untitled.jpeg)

    2. 유의할 점 및 신경 쓴 부분
        - 아마 while (lst→next)이렇게 초기에 썻던 것 같다...
        - 그러면 전체 전까지만 돌아서 안됨.
    3. 코드

    ```c
    int	ft_lstsize(t_list *lst)
    {
    	int	i;

    	i = 0;
    	if (!lst)
    		return (0);
    	while (lst)
    	{
    		i++;
    		lst = lst->next;
    	}
    	return (i);
    }
    ```

- ft_lstlast
    1. 함수 설명
        - 마지막 노드 리턴
    2. 유의할 점 및 신경 쓴 부분
        - 여기선 전체까지 돌면 안되고 전체 전까지 돌고 마지막꺼 리턴해줘야 한다
        - while (lst→next) (o)
        - while (lst) (x)
    3. 코드

    ```c
    t_list	*ft_lstlast(t_list *lst)
    {
    	if (!lst)
    		return (NULL);
    	while (lst->next)
    		lst = lst->next;
    	return (lst);
    }
    ```

- ft_lstadd_back
    1. 함수 설명
        - Adds the element ’new’ at the end of the list.
    2. 유의할 점 및 신경 쓴 부분
        - 위에 필기한 그림 보면 알다싶이 lst == 0 이랑 *lst = 0의 경우 둘다 고려해야 한다.
        - *lst = 0은 헤드 노드가 없다는 말 즉,  new가  헤드 노드가 된다는 말임,,!
        - 이 경우를 고려 안 하고 else문만 일반화로 처리하면, end = NULL;이니   end→next가 말이 안됨
    3. 코드

    ```c
    void	ft_lstadd_back(t_list **lst, t_list *new)
    {
    	t_list	*end;

    	if (!lst)
    		return ;
    	if (*lst == 0)
    	{
    		*lst = new;
    		return ;
    	}
    	else
    	{
    		end = ft_lstlast(*lst);
    		end->next = new;
    	}
    }
    ```

- ft_lstdelone
    1. 함수 설명
        - 노드 삭제 & 해제

        ![https://s3-us-west-2.amazonaws.com/secure.notion-static.com/b8d388c8-2709-45ba-af9b-2291d2b30600/Untitled.png](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/b8d388c8-2709-45ba-af9b-2291d2b30600/Untitled.png)

        - 위 그림과 같은 원리로 노드가 삭제된다.
        - 근데 여기선, 함수 포인터를 이용해서 하나만 삭제 하는거라 조금은 다름..
        - Takes as a parameter an element and frees the memory of the element’s content using the function ’del’ given as a parameter and free the element.
        **The memory of ’next’ must not be freed.**
    2. 유의할 점 및 신경 쓴 부분
    3. 코드

    ```c
    void	ft_lstdelone(t_list *lst, void (*del)(void *))
    {
    	if (!lst || !del)
    		return ;
    	del(lst->content);
    	free(lst);
    	lst = 0;
    }
    ```

- ft_lstclear
    1. 함수 설명
        - Deletes and frees the given element and every successor of that element, using the function ’del’ and free(3).
        **Finally, the pointer to the list must be set to NULL.**
        - 연결리스트가 주어졌을 때, 앞에서부터 하나씩 지운다
        - tmp값으로 위치를 잡아준다.
    2. 유의할 점 및 신경 쓴 부분
        - tmp로 다음 노드를 미리 가리키게 한다.
        - 그 다음, ft_lstdelone(*lst, del)로 현재 노드를 지워준다
        - cf. t_list *c의 경우, 주소값을 넘겨줘야 하니까 ft_lstdelone(&c,del)이 되었겟쥬?
        - 그리고 *lst가 tmp를 이용해서 다음 노드를 가리키게 한다.
    3. 코드

    ```c
    void	ft_lstclear(t_list **lst, void (*del)(void *))
    {
    	t_list	*tmp;

    	if (!lst || !del)
    		return ;
    	while (*lst)
    	{
    		tmp = (*lst)->next;
    		ft_lstdelone(*lst, del);
    		*lst = tmp;
    	}
    	*lst = 0; //**Finally, the pointer to the list must be set to NULL.**
    }
    ```

- ft_lstiter
    1. 함수 설명
        - Iterates the list ’lst’ and applies the function ’f’ to the content of each element.
        - 앞에서부터 노드의 content값에 f함수를 적용 시켜준다.
    2. 유의할 점 및 신경 쓴 부분
    3. 코드

    ```c
    void	ft_lstiter(t_list *lst, void (*f)(void *))
    {
    	if (!lst || !f)
    		return ;
    	while (lst)
    	{
    		f(lst->content);
    		lst = lst->next;
    	}
    }
    ```

- ft_lstmap
    1. 함수 설명
        - Iterates the list ’lst’ and applies the function ’f’ to the content of each element. Creates a new list resulting of the successive applications of the function ’f’.
        - The ’del’ function is used to delete the content of an element if needed.
    2. 유의할 점 및 신경 쓴 부분
        - del함수포인터는 실질적으로 ft_lstclear 함수에서 사용되고 lstmap함수는 단순히 del함수를 전달만 하고있기 때문에 널 가드를 하지 않아도 괜찮습니다! ft_lstclear함수에서 가드가 이루어져요.
        - 따라서, del이 널일때 처리 안해줘도 됨
        - 새로운 연결리스트(result)를 만들건데, 일단 아무 노드도 없게 설정한다.
        - new = ft_lstnew(f(lst->content));에서 함수가 적용된 새로운 노드를 생성한다.
        - 할당 실패시, ft_lstclear로 앞에서부터 다 해제하고 삭제해주고,
        - 아니면 ft_lstadd_back을 해준다.
        - 이를 lst가 끝날 때까지 반복해주고, 다 끝나면 result 연결리스트가 완성된거니 result리턴!
    3. 코드

    ```c
    t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
    {
    	t_list	*new;
    	t_list	*result;

    	if (!lst || !f)
    		return (NULL);
    	result = 0;
    	while (lst)
    	{
    		new = ft_lstnew(f(lst->content));
    		if (!new)
    		{
    			ft_lstclear(&result, del);
    			return (0);
    		}
    		ft_lstadd_back(&result, new);
    		new = 0;
    		lst = lst->next;
    	}
    	return (result);
    }
    ```
