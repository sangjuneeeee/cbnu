# React, JSX

## 대문자로 시작해야 하는 이유
> 소문자로 시작하는 건 기본 HTML 요소로 간주하기 때문에 App, Post처럼 앞에를 대문자로 해야함 그래야 component로 간주함

> Ex) div 등등

## 중괄호
> {} 하면 javascript형식 사용가능

> Ex) {2+2} >> 4출력  {varName} >> varName에 저장된 값 출력

## return
> return 은 하나만 반환해서 최상위 요소가 필요함, 최상위 요소를 통해 하나로 묶어주고 return

> Ex) < main.>  < /main.> 또는 할 거 없으면 빈 < ></>

## 종료 tag
> < > </> 이렇게 하던가 </> 자체 종료 태그를 해야함 종료 태그 없이 < >만 하는건 안됨

## props
> 함수 인를 전달할 때 예시 App.jsx처럼 호출하고 Function.jsx 에서 보이듯이 사용할 수 있다.
<pre>
Function.jsx
<hr/><code>function Exam (props){
    props.a
    props.b
}
</code>
</pre>
<pre>
App.jsx
<hr/><code>function App (){
    return (
    <>
        < Exam a="this" b="is example">
        < Exam a="hello" b="world!">
    <./>
    );
}
</code>
</pre>

## Jsx에서 CSS
> test.css 가 아니라 test.module.css 로 하여 모듈 기능을 사용할 수 있음. <br/>

jsx file 에서 import 하는 법 
<pre>
test.jsx
<hr/><code>
import anyname from 'css상대경로';

< div className = {anyname.test}> 
</code>
</pre>
>하게 되면 anyname의 이름 객체로 css 사용가능


