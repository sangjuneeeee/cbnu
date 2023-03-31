let a = 5;//let은 변수, (var 도 있지만 이건 옛날 거. 쓰지말고 걍 let 쓰면 됨)
const b = 2;//const는 상수


const c = null;
let somthing;


const player = {//object 배열과 유사
    name: "상준",
    point: 10,
    fat: false,
    sayHello : function(hi){//object 안의 function
        console.log(hi);
    }
};


function sayHi(hi){//function
    console.log(hi);
}

//player=false; ,는 오류남 
player.fat =true;//는 오류 안남 const
player.age = 23;//추가됨


const str = [1, 2, "abcd", false, true]//배열
str.push("add");//배열에 푸시


alert("박상준 그는 천잰가? \n(맞다면 확인)");

console.log(a + b + "a");//콘솔창에 출력
console.log(null, somthing);
console.log(str[3]);
console.log(player);
console.log(player.name);//== [player["name"]
player.age += 15;
console.log(player.age);

const hi = "hi my name is sangjun";
player.sayHello(hi);//object안의 function 호출
sayHi(hi);//or sayHi("hello"); 하면 hello 뜸