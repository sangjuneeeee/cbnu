const API_KEY = "ba52ecf7ad75b7c0671f29345b9b090b";
// api_key 는 https://home.openweathermap.org/api_keys 에서 확인 가능

function onGeoOk(position){
    const lat = position.coords.latitude;//위도
    const lon = position.coords.longitude;//경도
    const url = `https://api.openweathermap.org/data/2.5/weather?lat=${lat}&lon=${lon}&appid=${API_KEY}&units=metric`;//units=metric 추가(+&) 하면 화씨>>섭씨
    console.log(url);
    fetch(url)
    .then((response) => response.json())
    .then((data) => {
        const weather = document.querySelector("#weather span:first-child");
        const city = document.querySelector("#weather span:last-child");
        city.innerText = data.name;
        weather.innerText = `${data.weather[0].main} / ${data.main.temp}degree`;//``(백틱)은 string에 쓰임, ${}는 변수나 연산 삽입 가능
    });//js가 url불러옴, Network에서 확인 가능, 좀 오래 걸림 그래서 .then()추가하면 빨라짐 위url에 불러온게 json

}
function onGeoError(){
    alert("Can't find you. No weather for you.");
}

navigator.geolocation.getCurrentPosition(onGeoOk, onGeoError);