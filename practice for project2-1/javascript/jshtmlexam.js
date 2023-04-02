document.title = "상준의 페이지"//document는 html의 구성요소를 불러옴


const title = document.getElementById("title");//document.getElementById()는 html의 id를 불러옴
console.dir(title);//consol.log보다 자세하게 출력됨


title.innerText = "Changed TEXT! and Click Me!";//연결된 html id = title의 element 중 innerText를 바꿈


const hello = document.querySelector(".hello h2");
/*querySelector()는 하나의 element만 가져옴,
form 이나 h1, h2등 하위 태그까지 불러와서 좋음
querySelector()와 getElemtById등()은 유사 전자는 css형식처럼 class는. id는 #쓰면 됨
querySelectorAll이나 getElementByClassName()같은건 array로 받아옴*/
console.dir(hello);


function handleClick(){
    console.log("click!");
    title.style.color = "blue";//js에서 style을 바꿀 순 있지만 css에서 하는게 좋음
}
function handleIn(){
    title.innerText = "mouse in!";
}
function handleOut(){
    title.innerText = "mouse out!";
}
title.addEventListener("click", handleClick);//handle에 괄호를 안하면 js가 자동 실행해줌
title.addEventListener("mouseenter", handleIn);
title.addEventListener("mouseleave", handleOut);
//elements에서 앞에 on 써있는건 event들임, 쓸 때는 on 빼고 씀