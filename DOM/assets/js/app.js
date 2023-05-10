// var emailInput = document.getElementById('emailInput')
// var gander =document.getElementById('gander')

// console.log(emailInput);
// var userData=[]



// function addUser(){
//     if(validationEmail() ==true){
//         var user={
//             email:emailInput.value,
//             gander:gander.value
//         }
//         userData.push(user)
//         console.log(userData);
//     }
//     else{
//         alert('Sorry')
//     }
// }



// function validationEmail(){
//     var regx =/^\w{3,8}@(gmail|hotmail|yahoo)\.com$/
//     if(regx.test(emailInput.value)==true){
//         return true
//     }else{
//         return false
//     }
// }



// ----------------------------------
// DOM ==> Document Object Model

// 1- Selectors 
// var demo =document.querySelectorAll('#demo')
// console.log(demo);

// console.log(document.links);

// var btn = document.querySelectorAll('.btn')



// console.log(btn);
// // 2-Event 
// for(var i =0;i<btn.length;i++){
//     btn[i].addEventListener('keypress',sayHello)
// }
// var input =document.getElementById('input')
// input.addEventListener('blur',function(){
//     console.log('Hello');
// })

// function sayHello(){
//     console.log('Hello');
// }
// 3-Event Info 


// EX1 
// var rocketImg =document.getElementById('rocketImg')

// document.addEventListener('mousemove',function(e){
//     console.log(e.clientX);
//     rocketImg.style.left =e.clientX + `px`
//     rocketImg.style.top =e.clientY + `px`
// })

// Ex2 
// var imgBox =document.getElementById('imgBox')
// var imgList =document.querySelectorAll('.imgList')


// for(var i=0;i<imgList.length;i++){
//     imgList[i].addEventListener('click',function(e){
//         // console.log(e.target.getAttribute('src'));
//         var imgSrc =e.target.getAttribute('src')
//         imgBox.setAttribute('src',imgSrc)
//     })
// }

// Ex 3

// var btn =document.getElementById('btn')

// btn.addEventListener('click',function(e){
//     var r = Math.round(Math.random()*255)
//     var b = Math.round(Math.random()*255)
//     var g = Math.round(Math.random()*255)
//     document.body.style.backgroundColor = `rgb(${r},${b},${g})`
// })


// EX 4 
var imgesList = Array.from(document.querySelectorAll('.col-md-4 img'))
var imagesBox =document.getElementById('imagesBox')
var imgContainer =document.getElementById('imgContainer')
console.log(imgesList);


var prevBtn =document.getElementById('prevBtn')
var closeBtn =document.getElementById('closeBtn')
var nextBtn =document.getElementById('nextBtn')
var currentImgIndex
for(var i=0;i<imgesList.length;i++){
    imgesList[i].addEventListener('click',function(e){
        imagesBox.classList.remove('d-none')
        // console.log(e.target.getAttribute('src'));
        // console.log(imgesList.indexOf(e.target));
        currentImgIndex =imgesList.indexOf(e.target) //1
        var currentImgSrc = e.target.getAttribute('src')
        imgContainer.style.backgroundImage = `url(${currentImgSrc})`
    })
}


function nextSlide(){
    // currentImgIndex++;
    // if(currentImgIndex > imgesList.length -1){
    //     currentImgIndex =0
    // }
    currentImgIndex > imgesList.length -2?currentImgIndex =0:currentImgIndex++
    console.log(imgesList[currentImgIndex].getAttribute('src'));
    var newImgSrc =imgesList[currentImgIndex].getAttribute('src')
    imgContainer.style.backgroundImage = `url(${newImgSrc})`

}

nextBtn.addEventListener('click',nextSlide)



function prevSlide(){
    currentImgIndex--;
    // if(currentImgIndex < 0){
    //     currentImgIndex =imgesList.length -1
    // }
    currentImgIndex < 0?currentImgIndex =imgesList.length -1:''

    console.log(imgesList[currentImgIndex].getAttribute('src'));
    var newImgSrc =imgesList[currentImgIndex].getAttribute('src')
    imgContainer.style.backgroundImage = `url(${newImgSrc})`

}

prevBtn.addEventListener('click',prevSlide)



function closeSlide(){
    imagesBox.classList.add('d-none')
}

closeBtn.addEventListener('click',closeSlide)




// var x = [1,2,3,4,5]
// console.log(x.indexOf(2));