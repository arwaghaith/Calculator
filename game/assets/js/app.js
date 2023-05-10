function myFunction() {
    var element = document.getElementById("dropdown-menu");
    element.classList.add("show");
  }
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