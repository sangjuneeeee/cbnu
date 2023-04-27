const jsh1 = document.querySelector("div.divh1:first-child h1");



function handleTitleCick(){

    //1.
    // if(jsh1.className === clickedClass){
    //     jsh1.className = "";
    // }else{
    //     jsh1.className = clickedClass;
    // }

    //2.
    // const clickedClass = "active"; //코드 짤 때 실수를 덜하고 가독성을 위하여., css파일에 쓴 active class임
    // if(jsh1.classList.contains(clickedClass)){//1. 코드 대신 이렇게 하면 clickedClass만 추가하고 없애기 때문에 html h1의 class 에서 폰트는 유지한채로 class 추가 및 삭제 가능
    //     jsh1.classList.remove(clickedClass);
    // }else{
    //     jsh1.classList.add(clickedClass);
    // }

    //3.
    jsh1.classList.toggle("active");//2. 코드를 간략화한게 toggle
}

jsh1.addEventListener("click", handleTitleCick);

