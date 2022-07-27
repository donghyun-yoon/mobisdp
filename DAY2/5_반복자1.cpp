// 3_반복자1 - 104 page

// 반복자 : 복합객체의 내부구조에 상관없이 
//			동일한 방법으로 열거하기 위한 객체

// vector는 모든 요소가 연속적으로 놓입니다.
class vector {}; 

// list는 모든 요소가 분리되어 있습니다
class list {};

int main()
{
	vector v = { 1,2,3,4,5,6,7,8,9,10 };
	list   s = { 1,2,3,4,5,6,7,8,9,10 };

	// s, v의 모든 요소를 동일한 방법으로 열거할수 없을까 ?
	vector반복자 p1 = v.GetEnumerator();
	list  반복자 p2 = s.GetEnumerator();

	int n = p1.GetObject(); // 첫번째 요소 꺼내기
	p1.MoveNext();          // 다음으로 이동

	n = p1.GetObject();
	p1.MoveNext();  

	// p1객체뿐 아니라 list 반복자인 p2도 사용법이 동일해야 합니다. - "반복자 패턴의 핵심"

	// p1, p2는 사용법이 같아야 한다.
	// => 모든 반복자가 지켜야 하는 인터페이스 필요
	// => 모든 컨테이너는 GetEnumerator() 가 있어야 한다. - 인터페이스 필요
}















