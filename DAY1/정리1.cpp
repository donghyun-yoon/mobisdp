// 객체지향 디자인의 핵심 1
// => 변하지 않는 코드 내부에 숨은 변하는 것의 분리

1. 변하는 것을 가상함수로
=> template method
=> 파생 클래스에서 가상함수 재정의..


2. 변하는 것을 다른 클래스로,
=> 교체 할수 있어야 하므로 "인터페이스"를 먼저 설계

strategy : 객체의 알고리즘 교체
state    : 객체의 모든 동작을 교체
builder  : 복잡한 객체를 만드는 방법(공정) 과 각 공정의 표현(결과)을 분리.

// 1, 2 번의 장단점을 알아야 합니다.
// 다른 클래스로 : "실행시간 교체 가능", "다른 클래스에서 정책 재사용" 
// 가상함수로    : 교체 안되고, 다른 곳에서 정책 사용안됨.
//				 하지만 멤버 함수 이므로 private 멤버 접근 가능