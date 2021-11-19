# Functor란 무엇일까?

내가 map을 공부하면서 처음으로 Functor와 관련한 이야기를 보게 되었다. 그래서 찾아봤는 데, 구글 랭크 첫번째로 코틀린, 두번째로 자바스크립트의 예시가 나왔다.

그러고 나서 c++관련 문서를 보니 이게 언어마다 조금씩 차이가 있는 것같다. 공통점은 당연히 있겠고, 그러나 내가 모르는 것이 너무 많기 때문에 어떻게 비슷하고 다른지 모르겠다.

일단 c++에서는 이렇게 나온다.

> 많은 STL 알고리즘들이 Functor라고 부르는 함수 객체(Function object)를 많이 사용한다. Functor는 함수처럼 ()과 함께 사용할 수 있는 객체이다. 일반 함수의 이름, 함수를 지시하는 포인터, ()연산자가 오버로딩된 클래스 객체 모두 Functor가 될 수 있다.

솔직히 와닿지는 않지만 예를 들어 버플 정렬에서 if문으로 값들을 temp를 매개체로 swap하며 정렬을 하는 데, 그 규칙을 정해주는 함수가 functor라고 할 수 있다는 예시를 통해 어느정도 감은 잡긴했다.

그런데, 찾아본 결과 이것보다 functor의 정의는 더 넓은 것같다.

### 펑터 개념
STL은 컨테이너와 이터레이터의 개념을 정의하듯이 펑터의 개념도 정의한다.

- 제너레이터(generator)는 매개변수 없이 호출하는 함수입니다.
- 단항 함수(unary function)는 하나의 매개변수로 호출하는 함수입니다.
    - 단항 함수, 이항 함수 볼 때마다 맨날 모르겠다. 그냥. 부호 생김새가 다르다? 이정도? 근데, 부호 생김새가 똑같아도 다를 때도 있는 것같아 보였었고...
- 이항 함수(binary function)는 두 개의 매개변수로 호출하는 함수입니다.

이러한 개념들도 **개량**을 가질 수 있습니다.
- bool 값을 리턴하는 단항 함수는 조건(predicate)이다.
    - ??? 무슨 말이지?
- bool 값을 리턴하는 이항 함수는 이항 조건이다(binary predicate)이다.

몇 개의 STL함수들은 조건 또는 이항 조건을 요구하는 함수가 있다.

-> 대표적으로 sort함수이다. (sort함수는 이항 조건 제 3의 매개변수로 취하는 버전이 있다.)
