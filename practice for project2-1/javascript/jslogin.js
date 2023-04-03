//1.
// const loginForm = document.getElementById("login-form");
// const loginInput = loginForm.querySelector("input");
// const loginButton = loginForm.querySelector("button");

//if(click어쩌구)~~~{}등등//안쓰는 이유 : js로도 가능하지만 별로 안이쁨, 비효율 > html을 최대한 활용 후 이용

const loginForm = document.querySelector("#login-form");//1번 코드를 이 처럼 나타낼 수 있음
const loginInput = document.querySelector("#login-form input");

function onLoginSubmit(event){
    event.preventDefault();//브라우저 기본동작 막음 > 새로고침
    console.log(loginInput.value);
}

loginForm.addEventListener("submit", onLoginSubmit);//이게 실행되면서 함수의 'event' argument에 최근 실행된 event 정보를 전달함