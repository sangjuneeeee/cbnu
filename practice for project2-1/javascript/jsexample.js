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

const hi = "hi my name is sangjun";

const str = [1, 2, "abcd", false, true]//배열
str.push("add");//배열에 푸시


alert("박상준 그는 천잰가? \n(맞다면 확인)");


const promptage = parseInt(prompt("how old r u"));//웹에서 사용자에게 입력을 때까지 pause됨 옛날거여서 안씀, parseInt 숫자면 string을 number로 변경해줌, string이면 NaN

if(isNaN(promptage)===false){//isNaN()은 string이면 true, 다른거면 false return(boolean으로 판별), if, elseif, else 조건연산자 c언어와 유사 ==은 0=="0"되지만 ===은 data type 까지 비교함
    console.log(promptage);
}

console.log(a + b + "a");//콘솔창에 출력
console.log(null, somthing);//somthing을 그냥 선언만 해서 undefined
console.log(str[3]);
console.log(player);
console.log(player.name);//== [player["name"]
player.age += 15;
console.log(player.age);
player.sayHello(hi);//object안의 function 호출
sayHi(hi);//or sayHi("hello"); 하면 hello 뜸
