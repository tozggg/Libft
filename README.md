# Libft
[subject](https://github.com/tozggg/Libft/blob/master/subject.pdf)  
C 표준 라이브러리의 함수들을 구현해서 나만의 라이브러리 만들기
<br>
<br>
## Details
### part1

- isalpha
- isdigit
- isalnum
- isascii
- isprint
- toupper
- tolower

- memset
    - s위치부터 n바이트만큼 c값으로 초기화
    - !! unsigned char로 형변환 하는 이유? ⇒ 1바이트씩체크 , void는 역참조 할 수 없기때문
        
        → 1바이트 메모리에 있는 모든값들을 표현하기 위해서
        
- bzero
- memcpy
    - dst에 src의 값들을 n만큼 복사
    - src의 널문자를 상관하지 않는다 // 언제나 n바이트 복사
    - strcpy와의 차이? ⇒ NULL 까지 복사한다
    - ? dst src 둘다 null일때만 왜 null을 반환할까
        
        → dst만 null일때는 dst인 null을 반환하고 src만 null일때는 dst를 반환하기 때문
        
- memccpy
    - dst에 src의 값들을 n만큼 복사 // src에서 c를 찾게되면 중단
    - c를 찾으면 c가 있는주소 + 1 주소값을 반환
    - c를 찾지못하면 null반환
- memmove
    - dst에 src의 값들을 n만큼 복사
    - memcpy와 기능은 동일
    - memcpy와의 차이?
        - memcopy는 속도가 빠름 // memmove 가 더 안전함
        - ! memcopy에서 복사하려는 src와 dst의 범위가 겹쳐있을때 overlap 발생
            
            ⇒ dst < src     // 정상
            
            ⇒ !! src < dst  // 뒤에서부터 복사해서 overlap 되지 않게 하기
            
            ⇒ dst = src     // 같은 주소이니 복사할필요없이 바로 dst 리턴
            
- memchr
    - s에서 n만큼 c(char)검색
    - 있으면 해당주소 반환
    - 없으면 null 반환
- memcmp
    - s1과 s2를 n만큼 비교
    - 다른값이 나오면 (s1값 - s2값) 반환
    - n까지 모두 같으면 null(0) 반환

- strlen
- strlcpy
    - dst == NULL && src == NULL 일때 0 반환하도록함
        
        → test 케이스 protect 하기 위함
        
- strlcat
    - !! dst의 길이가 dstsize보다 짧을때 ( 붙이지않을때 )
        
        dst[dstsize]에 0을 넣으려고했더니 abort오류가 났음
        
        ⇒ if문으로 구별시켜서 필요할때만 0을 넣게해서 해결
        
- strncmp
- atoi
    - int ~ long long 사이의 값들은 자동형변환한 int값으로 리턴
    - long long 범위를 넘어가는 값들은  //  양수 : -1  //  음수 : 0  리턴

- strchr
    - str에서 c찾기 (앞에서부터)
    - 없으면 null 반환
- strrchr
    - str에서 c찾기 (뒤에서부터)
    - 없으면 null 반환
- strnstr
    - big에서 little 찾기 (big의 len 까지만)
    - 없으면 null반환
    - little 의 길이가 0이면 big의 첫 주소값 반환
    - !! big의 len 안에 little 전부가 있어야 됬었음
    

#### malloc 관련

- calloc
    - size 크기(바이트)의 변수를 count개 저장할수 있는 메모리 공간 할당
    - malloc으로 할당한 후 0 채워넣기 (bzero)
- strdup
    - 들어온 문자열 s1만큼 malloc으로 할당한후 넣고 반환

---

### part2

- substr
    - s 의 start 인덱스부터 잘라서 재할당후 반환
    - 최대길이는 len  //  len전에 문자열이 끝날수도 있음(null)
    - ? s 자체가 NULL 이면 NULL 반환
- strjoin
    - s1과 s2 붙여서 재할당후 반환
    - ? s1 && s2  NULL 이면 NULL 반환
    - ? s1   ||   s2  NULL 이면 NULL 이 아닌 친구 strdup 해서 반환
- strtrim
    - s1 에서 "앞뒤" set문자열 내의 문자 삭제  하고 재할당후 반환
    - ? s1 NULL 이면 NULL 반환 // set이 NULL 이면 s1 재할당후 반환
    - ! s1 모두 set문자로 이루어져 있을시  "" ← 빈문자열 반환
- split
    - s에서 문자 c로 구분자를 둬서 "문자열배열" 만들고 재할당후 반환
    - s가 NULL 이면 NULL반환
    - ! big malloc 실패시 NULL 반환 // small malloc 실패시 전부다 free 하고 NULL반환
    - ? s 첫번째인덱스 0 일때랑 구분자가 0일때 예외처리 하지않았음
        
        ⇒ s의 첫번째 인덱스가 0이 들어오면  //  malloc으로 null 배열한개 포인터 할당하고 반환됨 ?
        
        ⇒ 구분자가 0일때  //  malloc으로 (s) , null 이렇게 배열두개의 포인터 할당하고 반환됨 
        
- itoa
    - 매개변수로 들어온 정수n을 char배열로 재할당후 반환
    - ? int 최소값 처리 ⇒ long long 으로 처리
- strmapi
    - s문자열 , 포인터함수 들어와서 s문자열의 각 문자마다 포인터함수 호출
        
        각각 반환값을 배열로만들어 재할당후 반환
        
    - s 나 f 가 NULL 이면 return NULL
    - ! 포인터함수의 매개변수에 index가 필요한 이유?
        
        ⇒ 예를들면 홀수번째 index에만 해야되는 작업이 있을때
        
        ⇒ map 함수의 특징
        

- putchar_fd
- putstr_fd
- putendl_fd
- putnbr_fd
    - fd 시리즈들은 write를 어디 fd(파일 디스크립터)에 할지만 정해서 해당 함수 실행
        
        ⇒ fd  // 0 : 표준입력  //  1 : 표준출력  //  2 : 표준에러  //  3up : 해당파일
        
        ⇒ write 함수의 반환값?  //  실패시 -1  //  성공시 전달한 바이트 수
        
    - putnbr에서 재귀 돌리기
        
        → 재귀에 if 줘서 엔드포인트 만들어도 되지만 재귀 자체에 조건을 줬음. 
        

---

### bonus

#### +구조체

```c
struct ProductInfo
{
	int  num;
	char name[100];
	int  cost;
}

int    main(void)
{
  // typedef ~ 구조체별칭 안써도 그냥 사용가능? ==> 안됨!!!
	// 이런식으로 선언할수도..?
	struct ProductInfo myProduct{ 1234, "제주 한라봉", 20000 };
	myProduct.name == "제주 한라봉";

	struct ProductInfo *ptr_product;
	ptr_product = &myProduct;
	prt_product->name == "제주 한라봉";
}
```

- ? 구조체가 어떻게 메모리가 잡힐까
- ?? 구조체 LinkedList에서 구조체 이중포인터를 사용하는 이유
    
    ⇒  head포인터를 변경하기 위해
    
    ⇒  insert(+delete) 할때 필요한것 이었음.
    
- ??? 왜 구조체도 포인터인거 같은데 구조체를 그냥 안쓰고 하나의 구조체를
    
    지칭할때 구조체의 포인터를 쓸까....?
    
    ⇒ next도 t_list의 포인터 이기도 함
    

#### +Makefile

- [http://doc.kldp.org/KoreanDoc/html/GNU-Make/GNU-Make-1.html](http://doc.kldp.org/KoreanDoc/html/GNU-Make/GNU-Make-1.html)
- $@  :  현재 타겟의 이름
- $^   :  현재 타겟의 종속 항목 리스트
- $<   :  현재 타겟보다 더 최근에 갱신된 파일이름
- .c.o  :  SUFFIX RULE
    
    ⇒  확장자를 자동으로 인식해서 필요한 작업을 수행
    
    ⇒  개발자가 커스텀할수 있음 (flexible)
    
- $(MACRO_NAME:OLD=NEW)  :  매크로 치환
- addprefix  //  addsuffix  // subst
- 확장자 규칙
    
    ⇒ CC  //  CFLAGS ...
    

? 리링크

? 다른 makefile 보면 gcc명령어 전에 의존관계 쓰는이유

- lstnew
    - t_list 포인터형을 하나 malloc으로 할당하고 안에 content를 넣은후 반환
    - next에는 NULL이 들어간다
- lstadd_front
    - LinkedList(t_list 이중포인터) 의 가장 앞에 t_list 포인터형 하나 넣기
    - ! lst 나 new 중 하나가 NULL 이면 return ( void형 )
    - ! *lst가 NULL이면 new→next가 NULL 이되고 *lst는 new가 된다
- lstsize
    - lst(t_list*) next따라가면서 리스트의 개수 반환
- lstlast
    - lst(t_list*) next따라가면서 리스트의 마지막 t_list* 반환

- lstadd_back
    - LinkedList의 가장 뒤에 t_list형 포인터(new) 하나 넣기
    - ! lst 나 new 중 하나가 NULL 이면 return
    - ? *lst 가 NULL일때 추가해야할까
        
        ⇒ 만약 추가해야 된다면 add_front에서는 추가하지 않고 왜 add_back에만 추가할까?
        
        → 자동적으로 추가됬었음
        
    - ? new→next 에도 NULL을 집어넣어 줘야 될까
        
        → 일단은 집어넣지 않음  //  혹시나 LinkedList가 붙을 가능성??
        
- lstdelone
    - t_list 포인터형 lst 하나 지우기(free)
    - content는 매개변수로 들어온 del 함수로 지우고 lst 는 free 함수로 메모리 해제
    - ! lst나 del함수 중 하나가 NULL 이면 return
    - ! lst→next 는 신경쓰지 않음
- lstclear
    - LinkedList 전부의 content del함수(삭제)돌리기  //  각각의 lst free 하기
    - ! lst(LinkedList 첫번째 index) 나 del 중 하나가 NULL 이면 return
    - ! 전부 del / free 한후 LinkedList 스타트포인터 NULL 넣기
    
- lstiter
    - lst(LinkedList) 의 content마다 f함수 먹이기
    - ! lst 나 f 가 NULL 일때 return
    - ? lst가 1중포인터일때는 그냥사용가능  //  2중포인터일때는 temp에 넣어서 사용하자
        
        ⇒ 이유 : 2중포인터일때는 *lst 로 그냥 썼다가는 변경되면 LinkedList초기값이 변경될수 있으므로
        
- lstmap
    - 인자로 lst, f, del 이 들어옴
    - lst(LinkedList)의 content 마다 f 함수먹여서 리턴값을 content로 재정의한 새로운 LinkedList를 재할당해서 반환하기
    - 중간에 malloc 실패시 이제까지 했던것 전부 free / del(content 삭제) ⇒ lstclear
    - lstnew로 할당해서(매개변수→새로운content) lstadd_back으로 뒤에붙이기
    - lst 나 f 가 NULL 일떄 return NULL
    - !! 함수반환값을 NULL로 초기화 안할시 Segmentation fault
    - !! del함수 NULL일때 바로 return 예외처리 해버리면 CRASH??
        
        ⇒ 문제없이 malloc이 되는 상황에서는 del함수가 NULL이어도 상관이 없는듯?
        
---
#### 평가후

lstclear 에서 Segmentation fault

⇒ 이유 : free해버린 메모리에 NULL 을 넣으려고 했다

⇒ free하기전에 tmp에 *lst 담아놓고 바로 *lst에 NULL을 넣자
